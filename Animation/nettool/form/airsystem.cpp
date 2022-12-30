#include "airsystem.h"
#include "ui_airsystem.h"
#include<QGraphicsDropShadowEffect>

AirSystem::AirSystem(QWidget *parent) :
    QDialog(parent,Qt::WindowTitleHint | Qt::CustomizeWindowHint),
    ui(new Ui::AirSystem)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint | Qt::CustomizeWindowHint);
   // this->setWindowFlags(Qt::FramelessWindowHint | Qt::Tool);
   // this->setAttribute(Qt::WA_AcceptTouchEvents,true);
    Switch_Ifconfig();
    Shawdow();
    qRegisterMetaType<Data>("Data");
    data={0,26,0,0,1,1};
    connect(ui->SwingUpDown,&SwitchButton::checkedChanged,this,&AirSystem::SwitchButton_U_D);
    connect(ui->SwingLeftRight,&SwitchButton::checkedChanged,this,&AirSystem::SwitchButton_L_R);
    connect(ui->TempQslider,&QSlider::sliderReleased,this,&AirSystem::Trigger_TempQslider);
    AutoTime=new QTimer(this);
    connect(AutoTime,&QTimer::timeout,this,&AirSystem::AutoMode);
    ui->FunctionPanel->setEnabled(0);
    Image_Init();
}

AirSystem::~AirSystem()
{
    delete ui;
}

void AirSystem::Switch_Ifconfig()
{
    QList <SwitchButton*> Switch;
    Switch<<ui->SwingLeftRight<<ui->SwingUpDown;
    for(int i=0;i<Switch.length();i++)
    {
        Switch[i]->setSpace(15);
        Switch[i]->setRectRadius(15);
        Switch[i]->setShowText(false);
        Switch[i]->setAnimation(true);
    }
}

void AirSystem::Shawdow()
{
    ButtonStyle_Button(ui->AirSwitch,8,25);
    ButtonStyle_Label(ui->AirMode,8,25);

    QGraphicsDropShadowEffect *AirTemp = new QGraphicsDropShadowEffect(this);
    AirTemp->setOffset(8);
    AirTemp->setColor(/*Qt::gray*/QColor(43, 43, 43));
    AirTemp->setBlurRadius(25);
    ui->AirTemp->setGraphicsEffect(AirTemp);


    QGraphicsDropShadowEffect *bottom = new QGraphicsDropShadowEffect(this);
    bottom->setOffset(15);
    bottom->setColor(/*Qt::gray*/QColor(43, 43, 43));
    bottom->setBlurRadius(25);
    ui->bottom->setGraphicsEffect(bottom);//

    QGraphicsDropShadowEffect *Group_Mode = new QGraphicsDropShadowEffect(this);
    Group_Mode->setOffset(8);
    Group_Mode->setColor(/*Qt::gray*/QColor(43, 43, 43));
    Group_Mode->setBlurRadius(35);
    ui->Group_Mode->setGraphicsEffect(Group_Mode);

    QGraphicsDropShadowEffect *Group_Fan = new QGraphicsDropShadowEffect(this);
    Group_Fan->setOffset(8);
    Group_Fan->setColor(/*Qt::gray*/QColor(43, 43, 43));
    Group_Fan->setBlurRadius(35);
    ui->Group_Fan->setGraphicsEffect(Group_Fan);

    QGraphicsDropShadowEffect *AutoMode = new QGraphicsDropShadowEffect(this);
    AutoMode->setOffset(8);
    AutoMode->setColor(/*Qt::gray*/QColor(43, 43, 43));
    AutoMode->setBlurRadius(35);
    ui->AutoSwitch->setGraphicsEffect(AutoMode);
}

