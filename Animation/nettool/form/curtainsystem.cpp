#include "curtainsystem.h"
#include "ui_curtainsystem.h"
#include<QGraphicsDropShadowEffect>

CurtainSystem::CurtainSystem(QWidget *parent) :
    QDialog(parent,Qt::WindowTitleHint | Qt::CustomizeWindowHint),
    ui(new Ui::CurtainSystem)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint | Qt::CustomizeWindowHint);
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::Tool);
    Timer=new QTimer(this);
    connect(Timer,&QTimer::timeout,this,&CurtainSystem::AllCurtains);
    AutoTimer=new QTimer(this);
    connect(AutoTimer,&QTimer::timeout,this,&CurtainSystem::AutoMode);
    Shawdow();
}

CurtainSystem::~CurtainSystem()
{
    delete ui;
}

void CurtainSystem::Shawdow()
{
    QGraphicsDropShadowEffect *Bottom = new QGraphicsDropShadowEffect(this);
    Bottom->setOffset(10);
    Bottom->setColor(/*Qt::gray*/QColor(43, 43, 43));
    Bottom->setBlurRadius(35);
    ui->bottom->setGraphicsEffect(Bottom);

    QGraphicsDropShadowEffect *AutoSwitch = new QGraphicsDropShadowEffect(this);
    AutoSwitch->setOffset(10);
    AutoSwitch->setColor(/*Qt::gray*/QColor(43, 43, 43));
    AutoSwitch->setBlurRadius(35);
    ui->AutoSwitch->setGraphicsEffect(AutoSwitch);

    ButtonStylePlan(8,8,8);
}

void CurtainSystem::on_BackMain_clicked()
{
    this->close();
    emit SendClose();
}

void CurtainSystem::ButtonStyle(QPushButton *Name, int Offset, int BlurRadius)
{
    QGraphicsDropShadowEffect *ButtonStyle = new QGraphicsDropShadowEffect(this);
    ButtonStyle->setOffset(Offset);
    ButtonStyle->setColor(/*Qt::gray*/QColor(43, 43, 43));
    ButtonStyle->setBlurRadius(BlurRadius);
    Name->setGraphicsEffect(ButtonStyle);
}

void CurtainSystem::on_Up_clicked()
{
    qDebug()<<"innn---up";
    IconPlan(0);
    ButtonStylePlan(1,8,8);
    ui->Up->setStyleSheet("background-color: rgb(0, 0, 0);color:white;border-radius:15px;");
    ui->Down->setStyleSheet("background-color: rgb(255, 255, 255);color:black;border-radius:15px;");
    ui->Stop->setStyleSheet("background-color: rgb(255, 255,255 );color:black;border-radius:15px;");
    SetInstruction(0);
}

void CurtainSystem::on_Stop_clicked()
{
    IconPlan(4);
    ButtonStylePlan(8,8,1);
    ui->Stop->setStyleSheet("background-color: rgb(0, 0, 0);color:white;border-radius:15px;");
    ui->Down->setStyleSheet("background-color: rgb(255, 255, 255);color:black;border-radius:15px;");
    ui->Up->setStyleSheet("background-color: rgb(255, 255,255 );color:black;border-radius:15px;");
    SetInstruction(4);
}

void CurtainSystem::on_Down_clicked()
{


    IconPlan(1);
    ButtonStylePlan(8,1,8);
    ui->Down->setStyleSheet("background-color: rgb(0, 0, 0);color:white;border-radius:15px;");
    ui->Stop->setStyleSheet("background-color: rgb(255, 255, 255);color:black;border-radius:15px;");
    ui->Up->setStyleSheet("background-color: rgb(255, 255,255 );color:black;border-radius:15px;");
    SetInstruction(1);
}

void CurtainSystem::ButtonStylePlan(int Up,int Down,int Stop)
{
    ButtonStyle(ui->Up,Up,35);
    ButtonStyle(ui->Down,Down,35);
    ButtonStyle(ui->Stop,Stop,35);
}

void CurtainSystem::SetInstruction(int Order)
{
    QString Up="ZB1020001";
    QString Down="ZB1020011";
    QString Stop="ZB1020041";
    QString WxData="Curtain_";
    if(ui->CurrentNumber->text()=="0")
    {
        for(int i=0;i<=3;i++){
            WxData.insert(WxData.length(),QString::number(i));
            qDebug()<<WxData;
            emit SendToWx(WxData,Order);
            WxData.remove(WxData.length()-1,WxData.length());
        }
    }
    else {
        WxData.insert(8,ui->CurrentNumber->text());
        emit SendToWx(WxData,Order);
        qDebug()<<"Order:"<<Order<<"WxData:"<<WxData;
    }

    switch (Order) {
    case 1:
        if(ui->CurrentNumber->text()!="0"){
            Down.insert(6,ui->CurrentNumber->text());
            emit RadioBroadcast(Down);
        }
        else {
            emit RadioBroadcast("ZB10200011");
            Timer->stop();
            AllCurtainsFalg=1;
            Timer->start(800);
        }
        emit SendToWx(WxData,1);
        break;
    case 0:
        if(ui->CurrentNumber->text()!="0"){
            Up.insert(6,ui->CurrentNumber->text());
            emit RadioBroadcast(Up);
        }
        else {
            emit RadioBroadcast("ZB10200001");
            Timer->stop();
            AllCurtainsFalg=0;
            Timer->start(800);
        }
        emit SendToWx(WxData,0);
        break;
    case 4:
        if(ui->CurrentNumber->text()!="0"){
            Stop.insert(6,ui->CurrentNumber->text());
            emit RadioBroadcast(Stop);
        }
        else {
            emit RadioBroadcast("ZB10200041");
            Timer->stop();
            AllCurtainsFalg=4;
            Timer->start(800);
        }
        emit SendToWx(WxData,4);
        break;
    }
    status.MessageInsert(ui->CurrentNumber->text(),Order);
}

