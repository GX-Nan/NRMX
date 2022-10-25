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

    //    QGraphicsDropShadowEffect *LocalArea = new QGraphicsDropShadowEffect(this);
    //    LocalArea->setOffset(2);
    //    LocalArea->setColor(/*Qt::gray*/QColor(43, 43, 43));
    //    LocalArea->setBlurRadius(15);
    //    ui->LocalArea->setGraphicsEffect(LocalArea);
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

    ButtonStylePlan(8,8,1);
    ui->WindowClose->setStyleSheet("background-color: rgb(0, 0, 0);color:white;border-radius:15px;");
    ui->WindowOpen->setStyleSheet("background-color: rgb(255, 255, 255);color:black;border-radius:15px;");
    ui->WindowStop->setStyleSheet("background-color: rgb(255, 255,255 );color:black;border-radius:15px;");
    SetInstruction(2);
}

void WindowSystem::on_WindowOpen_clicked()
{

    ButtonStylePlan(8,1,8);
    ui->WindowOpen->setStyleSheet("background-color: rgb(0, 0, 0);color:white;border-radius:15px;");
    ui->WindowClose->setStyleSheet("background-color: rgb(255, 255, 255);color:black;border-radius:15px;");
    ui->WindowStop->setStyleSheet("background-color: rgb(255, 255,255 );color:black;border-radius:15px;");
    SetInstruction(1);
}

void WindowSystem::on_WindowStop_clicked()
{
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
    qDebug()<<"innnn"<<Function;
    switch(Function)
    {
    case 1:
        ui->CurrentTemp->setText(QString::number(Value));
        break;
    case 2:
        ui->OutSidePM25_Xprogress->setValue(Value);
        break;
    case 3:
        ui->OutsideHumi_XprogressBar->setValue(Value);
        break;
    case 4:
        ui->OutSideCo2_Xprogress->setValue(Value);
        // ui->OutsideHCHO_XprogressBar->setValue(Value);
        break;
    case 5://AQI

        break;
    }
}

void WindowSystem::Window_Status(int Sub , int Value)
{
    ui->Device_Qslider->setValue(Sub);
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
    XProgressBar<<ui->OutSidePM25_Xprogress<<ui->OutSideCo2_Xprogress<<ui->OutsideHumi_XprogressBar<<ui->TempRange_Xprogress;
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

    QString filePath2 = ":/new/AirQulity/AirQulity/co2.png";//图标位置自行调整
    QIcon icon2 = QIcon(filePath2);
    QPixmap m_pic2 = icon2.pixmap(icon2.actualSize(QSize(80, 80)));//size自行调整
    ui->Co2P->setPixmap(m_pic2);

    QString filePath3 = ":/new/Window/Window/Humi.png";//图标位置自行调整
    QIcon icon3 = QIcon(filePath3);
    QPixmap m_pic3 = icon3.pixmap(icon3.actualSize(QSize(80, 80)));//size自行调整
    ui->HumiP->setPixmap(m_pic3);
}
