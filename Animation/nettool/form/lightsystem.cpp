//Lightsysten.cpp
//Author: Y.PENG

#include "lightsystem.h"
#include "ui_lightsystem.h"
#include<QGraphicsDropShadowEffect>
LightSystem::LightSystem(QWidget *parent) :
    QDialog(parent,Qt::WindowTitleHint | Qt::CustomizeWindowHint),
    ui(new Ui::LightSystem)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint | Qt::CustomizeWindowHint);
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::Tool);
   // this->setAttribute(Qt::WA_TranslucentBackground);
    Shawdow();
    XprogressbarIfconfig();
    Switch_Ifconfig();
    Light_Init();
    Image_Init();
    connect(ui->Brightness_Slider,&QSlider::sliderReleased,this,&LightSystem::Trigger_BrightnessQslider);
    connect(ui->Color_Slider,&QSlider::sliderReleased,this,&LightSystem::Trigger_ColorQslider);
    connect(ui->Device_Slider,&QSlider::sliderReleased,this,&LightSystem::Trigger_DeviceQslider);
    connect(ui->Led_Switch,&SwitchButton::checkedChanged,this,&LightSystem::Light_Switch);
    connect(ui->Lux_All,&SwitchButton::checkedChanged,this,[=]
    {
        LuxFalg=-LuxFalg;
    });
    connect(ui->Color_All,&SwitchButton::checkedChanged,this,[=]
    {
        ColorFalg=-ColorFalg;
    });
}

LightSystem::~LightSystem()
{
    delete ui;
}

void LightSystem::Shawdow()
{
    QGraphicsDropShadowEffect *bottom = new QGraphicsDropShadowEffect(this);
    bottom->setOffset(15);
    bottom->setColor(/*Qt::gray*/QColor(43, 43, 43));
    bottom->setBlurRadius(25);
    ui->bottom->setGraphicsEffect(bottom);

    QGraphicsDropShadowEffect *ButtonBox = new QGraphicsDropShadowEffect(this);
    ButtonBox->setOffset(8);
    ButtonBox->setColor(/*Qt::gray*/QColor(43, 43, 43));
    ButtonBox->setBlurRadius(25);
    ui->ButtonBox->setGraphicsEffect(ButtonBox);
    ButtonStyle_Label(ui->InsidesBrightness,8,20);
}

void LightSystem::Switch_Ifconfig()
{
    QList <SwitchButton*> Switch;
    Switch<<ui->Led_Switch;
    for(int i=0;i<Switch.length();i++)
    {
        Switch[i]->setSpace(8);
        Switch[i]->setRectRadius(30);
        Switch[i]->setShowText(false);
        Switch[i]->setAnimation(true);
    }
}

void LightSystem::XprogressbarIfconfig()
{
    QList <XProgressBar*> XProgressBar;
    XProgressBar<<ui->Brightness_Xprogress<<ui->Color_Xprogress;
    QLinearGradient lineGradient(0, 0, ui->Brightness_Xprogress->width(), ui->Brightness_Xprogress->height());
    lineGradient.setColorAt(0.0, QColor("#F1B45B"));
    lineGradient.setColorAt(0.5, QColor("#F2765C"));
    lineGradient.setColorAt(1.0, QColor("#6D59EF"));
    for(int i=0;i<XProgressBar.length();i++){
        XProgressBar[i]->setValueBrush(lineGradient);
        XProgressBar[i]->setAutoRadius(true);
        XProgressBar[i]->setRange(0,99);
    }
}

void LightSystem::on_BackMain_clicked()
{
    this->close();
    emit SendClose();
}

void LightSystem::on_AloneControl_clicked()
{
    ui->PageBottom->setCurrentIndex(1);
}

void LightSystem::on_ModeChoice_clicked()
{
    ui->PageBottom->setCurrentIndex(0);
}

