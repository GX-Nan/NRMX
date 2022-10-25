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

void Usart_main();
//void usart_send(uint8_t *data ,int len);

#endif