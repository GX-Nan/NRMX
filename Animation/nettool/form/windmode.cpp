#include "windmode.h"
#include "ui_windmode.h"
#include<QGraphicsDropShadowEffect>

WindMode::WindMode(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WindMode)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint | Qt::CustomizeWindowHint);
  //  this->setWindowFlags(Qt::FramelessWindowHint | Qt::Tool);
    // this->setAttribute(Qt::WA_TranslucentBackground);
    ShawDowm();
}

WindMode::~WindMode()
{
    delete ui;
}

void WindMode::ShawDowm()
{
    QGraphicsDropShadowEffect *Bottom = new QGraphicsDropShadowEffect(this);
    Bottom->setOffset(8);
    Bottom->setColor(/*Qt::gray*/QColor(43, 43, 43));
    Bottom->setBlurRadius(25);
    ui->bottom->setGraphicsEffect(Bottom);

    ButtonStyle(ui->SeaMode,8,35);
    ButtonStyle(ui->SurroundMode,8,35);
    ButtonStyle(ui->NaturalMode,8,35);
    ButtonStyle(ui->StereoscopicMode,8,35);
    ButtonStyle(ui->CloseMode,8,35);
}

void WindMode::ButtonStyle(QPushButton *Name, int Offset, int BlurRadius)
{
    QGraphicsDropShadowEffect *ButtonStyle = new QGraphicsDropShadowEffect(this);
    ButtonStyle->setOffset(Offset);
    ButtonStyle->setColor(/*Qt::gray*/QColor(43, 43, 43));
    ButtonStyle->setBlurRadius(BlurRadius);
    Name->setGraphicsEffect(ButtonStyle);
}

void WindMode::on_SeaMode_clicked()
{
    ButtonStylePlan(8,1,8,8,8);
    BackgroundPlan(1,3,0,2,4);
    emit RadioBroadcast("ZB60101071");
    emit SendToWx("WindMode",7);
}

void WindMode::on_SurroundMode_clicked()
{
    ButtonStylePlan(8,8,8,1,8);
    BackgroundPlan(3,1,0,2,4);
    emit RadioBroadcast("ZB60101081");
    emit SendToWx("WindMode",8);
}

void WindMode::on_NaturalMode_clicked()
{
    ButtonStylePlan(8,8,1,8,8);
    BackgroundPlan(2,1,0,3,4);
    emit RadioBroadcast("ZB60101051");
    emit SendToWx("WindMode",5);
}

void WindMode::on_StereoscopicMode_clicked()
{
    ButtonStylePlan(1,8,8,8,8);
    BackgroundPlan(0,1,2,3,4);
    emit RadioBroadcast("ZB60101061");
    emit SendToWx("WindMode",6);
}



void WindMode::ButtonStylePlan(int i, int i2, int i3, int i4,int i5)
{
    ButtonStyle(ui->StereoscopicMode,i,35);
    ButtonStyle(ui->SeaMode,i2,35);
    ButtonStyle(ui->NaturalMode,i3,35);
    ButtonStyle(ui->SurroundMode,i4,35);
    ButtonStyle(ui->CloseMode,i5,35);
}

void WindMode::BackgroundPlan(int i, int i2, int i3, int i4,int i5)
{
    QList <QPushButton *>list;
    list<<ui->StereoscopicMode<<ui->SeaMode<<ui->NaturalMode<<ui->SurroundMode<<ui->CloseMode;
    list[i]->setStyleSheet("background-color: rgb(0, 0, 0);border-radius:15px;");
    list[i2]->setStyleSheet("background-color: rgb(255, 255, 255);border-radius:15px;");
    list[i3]->setStyleSheet("background-color: rgb(255, 255, 255);border-radius:15px;");
    list[i4]->setStyleSheet("background-color: rgb(255, 255, 255);border-radius:15px;");
    list[i5]->setStyleSheet("background-color: rgb(255, 255, 255);border-radius:15px;");
}

void WindMode::ModeCtrl(int value)
{
    switch(value)
    {
    case 0:
        ui->CloseMode->click();
        break;
    case 1:
        ui->NaturalMode->click();
        break;
    case 2:
        ui->StereoscopicMode->click();
        break;
    case 3:
        ui->SeaMode->click();
        break;
    case 4:
        ui->SurroundMode->click();
        break;
    }

}

void WindMode::Clear()
{
    ButtonStyle(ui->StereoscopicMode,8,35);
    ButtonStyle(ui->SeaMode,8,35);
    ButtonStyle(ui->NaturalMode,8,35);
    ButtonStyle(ui->SurroundMode,8,35);
    ui->bottom->setEnabled(0);
}

void WindMode::Enable(bool Falg)
{
    qDebug()<<"Enable"<<Falg;
    ui->bottom->setEnabled(Falg);
}

void WindMode::on_CloseMode_clicked()
{
    //Clear();
    BackgroundPlan(4,1,2,3,0);
    emit RadioBroadcast("ZB60101041");
    emit SendToWx("WindMode",0);
}
