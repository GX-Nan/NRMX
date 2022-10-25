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
signals:
    void TextClear();
    void TextColor(QString);
    void TextAppend(QString);
};

#endif // FRMTCPCLIENT_H