void AirSystem::ReceiveData(Data VarValue,int Value)//从分控接受后--界面更新
{
    data=VarValue;
    //    qDebug()<<"AirReceiveData";
    //    if(data.Station==1){

    //        if(Flag_AirSwitch!=0){
    //            on_AirSwitch_clicked();//按下按钮---做阴影特性
    //        }
    //    }
    //    else if(data.Station==0)
    //    {
    //        if(Flag_AirSwitch!=1){
    //            on_AirSwitch_clicked();
    //        }
    //        ButtonClear(3);
    //    }
    qDebug()<<"Air---station"<<Value;
    if(Value<16){
        switch (Value) {
        case 0:
            if(Flag_AirSwitch==1){
                ui->AirSwitch->click();
            }
            break;
        case 1:
            if(Flag_AirSwitch==0){
                ui->AirSwitch->click();
            }
            break;
        case 2://"Low"
            ui->Fan_Low->click();
            break;
        case 3://"Mid"
            ui->Fan_Mid->click();
            break;
        case 4://"High"
            ui->Fan_High->click();
            break;
        case 5:
            ui->SwingLeftRight->setChecked(1);
            break;
        case 6:
            ui->SwingLeftRight->setChecked(0);
            break;
        case 7:
            ui->SwingUpDown->setChecked(1);
            break;
        case 8:
            ui->SwingUpDown->setChecked(0);
            break;
        case 9://"Cool"
            ui->Cold->click();
            break;
        case 10://"Dry"
            ui->Dry->click();
            break;
        case 11://"Heat"
            ui->Heat->click();
            break;
        case 12://"Auto"
            //data.Mode=0;
            break;
        case 13://"Auto"
            //data.Fan=0;
            break;
        case 14:
            ui->Fan->click();
        case 15:
            break;
        }
    }
    else {
        ui->TempQslider->setValue(Value);
        Trigger_TempQslider();
    }
}

void AirSystem::ButtonClear(int Switch)
{
    switch (Switch) {
    case 1:
        ui->Fan_Low->setStyleSheet("background-color: rgb(255, 255, 255);color:black;max-width:60px;max-height:60px; min-width:60px; min-height:60px; border-radius:30px;");
        ui->Fan_Mid->setStyleSheet("background-color: rgb(255, 255, 255);color:black;max-width:60px;max-height:60px; min-width:60px; min-height:60px; border-radius:30px;");
        ui->Fan_High->setStyleSheet("background-color: rgb(255, 255, 255);color:black;max-width:60px;max-height:60px; min-width:60px; min-height:60px; border-radius:30px;");
        break;
    case 2:
        ui->Heat->setStyleSheet("background-color: rgb(255, 255, 255);color:black;max-width:60px;max-height:60px; min-width:60px; min-height:60px; border-radius:30px;");
        ui->Dry->setStyleSheet("background-color: rgb(255, 255, 255);color:black;max-width:60px;max-height:60px; min-width:60px; min-height:60px; border-radius:30px;");
        ui->Cold->setStyleSheet("background-color: rgb(255, 255, 255);color:black;max-width:60px;max-height:60px; min-width:60px; min-height:60px; border-radius:30px;");
        ui->Fan->setStyleSheet("background-color: rgb(255, 255, 255);color:black;max-width:60px;max-height:60px; min-width:60px; min-height:60px; border-radius:30px;");
        break;
    case 3:
        ui->Fan_Low->setStyleSheet("background-color: rgb(255, 255, 255);color:black;max-width:60px;max-height:60px; min-width:60px; min-height:60px; border-radius:30px;");
        ui->Fan_Mid->setStyleSheet("background-color: rgb(255, 255, 255);color:black;max-width:60px;max-height:60px; min-width:60px; min-height:60px; border-radius:30px;");
        ui->Fan_High->setStyleSheet("background-color: rgb(255, 255, 255);color:black;max-width:60px;max-height:60px; min-width:60px; min-height:60px; border-radius:30px;");
        ui->Heat->setStyleSheet("background-color: rgb(255, 255, 255);color:black;max-width:60px;max-height:60px; min-width:60px; min-height:60px; border-radius:30px;");
        ui->Dry->setStyleSheet("background-color: rgb(255, 255, 255);color:black;max-width:60px;max-height:60px; min-width:60px; min-height:60px; border-radius:30px;");
        ui->Cold->setStyleSheet("background-color: rgb(255, 255, 255);color:black;max-width:60px;max-height:60px; min-width:60px; min-height:60px; border-radius:30px;");
        ui->Fan->setStyleSheet("background-color: rgb(255, 255, 255);color:black;max-width:60px;max-height:60px; min-width:60px; min-height:60px; border-radius:30px;");
        ui->SwingUpDown->setChecked(0);
        ui->SwingLeftRight->setChecked(0);
        break;
    }
}

