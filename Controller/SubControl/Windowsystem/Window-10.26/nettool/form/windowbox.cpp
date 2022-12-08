#include "windowbox.h"
#include "ui_windowbox.h"

WindowBox::WindowBox(QWidget *parent) :
    QDialog(parent,Qt::WindowTitleHint | Qt::CustomizeWindowHint),
    ui(new Ui::WindowBox)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint | Qt::CustomizeWindowHint);
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::Tool);
    connect(ui->Device_Slider,&QSlider::sliderReleased,this,&WindowBox::Tigger_DeviceSlider);
    Shadow_Init();
}

WindowBox::~WindowBox()
{
    delete ui;
}

void WindowBox::on_Back_clicked()
{
    this->close();
    emit CloseShawdown();
}

void WindowBox::Shadow_Init()
{
    QGraphicsDropShadowEffect *Up = new QGraphicsDropShadowEffect(this);
    Up->setOffset(8);
    Up->setColor(/*Qt::gray*/QColor(43, 43, 43));
    Up->setBlurRadius(25);
    ui->Back->setGraphicsEffect(Up);

    QGraphicsDropShadowEffect *Stop = new QGraphicsDropShadowEffect(this);
    Stop->setOffset(8);
    Stop->setColor(/*Qt::gray*/QColor(43, 43, 43));
    Stop->setBlurRadius(25);
    ui->Stop->setGraphicsEffect(Stop);

    QGraphicsDropShadowEffect *Down = new QGraphicsDropShadowEffect(this);
    Down->setOffset(8);
    Down->setColor(/*Qt::gray*/QColor(43, 43, 43));
    Down->setBlurRadius(25);
    ui->Open->setGraphicsEffect(Down);

    QGraphicsDropShadowEffect *Close = new QGraphicsDropShadowEffect(this);
    Close->setOffset(8);
    Close->setColor(/*Qt::gray*/QColor(43, 43, 43));
    Close->setBlurRadius(25);
    ui->Close->setGraphicsEffect(Close);//优化按钮
}

void WindowBox::Tigger_DeviceSlider()
{
    ReturnStop=1;
    int status=Data.GetStatus(ui->CurrentText->text().toInt());
    Update_Ui(status);
}

void WindowBox::ButtonStylePlan(int i, int i2, int i3)
{
    ButtonStyle_Button(ui->Open,i,25);
    ButtonStyle_Button(ui->Close,i2,25);
    ButtonStyle_Button(ui->Stop,i3,25);
}

void WindowBox::ButtonStyle_Button(QPushButton *Name, int Offset, int BlurRadius)
{
    QGraphicsDropShadowEffect *ButtonStyle = new QGraphicsDropShadowEffect(this);
    ButtonStyle->setOffset(Offset);
    ButtonStyle->setColor(/*Qt::gray*/QColor(43, 43, 43));
    ButtonStyle->setBlurRadius(BlurRadius);
    Name->setGraphicsEffect(ButtonStyle);
}

void WindowBox::Update_Ui(int Order)
{
    emit StartSignals();
    switch(Order)
    {
    case 1:
        ui->Open->click();
        break;
    case 2:
        ui->Close->click();
        break;
    case 3:
        ui->Stop->click();
        break;
    }
    emit EndSignals();
}

void WindowBox::on_Open_clicked()
{
    ButtonStylePlan(1,8,8);
    SetInstruction(1);

    ui->Open->setIcon(QIcon(":/new/Window/Window/Open_White.png"));
    ui->Close->setIcon(QIcon(":/new/Window/Window/Close.png"));
    ui->Stop->setIcon(QIcon(":/new/Curtains/Curtains/Stop_OFF.png"));

    ui->Open->setStyleSheet("background-color: rgb(0, 0, 0);color:white;border-radius:15px;");
    ui->Close->setStyleSheet("background-color: rgb(255, 255, 255);color:black;border-radius:15px;");
    ui->Stop->setStyleSheet("background-color: rgb(255, 255,255 );color:black;border-radius:15px;");
}

void WindowBox::on_Close_clicked()
{

    ButtonStylePlan(8,1,8);
    SetInstruction(2);

    ui->Open->setIcon(QIcon(":/new/Window/Window/Open.png"));
    ui->Close->setIcon(QIcon(":/new/Window/Window/Close_White.png"));
    ui->Stop->setIcon(QIcon(":/new/Curtains/Curtains/Stop_OFF.png"));


    ui->Close->setStyleSheet("background-color: rgb(0, 0, 0);color:white;border-radius:15px;");
    ui->Open->setStyleSheet("background-color: rgb(255, 255, 255);color:black;border-radius:15px;");
    ui->Stop->setStyleSheet("background-color: rgb(255, 255,255 );color:black;border-radius:15px;");
}

void WindowBox::on_Stop_clicked()
{

    ButtonStylePlan(8,8,1);
    SetInstruction(3);

    ui->Open->setIcon(QIcon(":/new/Window/Window/Open.png"));
    ui->Close->setIcon(QIcon(":/new/Window/Window/Close.png"));
    ui->Stop->setIcon(QIcon(":/new/Curtains/Curtains/Stop_ON.png"));

    ui->Stop->setStyleSheet("background-color: rgb(0, 0, 0);color:white;border-radius:15px;");
    ui->Open->setStyleSheet("background-color: rgb(255, 255, 255);color:black;border-radius:15px;");
    ui->Close->setStyleSheet("background-color: rgb(255, 255,255 );color:black;border-radius:15px;");
}

void WindowBox::SetInstruction(int Order)
{
    QString Sub=ui->CurrentText->text();
    qDebug()<<"Order:"<<Order;
    if(ReturnStop==0){
        QString Open="ZB1010011";
        QString Close="ZB1010021";
        QString Stop="ZB1010031";
        switch(Order)
        {
        case 1:
            Open.insert(6,Sub);
            emit RadioBroadcast(Open);
            break;
        case 2:
            Close.insert(6,Sub);
            emit RadioBroadcast(Close);
            break;
        case 3:
            Stop.insert(6,Sub);
            emit RadioBroadcast(Stop);
            break;
        }
    }
    if(Sub=="0"){
        for(int i=0;i<=3;i++)
        {
            Data.SetData(i,Order);//写入库内
        }
        emit Windows_Sub(Order);
    }else {
        Data.SetData(Sub.toInt(),Order);//写入库内
    }
    ReturnStop=0;
}

void WindowBox::ReceiveData(int Sub, int Value)
{
    ui->Device_Slider->setValue(Sub);
    Update_Ui(Value);
}

void WindowBox::Windows_Sync(int Order)
{
    qDebug()<<"WindowBox-----Sync";
    ui->Device_Slider->setValue(0);
    switch(Order)
    {
    case 1:
        ui->Open->click();
        break;
    case 2:
        ui->Close->click();
        break;
    case 3:
        ui->Stop->click();
        break;
    }
}

void WindowBox::on_Device_Slider_valueChanged(int value)
{
    ui->CurrentText->setText(QString::number(value));
}
