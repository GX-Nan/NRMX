#include "windowsystem.h"
#include "ui_windowsystem.h"
#include<QGraphicsDropShadowEffect>

WindowSystem::WindowSystem(QWidget *parent) :
    QDialog(parent,Qt::WindowTitleHint | Qt::CustomizeWindowHint),
    ui(new Ui::WindowSystem)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint | Qt::CustomizeWindowHint);
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::Tool);
    // this->setAttribute(Qt::WA_TranslucentBackground);

    Shadow();

    connect(ui->Device_Qslider,&QSlider::sliderReleased,this,&WindowSystem::Tigger_Device);
    AutoTime=new QTimer(this);
    connect(AutoTime,&QTimer::timeout,this,[=]{
        AutoMode();
    });
    Button_Init();
    XprogressbarIfconfig();
    Image_Init();
}

WindowSystem::~WindowSystem()
{
    delete ui;
}

void WindowSystem::Shadow()
{
    QGraphicsDropShadowEffect *bottom = new QGraphicsDropShadowEffect(this);
    bottom->setOffset(8);
    bottom->setColor(/*Qt::gray*/QColor(43, 43, 43));
    bottom->setBlurRadius(35);
    ui->bottom->setGraphicsEffect(bottom);

    QGraphicsDropShadowEffect *OutsideTemp = new QGraphicsDropShadowEffect(this);
    OutsideTemp->setOffset(2);
    OutsideTemp->setColor(/*Qt::gray*/QColor(43, 43, 43));
    OutsideTemp->setBlurRadius(15);
    ui->CurrentTemp->setGraphicsEffect(OutsideTemp);

    ButtonStyle_Button(ui->WindowClose,8,25);
    ButtonStyle_Button(ui->WindowOpen,8,25);
    ButtonStyle_Button(ui->WindowStop,8,25);

    QGraphicsDropShadowEffect *AutoSwitch = new QGraphicsDropShadowEffect(this);
    AutoSwitch->setOffset(2);
    AutoSwitch->setColor(/*Qt::gray*/QColor(43, 43, 43));
    AutoSwitch->setBlurRadius(15);
    ui->AutoSwitch->setGraphicsEffect(AutoSwitch);
}


void WindowSystem::on_BackMain_clicked()
{
    emit SendClose();
    this->close();
}

void WindowSystem::ButtonStyle(QPushButton *Name, int Offset, int BlurRadius)
{
    QGraphicsDropShadowEffect *ButtonStyle = new QGraphicsDropShadowEffect(this);
    ButtonStyle->setOffset(Offset);
    ButtonStyle->setColor(/*Qt::gray*/QColor(43, 43, 43));
    ButtonStyle->setBlurRadius(BlurRadius);
    Name->setGraphicsEffect(ButtonStyle);
}



void WindowSystem::on_WindowClose_clicked()
{
    Icon_Plan(0);
    ButtonStylePlan(8,8,1);
    ui->WindowClose->setStyleSheet("background-color: rgb(0, 0, 0);color:white;border-radius:15px;");
    ui->WindowOpen->setStyleSheet("background-color: rgb(255, 255, 255);color:black;border-radius:15px;");
    ui->WindowStop->setStyleSheet("background-color: rgb(255, 255,255 );color:black;border-radius:15px;");
    SetInstruction(2);
}

void WindowSystem::on_WindowOpen_clicked()
{
    Icon_Plan(1);
    ButtonStylePlan(8,1,8);
    ui->WindowOpen->setStyleSheet("background-color: rgb(0, 0, 0);color:white;border-radius:15px;");
    ui->WindowClose->setStyleSheet("background-color: rgb(255, 255, 255);color:black;border-radius:15px;");
    ui->WindowStop->setStyleSheet("background-color: rgb(255, 255,255 );color:black;border-radius:15px;");
    SetInstruction(1);
}

void WindowSystem::on_WindowStop_clicked()
{
    Icon_Plan(2);
    ButtonStylePlan(1,8,8);
    ui->WindowStop->setStyleSheet("background-color: rgb(0, 0, 0);color:white;border-radius:15px;");
    ui->WindowClose->setStyleSheet("background-color: rgb(255, 255, 255);color:black;border-radius:15px;");
    ui->WindowOpen->setStyleSheet("background-color: rgb(255, 255,255 );color:black;border-radius:15px;");
    SetInstruction(3);
}