void AirSystem::Ui_Update()//界面更新
{
    QString Temp=QString::number(data.Temp);
    ui->AirTemp->setText(Temp);//大字显示
    ui->TempQslider->setValue(Temp.toInt());//进度条
    switch (data.Fan) {
    case 0:  break; //自动
    case 1:
        ui->Fan_Low->setStyleSheet("background-color: rgb(0, 0, 0);color:white;max-width:60px;max-height:60px; min-width:60px; min-height:60px; border-radius:30px;");
        ui->Fan_Mid->setStyleSheet("background-color: rgb(255, 255, 255);color:black;max-width:60px;max-height:60px; min-width:60px; min-height:60px; border-radius:30px;");
        ui->Fan_High->setStyleSheet("background-color: rgb(255, 255, 255);color:black;max-width:60px;max-height:60px; min-width:60px; min-height:60px; border-radius:30px;");
        break; //低档
    case 2:
        ui->Fan_Mid->setStyleSheet("background-color: rgb(0, 0, 0);color:white;max-width:60px;max-height:60px; min-width:60px; min-height:60px; border-radius:30px;");
        ui->Fan_Low->setStyleSheet("background-color: rgb(255, 255, 255);color:black;max-width:60px;max-height:60px; min-width:60px; min-height:60px; border-radius:30px;");
        ui->Fan_High->setStyleSheet("background-color: rgb(255, 255, 255);color:black;max-width:60px;max-height:60px; min-width:60px; min-height:60px; border-radius:30px;");
        break; //中档
    case 3:
        ui->Fan_High->setStyleSheet("background-color: rgb(0, 0, 0);color:white;max-width:60px;max-height:60px; min-width:60px; min-height:60px; border-radius:30px;");
        ui->Fan_Low->setStyleSheet("background-color: rgb(255, 255, 255);color:black;max-width:60px;max-height:60px; min-width:60px; min-height:60px; border-radius:30px;");
        ui->Fan_Mid->setStyleSheet("background-color: rgb(255, 255, 255);color:black;max-width:60px;max-height:60px; min-width:60px; min-height:60px; border-radius:30px;");
        break; //高档
    }
    switch(data.Swing_L_R)
    {
    case 0:
        ui->SwingLeftRight->setChecked(0);
        break;
    case 1:
        ui->SwingLeftRight->setChecked(1);
        break;
    }
    switch(data.Swing_U_D)
    {
    case 0:
        ui->SwingUpDown->setChecked(0);
        break;
    case 1:
        ui->SwingUpDown->setChecked(1);
        break;
    }
    switch(data.Mode)
    {
    case 0:  break; //自动
    case 1:
        StyleSheet(2,1,3,0);
        break; //制冷
    case 2:
        StyleSheet(1,2,3,0);
        break; //制热
    case 3:
        StyleSheet(3,2,0,1);
        break; //除湿
    case 4:
        StyleSheet(0,2,3,1);
        break; //送风
    }
}

void AirSystem::SwitchButton_U_D(int Falg)
{
    if(Falg==1)
    {
        SetInstruction(7);

    }
    else {
        SetInstruction(8);

    }
    qDebug()<<"Swing:"<<data.Swing_U_D;
}

void AirSystem::SwitchButton_L_R(int Falg)
{
    if(Falg==1)
    {
        SetInstruction(5);

    }
    else {
        SetInstruction(6);
    }
    qDebug()<<"Swing:"<<data.Swing_L_R;
}

