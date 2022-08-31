#ifndef UIIPSREACH_H
#define UIIPSREACH_H

#include <QDialog>
#include"app.h"
#include"serversreach.h"
#include"qlistwidgetmouse.h"
#include <QMouseEvent>
#include"frmtcpclient.h"

namespace Ui {
class UiIPSreach;
}

class UiIPSreach : public QDialog
{
    Q_OBJECT

public:
    explicit UiIPSreach(QWidget *parent = nullptr);
    ~UiIPSreach();

    ServerSreach *Sreach;//搜索的子线程
    frmTcpClient *client;//tcp的子线程

    QString& SystemIP();
    void ClientConfig();//连接子线程的配置
    void InTaskFindIP(QString &IP);
    void initForm();//配置连接

private slots:
    void on_FindIP_clicked();
    void on_ClientSend_clicked();
    void on_ToConnect_clicked();
    void on_Disconnect_clicked();


signals:
     void clientConnect();//测试
     void ClientDisconnect();//断开连接
     void ClientConnect();//建立连接
     void ClientSend(const QString);//发送信息
     void SreachIP(QString);//查找服务器IP
     void ClientRecv(QString);
public slots:
     void lineeditEnable();//返回你选中的iteam内的text
     void on_pushButton_clicked();

private:
    Ui::UiIPSreach *ui;
};

#endif // UIIPSREACH_H
