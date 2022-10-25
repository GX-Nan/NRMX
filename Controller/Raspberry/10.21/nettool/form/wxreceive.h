#ifndef WXRECEIVE_H
#define WXRECEIVE_H

#include <QObject>
#include <Python.h>
#include <QDebug>
#include <pythreadstatelock.h>
#include "analysis_air.h"
class WxReceive : public QObject
{
    Q_OBJECT
public:
    explicit WxReceive(QObject *parent = nullptr);
    void Online();//登录
    void Crawl();//抓取指令
    void Python_Init();//python初始化
    void KeepCrawl();
    void Analysis(int);
signals:
    void RadioBroadcast(QString);//返回
    void Light_Status(int,int,int);
    void Air_Status(int);
    void Window_Status(int,int);
    void Curtain_Status(int,int);
    void Wind_Status(int);//不确定之后会不会加东西，fun部分就没传过去了

public slots:
};

#endif // WXRECEIVE_H
