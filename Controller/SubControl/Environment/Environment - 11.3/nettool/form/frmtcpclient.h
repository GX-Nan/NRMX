#ifndef FRMTCPCLIENT_H
#define FRMTCPCLIENT_H

#include <QWidget>
#include <QtNetwork>
#include<QThread>
#include <QCoreApplication>
#include <unistd.h>

//namespace Ui {
//class frmTcpClient;
//}

class frmTcpClient : public QObject
{
    Q_OBJECT

public:
    explicit frmTcpClient(QObject *parent = 0);
    ~frmTcpClient();
    void ClientRecv();

private:
//    Ui::frmTcpClient *ui;

    bool isOk;
    QTcpSocket *tcpSocket;//套接字节
    QTimer *timer;
    int StopReturn=0;

private slots:
    void initForm();
    void initConfig();
    void saveConfig();
    void changeTimer();
    void append(int type, const QString &data, bool clear = false);
    void connected();
    void disconnected();
    void readData();
    void Analysis_Air(QString);
    void Analysis_Light(QString);
    void Air_Decode(int Value);
public slots:
    void ClientConnect();
    void ClientDisconnect();
    void sendData(const QString &data);
    void RadioBroadcast(QString);
    void SignalsRecover();
    void SignalsStop();
signals:
    void TextClear();
    void TextColor(QString);
    void TextAppend(QString);
    void Air_UiValue(int);
    void StatusSignals(int Function,int Sub,int Value);
    void OutSideTemp(int);
    void OutSideHum(int);

};

#endif // FRMTCPCLIENT_H
