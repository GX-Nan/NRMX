#include "uitcpserver.h"
#include "ui_uitcpserver.h"

uiTcpServer::uiTcpServer(QWidget *parent) :
    QDialog(parent,Qt::WindowTitleHint | Qt::CustomizeWindowHint),
    ui(new Ui::uiTcpServer)
{
    ui->setupUi(this);
    initForm();//连接配置
    IPForm();//搜索本地ip
    qDebug()<<"链接状态:"<<App::TcpStation;
    if(App::TcpStation==1)
    {
        ui->Listen->setText("监听中");
    }
}

uiTcpServer::~uiTcpServer()
{
    delete ui;
}

void uiTcpServer::initForm()
{
    frmTcpServer *TaskTcpServer=new frmTcpServer;

    connect(TaskTcpServer,&frmTcpServer::ClientIpGroup,this,[=]( const QString &ClientIP)//显示有多少客户端连接
    {
        ui->listWidget->addItem(ClientIP);
        ui->labCount->setText(QString("共 %1 个客户端").arg(ui->listWidget->count()));
    });
    connect(TaskTcpServer,&frmTcpServer::ListCountText,this,[=](int row,QString str)//listwidget清理
    {
        qDebug()<<"clear"<<ui->listWidget->item(0)->text()<<str;

        for (int i = 0; i < ui->listWidget->count(); i++) {
            if (ui->listWidget->item(i)->text() == str) {
                row = i;
                break;
            }
        }
        delete ui->listWidget->takeItem(row);
        ui->labCount->setText(QString("共 %1 个客户端").arg(ui->listWidget->count()));
    });
    connect(this,&uiTcpServer::SendData,TaskTcpServer,&frmTcpServer::RadioBroadcast);//广播
    connect(this,&uiTcpServer::ServerListen,TaskTcpServer,&frmTcpServer::Listen);//监听
    connect(this,&uiTcpServer::ServerClose,TaskTcpServer,&frmTcpServer::ListenClose);//关闭监听

    connect(TaskTcpServer,&frmTcpServer::TextClear,this,[=]
    {
        ui->txtMain->clear();
    });
    connect(TaskTcpServer,&frmTcpServer::TextColor,this,[=](QString Color)
    {
        ui->txtMain->setTextColor(QColor(Color));
    });
    connect(TaskTcpServer,&frmTcpServer::TextAppend,this,[=](QString Msg)
    {
        ui->txtMain->append(Msg);
    });

    QThread *Task1=new QThread();
    TaskTcpServer->moveToThread(Task1);
    Task1->start();
    ui->txtListenPort->setText(QString::number(App::TcpServerPort));

}

void uiTcpServer::IPForm()
{
    QStringList ips;
    QList<QNetworkInterface> netInterfaces = QNetworkInterface::allInterfaces();
    foreach(const QNetworkInterface  &netInterface, netInterfaces) {
        //移除虚拟机和抓包工具的虚拟网卡
        QString humanReadableName = netInterface.humanReadableName().toLower();
        if(humanReadableName.startsWith("vmware network adapter") || humanReadableName.startsWith("npcap loopback adapter")) {
            continue;
        }

        //过滤当前网络接口
        bool flag = (netInterface.flags() == (QNetworkInterface::IsUp | QNetworkInterface::IsRunning | QNetworkInterface::CanBroadcast | QNetworkInterface::CanMulticast));
        if(flag) {
            QList<QNetworkAddressEntry> addrs = netInterface.addressEntries();
            foreach(QNetworkAddressEntry addr, addrs) {
                //只取出IPV4的地址
                if(addr.ip().protocol() == QAbstractSocket::IPv4Protocol) {
                    QString ip4 = addr.ip().toString();
                    if(ip4 != "127.0.0.1") {
                        ips.append(ip4);
                    }
                }
            }
        }
    }
    ui->cboxListenIP->addItems(ips);
    ui->cboxListenIP->addItem("127.0.0.1");
}


void uiTcpServer::on_Listen_clicked()
{
    if(ui->Listen->text()=="监听中")
    {
        QMessageBox msgBox;
        msgBox.setText("服务器正在监听中");
        msgBox.exec();
    }
    else
    {
        if(App::TcpStation==0){
            emit ServerListen();
            App::TcpStation=1;
            qDebug()<<"界面线程ID"<<QThread::currentThread();
            ui->Listen->setText("监听中");
        }
        else {
            ui->Listen->setText("监听中");
        }
    }
}

void uiTcpServer::on_DisListen_clicked()
{
    emit ServerClose();
    ui->Listen->setText("开始监听");
    App::TcpStation=0;
}

void uiTcpServer::on_Close_Ui_clicked()
{
    this->hide();
}
