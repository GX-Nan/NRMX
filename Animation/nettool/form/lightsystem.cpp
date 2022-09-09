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

    QGraphicsDropShadowEffect *ChandelierBox = new QGraphicsDropShadowEffect(this);
    ChandelierBox->setOffset(8);
    ChandelierBox->setColor(/*Qt::gray*/QColor(43, 43, 43));
    ChandelierBox->setBlurRadius(25);
    ui->ChandelierBox->setGraphicsEffect(ChandelierBox);

    QGraphicsDropShadowEffect *LEDBox = new QGraphicsDropShadowEffect(this);
    LEDBox->setOffset(8);
    LEDBox->setColor(/*Qt::gray*/QColor(43, 43, 43));
    LEDBox->setBlurRadius(25);
    ui->LEDBox->setGraphicsEffect(LEDBox);

    QGraphicsDropShadowEffect *SpotBox = new QGraphicsDropShadowEffect(this);
    SpotBox->setOffset(8);
    SpotBox->setColor(/*Qt::gray*/QColor(43, 43, 43));
    SpotBox->setBlurRadius(25);
    ui->SpotBox->setGraphicsEffect(SpotBox);//ChandeBottom

    QGraphicsDropShadowEffect *ChanStackedWidget = new QGraphicsDropShadowEffect(this);
    ChanStackedWidget->setOffset(8);
    ChanStackedWidget->setColor(/*Qt::gray*/QColor(43, 43, 43));
    ChanStackedWidget->setBlurRadius(25);
    ui->ChanStackedWidget->setGraphicsEffect(ChanStackedWidget);

    QGraphicsDropShadowEffect *Frame = new QGraphicsDropShadowEffect(this);
    Frame->setOffset(8);
    Frame->setColor(/*Qt::gray*/QColor(43, 43, 43));
    Frame->setBlurRadius(25);
    ui->frame->setGraphicsEffect(Frame);

    QGraphicsDropShadowEffect *LedSpot = new QGraphicsDropShadowEffect(this);
    LedSpot->setOffset(8);
    LedSpot->setColor(/*Qt::gray*/QColor(43, 43, 43));
    LedSpot->setBlurRadius(25);
    ui->LedSpot->setGraphicsEffect(LedSpot);

    QGraphicsDropShadowEffect *SpotFrame = new QGraphicsDropShadowEffect(this);
    SpotFrame->setOffset(8);
    SpotFrame->setColor(/*Qt::gray*/QColor(43, 43, 43));
    SpotFrame->setBlurRadius(25);
    ui->SpotFrame->setGraphicsEffect(SpotFrame);

    QGraphicsDropShadowEffect *LedFrame = new QGraphicsDropShadowEffect(this);
    LedFrame->setOffset(8);
    LedFrame->setColor(/*Qt::gray*/QColor(43, 43, 43));
    LedFrame->setBlurRadius(25);
    ui->LedFrame->setGraphicsEffect(LedFrame);
}

void LightSystem::Switch_Ifconfig()
{

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
        SendData.insert(6,"0");
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
        SendData.insert(6,"0");
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
    ui->Brightness_Slider->setValue(Lux);
    ui->Color_Slider->setValue(Color);
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
    ui->BrightnessP2->setPixmap(m_pic);
}

void LightSystem::on_LedChoice_clicked()
{
    ui->LedSpot->setCurrentIndex(1);
}

void LightSystem::on_SpotChoice_clicked()
{
    ui->LedSpot->setCurrentIndex(0);
}

void LightSystem::on_ChandChoice_clicked()
{
    int Index=ui->ChanStackedWidget->currentIndex();
    if(Index==1)
    {
        ui->ChanStackedWidget->setCurrentIndex(0);
    }
    else {
        ui->ChanStackedWidget->setCurrentIndex(1);
    }
    ui->label_11->setText("吊灯--"+QString::number(Index));
}

void LightSystem::on_ChandeDown2_clicked()
{
    ButtonStyle_Chandelier_2("ChandeDown2",1);

}

void LightSystem::on_ChandeStop2_clicked()
{
    ButtonStyle_Chandelier_2("ChandeStop2",1);
}

void LightSystem::on_ChandeUp2_clicked()
{
    ButtonStyle_Chandelier_2("ChandeUp2",1);
}


