#ifndef PWMCTRL_H
#define PWMCTRL_H

#include <QObject>
#include"wiringPi.h"
#include"softPwm.h"
#include<QThread>
#include<QTimer>


class PwmCtrl : public QObject
{
    Q_OBJECT
public:
    explicit PwmCtrl(QObject *parent = nullptr);
public:
    void PowerChange(int Value,int Start);
    QTimer *Timer;
    void PowerStep();
signals:
    void Work();
public slots:
};

#endif // PWMCTRL_H
