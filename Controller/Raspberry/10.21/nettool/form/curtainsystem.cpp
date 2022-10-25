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
    //this->setAttribute(Qt::WA_TranslucentBackground);
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

    //    QGraphicsDropShadowEffect *ShowBottom = new QGraphicsDropShadowEffect(this);
    //    ShowBottom->setOffset(10);
    //    ShowBottom->setColor(/*Qt::gray*/QColor(43, 43, 43));
    //    ShowBottom->setBlurRadius(35);
    //    ui->ShowBottom->setGraphicsEffect(ShowBottom);

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
    ButtonStylePlan(1,8,8);
    ui->Up->setStyleSheet("background-color: rgb(0, 0, 0);color:white;border-radius:15px;");
    ui->Down->setStyleSheet("background-color: rgb(255, 255, 255);color:black;border-radius:15px;");
    ui->Stop->setStyleSheet("background-color: rgb(255, 255,255 );color:black;border-radius:15px;");
    SetInstruction(0);
}

void CurtainSystem::on_Stop_clicked()
{
    ButtonStylePlan(8,8,1);
    ui->Stop->setStyleSheet("background-color: rgb(0, 0, 0);color:white;border-radius:15px;");
    ui->Down->setStyleSheet("background-color: rgb(255, 255, 255);color:black;border-radius:15px;");
    ui->Up->setStyleSheet("background-color: rgb(255, 255,255 );color:black;border-radius:15px;");
    SetInstruction(4);
}

void CurtainSystem::on_Down_clicked()
{
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
        for(int i=0;i<=2;i++){
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
            emit RadioBroadcast("ZB10201011");
            emit RadioBroadcast("ZB10202011");
            emit RadioBroadcast("ZB10203011");
        }
        break;
    case 0:
        Up.insert(6,ui->CurrentNumber->text());
        emit RadioBroadcast(Up);
        break;
    case 4:
        Stop.insert(6,ui->CurrentNumber->text());
        emit SendToWx(WxData,4);
        emit RadioBroadcast(Stop);
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
    ui->CurtainStatus->setText(QString::number(value));
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
