#include "windsystem.h"
#include "ui_windsystem.h"
#include<QGraphicsDropShadowEffect>

WindSystem::WindSystem(QWidget *parent) :
    QDialog(parent,Qt::WindowTitleHint | Qt::CustomizeWindowHint),
    ui(new Ui::WindSystem)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint | Qt::CustomizeWindowHint);
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::Tool);
   // this->setAttribute(Qt::WA_TranslucentBackground);
    AirSubUi=new WindAirQuality(this);
    ModeSubUi=new WindMode(this);
    connect(this,&WindSystem::Enable,ModeSubUi,&WindMode::Enable);
    connect(ModeSubUi,&WindMode::RadioBroadcast,this,&WindSystem::RadioBroadcast);
    connect(this,&WindSystem::Xprogress_Update,AirSubUi,&WindAirQuality::Xprogressbar_Update);
    Image_Init();
    Shadow();
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
    qDebug()<<"innn------------2";
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
}

void WindSystem::ReceiveData(const Wind_Data VarValue)
{
    qDebug()<<"传进来了捏";
    data=VarValue;
    switch (data.Station) {
    case 0:
        ButtonStylePlan(1,8,8,8);
        ModeSubUi->Clear();
        data.Mode=0;
        break;
    case 1:
        ButtonStylePlan(8,1,8,8);
        break;
    case 2:
        ButtonStylePlan(8,8,1,8);
        break;
    case 3:
        ButtonStylePlan(8,8,8,1);
        break;
    }
//    qDebug()<<"data.Mode"<<data.Mode;
//    ModeSubUi->Ui_Update(data.Mode);
}



void WindSystem::on_StopMode_clicked()
{
    ButtonStylePlan(1,8,8,8);
    ModeSubUi->Clear();
    data.Mode=0;
    BackgroundPlan(0,1,2,3);
    emit RadioBroadcast("ZB60101001");
}

void WindSystem::on_MinMode_clicked()
{
    ButtonStylePlan(8,1,8,8);
    emit Enable(1);
    BackgroundPlan(1,0,2,3);
    emit RadioBroadcast("ZB60101011");
}

void WindSystem::on_MidMode_clicked()
{
    ButtonStylePlan(8,8,1,8);
    BackgroundPlan(2,0,1,3);
    emit Enable(1);
    emit RadioBroadcast("ZB60101021");
}

void WindSystem::on_HighMode_clicked()
{
    ButtonStylePlan(8,8,8,1);
    BackgroundPlan(3,2,1,0);
    emit Enable(1);
    emit RadioBroadcast("ZB60101031");
}

void WindSystem::ButtonStylePlan(int i, int i2, int i3,int i4)
{
    ButtonStyle(ui->StopMode,i,35);
    ButtonStyle(ui->MinMode,i2,35);
    ButtonStyle(ui->MidMode,i3,35);
    ButtonStyle(ui->HighMode,i4,35);
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
    list<<ui->StopMode<<ui->MinMode<<ui->MidMode<<ui->HighMode;
    list[i]->setStyleSheet("background-color: rgb(0, 0, 0);border-radius:15px;");
    list[i2]->setStyleSheet("background-color: rgb(255, 255, 255);border-radius:15px;");
    list[i3]->setStyleSheet("background-color: rgb(255, 255, 255);border-radius:15px;");
    list[i4]->setStyleSheet("background-color: rgb(255, 255, 255);border-radius:15px;");
}
