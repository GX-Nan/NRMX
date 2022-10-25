#define usart_c_
#include "usart.h"

// // static const char *TAG = "usart_function";

#define RX2_BUF_SIZE (1024)
#define TX2_BUF_SIZE (512)
#define TXD2_PIN (GPIO_NUM_12)
#define RXD2_PIN (GPIO_NUM_13)

extern pv_tcp_client_select_struct_t tcp_client;
/*
===========================
全局变量定义
===========================
*/

/*
===========================
函数声明
===========================
*/
void uart2_rx_task();

/*
* esp32双路串口配置
* @param[in]   void  		       :无
* @retval      void                :无
* @note        修改日志
*               Ver0.0.1:
                    hx-zsj, 2018/08/06, 初始化版本\n
*/
void uart_init(void)
{
    //串口配置结构体
    uart_config_t uart2_config;

    //串口参数配置->uart2
    uart2_config.baud_rate = 115200;                     //波特率
    uart2_config.data_bits = UART_DATA_8_BITS;         //数据位
    uart2_config.parity = UART_PARITY_DISABLE;         //校验位
    uart2_config.stop_bits = UART_STOP_BITS_1;         //停止位
    uart2_config.flow_ctrl = UART_HW_FLOWCTRL_DISABLE; //硬件流控
    uart_param_config(UART_NUM_2, &uart2_config);      //设置串口
    // IO映射-> T:IO12  R:IO13
    uart_set_pin(UART_NUM_2, TXD2_PIN, RXD2_PIN, UART_PIN_NO_CHANGE, UART_PIN_NO_CHANGE);
    //注册串口服务即使能+设置缓存区大小
    uart_driver_install(UART_NUM_2, RX2_BUF_SIZE * 2, TX2_BUF_SIZE * 2, 0, NULL, 0);
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
    uart_write_bytes(UART_NUM_2, "uart2 test OK ", strlen("uart2 test OK "));
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
    uint8_t *data = (uint8_t *)malloc(RX2_BUF_SIZE + 1);
    int Data_Judge = (int)malloc(RX2_BUF_SIZE + 2);
    char Send_Data=(char)malloc(50);

    while (1)
    {
        const int rxBytes = uart_read_bytes(UART_NUM_2, data, RX2_BUF_SIZE, 10 / portTICK_RATE_MS);
        if (rxBytes > 0)
        {
            data[rxBytes] = 0;
            printf("uart Data :%d\r\n", (int)*data);
            Data_Judge = (int)*data;
            printf("Data_Judge:%d\r\n", Data_Judge);
            if (tcp_client.connected == 1) //判断一下是否已经连接
            {

                switch (Data_Judge)
                {
                case 1: //打开新风
                    printf("wind-Turn on\r\n");
                    write(tcp_client.socket_fd, "ZB60101091", 10);//1.载体 2.发送的变量 3.长度
                    break;
                case 2: //关闭新风
                    printf("wind-Turn Off\r\n");
                    write(tcp_client.socket_fd, "ZB60101181", 10);
                    break;
                case 3: //打开空调
                    printf("Air-Turn On\r\n");
                    write(tcp_client.socket_fd, "ZB20201011", 10);
                    break;
                case 4: //关闭空调
                    printf("Air-Turn Off\r\n");
                    write(tcp_client.socket_fd, "ZB20201001", 10);
                    break;
                case 5: //风速低
                    printf("Air-Low\r\n");
                    write(tcp_client.socket_fd, "ZB20201021", 10);
                    break;
                case 6: //风速中
                    printf("Air-Low\r\n");
                    write(tcp_client.socket_fd, "ZB20201031", 10);
                    break;
                case 7: //风速高
                    write(tcp_client.socket_fd, "ZB20201041", 10);
                    break;
                case 8: //除湿模式
                    write(tcp_client.socket_fd, "ZB20201101", 10);
                    break;
                case 9: //暖气
                    write(tcp_client.socket_fd, "ZB20201111", 10);
                    break;
                case 16: //极速降温
                    write(tcp_client.socket_fd, "ZB20201091", 10);
                    write(tcp_client.socket_fd, "ZB20201161", 10);
                    break;
                case 17: //舒适模式
                    write(tcp_client.socket_fd, "ZB20201091", 10);
                    write(tcp_client.socket_fd, "ZB20201231", 10);
                    break;
                case 18: //极速升温
                    write(tcp_client.socket_fd, "ZB20201111", 10);
                    write(tcp_client.socket_fd, "ZB20201311", 10);
                    break;
                case 19: //打开加湿器
                    printf("Air-Low\r\n");
                    break;
                case 20: //关闭加湿器
                    printf("Air-Low\r\n");
                    break;
                case 21: //制冷模式
                    write(tcp_client.socket_fd, "ZB20201091", 10);
                    break;
                case 22: //环绕模式
                    printf("Air-Low\r\n");
                    write(tcp_client.socket_fd, "ZB60101041", 10);
                    break;
                case 23: //海洋模式
                    printf("Air-Low\r\n");
                    write(tcp_client.socket_fd, "ZB60101021", 10);
                    break;
                case 24: //自然模式
                    printf("Air-Low\r\n");
                    write(tcp_client.socket_fd, "ZB60101011", 10);
                    break;
                case 25: //立体模式
                    printf("Air-Low\r\n");
                    write(tcp_client.socket_fd, "ZB60101031", 10);
                    break;
                case 32: //关闭所有模式
                    printf("Air-Low\r\n");
                    write(tcp_client.socket_fd, "ZB60101071", 10);
                    break;
                case 33: //打开追踪模式
                    printf("Air-Low\r\n");
                    write(tcp_client.socket_fd, "ZB60101191", 10);
                    break;
                case 34: //区域一新风
                    printf("Air-Low\r\n");
                    write(tcp_client.socket_fd, "ZB60101211", 10);
                    break;
                case 35: //区域二新风
                    printf("Air-Low\r\n");
                    write(tcp_client.socket_fd, "ZB60101221", 10);
                    break;
                case 36: //区域三新风
                    printf("Air-Low\r\n");
                    write(tcp_client.socket_fd, "ZB60101231", 10);
                    break;
                case 37: //区域四新风
                    printf("Air-Low\r\n");
                    write(tcp_client.socket_fd, "ZB60101241", 10);
                    break;
                case 38: //关闭区域一新风
                    printf("Air-Low\r\n");
                    write(tcp_client.socket_fd, "ZB60101251", 10);
                    break;
                case 39: //关闭区域二新风
                    printf("Air-Low\r\n");
                    write(tcp_client.socket_fd, "ZB60101261", 10);
                    break;
                case 40: //关闭区域三新风
                    printf("Air-Low\r\n");
                    write(tcp_client.socket_fd, "ZB60101271", 10);
                    break;
                case 41: //关闭区域四新风
                    printf("Air-Low\r\n");
                    write(tcp_client.socket_fd, "ZB60101281", 10);
                    break;
                case 48: //开灯
                    printf("Air-Low\r\n");
                    write(tcp_client.socket_fd, "ZB20300041", 10);
                    break;
                case 49: //关灯
                    printf("Air-Low\r\n");
                    write(tcp_client.socket_fd, "ZB20300051", 10);
                    break;
                case 50: //开一号灯
                    printf("Air-Low\r\n");
                    write(tcp_client.socket_fd, "ZB20301041", 10);
                    break;
                case 51: //开二号灯
                    printf("Air-Low\r\n");
                    write(tcp_client.socket_fd, "ZB20302041", 10);
                    break;
                case 52: //开三号灯
                    printf("Air-Low\r\n");
                    write(tcp_client.socket_fd, "ZB20303041", 10);
                    break;
                case 53: //开四号灯
                    printf("Air-Low\r\n");
                    write(tcp_client.socket_fd, "ZB20304041", 10);
                    break;
                case 54: //关闭一号灯
                    printf("Air-Low\r\n");
                    write(tcp_client.socket_fd, "ZB20301051", 10);
                    break;
                case 55: //关闭二号灯
                    printf("Air-Low\r\n");
                    write(tcp_client.socket_fd, "ZB20302051", 10);
                    break;
                case 56: //关闭三号灯
                    printf("Air-Low\r\n");
                    write(tcp_client.socket_fd, "ZB20303051", 10);
                    break;
                case 57: //关闭四号灯
                    printf("Air-Low\r\n");
                    write(tcp_client.socket_fd, "ZB20304051", 10);
                    break;
                case 64: //开左灯
                    printf("Air-Low\r\n");
                    write(tcp_client.socket_fd, "ZB20304041", 10);
                    write(tcp_client.socket_fd, "ZB20301041", 10);
                    break;
                case 65: //开右灯
                    printf("Air-Low\r\n");
                    write(tcp_client.socket_fd, "ZB20302041", 10);
                    write(tcp_client.socket_fd, "ZB20303041", 10);
                    break;
                case 66: //关左灯
                    printf("Air-Low\r\n");
                    write(tcp_client.socket_fd, "ZB20304051", 10);
                    write(tcp_client.socket_fd, "ZB20301051", 10);
                    break;
                case 67: //关右灯
                    printf("Air-Low\r\n");
                    write(tcp_client.socket_fd, "ZB20302051", 10);
                    write(tcp_client.socket_fd, "ZB20303051", 10);
                    break;
                case 68: //开前灯
                    printf("Air-Low\r\n");
                    write(tcp_client.socket_fd, "ZB20301041", 10);
                    write(tcp_client.socket_fd, "ZB20303041", 10);
                    break;
                case 69: //关前灯
                    printf("Air-Low\r\n");
                    write(tcp_client.socket_fd, "ZB20301051", 10);
                    write(tcp_client.socket_fd, "ZB20303051", 10);
                    break;
                case 70: //关后灯
                    printf("Air-Low\r\n");
                    write(tcp_client.socket_fd, "ZB20302051", 10);
                    write(tcp_client.socket_fd, "ZB20304051", 10);
                    break;
                case 71: //开后灯
                    write(tcp_client.socket_fd, "ZB20302041", 10);
                    write(tcp_client.socket_fd, "ZB20304041", 10);
                    printf("Air-Low\r\n");
                    break;
                case 72: //开窗
                    printf("Air-Low\r\n");
                    write(tcp_client.socket_fd, "ZB10101011", 10);
                    write(tcp_client.socket_fd, "ZB10102011", 10);
                    break;
                case 73: //关窗
                    printf("Air-Low\r\n");
                    write(tcp_client.socket_fd, "ZB10101021", 10);
                    write(tcp_client.socket_fd, "ZB10102021", 10);
                    break;
                case 80: //开窗帘
                    printf("Air-Low\r\n");
                    write(tcp_client.socket_fd, "ZB10201011", 10);
                    break;
                case 81: //关窗帘
                    printf("Air-Low\r\n");
                    write(tcp_client.socket_fd, "ZB10201001", 10);
                    break;
                default:
                    printf("错误指令");
                    break;
                }
                
            }
            // if (strcmp((char)*data, "1") == 0)
            // {
            //     printf("wake up");
            // }
            //将接收到的数据发出去
           // uart_write_bytes(UART_NUM_2, (char *)data, rxBytes);
        }
    }
    free(data);
}