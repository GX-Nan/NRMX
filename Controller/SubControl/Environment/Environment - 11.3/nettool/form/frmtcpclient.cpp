#include "frmtcpclient.h"
#include "ui_frmtcpclient.h"
#include "quiwidget.h"

frmTcpClient::frmTcpClient(QObject *parent) : QObject(parent)/*, ui(new Ui::frmTcpClient)*/
{
    this->initForm();
    this->initConfig();

    qDebug()<<"客户端界面线程ID"<<QThread::currentThread();
}

frmTcpClient::~frmTcpClient()
{
    delete this;
}

void frmTcpClient::ClientRecv()
{
    qDebug()<<"innn--client";
    qDebug()<<"客户端界面线程ID"<<QThread::currentThread();
}

void frmTcpClient::initForm()
{
    isOk = false;
    tcpSocket = new QTcpSocket(this);
    connect(tcpSocket, SIGNAL(connected()), this, SLOT(connected()));
    connect(tcpSocket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(disconnected()));
    connect(tcpSocket, SIGNAL(disconnected()), this, SLOT(disconnected()));
    connect(tcpSocket, SIGNAL(readyRead()), this, SLOT(readData()));

    timer = new QTimer(this);
    //connect(timer, SIGNAL(timeout()), this, SLOT(on_btnSend_clicked()));

    //    ui->cboxInterval->addItems(App::Intervals);
    //    ui->cboxData->addItems(App::Datas);
}

void frmTcpClient::initConfig()
{

    this->changeTimer();
}

void frmTcpClient::saveConfig()
{

    App::writeConfig();

    this->changeTimer();
}

void frmTcpClient::changeTimer()
{
    timer->setInterval(App::IntervalTcpClient);
    if (App::AutoSendTcpClient) {
        if (!timer->isActive()) {
            timer->start();
        }
    } else {
        if (timer->isActive()) {
            timer->stop();
        }
    }
}

void frmTcpClient::append(int type, const QString &data, bool clear)
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

void frmTcpClient::connected()
{
    //    isOk = true;
    //    ui->btnConnect->setText("断开");
    //    append(0, "服务器连接");
}

void frmTcpClient::disconnected()//voidClientDisconnect
{
    isOk = false;
    tcpSocket->abort();
    for(int i=0;i<=5;i++)
    {
        tcpSocket->abort();
        tcpSocket->connectToHost(App::TcpListenIP,App::TcpListenPort);//ClientConnect
        sleep(5);
        qDebug()<<"sleep:"<<i;
    }
    qDebug()<<"链接失败";
    append(1, "服务器断开");
}

void frmTcpClient::readData()//用信号槽连接主线程ui控件的修改-----要不要放进线程内处理线程
{
    QByteArray data = tcpSocket->readAll();
    if (data.length() <= 0) {
        return;
    }

    QString buffer;
    if (App::HexReceiveTcpClient) {
        buffer = QUIHelper::byteArrayToHexStr(data);
    } else if (App::AsciiTcpClient) {
        buffer = QUIHelper::byteArrayToAsciiStr(data);
    } else {
        buffer = QString(data);
    }
    //写一个工作执行寄存的程序----1.先执行看是否执行完了2.执行完了之后把数据----例子：温度 25 或者是开关：True这样记录下来3.3000条的话就清空，重新写入;3.如果出现错误则放入另一个text内-->并且上报到云服务器上

    StopReturn=1;
    bool Judge =(buffer.length())%10;
    qDebug()<<"data------------------------:"<<buffer<<"buffer.length()"<<buffer.length();
    QString Transition;
    QString TempHumTrasition;
    if(Judge==false){
        for(int i=0;i<(buffer.length())/10;i++){
            for(int a=0;a<10;a++){
                Transition.append(data.at(i*10+a));
            }
            if(Transition.at(2)=="2")
            {

                if(Transition.at(4)=="1"||Transition.at(4)=="3"||Transition.at(4)=="0"||Transition.at(4)=="4"||Transition.at(4)=="5"||Transition.at(4)=="6")
                {
                    Analysis_Light(Transition);
                }
                else if(Transition.at(4)=="2")
                {
                    Analysis_Air(Transition);
                }
            }
            else if(Transition.at(2)=="3")
            {
                for(int i=7;i<=8;i++)
                {
                    TempHumTrasition.append(Transition.at(i));
                }
                qDebug()<<"Trasition:"<<TempHumTrasition;
                if(Transition.at(6)=="1")
                {
                    emit OutSideTemp(TempHumTrasition.toInt());
                }
                else if(Transition.at(6)=="2")
                {
                    qDebug()<<"WeatherHum:"<<TempHumTrasition.toInt();
                    emit OutSideHum(TempHumTrasition.toInt());
                }
                TempHumTrasition.clear();
            }
            Transition.clear();
        }
    }
    append(1, buffer);//更新列表
    //自动回复数据,可以回复的数据是以;隔开,每行可以带多个;所以这里不需要继续判断
    //    if (App::DebugTcpClient) {
    //        int count = App::Keys.count();
    //        for (int i = 0; i < count; i++) {
    //            if (App::Keys.at(i) == buffer) {
    //                sendData(App::Values.at(i));
    //                break;
    //            }
    //        }
    //    }
}

