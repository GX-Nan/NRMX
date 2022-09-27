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
    SetInstruction(1);
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
    SetInstruction(0);
}

void CurtainSystem::ButtonStylePlan(int Up,int Down,int Stop)
{
    ButtonStyle(ui->Up,Up,35);
    ButtonStyle(ui->Down,Down,35);
    ButtonStyle(ui->Stop,Stop,35);
}

void CurtainSystem::SetInstruction(int Order)
{
    if(SingleFalg==1){
        QString OpenWindow="ZB1010011";
        QString CloseWindow="ZB1010021";
        QString StopWindow="ZB1010031";
        switch (Order) {
        case 0:
            OpenWindow.insert(6,ui->CurrentNumber->text());
            emit RadioBroadcast(OpenWindow);
            break;
        case 1:
            CloseWindow.insert(6,ui->CurrentNumber->text());
            emit RadioBroadcast(CloseWindow);
            break;
        case 4:
            StopWindow.insert(6,ui->CurrentNumber->text());
            emit RadioBroadcast(StopWindow);
            break;
        }
        if(ui->CurrentNumber->text()=="0"){
            status.MessageInsert("1",Order);
            status.MessageInsert("2",Order);
            status.MessageInsert("3",Order);
        }
        else {
            status.MessageInsert(ui->CurrentNumber->text(),Order);
        }
        qDebug()<<"Values:"<<status.Values();
    }
}

void CurtainSystem::ReceiveData(QString)
{

}

void CurtainSystem::BrightnessShow(QString Value)
{
    ui->InsideBrightness->setText(Value);
}

void CurtainSystem::on_Device_Slider_valueChanged(int value)
{
    ui->CurrentNumber->setText(QString::number(value));
    int Curtainstatus= status.GetMessage(QString::number(value));
    CurtainsStatus(Curtainstatus);
}

void CurtainSystem::on_horizontalSlider_2_valueChanged(int value)
{
    ui->CurtainStatus->setText(QString::number(value));
}

void CurtainSystem::CurtainsStatus(int value)
{
    SingleFalg=0;
    switch(value)
    {
    case 0:
        ui->Down->click();
        break;
    case 1:
        ui->Up->click();
        break;
    case 4:
        ui->Stop->click();
        break;
    }
    SingleFalg=1;
}
