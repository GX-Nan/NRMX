#include "frmmain.h"
#include "ui_frmmain.h"
#include "quiwidget.h"
#include<QThread>



frmMain::frmMain(QWidget *parent) : QWidget(parent,Qt::WindowTitleHint | Qt::CustomizeWindowHint), ui(new Ui::frmMain)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::Tool);
    InterfaceUpdate();
    Shadow();
    TcpTaskInit();
    initConfig();
    IPForm();
    emit ServerListen();//开监听
    qDebug()<<"主界面线程ID"<<QThread::currentThread();
}

frmMain::~frmMain()
{
    delete ui;
    delete shade ;
    delete WindUi;
    delete DoorUi;
    delete CurtainUi;
    delete AirUi;
    delete LightUi;
    delete WindowUi;
}

void frmMain::InterfaceUpdate()
{
    //动画----伸缩
    QPropertyAnimation *pScaleAnimation1 = new QPropertyAnimation(ui->Pm25GroupBox, "geometry");//
    pScaleAnimation1->setDuration(800);//设置时间
    pScaleAnimation1->setStartValue(QRect(950, 30, 111, 451));//设置开始大小
    pScaleAnimation1->setEndValue(QRect(950, 120, 111, 451));//设置结束大小
    pScaleAnimation1->setEasingCurve(QEasingCurve::OutQuad);

    QPropertyAnimation *pScaleAnimation2 = new QPropertyAnimation(ui->TempGroupBox, "geometry");//
    pScaleAnimation2->setDuration(800);//设置时间
    pScaleAnimation2->setStartValue(QRect(1200, 800, 111, 451));//设置开始大小
    pScaleAnimation2->setEndValue(QRect(1200, 420, 111, 451));//设置结束大小
    pScaleAnimation2->setEasingCurve(QEasingCurve::OutQuad);

    QPropertyAnimation *pScaleAnimation3 = new QPropertyAnimation(ui->HumidityGroupBox, "geometry");//
    pScaleAnimation3->setDuration(800);//设置时间
    pScaleAnimation3->setStartValue(QRect(1460, 40, 111, 451));//设置开始大小
    pScaleAnimation3->setEndValue(QRect(1460, 180, 111, 451));//设置结束大小
    pScaleAnimation3->setEasingCurve(QEasingCurve::OutQuad);

    QPropertyAnimation *pScaleAnimation4 = new QPropertyAnimation(ui->LuxGroupBox, "geometry");//
    pScaleAnimation4->setDuration(800);//设置时间
    pScaleAnimation4->setStartValue(QRect(1710, 800, 111, 451));//设置开始大小
    pScaleAnimation4->setEndValue(QRect(1710, 390, 111, 451));//设置结束大小
    pScaleAnimation4->setEasingCurve(QEasingCurve::OutQuad);


    QParallelAnimationGroup * m_group = new QParallelAnimationGroup(this);
    // m_group->addAnimation(pButtonOpacity1);
    m_group->addAnimation(pScaleAnimation1);
    m_group->addAnimation(pScaleAnimation2);
    m_group->addAnimation(pScaleAnimation3);
    m_group->addAnimation(pScaleAnimation4);
    m_group->start();


    //QRectF rectangle1(10.0, 100.0, 80.0, 80.0);
    //----贴图--温度
    QString filePath = ":/new/Window/Window/Temp.png";//图标位置自行调整
    QIcon icon = QIcon(filePath);
    QPixmap TempP = icon.pixmap(icon.actualSize(QSize(80, 80)));//size自行调整
    ui->TempP->setPixmap(TempP);
    //----贴图--湿度
    QString HumiPath = ":/new/Window/Window/Humi.png";//图标位置自行调整
    QIcon Humi = QIcon(HumiPath);
    QPixmap HumiP = Humi.pixmap(icon.actualSize(QSize(80, 80)));//size自行调整
    ui->HumiP->setPixmap(HumiP);
    //----贴图--光照
    QString LuxPath = ":/new/Led/Led/Brightness.png";//图标位置自行调整
    QIcon Lux = QIcon(LuxPath);
    QPixmap LuxP = Lux.pixmap(icon.actualSize(QSize(80, 80)));//size自行调整
    ui->LuxP->setPixmap(LuxP);
    //----贴图--Pm2.5
    QString Pm25Path = ":/new/AirQulity/AirQulity/pm2.5.png";//图标位置自行调整
    QIcon Pm25 = QIcon(Pm25Path);
    QPixmap Pm25P = Pm25.pixmap(icon.actualSize(QSize(80, 80)));//size自行调整
    ui->Pm25P->setPixmap(Pm25P);

}

