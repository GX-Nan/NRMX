#include "airsystem.h"
#include "ui_airsystem.h"
#include<QGraphicsDropShadowEffect>

AirSystem::AirSystem(QWidget *parent) :
    QDialog(parent,Qt::WindowTitleHint | Qt::CustomizeWindowHint),
    ui(new Ui::AirSystem)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint | Qt::CustomizeWindowHint);
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::Tool);
    Switch_Ifconfig();
    Shawdow();
    qRegisterMetaType<Data>("Data");
    data={0,26,0,0,1,1};
    connect(ui->SwingUpDown,&SwitchButton::checkedChanged,this,&AirSystem::SwitchButton_U_D);
    connect(ui->SwingLeftRight,&SwitchButton::checkedChanged,this,&AirSystem::SwitchButton_L_R);
    connect(ui->TempQslider,&QSlider::sliderReleased,this,&AirSystem::Trigger_TempQslider);
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
}

void AirSystem::ReceiveData(Data VarValue)
{
    data=VarValue;
    if(data.Station==1){
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
        case 0: ui->SwingLeftRight->setChecked(0); break;
        case 1: ui->SwingLeftRight->setChecked(1); break;
        }
        switch(data.Swing_U_D)
        {
        case 0: ui->SwingUpDown->setChecked(0); break;
        case 1: ui->SwingUpDown->setChecked(1); break;
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
        if(Falg_AirSwitch!=0){
            on_AirSwitch_clicked();//按下按钮---做阴影特性
        }
    }
    else if(data.Station==0)
    {
        if(Falg_AirSwitch!=1){
            on_AirSwitch_clicked();
        }
        ButtonClear(3);
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

void AirSystem::Ui_Update()
{
    qDebug()<<"App::StopReturn:"<<App::StopReturn;
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
    if(Falg_AirSwitch==0){
        switch (Order) {
        case 0:
            emit RadioBroadcast("ZB20201001");
            break;
        case 1:
            emit RadioBroadcast("ZB20201011");
            break;
        case 2:
            emit RadioBroadcast("ZB20201021");
            data.Fan=1;
            break;
        case 3:
            emit RadioBroadcast("ZB20201031");
            data.Fan=2;
            break;
        case 4:
            emit RadioBroadcast("ZB20201041");
            data.Fan=3;
            break;
        case 5:
            emit RadioBroadcast("ZB20201051");
            data.Swing_L_R=1;
            break;
        case 6:
            emit RadioBroadcast("ZB20201061");
            data.Swing_L_R=0;
            break;
        case 7:
            emit RadioBroadcast("ZB20201071");
            data.Swing_U_D=1;
            break;
        case 8:
            emit RadioBroadcast("ZB20201081");
            data.Swing_U_D=0;
            break;
        case 9:
            emit RadioBroadcast("ZB20201091");
            data.Mode=1;
            break;
        case 10:
            emit RadioBroadcast("ZB20201101");
            data.Mode=3;
            break;
        case 11:
            emit RadioBroadcast("ZB20201111");
            data.Mode=2;
            break;
        case 12:
            emit RadioBroadcast("ZB20201121");
            data.Mode=0;
            break;
        case 13:
            emit RadioBroadcast("ZB20201131");
            data.Fan=0;
            break;
        case 14:
            emit RadioBroadcast("ZB20201141");
            data.Mode=4;
            break;
        }
    }
    emit Class_Update(data);
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
}

void AirSystem::Implement()
{
    switch(data.Station){
    case 0:
        emit RadioBroadcast("ZB20201001");
        break;
    case 1:
        emit RadioBroadcast("ZB20201011");
        break;
    }
    switch(data.Fan){
    case 0:
        break;
    case 1:
        emit RadioBroadcast("ZB20201021");
        break;
    case 2:
        emit RadioBroadcast("ZB20201031");
        break;
    case 3:
        emit RadioBroadcast("ZB20201041");
        break;
    }
    switch(data.Swing_L_R){
    case 0:
        emit RadioBroadcast("ZB20201061");
        break;
    case 1:
        emit RadioBroadcast("ZB20201051");
        break;
    }
    switch(data.Swing_U_D){
    case 0:
        emit RadioBroadcast("ZB20201081");
        break;
    case 1:
        emit RadioBroadcast("ZB20201071");
        break;
    }
    switch(data.Mode){
    case 0:
        emit RadioBroadcast("ZB20201121");
        break;
    case 1:
        emit RadioBroadcast("ZB20201091");
        break;
    case 2:
        emit RadioBroadcast("ZB20201111");
        break;
    case 3:
        emit RadioBroadcast("ZB20201101");
        break;
    case 4:
        emit RadioBroadcast("ZB20201141");
        break;
    }
    QString SendData="ZB202011";
    QString SetTemp=ui->AirTemp->text();
    SendData.insert(7,SetTemp);
    emit RadioBroadcast(SendData);
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
    if(Falg_AirSwitch==1)
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
        Falg_AirSwitch=0;
    }
    else if(Falg_AirSwitch==0)
    {
        //----阴影
        SetAirSwitch->setOffset(8);
        SetAirSwitch->setBlurRadius(35);
        ui->AirSwitch->setGraphicsEffect(SetAirSwitch);
        //-----界面更新--------
        Falg_AirSwitch=1;
        data.Station=0;
        ui->FunctionPanel->setEnabled(0);
        ButtonClear(3);
        //-----发到执行器上---
        emit RadioBroadcast("ZB20201001");

    }
}

void AirSystem::on_Fan_Low_clicked()
{
    ui->Fan_Low->setStyleSheet("background-color: rgb(0, 0, 0);color:white;max-width:60px;max-height:60px; min-width:60px; min-height:60px; border-radius:30px;");
    ui->Fan_Mid->setStyleSheet("background-color: rgb(255, 255, 255);color:black;max-width:60px;max-height:60px; min-width:60px; min-height:60px; border-radius:30px;");
    ui->Fan_High->setStyleSheet("background-color: rgb(255, 255, 255);color:black;max-width:60px;max-height:60px; min-width:60px; min-height:60px; border-radius:30px;");
    SetInstruction(2);
}

void AirSystem::on_Fan_Mid_clicked()
{
    ui->Fan_Mid->setStyleSheet("background-color: rgb(0, 0, 0);color:white;max-width:60px;max-height:60px; min-width:60px; min-height:60px; border-radius:30px;");
    ui->Fan_Low->setStyleSheet("background-color: rgb(255, 255, 255);color:black;max-width:60px;max-height:60px; min-width:60px; min-height:60px; border-radius:30px;");
    ui->Fan_High->setStyleSheet("background-color: rgb(255, 255, 255);color:black;max-width:60px;max-height:60px; min-width:60px; min-height:60px; border-radius:30px;");
    SetInstruction(3);
}

void AirSystem::on_Fan_High_clicked()
{
    ui->Fan_High->setStyleSheet("background-color: rgb(0, 0, 0);color:white;max-width:60px;max-height:60px; min-width:60px; min-height:60px; border-radius:30px;");
    ui->Fan_Mid->setStyleSheet("background-color: rgb(255, 255, 255);color:black;max-width:60px;max-height:60px; min-width:60px; min-height:60px; border-radius:30px;");
    ui->Fan_Low->setStyleSheet("background-color: rgb(255, 255, 255);color:black;max-width:60px;max-height:60px; min-width:60px; min-height:60px; border-radius:30px;");
    SetInstruction(4);
}
void AirSystem::on_Cold_clicked()
{
    StyleSheet(2,1,3,0);
    SetInstruction(9);
}
void AirSystem::on_Heat_clicked()
{
    StyleSheet(1,2,3,0);
    SetInstruction(11);
}
void AirSystem::on_Dry_clicked()
{
    StyleSheet(3,2,0,1);
    SetInstruction(10);
}
void AirSystem::on_Fan_clicked()
{
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

