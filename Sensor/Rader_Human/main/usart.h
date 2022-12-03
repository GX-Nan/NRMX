#ifndef usart_h_
#define usart_h_

#ifndef usart_c_
#define usart_cx_ extern
#else
#define usart_cx_
#endif

#include <stdio.h>
#include <string.h>
#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include "driver/gpio.h"
#include "driver/timer.h"
#include "esp_timer.h"
#include "driver/uart.h"
#include "event_handler.h"
#include "public_variable.h"
#include "tcp_client_select.h"
#include "wifi_softap_sta.h"

static int TargetStatus;          //目标状态
static int SportDistance = 0;     //运动目标距离
static int SportEnergy = 0;       //运动目标能量值
static int StaticDistance = 0;    //静止目标距离
static int StaticEnergy = 0;      //静止目标能量值
static int DetectionDistance = 0; //探测距离
static int TargetStautsFlag = 0;  //取消一直上传
static int EnergyFlag=0;//判断能量的
static int testFlag=0;

void Usart_main();
void rx_task();
// void usart_send(uint8_t *data ,int len);

#endif