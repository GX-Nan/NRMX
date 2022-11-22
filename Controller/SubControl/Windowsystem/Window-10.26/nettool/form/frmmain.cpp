#include "frmmain.h"
#include "ui_frmmain.h"
#include "quiwidget.h"
#include<QThread>



frmMain::frmMain(QWidget *parent) : QWidget(parent,Qt::WindowTitleHint | Qt::CustomizeWindowHint), ui(new Ui::frmMain)
{
    ui->setupUi(this);
    qDebug()<<"main线程ID"<<QThread::currentThread();
    ShadowInit();
    ProgressInit();
    BackdropInit();
    ClientConfig();
    ui->Bottom->installEventFilter(this);

    QString filePath = ":/Suitable/Clothes.png";//图标位置自行调整
    QIcon icon = QIcon(filePath);
    QPixmap Suit1 = icon.pixmap(icon.actualSize(QSize(ui->Suitable1->width(), ui->Suitable1->width())));//size自行调整
    ui->Suitable1->setPixmap(Suit1);

    QString filePath2 = ":/Suitable/Sport.png";//图标位置自行调整
    QIcon icon2 = QIcon(filePath2);
    QPixmap Suit2 = icon2.pixmap(icon2.actualSize(QSize(ui->Suitable1->width(), ui->Suitable1->width())));//size自行调整
    ui->Suitable2->setPixmap(Suit2);

    QString filePath3 = ":/Suitable/home.png";//图标位置自行调整
    QIcon icon3 = QIcon(filePath3);
    QPixmap Suit3 = icon3.pixmap(icon3.actualSize(QSize(ui->Suitable1->width(), ui->Suitable1->width())));//size自行调整
    ui->Suitable3->setPixmap(Suit3);

    QString filePath4 = ":/Suitable/Temp.png";//图标位置自行调整
    QIcon icon4= QIcon(filePath4);
    QPixmap Suit4 = icon4.pixmap(icon4.actualSize(QSize(ui->TempP->width(), ui->TempP->width())));//size自行调整
    ui->TempP->setPixmap(Suit4);

    QString filePath5 = ":/Suitable/Hum.png";//图标位置自行调整
    QIcon icon5 = QIcon(filePath5);
    QPixmap Suit5 = icon5.pixmap(icon5.actualSize(QSize(ui->HumP->width(), ui->HumP->width())));//size自行调整
    ui->HumP->setPixmap(Suit5);
}

frmMain::~frmMain()
{
    delete ui;
}

bool frmMain::eventFilter(QObject *obj, QEvent *event)
{
    if(obj == ui->Bottom && event->type() == QEvent::Paint)
    {
        BackgroundInit();
        return true;
    }
}


void frmMain::on_tabWidget_currentChanged(int index)
{
    App::CurrentIndex = index;
    App::writeConfig();
}