void frmMain::paintEvent(QPaintEvent *)
{

}



void frmMain::Shadow()
{

    //阴影绘制
    QGraphicsDropShadowEffect *SystemOptimization = new QGraphicsDropShadowEffect(this);
    SystemOptimization->setOffset(8);
    SystemOptimization->setColor(/*Qt::gray*/QColor(43, 43, 43));
    SystemOptimization->setBlurRadius(25);
    ui->SystemOptimization->setGraphicsEffect(SystemOptimization);//优化按钮

    QGraphicsDropShadowEffect *HouseIntelligence = new QGraphicsDropShadowEffect(this);
    HouseIntelligence->setOffset(8);
    HouseIntelligence->setColor(/*Qt::gray*/QColor(43, 43, 43));
    HouseIntelligence->setBlurRadius(25);
    ui->HouseIntelligence->setGraphicsEffect(HouseIntelligence);//智能按钮

    QGraphicsDropShadowEffect *Pm25GroupBox = new QGraphicsDropShadowEffect(this);
    Pm25GroupBox->setOffset(8);
    Pm25GroupBox->setColor(/*Qt::gray*/QColor(43, 43, 43));
    Pm25GroupBox->setBlurRadius(25);
    ui->Pm25GroupBox->setGraphicsEffect(Pm25GroupBox);

    QGraphicsDropShadowEffect *TempGroupBox = new QGraphicsDropShadowEffect(this);
    TempGroupBox->setOffset(8);
    TempGroupBox->setColor(/*Qt::gray*/QColor(43, 43, 43));
    TempGroupBox->setBlurRadius(25);
    ui->TempGroupBox->setGraphicsEffect(TempGroupBox);

    QGraphicsDropShadowEffect *HumidityGroupBox = new QGraphicsDropShadowEffect(this);
    HumidityGroupBox->setOffset(8);
    HumidityGroupBox->setColor(/*Qt::gray*/QColor(43, 43, 43));
    HumidityGroupBox->setBlurRadius(25);
    ui->HumidityGroupBox->setGraphicsEffect(HumidityGroupBox);


    QGraphicsDropShadowEffect *LuxGroupBox = new QGraphicsDropShadowEffect(this);
    LuxGroupBox->setOffset(8);
    LuxGroupBox->setColor(/*Qt::gray*/QColor(43, 43, 43));
    LuxGroupBox->setBlurRadius(25);
    ui->LuxGroupBox->setGraphicsEffect(LuxGroupBox);

    QGraphicsDropShadowEffect *SystemScore = new QGraphicsDropShadowEffect(this);
    SystemScore->setOffset(8);
    SystemScore->setColor(/*Qt::gray*/QColor(43, 43, 43));
    SystemScore->setBlurRadius(25);
    ui->SystemScore->setGraphicsEffect(SystemScore);

    QGraphicsDropShadowEffect *SystemScore_ControlPage = new QGraphicsDropShadowEffect(this);
    SystemScore_ControlPage->setOffset(8);
    SystemScore_ControlPage->setColor(/*Qt::gray*/QColor(43, 43, 43));
    SystemScore_ControlPage->setBlurRadius(25);
    ui->group->setGraphicsEffect(SystemScore_ControlPage);

    QGraphicsDropShadowEffect *ButtonBox = new QGraphicsDropShadowEffect(this);
    ButtonBox->setOffset(8);
    ButtonBox->setColor(/*Qt::gray*/QColor(43, 43, 43));
    ButtonBox->setBlurRadius(25);
    ui->ButtonBox->setGraphicsEffect(ButtonBox);

    QGraphicsDropShadowEffect *WhiteGroupBox = new QGraphicsDropShadowEffect(this);
    WhiteGroupBox->setOffset(8);
    WhiteGroupBox->setColor(/*Qt::gray*/QColor(43, 43, 43));
    WhiteGroupBox->setBlurRadius(25);
    ui->WhiteGroupBox->setGraphicsEffect(WhiteGroupBox);


    QGraphicsDropShadowEffect *WhiteGroupBox2 = new QGraphicsDropShadowEffect(this);
    WhiteGroupBox2->setOffset(8);
    WhiteGroupBox2->setColor(/*Qt::gray*/QColor(43, 43, 43));
    WhiteGroupBox2->setBlurRadius(25);
    ui->WhiteGroupBox2->setGraphicsEffect(WhiteGroupBox2);

    QGraphicsDropShadowEffect *WhiteGroupBox3 = new QGraphicsDropShadowEffect(this);
    WhiteGroupBox3->setOffset(8);
    WhiteGroupBox3->setColor(/*Qt::gray*/QColor(43, 43, 43));
    WhiteGroupBox3->setBlurRadius(25);
    ui->WhiteGroupBox3->setGraphicsEffect(WhiteGroupBox3);

    QGraphicsDropShadowEffect *WhiteGroupBox4 = new QGraphicsDropShadowEffect(this);
    WhiteGroupBox4->setOffset(8);
    WhiteGroupBox4->setColor(/*Qt::gray*/QColor(43, 43, 43));
    WhiteGroupBox4->setBlurRadius(25);
    ui->WhiteGroupBox4->setGraphicsEffect(WhiteGroupBox4);
}