void AirSystem::SetInstruction(int Order)
{
    if(Flag_AirSwitch==0){
        switch (Order) {
        case 0://开关
            emit RadioBroadcast("ZB20201001");
            emit SendToWx("AirStation",0);
            break;
        case 1:
            emit RadioBroadcast("ZB20201011");
            emit SendToWx("AirStation",1);
            break;
        case 2://低速
            emit RadioBroadcast("ZB20201021");
            data.Fan=1;
            emit SendToWx("AirFan",1);
            break;
        case 3://中速
            emit RadioBroadcast("ZB20201031");
            emit SendToWx("AirFan",2);
            data.Fan=2;
            break;
        case 4://高速
            emit RadioBroadcast("ZB20201041");
            emit SendToWx("AirFan",3);
            data.Fan=3;
            break;
        case 5://左右摆风
            emit RadioBroadcast("ZB20201051");
            emit SendToWx("Air_LR",1);
            data.Swing_L_R=1;
            break;
        case 6:
            emit RadioBroadcast("ZB20201061");
            emit SendToWx("Air_LR",0);
            data.Swing_L_R=0;
            break;
        case 7://上下摆风
            emit RadioBroadcast("ZB20201071");
            emit SendToWx("Air_UD",1);
            data.Swing_U_D=1;
            break;
        case 8:
            emit RadioBroadcast("ZB20201081");
            emit SendToWx("Air_UD",0);
            data.Swing_U_D=0;
            break;
        case 9://制冷
            emit RadioBroadcast("ZB20201091");
            emit SendToWx("Air_Mode",1);
            data.Mode=1;
            break;
        case 10://除湿
            emit RadioBroadcast("ZB20201101");
            emit SendToWx("Air_Mode",3);
            data.Mode=3;
            break;
        case 11://暖气
            emit RadioBroadcast("ZB20201111");
            emit SendToWx("Air_Mode",2);
            data.Mode=2;
            break;
        case 12://智能
            emit RadioBroadcast("ZB20201121");
            emit SendToWx("Air_Mode",0);
            data.Mode=0;
            break;
        case 13://风速--自动
            emit RadioBroadcast("ZB20201131");
            emit SendToWx("AirFan",0);
            data.Fan=0;
            break;
        case 14://送风
            emit RadioBroadcast("ZB20201141");
            emit SendToWx("Air_Mode",4);
            data.Mode=4;
            break;
        }
    }

    // emit Class_Update(data);
    //    QString SendData="ZB202011";
    //    SendData.insert(Order,6);
    //    qDebug()<<"SendData:"<<SendData;
}

void AirSystem::Trigger_TempQslider()
{
    QString SendData="ZB202011";
    QString SetTemp=ui->AirTemp->text();
    SendData.insert(7,SetTemp);
    data.Temp=SetTemp.toInt();
    emit RadioBroadcast(SendData);
    emit SendToWx("AirTemp",SetTemp.toInt());
}

void AirSystem::Implement()//保存传过来数据，并执行
{
    switch(data.Station){
    case 0:
        emit RadioBroadcast("ZB20201001");
        emit SendToWx("AirStation",0);
        break;
    case 1:
        emit RadioBroadcast("ZB20201011");
        emit SendToWx("AirStation",1);
        break;
    }
    switch(data.Fan){
    case 0:
        break;
    case 1://低
        emit RadioBroadcast("ZB20201021");
        emit SendToWx("AirFan",1);
        break;
    case 2://中
        emit RadioBroadcast("ZB20201031");
        emit SendToWx("AirFan",2);
        break;
    case 3://高
        emit RadioBroadcast("ZB20201041");
        emit SendToWx("AirFan",3);
        break;
    }
    switch(data.Swing_L_R){
    case 0://左右摆风--关
        emit RadioBroadcast("ZB20201061");
        emit SendToWx("Air_LR",0);
        break;
    case 1://--开
        emit RadioBroadcast("ZB20201051");
        emit SendToWx("Air_LR",1);
        break;
    }
    switch(data.Swing_U_D){
    case 0://上下摆风--关
        emit RadioBroadcast("ZB20201081");
        emit SendToWx("Air_UD",0);
        break;
    case 1://--开
        emit RadioBroadcast("ZB20201071");
        emit SendToWx("Air_UD",1);
        break;
    }
    switch(data.Mode){
    case 0://智能
        emit RadioBroadcast("ZB20201121");
        emit SendToWx("Air_Mode",0);
        break;
    case 1://制冷
        emit RadioBroadcast("ZB20201091");
        emit SendToWx("Air_Mode",1);
        break;
    case 2://暖气
        emit RadioBroadcast("ZB20201111");
        emit SendToWx("Air_Mode",2);
        break;
    case 3://除湿
        emit RadioBroadcast("ZB20201101");
        emit SendToWx("Air_Mode",3);
        break;
    case 4://送风
        emit RadioBroadcast("ZB20201141");
        emit SendToWx("Air_Mode",4);
        break;
    }
    QString SendData="ZB202011";
    QString SetTemp=ui->AirTemp->text();
    SendData.insert(7,SetTemp);
    emit RadioBroadcast(SendData);
}