void frmMain::ClientConfig()
{
    client=new frmTcpClient();//不允许有父对象 不然无法放入子线程内执行
    connect(this,&frmMain::ClientConnect,client,&frmTcpClient::ClientConnect);//连接
    connect(this,&frmMain::EndSignals,client,&frmTcpClient::RecoverSignals);

    //-----------------------窗帘
    connect(Curtains,&CurtainsBox::RadioBroadcast,client,&frmTcpClient::RadioBroadcast);//子界面广播
    connect(client,&frmTcpClient::Updata_Curtain,Curtains,&CurtainsBox::ReceiveData);//更新界面
    connect(Curtains,&CurtainsBox::EndSignals,client,&frmTcpClient::RecoverSignals);
    //---
    connect(this,&frmMain::RadioBroadcast,client,&frmTcpClient::RadioBroadcast);
    connect(this,&frmMain::Curtains_Sync,Curtains,&CurtainsBox::Curtains_Sync);
    connect(Curtains,&CurtainsBox::Curtains_Sub,this,[=](int Order)
    {
        StopReturn=1;
        switch(Order)
        {
        case 0:
            ui->AllCurtains_Up->click();
            break;
        case 1:
            ui->AllCurtains_Down->click();
            break;
        case 4:
            ui->AllCurtains_Stop->click();
            break;
        }
        StopReturn=0;
    });
    //-----------------------窗户
    connect(Windows,&WindowBox::RadioBroadcast,client,&frmTcpClient::RadioBroadcast);
    connect(Windows,&WindowBox::EndSignals,client,&frmTcpClient::RecoverSignals);
    connect(Windows,&WindowBox::StartSignals,client,&frmTcpClient::StopSignals);
    connect(client,&frmTcpClient::Updata_Window,Windows,&WindowBox::ReceiveData);//更新界面
    connect(this,&frmMain::Window_Sync,Windows,&WindowBox::Windows_Sync);
    connect(Windows,&WindowBox::Windows_Sub,this,[=](int Order)
    {
        StopReturn=1;
        switch(Order)
        {
        case 1:
            ui->AllWindow_Open->click();
            break;
        case 2:
            ui->AllWindow_Close->click();
            break;
        case 3:
            ui->AllWindow_Stop->click();
            break;
        }
        StopReturn=0;
    });
    //-----------------------------------
    Weather=new WeatherCrawler();
    connect(this,&frmMain::StartCrawl,Weather,&WeatherCrawler::TimeCatch);
    connect(Weather,&WeatherCrawler::SendMessage,this,[=](const CrawlMessage* data)
    {
        emit EndSignals();
        qDebug()<<"WeatherNow:"<<data->WeatherNow;
        ui->TempLabel->setText(data->WeatherNow.value("Temp"));
        ui->HumLabel->setText(data->WeatherNow.value("Hum"));
        //-----
        emit RadioBroadcast("ZB30101"+data->WeatherNow.value("Temp")+"1");
        emit RadioBroadcast("ZB30102"+data->WeatherNow.value("Hum")+"1");
        //----
        if(data->WeatherNow.value("Weather")=="晴")
        {
            IconSet("晴",ui->CurrentWeatherP);
            emit RadioBroadcast("ZB30110011");
        }
        else if(data->WeatherNow.value("Weather")=="雨")
        {
            IconSet("小雨",ui->CurrentWeatherP);
            emit RadioBroadcast("ZB30110031");
        }
        else if(data->WeatherNow.value("Weather")=="多云"||data->WeatherNow.value("Weather")=="阴天")
        {
            IconSet("多云",ui->CurrentWeatherP);
            emit RadioBroadcast("ZB30110021");
        }
        //---------------------------------
        ui->So2_Xprogress->setValue(data->OutSideAir.value("so2").toInt());
        ui->PM10_Xprogress->setValue(data->OutSideAir.value("Pm10").toInt());
        ui->PM25_Xprogress->setValue(data->OutSideAir.value("Pm25").toInt());
        ui->No2_Xprogress->setValue(data->OutSideAir.value("No2").toInt());
        //---i
        QString So2Mes="ZB30105";
        QString No2Mes="ZB30103";
        QString Pm25Mes="ZB30104";
        QString CoMes="ZB30106";
        QString Pm10Mes="ZB30107";

        if(data->OutSideAir.value("No2").length()==1){
            No2Mes.append("0");
        }
        if(data->OutSideAir.value("Pm25").length()==1){
            Pm25Mes.append("0");
        }
        if(data->OutSideAir.value("so2").length()==1){
            So2Mes.append("0");
        }
        if(data->OutSideAir.value("Pm10").length()==1){
            Pm10Mes.append("0");
        }
        emit RadioBroadcast(No2Mes+data->OutSideAir.value("No2")+"1");
        emit RadioBroadcast(Pm25Mes+data->OutSideAir.value("Pm25")+"1");
        emit RadioBroadcast(So2Mes+data->OutSideAir.value("so2")+"1");
        emit RadioBroadcast(Pm10Mes+data->OutSideAir.value("Pm10")+"1");
        //组合包-----
        QTime current_time =QTime::currentTime();
        int hour = current_time.hour();     //当前的小时
        qDebug()<<"当前时间："<<current_time;
        qDebug()<<"当前钟数："<<hour;
        QList<QProgressBar*> progress;
        progress<<ui->After_1<<ui->After_2<<ui->After_3<<ui->After_4<<ui->After_5<<ui->After_6<<ui->After_7<<ui->After_8<<ui->After_9<<ui->After_10<<ui->After_11;
        QList<QLabel*> progressText;
        progressText<<ui->AfterTemp_1<<ui->AfterTemp_2<<ui->AfterTemp_3<<ui->AfterTemp_4<<ui->AfterTemp_5<<ui->AfterTemp_6<<ui->AfterTemp_7<<ui->AfterTemp_8<<ui->AfterTemp_9<<ui->AfterTemp_10<<ui->AfterTemp_11;
        QList<QLabel*> LabelTime;
        LabelTime<<ui->AfterTime_1<<ui->AfterTime_2<<ui->AfterTime_3<<ui->AfterTime_4<<ui->AfterTime_5<<ui->AfterTime_6<<ui->AfterTime_7<<ui->AfterTime_8<<ui->AfterTime_9<<ui->AfterTime_10<<ui->AfterTime_11;
        QList<QLabel*> LabelImage;
        LabelImage<<ui->AfterP_1<<ui->AfterP_2<<ui->AfterP_3<<ui->AfterP_4<<ui->AfterP_5<<ui->AfterP_6<<ui->AfterP_7<<ui->AfterP_8<<ui->AfterP_9<<ui->AfterP_10<<ui->AfterP_11;
        for(int i=0;i<=10;i++)
        {
            progress[i]->setValue(data->HoulyTemp.value(i).toInt());
            progressText[i]->setText(data->HoulyTemp.value(i)+"°");
            LabelTime[i]->setText(QString::number(hour+i)+":00");
            IconSet(data->HoulyWeather.value(i),LabelImage[i]);
        }
        //----适宜运动
        switch(data->Activity.value("穿衣指数").toInt())
        {
        case 1://适宜
            ui->SuitableClothes->setText("晾衣服:适宜");
            break;
        case 2://较适宜
            ui->SuitableClothes->setText("晾衣服:较适宜");
            break;
        case 3://不适宜
            ui->SuitableClothes->setText("晾衣服:不适宜");
            break;
        }

        switch(data->Activity.value("运动指数").toInt())
        {
        case 1://适宜
            ui->SuitableSport->setText("运动:适宜");
            break;
        case 2://较适宜
            ui->SuitableSport->setText("运动:较适宜");
            break;
        case 3://不适宜
            ui->SuitableSport->setText("运动:不适宜");
            break;
        }

        switch(data->Activity.value("穿衣指数").toInt())
        {
        case 1://适宜
            ui->SuitableHome->setText("居家:舒适");
            break;
        case 2://较适宜
            ui->SuitableHome->setText("居家:适宜");
            break;
        case 3://不适宜
            ui->SuitableHome->setText("居家:舒适");
            break;
        }

        emit RadioBroadcast("ZB301080"+data->Activity.value("穿衣指数")+"1");
        emit RadioBroadcast("ZB301090"+data->Activity.value("运动指数")+"1");
        //----

        ui->AirQualityLevel->setText(QString::number(100-data->OutSideAir.value("AQi").toInt()));
        emit RadioBroadcast("ZB30111"+data->OutSideAir.value("AQi")+"1");
        if(data->OutSideAir.value("AQi").toInt()<50)
        {
            ui->TipsLabel->setText("空气质量令人满意，基本无空气污染");
        }
        else{
            ui->TipsLabel->setText("空气质量可接受，但略带些污染物");
        }
        //------
        qDebug()<<"OutSideAir:"<<data->OutSideAir;
        qDebug()<<"Activity:"<<data->Activity;
        qDebug()<<"HoulyHum:"<<data->HoulyHum;
        qDebug()<<"HoulyTemp:"<<data->HoulyTemp;
        qDebug()<<"HoulyWeather:"<<data->HoulyWeather;
    });
    QThread *CrawlerTask=new QThread();
    Weather->moveToThread(CrawlerTask);
    CrawlerTask->start();
    emit StartCrawl();
    //-------
    QThread *Task1=new QThread();
    client->moveToThread(Task1);
    Task1->start();//启动子线程
    QString ipstring="192.168.31.246";//获取text内的地址
    int portInt=6000;//获取目标服务器的端口号
    App::TcpListenIP=ipstring;
    App::TcpListenPort=portInt;//不用指针---指针的作用是修改内存内的数值 --指针本身又要增加内存空间的分配--增加错误的几率
    emit ClientConnect();
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

    QGraphicsDropShadowEffect *AllWindow_Page = new QGraphicsDropShadowEffect(this);
    AllWindow_Page->setOffset(4);
    AllWindow_Page->setColor(/*Qt::gray*/QColor(43, 43, 43));
    AllWindow_Page->setBlurRadius(25);
    ui->AllWindow_Page->setGraphicsEffect(AllWindow_Page);//优化按钮

    QGraphicsDropShadowEffect *AllCurtains_Page = new QGraphicsDropShadowEffect(this);
    AllCurtains_Page->setOffset(4);
    AllCurtains_Page->setColor(/*Qt::gray*/QColor(43, 43, 43));
    AllCurtains_Page->setBlurRadius(25);
    ui->AllCurtains_Page->setGraphicsEffect(AllCurtains_Page);//优化按钮


    QGraphicsDropShadowEffect *WeatherBox = new QGraphicsDropShadowEffect(this);
    WeatherBox->setOffset(4);
    WeatherBox->setColor(/*Qt::gray*/QColor(43, 43, 43));
    WeatherBox->setBlurRadius(25);
    ui->WeatherBox->setGraphicsEffect(WeatherBox);//优化按钮

    QGraphicsDropShadowEffect *UltravioletBox = new QGraphicsDropShadowEffect(this);
    UltravioletBox->setOffset(4);
    UltravioletBox->setColor(/*Qt::gray*/QColor(43, 43, 43));
    UltravioletBox->setBlurRadius(25);
    ui->UltravioletBox->setGraphicsEffect(UltravioletBox);//优化按钮

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
        progress[i]->setRange(0,45);
    }
}



