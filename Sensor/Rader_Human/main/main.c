#include <stdio.h>
#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include "freertos/event_groups.h"
#include "lwip/sockets.h"
#include "lwip/netdb.h"
#include "esp_system.h"
#include "esp_wifi.h"
#include "esp_netif.h"
#include "esp_log.h"

#include "nvs_flash.h"
#include "wifi_softap_sta.h"
#include "usart.h"
#include "tcp_client_select.h"
#include "Infra_Red.h"


PRIVILEGED_DATA static portMUX_TYPE xTaskQueueMutex = portMUX_INITIALIZER_UNLOCKED;

pv_tcp_client_select_struct_t tcp_client;

//TCP客户端数据接收回调函数
void tcp_client_recv_data(char *data,int len){
  //返回数据给服务器
  write(tcp_client.socket_fd, data, len);
}

void app_main(void)
{
    // gpio配置结构
    esp_err_t ret = nvs_flash_init();
    if (ret == ESP_ERR_NVS_NO_FREE_PAGES || ret == ESP_ERR_NVS_NEW_VERSION_FOUND) {
      ESP_ERROR_CHECK(nvs_flash_erase());
      ret = nvs_flash_init();
    }
    ESP_ERROR_CHECK(ret);

    //初始化内部的lwip
    ESP_ERROR_CHECK(esp_netif_init());
    //创建系统事件任务
    ESP_ERROR_CHECK(esp_event_loop_create_default());
    //初始化配置AP+STA
    wifi_init_softap_sta();

    // portENTER_CRITICAL(&xTaskQueueMutex);//进入临界点
    Usart_main();
   // Infra_Red_Main();
    strcpy(tcp_client.ip, "192.168.1.109");//设置连接的服务器IP地址
    tcp_client.port = 6000  ;//设置连接的端口号
    tcp_client_select_task_init(&tcp_client,10,tcp_client_recv_data);

}