void frmTcpClient::Analysis_Air(QString Data)
{
    QString Sub;
    QString Value;
    QString Function;
    //-----截取------------
    for(int i=3;i<=4;i++)
    {
        Function.append(Data.at(i));
    }
    for(int a=5;a<=6;a++)
    {
        Sub.append(Data.at(a));
    }
    for(int b=7;b<=8;b++)
    {
        Value.append(Data.at(b));
    }
    //------------------
    if(Function.toInt()==2)
    {
        if(Sub.toInt()==1)
        {
            emit Air_UiValue(Value.toInt());
        }
    }
}

void frmTcpClient::Analysis_Light(QString Data)
{
    QString Sub;
    QString Value;
    QString Function;
    //-----截取------------
    for(int i=3;i<=4;i++)
    {
        Function.append(Data.at(i));
    }
    for(int a=5;a<=6;a++)
    {
        Sub.append(Data.at(a));
    }
    for(int b=7;b<=8;b++)
    {
        Value.append(Data.at(b));
    }
    qDebug()<<"Function:"<<Function;
    //------------------
    if(Function.toInt()==1||Function.toInt()==3||Function.toInt()==4||Function.toInt()==5||Function.toInt()==6||Function.toInt()==0){
        emit StatusSignals(Function.toInt(),Sub.toInt(),Value.toInt());
        qDebug()<<"Function:"<<Function;
    }
}

void frmTcpClient::Air_Decode(int Value)
{
    //之后可以写数据库？？
    //    if(Value<16){
    //        switch (Value) {
    //        case 0:
    //            data.Station=0;
    //            break;
    //        case 1:
    //            data.Station=1;
    //            break;
    //        case 2://"Low"
    //            data.Fan=1;
    //            break;
    //        case 3://"Mid"
    //            data.Fan=2;
    //            break;
    //        case 4://"High"
    //            data.Fan=3;
    //            break;
    //        case 5:
    //            data.Swing_L_R=1;
    //            break;
    //        case 6:
    //            data.Swing_L_R=0;
    //            break;
    //        case 7:
    //            data.Swing_U_D=1;
    //            break;
    //        case 8:
    //            data.Swing_U_D=0;
    //            break;
    //        case 9://"Cool"
    //            data.Mode=1;
    //            break;
    //        case 10://"Dry"
    //            data.Mode=3;
    //            break;
    //        case 11://"Heat"
    //            data.Mode=2;
    //            break;
    //        case 12://"Auto"
    //            data.Mode=0;
    //            break;
    //        case 13://"Auto"
    //            data.Fan=0;
    //            break;
    //        case 14:
    //            data.Mode=4;
    //        case 15:
    //            break;
    //        }
    //    }
    //    else {
    //        data.Temp=Value;
    //    }
    //    emit Air_UiValue(int Value);
}



void frmTcpClient::sendData(const QString &data)
{
    QByteArray buffer;
    if (App::HexSendTcpClient) {
        buffer = QUIHelper::hexStrToByteArray(data);
    } else if (App::AsciiTcpClient) {
        buffer = QUIHelper::asciiStrToByteArray(data);
    } else {
        buffer = data.toLatin1();
    }

    tcpSocket->write(buffer);
    append(0, data);
}

void frmTcpClient::RadioBroadcast(QString data)
{
    if(StopReturn==0){
        sendData(data);
    }
}

void frmTcpClient::SignalsRecover()
{
    StopReturn=0;
}

void frmTcpClient::SignalsStop()
{
    StopReturn=1;
}

void frmTcpClient::ClientConnect()
{
    isOk=true;
    tcpSocket->abort();
    tcpSocket->connectToHost(App::TcpListenIP,App::TcpListenPort);//ClientConnect
    append(0, "服务器连接");
}

void frmTcpClient::ClientDisconnect()
{
    tcpSocket->abort();// ClientDisonnect
    qDebug()<<"断开连接";
    qDebug()<<"子线程ID"<<QThread::currentThread();
    append(1, "服务器断开");
}





