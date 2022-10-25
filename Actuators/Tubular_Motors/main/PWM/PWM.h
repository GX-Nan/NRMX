#include <stdio.h>
#include "esp_system.h"
#include "esp_log.h"
#include "esp_err.h"
#include "nvs_flash.h"  
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/ledc.h"
#include "driver/gpio.h"

#define Lux_Pin 27
#define Color_Pin  25
#define Clock 14//í˜•rá˜
#define Counter 15//ÄæÊ±Õë

static int CurrentValue;

void GPIO_Config();
void PWM_Config();
void Motor_Config();
void SetLux(int Lux);
void SetColorTemp(int value);

void StopMotor();
void ClockWise();
void CounterClockWise();
void SetLight(int);
