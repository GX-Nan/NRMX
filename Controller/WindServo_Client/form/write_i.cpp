#include "write_i.h"
#include<wiringPi.h>
#include<wiringPiI2C.h>
#include<QDateTime>
#include<QTime>

bool PCA9685_initSuccess = false;
int PCA9685_fd = 0;
bool PCA9685_initSuccess_Two = false;
int PCA9685_fd_Two = 0;
static int WhileFalg=0;
static unsigned short int BaseAnle=800;
//static  int fd_1;
write_i::write_i(QObject *parent) : QObject(parent)
{
    WiringPiSetUp();              //窗口init设置
    Timer=new QTimer(this);
    connect(Timer,&QTimer::timeout,this,&write_i::WhileTurnTimer);
    Timer->start(1000);
}
write_i::~write_i()
{

}

void write_i::WiringPiSetUp()
{
    PCA9685Init();
    PCA9685Init2();
    PCA9685SetPwmFreq(50);
    PCA9685SetPwmFreq_Two(50);
    wiringPiSetup();//初始化wiringpi
}

bool write_i::PCA9685Init()
{
    //初始化
    PCA9685_fd = wiringPiI2CSetup(PCA9685_ADDRESS);
    if (PCA9685_fd <= 0)
        return false;
    PCA9685_initSuccess = true;
    ResetPca9685();
    return true;
}

bool write_i::PCA9685Init2()
{
    PCA9685_fd_Two = wiringPiI2CSetup(PCA9685_ADDRESS2);
    if (PCA9685_fd_Two <= 0)
        return false;
    PCA9685_initSuccess_Two = true;
    ResetPca9685_Two();
    return true;
}

void write_i::PCA9685SetPwmFreq_Two(unsigned short freq)
{
    unsigned char preScale = (PCA9685_CLOCK_FREQ / 4096 / freq) - 1;
    unsigned char oldMode = 0;
    printf("set PWM frequency to %d HZ\n",freq);                       //read old mode
    oldMode = ReadByte_Two(PCA9685_fd_Two, PCA9685_MODE1);                     //setup sleep mode, Low power mode. Oscillator off (bit4: 1-sleep, 0-normal)
    WriteByte_Two(PCA9685_fd_Two, PCA9685_MODE1, (oldMode & 0x7F) | 0x10);     //set freq
    WriteByte_Two(PCA9685_fd_Two, PCA9685_PRE_SCALE, preScale);                //setup normal mode (bit4: 1-sleep, 0-normal)
    WriteByte_Two(PCA9685_fd_Two, PCA9685_MODE1, oldMode);
    usleep(1000);                                                      // >500us
    //setup restart (bit7: 1- enable, 0-disable)
    WriteByte_Two(PCA9685_fd_Two, PCA9685_MODE1, oldMode | 0x80);
    usleep(1000);
}

void write_i::PCA9685SetPwm_Two(unsigned char channel, unsigned short on, unsigned short value)
{
    if (!PCA9685_initSuccess_Two)
    {
        printf("Set Pwm failure!\n");
        return;
    }
    WriteByte_Two(PCA9685_fd_Two, PCA9685_LED0_ON_L + PCA9685_LED_SHIFT * channel, on & 0xFF);
    WriteByte_Two(PCA9685_fd_Two, PCA9685_LED0_ON_H + PCA9685_LED_SHIFT * channel, on >> 8);
    WriteByte_Two(PCA9685_fd_Two, PCA9685_LED0_OFF_L + PCA9685_LED_SHIFT * channel, value & 0xFF);
    WriteByte_Two(PCA9685_fd_Two, PCA9685_LED0_OFF_H + PCA9685_LED_SHIFT * channel, value >> 8);
}

void write_i::SetServoPulse_Two(unsigned int channel, unsigned short pulse)
{
    pulse = pulse * 4096 / 20000;
    PCA9685SetPwm_Two(channel, 0, pulse);
}

bool write_i::WriteByte_Two(int fd, unsigned char regAddr, unsigned char data)
{
    if (wiringPiI2CWriteReg8(fd, regAddr, data) < 0)
        return -1;
    return 0;
}

unsigned char write_i::ReadByte_Two(int fd, unsigned char regAddr)
{
    unsigned char data; // `data` will store the register data
    data = wiringPiI2CReadReg8(fd, regAddr);
    if (data < 0)
        return -1;
    return data;
}

void write_i::ResetPca9685()
{
    if (true == PCA9685_initSuccess)
    {
        //sleep mode, Low power mode. Oscillator off
        WriteByte(PCA9685_fd, PCA9685_MODE1, 0x00);
        WriteByte(PCA9685_fd, PCA9685_MODE2, 0x04);
        usleep(1000);
        //Delay Time is 0, means it always turn into high at the begin
        WriteByte(PCA9685_fd, PCA9685_LED0_ON_L + PCA9685_LED_SHIFT * 0, 0);
        WriteByte(PCA9685_fd, PCA9685_LED0_ON_H + PCA9685_LED_SHIFT * 0, 0);
        WriteByte(PCA9685_fd, PCA9685_LED0_ON_L + PCA9685_LED_SHIFT * 1, 0);
        WriteByte(PCA9685_fd, PCA9685_LED0_ON_H + PCA9685_LED_SHIFT * 1, 0);
        WriteByte(PCA9685_fd, PCA9685_LED0_ON_L + PCA9685_LED_SHIFT * 2, 0);
        WriteByte(PCA9685_fd, PCA9685_LED0_ON_H + PCA9685_LED_SHIFT * 2, 0);
        WriteByte(PCA9685_fd, PCA9685_LED0_ON_L + PCA9685_LED_SHIFT * 3, 0);
        WriteByte(PCA9685_fd, PCA9685_LED0_ON_H + PCA9685_LED_SHIFT * 3, 0);
        usleep(1000);
    }
    else
    {
        printf("pca9685 doesn't init\n");
    }
}

