#include "frmmain.h"
#include "ui_frmmain.h"
#include "quiwidget.h"
#include<QThread>



frmMain::frmMain(QWidget *parent) : QWidget(parent), ui(new Ui::frmMain)
{
    ui->setupUi(this);
    initConfig();
    ClientConfig();
    // ui->tabWidget->setCurrentIndex(App::CurrentIndex);
    qDebug()<<"main线程ID"<<QThread::currentThread();

}

frmMain::~frmMain()
{
    delete ui;
}


void frmMain::on_tabWidget_currentChanged(int index)
{
    App::CurrentIndex = index;
    App::writeConfig();
}


void frmMain::saveConfig()
{

}

void frmMain::initConfig()//配置
{
    frmTcpClient *client=new frmTcpClient();//不允许有父对象 不然无法放入子线程内执行
//    connect(this,&UiIPSreach::clientConnect,client,&frmTcpClient::ClientRecv);//接受
    connect(this,&frmMain::ClientConnect,client,&frmTcpClient::ClientConnect);//连接
    QThread *Task1=new QThread();
    client->moveToThread(Task1);
    Task1->start();//启动子线程
}


void frmMain::ClientConfig()
{
    frmTcpClient *client=new frmTcpClient();//不允许有父对象 不然无法放入子线程内执行

    QString ipstring="192.168.31.93";//获取text内的地址

    int portInt=6002;//获取目标服务器的端口号

    App::TcpListenIP=ipstring;

    App::TcpListenPort=portInt;//不用指针---指针的作用是修改内存内的数值 --指针本身又要增加内存空间的分配--增加错误的几率

    emit ClientConnect();

    QThread *Task1=new QThread();
    client->moveToThread(Task1);
    Task1->start();//启动子线程
}


