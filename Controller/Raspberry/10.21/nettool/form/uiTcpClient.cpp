#include "uiTcpClient.h"
#include "ui_uiTcpClient.h"

UiIPSreach::UiIPSreach(QWidget *parent) :
    QDialog(parent,Qt::WindowTitleHint | Qt::CustomizeWindowHint),
    ui(new Ui::UiIPSreach)
{
    ui->setupUi(this);
    ClientConfig();//连接服务的配置
    initForm();//显示配置
    connect(ui->Mouselist,SIGNAL(itemSelectionChanged()),this,SLOT(lineeditEnable()));
    qDebug()<<"innn---config";

}

UiIPSreach::~UiIPSreach()
{
    delete ui;
}

void UiIPSreach::on_FindIP_clicked()
{
    // QPointer<QString> ip=SystemIP();
    if(ui->FindIP->text()=="搜索中")
    {
        QMessageBox msgBox;
        msgBox.setText("已开启搜索，请勿重复搜索");
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.exec();
    }
    else {
        QString& ip=SystemIP();
        qDebug()<<"ip:"<<ip;
        InTaskFindIP(ip);
        ui->FindIP->setText("搜索中");
        ui->Mouselist->clear();
    }
}

void UiIPSreach::on_ClientSend_clicked()
{
     emit ClientSend(ui->MainSend->text());
}

void UiIPSreach::on_ToConnect_clicked()
{
    QString ipstring=ui->IP->text();//获取text内的地址

    int portInt=ui->Port->text().toInt();//获取目标服务器的端口号

    App::TcpListenIP=ipstring;

    App::TcpListenPort=portInt;//不用指针---指针的作用是修改内存内的数值 --指针本身又要增加内存空间的分配--增加错误的几率

    emit ClientConnect();

    qDebug()<<"TcpListenIP:"<<App::TcpListenIP;

    qDebug()<<"main线程ID"<<QThread::currentThread();
}

void UiIPSreach::on_Disconnect_clicked()
{
    emit ClientDisconnect();
    int Row=ui->Mouselist->currentRow();
    qDebug()<<"Row:"<<Row;
    if(Row!=-1)
    {
        QListWidgetItem *item = ui->Mouselist->item(Row);
        item->setSelected(false);
    }
}
void UiIPSreach::ClientConfig()
{
    frmTcpClient *client=new frmTcpClient();//不允许有父对象 不然无法放入子线程内执行
    connect(this,&UiIPSreach::clientConnect,client,&frmTcpClient::ClientRecv);//接受
    connect(this,&UiIPSreach::ClientConnect,client,&frmTcpClient::ClientConnect);//连接
    connect(this,&UiIPSreach::ClientDisconnect,client,&frmTcpClient::ClientDisconnect);//断开连接
    connect(this,&UiIPSreach::ClientSend,client,&frmTcpClient::sendData);//发送信息
    connect(client,&frmTcpClient::TextClear,this,[=]
    {
        ui->MsgMain->clear();
    });
    connect(client,&frmTcpClient::TextColor,this,[=](QString Color)
    {
         ui->MsgMain->setTextColor(QColor(Color));
    });
    connect(client,&frmTcpClient::TextAppend,this,[=](QString Msg)
    {
         ui->MsgMain->append(Msg);
    });

    QThread *Task1=new QThread();
    client->moveToThread(Task1);
    Task1->start();//启动子线程

}

void UiIPSreach::InTaskFindIP(QString &IP)
{
    ServerSreach *Sreach =new ServerSreach();
    QThread *Task2=new QThread();
    Sreach->moveToThread(Task2);
    connect(this,&UiIPSreach::SreachIP,Sreach,&ServerSreach::ServerIPSreach);
    connect(Sreach,&ServerSreach::SreachIPArdress,this,[=](QString address)
    {
        ui->Mouselist->addItem(address);
    });
    Task2->start();

    QString ip_scan=IP;
    qDebug()<<"last . location"<<ip_scan.lastIndexOf(".");
    qDebug()<<"send location"<<ip_scan.left(ip_scan.lastIndexOf(".")+1);
    QString ip_sen=ip_scan.left(ip_scan.lastIndexOf(".")+1);
    qDebug()<<ip_sen;

    emit SreachIP(ip_sen);

    connect(Sreach,&ServerSreach::SerachOver,this,[=]
    {
        QMessageBox msgBox;
        msgBox.setText("搜索完成,可用IP个数为："+QString::number(ui->Mouselist->count()));
        msgBox.exec();
        ui->FindIP->setText("搜索");
        Task2->quit();
        Task2->wait();
        Task2->deleteLater();
        Sreach->deleteLater();
    });
}

void UiIPSreach::initForm()
{
    ui->IP->setText(App::TcpListenIP);
    ui->Port->setText(QString::number(App::TcpListenPort));
}


void UiIPSreach::lineeditEnable()
{

    QListWidgetItem* Item=ui->Mouselist->currentItem();

 if(Item->isSelected()==1)//判断是否有是false的状态 如果有不是true的状态就不执行连接
 {
    QString ipstring=Item->text();

    qDebug()<<"ip:"<<ipstring;

    App::TcpListenIP=ipstring;

    App::TcpListenPort=6000;//不用指针---指针的作用是修改内存内的数值 --指针本身又要增加内存空间的分配--增加错误的几率

    emit ClientConnect();
 }

}


QString& UiIPSreach::SystemIP()
{
    QStringList ips;
    QList<QNetworkInterface> netInterfaces = QNetworkInterface::allInterfaces();//生成一个列表--里面寄存着所有能用的ip地址 const 类型
    foreach(const QNetworkInterface  &netInterface, netInterfaces) //遍历复制 把里面的数值都复制到列表里
    {
        //移除虚拟机和抓包工具的虚拟网卡
        QString humanReadableName = netInterface.humanReadableName().toLower();
        qDebug()<<"humanReadableName:"<<humanReadableName;
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
                        static QString IP4Ard=ip4;//会在函数结束时释放？
//                        QPointer <QString> IP4=new QString;
//                        *IP4=ip4;
                        return IP4Ard;
                    }
                }
            }
        }
    }
}


void UiIPSreach::on_pushButton_clicked()
{
   this->hide();//不允许在其他窗口调用close
}