void LightSystem::ButtonStyle_Label(QLabel *Name, int Offset, int BlurRadius)
{
    QGraphicsDropShadowEffect *ButtonStyle = new QGraphicsDropShadowEffect(this);
    ButtonStyle->setOffset(Offset);
    ButtonStyle->setColor(/*Qt::gray*/QColor(43, 43, 43));
    ButtonStyle->setBlurRadius(BlurRadius);
    Name->setGraphicsEffect(ButtonStyle);
}

void LightSystem::ButtonStyle_Button(QPushButton *Name, int Offset, int BlurRadius)
{
    QGraphicsDropShadowEffect *ButtonStyle = new QGraphicsDropShadowEffect(this);
    ButtonStyle->setOffset(Offset);
    ButtonStyle->setColor(/*Qt::gray*/QColor(43, 43, 43));
    ButtonStyle->setBlurRadius(BlurRadius);
    Name->setGraphicsEffect(ButtonStyle);
}

void LightSystem::on_Brightness_Slider_valueChanged(int value)
{
    QString CurrentLed= ui->SelectedLed->text();

    ui->Brightness_Xprogress->setValue(value);
    ui->Brightness_Text->setText(QString::number(value));

    status.SetLux(value);
    if(LuxFalg==1)
    {
        for(int i=1;i<=6;i++){
            data.insert(i,status);
        }
    }
    else{
        data.insert(CurrentLed.toInt(),status);
    }

}

void LightSystem::on_Color_Slider_valueChanged(int value)
{
    QString CurrentLed= ui->SelectedLed->text();

    ui->Color_Xprogress->setValue(value);
    ui->Color_Text->setText(QString::number(value));

    status.SetColor(value);
    if(ColorFalg==1)
    {
        for(int i=1;i<=6;i++){
            data.insert(i,status);
        }
    }
    else {
        data.insert(CurrentLed.toInt(),status);
    }
}

void LightSystem::Trigger_BrightnessQslider()
{

    QString SendData="ZB20301";//亮度
    QString CurrentLed= ui->SelectedLed->text();
    QString SetTemp=ui->Brightness_Text->text();

    switch (LuxFalg) {
    case -1:
        SendData.insert(6,CurrentLed);
        break;
    case 1:
        SendData.insert(6,0);
        break;
    }
    if(SetTemp.toInt()<10)
    {
        SetTemp.insert(0,"0");
    }
    SendData.insert(7,SetTemp);

    //data.Temp=SetTemp.toInt();
    emit RadioBroadcast(SendData);
    qDebug()<<"test----brightness";
}

void LightSystem::Trigger_ColorQslider()
{
    QString SendData="ZB20101";//色温
    QString SetTemp=ui->Color_Text->text();
    QString CurrentLed= ui->SelectedLed->text();
    switch (LuxFalg) {
    case -1:
        SendData.insert(6,CurrentLed);
        break;
    case 1:
        SendData.insert(6,0);
        break;
    }
    if(SetTemp.toInt()<10)
    {
        SetTemp.insert(0,"0");
    }
    SendData.insert(7,SetTemp);
    // data.Temp=SetTemp.toInt();
    emit RadioBroadcast(SendData);
    qDebug()<<"test----Color";
}

void LightSystem::Trigger_DeviceQslider()
{
    QString CurrentLed= ui->SelectedLed->text();
    Status test=data.value(CurrentLed.toInt());
    int Lux =test.GetLux();
    int Color=test.GetColor();
    int station=test.GetStation();
    ui->Brightness_Slider->setValue(Lux);
    ui->Color_Slider->setValue(Color);
    ui->Led_Switch->setChecked(station);
    qDebug()<<"Current:"<<CurrentLed<<"lux:"<<Lux<<"Color:"<<Color;
}



