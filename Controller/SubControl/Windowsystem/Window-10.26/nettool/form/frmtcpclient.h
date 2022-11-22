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
    int StopReturn=0;
private:
//    Ui::frmTcpClient *ui;

    bool isOk;
    QTcpSocket *tcpSocket;//套接字节
    QTimer *timer;

private slots:
    void initForm();
    void initConfig();
    void saveConfig();
    void changeTimer();
    void append(int type, const QString &data, bool clear = false);
    void connected();
    void disconnected();
    void readData();
public slots:
    void ClientConnect();
    void ClientDisconnect();
    void sendData(const QString &data);
    void RadioBroadcast(QString);
    void Analysis_Curtains(QString);
    void Analysis_Window(QString);
    void RecoverSignals();
    void StopSignals();
signals:
    void TextClear();
    void TextColor(QString);
    void TextAppend(QString);
    void Updata_Curtain(int,int);
    void Updata_Window(int,int);

};

#endif // FRMTCPCLIENT_H