void AirSystem::GetIndoorAirQuality(int Temp, int Hum)
{
    IndoorTemp=Temp;
    IndoorHum=Hum;
}

void AirSystem::on_BackMain_clicked()
{
    this->close();
    emit SendClose();
}

void AirSystem::on_AirSwitch_clicked()
{
    //--------按键效果
    QGraphicsDropShadowEffect *SetAirSwitch = new QGraphicsDropShadowEffect(this);
    SetAirSwitch->setColor(/*Qt::gray*/QColor(43, 43, 43));
    if(Flag_AirSwitch==0)
    {
        //------阴影---------
        SetAirSwitch->setOffset(1);
        SetAirSwitch->setBlurRadius(35);
        ui->AirSwitch->setGraphicsEffect(SetAirSwitch);
        //-----发到执行器上---
        data.Station=1;
        Implement();
        //-----界面更新--------
        ui->FunctionPanel->setEnabled(1);
        Ui_Update();
        //------重置------
        Flag_AirSwitch=1;

    }
    else if(Flag_AirSwitch==1)
    {
        //----阴影
        SetAirSwitch->setOffset(8);
        SetAirSwitch->setBlurRadius(35);
        ui->AirSwitch->setGraphicsEffect(SetAirSwitch);
        //-----界面更新--------
        Flag_AirSwitch=0;
        data.Station=0;
        ui->FunctionPanel->setEnabled(0);
        ButtonClear(3);
        //-----发到执行器上---
        emit RadioBroadcast("ZB20201001");
        emit SendToWx("AirStation",0);
    }
}

void AirSystem::on_Fan_Low_clicked()
{
    Icon_FanPlan(1);
    ui->Fan_Low->setStyleSheet("background-color: rgb(0, 0, 0);color:white;max-width:60px;max-height:60px; min-width:60px; min-height:60px; border-radius:30px;");
    ui->Fan_Mid->setStyleSheet("background-color: rgb(255, 255, 255);color:black;max-width:60px;max-height:60px; min-width:60px; min-height:60px; border-radius:30px;");
    ui->Fan_High->setStyleSheet("background-color: rgb(255, 255, 255);color:black;max-width:60px;max-height:60px; min-width:60px; min-height:60px; border-radius:30px;");
    SetInstruction(2);
}

void AirSystem::on_Fan_Mid_clicked()
{
    Icon_FanPlan(2);
    ui->Fan_Mid->setStyleSheet("background-color: rgb(0, 0, 0);color:white;max-width:60px;max-height:60px; min-width:60px; min-height:60px; border-radius:30px;");
    ui->Fan_Low->setStyleSheet("background-color: rgb(255, 255, 255);color:black;max-width:60px;max-height:60px; min-width:60px; min-height:60px; border-radius:30px;");
    ui->Fan_High->setStyleSheet("background-color: rgb(255, 255, 255);color:black;max-width:60px;max-height:60px; min-width:60px; min-height:60px; border-radius:30px;");
    SetInstruction(3);
}

