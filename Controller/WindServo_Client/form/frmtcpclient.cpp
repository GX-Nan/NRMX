#include "frmtcpclient.h"
#include "ui_frmtcpclient.h"
#include "quiwidget.h"

static int Num=1;
frmTcpClient::frmTcpClient(QWidget *parent) : QWidget(parent), ui(new Ui::frmTcpClient)
{
    ui->setupUi(this);
    this->initForm();
    this->initConfig();

    qDebug()<<"Main thread address:"<<QThread::currentThread();

    SubThread=new write_i();
    TimerMode=new QTimer(this);
    PWmMode=new QTimer(this);
    PowerValue=new PwmCtrl();

    QThread * Task1=new QThread();

    PowerValue->moveToThread(Task1);

    Task1->start();

   // connect(this,&frmTcpClient::pwmMode,PowerValue,&PwmCtrl::PowerChange);

    connect(this,&frmTcpClient::pwmMode,PowerValue,&PwmCtrl::PowerChange);

    connect(this,&frmTcpClient::TurnAngle,SubThread,&write_i::ServoTurn);

    connect(this,&frmTcpClient::ServoTurn,SubThread,&write_i::ServoGroup);

    connect(this,&frmTcpClient::WhileTurn,SubThread,&write_i::WhileTurn);

//    connect(this,&frmTcpClient::TurnAngle,SubThread,&write_i::ServoTurn);
//    connect(this,&frmTcpClient::TurnAngle,SubThread,&write_i::ServoTurn);
//    connect(this,&frmTcpClient::TurnAngle,SubThread,&write_i::ServoTurn);
//    connect(this,&frmTcpClient::TurnAngle,SubThread,&write_i::ServoTurn);


}

frmTcpClient::~frmTcpClient()
{
    delete ui;
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
    connect(timer, SIGNAL(timeout()), this, SLOT(on_btnSend_clicked()));

    ui->cboxInterval->addItems(App::Intervals);
    ui->cboxData->addItems(App::Datas);


}

void frmTcpClient::initConfig()
{
    ui->ckHexSend->setChecked(App::HexSendTcpClient);
    connect(ui->ckHexSend, SIGNAL(stateChanged(int)), this, SLOT(saveConfig()));

    ui->ckHexReceive->setChecked(App::HexReceiveTcpClient);
    connect(ui->ckHexReceive, SIGNAL(stateChanged(int)), this, SLOT(saveConfig()));

    ui->ckAscii->setChecked(App::AsciiTcpClient);
    connect(ui->ckAscii, SIGNAL(stateChanged(int)), this, SLOT(saveConfig()));

    ui->ckDebug->setChecked(App::DebugTcpClient);
    connect(ui->ckDebug, SIGNAL(stateChanged(int)), this, SLOT(saveConfig()));

    ui->ckAutoSend->setChecked(App::AutoSendTcpClient);
    connect(ui->ckAutoSend, SIGNAL(stateChanged(int)), this, SLOT(saveConfig()));

    ui->cboxInterval->setCurrentIndex(ui->cboxInterval->findText(QString::number(App::IntervalTcpClient)));
    connect(ui->cboxInterval, SIGNAL(currentIndexChanged(int)), this, SLOT(saveConfig()));

    ui->txtServerIP->setText(App::TcpServerIP);
    connect(ui->txtServerIP, SIGNAL(textChanged(QString)), this, SLOT(saveConfig()));

    ui->txtServerPort->setText(QString::number(App::TcpServerPort));
    connect(ui->txtServerPort, SIGNAL(textChanged(QString)), this, SLOT(saveConfig()));

    this->changeTimer();
}