void frmMain::on_WindowBox_clicked()
{
    Windows->show();
    shade->setGeometry(0,0,this->width(),this->height());
    shade->show();
}

void frmMain::on_CurtainsBox_clicked()
{
    Curtains->show();
    shade->setGeometry(0,0,this->width(),this->height());
    shade->show();
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
    //----------
    Windows=new WindowBox(this);
    Curtains=new CurtainsBox(this);
    connect(Windows,&WindowBox::CloseShawdown,this,[=]
    {
        shade->hide();
    });
    connect(Curtains,&CurtainsBox::CloseShawdown,this,[=]
    {
        shade->hide();
    });
}

void frmMain::BackgroundInit()
{
    QPainter painter(ui->Bottom);
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setBrush(QColor(41,43,74));//
    painter.setPen(Qt::NoPen);//设置no pen
    painter.drawEllipse(-120,-400,700,700);

    painter.setBrush(QColor(255,192,0));//
    painter.drawEllipse(1400,-300,800,800);

    painter.setBrush(QColor(210,21,21));//
    painter.drawEllipse(1100,600,900,900);
}

void frmMain::ButtonStyle_Button(QPushButton *Name, int Offset, int BlurRadius)
{
    QGraphicsDropShadowEffect *ButtonStyle = new QGraphicsDropShadowEffect(this);
    ButtonStyle->setOffset(Offset);
    ButtonStyle->setColor(/*Qt::gray*/QColor(43, 43, 43));
    ButtonStyle->setBlurRadius(BlurRadius);
    Name->setGraphicsEffect(ButtonStyle);
}