bool frmMain::eventFilter(QObject *obj, QEvent *event)
{

    if(obj==ui->Pm25GroupBox||obj==ui->HumidityGroupBox||obj==ui->LuxGroupBox||obj==ui->TempGroupBox)
    {
        if(event->type()==QEvent::MouseButtonPress)//监视鼠标按下的动作
        {
            QMouseEvent*mouseEvent=static_cast<QMouseEvent*>(event);
            if(mouseEvent->button()==Qt::RightButton)
            {
                ui->Bottom->setCurrentIndex(1);
                qDebug()<<"innn----1";
                //event->accept();//接受这个事件？？？---不懂
            }
            //            else if(mouseEvent->button()==Qt::LeftButton)
            //            {
            //                ui->Bottom->setCurrentIndex(1);
            //            }
        }
        else {
            return QObject::eventFilter(obj,event);
        }
    }
   else if(obj==ui->Main && event->type()==QEvent::Paint)
    {
       MainBackground();
       qDebug()<<"innn----2";
    }
}

void frmMain::ControlPage()
{

}

void frmMain::TcpTaskInit()
{
    TaskTcpServer=new frmTcpServer();
    qRegisterMetaType<QMultiMap<int,QString>>("QMultiMap<int,QString>");//容器初始化
    //    connect(TaskTcpServer,&frmTcpServer::ClientIpGroup,this,[=]( const QString &ClientIP)//显示有多少客户端连接
    //    {
    //        ui->listWidget->addItem(ClientIP);
    //        ui->labCount->setText(QString("共 %1 个客户端").arg(ui->listWidget->count()));
    //    });

    connect(this,&frmMain::ServerListen,TaskTcpServer,&frmTcpServer::Listen);
    connect(this,&frmMain::ServerClose,TaskTcpServer,&frmTcpServer::ListenClose);
    connect(TaskTcpServer,&frmTcpServer::TextAppend,this,[=](QString Data)
    {
        qDebug()<<"Rece Msg:"<<Data;
    });
    //    connect(TaskTcpServer,&frmTcpServer::TextAppend,this,[=](QString Msg)
    //    {
    //        qDebug()<<"Rece Msg:"<<Msg;
    //    });
    connect(TaskTcpServer,&frmTcpServer::Return_Data,this,[=](QMultiMap<int,QString>Data)
    {
        qDebug()<<Data;
    });

    QThread *Task1=new QThread();
    TaskTcpServer->moveToThread(Task1);
    Task1->start();
}

