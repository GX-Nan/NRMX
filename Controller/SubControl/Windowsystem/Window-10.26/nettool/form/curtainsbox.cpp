#include "curtainsbox.h"
#include "ui_curtainsbox.h"

CurtainsBox::CurtainsBox(QWidget *parent) :
    QDialog(parent,Qt::WindowTitleHint | Qt::CustomizeWindowHint),
    ui(new Ui::CurtainsBox)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint | Qt::CustomizeWindowHint);
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::Tool);
    connect(ui->Device_Slider,&QSlider::sliderReleased,this,&CurtainsBox::Tigger_DeviceSlider);
    ShadowInit();

}

CurtainsBox::~CurtainsBox()
{
    delete ui;
}

void CurtainsBox::on_Close_clicked()
{
    this->close();
    emit CloseShawdown();
}

void CurtainsBox::ShadowInit()
{
    QGraphicsDropShadowEffect *Up = new QGraphicsDropShadowEffect(this);
    Up->setOffset(8);
    Up->setColor(/*Qt::gray*/QColor(43, 43, 43));
    Up->setBlurRadius(25);
    ui->Up->setGraphicsEffect(Up);

    QGraphicsDropShadowEffect *Stop = new QGraphicsDropShadowEffect(this);
    Stop->setOffset(8);
    Stop->setColor(/*Qt::gray*/QColor(43, 43, 43));
    Stop->setBlurRadius(25);
    ui->Stop->setGraphicsEffect(Stop);

    QGraphicsDropShadowEffect *Down = new QGraphicsDropShadowEffect(this);
    Down->setOffset(8);
    Down->setColor(/*Qt::gray*/QColor(43, 43, 43));
    Down->setBlurRadius(25);
    ui->Down->setGraphicsEffect(Down);

    QGraphicsDropShadowEffect *Close = new QGraphicsDropShadowEffect(this);
    Close->setOffset(8);
    Close->setColor(/*Qt::gray*/QColor(43, 43, 43));
    Close->setBlurRadius(25);
    ui->Close->setGraphicsEffect(Close);
}

void CurtainsBox::ButtonStyle_Button(QPushButton *Name, int Offset, int BlurRadius)
{
    QGraphicsDropShadowEffect *ButtonStyle = new QGraphicsDropShadowEffect(this);
    ButtonStyle->setOffset(Offset);
    ButtonStyle->setColor(/*Qt::gray*/QColor(43, 43, 43));
    ButtonStyle->setBlurRadius(BlurRadius);
    Name->setGraphicsEffect(ButtonStyle);
}

void CurtainsBox::on_Up_clicked()
{
    ButtonStylePlan(1,8,8);
    SetInstruction(0);
    ui->Up->setStyleSheet("background-color: rgb(0, 0, 0);color:white;border-radius:15px;");
    ui->Down->setStyleSheet("background-color: rgb(255, 255, 255);color:black;border-radius:15px;");
    ui->Stop->setStyleSheet("background-color: rgb(255, 255,255 );color:black;border-radius:15px;");
}

void CurtainsBox::on_Stop_clicked()
{
    ButtonStylePlan(8,8,1);
    SetInstruction(4);
    ui->Stop->setStyleSheet("background-color: rgb(0, 0, 0);color:white;border-radius:15px;");
    ui->Down->setStyleSheet("background-color: rgb(255, 255, 255);color:black;border-radius:15px;");
    ui->Up->setStyleSheet("background-color: rgb(255, 255,255 );color:black;border-radius:15px;");


}

void CurtainsBox::on_Down_clicked()
{

    ButtonStylePlan(8,1,8);
    SetInstruction(1);
    ui->Down->setStyleSheet("background-color: rgb(0, 0, 0);color:white;border-radius:15px;");
    ui->Stop->setStyleSheet("background-color: rgb(255, 255, 255);color:black;border-radius:15px;");
    ui->Up->setStyleSheet("background-color: rgb(255, 255,255 );color:black;border-radius:15px;"); 
}

void CurtainsBox::on_Device_Slider_valueChanged(int value)
{
    ui->CurrentText->setText(QString::number(value));
}

void CurtainsBox::Tigger_DeviceSlider()
{
    ReturnStop=1;
    int status=Data.GetStatus(ui->CurrentText->text().toInt());
    Update_Ui(status);

}

void CurtainsBox::ButtonStylePlan(int i, int i2, int i3)
{
    ButtonStyle_Button(ui->Up,i,25);
    ButtonStyle_Button(ui->Down,i2,25);
    ButtonStyle_Button(ui->Stop,i3,25);
}

void CurtainsBox::Update_Ui(int Order)//切换活动条的时候界面更换
{
    switch(Order)
    {
    case 0:
        ui->Up->click();
        break;
    case 1:
        ui->Down->click();
        break;
    case 4:
        ui->Stop->click();
        break;
    }
}

void CurtainsBox::ReceiveData(int Sub, int Value)//接收服务器发来的信息
{
    ui->Device_Slider->setValue(Sub);
    Update_Ui(Value);
    emit EndSignals();
}

void CurtainsBox::Curtains_Sync(int Order)
{

    ui->Device_Slider->setValue(0);
    Update_Ui(Order);
}

void CurtainsBox::SetInstruction(int Order)
{
    QString Sub=ui->CurrentText->text();
    qDebug()<<"Order:"<<Order;
    if(ReturnStop==0){
        QString Open="ZB1020001";
        QString Close="ZB1020011";
        QString Stop="ZB1020041";
        switch(Order)
        {
        case 0:
            Open.insert(6,Sub);
            emit RadioBroadcast(Open);
            break;
        case 1:
            Close.insert(6,Sub);
            emit RadioBroadcast(Close);
            break;
        case 4:
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
        emit Curtains_Sub(Order);
    }else {
        Data.SetData(Sub.toInt(),Order);//写入库内
    }
    ReturnStop=0;
}