void LightSystem::ButtonStyle_Chandelier_1(QString Name, int Falg)
{
    QMap<QString,QPushButton*> Chande1;
    Chande1.insert("ChandeUp1",ui->ChandeUp1);
    Chande1.insert("ChandeDown1",ui->ChandeDown1);
    Chande1.insert("ChandeStop1",ui->ChandeStop1);


    if(Falg==1){
        QGraphicsDropShadowEffect *ButtonStyle = new QGraphicsDropShadowEffect(this);
        ButtonStyle->setOffset(8);
        ButtonStyle->setColor(/*Qt::gray*/QColor(43, 43, 43));
        ButtonStyle->setBlurRadius(15);
        Chande1.value(Name)->setGraphicsEffect(ButtonStyle);
        Chande1.value(Name)->setStyleSheet("background-color: rgb(0, 0, 0);color:white; border-radius:15px;");
        Chande1.remove(Name);

        for (QMap<QString, QPushButton*>::const_iterator it = Chande1.constBegin(); it != Chande1.constEnd(); it++) {
             it.value()->setStyleSheet("background-color: rgb(255, 255, 255);color:black; border-radius:15px;");
        }
    }
}

void LightSystem::ButtonStyle_Chandelier_2(QString Name, int Falg)
{
    QMap<QString,QPushButton*> Chande2;
    Chande2.insert("ChandeUp2",ui->ChandeUp2);
    Chande2.insert("ChandeDown2",ui->ChandeDown2);
    Chande2.insert("ChandeStop2",ui->ChandeStop2);

    if(Falg==1){
        QGraphicsDropShadowEffect *ButtonStyle = new QGraphicsDropShadowEffect(this);
        ButtonStyle->setOffset(8);
        ButtonStyle->setColor(/*Qt::gray*/QColor(43, 43, 43));
        ButtonStyle->setBlurRadius(15);
        Chande2.value(Name)->setGraphicsEffect(ButtonStyle);
        Chande2.value(Name)->setStyleSheet("background-color: rgb(0, 0, 0);color:white; border-radius:15px;");
        Chande2.remove(Name);

        for (QMap<QString, QPushButton*>::const_iterator it = Chande2.constBegin(); it != Chande2.constEnd(); it++) {
             it.value()->setStyleSheet("background-color: rgb(255, 255, 255);color:black; border-radius:15px;");
        }
    }
}

void LightSystem::on_ChandeDown1_clicked()
{
    ButtonStyle_Chandelier_1("ChandeDown1",1);
    emit RadioBroadcast("ZB20401021");
}

void LightSystem::on_ChandeStop1_clicked()
{
    ButtonStyle_Chandelier_1("ChandeStop1",1);
    emit RadioBroadcast("ZB20401031");
}

void LightSystem::on_ChandeUp1_clicked()
{
    ButtonStyle_Chandelier_1("ChandeUp1",1);
    emit RadioBroadcast("ZB20401011");
}

void LightSystem::on_ChandelierSwitch1_clicked()
{
    QString Status=status.GetMessage("Chandelier1");
    switch (Status.toInt()) {
    case 0:
        ButtonStyle_Button(ui->ChandelierSwitch1,1,25);
        ui->ChandelierSwitch1->setStyleSheet("background-color: rgb(0, 0, 0);color:black; border-radius:15px;");
        status.InsertMessage("Chandelier1","1");
        emit RadioBroadcast("ZB20401051");
        break;
    case 1:
        ButtonStyle_Button(ui->ChandelierSwitch1,8,25);
        ui->ChandelierSwitch1->setStyleSheet("background-color: rgb(255, 255, 255);color:white; border-radius:15px;");
        status.InsertMessage("Chandelier1","0");
        emit RadioBroadcast("ZB20401041");
        break;
    }
}
void LightSystem::on_ChandelierSwitch2_clicked()
{
    QString Status=status.GetMessage("Chandelier2");
    switch (Status.toInt()) {
    case 0:
        ButtonStyle_Button(ui->ChandelierSwitch2,1,25);
        ui->ChandelierSwitch2->setStyleSheet("background-color: rgb(0, 0, 0);color:black; border-radius:15px;");
        status.InsertMessage("Chandelier2","1");
        emit RadioBroadcast("ZB20402051");
        break;
    case 1:
        ButtonStyle_Button(ui->ChandelierSwitch2,8,25);
        ui->ChandelierSwitch2->setStyleSheet("background-color: rgb(255, 255, 255);color:white; border-radius:15px;");
        status.InsertMessage("Chandelier2","0");
        emit RadioBroadcast("ZB20402041");
        break;
    }
}