void AirSystem::on_Fan_High_clicked()
{
    Icon_FanPlan(3);
    ui->Fan_High->setStyleSheet("background-color: rgb(0, 0, 0);color:white;max-width:60px;max-height:60px; min-width:60px; min-height:60px; border-radius:30px;");
    ui->Fan_Mid->setStyleSheet("background-color: rgb(255, 255, 255);color:black;max-width:60px;max-height:60px; min-width:60px; min-height:60px; border-radius:30px;");
    ui->Fan_Low->setStyleSheet("background-color: rgb(255, 255, 255);color:black;max-width:60px;max-height:60px; min-width:60px; min-height:60px; border-radius:30px;");
    SetInstruction(4);
}
void AirSystem::on_Cold_clicked()
{
    Icon_ModePlan(1);
    StyleSheet(2,1,3,0);
    SetInstruction(9);
}
void AirSystem::on_Heat_clicked()
{
    Icon_ModePlan(4);
    StyleSheet(1,2,3,0);
    SetInstruction(11);
}
void AirSystem::on_Dry_clicked()
{
    Icon_ModePlan(2);
    StyleSheet(3,2,0,1);
    SetInstruction(10);
}
void AirSystem::on_Fan_clicked()
{
    Icon_ModePlan(3);
    StyleSheet(0,2,3,1);
    SetInstruction(14);
}
void AirSystem::on_TempQslider_valueChanged(int value)
{
    ui->AirTemp->setText(QString::number(value));
}

void AirSystem::ButtonStyle_Button(QPushButton *Name, int Offset, int BlurRadius)
{
    QGraphicsDropShadowEffect *ButtonStyle = new QGraphicsDropShadowEffect(this);
    ButtonStyle->setOffset(Offset);
    ButtonStyle->setColor(/*Qt::gray*/QColor(43, 43, 43));
    ButtonStyle->setBlurRadius(BlurRadius);
    Name->setGraphicsEffect(ButtonStyle);
}

void AirSystem::ButtonStyle_Label(QLabel *Name, int Offset, int BlurRadius)
{
    QGraphicsDropShadowEffect *ButtonStyle = new QGraphicsDropShadowEffect(this);
    ButtonStyle->setOffset(Offset);
    ButtonStyle->setColor(/*Qt::gray*/QColor(43, 43, 43));
    ButtonStyle->setBlurRadius(BlurRadius);
    Name->setGraphicsEffect(ButtonStyle);
}

void AirSystem::StyleSheet(int One, int Two, int Three , int Four)
{
    QList<QPushButton*> Mode;
    Mode<<ui->Fan<<ui->Heat<<ui->Cold<<ui->Dry;

    Mode[One]->setStyleSheet("background-color: rgb(0, 0, 0);color:white;max-width:60px;max-height:60px; min-width:60px; min-height:60px; border-radius:30px;");
    Mode[Two]->setStyleSheet("background-color: rgb(255, 255, 255);color:black;max-width:60px;max-height:60px; min-width:60px; min-height:60px; border-radius:30px;");
    Mode[Three]->setStyleSheet("background-color: rgb(255, 255, 255);color:black;max-width:60px;max-height:60px; min-width:60px; min-height:60px; border-radius:30px;");
    Mode[Four]->setStyleSheet("background-color: rgb(255, 255, 255);color:black;max-width:60px;max-height:60px; min-width:60px; min-height:60px; border-radius:30px;");

}

void AirSystem::Image_Init()
{
    QString filePath = ":/new/Air/Air/AirMode.png";
    QIcon icon = QIcon(filePath);
    QPixmap m_pic = icon.pixmap(icon.actualSize(QSize(120, 120)));//size自行调整
    ui->AirMode->setPixmap(m_pic);

    QString filePath2 = ":/new/Air/Air/Swing_LR.png";
    QIcon icon2 = QIcon(filePath2);
    QPixmap m_pic2 = icon2.pixmap(icon.actualSize(QSize(71, 71)));//size自行调整
    ui->SwingLR_P->setPixmap(m_pic2);

    QString filePath3 = ":/new/Air/Air/Swing_UD.png";
    QIcon icon3 = QIcon(filePath3);
    QPixmap m_pic3 = icon3.pixmap(icon.actualSize(QSize(71, 71)));//size自行调整
    ui->SwingUD_P->setPixmap(m_pic3);
}

void AirSystem::AutoMode()
{
    if(IndoorHum<=65){
        if(IndoorTemp<23){
            //关闭空调
            qDebug()<<"湿度---适宜---温度过低---关闭空调";
            if(Flag_AirSwitch==1){
                on_AirSwitch_clicked();
            }
        }
        else {
            qDebug()<<"湿度---适宜---温度适宜---开启空调";
            //开启空调
            if(Flag_AirSwitch==0){
                on_AirSwitch_clicked();
                ui->TempQslider->setValue(23);
                Trigger_TempQslider();
            }
        }
    }
    else {
        //关闭空调
        if(Flag_AirSwitch==0){
            ui->AirSwitch->click();
        }
    }
}


