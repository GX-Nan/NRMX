/*
* @file         hx_oled.c 
* @brief        ESP32����OLED-I2C
* @details      �û�Ӧ�ó��������ļ�,�û�����Ҫʵ�ֵĹ����߼����ǴӸ��ļ���ʼ���ߴ���
* @author       �����Ŷ� 
* @par Copyright (c):  
*               �������߿����Ŷӣ�QQȺ��671139854
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
//         vTaskDelay(10 / portTICK_RATE_MS);//��ʱԼ3S
//     } 
// }


pv_tcp_client_select_struct_t tcp_client;

//TCP�ͻ������ݽ��ջص�����
void tcp_client_recv_data(char *data,int len){
  //�������ݸ�������
  write(tcp_client.socket_fd, data, len);
}

void app_main()
{
     // gpio���ýṹ
    esp_err_t ret = nvs_flash_init();
    if (ret == ESP_ERR_NVS_NO_FREE_PAGES || ret == ESP_ERR_NVS_NEW_VERSION_FOUND) {
      ESP_ERROR_CHECK(nvs_flash_erase());
      ret = nvs_flash_init();
    }
    ESP_ERROR_CHECK(ret);
    //��ʼ���ڲ���lwip
    ESP_ERROR_CHECK(esp_netif_init());
    //����ϵͳ�¼�����
    ESP_ERROR_CHECK(esp_event_loop_create_default());
    //��ʼ������AP+STA
    wifi_init_softap_sta();

    Motor_Config();//���������ʼ��
    oled_init();//oled��Ļ��ʼ��
    oled_show_str(0,0, "Amye-----------------",&Font_7x10,1);
    strcpy(tcp_client.ip, "192.168.31.93");//�������ӵķ�����IP��ַ
    tcp_client.port = 6000;//�������ӵĶ˿ں�
    tcp_client_select_task_init(&tcp_client,10,tcp_client_recv_data);

}                                                                                          