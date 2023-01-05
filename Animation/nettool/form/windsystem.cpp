#include "windsystem.h"
#include "ui_windsystem.h"
#include<QGraphicsDropShadowEffect>

WindSystem::WindSystem(QWidget *parent) :
    QDialog(parent,Qt::WindowTitleHint | Qt::CustomizeWindowHint),
    ui(new Ui::WindSystem)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint | Qt::CustomizeWindowHint);
    //this->setWindowFlags(Qt::FramelessWindowHint | Qt::Tool);
    // this->setAttribute(Qt::WA_TranslucentBackground);
    this->setAttribute(Qt::WA_AcceptTouchEvents,true);
    AirSubUi=new WindAirQuality(this);
    ModeSubUi=new WindMode(this);
    connect(this,&WindSystem::Enable,ModeSubUi,&WindMode::Enable);
    connect(ModeSubUi,&WindMode::RadioBroadcast,this,&WindSystem::RadioBroadcast);
    connect(ModeSubUi,&WindMode::SendToWx,this,&WindSystem::SendToWx);
    connect(this,&WindSystem::Xprogress_Update,AirSubUi,&WindAirQuality::Xprogressbar_Update);
    connect(this,&WindSystem::ModeCtrl,ModeSubUi,&WindMode::ModeCtrl);
    Image_Init();
    Shadow();
    StopTime=new QTimer(this);
    connect(StopTime,&QTimer::timeout,this,&WindSystem::AiWindWait);
}

WindSystem::~WindSystem()
{
    delete ui;
}

void WindSystem::on_pushButton_2_clicked()
{
    emit SendClose();
    AirSubUi->close();
    ModeSubUi->close();
    this->close();
}

void WindSystem::ButtonStyle(QPushButton *Name, int Offset, int BlurRadius)
{
    QGraphicsDropShadowEffect *ButtonStyle = new QGraphicsDropShadowEffect(this);
    ButtonStyle->setOffset(Offset);
    ButtonStyle->setColor(/*Qt::gray*/QColor(43, 43, 43));
    ButtonStyle->setBlurRadius(BlurRadius);
    Name->setGraphicsEffect(ButtonStyle);
}

void WindSystem::ShowSubUi()
{
    AirSubUi->show();
    AirSubUi->move(1170,200);
    ModeSubUi->show();
    ModeSubUi->move(330,200);
}

void WindSystem::Shadow()
{
    ButtonStylePlan(8,8,8,8);

    QGraphicsDropShadowEffect *Bottom = new QGraphicsDropShadowEffect(this);
    Bottom->setOffset(8);
    Bottom->setColor(/*Qt::gray*/QColor(43, 43, 43));
    Bottom->setBlurRadius(15);
    ui->bottom->setGraphicsEffect(Bottom);

    QGraphicsDropShadowEffect *AutoSwitch = new QGraphicsDropShadowEffect(this);
    AutoSwitch->setOffset(8);
    AutoSwitch->setColor(/*Qt::gray*/QColor(43, 43, 43));
    AutoSwitch->setBlurRadius(15);
    ui->AutoSwitch->setGraphicsEffect(AutoSwitch);
}

void WindSystem::ReceiveData(const Wind_Data VarValue,int Value)
{
    qDebug()<<"Wind---receiveData";
    data=VarValue;
    switch(Value)
    {
    case 0:
        ui->StopMode->click();
        ModeSubUi->Clear();
        data.Mode=0;
        break;
    case 1:
        ui->MinMode->click();
        break;
    case 2:
        ui->MidMode->click();
        break;
    case 3:
        ui->MaxMode->click();
        break;
    case 4:
        emit ModeCtrl(0);
        break;
    case 5:
        emit ModeCtrl(1);
        break;
    case 6:
        emit ModeCtrl(2);
        break;
    case 7:
        emit ModeCtrl(3);
        break;
    case 8:
        emit ModeCtrl(4);
        break;
    }
    //SetInstruction(data.Station);
}