void AirSystem::on_AutoSwitch_clicked()
{
    if(AutoFlag==0){
        ui->AutoSwitch->setIcon(QIcon(":/new/Led/Led/AI_OFF.png"));
        ui->AutoSwitch->setStyleSheet("background-color: rgb(0, 0, 0);color:black; border-radius:15px;");
        AutoTime->start(1000);
        AutoFlag=1;
        ui->FunctionPanel->setEnabled(0);
        ui->TempQslider->setEnabled(0);
        ui->AirSwitch->setEnabled(0);
    }
    else {
        ui->AutoSwitch->setIcon(QIcon(":/new/Led/Led/AI_ON.png"));
        ui->AutoSwitch->setStyleSheet("background-color: rgb(255, 255, 255);color:black; border-radius:15px;");
        AutoTime->stop();
        AutoFlag=0;
        ui->FunctionPanel->setEnabled(1);
        ui->TempQslider->setEnabled(1);
        ui->AirSwitch->setEnabled(1);

    }
}

void AirSystem::Icon_FanPlan(int Order)
{
    switch(Order){
    case 0:
        break;
    case 1:
        ui->Fan_Low->setIcon(QIcon(":/new/Air/Air/Low_ON.png"));
        ui->Fan_Mid->setIcon(QIcon(":/new/Air/Air/Mid_OFF.png"));
        ui->Fan_High->setIcon(QIcon(":/new/Air/Air/High_OFF.png"));
        break;
    case 2:
        ui->Fan_Low->setIcon(QIcon(":/new/Air/Air/Low_OFF.png"));
        ui->Fan_Mid->setIcon(QIcon(":/new/Air/Air/Mid_ON.png"));
        ui->Fan_High->setIcon(QIcon(":/new/Air/Air/High_OFF.png"));
        break;
    case 3:
        ui->Fan_Low->setIcon(QIcon(":/new/Air/Air/Low_OFF.png"));
        ui->Fan_Mid->setIcon(QIcon(":/new/Air/Air/Mid_OFF.png"));
        ui->Fan_High->setIcon(QIcon(":/new/Air/Air/High_ON.png"));
        break;
    }
}

void AirSystem::Icon_ModePlan(int Order)
{
    switch (Order) {
    case 1:
        ui->Cold->setIcon(QIcon(":/new/Air/Air/Cold_ON.png"));
        ui->Dry->setIcon(QIcon(":/new/Air/Air/Dry_OFF.png"));
        ui->Fan->setIcon(QIcon(":/new/Air/Air/Fan_OFF.png"));
        ui->Heat->setIcon(QIcon(":/new/Air/Air/Heat_OFF.png"));
        break;
    case 2:
        ui->Cold->setIcon(QIcon(":/new/Air/Air/Cold_OFF.png"));
        ui->Dry->setIcon(QIcon(":/new/Air/Air/Dry_ON.png"));
        ui->Fan->setIcon(QIcon(":/new/Air/Air/Fan_OFF.png"));
        ui->Heat->setIcon(QIcon(":/new/Air/Air/Heat_OFF.png"));
        break;
    case 3:
        ui->Cold->setIcon(QIcon(":/new/Air/Air/Cold_OFF.png"));
        ui->Dry->setIcon(QIcon(":/new/Air/Air/Dry_OFF.png"));
        ui->Fan->setIcon(QIcon(":/new/Air/Air/Fan_ON.png"));
        ui->Heat->setIcon(QIcon(":/new/Air/Air/Heat_OFF.png"));
        break;
    case 4:
        ui->Cold->setIcon(QIcon(":/new/Air/Air/Cold_OFF.png"));
        ui->Dry->setIcon(QIcon(":/new/Air/Air/Dry_OFF.png"));
        ui->Fan->setIcon(QIcon(":/new/Air/Air/Fan_OFF.png"));
        ui->Heat->setIcon(QIcon(":/new/Air/Air/Heat_ON.png"));
        break;
    }
}