void frmMain::on_AllWindow_Open_clicked()
{
    emit EndSignals();
    ButtonStylePlan_Window(1,8,8);
    Window_SetInstruction(1);
    ui->AllWindow_Open->setStyleSheet("background-color: rgb(0, 0, 0);color:white;border-radius:15px;");
    ui->AllWindow_Close->setStyleSheet("background-color: rgb(255, 255, 255);color:black;border-radius:15px;");
    ui->AllWindow_Stop->setStyleSheet("background-color: rgb(255, 255,255 );color:black;border-radius:15px;"); 
}

void frmMain::on_AllWindow_Stop_clicked()
{
    emit EndSignals();
    ButtonStylePlan_Window(8,8,1);
    Window_SetInstruction(3);
    ui->AllWindow_Open->setStyleSheet("background-color: rgb(255, 255, 255);color:black;border-radius:15px;");
    ui->AllWindow_Close->setStyleSheet("background-color: rgb(255, 255, 255);color:black;border-radius:15px;");
    ui->AllWindow_Stop->setStyleSheet("background-color: rgb(0, 0, 0);color:white;border-radius:15px;");
}

void frmMain::on_AllWindow_Close_clicked()
{
    emit EndSignals();
    ButtonStylePlan_Window(8,1,8);
    Window_SetInstruction(2);
    ui->AllWindow_Open->setStyleSheet("background-color: rgb(255, 255, 255);color:black;border-radius:15px;");
    ui->AllWindow_Close->setStyleSheet("background-color: rgb(0, 0, 0);color:white;border-radius:15px;");
    ui->AllWindow_Stop->setStyleSheet("background-color: rgb(255, 255, 255);color:black;border-radius:15px;");
}