void WindSystem::AirAutoTigger(int data)
{
    //1.逻辑-
    //2.判断是否开启
    //3.那部分有人---然后再开那部分的风量口
    qDebug()<<"查看状态---"<<StopSend;
    if(AutoFlag==1){//----------?无法确定是否开了？
        if(StopAiTime==0){
            switch(data){
            case 0:
                qDebug()<<"开新风------关";
                if(StopSend==1){
                    on_StopMode_clicked();
                    StopSend=0;
                }
                break;
            case 1:
                qDebug()<<"开新风------开";
                if(StopSend==0){
                    on_MaxMode_clicked();
                    StopTime->start(50000);
                    emit WindLock(1);
                    StopSend=1;
                }
                StopAiTime=1;
                break;
            }
        }
    }
}

void WindSystem::Auto_Sync(int data)
{
    switch(data){
    case 0:
        AutoFlag=1;
        ui->AutoSwitch->click();
        break;
    case 1:
        AutoFlag=0;
        ui->AutoSwitch->click();
        break;
    }
}

void WindSystem::Location_Sync(int sub, int value)
{
    switch (sub) {
    case 1:
        locationMeeting=value;
        break;
    case 2:
        locationBar=value;
        break;
    case 3:
        locationOffice=value;
        break;
    }
    if(StopSend==1){
        qDebug()<<"新风----判断---是否有人---";
        InductiveLogic();
    }

}

void WindSystem::Tuyere_Sync(QString data)
{
    qDebug()<<"Tuyere----data:"<<data;
    emit RadioBroadcast(data);
}



void WindSystem::on_StopMode_clicked()
{
    Icon_Plan(0);//图标
    ButtonStylePlan(1,8,8,8);
    emit ModeCtrl(0);
    ModeSubUi->Clear();
    data.Mode=0;
    BackgroundPlan(0,1,2,3);
    SetInstruction(0);
    emit SendToWx("WindSpeed",0);

}

void WindSystem::on_MinMode_clicked()
{
    Icon_Plan(1);//图标
    ButtonStylePlan(8,1,8,8);
    emit Enable(1);
    BackgroundPlan(1,0,2,3);
    SetInstruction(1);
    emit SendToWx("WindSpeed",1);

}

void WindSystem::on_MidMode_clicked()
{
    Icon_Plan(2);//图标
    ButtonStylePlan(8,8,1,8);
    BackgroundPlan(2,0,1,3);
    emit Enable(1);
    SetInstruction(2);
    emit SendToWx("WindSpeed",2);
}

void WindSystem::on_MaxMode_clicked()
{
    Icon_Plan(3);//图标
    ButtonStylePlan(8,8,8,1);
    BackgroundPlan(3,2,1,0);
    emit Enable(1);
    SetInstruction(3);
    emit SendToWx("WindSpeed",3);
}

void WindSystem::ButtonStylePlan(int i, int i2, int i3,int i4)
{
    ButtonStyle(ui->StopMode,i,35);
    ButtonStyle(ui->MinMode,i2,35);
    ButtonStyle(ui->MidMode,i3,35);
    ButtonStyle(ui->MaxMode,i4,35);
}

void WindSystem::Image_Init()
{
    QString filePath = ":/new/Wind/Wind/WindP.png";//图标位置自行调整
    QIcon icon = QIcon(filePath);
    QPixmap m_pic = icon.pixmap(icon.actualSize(QSize(120, 120)));//size自行调整
    ui->Pirture->setPixmap(m_pic);
}
void WindSystem::BackgroundPlan(int i, int i2, int i3, int i4)
{
    QList <QPushButton *>list;
    list<<ui->StopMode<<ui->MinMode<<ui->MidMode<<ui->MaxMode;
    list[i]->setStyleSheet("background-color: rgb(0, 0, 0);border-radius:15px;");
    list[i2]->setStyleSheet("background-color: rgb(255, 255, 255);border-radius:15px;");
    list[i3]->setStyleSheet("background-color: rgb(255, 255, 255);border-radius:15px;");
    list[i4]->setStyleSheet("background-color: rgb(255, 255, 255);border-radius:15px;");
}

void WindSystem::SetInstruction(int Order)
{
    qDebug()<<"Order"<<Order;
    if(SingleFalg==1){
        QString data="ZB6010101";
        data.insert(8,QString::number(Order));
        qDebug()<<"Order:"<<data;
        emit RadioBroadcast(data);
    }
}