void CurtainSystem::ReceiveData(QString)//貌似没有用
{

}

void CurtainSystem::BrightnessShow(QString Value)//室内光照强度
{
    ui->InsideBrightness->setText(Value);
}

void CurtainSystem::Ui_Update(int Sub, int Value)
{
    ui->Device_Slider->setValue(Sub);
    CurtainsStatus(Value);
    qDebug()<<"Curtain--Update";
}

void CurtainSystem::on_Device_Slider_valueChanged(int value)
{
    SingleFalg=0;
    ui->CurrentNumber->setText(QString::number(value));
    int Curtainstatus= status.GetMessage(QString::number(value));
    CurtainsStatus(Curtainstatus);

    qDebug()<<"Curtain--Device";
}

void CurtainSystem::on_horizontalSlider_2_valueChanged(int value)
{
    // ui->CurtainStatus->setText(QString::number(value));
}

void CurtainSystem::CurtainsStatus(int value)
{
    if(SingleFalg==1){
        switch(value)
        {
        case 1:
            ui->Down->click();
            qDebug()<<"down-------------Curtains";
            break;
        case 0:
            ui->Up->click();
            qDebug()<<"Up-------------Curtains";
            break;
        case 4:
            ui->Stop->click();
            break;
        }
    }
    SingleFalg=1;
}

void CurtainSystem::AllCurtains()
{
    QString Up="ZB1020001";
    QString Down="ZB1020011";
    QString Stop="ZB1020041";

    if(AllCurtainsStop!=4){
        if(AllCurtainsFalg==1){
            Down.insert(6,QString::number(AllCurtainsStop));
            emit RadioBroadcast(Down);
            qDebug()<<"Down:"<<Down;
        }
        else if(AllCurtainsFalg==0){
            Up.insert(6,QString::number(AllCurtainsStop));
            emit RadioBroadcast(Up);
        }
        else if(AllCurtainsFalg==4){
            Stop.insert(6,QString::number(AllCurtainsStop));
            emit RadioBroadcast(Stop);
        }
        AllCurtainsStop=AllCurtainsStop+1;
    }
    else {
        AllCurtainsStop=1;
        Timer->stop();
    }
}

void CurtainSystem::on_AutoSwitch_clicked()
{
    if(AutoFlag==0){
        ui->AutoSwitch->setIcon(QIcon(":/new/Led/Led/AI_OFF.png"));
        ui->AutoSwitch->setStyleSheet("background-color: rgb(0, 0, 0);color:black; border-radius:15px;");
        AutoTimer->start(1000);
        ui->Device_Slider->setEnabled(0);
        ui->Up->setEnabled(0);
        ui->Down->setEnabled(0);
        ui->Stop->setEnabled(0);
        AutoFlag=1;
    }
    else{
        ui->AutoSwitch->setIcon(QIcon(":/new/Led/Led/AI_ON.png"));
        ui->AutoSwitch->setStyleSheet("background-color: rgb(255, 255, 255);color:black; border-radius:15px;");
        AutoTimer->stop();
        ui->Device_Slider->setEnabled(1);
        ui->Up->setEnabled(1);
        ui->Down->setEnabled(1);
        ui->Stop->setEnabled(1);
        AutoFlag=0;
    }
}

void CurtainSystem::AutoMode()
{
    QTime CurrentTime = QTime::currentTime();
    int Hour=CurrentTime.hour();
    int Status=status.GetMessage("0");
    qDebug()<<"当前时间："<<Hour;
    ui->Device_Slider->setValue(0);
    if (Hour<12&&Hour>=7) {//上天
        qDebug()<<"上午"<<Hour;
        if(Status!=0){
            on_Up_clicked();
        }
    }
    else if(Hour>=12&&Hour<14){//中午
        if(Status!=1){
            on_Down_clicked();
        }
    }
    else if(Hour>=14&&Hour<20){//下午
        if(Status!=0){
            on_Up_clicked();
        }
    }
    else {//下班
        if(Status!=1){
            on_Down_clicked();
        }
    }
}

void CurtainSystem::IconPlan(int Order)
{
    switch(Order){
    case 0:
        ui->Up->setIcon(QIcon(":/new/Curtain/Curtain/Up_ON.png"));
        ui->Down->setIcon(QIcon(":/new/Curtain/Curtain/Down_OFF.png"));
        ui->Stop->setIcon(QIcon(":/new/Curtain/Curtain/Stop_OFF.png"));
        break;
    case 1:
        ui->Up->setIcon(QIcon(":/new/Curtain/Curtain/Up_OFF.png"));
        ui->Down->setIcon(QIcon(":/new/Curtain/Curtain/Down_ON.png"));
        ui->Stop->setIcon(QIcon(":/new/Curtain/Curtain/Stop_OFF.png"));
        break;
    case 4:
        ui->Up->setIcon(QIcon(":/new/Curtain/Curtain/Up_OFF.png"));
        ui->Down->setIcon(QIcon(":/new/Curtain/Curtain/Down_OFF.png"));
        ui->Stop->setIcon(QIcon(":/new/Curtain/Curtain/Stop_ON.png"));
        break;
    }
}