void frmMain::ButtonStylePlan_Window(int i, int i2, int i3)
{

    ButtonStyle_Button(ui->AllWindow_Open,i,25);
    ButtonStyle_Button(ui->AllWindow_Close,i2,25);
    ButtonStyle_Button(ui->AllWindow_Stop,i3,25);
}

void frmMain::ButtonStylePlan_Curtains(int i, int i2, int i3)
{

    ButtonStyle_Button(ui->AllCurtains_Up,i,25);
    ButtonStyle_Button(ui->AllCurtains_Down,i2,25);
    ButtonStyle_Button(ui->AllCurtains_Stop,i3,25);
}

void frmMain::on_AllCurtains_Up_clicked()
{
    emit EndSignals();
    ButtonStylePlan_Curtains(1,8,8);
    Curtains_SetInstruction(0);
    ui->AllCurtains_Up->setStyleSheet("background-color: rgb(0, 0, 0);color:white;border-radius:15px;");
    ui->AllCurtains_Down->setStyleSheet("background-color: rgb(255, 255, 255);color:black;border-radius:15px;");
    ui->AllCurtains_Stop->setStyleSheet("background-color: rgb(255, 255, 255);color:black;border-radius:15px;");
}

void frmMain::on_AllCurtains_Stop_clicked()
{
    emit EndSignals();
    ButtonStylePlan_Curtains(8,8,1);
    Curtains_SetInstruction(4);
    ui->AllCurtains_Up->setStyleSheet("background-color: rgb(255, 255, 255);color:black;border-radius:15px;");
    ui->AllCurtains_Down->setStyleSheet("background-color: rgb(255, 255, 255);color:black;border-radius:15px;");
    ui->AllCurtains_Stop->setStyleSheet("background-color: rgb(0, 0, 0);color:white;border-radius:15px;");
}

void frmMain::on_AllCurtains_Down_clicked()
{
    emit EndSignals();
    ButtonStylePlan_Curtains(8,1,8);
    Curtains_SetInstruction(1);
    ui->AllCurtains_Up->setStyleSheet("background-color: rgb(255, 255, 255);color:black;border-radius:15px;");
    ui->AllCurtains_Down->setStyleSheet("background-color: rgb(0, 0, 0);color:white;border-radius:15px;");
    ui->AllCurtains_Stop->setStyleSheet("background-color: rgb(255, 255, 255);color:black;border-radius:15px;");
}

void frmMain::Curtains_SetInstruction(int Order)
{
    if(StopReturn==0){
        emit Curtains_Sync(Order);
    }
}

void frmMain::Window_SetInstruction(int Order)
{
    if(StopReturn==0){
        emit Window_Sync(Order);
    }
}

void frmMain::IconSet(QString Weather,QLabel* Object)
{
    if(Weather=="晴")
    {
        QString filePath = ":/Sun.png";//图标位置自行调整
        QIcon icon = QIcon(filePath);
        QPixmap TempP = icon.pixmap(icon.actualSize(QSize(Object->width(), Object->width())));//size自行调整
        Object->setPixmap(TempP);
    }
    else if(Weather=="小雨"||Weather=="中雨"||Weather=="大雨")
    {
        QString filePath = ":/Rain.png";//图标位置自行调整
        QIcon icon = QIcon(filePath);
        QPixmap TempP = icon.pixmap(icon.actualSize(QSize(Object->width(), Object->width())));//size自行调整
        Object->setPixmap(TempP);
    }
    else if(Weather=="多云")
    {
        QString filePath = ":/Cloudy.png";//图标位置自行调整
        QIcon icon = QIcon(filePath);
        QPixmap TempP = icon.pixmap(icon.actualSize(QSize(Object->width(),Object->width())));//size自行调整
        Object->setPixmap(TempP);
    }
}
