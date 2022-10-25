#include <stdio.h>
#include "esp_system.h"
#include "esp_log.h"
#include "esp_err.h"
#include "nvs_flash.h"  
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/ledc.h"

#define Lux_Pin 25
#define Color_Pin  27

void GPIO_Config();
void PWM_Config();
void Motor_Config();
void SetLux(int Lux);
void SetColorTemp(int value);