void frmMain::IPForm()
{
    QStringList ips;
    QList<QNetworkInterface> netInterfaces = QNetworkInterface::allInterfaces();
    foreach(const QNetworkInterface  &netInterface, netInterfaces) {
        //移除虚拟机和抓包工具的虚拟网卡
        QString humanReadableName = netInterface.humanReadableName().toLower();
        if(humanReadableName.startsWith("vmware network adapter") || humanReadableName.startsWith("npcap loopback adapter")) {
            continue;
        }

        //过滤当前网络接口
        bool flag = (netInterface.flags() == (QNetworkInterface::IsUp | QNetworkInterface::IsRunning | QNetworkInterface::CanBroadcast | QNetworkInterface::CanMulticast));
        if(flag) {
            QList<QNetworkAddressEntry> addrs = netInterface.addressEntries();
            foreach(QNetworkAddressEntry addr, addrs) {
                //只取出IPV4的地址
                if(addr.ip().protocol() == QAbstractSocket::IPv4Protocol) {
                    QString ip4 = addr.ip().toString();
                    if(ip4 != "127.0.0.1") {
                        ips.append(ip4);
                    }
                }
            }
        }
    }
    qDebug()<<"Ip list:"<<ips[0];
    App::TcpListenIP=ips[0];
    App::TcpListenPort=6000;
}