void LightSystem::on_SpotMeet1_clicked()
{
    QString Status=status.GetMessage("SpotMeet1");
    switch (Status.toInt()) {
    case 0:
        ButtonStyle_Button(ui->SpotMeet1,1,25);
        ui->SpotMeet1->setStyleSheet("background-color: rgb(0, 0, 0);color:black; border-radius:15px;");
        status.InsertMessage("SpotMeet1","1");
        emit RadioBroadcast("ZB20501011");
        break;
    case 1:
        ButtonStyle_Button(ui->SpotMeet1,8,25);
        ui->SpotMeet1->setStyleSheet("background-color: rgb(255, 255, 255);color:white; border-radius:15px;");
        status.InsertMessage("SpotMeet1","0");
        emit RadioBroadcast("ZB20501001");
        break;
    }
}

void LightSystem::on_SpotMeet2_clicked()
{
    QString Status=status.GetMessage("SpotMeet2");
    switch (Status.toInt()) {
    case 0:
        ButtonStyle_Button(ui->SpotMeet2,1,25);
        ui->SpotMeet2->setStyleSheet("background-color: rgb(0, 0, 0);color:black; border-radius:15px;");
        status.InsertMessage("SpotMeet2","1");
        emit RadioBroadcast("ZB20502011");
        break;
    case 1:
        ButtonStyle_Button(ui->SpotMeet2,8,25);
        ui->SpotMeet2->setStyleSheet("background-color: rgb(255, 255, 255);color:white; border-radius:15px;");
        status.InsertMessage("SpotMeet2","0");
        emit RadioBroadcast("ZB20502001");
        break;
    }
}

void LightSystem::on_SpotOffice1_clicked()
{
    QString Status=status.GetMessage("SpotOffice1");
    switch (Status.toInt()) {
    case 0:
        ButtonStyle_Button(ui->SpotOffice1,1,25);
        ui->SpotOffice1->setStyleSheet("background-color: rgb(0, 0, 0);color:black; border-radius:15px;");
        status.InsertMessage("SpotOffice1","1");
        emit RadioBroadcast("ZB20505011");
        break;
    case 1:
        ButtonStyle_Button(ui->SpotOffice1,8,25);
        ui->SpotOffice1->setStyleSheet("background-color: rgb(255, 255, 255);color:white; border-radius:15px;");
        status.InsertMessage("SpotOffice1","0");
        emit RadioBroadcast("ZB20505001");
        break;
    }
}

void LightSystem::on_SpotOffice2_clicked()
{
    QString Status=status.GetMessage("SpotOffice2");
    switch (Status.toInt()) {
    case 0:
        ButtonStyle_Button(ui->SpotOffice2,1,25);
        ui->SpotOffice2->setStyleSheet("background-color: rgb(0, 0, 0);color:black; border-radius:15px;");
        status.InsertMessage("SpotOffice2","1");
        emit RadioBroadcast("ZB20506011");
        break;
    case 1:
        ButtonStyle_Button(ui->SpotOffice2,8,25);
        ui->SpotOffice2->setStyleSheet("background-color: rgb(255, 255, 255);color:white; border-radius:15px;");
        status.InsertMessage("SpotOffice2","0");
        emit RadioBroadcast("ZB20506001");
        break;
    }
}

void LightSystem::on_SpotBar1_clicked()
{
    QString Status=status.GetMessage("SpotBar1");
    switch (Status.toInt()) {
    case 0:
        ButtonStyle_Button(ui->SpotBar1,1,25);
        ui->SpotBar1->setStyleSheet("background-color: rgb(0, 0, 0);color:black; border-radius:15px;");
        status.InsertMessage("SpotBar1","1");
        emit RadioBroadcast("ZB20503011");
        break;
    case 1:
        ButtonStyle_Button(ui->SpotBar1,8,25);
        ui->SpotBar1->setStyleSheet("background-color: rgb(255, 255, 255);color:white; border-radius:15px;");
        status.InsertMessage("SpotBar1","0");
        emit RadioBroadcast("ZB20503001");
        break;
    }
}

