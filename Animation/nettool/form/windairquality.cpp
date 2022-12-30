#include "windairquality.h"
#include "ui_windairquality.h"
#include<QGraphicsDropShadowEffect>

WindAirQuality::WindAirQuality(QWidget *parent) :
    QDialog(parent,Qt::WindowTitleHint | Qt::CustomizeWindowHint),
    ui(new Ui::WindAirQuality)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint | Qt::CustomizeWindowHint);
  //  this->setWindowFlags(Qt::FramelessWindowHint | Qt::Tool);
   // this->setAttribute(Qt::WA_TranslucentBackground);
    ShawDowm();
    Xprogressbar_Init();
    Image_Init();
    //this->move(200,0);
}

WindAirQuality::~WindAirQuality()
{
    delete ui;
}

void WindAirQuality::ShawDowm()
{
    QGraphicsDropShadowEffect *Bottom = new QGraphicsDropShadowEffect(this);
    Bottom->setOffset(8);
    Bottom->setColor(/*Qt::gray*/QColor(43, 43, 43));
    Bottom->setBlurRadius(25);
    ui->bottom->setGraphicsEffect(Bottom);
}

void WindAirQuality::Xprogressbar_Init()
{
    QList <XProgressBar *>XprogressList;
    XprogressList<<ui->Co2_Xprogress<<ui->HCHO_Xprogress<<ui->TVCO_Xprogress<<ui->PM25_Xprogress<<ui->PM10_Xprogress;
    for(int i=0;i<5;i++)
    {
        XprogressList[i]->setAutoRadius(true);
        QLinearGradient lineGradient(0, 0, XprogressList[i]->width(), XprogressList[i]->height());
        lineGradient.setColorAt(0.0, QColor("#338763"));
        lineGradient.setColorAt(1.0, QColor("#338763"));
        XprogressList[i]->setValueBrush(lineGradient);
        XprogressList[i]->setValue(50);
        XprogressList[i]->setRange(0,100);
    }
    XprogressList[0]->setRange(0,1000);
    XprogressList[2]->setRange(0,1000);
}

void WindAirQuality::Xprogressbar_Update(AirQuality Data)
{
    ui->Co2_Xprogress->setValue(Data.Co2);
    ui->HCHO_Xprogress->setValue(Data.HCHO);
    ui->TVCO_Xprogress->setValue(Data.TVCO);
    ui->PM25_Xprogress->setValue(Data.PM25);
    ui->PM10_Xprogress->setValue(Data.PM10);

    ui->Co2_Label->setText(QString::number(Data.Co2)+"/mg");
    ui->HCHO_Label->setText(QString::number(Data.HCHO)+"/mg");
    ui->Tvco_Label->setText(QString::number(Data.TVCO)+"/mg");
    ui->Pm25_Label->setText(QString::number(Data.PM25)+"/mg");
    ui->Pm10_Label->setText(QString::number(Data.PM10)+"/mg");
}

void WindAirQuality::Image_Init()
{
    QString filePath2 = ":/new/AirQulity/AirQulity/co2.png";//图标位置自行调整
    QIcon icon2 = QIcon(filePath2);
    QPixmap m_pic2 = icon2.pixmap(icon2.actualSize(QSize(50, 50)));//size自行调整
    ui->Co2P->setPixmap(m_pic2);

    QString filePath3 = ":/new/AirQulity/AirQulity/HCHO.png";//图标位置自行调整
    QIcon icon3 = QIcon(filePath3);
    QPixmap m_pic3 = icon3.pixmap(icon3.actualSize(QSize(50, 50)));//size自行调整
    ui->HCHOP->setPixmap(m_pic3);

    QString filePath4 = ":/new/AirQulity/AirQulity/TVOC.png";//图标位置自行调整
    QIcon icon4 = QIcon(filePath4);
    QPixmap m_pic4 = icon4.pixmap(icon4.actualSize(QSize(50, 50)));//size自行调整
    ui->TVCOP->setPixmap(m_pic4);

    QString filePath5 = ":/new/AirQulity/AirQulity/pm2.5.png";//图标位置自行调整
    QIcon icon5 = QIcon(filePath5);
    QPixmap m_pic5 = icon5.pixmap(icon5.actualSize(QSize(50, 50)));//size自行调整
    ui->PM25P->setPixmap(m_pic5);

    QString filePath6 = ":/new/AirQulity/AirQulity/PM10.png";//图标位置自行调整
    QIcon icon6 = QIcon(filePath6);
    QPixmap m_pic6 = icon6.pixmap(icon6.actualSize(QSize(50, 50)));//size自行调整
    ui->PM10P->setPixmap(m_pic6);
}
