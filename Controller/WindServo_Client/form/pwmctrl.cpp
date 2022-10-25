#include "pwmctrl.h"
#include <QDebug>
static int Power=10;
static int flag;

PwmCtrl::PwmCtrl(QObject *parent) : QObject(parent)
{
    wiringPiSetup();//初始化wiringpi

    softPwmCreate(25,0,100);//设置范围
    softPwmCreate(26,0,100);//设置范围
    softPwmCreate(22,0,100);//设置范围
    softPwmCreate(23,0,100);//设置范围
    softPwmCreate(24,0,100);//设置范围
    softPwmCreate(27,0,100);//设置范围
    softPwmCreate(28,0,100);//设置范围
    softPwmCreate(29,0,100);//设置范围

    Timer=new QTimer(this);
    connect(Timer,&QTimer::timeout,this,&PwmCtrl::PowerStep);
    Timer->start(3000);
}

void PwmCtrl::PowerChange(int Value,int Start)
{
    softPwmWrite(25,0);
    if(Start==1)
    {
        softPwmWrite(25,Value);
        softPwmWrite(26,Value);
        softPwmWrite(22,Value);
        softPwmWrite(23,Value);
        softPwmWrite(24,Value);
        softPwmWrite(27,Value);
        softPwmWrite(28,Value);
        softPwmWrite(29,Value);
    }
    else if(Start==0){
        qDebug()<<"fuck you";
        flag=0;
    }
    else if(Start==2)
    {
        flag=2;
    }


}

void PwmCtrl::PowerStep()
{
    if(flag==0)
    {
        qDebug()<<"stop";
    }
    else if(flag==2){
        if(Power==80)
        {
            for(;Power>=0;Power-=10)
            {
                softPwmWrite(25,Power);
                softPwmWrite(26,Power);
                softPwmWrite(22,Power);
                softPwmWrite(23,Power);
                softPwmWrite(24,Power);
                softPwmWrite(27,Power);
                softPwmWrite(28,Power);
                softPwmWrite(29,Power);
                qDebug()<<"Power:"<<Power;
                delay(3000);
            }
            Power=0;
            qDebug()<<"Clear";
        }
        softPwmWrite(25,Power);
        softPwmWrite(26,Power);
        softPwmWrite(22,Power);
        softPwmWrite(23,Power);
        softPwmWrite(24,Power);
        softPwmWrite(27,Power);
        softPwmWrite(28,Power);
        softPwmWrite(29,Power);
        Power+=10;
        qDebug()<<"Power:"<<Power;
    }
}

