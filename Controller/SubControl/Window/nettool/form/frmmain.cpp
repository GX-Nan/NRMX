#include "frmmain.h"
#include "ui_frmmain.h"
#include "quiwidget.h"
#include<QThread>



frmMain::frmMain(QWidget *parent) : QWidget(parent,Qt::WindowTitleHint | Qt::CustomizeWindowHint), ui(new Ui::frmMain)
{
    ui->setupUi(this);
    initConfig();
    ClientConfig();
    qDebug()<<"main线程ID"<<QThread::currentThread();
    ShadowInit();
    ProgressInit();
    BackdropInit();
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


void frmMain::saveConfig()
{

}

void frmMain::initConfig()//配置
{
    frmTcpClient *client=new frmTcpClient();//不允许有父对象 不然无法放入子线程内执行
    //    connect(this,&UiIPSreach::clientConnect,client,&frmTcpClient::ClientRecv);//接受
    connect(this,&frmMain::ClientConnect,client,&frmTcpClient::ClientConnect);//连接
    QThread *Task1=new QThread();
    client->moveToThread(Task1);
    Task1->start();//启动子线程
}

void frmMain::on_UISreachIP_clicked()
{

}

void frmMain::ClientConfig()
{
    frmTcpClient *client=new frmTcpClient();//不允许有父对象 不然无法放入子线程内执行

    QString ipstring="192.168.31.93";//获取text内的地址

    int portInt=6002;//获取目标服务器的端口号

    App::TcpListenIP=ipstring;

    App::TcpListenPort=portInt;//不用指针---指针的作用是修改内存内的数值 --指针本身又要增加内存空间的分配--增加错误的几率

    emit ClientConnect();

    QThread *Task1=new QThread();
    client->moveToThread(Task1);
    Task1->start();//启动子线程
}

void frmMain::ShadowInit()
{
    QGraphicsDropShadowEffect *TempAndHumi = new QGraphicsDropShadowEffect(this);
    TempAndHumi->setOffset(8);
    TempAndHumi->setColor(/*Qt::gray*/QColor(43, 43, 43));
    TempAndHumi->setBlurRadius(25);
    ui->TempAndHumi->setGraphicsEffect(TempAndHumi);//优化按钮

    QGraphicsDropShadowEffect *WindowPage = new QGraphicsDropShadowEffect(this);
    WindowPage->setOffset(5);
    WindowPage->setColor(/*Qt::gray*/QColor(43, 43, 43));
    WindowPage->setBlurRadius(25);
    ui->WindowPage->setGraphicsEffect(WindowPage);//优化按钮

    QGraphicsDropShadowEffect *CurtainsPage = new QGraphicsDropShadowEffect(this);
    CurtainsPage->setOffset(5);
    CurtainsPage->setColor(/*Qt::gray*/QColor(43, 43, 43));
    CurtainsPage->setBlurRadius(25);
    ui->CurtainsPage->setGraphicsEffect(CurtainsPage);//优化按钮

    QGraphicsDropShadowEffect *WeatherPage = new QGraphicsDropShadowEffect(this);
    WeatherPage->setOffset(8);
    WeatherPage->setColor(/*Qt::gray*/QColor(43, 43, 43));
    WeatherPage->setBlurRadius(25);
    ui->WeatherPage->setGraphicsEffect(WeatherPage);//优化按钮

    QGraphicsDropShadowEffect *CurtainsBox = new QGraphicsDropShadowEffect(this);
    CurtainsBox->setOffset(4);
    CurtainsBox->setColor(/*Qt::gray*/QColor(43, 43, 43));
    CurtainsBox->setBlurRadius(25);
    ui->CurtainsBox->setGraphicsEffect(CurtainsBox);//优化按钮

    QGraphicsDropShadowEffect *WindowBox = new QGraphicsDropShadowEffect(this);
    WindowBox->setOffset(8);
    WindowBox->setColor(/*Qt::gray*/QColor(43, 43, 43));
    WindowBox->setBlurRadius(25);
    ui->WindowBox->setGraphicsEffect(WindowBox);//优化按钮

    QGraphicsDropShadowEffect *frame_2 = new QGraphicsDropShadowEffect(this);
    frame_2->setOffset(4);
    frame_2->setColor(/*Qt::gray*/QColor(43, 43, 43));
    frame_2->setBlurRadius(25);
    ui->frame_2->setGraphicsEffect(frame_2);//优化按钮

//    QGraphicsDropShadowEffect *frame = new QGraphicsDropShadowEffect(this);
//    frame->setOffset(4);
//    frame->setColor(/*Qt::gray*/QColor(43, 43, 43));
//    frame->setBlurRadius(25);
//    ui->frame->setGraphicsEffect(frame);//优化按钮

    //    QGraphicsDropShadowEffect *AirQualityBox = new QGraphicsDropShadowEffect(this);
    //    AirQualityBox->setOffset(4);
    //    AirQualityBox->setColor(/*Qt::gray*/QColor(43, 43, 43));
    //    AirQualityBox->setBlurRadius(25);
    //    ui->AirQualityBox->setGraphicsEffect(AirQualityBox);//优化按钮

    QGraphicsDropShadowEffect *OutAirQuality = new QGraphicsDropShadowEffect(this);
    OutAirQuality->setOffset(4);
    OutAirQuality->setColor(/*Qt::gray*/QColor(43, 43, 43));
    OutAirQuality->setBlurRadius(25);
    ui->OutAirQuality->setGraphicsEffect(OutAirQuality);//优化按钮

    QGraphicsDropShadowEffect *SuitableBox = new QGraphicsDropShadowEffect(this);
    SuitableBox->setOffset(4);
    SuitableBox->setColor(/*Qt::gray*/QColor(43, 43, 43));
    SuitableBox->setBlurRadius(25);
    ui->SuitableBox->setGraphicsEffect(SuitableBox);//优化按钮 SuitableBox
    //}
}



void frmMain::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setBrush(QColor(41,43,74));//
    painter.setPen(Qt::NoPen);//设置no pen
    painter.drawEllipse(-100,-400,700,700);

    painter.setBrush(QColor(255,192,0));//
    painter.drawEllipse(1400,-300,800,800);

    painter.setBrush(QColor(210,21,21));//
    painter.drawEllipse(1100,600,900,900);
}

void frmMain::ProgressInit()
{
    QList<QProgressBar*> progress;
    progress<<ui->After_1<<ui->After_2<<ui->After_3<<ui->After_4<<ui->After_5<<ui->After_6<<ui->After_7<<ui->After_8<<ui->After_9<<ui->After_10<<ui->After_11;
    for(int i=0;i<11;i++)
    {
        progress[i]->setOrientation(Qt::Vertical);
        progress[i]->setValue(40);
        progress[i]->setTextVisible(false);
    }
}



void frmMain::on_WindowBox_clicked()
{
    shade->setGeometry(0,0,this->width(),this->height());
    shade->show();
}

void frmMain::on_CurtainsBox_clicked()
{

}

void frmMain::BackdropInit()
{
    shade = new QWidget(this);
    QPalette palette = shade->palette();
    palette.setColor(QPalette::Window,QColor(125,125,125,150));
    shade->setAutoFillBackground(true);
    shade->setPalette(palette);
    shade->hide();
    shade->raise();
}
