#include "Dc_Motor.h"
ledc_channel_config_t Dc_Motor_Config;
void GPIO_Config()
{
    gpio_config_t io_conf = {
        .pin_bit_mask = (1ull << Pin2) | (1ull << Pin1),
        .mode = GPIO_MODE_OUTPUT,
        .pull_down_en = 0,
        .pull_up_en = 0,
    };
    gpio_config(&io_conf);
}
void PWM_Config()
{
    ledc_timer_config_t Pwm_Timer =
        {
            .duty_resolution = LEDC_TIMER_8_BIT,
            .freq_hz = 2000,
            .speed_mode = LEDC_HIGH_SPEED_MODE,
            .timer_num = LEDC_TIMER_0,
            .clk_cfg = LEDC_AUTO_CLK,
        };
    ledc_timer_config(&Pwm_Timer);

    Dc_Motor_Config.channel = LEDC_CHANNEL_0,              // PWM 通道
        Dc_Motor_Config.duty = 0,                          //设置初始pwm状态
        Dc_Motor_Config.gpio_num = Pwm_Pin,                //设置gpio为pwm输出引脚
        Dc_Motor_Config.speed_mode = LEDC_HIGH_SPEED_MODE, //设置为高速通道
        Dc_Motor_Config.hpoint = 0,                        // ledc通道的hpoint值
        Dc_Motor_Config.timer_sel = LEDC_TIMER_0,          // ledc依赖的定时器
        ledc_channel_config(&Dc_Motor_Config);
}
void Clockwise() //顺时针
{
    gpio_set_level(Pin1, 1);
    gpio_set_level(Pin2, 0);
}
void AntiClockwise() //逆时针
{
    gpio_set_level(Pin1, 0);
    gpio_set_level(Pin2, 1);
}
void Stop()
{
    gpio_set_level(Pin1, 0);
    gpio_set_level(Pin2, 0);
    printf("Stop--Motor \r\n");
}
void Motor_Config() //初始配置文件
{
    PWM_Config();
    GPIO_Config();
}
void Slow_Motion_Up(int Falg) //
{
    if (Falg == 1) //正转时------增加pwm为 增大电压
    {
        for (int StepperValue = 0; StepperValue <= 240; StepperValue = StepperValue + 10)
        {
            ledc_set_duty(Dc_Motor_Config.speed_mode, Dc_Motor_Config.channel, StepperValue);
            ledc_update_duty(Dc_Motor_Config.speed_mode, Dc_Motor_Config.channel);
            vTaskDelay(200 / portTICK_RATE_MS);
        }
    }
}
void Slow_Motion_Down(int Falg) //关闭 缓动
{
    if (Falg == 1)//正转时------减少pwm为 减少电压
    {
        for (int StepperValue = 240; StepperValue >= 0; StepperValue = StepperValue - 10)
        {
            ledc_set_duty(Dc_Motor_Config.speed_mode, Dc_Motor_Config.channel, StepperValue);
            ledc_update_duty(Dc_Motor_Config.speed_mode, Dc_Motor_Config.channel);
            vTaskDelay(200 / portTICK_RATE_MS);
        }
    }
}
void V_Max()
{
    ledc_set_duty(Dc_Motor_Config.speed_mode, Dc_Motor_Config.channel, 240);
    ledc_update_duty(Dc_Motor_Config.speed_mode, Dc_Motor_Config.channel);
}
