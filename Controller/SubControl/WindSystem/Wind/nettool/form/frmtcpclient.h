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
    void Analysis_Wind(QString);
public slots:
    void ClientConnect();
    void ClientDisconnect();
    void sendData(const QString &data);
    void RadioBroadcast(QString);
    void SignalsRecover();
    void StopSignals();
signals:
    void TextClear();
    void TextColor(QString);
    void TextAppend(QString);
    void Updata_Wind(int);
    void OutSideTemp(int);
    void OutSideHum(int);
    void OutSideSo2(int);
    void OutSideNo2(int);
    void OutSidePm25(int);
    void OutSidePm10(int);
    void OutSideAQI(int);

};

#endif // FRMTCPCLIENT_H
