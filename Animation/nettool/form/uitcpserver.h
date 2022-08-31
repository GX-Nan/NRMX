#ifndef UITCPSERVER_H
#define UITCPSERVER_H

#include <QDialog>
#include "tcpserver.h"
#include<QObject>
#include"frmtcpserver.h"
#include"app.h"


namespace Ui {
class uiTcpServer;
}

class uiTcpServer : public QDialog
{
    Q_OBJECT

public:
    explicit uiTcpServer(QWidget *parent = nullptr);
    ~uiTcpServer();
    bool isOk;
    TcpServer *tcpServer;
    QTimer *timer;
signals:
    void ServerListen();
    void ServerClose();
    void ReceiveData(QString);
    void SendData(QString&);
    void SendListCount(int);

private:
    Ui::uiTcpServer *ui;
private slots:
    void on_Listen_clicked();

    void on_DisListen_clicked();

    void on_Close_Ui_clicked();

public:
    void initForm();//配置
    void IPForm();
};


#endif // UITCPSERVER_H
