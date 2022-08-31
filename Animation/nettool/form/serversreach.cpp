#include "serversreach.h"

#include <QProcess>
#include<QDebug>

ServerSreach::ServerSreach(QObject *parent) : QObject(parent)
{
  connect(this,&ServerSreach::SreachIPArdress,this,&ServerSreach::PrintfServer);
}

void ServerSreach::ServerIPSreach(QString ip_rec)
{
    qDebug()<<"start a new thread";
    for(int i=0;i<255;i++)
    {
        QString ip_ready_ping=ip_rec+QString::number(i);
        qDebug()<<ip_ready_ping;
        QString cmd_ping=QString("ping %1 -n 1 -w %2").arg(ip_ready_ping).arg(1000);
        QProcess p_ping;
        p_ping.start(cmd_ping);
        p_ping.waitForReadyRead(1000);
        p_ping.waitForFinished(1000);
        QString response=QString::fromLocal8Bit(p_ping.readAllStandardOutput());
        if(response.contains("TTL"))
            emit SreachIPArdress(ip_ready_ping);
    }
    emit SerachOver();
    qDebug()<<"finish a new thread";
}

void ServerSreach::PrintfServer(QString address)
{
    qDebug()<<"找到地址："<<address;
}
