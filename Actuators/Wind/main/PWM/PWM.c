#include "PWM.h"
ledc_channel_config_t LED_Lux_Config;
ledc_channel_config_t LED_Color_Config;
void GPIO_Config()
{
   
}
void PWM_Config()
{
    //------------pwm ---1
    ledc_timer_config_t Lux_Timer =
        {
            .duty_resolution = LEDC_TIMER_8_BIT,
            .freq_hz = 500,
            .speed_mode = LEDC_HIGH_SPEED_MODE,
            .timer_num = LEDC_TIMER_0,
            .clk_cfg = LEDC_AUTO_CLK,
        };
    ledc_timer_config(&Lux_Timer);

    LED_Lux_Config.channel = LEDC_CHANNEL_0,              // PWM ͨ��
        LED_Lux_Config.duty = 0,                          //���ó�ʼpwm״̬
        LED_Lux_Config.gpio_num = Lux_Pin,                //����gpioΪpwm�������
        LED_Lux_Config.speed_mode = LEDC_HIGH_SPEED_MODE, //����Ϊ����ͨ��
        LED_Lux_Config.hpoint = 0,                        // ledcͨ����hpointֵ
        LED_Lux_Config.timer_sel = LEDC_TIMER_0,          // ledc�����Ķ�ʱ��
        ledc_channel_config(&LED_Lux_Config);

    //------------pwm ---2
    ledc_timer_config_t Color_Timer =
        {
            .duty_resolution = LEDC_TIMER_8_BIT,
            .freq_hz = 500,
            .speed_mode = LEDC_HIGH_SPEED_MODE,
            .timer_num = LEDC_TIMER_1,
            .clk_cfg = LEDC_AUTO_CLK,
        };
    ledc_timer_config(&Color_Timer);
    
    LED_Color_Config.channel = LEDC_CHANNEL_1,              // PWM ͨ��
        LED_Color_Config.duty = 0,                          //���ó�ʼpwm״̬
        LED_Color_Config.gpio_num = Color_Pin,                //����gpioΪpwm�������
        LED_Color_Config.speed_mode = LEDC_HIGH_SPEED_MODE, //����Ϊ����ͨ��
        LED_Color_Config.hpoint = 0,                        // ledcͨ����hpointֵ
        LED_Color_Config.timer_sel = LEDC_TIMER_1,          // ledc�����Ķ�ʱ��
        ledc_channel_config(&LED_Color_Config);
}

void Motor_Config() //��ʼ�����ļ�
{
    PWM_Config();
    GPIO_Config();
}

void SetLux(int Lux)
{
    ledc_set_duty(LED_Lux_Config.speed_mode, LED_Lux_Config.channel, Lux*1.1119);//40%ռ�ձ�
    ledc_update_duty(LED_Lux_Config.speed_mode, LED_Lux_Config.channel);
    printf("Lux%d\r\n",Lux);
}
void SetColorTemp(int value)
{
    ledc_set_duty(LED_Color_Config.speed_mode, LED_Color_Config.channel, value*1.1119);//40%ռ�ձ�
    ledc_update_duty(LED_Color_Config.speed_mode, LED_Color_Config.channel);
    printf("Value %d\r\n",value);
}
