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
    ui->label_11->setText("吊灯--"+QString::number(ui->ChanStackedWidget->currentIndex()));
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
    //---
    SpotInstructionSet(1,0);
    //------timer
    AutoTime=new QTimer(this);
    connect(AutoTime,&QTimer::timeout,this,&LightSystem::AutoMode);


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
        XProgressBar[i]->setRange(0,100);
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

    QString SendData="ZB20301";//亮度--最后一位是校验位
    QString CurrentLed= ui->SelectedLed->text();
    QString SetTemp=ui->Brightness_Text->text();
    if(SetTemp.toInt()>=99)
    {
        SetTemp="99";
    }
    QString WxData="Auxiliary_Bright_";
    if(LuxFalg==1){
        CurrentLed="0";
        for(int i=0;i<7;i++)
        {
            WxData.insert(WxData.length(),QString::number(i));
            emit SendToWx(WxData,SetTemp.toInt()*1.02);
            WxData.remove(WxData.length()-1,WxData.length());
        }
    }
    else {
        WxData.insert(WxData.length(),CurrentLed);
        emit SendToWx(WxData,SetTemp.toInt()*1.02);
    }
    SendData.insert(6,CurrentLed);
    if(SetTemp.toInt()<10)
    {
        SetTemp.insert(0,"0");
    }
    SendData.insert(7,SetTemp);
    emit RadioBroadcast(SendData);
}

void LightSystem::Trigger_ColorQslider()
{
    QString SendData="ZB20101";//色温
    QString SetTemp=ui->Color_Text->text();
    QString CurrentLed= ui->SelectedLed->text();
    QString WxData="Auxiliary_Color_";
    if(SetTemp.toInt()>=99)
    {
        SetTemp="99";
    }
    if (ColorFalg==1) {//是否全部灯一起开
        CurrentLed="0";
        for(int i=0;i<7;i++)
        {
            WxData.insert(WxData.length(),QString::number(i));
            emit SendToWx(WxData,SetTemp.toInt()*1.02);
            WxData.remove(WxData.length()-1,WxData.length());
        }
        qDebug()<<"test--color:"<<SetTemp.toInt()*1.02;
    }
    else {
        WxData.insert(WxData.length(),CurrentLed);
        emit SendToWx(WxData,SetTemp.toInt()*1.02);
    }
    SendData.insert(6,CurrentLed);
    if(SetTemp.toInt()<10)
    {
        SetTemp.insert(0,"0");
    }
    SendData.insert(7,SetTemp);
    emit RadioBroadcast(SendData);
}

void LightSystem::Trigger_DeviceQslider()
{
    QString CurrentLed= ui->SelectedLed->text();
    Status test=data.value(CurrentLed.toInt());
    int Lux =test.GetLux();
    int Color=test.GetColor();
    ui->Brightness_Slider->setValue(Lux);
    ui->Color_Slider->setValue(Color);
//    qDebug()<<"Current:"<<CurrentLed<<"lux:"<<Lux<<"Color:"<<Color;
}



void LightSystem::on_AllLed_Status_clicked()
{
    if(AllLight_Status==0){

        ButtonStyle_Button(ui->AllLed_Status,1,20);
        ButtonStyle_Button(ui->AiMode,8,20);
        ui->AllLed_Status->setStyleSheet("background-color: rgb(0, 0, 0);color:white;border-radius:15px;");
        ui->AllLed_Status->setIcon(QIcon(":/new/Led/Led/AirSwitch-ON.png"));
        ui->Brightness_Slider->setValue(99);
        ui->Lux_All->setChecked(1);
        Trigger_BrightnessQslider();//发送信息去微信

        if(status.GetMessage("Chandelier1")=="0"){
            ui->ChandelierSwitch1->click();
            qDebug()<<"test----"<<status.GetMessage("Chandelier1");
        }
        if(AllSpot_Status==0){
            ui->SpotAll->click();
        }
        emit RadioBroadcast("ZB20000011");
        AllLight_Status=1;

    }
    else {
        ButtonStyle_Button(ui->AllLed_Status,8,20);
        ButtonStyle_Button(ui->AiMode,8,20);
        ui->AllLed_Status->setStyleSheet("background-color: rgb(255, 255, 255);color:white;border-radius:15px;");
        ui->AllLed_Status->setIcon(QIcon(":/new/Led/Led/All_Light_OFF.png"));
        ui->Brightness_Slider->setValue(0);
        Trigger_BrightnessQslider();//发送信息去微信
        qDebug()<<"Lux----all";
        ui->Lux_All->setChecked(0);
        ui->Color_All->setChecked(0);
        if(status.GetMessage("Chandelier1")=="1"){
            ui->ChandelierSwitch1->click();
        }
        if(AllSpot_Status==1){
            ui->SpotAll->click();
        }
        emit RadioBroadcast("ZB20000001");
        AllLight_Status=0;
    }

}

