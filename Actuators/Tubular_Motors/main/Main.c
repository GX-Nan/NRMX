/*
* @file         hx_oled.c 
* @brief        ESP32操作OLED-I2C
* @details      用户应用程序的入口文件,用户所有要实现的功能逻辑均是从该文件开始或者处理
* @author       红旭团队 
* @par Copyright (c):  
*               红旭无线开发团队，QQ群：671139854
*/
#include <stdio.h>
#include "esp_system.h"
#include <esp_log.h>
#include <freertos/FreeRTOS.h>
#include "freertos/task.h"
#include "driver/gpio.h"
#include "PWM/PWM.h"
#include "OLED/oled.h"
#include "Tcp_Client/tcp_client_select.h"
#include "Tcp_Client/event_handler.h"
#include "Tcp_Client/public_variable.h"
#include "Tcp_Client/wifi_softap_sta.h"


// static void Function(void *pvParameters); 
// static int Falg ;



// static void Function(void *pvParameters)
// {
//     while (1)
//     {
//         Falg=gpio_get_level(gpio_pin);
//         if(Falg==1){
//              oled_show_str(0,45,"Some one Pass",&Font_7x10,1);
//         }
//         else if(Falg==0){
//              oled_show_str(0,45,"No one Pass",&Font_7x10,1);
//         }
//         vTaskDelay(10 / portTICK_RATE_MS);//延时约3S
//     } 
// }


pv_tcp_client_select_struct_t tcp_client;

//TCP客户端数据接收回调函数
void tcp_client_recv_data(char *data,int len){
  //返回数据给服务器
  write(tcp_client.socket_fd, data, len);
}

void app_main()
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

    Motor_Config();//窗户电机初始化
    oled_init();//oled屏幕初始化
    oled_show_str(0,0, "Amye-----------------",&Font_7x10,1);
    strcpy(tcp_client.ip, "192.168.31.93");//设置连接的服务器IP地址
    tcp_client.port = 6000;//设置连接的端口号
    tcp_client_select_task_init(&tcp_client,10,tcp_client_recv_data);

}                                                                                          