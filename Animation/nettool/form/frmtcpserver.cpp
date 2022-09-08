#include "frmtcpserver.h"
#include "ui_frmtcpserver.h"
#include "quiwidget.h"

frmTcpServer::frmTcpServer(QWidget *parent) : QObject(parent)
{
    this->initForm();
    this->initIP();
    this->initConfig();
    qDebug()<<"服务器界面线程ID"<<QThread::currentThread();
}

frmTcpServer::~frmTcpServer()
{

}

void frmTcpServer::initForm()
{
    isOk = false;
    tcpServer = new TcpServer(this);
    connect(tcpServer, SIGNAL(clientConnected(QString, int)), this, SLOT(clientConnected(QString, int)));
    connect(tcpServer, SIGNAL(clientDisconnected(QString, int)), this, SLOT(clientDisconnected(QString, int)));
    connect(tcpServer, SIGNAL(sendData(QString, int, QString)), this, SLOT(sendData(QString, int, QString)));
    connect(tcpServer, SIGNAL(receiveData(QString, int, QString)), this, SLOT(receiveData(QString, int, QString)));

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(on_btnSend_clicked()));
    //----------------

    Door_handle=new Analysis_Door(this);
    connect(this,&frmTcpServer::Server_Receive_Data,Door_handle,&Analysis_Door::Receive_Data);
    Wind_handle=new Analysis_Wind(this);

    connect(this,&frmTcpServer::Server_Receive_Data,Wind_handle,&Analysis_Wind::Receive_Data);

    //    ui->cboxInterval->addItems(App::Intervals);
    //    ui->cboxData->addItems(App::Datas);
    //    QUIHelper::setLabStyle(ui->labCount, 3);
}

void frmTcpServer::initIP()
{

}

void frmTcpServer::initConfig()
{
}

void frmTcpServer::saveConfig()
{

    this->changeTimer();
}

void frmTcpServer::changeTimer()
{

}

void frmTcpServer::append(int type, const QString &data, bool clear)
{
    static int currentCount = 0;
    static int maxCount = 100;

    if (clear) {
        emit TextClear();
        currentCount = 0;
        return;
    }

    if (currentCount >= maxCount) {
        emit TextClear();
        currentCount = 0;
    }

    //    if (ui->ckShow->isChecked()) {//空的时候
    //        return;
    //    }

    //过滤回车换行符
    QString strData = data;
    strData = strData.replace("\r", "");
    strData = strData.replace("\n", "");

    //不同类型不同颜色显示
    QString strType;
    if (type == 0) {
        strType = "发送";
        emit TextColor("Dark");//黑色
    } else {
        strType = "接收";
        emit TextColor("Red");//红色
    }

    strData = QString("时间[%1] %2: %3").arg(TIMEMS).arg(strType).arg(strData);
    //ui->txtMain->append(strData);
    emit TextAppend(strData);
    currentCount++;
}

void frmTcpServer::clientConnected(const QString &ip, int port)
{
    QString str = QString("%1:%2").arg(ip).arg(port);
    emit ClientIpGroup(ip);
}

void frmTcpServer::clientDisconnected(const QString &ip, int port)
{
    int row = -1;
    QString str = QString("%1:%2").arg(ip).arg(port);
    emit ListCountText(row,ip);
}

void frmTcpServer::sendData(const QString &ip, int port, const QString &data)
{
    QString str = QString("[%1:%2] %3").arg(ip).arg(port).arg(data);
    bool error = (data.contains("下线") || data.contains("离线"));
    append(error ? 1 : 0, str);
}

void frmTcpServer::receiveData(const QString &ip, int port, const QString &data)
{
    App::StopReturn=true;
    qDebug()<<"App::StopReturn:"<<App::StopReturn;
    QString str = QString("[%1:%2] %3").arg(ip).arg(port).arg(data);
   // QVector<QString>(Manage);
    QMultiMap<int,QString>(System);
    bool Judge =(data.length())%10;
    qDebug()<<"data------------------------:"<<data<<"data.length()"<<data.length();
    QString Transition;
    if(Judge==false){
        for(int i=0;i<(data.length())/10;i++){
            for(int a=0;a<10;a++){
                Transition.append(data.at(i*10+a));
            }
            if(data.at(0)=="Z"){
                if(Transition.at(2)=="1"){
                    System.insert(1,Transition);
                }
                else if(Transition.at(2)=="2"){
                    System.insert(2,Transition);
                }
                else if(Transition.at(2)=="3"){
                    System.insert(3,Transition);
                }
                else if(Transition.at(2)=="4"){
                    System.insert(4,Transition);
                }
                else if(Transition.at(2)=="5"){
                    System.insert(5,Transition);
                }
                else if(Transition.at(2)=="6"){
                    System.insert(6,Transition);
                }
                else if(Transition.at(2)=="7")
                {
                    System.insert(7,Transition);
                }
                Transition.clear();
                emit Server_Receive_Data(System);
            }
            else if(data.at(0)=="E")
            {
                emit Esp_Data(Transition);
            }
        }
    }
    App::StopReturn=false;
}

void frmTcpServer::on_btnListen_clicked()
{

}

void frmTcpServer::on_btnSave_clicked()
{

}

void frmTcpServer::on_btnClear_clicked()
{
    append(0, "", true);
}

void frmTcpServer::on_btnSend_clicked()
{

}

void frmTcpServer::on_btnClose_clicked()
{

}

void frmTcpServer::RadioBroadcast(QString data)//广播
{
    if (!isOk) {
        return;
    }
    else
    {
        tcpServer->writeData(data);
        append(0,data);
    }
}

void frmTcpServer::Listen()
{
    isOk = tcpServer->start();
    if (isOk) {
        //append(0, "监听成功");
        qDebug()<<"监听成功";
    }

}

void frmTcpServer::ListenClose()
{
    tcpServer->stop();
    isOk=-1;
}
