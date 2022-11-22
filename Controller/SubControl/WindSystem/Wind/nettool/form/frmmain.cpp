#include "frmmain.h"
#include "ui_frmmain.h"
#include "quiwidget.h"
#include<QThread>



frmMain::frmMain(QWidget *parent) : QWidget(parent), ui(new Ui::frmMain)
{
    ui->setupUi(this);
    initConfig();
    // ui->tabWidget->setCurrentIndex(App::CurrentIndex);
    qDebug()<<"main线程ID"<<QThread::currentThread();
    Shade_Init();
    Xprogress_Init();
    AirQualityIcon_Init();
    XprogressbarIfconfig();

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

void frmMain::initConfig()//配置
{
    client=new frmTcpClient();//不允许有父对象 不然无法放入子线程内执行
    connect(this,&frmMain::EndSignals,client,&frmTcpClient::SignalsRecover);
    connect(this,&frmMain::StartSignals,client,&frmTcpClient::StopSignals);
    bool i=connect(this,&frmMain::ClientConnect,client,&frmTcpClient::ClientConnect);//连接
    connect(client,&frmTcpClient::Updata_Wind,this,&frmMain::Updata_Ui);
    connect(this,&frmMain::RadioBroadcast,client,&frmTcpClient::RadioBroadcast);
    connect(client,&frmTcpClient::OutSideTemp,this,[=](int Temp)
    {
        ui->Temp_Xpro->setValue(Temp);
        emit EndSignals();
    });
    connect(client,&frmTcpClient::OutSideHum,this,[=](int Hum)
    {
        ui->Humi_Xpro->setValue(Hum);
        emit EndSignals();
    });
    connect(client,&frmTcpClient::OutSideNo2,this,[=](int value)
    {
        ui->OutSideNo2_Xpro->setValue(value);
        emit EndSignals();
    });
    connect(client,&frmTcpClient::OutSideSo2,this,[=](int value)
    {
        ui->OutSideSo2_Xpro->setValue(value);
        emit EndSignals();
    });
    connect(client,&frmTcpClient::OutSidePm10,this,[=](int value)
    {
        ui->OutSidePm10_Xpro->setValue(value);
        emit EndSignals();
    });
    connect(client,&frmTcpClient::OutSidePm25,this,[=](int value)
    {
        ui->OutSidePm25_Xpro->setValue(value);
        emit EndSignals();
    });
    connect(client,&frmTcpClient::OutSideAQI,this,[=](int value)
    {
        ui->AirQualityLabel->setText(QString::number((100-value)));
        emit EndSignals();
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



void frmMain::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setBrush(QColor(41,43,74));//
    painter.setPen(Qt::NoPen);//设置no pen
    painter.drawEllipse(-120,-400,700,700);

    painter.setBrush(QColor(255,192,0));//
    painter.drawEllipse(1400,-300,800,800);

    painter.setBrush(QColor(210,21,21));//
    painter.drawEllipse(1100,600,900,900);
}

void frmMain::Shade_Init()
{
    QGraphicsDropShadowEffect *OutDoorAir = new QGraphicsDropShadowEffect(this);
    OutDoorAir->setOffset(8);
    OutDoorAir->setColor(/*Qt::gray*/QColor(43, 43, 43));
    OutDoorAir->setBlurRadius(25);
    ui->OutDoorAir->setGraphicsEffect(OutDoorAir);

    QGraphicsDropShadowEffect *InDoorAir = new QGraphicsDropShadowEffect(this);
    InDoorAir->setOffset(8);
    InDoorAir->setColor(/*Qt::gray*/QColor(43, 43, 43));
    InDoorAir->setBlurRadius(25);
    ui->InDoorAir->setGraphicsEffect(InDoorAir);

    QGraphicsDropShadowEffect *InDoorBox = new QGraphicsDropShadowEffect(this);
    InDoorBox->setOffset(8);
    InDoorBox->setColor(/*Qt::gray*/QColor(43, 43, 43));
    InDoorBox->setBlurRadius(25);
    ui->InDoorBox->setGraphicsEffect(InDoorBox);


    QGraphicsDropShadowEffect *OutDoorBox = new QGraphicsDropShadowEffect(this);
    OutDoorBox->setOffset(8);
    OutDoorBox->setColor(/*Qt::gray*/QColor(43, 43, 43));
    OutDoorBox->setBlurRadius(25);
    ui->OutDoorBox->setGraphicsEffect(OutDoorBox);

    QGraphicsDropShadowEffect *frame = new QGraphicsDropShadowEffect(this);
    frame->setOffset(8);
    frame->setColor(/*Qt::gray*/QColor(43, 43, 43));
    frame->setBlurRadius(25);
    ui->frame->setGraphicsEffect(frame);

    QGraphicsDropShadowEffect *frame_2 = new QGraphicsDropShadowEffect(this);
    frame_2->setOffset(8);
    frame_2->setColor(/*Qt::gray*/QColor(43, 43, 43));
    frame_2->setBlurRadius(25);
    ui->frame_2->setGraphicsEffect(frame_2);//FanPage

    QGraphicsDropShadowEffect *FanPage = new QGraphicsDropShadowEffect(this);
    FanPage->setOffset(8);
    FanPage->setColor(/*Qt::gray*/QColor(43, 43, 43));
    FanPage->setBlurRadius(25);
    ui->FanPage->setGraphicsEffect(FanPage);


    QGraphicsDropShadowEffect *ModePage = new QGraphicsDropShadowEffect(this);
    ModePage->setOffset(8);
    ModePage->setColor(/*Qt::gray*/QColor(43, 43, 43));
    ModePage->setBlurRadius(25);
    ui->ModePage->setGraphicsEffect(ModePage);

    QGraphicsDropShadowEffect *AiMode = new QGraphicsDropShadowEffect(this);
    AiMode->setOffset(8);
    AiMode->setColor(/*Qt::gray*/QColor(43, 43, 43));
    AiMode->setBlurRadius(25);
    ui->AiMode->setGraphicsEffect(AiMode);

    QGraphicsDropShadowEffect *MainBox = new QGraphicsDropShadowEffect(this);
    MainBox->setOffset(8);
    MainBox->setColor(/*Qt::gray*/QColor(43, 43, 43));
    MainBox->setBlurRadius(25);
    ui->MainBox->setGraphicsEffect(MainBox);
}

void frmMain::Xprogress_Init()
{
    QList <XProgressBar*> XProgressBar;
    XProgressBar<<ui->Temp_Xpro<<ui->Humi_Xpro;
    QLinearGradient lineGradient(0, 0, ui->Humi_Xpro->width(), ui->Humi_Xpro->height());
    lineGradient.setColorAt(0.0, QColor("#F1B45B"));
    lineGradient.setColorAt(0.5, QColor("#F2765C"));
    lineGradient.setColorAt(1.0, QColor("#6D59EF"));
    for(int i=0;i<XProgressBar.length();i++){
        XProgressBar[i]->setValueBrush(lineGradient);
        XProgressBar[i]->setAutoRadius(true);
        XProgressBar[i]->setRange(0,100);
    }
}

void frmMain::ButtonStyle_Button(QPushButton *Name, int Offset, int BlurRadius)
{
    QGraphicsDropShadowEffect *ButtonStyle = new QGraphicsDropShadowEffect(this);
    ButtonStyle->setOffset(Offset);
    ButtonStyle->setColor(/*Qt::gray*/QColor(43, 43, 43));
    ButtonStyle->setBlurRadius(BlurRadius);
    Name->setGraphicsEffect(ButtonStyle);
}

void frmMain::ButtonStylePlan_Fan(int i, int i2, int i3)
{
    ButtonStyle_Button(ui->Low,i,25);
    ButtonStyle_Button(ui->Mid,i2,25);
    ButtonStyle_Button(ui->High,i3,25);
}

void frmMain::ButtonStylePlan_Mode(int i, int i2, int i3,int i4)
{
    ButtonStyle_Button(ui->Sea,i,25);
    ButtonStyle_Button(ui->Nature,i2,25);
    ButtonStyle_Button(ui->Solid,i3,25);
    ButtonStyle_Button(ui->Surround,i4,25);
}

void frmMain::on_Low_clicked()
{

    if(Fan_status==1) {
        StyleSheet_Plan_Fan(0);
        ButtonStylePlan_Fan(8,8,8);
        Icon_Clear_Fan();
        Fan_status=0;
    }else{

        StyleSheet_Plan_Fan(1);
        ButtonStylePlan_Fan(1,8,8);
        Fan_StylePlan(1);
        Fan_status=1;
    }
    SetInstruction(Fan_status);

}

void frmMain::on_Mid_clicked()
{

    if(Fan_status==2) {
        StyleSheet_Plan_Fan(0);
        ButtonStylePlan_Fan(8,8,8);
        Icon_Clear_Fan();
        Fan_status=0;
    }else{
        StyleSheet_Plan_Fan(2);
        ButtonStylePlan_Fan(8,1,8);
        Fan_StylePlan(2);
        Fan_status=2;
    }
    SetInstruction(Fan_status);

}

void frmMain::on_High_clicked()
{

    if(Fan_status==3) {
        StyleSheet_Plan_Fan(0);
        ButtonStylePlan_Fan(8,8,8);
        Icon_Clear_Fan();
        Fan_status=0;
    }else{
        StyleSheet_Plan_Fan(3);
        ButtonStylePlan_Fan(8,8,1);
        Fan_StylePlan(3);
        Fan_status=3;
    }
    SetInstruction(Fan_status);

}

void frmMain::Fan_StylePlan(int Order)
{
    switch(Order)
    {
    case 1 :
        ui->Low->setIcon(QIcon(":/Wind/Low_ON.png"));
        ui->Mid->setIcon(QIcon(":/Wind/Mid_OFF.png"));
        ui->High->setIcon(QIcon(":/Wind/High_OFF.png"));
        break;
    case 2:
        ui->Low->setIcon(QIcon(":/Wind/Low_OFF.png"));
        ui->Mid->setIcon(QIcon(":/Wind/Mid_ON.png"));
        ui->High->setIcon(QIcon(":/Wind/High_OFF.png"));
        break;
    case 3 :
        ui->Low->setIcon(QIcon(":/Wind/Low_OFF.png"));
        ui->Mid->setIcon(QIcon(":/Wind/Mid_OFF.png"));
        ui->High->setIcon(QIcon(":/Wind/High_ON.png"));
        break;
    }
}

void frmMain::Mode_StylePlan(int Order)
{
    switch(Order)
    {
    case 1:
        ui->Sea->setIcon(QIcon(":/Wind/Sea_ON.png"));
        ui->Solid->setIcon(QIcon(":/Wind/Solid_OFF.png"));
        ui->Nature->setIcon(QIcon(":/Wind/Natural_OFF.png"));
        ui->Surround->setIcon(QIcon(":/Wind/Surround_OFF.png"));
        break;
    case 2:
        ui->Sea->setIcon(QIcon(":/Wind/Sea_OFF.png"));
        ui->Solid->setIcon(QIcon(":/Wind/Solid_ON.png"));
        ui->Nature->setIcon(QIcon(":/Wind/Natural_OFF.png"));
        ui->Surround->setIcon(QIcon(":/Wind/Surround_OFF.png"));
        break;
    case 3:
        ui->Sea->setIcon(QIcon(":/Wind/Sea_OFF.png"));
        ui->Solid->setIcon(QIcon(":/Wind/Solid_OFF.png"));
        ui->Nature->setIcon(QIcon(":/Wind/Natural_ON.png"));
        ui->Surround->setIcon(QIcon(":/Wind/Surround_OFF.png"));
        break;
    case 4:
        ui->Sea->setIcon(QIcon(":/Wind/Sea_OFF.png"));
        ui->Solid->setIcon(QIcon(":/Wind/Solid_OFF.png"));
        ui->Nature->setIcon(QIcon(":/Wind/Natural_OFF.png"));
        ui->Surround->setIcon(QIcon(":/Wind/Surround_ON.png"));
        break;
    }
}

void frmMain::Icon_Clear()
{
    ui->Sea->setIcon(QIcon(":/Wind/Sea_OFF.png"));
    ui->Solid->setIcon(QIcon(":/Wind/Solid_OFF.png"));
    ui->Surround->setIcon(QIcon(":/Wind/Surround_OFF.png"));
    ui->Nature->setIcon(QIcon(":/Wind/Natural_OFF.png"));
}

void frmMain::Icon_Clear_Fan()
{
    ui->Low->setIcon(QIcon(":/Wind/Low_OFF.png"));
    ui->Mid->setIcon(QIcon(":/Wind/Mid_OFF.png"));
    ui->High->setIcon(QIcon(":/Wind/High_OFF.png"));
}




void frmMain::on_Nature_clicked()
{

    if(Mode_status==5) {
        StyleSheet_Plan_Mode(4);
        ButtonStylePlan_Mode(8,8,8,8);
        Icon_Clear();
        Mode_status=4;
    }else{
        StyleSheet_Plan_Mode(5);
        ButtonStylePlan_Mode(8,1,8,8);
        Mode_StylePlan(3);
        Mode_status=5;
    }
    SetInstruction(Mode_status);

}

void frmMain::on_Sea_clicked()
{

    if(Mode_status==7) {
        StyleSheet_Plan_Mode(4);
        ButtonStylePlan_Mode(8,8,8,8);
        Icon_Clear();
        Mode_status=4;
    }else{
        StyleSheet_Plan_Mode(7);
        ButtonStylePlan_Mode(1,8,8,8);
        Mode_StylePlan(1);
        Mode_status=7;
    }
    SetInstruction(Mode_status);

}

void frmMain::on_Solid_clicked()
{

    if(Mode_status==6) {
        StyleSheet_Plan_Mode(4);
        ButtonStylePlan_Mode(8,8,8,8);
        Icon_Clear();
        Mode_status=4;
    }else{
        StyleSheet_Plan_Mode(6);
        ButtonStylePlan_Mode(8,8,1,8);
        Mode_StylePlan(2);
        Mode_status=6;
    }
    SetInstruction(Mode_status);

}

void frmMain::on_Surround_clicked()
{

    if(Mode_status==8) {
        StyleSheet_Plan_Mode(4);
        ButtonStylePlan_Mode(8,8,8,8);
        Icon_Clear();
        Mode_status=4;
    }else{
        StyleSheet_Plan_Mode(8);
        ButtonStylePlan_Mode(8,8,8,1);
        Mode_StylePlan(4);
        Mode_status=8;
    }
    SetInstruction(Mode_status);

}

void frmMain::StyleSheet_Plan_Mode(int Plan)
{
    switch(Plan)
    {
    case 4:
        ui->Sea->setStyleSheet("background-color: rgb(255,255, 255);color:black;max-width:120px;max-height:120px; min-width:120px; min-height:120px; border-radius:60px;");
        ui->Nature->setStyleSheet("background-color: rgb(255, 255, 255);color:black;max-width:120px;max-height:120px; min-width:120px; min-height:120px; border-radius:60px;");
        ui->Solid->setStyleSheet("background-color: rgb(255, 255, 255);color:black;max-width:120px;max-height:120px; min-width:120px; min-height:120px; border-radius:60px;");
        ui->Surround->setStyleSheet("background-color: rgb(255, 255, 255);color:black;max-width:120px;max-height:120px; min-width:120px; min-height:120px; border-radius:60px;");
        break;
    case 5:
        ui->Nature->setStyleSheet("background-color: rgb(0, 0, 0);color:white;max-width:120px;max-height:120px; min-width:120px; min-height:120px; border-radius:60px;");
        ui->Sea->setStyleSheet("background-color: rgb(255, 255, 255);color:black;max-width:120px;max-height:120px; min-width:120px; min-height:120px; border-radius:60px;");
        ui->Solid->setStyleSheet("background-color: rgb(255, 255, 255);color:black;max-width:120px;max-height:120px; min-width:120px; min-height:120px; border-radius:60px;");
        ui->Surround->setStyleSheet("background-color: rgb(255, 255, 255);color:black;max-width:120px;max-height:120px; min-width:120px; min-height:120px; border-radius:60px;");
        break;
    case 6:
        ui->Solid->setStyleSheet("background-color: rgb(0, 0, 0);color:white;max-width:120px;max-height:120px; min-width:120px; min-height:120px; border-radius:60px;");
        ui->Nature->setStyleSheet("background-color: rgb(255, 255, 255);color:black;max-width:120px;max-height:120px; min-width:120px; min-height:120px; border-radius:60px;");
        ui->Sea->setStyleSheet("background-color: rgb(255, 255, 255);color:black;max-width:120px;max-height:120px; min-width:120px; min-height:120px; border-radius:60px;");
        ui->Surround->setStyleSheet("background-color: rgb(255, 255, 255);color:black;max-width:120px;max-height:120px; min-width:120px; min-height:120px; border-radius:60px;");
        break;
    case 7:
        ui->Sea->setStyleSheet("background-color: rgb(0, 0, 0);color:white;max-width:120px;max-height:120px; min-width:120px; min-height:120px; border-radius:60px;");
        ui->Nature->setStyleSheet("background-color: rgb(255, 255, 255);color:black;max-width:120px;max-height:120px; min-width:120px; min-height:120px; border-radius:60px;");
        ui->Solid->setStyleSheet("background-color: rgb(255, 255, 255);color:black;max-width:120px;max-height:120px; min-width:120px; min-height:120px; border-radius:60px;");
        ui->Surround->setStyleSheet("background-color: rgb(255, 255, 255);color:black;max-width:120px;max-height:120px; min-width:120px; min-height:120px; border-radius:60px;");
        break;
    case 8:
        ui->Surround->setStyleSheet("background-color: rgb(0, 0, 0);color:white;max-width:120px;max-height:120px; min-width:120px; min-height:120px; border-radius:60px;");
        ui->Nature->setStyleSheet("background-color: rgb(255, 255, 255);color:black;max-width:120px;max-height:120px; min-width:120px; min-height:120px; border-radius:60px;");
        ui->Solid->setStyleSheet("background-color: rgb(255, 255, 255);color:black;max-width:120px;max-height:120px; min-width:120px; min-height:120px; border-radius:60px;");
        ui->Sea->setStyleSheet("background-color: rgb(255, 255, 255);color:black;max-width:120px;max-height:120px; min-width:120px; min-height:120px; border-radius:60px;");
        break;
    case 9:
        ui->Sea->setStyleSheet("background-color: rgb(255, 255, 255);color:black;max-width:120px;max-height:120px; min-width:120px; min-height:120px; border-radius:60px;");
        ui->Nature->setStyleSheet("background-color: rgb(255, 255, 255);color:black;max-width:120px;max-height:120px; min-width:120px; min-height:120px; border-radius:60px;");
        ui->Solid->setStyleSheet("background-color: rgb(255, 255, 255);color:black;max-width:120px;max-height:120px; min-width:120px; min-height:120px; border-radius:60px;");
        ui->Surround->setStyleSheet("background-color: rgb(255, 255, 255);color:black;max-width:120px;max-height:120px; min-width:120px; min-height:120px; border-radius:60px;");
        break;
    }
}

void frmMain::StyleSheet_Plan_Fan(int Plan)
{
    switch(Plan)
    {
    case 0:
        ui->Low->setStyleSheet("background-color: rgb(255,255, 255);color:black;max-width:120px;max-height:120px; min-width:120px; min-height:120px; border-radius:60px;");
        ui->Mid->setStyleSheet("background-color: rgb(255, 255, 255);color:black;max-width:120px;max-height:120px; min-width:120px; min-height:120px; border-radius:60px;");
        ui->High->setStyleSheet("background-color: rgb(255, 255, 255);color:black;max-width:120px;max-height:120px; min-width:120px; min-height:120px; border-radius:60px;");
        break;
    case 1:
        ui->Low->setStyleSheet("background-color: rgb(0, 0, 0);color:white;max-width:120px;max-height:120px; min-width:120px; min-height:120px; border-radius:60px;");
        ui->Mid->setStyleSheet("background-color: rgb(255, 255, 255);color:black;max-width:120px;max-height:120px; min-width:120px; min-height:120px; border-radius:60px;");
        ui->High->setStyleSheet("background-color: rgb(255, 255, 255);color:black;max-width:120px;max-height:120px; min-width:120px; min-height:120px; border-radius:60px;");
        break;
    case 2:
        ui->Mid->setStyleSheet("background-color: rgb(0, 0, 0);color:white;max-width:120px;max-height:120px; min-width:120px; min-height:120px; border-radius:60px;");
        ui->Low->setStyleSheet("background-color: rgb(255, 255, 255);color:black;max-width:120px;max-height:120px; min-width:120px; min-height:120px; border-radius:60px;");
        ui->High->setStyleSheet("background-color: rgb(255, 255, 255);color:black;max-width:120px;max-height:120px; min-width:120px; min-height:120px; border-radius:60px;");
        break;
    case 3:
        ui->High->setStyleSheet("background-color: rgb(0, 0, 0);color:white;max-width:120px;max-height:120px; min-width:120px; min-height:120px; border-radius:60px;");
        ui->Low->setStyleSheet("background-color: rgb(255, 255, 255);color:black;max-width:120px;max-height:120px; min-width:120px; min-height:120px; border-radius:60px;");
        ui->Mid->setStyleSheet("background-color: rgb(255, 255, 255);color:black;max-width:120px;max-height:120px; min-width:120px; min-height:120px; border-radius:60px;");
        break;
    }
}

void frmMain::SetInstruction(int Order)
{
    switch(Order)
    {
    case 0:
        emit RadioBroadcast("ZB60101001");
        break;
    case 1:
        emit RadioBroadcast("ZB60101011");
        break;
    case 2:
        emit RadioBroadcast("ZB60101021");
        break;
    case 3:
        emit RadioBroadcast("ZB60101031");
        break;
    case 4:
        emit RadioBroadcast("ZB60101041");
        break;
    case 5:
        emit RadioBroadcast("ZB60101051");
        break;
    case 6:
        emit RadioBroadcast("ZB60101061");
        break;
    case 7:
        emit RadioBroadcast("ZB60101071");
        break;
    case 8:
        emit RadioBroadcast("ZB60101081");
        break;
    case 9:
        emit RadioBroadcast("ZB60101091");
        break;
    }
}

void frmMain::Updata_Ui(int Order)
{
    emit StartSignals();
    qDebug()<<"innnn=-----接受---";
    switch(Order)
    {
    case 0:
        Fan_status=1;
        ui->Low->click();
        break;
    case 1:
        Fan_status=0;
        ui->Low->click();
        break;
    case 2:
        Fan_status=0;
        ui->Mid->click();
        break;
    case 3:
        Fan_status=0;
        ui->High->click();
        break;
    case 4://关闭
        Mode_status=7;
        ui->Sea->click();
        break;
    case 5:

        Mode_status=4;
        ui->Nature->click();

        break;
    case 6:

        Mode_status=4;
        ui->Solid->click();

        break;
    case 7:

        Mode_status=4;
        ui->Sea->click();

    break;
    case 8:

        Mode_status=4;
        ui->Surround->click();

        break;
    case 9:
        break;
}
emit EndSignals();
}

void frmMain::AirQualityIcon_Init()
{
    QString Pm10P = ":/AirQulity/PM10.png";
    QIcon Pm10 = QIcon(Pm10P);
    QPixmap Pm10Map = Pm10.pixmap(Pm10.actualSize(QSize(ui->Pm10P->width(), ui->Pm10P->height())));//size自行调整
    ui->Pm10P->setPixmap(Pm10Map);

    QString Pm25P = ":/AirQulity/pm2.5.png";
    QIcon Pm25 = QIcon(Pm25P);
    QPixmap Pm25Map = Pm25.pixmap(Pm25.actualSize(QSize(ui->Pm25P->width(), ui->Pm25P->height())));//size自行调整
    ui->Pm25P->setPixmap(Pm25Map);

    QString TVCOP = ":/AirQulity/TVOC.png";
    QIcon TVCO = QIcon(TVCOP);
    QPixmap TVCOMap = TVCO.pixmap(TVCO.actualSize(QSize(ui->TVCOP->width(), ui->TVCOP->height())));//size自行调整
    ui->TVCOP->setPixmap(TVCOMap);

    QString Co2P = ":/AirQulity/co2.png";
    QIcon Co2 = QIcon(Co2P);
    QPixmap Co2Map = Co2.pixmap(Co2.actualSize(QSize(ui->Co2P->width(), ui->Co2P->height())));//size自行调整
    ui->Co2P->setPixmap(Co2Map);

    QString HchoP = ":/AirQulity/HCHO.png";
    QIcon Hcho = QIcon(HchoP);
    QPixmap HchoMap = Hcho.pixmap(Hcho.actualSize(QSize(ui->HchoP->width(), ui->HchoP->height())));//size自行调整
    ui->HchoP->setPixmap(HchoMap);

    QString OutSideNo2P = ":/AirQulity/No2.png";
    QIcon OutSideNo2 = QIcon(OutSideNo2P);
    QPixmap OutSideNo2Map = OutSideNo2.pixmap(OutSideNo2.actualSize(QSize(ui->OutSideNo2->width(), ui->OutSideNo2->height())));//size自行调整
    ui->OutSideNo2->setPixmap(OutSideNo2Map);

    QString OutSidePm25P = ":/AirQulity/pm2.5.png";
    QIcon OutSidePm25 = QIcon(OutSidePm25P);
    QPixmap OutSidePm25Map = OutSidePm25.pixmap(OutSidePm25.actualSize(QSize(ui->OutSidePm25->width(), ui->OutSidePm25->height())));//size自行调整
    ui->OutSidePm25->setPixmap(OutSidePm25Map);

    QString OutSideSo2P = ":/AirQulity/So2.png";
    QIcon OutSideSo2 = QIcon(OutSideSo2P);
    QPixmap OutSideSo2Map = OutSideSo2.pixmap(OutSideSo2.actualSize(QSize(ui->OutSideSo2->width(), ui->OutSideSo2->height())));//size自行调整
    ui->OutSideSo2->setPixmap(OutSideSo2Map);

    QString OutSidePm10P = ":/AirQulity/PM10.png";
    QIcon OutSidePm10 = QIcon(OutSidePm10P);
    QPixmap OutSidePm10Map = OutSidePm10.pixmap(OutSidePm10.actualSize(QSize(ui->OutSidePm10->width(), ui->OutSidePm10->height())));//size自行调整
    ui->OutSidePm10->setPixmap(OutSidePm10Map);




}

void frmMain::XprogressbarIfconfig()
{
    QList <XProgressBar*> XProgressBar;
    XProgressBar<<ui->OutSideNo2_Xpro<<ui->OutSidePm25_Xpro<<ui->OutSideSo2_Xpro<<ui->OutSidePm10_Xpro<<ui->OutSidePm25_Xpro<<ui->InsideCo2_Xpro<<ui->InsideHcho_Xpro<<ui->InsidePm10_Xpro<<ui->InsidePm25_Xpro<<ui->InsideTvco_Xpro;
    QLinearGradient lineGradient(0, 0, ui->OutSideNo2_Xpro->width(), ui->OutSideNo2_Xpro->height());
    lineGradient.setColorAt(0.0, QColor("#F1B45B"));
    lineGradient.setColorAt(0.5, QColor("#F2765C"));
    lineGradient.setColorAt(1.0, QColor("#6D59EF"));
    for(int i=0;i<XProgressBar.length();i++){
        XProgressBar[i]->setValueBrush(lineGradient);
        XProgressBar[i]->setAutoRadius(true);
        XProgressBar[i]->setRange(0,100);
    }
}

