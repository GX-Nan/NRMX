#ifndef WXSEND_H
#define WXSEND_H

#include <QObject>
#include <Python.h>
#include <QDebug>
#include <string>
#include<stdio.h>
#include <pythreadstatelock.h>

class WxSend : public QObject
{
    Q_OBJECT
public:
    explicit WxSend(QObject *parent = nullptr);
    void SendData(QString,int);//发送数据给服务器
    void Python_Init();
signals:

public slots:
};

#endif // WXSEND_H