void WindSystem::on_AutoSwitch_clicked()
{
    if(AutoFlag==0){
        ui->AutoSwitch->setIcon(QIcon(":/new/Led/Led/AI_OFF.png"));
        ui->AutoSwitch->setStyleSheet("background-color: rgb(0, 0, 0);color:black; border-radius:15px;");
        ui->ButtonBox->setEnabled(0);
        emit AutoMode_Sync(1);
        AutoFlag=1;
    }else{
        ui->AutoSwitch->setIcon(QIcon(":/new/Led/Led/AI_ON.png"));
        ui->AutoSwitch->setStyleSheet("background-color: rgb(255, 255, 255);color:black; border-radius:15px;");
        ui->ButtonBox->setEnabled(1);
        emit AutoMode_Sync(0);
        AutoFlag=0;
    }
}

void WindSystem::Icon_Plan(int Order)
{
    switch(Order){
    case 0:
        ui->StopMode->setIcon(QIcon(":/new/Curtain/Curtain/Stop_ON.png"));
        ui->MinMode->setIcon(QIcon(":/new/Wind/Wind/Low_OFF.png"));
        ui->MidMode->setIcon(QIcon(":/new/Wind/Wind/Mid_OFF.png"));
        ui->MaxMode->setIcon(QIcon(":/new/Wind/Wind/High_OFF.png"));
        break;
    case 1:
        ui->StopMode->setIcon(QIcon(":/new/Curtain/Curtain/Stop_OFF.png"));
        ui->MinMode->setIcon(QIcon(":/new/Wind/Wind/Low_ON.png"));
        ui->MidMode->setIcon(QIcon(":/new/Wind/Wind/Mid_OFF.png"));
        ui->MaxMode->setIcon(QIcon(":/new/Wind/Wind/High_OFF.png"));
        break;
    case 2:
        ui->StopMode->setIcon(QIcon(":/new/Curtain/Curtain/Stop_OFF.png"));
        ui->MinMode->setIcon(QIcon(":/new/Wind/Wind/Low_OFF.png"));
        ui->MidMode->setIcon(QIcon(":/new/Wind/Wind/Mid_ON.png"));
        ui->MaxMode->setIcon(QIcon(":/new/Wind/Wind/High_OFF.png"));
        break;
    case 3:
        ui->StopMode->setIcon(QIcon(":/new/Curtain/Curtain/Stop_OFF.png"));
        ui->MinMode->setIcon(QIcon(":/new/Wind/Wind/Low_OFF.png"));
        ui->MidMode->setIcon(QIcon(":/new/Wind/Wind/Mid_OFF.png"));
        ui->MaxMode->setIcon(QIcon(":/new/Wind/Wind/High_ON.png"));
        break;
    }
}

void WindSystem::InductiveLogic()
{
    //2---90（打开）  4---180(关闭)
    //-------吧台
    if (locationBar==1) {
        //开启
        emit RadioBroadcast("ZB60201021");
        emit RadioBroadcast("ZB60203021");
    }
    else{
        emit RadioBroadcast("ZB60201041");
        emit RadioBroadcast("ZB60203041");
    }
    //-----办公
    if(locationOffice==1){
        emit RadioBroadcast("ZB60202021");
        emit RadioBroadcast("ZB60204021");
    }
    else{
        emit RadioBroadcast("ZB60202041");
        emit RadioBroadcast("ZB60204041");
    }
    //-------会议室
    if(locationMeeting==1){
        emit RadioBroadcast("ZB60205021");
        emit RadioBroadcast("ZB60206021");
    }
    else{
        emit RadioBroadcast("ZB60205041");
        emit RadioBroadcast("ZB60206041");
    }
}

void WindSystem::AiWindWait()
{
    qDebug()<<"Timer等待-----新风";
    if(StopSend==1){
        if(Time==0){
            qDebug()<<"加1-----新风";
            Time=Time+1;
        }else{
            qDebug()<<"结束等待-----新风";
            emit WindLock(0);
            StopAiTime=0;
            StopTime->stop();
            Time=0;
        }
    }
}


