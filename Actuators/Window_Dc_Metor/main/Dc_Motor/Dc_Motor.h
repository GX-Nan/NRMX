#include <stdio.h>
#include "esp_system.h"
#include "esp_log.h"
#include "esp_err.h"
#include "nvs_flash.h"  
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/ledc.h"

#define Pwm_Pin 27
#define Pin1 14
#define Pin2 26

void GPIO_Config();
void PWM_Config();
void Clockwise();
void AntiClockwise();
void Stop();
void Slow_Motion_Up(int Falg);
void Slow_Motion_Down(int Falg);
void Motor_Config();
void V_Max();