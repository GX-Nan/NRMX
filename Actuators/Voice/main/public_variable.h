#ifndef public_variable_h_
#define public_variable_h_

#ifndef public_variable_c_
#define public_variable_cx_ extern
#else
#define public_variable_cx_
#endif

#include <stdio.h>
#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include "freertos/event_groups.h"
#include "freertos/ringbuf.h"
#include "lwip/sockets.h"
#include "lwip/netdb.h"
#include "esp_system.h"
#include "esp_wifi.h"
#include "esp_netif.h"
#include "esp_log.h"

#define Window1Open  4  //窗户1开启
#define Window1close 15 //窗户1关闭
#define Window1Stop 2  //窗户1停止
//-----------窗户2引脚
#define Window2Open 25  //窗户2开启
#define Window2close 32 //窗户2关闭
#define Window2Stop 33  //窗户2停止
//-----------窗帘引脚
#define CurtainLeft  18
#define CurtainRight  19
#define CurtainUp  21
#define CurtainDown  23
#define CurtainStop  22

typedef struct pv_tcp_server_select_struct
{
    RingbufHandle_t ringbuf_handle;
    SemaphoreHandle_t SemaphoreHandle_t_count;
    int tcp_server_select_port;
    int clientfds[FD_SETSIZE - 1]; //记录客户端的socket_fd
    int index;
    int clientfds_index;
    fd_set all_set;
    uint8_t read_buff[1500]; //接收数据的缓存数组
} pv_tcp_server_select_struct_t;

typedef struct pv_tcp_client_select_struct
{
    int port;
    char ip[128];
    int socket_fd;
    char connected;
    char read_buff[1500];    //接收数据的缓存数组
    char MessageJudge[1500]; //判断数据的数组
    char test[50];
    void (*CallBack)(char *data, int len);

} pv_tcp_client_select_struct_t;

#endif