void write_i::PCA9685SetPwmFreq(unsigned short freq)
{
    unsigned char preScale = (PCA9685_CLOCK_FREQ / 4096 / freq) - 1;
    unsigned char oldMode = 0;
    printf("set PWM frequency to %d HZ\n",freq);                       //read old mode
    oldMode = ReadByte(PCA9685_fd, PCA9685_MODE1);                     //setup sleep mode, Low power mode. Oscillator off (bit4: 1-sleep, 0-normal)
    WriteByte(PCA9685_fd, PCA9685_MODE1, (oldMode & 0x7F) | 0x10);     //set freq
    WriteByte(PCA9685_fd, PCA9685_PRE_SCALE, preScale);                //setup normal mode (bit4: 1-sleep, 0-normal)
    WriteByte(PCA9685_fd, PCA9685_MODE1, oldMode);
    usleep(1000);                                                      // >500us
    //setup restart (bit7: 1- enable, 0-disable)
    WriteByte(PCA9685_fd, PCA9685_MODE1, oldMode | 0x80);
    usleep(1000);

}

void write_i::PCA9685SetPwm(unsigned char channel, unsigned short on, unsigned short value)
{
    if (!PCA9685_initSuccess)
    {
        printf("Set Pwm failure!\n");
        return;
    }
    WriteByte(PCA9685_fd, PCA9685_LED0_ON_L + PCA9685_LED_SHIFT * channel, on & 0xFF);
    WriteByte(PCA9685_fd, PCA9685_LED0_ON_H + PCA9685_LED_SHIFT * channel, on >> 8);
    WriteByte(PCA9685_fd, PCA9685_LED0_OFF_L + PCA9685_LED_SHIFT * channel, value & 0xFF);
    WriteByte(PCA9685_fd, PCA9685_LED0_OFF_H + PCA9685_LED_SHIFT * channel, value >> 8);
}

void write_i::SetServoPulse(unsigned int channel, unsigned short pulse)
{
    pulse = pulse * 4096 / 20000;
    PCA9685SetPwm(channel, 0, pulse);
}

bool write_i::WriteByte(int fd, unsigned char regAddr, unsigned char data)
{
    if (wiringPiI2CWriteReg8(fd, regAddr, data) < 0)
        return -1;
    return 0;
}

unsigned char write_i::ReadByte(int fd, unsigned char regAddr)
{
    unsigned char data; // `data` will store the register data
    data = wiringPiI2CReadReg8(fd, regAddr);
    if (data < 0)
        return -1;
    return data;
}

void write_i::ResetPca9685_Two()
{
    if (true == PCA9685_initSuccess_Two)
    {
        //sleep mode, Low power mode. Oscillator off
        WriteByte(PCA9685_fd_Two, PCA9685_MODE1, 0x00);
        WriteByte(PCA9685_fd_Two, PCA9685_MODE2, 0x04);
        usleep(1000);
        //Delay Time is 0, means it always turn into high at the begin
        WriteByte(PCA9685_fd_Two, PCA9685_LED0_ON_L + PCA9685_LED_SHIFT * 0, 0);
        WriteByte(PCA9685_fd_Two, PCA9685_LED0_ON_H + PCA9685_LED_SHIFT * 0, 0);
        WriteByte(PCA9685_fd_Two, PCA9685_LED0_ON_L + PCA9685_LED_SHIFT * 1, 0);
        WriteByte(PCA9685_fd_Two, PCA9685_LED0_ON_H + PCA9685_LED_SHIFT * 1, 0);
        WriteByte(PCA9685_fd_Two, PCA9685_LED0_ON_L + PCA9685_LED_SHIFT * 2, 0);
        WriteByte(PCA9685_fd_Two, PCA9685_LED0_ON_H + PCA9685_LED_SHIFT * 2, 0);
        WriteByte(PCA9685_fd_Two, PCA9685_LED0_ON_L + PCA9685_LED_SHIFT * 3, 0);
        WriteByte(PCA9685_fd_Two, PCA9685_LED0_ON_H + PCA9685_LED_SHIFT * 3, 0);
        usleep(1000);
    }
    else
    {
        printf("pca9685 doesn't init\n");
    }
}

void write_i::ServoTurn(int Angle)
{
    unsigned short int Anle=(unsigned short int)Angle;
    unsigned char i=0;
    unsigned char i2=20;//All Servo
    for(;i<i2;i++)
    {
        SetServoPulse(i, Anle);
        SetServoPulse_Two(i,Anle);
    }
}

void write_i::ServoGroup(int Angle, int Angles2,unsigned int Pin1, unsigned int Pin2)
{
    unsigned short int Anle=(unsigned short int)Angle;
    SetServoPulse(Pin1,Anle);
    SetServoPulse(Pin2,Anle);
}

void write_i::WhileTurn(int Falg)
{
    if(Falg==1)
    {
        WhileFalg=1;
    }
    else {
        WhileFalg=0;
    }
}

void write_i::WhileTurnTimer()
{
    if(WhileFalg!=0){
        if(BaseAnle<=2500){
            for(unsigned char i=0;i<20;i++)
            {
                SetServoPulse(i, BaseAnle);
                SetServoPulse_Two(i,BaseAnle);
            }
            BaseAnle=BaseAnle+10;
        }
        else {
            BaseAnle=800;
        }
    }
}

