#ifndef FRMTCPCLIENT_H
#define FRMTCPCLIENT_H

#include <QWidget>
#include <QtNetwork>

#include "serial.h"
#include "QDebug"
#include <QTime>
#include<QThread>
#include "write_i.h"
#include "serial.h"
#include "pwmctrl.h"


namespace Ui {
class frmTcpClient;
}

class frmTcpClient : public QWidget
{
    Q_OBJECT

public:
    explicit frmTcpClient(QWidget *parent = 0);
    ~frmTcpClient();
    write_i *write;
    PwmCtrl *PowerValue;

    QTimer *TimerMode;
    QTimer *PWmMode;

private:
    Ui::frmTcpClient *ui;

    bool isOk;
    QTcpSocket *tcpSocket;
    QTimer *timer;
    QTimer *timer2;
    write_i*SubThread;

signals:
    void TurnAngle(int);
    void pwmMode(int,int);
    void StartPwm(int);
    void ServoTurn(int,int,unsigned int,unsigned int);
    void WhileTurn(int);// All while turn
private slots:
    void initForm();
    void initConfig();
    void saveConfig();
    void changeTimer();
    void append(int type, const QString &data, bool clear = false);

    void connected();
    void disconnected();
    void readData();
    void sendData(const QString &data);


private slots:
    void on_btnConnect_clicked();
    void on_btnSave_clicked();
    void on_btnClear_clicked();
    void on_btnSend_clicked();
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_6_clicked();
    void on_pushButton_7_clicked();
};

#endif // FRMTCPCLIENT_H