void LightSystem::on_SpotBar2_clicked()
{
    QString Status=status.GetMessage("SpotBar2");
    switch (Status.toInt()) {
    case 0:
        ButtonStyle_Button(ui->SpotBar2,1,25);
        ui->SpotBar2->setStyleSheet("background-color: rgb(0, 0, 0);color:black; border-radius:15px;");
        status.InsertMessage("SpotBar2","1");
        emit RadioBroadcast("ZB20504011");
        break;
    case 1:
        ButtonStyle_Button(ui->SpotBar2,8,25);
        ui->SpotBar2->setStyleSheet("background-color: rgb(255, 255, 255);color:white; border-radius:15px;");
        status.InsertMessage("SpotBar2","0");
        emit RadioBroadcast("ZB20504001");
        break;
    }
}

void LightSystem::on_LedMeet1_clicked()
{
    QString Status=status.GetMessage("LedMeet1");
    switch (Status.toInt()) {
    case 0:
        ButtonStyle_Button(ui->LedMeet1,1,25);
        ui->LedMeet1->setStyleSheet("background-color: rgb(0, 0, 0);color:black; border-radius:15px;");
        status.InsertMessage("LedMeet1","1");
        emit RadioBroadcast("ZB20601011");
        break;
    case 1:
        ButtonStyle_Button(ui->LedMeet1,8,25);
        ui->LedMeet1->setStyleSheet("background-color: rgb(255, 255, 255);color:white; border-radius:15px;");
        status.InsertMessage("LedMeet1","0");
        emit RadioBroadcast("ZB20601001");
        break;
    }
}

void LightSystem::on_LedMeet2_clicked()
{
    QString Status=status.GetMessage("LedMeet2");
    switch (Status.toInt()) {
    case 0:
        ButtonStyle_Button(ui->LedMeet2,1,25);
        ui->LedMeet2->setStyleSheet("background-color: rgb(0, 0, 0);color:black; border-radius:15px;");
        status.InsertMessage("LedMeet2","1");
        emit RadioBroadcast("ZB20602011");
        break;
    case 1:
        ButtonStyle_Button(ui->LedMeet2,8,25);
        ui->LedMeet2->setStyleSheet("background-color: rgb(255, 255, 255);color:white; border-radius:15px;");
        status.InsertMessage("LedMeet2","0");
        emit RadioBroadcast("ZB20602001");
        break;
    }
}

void LightSystem::on_LedBar1_clicked()
{
    QString Status=status.GetMessage("LedBar1");
    switch (Status.toInt()) {
    case 0:
        ButtonStyle_Button(ui->LedBar1,1,25);
        ui->LedBar1->setStyleSheet("background-color: rgb(0, 0, 0);color:black; border-radius:15px;");
        status.InsertMessage("LedBar1","1");
        emit RadioBroadcast("ZB20603011");
        break;
    case 1:
        ButtonStyle_Button(ui->LedBar1,8,25);
        ui->LedBar1->setStyleSheet("background-color: rgb(255, 255, 255);color:white; border-radius:15px;");
        status.InsertMessage("LedBar1","0");
        emit RadioBroadcast("ZB20603001");
        break;
    }
}

void LightSystem::on_LedBar2_clicked()
{
    QString Status=status.GetMessage("LedBar2");
    switch (Status.toInt()) {
    case 0:
        ButtonStyle_Button(ui->LedBar2,1,25);
        ui->LedBar2->setStyleSheet("background-color: rgb(0, 0, 0);color:black; border-radius:15px;");
        status.InsertMessage("LedBar2","1");
        emit RadioBroadcast("ZB20604011");
        break;
    case 1:
        ButtonStyle_Button(ui->LedBar2,8,25);
        ui->LedBar2->setStyleSheet("background-color: rgb(255, 255, 255);color:white; border-radius:15px;");
        status.InsertMessage("LedBar2","0");
        emit RadioBroadcast("ZB20604001");
        break;
    }
}