void LightSystem::on_AiMode_clicked()
{
    if(AiMode_Falg==0){
        ui->AiMode->setIcon(QIcon(":/new/Led/Led/AI_OFF.png"));
        ui->AiMode->setStyleSheet("background-color: rgb(0, 0, 0);color:black; border-radius:15px;");
        qDebug()<<"innn-----aimode-flag";
        AiMode_Falg=1;
    }
    else {
        ui->AiMode->setIcon(QIcon(":/new/Led/Led/AI_ON.png"));
        ui->AiMode->setStyleSheet("background-color: rgb(255, 255, 255);color:black; border-radius:15px;");
        qDebug()<<"innn-----aimode-flag--off";
        AiMode_Falg=0;
    }
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
    qDebug()<<"innnn---light"<<Function<<Sub<<Value;
    int SelectNumber=ui->SelectedLed->text().toInt();

    QString SpotMeet1=status.GetMessage("SpotMeet1");
    QString SpotMeet2=status.GetMessage("SpotMeet2");
    QString SpotBar1=status.GetMessage("SpotBar1");
    QString SpotBar2=status.GetMessage("SpotBar2");
    QString SpotOffice1=status.GetMessage("SpotOffice1");
    QString SpotOffice2=status.GetMessage("SpotOffice2");

    QList<QPushButton*> SpotButton;//建立button的list
    QMap<int,QPushButton*> SpotList;//对应
    SpotButton<<ui->SpotMeet1<<ui->SpotMeet2<<ui->SpotBar1<<ui->SpotBar2<<ui->SpotOffice1<<ui->SpotOffice2;
    QList<QString>SpotValue ;
    SpotValue<<SpotMeet1<<SpotMeet2<<SpotBar1<<SpotBar2<<SpotOffice1<<SpotOffice2;

    for(int i=0;i<6;i++){
        SpotList.insert(i,SpotButton.at(i));
    }
    //--------------------------------------------------------------
    QString LedMeet1=status.GetMessage("LedMeet1");
    QString LedMeet2=status.GetMessage("LedMeet2");
    QString LedBar1=status.GetMessage("LedBar1");
    QString LedBar2=status.GetMessage("LedBar2");
    QString LedOffice1=status.GetMessage("LedOffice1");
    QString LedOffice2=status.GetMessage("LedOffice2");

    QList<QPushButton*> LedButton;//建立button的list
    QMap<int,QPushButton*> LedList;//对应
    LedButton<<ui->LedMeet1<<ui->LedMeet2<<ui->LedBar1<<ui->LedBar2<<ui->LedOffice1<<ui->LedOffice2;
    QList<QString>LedValue ;
    LedValue<<LedMeet1<<LedMeet2<<LedBar1<<LedBar2<<LedOffice1<<LedOffice2;

    for(int i=0;i<6;i++){
        LedList.insert(i,LedButton.at(i));
    }
    //-----------Qslier拖动
    if(Function!=0){
        switch (Function) {
        case 1://本来是给调整颜色与亮度的

            break;
        case 3:

            break;
        case 4://吊灯
            switch(Sub)
            {
            case 1:
                if(Value<4){
                    switch(Value)
                    {
                    case 1:
                        ui->ChandeUp1->click();
                        break;
                    case 2:
                        ui->ChandeDown1->click();
                        break;
                    case 3:
                        ui->ChandeStop1->click();
                        break;
                    }
                }
                else {
                    if(status.GetMessage("Chandelier1")!=QString::number(Value))
                    {
                        qDebug()<<"innnn--switch-Change"<<status.GetMessage("Chandelier1");
                        if(Value==4)
                        {
                            status.InsertMessage("Chandelier1","1");
                        }
                        else if (Value==5) {
                            status.InsertMessage("Chandelier1","0");
                        }

                        ui->ChandelierSwitch1->click();
                    }
                }
                break;
            case 2:
                if(status.GetMessage("Chandelier2")!=QString::number(Value))
                {
                    status.InsertMessage("Chandelier2",QString::number(Value));
                    ui->ChandelierSwitch2->click();
                }
                break;
            }
            break;
        case 5://射灯
            switch(Sub)
            {
            case 0:
                SpotStopFalg=1;//停止广播
                switch(Value)
                {
                case 0:
                    for(int i=0;i<6;i++){
                        if(SpotValue.at(i)=="1"){
                            SpotList.value(i)->click();
                        }
                    }
                    emit RadioBroadcast("ZB20500001");
                    emit SendToWx("SpotLight_0",0);
                    break;
                case 1:
                    for(int i=0;i<6;i++){
                        if(SpotValue.at(i)=="0"){
                            SpotList.value(i)->click();
                        }
                    }
                    emit SendToWx("SpotLight_0",1);
                    emit RadioBroadcast("ZB20500011");
                    break;
                }
                SpotStopFalg=0;
                break;
            case 1:
                if(status.GetMessage("SpotMeet1")!=QString::number(Value))
                {
                    ui->SpotMeet1->click();
                }
                break;
            case 2:
                if(status.GetMessage("SpotMeet2")!=QString::number(Value))
                {
                    ui->SpotMeet2->click();
                }
                break;
            case 3:
                if(status.GetMessage("SpotBar1")!=QString::number(Value))
                {
                    ui->SpotBar1->click();
                }
                break;
            case 4:
                if(status.GetMessage("SpotBar2")!=QString::number(Value))
                {
                    ui->SpotBar2->click();
                }
                break;
            case 5:
                if(status.GetMessage("SpotOffice1")!=QString::number(Value))
                {
                    ui->SpotOffice1->click();
                }
                break;
            case 6:
                if(status.GetMessage("SpotOffice2")!=QString::number(Value))
                {
                    ui->SpotOffice2->click();
                }
                break;
            }
            break;
        case 6://主灯
            switch (Sub) {
            case 0:
                LedStopFlag=1;
                if(AllLed_Status==0){
                    for(int i=0;i<6;i++){
                        if(LedValue.at(i)=="0"){
                            LedList.value(i)->click();
                        }
                    }
                    emit RadioBroadcast("ZB20600011");
                    emit SendToWx("All_Led_0",1);
                    AllLed_Status=1;
                }
                else if(AllLed_Status==1)
                {
                    for(int i=0;i<6;i++){
                        if(LedValue.at(i)=="1"){
                            LedList.value(i)->click();
                        }
                    }
                    emit RadioBroadcast("ZB20600001");
                    emit SendToWx("All_Led_0",0);
                    AllLed_Status=0;
                }
                LedStopFlag=0;
                break;
            case 1:
                if(status.GetMessage("LedMeet1")!=QString::number(Value))
                {
                    ui->LedMeet1->click();
                }
                break;
            case 2:
                if(status.GetMessage("LedMeet2")!=QString::number(Value))
                {
                    ui->LedMeet2->click();
                }
                break;
            case 3:
                if(status.GetMessage("LedBar1")!=QString::number(Value))
                {
                    ui->LedBar1->click();
                }
                break;
            case 4:
                if(status.GetMessage("LedBar2")!=QString::number(Value))
                {
                    ui->LedBar2->click();
                }
                break;
            case 5:
                if(status.GetMessage("LedOffice1")!=QString::number(Value))
                {
                    ui->LedOffice1->click();
                }
                break;
            case 6:
                if(status.GetMessage("LedOffice2")!=QString::number(Value))
                {
                    ui->LedOffice2->click();
                }
                break;
            }
            break;
        }
        //-------------全开/关
        if(Function==1||Function==3){
            if(Sub==0){
                Status DataMap;
                switch (Function) {
                case 1:
                    for(int i=1;i<=6;i++){
                        DataMap=data.value(i);
                        DataMap.SetColor(Value*1.02);
                    }
                    ui->Color_All->setChecked(1);
                    InstructionSet(Function,Value*1.02);
                    Trigger_ColorQslider();
                    break;
                case 3:
                    for(int i=1;i<=6;i++){
                        DataMap=data.value(i);
                        DataMap.SetLux(Value*1.02);
                    }
                    ui->Lux_All->setChecked(1);
                    InstructionSet(Function,Value*1.02);
                    Trigger_BrightnessQslider();
                    qDebug()<<"innnn---Bright";
                    break;
                }
            }
            else {
                Status DataMap;
                DataMap=data.value(Sub);//
                if(DataMap.GetLux()!=Value+1||DataMap.GetColor()!=Value+1){
                    switch (Function) {//测试测试
                    case 1:
                        DataMap.SetColor(Value+1);
                        break;
                    case 3:
                        DataMap.SetLux(Value+1);
                        break;
                    }
                    data.insert(Sub,status);//存入map中
                    //----发送到服务器
                    QString SendData,WxData,StringValue;
                    StringValue=QString::number(Value);
                    qDebug()<<"StringValue"<<StringValue;
                    switch (Function) {
                    case 1:
                        //----发送到服务器
                        SendData="ZB20101";//色温
                        WxData="Auxiliary_Color_";
                        WxData.insert(WxData.length(),QString::number(Sub));
                        emit SendToWx(WxData,Value*1.02);//区间0-99 0-100
                        break;
                    case 3:
                        SendData ="ZB20301";//亮度
                        WxData="Auxiliary_Bright_";
                        WxData.insert(WxData.length(),QString::number(Sub));
                        emit SendToWx(WxData,Value*1.02);//区间0-99 0-100
                        qDebug()<<"Value"<<Value*1.02;
                        break;
                    }
                    SendData.insert(6,QString::number(Sub));
                    if(StringValue.toInt()<10)
                    {
                        StringValue.insert(0,"0");
                    }
                    SendData.insert(7,StringValue);
                    emit RadioBroadcast(SendData);
                    //-------
                    if(Sub==SelectNumber)
                    {
                        qDebug()<<"符合当前的";
                        InstructionSet(Function,Value*1.02);
                    }
                }
            }
        }

    }else {
        qDebug()<<"全部灯都开启---------------------------------------------";
        if(Value==1){
            AllLight_Status=0;
            ui->AllLed_Status->click();
        }
        else{
            AllLight_Status=1;
            ui->AllLed_Status->click();
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

void LightSystem::SpotInstructionSet(int sub,int value)
{
    if(SpotStopFalg==0){
        QString data="ZB205001";
        data.insert(6,QString::number(sub));
        data.insert(data.length()-1,QString::number(value));
        emit RadioBroadcast(data);
    }
}

void LightSystem::LedInstructionSet(int sub,int value)
{
    if(LedStopFlag==0){
        QString data="ZB206001";
        data.insert(6,QString::number(sub));
        data.insert(data.length()-1,QString::number(value));
        emit RadioBroadcast(data);
    }
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
    emit RadioBroadcast("ZB20402021");
    emit SendToWx("ChanderierStation2",2);

}

void LightSystem::on_ChandeStop2_clicked()
{
    ButtonStyle_Chandelier_2("ChandeStop2",1);
    emit RadioBroadcast("ZB20402031");
    emit SendToWx("ChanderierStation2",3);
}

void LightSystem::on_ChandeUp2_clicked()
{
    ButtonStyle_Chandelier_2("ChandeUp2",1);
    emit RadioBroadcast("ZB20402011");
    emit SendToWx("ChanderierStation2",1);
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
    emit SendToWx("ChanderierStation1",2);
}

void LightSystem::on_ChandeStop1_clicked()
{
    ButtonStyle_Chandelier_1("ChandeStop1",1);
    emit RadioBroadcast("ZB20401031");
    emit SendToWx("ChanderierStation1",3);
}

void LightSystem::on_ChandeUp1_clicked()
{
    ButtonStyle_Chandelier_1("ChandeUp1",1);
    emit RadioBroadcast("ZB20401011");
    emit SendToWx("ChanderierStation1",1);
}

void LightSystem::on_ChandelierSwitch1_clicked()
{
    QString Status=status.GetMessage("Chandelier1");
    qDebug()<<"ChandelierSwitch1_clicked:"<<Status;
    switch (Status.toInt()) {
    case 0:
        ButtonStyle_Button(ui->ChandelierSwitch1,1,25);
        ui->ChandelierSwitch1->setStyleSheet("background-color: rgb(0, 0, 0);color:black; border-radius:15px;");
        status.InsertMessage("Chandelier1","1");//变量储存
        emit RadioBroadcast("ZB20401051");
        emit SendToWx("Chandelier1",1);//微信
        qDebug()<<"innnnn----";
        break;
    case 1:
        ButtonStyle_Button(ui->ChandelierSwitch1,8,25);
        ui->ChandelierSwitch1->setStyleSheet("background-color: rgb(255, 255, 255);color:white; border-radius:15px;");
        status.InsertMessage("Chandelier1","0");
        emit RadioBroadcast("ZB20401041");
        emit SendToWx("Chandelier1",0);//微信
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
        emit SendToWx("Chandelier2",1);//微信
        break;
    case 1:
        ButtonStyle_Button(ui->ChandelierSwitch2,8,25);
        ui->ChandelierSwitch2->setStyleSheet("background-color: rgb(255, 255, 255);color:white; border-radius:15px;");
        status.InsertMessage("Chandelier2","0");
        emit RadioBroadcast("ZB20402041");
        emit SendToWx("Chandelier2",0);//微信
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
        SpotInstructionSet(1,1);
        emit SendToWx("SpotMeet1",1);//微信
        break;
    case 1:
        ButtonStyle_Button(ui->SpotMeet1,8,25);
        ui->SpotMeet1->setStyleSheet("background-color: rgb(255, 255, 255);color:white; border-radius:15px;");
        status.InsertMessage("SpotMeet1","0");
        SpotInstructionSet(1,0);
        emit SendToWx("SpotMeet1",0);//微信
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
        SpotInstructionSet(2,1);
        emit SendToWx("SpotMeet2",1);//微信
        break;
    case 1:
        ButtonStyle_Button(ui->SpotMeet2,8,25);
        ui->SpotMeet2->setStyleSheet("background-color: rgb(255, 255, 255);color:white; border-radius:15px;");
        status.InsertMessage("SpotMeet2","0");
        SpotInstructionSet(2,0);
        emit SendToWx("SpotMeet2",0);//微信
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
        SpotInstructionSet(5,1);
        emit SendToWx("SpotOffice1",1);//微信
        break;
    case 1:
        ButtonStyle_Button(ui->SpotOffice1,8,25);
        ui->SpotOffice1->setStyleSheet("background-color: rgb(255, 255, 255);color:white; border-radius:15px;");
        status.InsertMessage("SpotOffice1","0");
        SpotInstructionSet(5,0);
        emit SendToWx("SpotOffice1",0);//微信
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
        SpotInstructionSet(6,1);
        emit SendToWx("SpotOffice2",1);//微信
        break;
    case 1:
        ButtonStyle_Button(ui->SpotOffice2,8,25);
        ui->SpotOffice2->setStyleSheet("background-color: rgb(255, 255, 255);color:white; border-radius:15px;");
        status.InsertMessage("SpotOffice2","0");
        SpotInstructionSet(6,0);
        emit SendToWx("SpotOffice2",0);//微信
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
        SpotInstructionSet(3,1);
        emit SendToWx("SpotBar1",1);//微信
        break;
    case 1:
        ButtonStyle_Button(ui->SpotBar1,8,25);
        ui->SpotBar1->setStyleSheet("background-color: rgb(255, 255, 255);color:white; border-radius:15px;");
        status.InsertMessage("SpotBar1","0");
        SpotInstructionSet(3,0);
        emit SendToWx("SpotBar1",0);//微信
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
        SpotInstructionSet(4,1);
        emit SendToWx("SpotBar2",1);//微信
        break;
    case 1:
        ButtonStyle_Button(ui->SpotBar2,8,25);
        ui->SpotBar2->setStyleSheet("background-color: rgb(255, 255, 255);color:white; border-radius:15px;");
        status.InsertMessage("SpotBar2","0");
        SpotInstructionSet(4,0);
        emit SendToWx("SpotBar2",0);//微信
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
        emit SendToWx("LedMeet1",1);//微信
        LedInstructionSet(1,1);
        break;
    case 1:
        ButtonStyle_Button(ui->LedMeet1,8,25);
        ui->LedMeet1->setStyleSheet("background-color: rgb(255, 255, 255);color:white; border-radius:15px;");
        status.InsertMessage("LedMeet1","0");
        emit SendToWx("LedMeet1",0);//微信
        LedInstructionSet(1,0);
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
        LedInstructionSet(2,1);
        emit SendToWx("LedMeet2",1);//微信
        break;
    case 1:
        ButtonStyle_Button(ui->LedMeet2,8,25);
        ui->LedMeet2->setStyleSheet("background-color: rgb(255, 255, 255);color:white; border-radius:15px;");
        status.InsertMessage("LedMeet2","0");
        LedInstructionSet(2,0);
        emit SendToWx("LedMeet2",0);//微信
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
        LedInstructionSet(3,1);
        emit SendToWx("LedBar1",1);//微信
        break;
    case 1:
        ButtonStyle_Button(ui->LedBar1,8,25);
        ui->LedBar1->setStyleSheet("background-color: rgb(255, 255, 255);color:white; border-radius:15px;");
        status.InsertMessage("LedBar1","0");
        LedInstructionSet(3,0);
        emit SendToWx("LedBar1",0);//微信
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
        emit SendToWx("LedBar2",1);//微信
        LedInstructionSet(4,1);
        break;
    case 1:
        ButtonStyle_Button(ui->LedBar2,8,25);
        ui->LedBar2->setStyleSheet("background-color: rgb(255, 255, 255);color:white; border-radius:15px;");
        status.InsertMessage("LedBar2","0");
        emit SendToWx("LedBar2",0);//微信
        LedInstructionSet(4,0);
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
        LedInstructionSet(5,1);
        emit SendToWx("LedOffice1",1);//微信
        break;
    case 1:
        ButtonStyle_Button(ui->LedOffice1,8,25);
        ui->LedOffice1->setStyleSheet("background-color: rgb(255, 255, 255);color:white; border-radius:15px;");
        status.InsertMessage("LedOffice1","0");
        LedInstructionSet(5,0);
        emit SendToWx("LedOffice1",0);//微信
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
        LedInstructionSet(6,1);
        emit SendToWx("LedOffice2",1);//微信
        break;
    case 1:
        ButtonStyle_Button(ui->LedOffice2,8,25);
        ui->LedOffice2->setStyleSheet("background-color: rgb(255, 255, 255);color:white; border-radius:15px;");
        status.InsertMessage("LedOffice2","0");
        LedInstructionSet(6,0);
        emit SendToWx("LedOffice2",0);//微信
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
    LedStopFlag=1;
    if(AllLed_Status==0){
        for(int i=0;i<6;i++){
            if(Value.at(i)=="0"){
                List.value(i)->click();
            }
        }
        emit RadioBroadcast("ZB20600011");
        emit SendToWx("All_Led_0",1);
        AllLed_Status=1;
    }
    else if(AllLed_Status==1)
    {
        for(int i=0;i<6;i++){
            if(Value.at(i)=="1"){
                List.value(i)->click();
            }
        }
        emit RadioBroadcast("ZB20600001");
        emit SendToWx("All_Led_0",0);
        AllLed_Status=0;
    }
    LedStopFlag=0;
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

    SpotStopFalg=1;//停止广播
    if(AllSpot_Status==0){
        for(int i=0;i<6;i++){
            if(Value.at(i)=="0"){
                List.value(i)->click();
            }
        }
        emit RadioBroadcast("ZB20500011");
        emit SendToWx("SpotLight_0",1);
        AllSpot_Status=1;
    }
    else if(AllSpot_Status==1)
    {
        for(int i=0;i<6;i++){
            if(Value.at(i)=="1"){
                List.value(i)->click();
            }
        }
        emit RadioBroadcast("ZB20500001");
        emit SendToWx("SpotLight_0",0);
        AllSpot_Status=0;
    }
    SpotStopFalg=0;
}

void LightSystem::AutoMode()
{
    if(AiMode_Falg==1){
        QTime CurrentTime = QTime::currentTime();
        int Hour=CurrentTime.hour();
        //    qDebug()<<"当前时间："<<Hour;
        if (Hour<12&&Hour>=7) {//上天
            qDebug()<<"上午"<<Hour;
            WorkTime=1;
            AuxiliaryLightLogic();//辅灯
            SpotLightLogic();//射灯
            //--------色温
            ui->Color_All->setChecked(1);
            ui->Color_Slider->setValue(30);
            Trigger_ColorQslider();
        }
        else if(Hour>=12&&Hour<14){//中午
            MiddayFalg=1;
            WorkTime=1;
            AuxiliaryLightLogic();
            SpotLightLogic();
            //--------色温
            ui->Color_All->setChecked(1);
            ui->Color_Slider->setValue(60);
            Trigger_ColorQslider();
        }
        else if(Hour>=14&&Hour<20){//下午
            MiddayFalg=0;
            WorkTime=1;
            SpotLightLogic();

            AuxiliaryLightLogic();

            //--------色温
            ui->Color_All->setChecked(1);
            ui->Color_Slider->setValue(10);
            Trigger_ColorQslider();
        }
        else {//下班
            WorkTime=0;
            SpotLightLogic();//射灯
            if(status.GetMessage("Chandelier1")!="5"){//关闭吧台吊灯
                status.InsertMessage("Chandelier1","5");
                ui->ChandelierSwitch1->click();
            }
            //----亮度
            ui->Lux_All->setChecked(1);
            ui->Brightness_Slider->setValue(0);//关闭所有副灯
            Trigger_BrightnessQslider();
            //--------色温
            ui->Color_All->setChecked(1);
            ui->Color_Slider->setValue(80);
            Trigger_ColorQslider();
        }
    }
}

void LightSystem::AuxiliaryLightLogic()//先判断有无人----->再判断传感器输入亮度等级
{
    int Result;
    int Difference;
    //-------------------判断会议区是是否有人
    if(locationMissing==1){

        if(MiddayFalg!=1){
            //            if(LuxMissing<=460){
            if(LuxMissing<=460){
                qDebug()<<"innnnn---chandelier2---";
                if(status.GetMessage("Chandelier2")!="1"){//如果现在不是关着的话，则先写入
                    status.InsertMessage("Chandelier2","0");
                    // on_ChandelierSwitch2_clicked();
                    ui->ChandelierSwitch2->click();
                }
            }
            for(int i=1;i<=3;i++){
                ui->Device_Slider->setValue(i);
                Trigger_DeviceQslider();
                Difference=460-LuxMissing;
                Result=Difference/0.8;
                LatestMeeting=LatestMeeting+Result;
                ui->Brightness_Slider->setValue(LatestMeeting);
                Trigger_BrightnessQslider();
            }
            qDebug()<<"会议区--------------------innnn--不是中午";
            //            }
        }
        else {
            if(status.GetMessage("Chandelier2")!="0"){//如果现在不是关着的话，则先写入
                status.InsertMessage("Chandelier2","1");
                // on_ChandelierSwitch2_clicked();
                ui->ChandelierSwitch2->click();
            }
            for(int i=1;i<=3;i++){
                ui->Device_Slider->setValue(i);
                Trigger_DeviceQslider();
                ui->Brightness_Slider->setValue(20);
                Trigger_BrightnessQslider();
            }
            qDebug()<<"会议区--------------------innnn--是中午";
        }
    }else{
        //------会议区-----下班了
        if(status.GetMessage("Chandelier2")!="0"){//如果现在不是关着的话，则先写入
            status.InsertMessage("Chandelier2","1");
            // on_ChandelierSwitch2_clicked();
            ui->ChandelierSwitch2->click();
        }
        for(int i=1;i<=3;i++){
            ui->Device_Slider->setValue(i);
            Trigger_DeviceQslider();
            ui->Brightness_Slider->setValue(0);
            Trigger_BrightnessQslider();
        }
    }
    //-------------------判断吧台是是否有人
    if(locationBar==1){
        qDebug()<<"吧台有人--------";
        ui->Lux_All->setChecked(0);
        if(MiddayFalg!=1){
            qDebug()<<"当前吊灯状态------"<<status.GetMessage("Chandelier1");
            if(status.GetMessage("Chandelier1")!="1"){//如果现在不是开着的话，则先写入
                status.InsertMessage("Chandelier1","0");
                ui->ChandelierSwitch1->click();
            }
        }
        else {
            qDebug()<<"当前吊灯状态------"<<status.GetMessage("Chandelier1");
            if(status.GetMessage("Chandelier1")!="0"){//如果现在不是开着的话，则先写入
                status.InsertMessage("Chandelier1","1");
                ui->ChandelierSwitch1->click();
            }
        }
    }
    else{
        qDebug()<<"吧台没有人--------";
        //----吊灯
        qDebug()<<"当前吊灯状态------"<<status.GetMessage("Chandelier1");
        if(status.GetMessage("Chandelier1")!="0"){//如果现在不是开着的话，则先写入
            status.InsertMessage("Chandelier1","1");
            ui->ChandelierSwitch1->click();
        }
    }
    //-------------------判断办公区是是否有人
    if(locationOffice==1){
        ui->Lux_All->setChecked(0);//取消所有的灯光的控制
        ui->Device_Slider->setValue(4);
        Trigger_DeviceQslider();
        if(MiddayFalg!=1){
            Difference=212-LuxBarAndOffice;
            Result=Difference/0.4;
            qDebug()<<"LatestBarAndOffice--1:"<<LatestBarAndOffice;
            LatestBarAndOffice=LatestBarAndOffice+Result;
            qDebug()<<"LatestBarAndOffice----2:"<<LatestBarAndOffice;
            ui->Brightness_Slider->setValue(LatestBarAndOffice);
            Trigger_BrightnessQslider();
        }
        else {
            ui->Brightness_Slider->setValue(20);
            Trigger_BrightnessQslider();
        }
    }
    else{
        ui->Device_Slider->setValue(4);
        Trigger_DeviceQslider();
        ui->Brightness_Slider->setValue(0);
        Trigger_BrightnessQslider();
    }
    //----------中间两个副灯的判断----办公室和吧台有一个有人就亮
    if(locationBar==1||locationOffice==1){
        qDebug()<<"吧台和辦公室有人--------";
        ui->Lux_All->setChecked(0);
        if(MiddayFalg!=1){
            //-----副灯
            for(int i=5;i<=6;i++){//副灯
                ui->Device_Slider->setValue(i);
                Trigger_DeviceQslider();
//                Difference=212-LuxBarAndOffice;
//                Result=Difference/0.4;
//                LatestBarAndOffice=LatestBarAndOffice+Result;
                ui->Brightness_Slider->setValue(LatestBarAndOffice);
                Trigger_BrightnessQslider();
            }
        }
        else {
            //-----副灯
            for(int i=5;i<=6;i++){//副灯
                ui->Device_Slider->setValue(i);
                Trigger_DeviceQslider();
                ui->Brightness_Slider->setValue(20);
                Trigger_BrightnessQslider();
            }
        }
    }
    else{
        qDebug()<<"吧台和办公室没有人--------";
        //-----副灯
        for(int i=5;i<=6;i++){//副灯
            ui->Device_Slider->setValue(i);
            Trigger_DeviceQslider();
            ui->Brightness_Slider->setValue(0);
            Trigger_BrightnessQslider();
        }
    }
    LatestBarAndOffice=0;
    LatestMeeting=0;

}

void LightSystem::SpotLightLogic()
{
    QString SpotMeet1=status.GetMessage("SpotMeet1");
    QString SpotMeet2=status.GetMessage("SpotMeet2");
    QString SpotBar1=status.GetMessage("SpotBar1");
    QString SpotBar2=status.GetMessage("SpotBar2");
    QString SpotOffice1=status.GetMessage("SpotOffice1");
    QString SpotOffice2=status.GetMessage("SpotOffice2");

    QList<QPushButton*> SpotButton;//建立button的list
    QMap<int,QPushButton*> SpotList;//对应
    SpotButton<<ui->SpotMeet1<<ui->SpotMeet2<<ui->SpotBar1<<ui->SpotBar2<<ui->SpotOffice1<<ui->SpotOffice2;
    QList<QString>SpotValue ;
    SpotValue<<SpotMeet1<<SpotMeet2<<SpotBar1<<SpotBar2<<SpotOffice1<<SpotOffice2;

    for(int i=0;i<6;i++){
        SpotList.insert(i,SpotButton.at(i));
    }
    SpotStopFalg=1;
    if(MiddayFalg!=1&&WorkTime==1){//非中午时间段
        if (OutsideWeather==1) {

            AllSpot_Status=1;
            ui->SpotAll->click();

        }else {
            AllSpot_Status=0;
            ui->SpotAll->click();
        }
    }
    else if(MiddayFalg==1||WorkTime==0){//中午时间段
        AllSpot_Status=1;
        ui->SpotAll->click();
    }
    SpotStopFalg=0;
}

void LightSystem::GetWeather(int Weather)
{
    OutsideWeather=Weather;
}

void LightSystem::Location_Sync(int sub, int value)
{
    switch (sub) {
    case 1:
        locationMissing=value;
        break;
    case 2:
        locationBar=value;
        break;
    case 3:
        locationOffice=value;
        break;
    }
    if(locationMissing==1||locationBar==1||locationOffice==1){
        AutoMode();
//        if(StopTest==0){
//            AutoTime->start(10000);
//            StopTest=1;
//        }
    }
    else if(locationMissing==0&&locationBar==0&&locationOffice==0){
        AutoMode();
//        if(StopTest==1){
//            AutoTime->stop();
//        }
    }
    qDebug()<<"Light--sync"<<"locationMissing:"<<locationMissing<<"locationBar:"<<locationBar<<"locationOffice:"<<locationOffice;
}

void LightSystem::Lux_Sync(int sub, int value)
{
    switch (sub) {
    case 1:
        LuxMissing=value;
        break;
    case 2:
        LuxBarAndOffice=value;
        break;
    }
    AutoMode();
    ui->CurtainNumber->setText(QString::number(LuxMissing));
    qDebug()<<"LuxMissing:"<<LuxMissing<<"LuxBarAndOffice:"<<LuxBarAndOffice;
}