void WindowSystem::ButtonStyle_Button(QPushButton *Name, int Offset, int BlurRadius)
{
    QGraphicsDropShadowEffect *ButtonStyle = new QGraphicsDropShadowEffect(this);
    ButtonStyle->setOffset(Offset);
    ButtonStyle->setColor(/*Qt::gray*/QColor(43, 43, 43));
    ButtonStyle->setBlurRadius(BlurRadius);
    Name->setGraphicsEffect(ButtonStyle);
}

void WindowSystem::AirQuality_Status(int Function, int Sub, int Value)//Sub---->地区
{
    qDebug()<<"innnn"<<Sub;
    switch(Sub)
    {
    case 1:
        ui->CurrentTemp->setText(QString::number(Value));
        ui->TempRange_Xprogress->setValue(Value);

        emit SendToWx("OutTemp",Value);
        qDebug()<<"Temp:"<<Value;
        break;
    case 2:
        ui->OutsideHum_XprogressBar->setValue(Value);
        emit SendToWx("OutHum",Value);
        OutSideHum=Value;
        qDebug()<<"Humi:"<<Value;
        break;
    case 4:
        ui->OutSidePM25_Xprogress->setValue(Value);
        emit SendToWx("OutSidePM25",Value);
        qDebug()<<"PM25:"<<Value;
        break;
    case 5:
        ui->OutSideSo2_Xprogress->setValue(Value);
        emit SendToWx("OutSideSo2",Value);
        qDebug()<<"PM25:"<<Value;
        break;
    case 8://晾衣服

        break;
    case 9://运动

        break;
    case 10://AQI
        if(Value==1)
        {
            ui->WeatherStatus->setText("晴天");
            emit SendToWx("Weather",1);
        }
        else if(Value){
            ui->WeatherStatus->setText("多云");
            emit SendToWx("Weather",2);
        }
        else if(Value){
            ui->WeatherStatus->setText("雨天");
            emit SendToWx("Weather",3);
        }
        Weather=Value;
        break;
    case 11:
        if(Value<=50){//良好
            ui->AirAqi->setText("良好");
            AQI=1;
        }
        else if(Value>50&&Value<=100){//较好
            ui->AirAqi->setText("较好");
            AQI=2;
        }
        else if(Value>100){//差
            ui->AirAqi->setText("较差");
            AQI=3;
        }
        break;
    }

    qDebug()<<"窗户----有爬虫程序";
}

void WindowSystem::Window_Status(int Sub , int Value)
{
    ui->Device_Qslider->setValue(Sub);
    qDebug()<<"窗户：---"<<Sub<<"操作："<<Value;
    switch(Value)
    {
    case 1:
        ui->WindowOpen->click();
        break;
    case 2:
        ui->WindowClose->click();
        break;
    case 3:
        ui->WindowStop->click();
        break;
    }

    data.insert(Sub,Value);
}

void WindowSystem::SetInstruction(int Order)
{
    int Sub=ui->CurrentWindow->text().toInt();
    QString WxData="Window_";
    if(Sub==0)
    {
        for(int i=0;i<=2;i++){
            WxData.insert(WxData.length(),QString::number(i));
            emit SendToWx(WxData,Order);
            WxData.remove(WxData.length()-1,WxData.length());
        }
    }
    else {
        WxData.insert(WxData.length(),QString::number(Sub));
        emit SendToWx(WxData,Order);//1--开 2--关 3--停
    }
    WindowStatus=Order;
    data.insert(Sub,WindowStatus);
    //-----指令发送
    if(SingleFalg==1){
        QString Open="ZB1010011";
        QString Close="ZB1010021";
        QString Stop="ZB1010031";
        switch(Order)
        {
        case 1:
            Open.insert(6,QString::number(Sub));
            emit RadioBroadcast(Open);
            break;
        case 2:
            Close.insert(6,QString::number(Sub));
            emit RadioBroadcast(Close);
            break;
        case 3:
            Stop.insert(6,QString::number(Sub));
            emit RadioBroadcast(Stop);
            break;
        }
    }
}

void WindowSystem::Button_Init()
{
    for(int i=1;i<=6;i++){
        data.insert(i,WindowStatus);
    }
}






void WindowSystem::CrawlAir(QMap<QString, QString> data )
{
    qDebug()<<"CrawlAir---------------------:"<<data;
}

void WindowSystem::CrawlWeather(QMap<QString, QString> data )
{
    qDebug()<<"CrawlWeather---------------------:"<<data;
}

void WindowSystem::CrawlActive(QMap<QString, QString> data )
{
    qDebug()<<"CrawlActive---------------------:"<<data;
}

