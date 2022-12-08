#include "frmmain.h"
#include "ui_frmmain.h"
#include "quiwidget.h"
#include<QThread>



frmMain::frmMain(QWidget *parent) : QWidget(parent), ui(new Ui::frmMain)
{
    ui->setupUi(this);
    qDebug()<<"main线程ID"<<QThread::currentThread();
    ui->Bottom->installEventFilter(this);
    ShadowInit();
    SwitchInit();
    BackdropInit();
    ClientConfig();
    AirQualityIcon_Init();
    //---switch绑定
    connect(ui->AllLightSwitch,&SwitchButton::checkedChanged,this,&frmMain::AllLed_Switch);
    connect(ui->AirSwitch,&SwitchButton::checkedChanged,this,&frmMain::Air_Switch);
    //---按钮绑定
    connect(this,&frmMain::LightSwitch_Sub,LightUi,&LightSystem::Light_Status);
    connect(this,&frmMain::AirSwitch_Sub,AirUi,&AirSystem::Main_AirSwitch);
    connect(AirUi,&AirSystem::Air_Sync,this,[=](int value)
    {
        StopReturn=1;
        ui->AirSwitch->setChecked(value);
        StopReturn=0;
    });
    connect(LightUi,&LightSystem::Light_Sync,this,[=](int value)
    {
        StopReturn=1;
        ui->AllLightSwitch->setChecked(value);
        StopReturn=0;
    });
    //------释放才发送信号给子界面---辅灯
    connect(this,&frmMain::Sub_Auxiliary,LightUi,&LightSystem::Main_Auxiliary);
    connect(ui->AuxiliarySlider,&QSlider::sliderReleased,[=]
    {
        qDebug()<<"innnn---";
        emit Sub_Auxiliary((ui->AllAuxiliaryValue->text()).toInt());
    });
    //-------释放才发送信号给子界面---空调
    connect(this,&frmMain::Sub_AirTemp,AirUi,&AirSystem::Main_AirTemp);
    connect(ui->AirSlider,&QSlider::sliderReleased,[=]
    {
        qDebug()<<"innnn---";
        emit Sub_AirTemp((ui->AirTemp->text()).toInt());
    });
    //--------温度同步 AirTemp_Sync
    connect(AirUi,&AirSystem::AirTemp_Sync,this,[=](int value)
    {
        ui->AirSlider->setValue(value);
    });
    //------亮度同步
    connect(LightUi,&LightSystem::Auxiliary_Sync,this,[=](int value)
    {
        ui->AuxiliarySlider->setValue(value);
    });
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



void frmMain::ClientConfig()
{
    client=new frmTcpClient();//不允许有父对象 不然无法放入子线程内执行
    connect(this,&frmMain::ClientConnect,client,&frmTcpClient::ClientConnect);//连接
    connect(client,&frmTcpClient::Air_UiValue,AirUi,&AirSystem::ReceiveData);
    connect(client,&frmTcpClient::StatusSignals,LightUi,&LightSystem::Light_Status);
    connect(AirUi,&AirSystem::RadioBroadcast,client,&frmTcpClient::RadioBroadcast);
    connect(LightUi,&LightSystem::RadioBroadcast,client,&frmTcpClient::RadioBroadcast);
    connect(this,&frmMain::RadioBroadcast,client,&frmTcpClient::RadioBroadcast);
    //----
    connect(AirUi,&AirSystem::EndSignal,client,&frmTcpClient::SignalsRecover);
    connect(LightUi,&LightSystem::EndSignal,client,&frmTcpClient::SignalsRecover);
    connect(AirUi,&AirSystem::StartSignal,client,&frmTcpClient::SignalsStop);
    connect(LightUi,&LightSystem::StartSignal,client,&frmTcpClient::SignalsStop);
    //---
    connect(client,&frmTcpClient::OutSideTemp,this,[=](int Temp)
    {
       ui->OutSideTempLabel->setText(QString::number(Temp)+"°");
    });
    connect(client,&frmTcpClient::OutSideHum,this,[=](int Hum)
    {
        ui->OutSideHumLabel->setText(QString::number(Hum)+"°");
    });
    QThread *Task1=new QThread();
    client->moveToThread(Task1);
    Task1->start();//启动子线程
    QString ipstring="192.168.31.246";//获取text内的地址
    int portInt=6000;//获取目标服务器的端口号
    App::TcpListenIP=ipstring;
    App::TcpListenPort=portInt;//不用指针---指针的作用是修改内存内的数值 --指针本身又要增加内存空间的分配--增加错误的几率
    emit ClientConnect();
}

void frmMain::ShadowInit()
{
    QGraphicsDropShadowEffect *AirQualityPage = new QGraphicsDropShadowEffect(this);
    AirQualityPage->setOffset(8);
    AirQualityPage->setColor(/*Qt::gray*/QColor(43, 43, 43));
    AirQualityPage->setBlurRadius(25);
    ui->AirQualityPage->setGraphicsEffect(AirQualityPage);

    QGraphicsDropShadowEffect *AirPage = new QGraphicsDropShadowEffect(this);
    AirPage->setOffset(8);
    AirPage->setColor(/*Qt::gray*/QColor(43, 43, 43));
    AirPage->setBlurRadius(25);
    ui->AirPage->setGraphicsEffect(AirPage);

    QGraphicsDropShadowEffect *LightPage = new QGraphicsDropShadowEffect(this);
    LightPage->setOffset(8);
    LightPage->setColor(/*Qt::gray*/QColor(43, 43, 43));
    LightPage->setBlurRadius(25);
    ui->LightPage->setGraphicsEffect(LightPage);

    QGraphicsDropShadowEffect *MainPage = new QGraphicsDropShadowEffect(this);
    MainPage->setOffset(8);
    MainPage->setColor(/*Qt::gray*/QColor(43, 43, 43));
    MainPage->setBlurRadius(25);
    ui->MainPage->setGraphicsEffect(MainPage);

    QGraphicsDropShadowEffect *LightSubUi = new QGraphicsDropShadowEffect(this);
    LightSubUi->setOffset(8);
    LightSubUi->setColor(/*Qt::gray*/QColor(43, 43, 43));
    LightSubUi->setBlurRadius(25);
    ui->LightSubUi->setGraphicsEffect(LightSubUi);
    //AirSubUi
    QGraphicsDropShadowEffect *AirSubUi = new QGraphicsDropShadowEffect(this);
    AirSubUi->setOffset(8);
    AirSubUi->setColor(/*Qt::gray*/QColor(43, 43, 43));
    AirSubUi->setBlurRadius(25);
    ui->AirSubUi->setGraphicsEffect(AirSubUi);
    //OutSideTemp
    QGraphicsDropShadowEffect *OutSideTemp = new QGraphicsDropShadowEffect(this);
    OutSideTemp->setOffset(8);
    OutSideTemp->setColor(/*Qt::gray*/QColor(43, 43, 43));
    OutSideTemp->setBlurRadius(25);
    ui->OutSideTemp->setGraphicsEffect(OutSideTemp);
    //OutSideHum
    QGraphicsDropShadowEffect *OutSideHum = new QGraphicsDropShadowEffect(this);
    OutSideHum->setOffset(8);
    OutSideHum->setColor(/*Qt::gray*/QColor(43, 43, 43));
    OutSideHum->setBlurRadius(25);
    ui->OutSideHum->setGraphicsEffect(OutSideHum);
}

void frmMain::BackgroundInit()
{
    QPainter painter(ui->Bottom);
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setBrush(QColor(41,43,74));//
    painter.setPen(Qt::NoPen);//设置no pen
    painter.drawEllipse(-120,-400,700,700);

    painter.setBrush(QColor(255,192,0));//
    painter.drawEllipse(1400,-300,800,800);

    painter.setBrush(QColor(210,21,21));//
    painter.drawEllipse(1100,600,900,900);
}

bool frmMain::eventFilter(QObject *obj, QEvent *event)
{
    if(obj == ui->Bottom && event->type() == QEvent::Paint)
    {
        BackgroundInit();
        return true;
    }
}

void frmMain::SwitchInit()
{
    ui->AllLightSwitch->setButtonStyle(SwitchButton::ButtonStyle_CircleOut);
    ui->AllLightSwitch->setSpace(8);
    ui->AllLightSwitch->setRectRadius(8);
    ui->AllLightSwitch->setBgColorOn(QColor(72, 103, 149));
    ui->AllLightSwitch->setSliderColorOn(QColor(72, 103, 149));
    ui->AllLightSwitch->setShowText(true);
    ui->AllLightSwitch->setAnimation(true);
    ui->AllLightSwitch->setChecked(0);

    ui->AirSwitch->setButtonStyle(SwitchButton::ButtonStyle_CircleOut);
    ui->AirSwitch->setSpace(8);
    ui->AirSwitch->setRectRadius(8);
    ui->AirSwitch->setBgColorOn(QColor(72, 103, 149));
    ui->AirSwitch->setSliderColorOn(QColor(72, 103, 149));
    ui->AirSwitch->setShowText(true);
    ui->AirSwitch->setAnimation(true);
    ui->AirSwitch->setChecked(0);
}

void frmMain::BackdropInit()
{
    shade = new QWidget(this);
    AirUi=new AirSystem(this);
    LightUi=new LightSystem(this);
    //----------------
    QPalette palette = shade->palette();
    palette.setColor(QPalette::Window,QColor(125,125,125,150));
    shade->setAutoFillBackground(true);
    shade->setPalette(palette);
    shade->hide();
    shade->raise();
    //----------
    connect(AirUi,&AirSystem::SendClose,this,[=]
    {
        shade->hide();
    });
    connect(LightUi,&LightSystem::SendClose,this,[=]
    {
        shade->hide();
    });
}



void frmMain::on_LightSubUi_clicked()
{
    LightUi->show();
    shade->setGeometry(0,0,this->width(),this->height());
    shade->show();
}

void frmMain::on_AirSubUi_clicked()
{
    AirUi->show();
    shade->setGeometry(0,0,this->width(),this->height());
    shade->show();
}

void frmMain::AllLed_Switch(bool value)
{
    if(value==0)
    {
        Light_Order(0);
    }
    else {
        Light_Order(1);
    }
}

void frmMain::Air_Switch(bool value)
{
    if(value==0)
    {
        Air_Order(0);
    }
    else {
        Air_Order(1);
    }
}

void frmMain::Air_Order(int order)
{
    if(StopReturn!=1){
        switch (order) {
        case 0:
            emit AirSwitch_Sub(0);
            break;
        case 1:
            emit AirSwitch_Sub(1);
            break;
        }
    }
}

void frmMain::Light_Order(int order)
{
    if(StopReturn!=1){
        switch (order) {
        case 0:
            emit LightSwitch_Sub(3,0,0);
            break;
        case 1:
            emit LightSwitch_Sub(3,0,99);
            break;
        }
    }
}


void frmMain::on_AuxiliarySlider_valueChanged(int value)
{
    ui->AllAuxiliaryValue->setText(QString::number(value));
}

void frmMain::on_AirSlider_valueChanged(int value)
{
    ui->AirTemp->setText(QString::number(value));
}

void frmMain::AirQualityIcon_Init()
{
    QString TempP = ":/new/AirQuality/AirQulity/Temp.png";
    QIcon Temp = QIcon(TempP);
    QPixmap TempMap = Temp.pixmap(Temp.actualSize(QSize(ui->HchoP->width(), ui->HchoP->height())));//size自行调整
    ui->TempP->setPixmap(TempMap);

    QString PM25P = ":/new/AirQuality/AirQulity/pm2.5.png";
    QIcon PM25 = QIcon(PM25P);
    QPixmap PM25Map = PM25.pixmap(PM25.actualSize(QSize(ui->HchoP->width(), ui->HchoP->height())));//size自行调整
    ui->PM25P->setPixmap(PM25Map);

    QString HumP = ":/new/AirQuality/AirQulity/Humi.png";
    QIcon Hum = QIcon(HumP);
    QPixmap HumPMap = Hum.pixmap(Hum.actualSize(QSize(ui->HchoP->width(), ui->HchoP->height())));//size自行调整
    ui->HumP->setPixmap(HumPMap);

    QString HchoP = ":/new/AirQuality/AirQulity/HCHO.png";
    QIcon Hcho = QIcon(HchoP);
    QPixmap HchoMap = Hcho.pixmap(Hcho.actualSize(QSize(ui->HchoP->width(), ui->HchoP->height())));//size自行调整
    ui->HchoP->setPixmap(HchoMap);

    QString Co2P = ":/new/AirQuality/AirQulity/co2.png";
    QIcon Co2 = QIcon(Co2P);
    QPixmap Co2Map = Co2.pixmap(Co2.actualSize(QSize(ui->HchoP->width(), ui->HchoP->height())));//size自行调整
    ui->Co2P->setPixmap(Co2Map);

    QString TvcoP = ":/new/AirQuality/AirQulity/TVOC.png";
    QIcon Tvco = QIcon(TvcoP);
    QPixmap TvcoMap = Tvco.pixmap(Tvco.actualSize(QSize(ui->HchoP->width(), ui->HchoP->height())));//size自行调整
    ui->TvcoP->setPixmap(TvcoMap);

    QString AirQualityP = ":/new/AirQuality/AirQulity/AirQuality.png";
    QIcon AirQuality = QIcon(AirQualityP);
    QPixmap AirQualityMap = AirQuality.pixmap(AirQuality.actualSize(QSize(ui->AirQualityP->width(), ui->AirQualityP->height())));//size自行调整
    ui->AirQualityP->setPixmap(AirQualityMap);

    ui->TempP2->setPixmap(TempMap);
    ui->HumP2->setPixmap(HumPMap);


}
