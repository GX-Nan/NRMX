#ifndef WRITE_I_H
#define WRITE_I_H

#include <QObject>
#include <QMessageBox>
#include <QDebug>
#include <QThread>
#include <QTimer>
#include"pwmctrl.h"
#include <stdbool.h>
#include <stdio.h>
#include "wiringPi.h"
#include <wiringPiI2C.h>
#include <unistd.h>
#include"softPwm.h"


#define PCA9685_ADDRESS			0x40       //pca9685地址
#define PCA9685_ADDRESS2		0x41       //pca9685地址
#define PCA9685_CLOCK_FREQ		25000000		//PWM频率25MHz
#define PCA9685_MODE1			0x00
#define PCA9685_MODE2			0x01
#define PCA9685_PRE_SCALE		0xFE
#define PCA9685_LED0_ON_L		0x06
#define PCA9685_LED0_ON_H		0x07
#define PCA9685_LED0_OFF_L		0x08
#define PCA9685_LED0_OFF_H		0x09
#define PCA9685_LED_SHIFT		4

class write_i : public QObject
{
    Q_OBJECT
public:
    explicit write_i(QObject *parent = nullptr);
    ~write_i();

    void WiringPiSetUp();  //初始化wiringPi
    QTimer *Timer;
    QTimer *Timer2;
    PwmCtrl *WindWork;

private:
    bool PCA9685Init();
    void ResetPca9685();
    void PCA9685SetPwmFreq(unsigned short freq);
    void PCA9685SetPwm(unsigned char channel, unsigned short on, unsigned short value);
    void SetServoPulse(unsigned int channel, unsigned short pulse);
    bool WriteByte(int fd, unsigned char regAddr, unsigned char data);
    unsigned char ReadByte(int fd, unsigned char regAddr);
   // ----
    void ResetPca9685_Two();
    bool PCA9685Init2();
    void PCA9685SetPwmFreq_Two(unsigned short freq);
    void PCA9685SetPwm_Two(unsigned char channel, unsigned short on, unsigned short value);
    void SetServoPulse_Two(unsigned int channel, unsigned short pulse);
    bool WriteByte_Two(int fd, unsigned char regAddr, unsigned char data);
    unsigned char ReadByte_Two(int fd, unsigned char regAddr);

signals:
    void receive_data(QByteArray);

    void query_status_again(int);

    void WindPower(int);

public slots:
    void ServoTurn(int);//All
    void ServoGroup(int, int,unsigned int, unsigned int);
    void WhileTurn(int);
    void WhileTurnTimer();





signals:
    void readSignal(); // 当下位机中有数据发送过来时就会触发这个信号，以提示其它类对象
public slots:




};
//class WindPower :public QObject
//{
//    explicit WindPower(QObject *parent = nullptr);
//    ~WindPower();

//public slots:
//    void PwmCrtl(int Mode);
//};

#endif // WRITE_I_H