void WindowSystem::AirAutoTigger(int data)
{
    AQI=4;
    if (data==1&&(locationOffice!=0||locationBar!=0||locationMeeting!=0)) {
        qDebug()<<"有人存在这个房间里面======";
        if(AQI<=3){//户外空气良好--开窗户
            qDebug()<<"户外空气质量好-----开启窗户";
            if(AutoFlag==1){
                AutoTime->start(1000);
            }
            else if(AutoFlag==0){
                AutoTime->stop();
            }
        }else{
            if(AutoFlag==1){
                if(WindStopFlag==0){
                    qDebug()<<"户外空气质量差-----开启新风";
                    qDebug()<<"AutoFlag-----"<<AutoFlag;
                    emit SendToWind(1);//户外空气差---开新风
                    emit AutoMode_Sync(1);
                    WindStopFlag=1;
                }
            }
        }
    }else {//如果没人或者室内空气良好则保持？
        if(WindLock==0){
            if(WindStopFlag==1){
                qDebug()<<"沒有人在辦公室";
                emit SendToWind(0);
                WindStopFlag=0;
            }
        }
    }
}

void WindowSystem::Auto_Sync(int data)
{
    switch(data){
    case 0:
        AutoFlag=1;
        break;
    case 1:
        AutoFlag=0;
        break;
    }
    ui->AutoSwitch->click();
    qDebug()<<"AutoFlag:"<<AutoFlag;
}

void WindowSystem::Location_Sync(int sub, int value)
{
    switch (sub) {
    case 1:
        locationMeeting=value;
        break;
    case 2:
        locationBar=value;
        break;
    case 3:
        locationOffice=value;
        break;
    }
}

void WindowSystem::Wind_Sync(int Order)
{
    WindLock=Order;
}


void WindowSystem::on_Device_Qslider_valueChanged(int value)
{
    ui->CurrentWindow->setText(QString::number(value));
}

void WindowSystem::Tigger_Device()
{
    Clear();
    QString CurrentWindow=ui->CurrentWindow->text();
    int Status=data.value(CurrentWindow.toInt());
    switch(Status)
    {
    case 1:
        ButtonStyle_Button(ui->WindowStop,8,25);
        ButtonStyle_Button(ui->WindowOpen,1,25);
        ButtonStyle_Button(ui->WindowClose,8,25);
        break;
    case 2:
        ButtonStyle_Button(ui->WindowStop,8,25);
        ButtonStyle_Button(ui->WindowOpen,8,25);
        ButtonStyle_Button(ui->WindowClose,1,25);
        break;
    case 3:
        ButtonStyle_Button(ui->WindowStop,1,25);
        ButtonStyle_Button(ui->WindowOpen,8,25);
        ButtonStyle_Button(ui->WindowClose,8,25);
        break;
    }
}

void WindowSystem::Clear()
{
    ButtonStyle_Button(ui->WindowStop,8,25);
    ButtonStyle_Button(ui->WindowOpen,8,25);
    ButtonStyle_Button(ui->WindowClose,8,25);
}

void WindowSystem::XprogressbarIfconfig()
{
    QList <XProgressBar*> XProgressBar;
    XProgressBar<<ui->OutSidePM25_Xprogress<<ui->OutSideSo2_Xprogress<<ui->OutsideHum_XprogressBar<<ui->TempRange_Xprogress;
    QLinearGradient lineGradient(0, 0, ui->OutSidePM25_Xprogress->width(), ui->OutSidePM25_Xprogress->height());
    lineGradient.setColorAt(0.0, QColor("#F1B45B"));
    lineGradient.setColorAt(0.5, QColor("#F2765C"));
    lineGradient.setColorAt(1.0, QColor("#6D59EF"));
    for(int i=0;i<XProgressBar.length();i++){
        XProgressBar[i]->setValueBrush(lineGradient);
        XProgressBar[i]->setAutoRadius(true);
        XProgressBar[i]->setRange(0,99);
    }
}

void WindowSystem::ButtonStylePlan(int i , int i2, int i3)
{
    ButtonStyle_Button(ui->WindowStop,i,25);
    ButtonStyle_Button(ui->WindowOpen,i2,25);
    ButtonStyle_Button(ui->WindowClose,i3,25);
}

