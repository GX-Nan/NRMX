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

#define gpio_pin 5

void Read_GPIO();
void GPIO_init();
void Infra_Red_Main();