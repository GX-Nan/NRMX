#define usart_c_
#include "usart.h"

// // static const char *TAG = "usart_function";

static const int RX_BUF_SIZE = 1024;

#define TXD_PIN (GPIO_NUM_12)
#define RXD_PIN (GPIO_NUM_13)

extern pv_tcp_client_select_struct_t tcp_client;

void uart2_rx_task();

void uart_init(void)
{
    const uart_config_t uart_config = {
        .baud_rate = 256000,
        .data_bits = UART_DATA_8_BITS,
        .parity = UART_PARITY_DISABLE,
        .stop_bits = UART_STOP_BITS_1,
        .flow_ctrl = UART_HW_FLOWCTRL_DISABLE,
        .source_clk = UART_SCLK_APB,
    };
    // We won't use a buffer for sending data.
    uart_driver_install(UART_NUM_1, RX_BUF_SIZE * 2, 0, 0, NULL, 0);
    uart_param_config(UART_NUM_1, &uart_config);
    uart_set_pin(UART_NUM_1, TXD_PIN, RXD_PIN, UART_PIN_NO_CHANGE, UART_PIN_NO_CHANGE);
}

/*
 * 应用程序的函数入口
 * @param[in]   NULL
 * @retval      NULL
 * @par         修改日志
 *               Ver0.0.1:
                     hx-zsj, 2018/08/06, 初始化版本\n
*/
void Usart_main()
{
    //串口初始化
    uart_init();
    //创建串口2接收任务
    xTaskCreate(uart2_rx_task, "uart2_rx_task", 1024 * 2, NULL, configMAX_PRIORITIES - 1, NULL);
    //串口2数据发送测试
    //  uart_write_bytes(UART_NUM_2, "uart2 test OK ", strlen("uart2 test OK "));
}
/*
* 串口1接收任务
* @param[in]   void  		       :无
* @retval      void                :无
* @note        修改日志
*               Ver0.0.1:
                    hx-zsj, 2018/08/06, 初始化版本\n
*/

/*
* 串口2接收任务
* @param[in]   void  		       :无
* @retval      void                :无
* @note        修改日志
*               Ver0.0.1:
                    hx-zsj, 2018/08/06, 初始化版本\n
*/

void uart2_rx_task()
{
    static const char *RX_TASK_TAG = "RX_TASK";
    esp_log_level_set(RX_TASK_TAG, ESP_LOG_INFO);
    uint8_t *data = (uint8_t *)malloc(RX_BUF_SIZE + 1);
    char SendData[12] = "ESP10";
    int Data;

    char CharData[4];
    while (1)
    {
        const int rxBytes = uart_read_bytes(UART_NUM_1, data, RX_BUF_SIZE, 10 / portTICK_RATE_MS);
        if (rxBytes > 0)
        {
            data[rxBytes] = 0;
            // ESP_LOGI(RX_TASK_TAG, "Read %d bytes: '%s'", rxBytes, data);
            //  ESP_LOG_BUFFER_HEXDUMP(RX_TASK_TAG, data, rxBytes, ESP_LOG_INFO);调试//---------------
            // printf("-----------------------------------------------------------------------------------------------------------------------------\r\n");
            //------以下的数据暂时不使用
            SportDistance = data[9] + data[10]; //运动目标距离
            // printf("distance:%d\r\n", SportDistance);
            SportEnergy = data[11]; //运动目标能量
            // printf("SportEnergy:%d\r\n", SportEnergy);
            StaticDistance = data[12] + data[13];
            // printf("StaticDistance:%d\r\n", StaticDistance);
            StaticEnergy = data[14];
            //    printf("StaticEnergy:%d\r\n", StaticEnergy);
            DetectionDistance = data[16] + data[17];
            // printf("DetectionDistance:%d\r\n", DetectionDistance);
            //----转出来感觉不是16进制？

            TargetStatus = data[8]; //目标状态
                                    // printf("distance:%d\r\n", TargetStatus);
            if (tcp_client.connected == 1)
            {
                if (TargetStatus != 0 || TargetStautsFlag == 3)
                {
                    //printf("SportEnergy:%d\r\n", SportEnergy);
                    //printf("StaticEnergy:%d\r\n", StaticEnergy);
                    testFlag = 0;
                    if (SportEnergy > 0 && StaticEnergy >= 70 && EnergyFlag == 0)
                    {
                        write(tcp_client.socket_fd, "ESPB090101", 10);
                        EnergyFlag = 1;
                        printf("有人\r\n");
                    }
                    else if (SportEnergy == 0 && StaticEnergy < 70 && EnergyFlag == 1)
                    {
                        write(tcp_client.socket_fd, "ESPB090100", 10);
                        EnergyFlag = 0;
                        printf("无人\r\n");
                    }
                }
                else if (TargetStatus == 0 || TargetStautsFlag == 3)
                {
                    if (testFlag == 0)
                    {
                        write(tcp_client.socket_fd, "ESPB090100", 10);
                        testFlag = 1;
                    }
                }
            }
            else
            {
                TargetStautsFlag = 3;
            }
        }
    }
    free(data);
}