void WindowSystem::Image_Init()
{
    QString filePath = ":/new/AirQulity/AirQulity/pm2.5.png";//图标位置自行调整
    QIcon icon = QIcon(filePath);
    QPixmap m_pic = icon.pixmap(icon.actualSize(QSize(80, 80)));//size自行调整
    ui->PM25P->setPixmap(m_pic);

    QString filePath2 = ":/new/AirQulity/AirQulity/PM10.png";//图标位置自行调整
    QIcon icon2 = QIcon(filePath2);
    QPixmap m_pic2 = icon2.pixmap(icon2.actualSize(QSize(80, 80)));//size自行调整
    ui->So2P->setPixmap(m_pic2);

    QString filePath3 = ":/new/Window/Window/Humi.png";//图标位置自行调整
    QIcon icon3 = QIcon(filePath3);
    QPixmap m_pic3 = icon3.pixmap(icon3.actualSize(QSize(80, 80)));//size自行调整
    ui->HumP->setPixmap(m_pic3);

    QString filePath4 = ":/new/Window/Window/Home.png";//图标位置自行调整
    QIcon icon4 = QIcon(filePath4);
    QPixmap m_pic4 = icon4.pixmap(icon4.actualSize(QSize(80, 80)));//size自行调整
    ui->SuitableP->setPixmap(m_pic4);


    QString filePath5 = ":/new/Window/Window/OutDoor.png";//图标位置自行调整
    QIcon icon5 = QIcon(filePath5);
    QPixmap m_pic5 = icon5.pixmap(icon5.actualSize(QSize(80, 80)));//size自行调整
    ui->SuitableP2->setPixmap(m_pic5);
}

void WindowSystem::AutoMode()
{
    IndoorTemp=24;
    if(OutSideHum<=65){
        if(IndoorTemp<=23&&IndoorTemp>=16){//在舒适的温度下---开窗户
            if(Weather!=1){//雨天----关窗户
                if(WindowStopFlag==0){
                    ui->Device_Qslider->setValue(1);//暂时先是---第一个窗户
                    on_WindowClose_clicked();
                    WindowStopFlag=1;
                }
            }
            else {//非雨天----开窗户
                if(WindowStopFlag==1){
                    ui->Device_Qslider->setValue(1);
                    on_WindowOpen_clicked();
                    WindowStopFlag=0;
                }
            }
        }
        else {//在寒冷或者炎热的时候--关闭窗户
            if(WindowStopFlag==1){
                ui->Device_Qslider->setValue(1);
                on_WindowClose_clicked();
                WindowStopFlag=0;
            }
        }
    }
    else {//湿度-----高于65关窗
        if(WindowStopFlag==1){
            ui->Device_Qslider->setValue(1);
            on_WindowClose_clicked();
            WindowStopFlag=0;
        }
    }
}

void WindowSystem::on_AutoSwitch_clicked()
{
    if(AutoFlag==0){
        ui->AutoSwitch->setIcon(QIcon(":/new/Led/Led/AI_OFF.png"));
        ui->AutoSwitch->setStyleSheet("background-color: rgb(0, 0, 0);color:black; border-radius:15px;");
        AutoFlag=1;
        ui->Device_Qslider->setEnabled(0);
        ui->WindowOpen->setEnabled(0);
        ui->WindowStop->setEnabled(0);
        ui->WindowClose->setEnabled(0);
    }
    else {
        ui->AutoSwitch->setIcon(QIcon(":/new/Led/Led/AI_ON.png"));
        ui->AutoSwitch->setStyleSheet("background-color: rgb(255, 255, 255);color:black; border-radius:15px;");
        AutoFlag=0;
        ui->Device_Qslider->setEnabled(1);
        ui->WindowOpen->setEnabled(1);
        ui->WindowStop->setEnabled(1);
        ui->WindowClose->setEnabled(1);
    }
}

void WindowSystem::Icon_Plan(int Order)
{
    switch(Order){
    case 0:
        ui->WindowClose->setIcon(QIcon(":/new/Window/Window/Close_White.png"));
        ui->WindowOpen->setIcon(QIcon(":/new/Window/Window/Open.png"));
        ui->WindowStop->setIcon(QIcon(":/new/Curtain/Curtain/Stop_OFF.png"));
        break;
    case 1:
        ui->WindowClose->setIcon(QIcon(":/new/Window/Window/Close.png"));
        ui->WindowOpen->setIcon(QIcon(":/new/Window/Window/Open_White.png"));
        ui->WindowStop->setIcon(QIcon(":/new/Curtain/Curtain/Stop_OFF.png"));
        break;
    case 2:
        ui->WindowClose->setIcon(QIcon(":/new/Window/Window/Close.png"));
        ui->WindowOpen->setIcon(QIcon(":/new/Window/Window/Open.png"));
        ui->WindowStop->setIcon(QIcon(":/new/Curtain/Curtain/Stop_ON.png"));
        break;
    }
}
