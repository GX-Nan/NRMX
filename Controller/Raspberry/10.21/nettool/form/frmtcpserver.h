#ifndef FRMTCPSERVER_H
#define FRMTCPSERVER_H

#include <QWidget>
#include "tcpserver.h"
#include<QObject>
#include <vector>
#include"Information/analysis_air.h"
#include"Information/analysis_cutarin.h"
#include"Information/analysis_door.h"
#include"Information/analysis_light.h"
#include"Information/analysis_wind.h"
#include"Information/analysis_window.h"




namespace Ui {
class frmTcpServer;
}

class frmTcpServer : public QObject
{
    Q_OBJECT

public:
    explicit frmTcpServer(QWidget *parent = 0);
    ~frmTcpServer();



private:
   // Ui::frmTcpServer *ui;
    bool isOk;
    TcpServer *tcpServer;
    QTimer *timer;
  //  Analysis_Air *Air_handle=nullptr;
    Analysis_Door *Door_handle=nullptr;
    Analysis_Wind *Wind_handle=nullptr;
    Analysis_Light *Light_handle=nullptr;
    Analysis_Window *Window_hanle=nullptr;
    Analysis_Cutarin *Cutarin_hanle=nullptr;

private slots:
    void initForm();
    void initIP();
    void initConfig();
    void saveConfig();
    void changeTimer();
    void append(int type, const QString &data, bool clear = false);

    void clientConnected(const QString &ip, int port);
    void clientDisconnected(const QString &ip, int port);
    void sendData(const QString &ip, int port, const QString &data);
    void receiveData(const QString &ip, int port, const QString &data);   

private slots:
    void on_btnListen_clicked();
    void on_btnSave_clicked();
    void on_btnClear_clicked();
    void on_btnSend_clicked();
    void on_btnClose_clicked();
    //-------链接发送信号
signals:
    void TextClear();
    void TextColor(QString);
    void TextAppend(QString);
    void LocalIP(QString);
    void ClientIpGroup(QString);
    void ListCountText(int,QString);
    void Return_Data(QMultiMap<int,QString>);
    //--------
    void Server_Receive_Data(QMultiMap<int,QString>);
    void Esp_Data(QString);


public:
    void RadioBroadcast(QString);//广播
    void Listen();
    void ListenClose();

};

#endif // FRMTCPSERVER_H