void frmMain::MainBackground()
{
    QPainter painter(ui->Main);
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setBrush(QColor(41,43,74));//
    painter.setPen(Qt::NoPen);//设置no pen
    painter.drawEllipse(-120,-400,700,700);

    painter.setBrush(QColor(255,192,0));//
    painter.drawEllipse(1400,-300,800,800);

    painter.setBrush(QColor(210,21,21));//
    painter.drawEllipse(1100,600,900,900);
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
    //----加事件监视器
    ui->Main->installEventFilter(this);
    ui->Pm25GroupBox->installEventFilter(this);
    ui->HumidityGroupBox->installEventFilter(this);
    ui->TempGroupBox->installEventFilter(this);
    ui->LuxGroupBox->installEventFilter(this);
    //ui->Bottom->installEventFilter(this);
    // ui->ControlPage->installEventFilter(this);
    //---------实例化
    shade = new QWidget(this);
    WindUi= new WindSystem(this);
    DoorUi= new DoorSystem(this);
    CurtainUi=new CurtainSystem(this);
    AirUi=new AirSystem(this);
    LightUi=new LightSystem(this);
    WindowUi=new WindowSystem(this);
    //----------
    Analysis_air=new Analysis_Air (this);
    Analysis_wind=new Analysis_Wind(this);
    Analysis_light=new Analysis_Light(this);
    Analysis_window=new Analysis_Window(this);
    Analysis_cutarin=new Analysis_Cutarin(this);
    //-----------wx
    WxMsg=new WxReceive();
    WxSd=new WxSend();
    //---添加幕布
    QPalette palette = shade->palette();
    palette.setColor(QPalette::Window,QColor(125,125,125,150));
    shade->setAutoFillBackground(true);
    shade->setPalette(palette);
    shade->hide();
    shade->raise();
    //-------添加关闭子窗口的信号
    connect(WindUi,&WindSystem::SendClose,this,[=]{
        shade->hide();
    });
    connect(DoorUi,&DoorSystem::SendClose,this,[=]{
        shade->hide();
    });
    connect(CurtainUi,&CurtainSystem::SendClose,this,[=]{
        shade->hide();
    });
    connect(AirUi,&AirSystem::SendClose,this,[=]{
        shade->hide();
    });
    connect(LightUi,&LightSystem::SendClose,this,[=]{
        shade->hide();
    });
    connect(WindowUi,&WindowSystem::SendClose,this,[=]{
        shade->hide();
    });
    //---数据触发---Air:
    connect(TaskTcpServer,&frmTcpServer::Server_Receive_Data,Analysis_air,&Analysis_Air::Receive_Data);//Tcp链接数据分析
    connect(Analysis_air,&Analysis_Air::Air_UiValue,AirUi,&AirSystem::ReceiveData);//数据分析链接分控
    connect(AirUi,&AirSystem::RadioBroadcast,TaskTcpServer,&frmTcpServer::RadioBroadcast);
//    connect(AirUi,&AirSystem::Class_Update,Analysis_air,&Analysis_Air::Data_Update);
    //---Wind
    connect(TaskTcpServer,&frmTcpServer::Server_Receive_Data,Analysis_wind,&Analysis_Wind::Receive_Data);//Tcp链接数据分析
    connect(Analysis_wind,&Analysis_Wind::Wind_UiData,WindUi,&WindSystem::ReceiveData);//数据分析链接分控
    connect(WindUi,&WindSystem::RadioBroadcast,TaskTcpServer,&frmTcpServer::RadioBroadcast);
    connect(WindUi,&WindSystem::Class_Update,Analysis_wind,&Analysis_Wind::Data_Update);
    connect(TaskTcpServer,&frmTcpServer::Esp_Data,Analysis_wind,&Analysis_Wind::Handle_Data_AirQuality);
    connect(Analysis_wind,&Analysis_Wind::AirQuality_Data,WindUi,&WindSystem::Xprogress_Update);
    //----Led
    connect(TaskTcpServer,&frmTcpServer::Server_Receive_Data,Analysis_light,&Analysis_Light::Receive_Data);//Tcp链接数据分析
    connect(LightUi,&LightSystem::RadioBroadcast,TaskTcpServer,&frmTcpServer::RadioBroadcast);
    connect(Analysis_light,&Analysis_Light::StatusSignals,LightUi,&LightSystem::Light_Status);
    //----Window-------------
    connect(TaskTcpServer,&frmTcpServer::Server_Receive_Data,Analysis_window,&Analysis_Window::Receive_Data);//Tcp链接数据分析
    connect(WindowUi,&WindowSystem::RadioBroadcast,TaskTcpServer,&frmTcpServer::RadioBroadcast);
    connect(Analysis_window,&Analysis_Window::AirQuality_Data,WindowUi,&WindowSystem::AirQuality_Status);
    connect(Analysis_window,&Analysis_Window::Window_Data,WindowUi,&WindowSystem::Window_Status);
    //--Curtain----
    connect(TaskTcpServer,&frmTcpServer::Server_Receive_Data,Analysis_cutarin,&Analysis_Cutarin::Receive_Data);//Tcp链接数据分析
    connect(CurtainUi,&CurtainSystem::RadioBroadcast,TaskTcpServer,&frmTcpServer::RadioBroadcast);
    connect(TaskTcpServer,&frmTcpServer::Esp_Data,Analysis_cutarin,&Analysis_Cutarin::Handle_Data_Esp);
    connect(Analysis_cutarin,&Analysis_Cutarin::BrightnessSignals,CurtainUi,&CurtainSystem::BrightnessShow);
    connect(Analysis_cutarin,&Analysis_Cutarin::StatusSignals,CurtainUi,&CurtainSystem::Ui_Update);
    //----WxReceive---
    QThread *WxReTask =new QThread();
    connect(this,&frmMain::OneNetStart,WxMsg,&WxReceive::KeepCrawl);
    WxMsg->moveToThread(WxReTask);
    WxReTask->start();
    connect(WxMsg,&WxReceive::Light_Status,LightUi,&LightSystem::Light_Status);
    //---
    connect(WxMsg,&WxReceive::Air_Status,Analysis_air,&Analysis_Air::Air_Decode);
    //------
    connect(WxMsg,&WxReceive::Curtain_Status,CurtainUi,&CurtainSystem::Ui_Update);
    //-----
    connect(WxMsg,&WxReceive::Window_Status,WindowUi,&WindowSystem::Window_Status);
    //----
    connect(WxMsg,&WxReceive::Wind_Status,Analysis_wind,&Analysis_Wind::Wind_Decode);
    //-----WxSend-----
    QThread *WxSeTask =new QThread();
    connect(this,&frmMain::SendToOneNet,WxSd,&WxSend::SendData);
    WxSd->moveToThread(WxSeTask);
    WxSeTask->start();
    //----------------------
    emit OneNetStart();//开启抓取从微信传过来的数据
    //------与子界面发射
    connect(AirUi,&AirSystem::SendToWx,WxSd,&WxSend::SendData);
    connect(CurtainUi,&CurtainSystem::SendToWx,WxSd,&WxSend::SendData);
    connect(LightUi,&LightSystem::SendToWx,WxSd,&WxSend::SendData);
    connect(WindUi,&WindSystem::SendToWx,WxSd,&WxSend::SendData);
    connect(WindowUi,&WindowSystem::SendToWx,WxSd,&WxSend::SendData);
    //-------

//    Crawler=new WeatherCrawler();
//    qDebug()<<"1-------------";
//    //-----爬虫传送
//    QThread *CrawlTask= new QThread();
//    Crawler->moveToThread(CrawlTask);
//    connect(this,&frmMain::StartCrawl,Crawler,&WeatherCrawler::TimeCatch);
//    connect(Crawler,&WeatherCrawler::SendMessage,this,[=](const CrawlMessage* test)
//    {
//        qDebug()<<"test";
//        qDebug()<<test->Activity;
//    });
//    CrawlTask->start();
//    emit StartCrawl();


//    qDebug()<<"2-------------";

//    qDebug()<<"3-------------";
//    QThread *CrawlerTask=new QThread();
//    Crawler->moveToThread(CrawlerTask);;
//    CrawlerTask->start();

//    connect(Crawler,&WeatherCrawler::AirMes,this,[=]
//    {
//        qDebug()<<"innnn---crawlAir";
//    });
//    connect(Crawler,&WeatherCrawler::WeatherMes,WindowUi,&WindowSystem::CrawlWeather);
//    connect(Crawler,&WeatherCrawler::ActivityMes,WindowUi,&WindowSystem::CrawlActive);

    //------------------
    connect(this,&frmMain::Show_SubUi,WindUi,&WindSystem::ShowSubUi);

}

