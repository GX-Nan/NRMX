#include "doorsystem.h"
#include "ui_doorsystem.h"
#include<QGraphicsDropShadowEffect>

DoorSystem::DoorSystem(QWidget *parent) :
    QDialog(parent,Qt::WindowTitleHint | Qt::CustomizeWindowHint),
    ui(new Ui::DoorSystem)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint | Qt::CustomizeWindowHint);
    //this->setWindowFlags(Qt::FramelessWindowHint | Qt::Tool);
   // this->setAttribute(Qt::WA_TranslucentBackground);
    Shawdow();
}

DoorSystem::~DoorSystem()
{
    delete ui;
}

void DoorSystem::Shawdow()
{
    ButtonStyle(ui->OpenDoor,8,35);
    ButtonStyle(ui->CloseDoor,8,35);

    QGraphicsDropShadowEffect *PassTimes = new QGraphicsDropShadowEffect(this);
    PassTimes->setOffset(8);
    PassTimes->setColor(/*Qt::gray*/QColor(43, 43, 43));
    PassTimes->setBlurRadius(25);
    ui->PassTimes->setGraphicsEffect(PassTimes);
}

void DoorSystem::on_BackMain_clicked()
{
    this->close();
    emit SendClose();
}

void DoorSystem::on_OpenDoor_clicked()
{
    ButtonStyle(ui->OpenDoor,1,35);
    ButtonStyle(ui->CloseDoor,8,35);
}

void DoorSystem::on_CloseDoor_clicked()
{
    ButtonStyle(ui->CloseDoor,1,35);
    ButtonStyle(ui->OpenDoor,8,35);
}

void DoorSystem::ButtonStyle(QPushButton *Name,int Offset,int BlurRadius)
{
    QGraphicsDropShadowEffect *ButtonStyle = new QGraphicsDropShadowEffect(this);
    ButtonStyle->setOffset(Offset);
    ButtonStyle->setColor(/*Qt::gray*/QColor(43, 43, 43));
    ButtonStyle->setBlurRadius(BlurRadius);
    Name->setGraphicsEffect(ButtonStyle);
}