void LightSystem::on_LedOffice1_clicked()
{
    QString Status=status.GetMessage("LedOffice1");
    switch (Status.toInt()) {
    case 0:
        ButtonStyle_Button(ui->LedOffice1,1,25);
        ui->LedOffice1->setStyleSheet("background-color: rgb(0, 0, 0);color:black; border-radius:15px;");
        status.InsertMessage("LedOffice1","1");
        emit RadioBroadcast("ZB20605011");
        break;
    case 1:
        ButtonStyle_Button(ui->LedOffice1,8,25);
        ui->LedOffice1->setStyleSheet("background-color: rgb(255, 255, 255);color:white; border-radius:15px;");
        status.InsertMessage("LedOffice1","0");
        emit RadioBroadcast("ZB20605001");
        break;
    }
}

void LightSystem::on_LedOffice2_clicked()
{
    QString Status=status.GetMessage("LedOffice2");
    switch (Status.toInt()) {
    case 0:
        ButtonStyle_Button(ui->LedOffice2,1,25);
        ui->LedOffice2->setStyleSheet("background-color: rgb(0, 0, 0);color:black; border-radius:15px;");
        status.InsertMessage("LedOffice2","1");
        emit RadioBroadcast("ZB20606011");
        break;
    case 1:
        ButtonStyle_Button(ui->LedOffice2,8,25);
        ui->LedOffice2->setStyleSheet("background-color: rgb(255, 255, 255);color:white; border-radius:15px;");
        status.InsertMessage("LedOffice2","0");
        emit RadioBroadcast("ZB20606001");
        break;
    }
}

void LightSystem::on_LedAll_clicked()
{
    ui->LedSpot->setCurrentIndex(1);
    QString LedMeet1=status.GetMessage("LedMeet1");
    QString LedMeet2=status.GetMessage("LedMeet2");
    QString LedBar1=status.GetMessage("LedBar1");
    QString LedBar2=status.GetMessage("LedBar2");
    QString LedOffice1=status.GetMessage("LedOffice1");
    QString LedOffice2=status.GetMessage("LedOffice2");

    QList<QPushButton*> Button;//建立button的list
    QMap<int,QPushButton*> List;//对应
    Button<<ui->LedMeet1<<ui->LedMeet2<<ui->LedBar1<<ui->LedBar2<<ui->LedOffice1<<ui->LedOffice2;
    QList<QString>Value ;
    Value<<LedMeet1<<LedMeet2<<LedBar1<<LedBar2<<LedOffice1<<LedOffice2;

    for(int i=0;i<6;i++){
        List.insert(i,Button.at(i));
    }

    if(AllSpot_Status==0){
        for(int i=0;i<6;i++){
            if(Value.at(i)=="0"){
                List.value(i)->click();
            }
        }
        AllSpot_Status=1;

    }
    else if(AllSpot_Status==1)
    {
        for(int i=0;i<6;i++){
            if(Value.at(i)=="1"){
                List.value(i)->click();
            }
        }
        AllSpot_Status=0;

    }
}

void LightSystem::on_SpotAll_clicked()
{
    ui->LedSpot->setCurrentIndex(0);
    QString SpotMeet1=status.GetMessage("SpotMeet1");
    QString SpotMeet2=status.GetMessage("SpotMeet2");
    QString SpotBar1=status.GetMessage("SpotBar1");
    QString SpotBar2=status.GetMessage("SpotBar2");
    QString SpotOffice1=status.GetMessage("SpotOffice1");
    QString SpotOffice2=status.GetMessage("SpotOffice2");

    QList<QPushButton*> Button;//建立button的list
    QMap<int,QPushButton*> List;//对应
    Button<<ui->SpotMeet1<<ui->SpotMeet2<<ui->SpotBar1<<ui->SpotBar2<<ui->SpotOffice1<<ui->SpotOffice2;
    QList<QString>Value ;
    Value<<SpotMeet1<<SpotMeet2<<SpotBar1<<SpotBar2<<SpotOffice1<<SpotOffice2;

    for(int i=0;i<6;i++){
        List.insert(i,Button.at(i));
    }

    if(AllSpot_Status==0){
        for(int i=0;i<6;i++){
            if(Value.at(i)=="0"){
                List.value(i)->click();
            }
        }
        AllSpot_Status=1;
        emit RadioBroadcast("ZB20500011");
    }
    else if(AllSpot_Status==1)
    {
        for(int i=0;i<6;i++){
            if(Value.at(i)=="1"){
                List.value(i)->click();
            }
        }
        AllSpot_Status=0;
        emit RadioBroadcast("ZB20500001");
    }
}