void frmMain::on_UISreachIP_clicked()//用于分控的主动找主控的--现在不怎么需要所以就先毙掉
{

//    UiIPSreach *uiipsreach=new UiIPSreach(this);//设置父类为主窗口 ---当主窗口析构的时候子界面也会析构
//    uiipsreach->setModal(true);//设置为半模式窗口
//    uiipsreach->setAttribute(Qt::WA_DeleteOnClose);//设置子窗口属性，在子窗口关闭之后，释放子窗口的资源(释放指针).
//    uiipsreach->show();
}


void frmMain::on_Server_clicked()//写的服务器启动界面--可以不使用
{
//    uiTcpServer*uitcpserver=new uiTcpServer(this);
//    uitcpserver->setAttribute(Qt::WA_DeleteOnClose);//设置子窗口属性，在子窗口关闭之后，释放子窗口的资源(释放指针).
//    uitcpserver->show();
}

void frmMain::on_GoMain_clicked()
{
    if(ui->Bottom->currentIndex()!=0){
        ui->Bottom->setCurrentIndex(0);
        InterfaceUpdate();
    }
}

void frmMain::on_GoControlPage_clicked()
{
    if(ui->Bottom->currentIndex()!=1){
        ui->Bottom->setCurrentIndex(1);
    }
}

void frmMain::on_CurtainSystem_clicked()
{
    if(shade->isHidden())
    {
        shade->setGeometry(0,0,this->width(),ui->Bottom->y()+ui->Bottom->height());
        shade->show();
        CurtainUi->show();
    }
    else{
        shade->hide();
    }
}

void frmMain::on_DoorSystem_clicked()
{
    if(shade->isHidden())
    {
        shade->setGeometry(0,0,this->width(),ui->Bottom->y()+ui->Bottom->height());
        shade->show();
        DoorUi->show();
    }
    else{
        shade->hide();
    }
}

void frmMain::on_WindSystem_clicked()
{
    if(shade->isHidden())
    {
        shade->setGeometry(0,0,this->width(),ui->Bottom->y()+ui->Bottom->height());
        shade->show();
        WindUi->show();
        emit Show_SubUi();
    }
    else{
        shade->hide();
    }
}

void frmMain::on_LightSystem_clicked()
{
    if(shade->isHidden())
    {
        shade->setGeometry(0,0,this->width(),ui->Bottom->y()+ui->Bottom->height());
        shade->show();
        LightUi->show();
    }
    else{
        shade->hide();
    }
}

void frmMain::on_AirSystem_clicked()
{
    if(shade->isHidden())
    {
        shade->setGeometry(0,0,this->width(),ui->Bottom->y()+ui->Bottom->height());
        shade->show();
        AirUi->show();
    }
    else{
        shade->hide();
    }
}

void frmMain::on_WindowSystem_clicked()
{
    if(shade->isHidden())
    {
        shade->setGeometry(0,0,this->width(),ui->Bottom->y()+ui->Bottom->height());
        shade->show();
        WindowUi->show();
        WindowUi->move(400,150);
        emit Show_Window_SubUi();
    }
    else{
        shade->hide();
    }
}
