#include "Infra_Red.h"

extern pv_tcp_client_select_struct_t tcp_client;

void Read_GPIO()
{
    int Falg;
    //char SendData="ZB1020210";
    while (1)
    {
       Falg=gpio_get_level(gpio_pin);
       printf("address:%d\r\n", Falg);
       if(tcp_client.connected==1){
           switch(Falg)
           {
               case 0:
               // write(tcp_client.socket_fd, "ZB10202101", 10);
                vTaskDelay(100/ portTICK_RATE_MS);
                break;
               case 1:
               // write(tcp_client.socket_fd, "ZB10202101", 10);
                vTaskDelay(100/ portTICK_RATE_MS);
                break;
           }
       }   
       vTaskDelay(100/ portTICK_RATE_MS);
    }
}
void GPIO_init()
{
    //gpio���ýṹ��
    gpio_config_t io_conf;
    //��ֹ�ж�
    io_conf.intr_type = GPIO_PIN_INTR_DISABLE;
    //�������ģʽ
    io_conf.mode = GPIO_MODE_INPUT_OUTPUT;
    //����Ҫ���õ�����
    io_conf.pin_bit_mask =gpio_pin;
    //��ֹ����
    io_conf.pull_down_en = 0;
    //��ֹ����
    io_conf.pull_up_en = 0;
    //����gpio(������������Ĭ������͵�ƽ)
    gpio_config(&io_conf);
}
void Infra_Red_Main()
{
    GPIO_init();
    xTaskCreate(Read_GPIO,"Read_GPIO",2048,NULL,2,NULL);
}