void LightSystem::on_AllLed_Status_clicked()
{
    if(AllLight_Status==0){
        ButtonStyle_Button(ui->AllLed_Status,1,20);
        ButtonStyle_Button(ui->AiMode,8,20);
      //  AiMode_Falg=0;
        ui->AllLed_Status->setStyleSheet("background-color: rgb(0, 0, 0);color:white;border-radius:15px;");
        emit RadioBroadcast("ZB20300991");//需要增加 0位的设备位 ----->是控制全部灯光的亮度与色温
        AllLight_Status=1;
    }
    else {
        ButtonStyle_Button(ui->AllLed_Status,8,20);
        ButtonStyle_Button(ui->AiMode,8,20);
        ui->AllLed_Status->setStyleSheet("background-color: rgb(255, 255, 255);color:white;border-radius:15px;");
        AiMode_Falg=0;
        emit RadioBroadcast("ZB20300001");//需要增加 0位的设备位 ----->是控制全部灯光的亮度与色温
        AllLight_Status=0;
    }
}

void LightSystem::on_AiMode_clicked()
{
    //    if(AiMode_Falg==0){
    //        ButtonStyle_Button(ui->AllLed_On,8,20);
    //        ButtonStyle_Button(ui->AllLed_OFF,8,20);
    //        ButtonStyle_Button(ui->AiMode,1,20);
    //        ui->AllLed_On->setEnabled(1);
    //        ui->AllLed_OFF->setEnabled(1);
    //        AiMode_Falg=1;
    //    }
    //    else if(AiMode_Falg==1)
    //    {
    //        ButtonStyle_Button(ui->AllLed_On,8,20);
    //        ButtonStyle_Button(ui->AllLed_OFF,8,20);
    //        ButtonStyle_Button(ui->AiMode,8,20);
    //        AiMode_Falg=0;
    //    }
}

void LightSystem::InstructionSet(int Function, int Value)
{
    switch (Function) {
    case 1:
        qDebug()<<"色温";
        ui->Color_Slider->setValue(Value);
        break;
    case 3:
        qDebug()<<"亮度";
        ui->Brightness_Slider->setValue(Value);
        break;
    }
}

void LightSystem::Light_Init()
{
    for(int i=1;i<=6;i++){
        data.insert(i,status);
    }
}

void LightSystem::Light_Status(int Function, int Sub, int Value)
{
    int SelectNumber=ui->SelectedLed->text().toInt();
    //-----------Qslier拖动
    switch (Function) {
    case 1:
        status.SetColor(Value);
        break;
    case 3:
        status.SetLux(Value);
        break;
    }
    //-------------全开/关
    if(Sub==0){
        for(int i=1;i<=6;i++){
            data.insert(i,status);
        }
        InstructionSet(Function,Value);
    }
    else {
        data.insert(Sub,status);
        if(Sub==SelectNumber)
        {
            qDebug()<<"符合当前的";
            InstructionSet(Function,Value);
        }
    }
}

void LightSystem::on_Device_Slider_valueChanged(int value)
{
    ui->SelectedLed->setText(QString::number(value));
}

void LightSystem::Light_Switch(int Falg)
{
    AiMode_Falg=0;
    int SelectNumber=ui->SelectedLed->text().toInt();
    //---------设置无法执行
    ui->Brightness_Slider->setEnabled(Falg);
    ui->Color_Slider->setEnabled(Falg);
    ui->Lux_All->setEnabled(Falg);
    ui->Color_All->setEnabled(Falg);
    //------------------------------
    status.SetStation(Falg);
    data.insert(SelectNumber,status);
    switch (Falg) {
    case 0:
        ui->Brightness_Slider->setValue(0);
        break;
    case 1:
        ui->Brightness_Slider->setValue(status.GetLux());
        break;
    }
}

void LightSystem::Image_Init()
{
    QString filePath = ":/new/Led/Led/Brightness.png";//图标位置自行调整
    QIcon icon = QIcon(filePath);
    QPixmap m_pic = icon.pixmap(icon.actualSize(QSize(80, 80)));//size自行调整
    ui->BrightnessP->setPixmap(m_pic);
    ui->BrightnessP2->setPixmap(m_pic);
}