void frmTcpClient::saveConfig()
{
    App::HexSendTcpClient = ui->ckHexSend->isChecked();
    App::HexReceiveTcpClient = ui->ckHexReceive->isChecked();
    App::AsciiTcpClient = ui->ckAscii->isChecked();
    App::DebugTcpClient = ui->ckDebug->isChecked();
    App::AutoSendTcpClient = ui->ckAutoSend->isChecked();
    App::IntervalTcpClient = ui->cboxInterval->currentText().toInt();
    App::TcpServerIP = ui->txtServerIP->text().trimmed();
    App::TcpServerPort = ui->txtServerPort->text().trimmed().toInt();
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
        ui->txtMain->clear();
        currentCount = 0;
        return;
    }

    if (currentCount >= maxCount) {
        ui->txtMain->clear();
        currentCount = 0;
    }

    if (ui->ckShow->isChecked()) {
        return;
    }

    //过滤回车换行符
    QString strData = data;
    strData = strData.replace("\r", "");
    strData = strData.replace("\n", "");

    //不同类型不同颜色显示
    QString strType;
    if (type == 0) {
        strType = "发送";
        ui->txtMain->setTextColor(QColor("darkgreen"));
    } else {
        strType = "接收";
        ui->txtMain->setTextColor(QColor("red"));
    }

    strData = QString("时间[%1] %2: %3").arg(TIMEMS).arg(strType).arg(strData);
    ui->txtMain->append(strData);
    currentCount++;
}

void frmTcpClient::connected()
{
    isOk = true;
    ui->btnConnect->setText("断开");
    append(0, "服务器连接");
}

void frmTcpClient::disconnected()
{
    isOk = false;
    tcpSocket->abort();
    ui->btnConnect->setText("连接");
    append(1, "服务器断开");
}

void frmTcpClient::readData()
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

    qDebug()<<"buffer:"<<buffer.toInt();

    qDebug()<<"innn---ServerToclient";

    append(1, buffer);

    //自动回复数据,可以回复的数据是以;隔开,每行可以带多个;所以这里不需要继续判断
    if (App::DebugTcpClient) {
        int count = App::Keys.count();
        for (int i = 0; i < count; i++) {
            if (App::Keys.at(i) == buffer) {
                sendData(App::Values.at(i));
                break;
            }
        }
    }
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

void frmTcpClient::on_btnConnect_clicked()
{
    if (ui->btnConnect->text() == "连接") {
        tcpSocket->abort();
        tcpSocket->connectToHost(App::TcpServerIP, App::TcpServerPort);
    } else {
        tcpSocket->abort();
    }
}

void frmTcpClient::on_btnSave_clicked()
{
    QString data = ui->txtMain->toPlainText();
    if (data.length() <= 0) {
        return;
    }

    QString fileName = QString("%1/%2.txt").arg(QUIHelper::appPath()).arg(STRDATETIME);
    QFile file(fileName);
    if (file.open(QFile::WriteOnly | QFile::Text)) {
        file.write(data.toUtf8());
        file.close();
    }

    on_btnClear_clicked();
}

void frmTcpClient::on_btnClear_clicked()
{
    append(0, "", true);
}

void frmTcpClient::on_btnSend_clicked()
{
    if (!isOk) {
        return;
    }

    QString data = ui->cboxData->currentText();
    if (data.length() <= 0) {
        return;
    }
    sendData(data);
}

void frmTcpClient::on_pushButton_clicked()
{
    QString ii=ui->ServoAngle->text();
    if(ii.toInt()>=800&&ii.toInt()<=2500)
    {
        emit TurnAngle(ii.toInt());
        qDebug()<<"Check in";
    }
}

void frmTcpClient::on_pushButton_2_clicked()
{
    QString Power=ui->WindPower->text();
    if(Power.toInt()<=100&&Power.toInt()>=0)
    {
        emit pwmMode(Power.toInt(),1);
        qDebug()<<"innnnn";
    }
}

void frmTcpClient::on_pushButton_3_clicked()
{
    emit pwmMode(0,0);
}

void frmTcpClient::on_pushButton_4_clicked()
{
    emit pwmMode(0,2);
}

void frmTcpClient::on_pushButton_5_clicked()
{
//    char*  ch;
//    QByteArray ba = ui->Pin1->text().toLatin1();
//    ch=ba.data();
//    char** ch1=&ch;
//    qDebug()<<"ch1"<<ch1;
    unsigned int Pin1=ui->Pin1->text().toInt();
    unsigned int Pin2=ui->Pin2->text().toInt();
    emit ServoTurn(ui->GroupAngle->text().toInt(),ui->GroupAngle_2->text().toInt(),Pin1,Pin2);
}

void frmTcpClient::on_pushButton_6_clicked()
{

    emit WhileTurn(1);
}

void frmTcpClient::on_pushButton_7_clicked()
{
    emit WhileTurn(0);
}
