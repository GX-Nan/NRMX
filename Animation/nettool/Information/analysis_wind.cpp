#include "analysis_wind.h"

Analysis_Wind::Analysis_Wind(QObject *parent) : QObject(parent)
{

}

Analysis_Wind::~Analysis_Wind()
{

}

void Analysis_Wind::Receive_Data(QMultiMap<int, QString> Data)
{
    QStringList StringList_Wind=Data.values(6);//选择键值----风机状态
    QStringList StringList_AirQuality=Data.values(2);
    /*
    --6 新风
*/
    QString HandleData;
    int Number =StringList_Wind.count();
    for(int i=0;i<Number;i++)
    {
        HandleData=StringList_Wind.at(i);
        Handle_Data_Wind(HandleData);
    }

}

void Analysis_Wind::Handle_Data_Wind(QString Data)
{
    QString Sub;
    QString Value;
    QString Function;
    //-----截取------------
    for(int i=3;i<=4;i++)
    {
        Function.append(Data.at(i));
    }
    for(int a=5;a<=6;a++)
    {
        Sub.append(Data.at(a));
    }
    for(int b=7;b<=8;b++)
    {
        Value.append(Data.at(b));
    }
    //------------------
    if(Function.toInt()==1)//601----1的那位
    {
        if(Sub.toInt()==1)//设备位
        {
            Wind_Decode(Value.toInt());
        }
        else if(Sub.toInt()==2)//风口位置
        {

        }
    }
    else if(Function.toInt()==2){
        qDebug()<<"风口位置-----------------------";
        emit SendToTuyere(Data);
    }
}

void Analysis_Wind::Handle_Data_AirQuality(QString Data)
{
    QString Value;
    QString Function;
    QString Head;

    //-----截取------------
    Head=Data.at(3);
    for(int i=4;i<=5;i++)
    {
        Function.append(Data.at(i));
    }
    for(int b=6;b<=9;b++)
    {
        Value.append(Data.at(b));
    }
    //----设备位置-----

    //------------------
    switch(Function.toInt())
    {
    case 1:
        Air.Brightness=Value.toInt();
        if(Head=="A"){
            emit SendToLight(1,Air.Brightness);
        }else if(Head=="B"){
            emit SendToLight(2,Air.Brightness);
        }else if(Head=="C"){
            emit SendToLight(3,Air.Brightness);
        }
        break;
    case 2:
        Air.Temp=Value.toInt();
        break;
    case 3:
        Air.Hum=Value.toInt();
        break;
    case 4:
        Air.PM25=Value.toInt();
        if(Air.PM25>=75){
            PM25Flag=1;
            qDebug()<<"innnn---PM25---超标";
        }else {
            PM25Flag=0;
        }
        break;
    case 5:
        Air.Co2=Value.toInt();
        if(Air.Co2>=700){
            Co2Flag=1;
            qDebug()<<"innnn---Co2---超标";
        }else {
            Co2Flag=0;
        }
        break;
    case 6:
        Air.TVCO=Value.toInt();
        if(Air.TVCO>=216){ //<0.6mg/m3 平方 120m2*3
            TvcoFlag=1;
            qDebug()<<"innnn---TVCO---超标";
        }else {
            TvcoFlag=0;
        }
        break;
    case 7://<0.1mg/m3 平方 120m2*3
        Air.HCHO=Value.toInt();
        if(Air.HCHO>=36){
            HCHOFlag=1;
            qDebug()<<"innnn---HCHO---超标";
        }else {
            HCHOFlag=0;
        }
        break;
    case 8://<0.15mg/m3 平方 120m2*3
        Air.PM10=Value.toInt();
        if(Air.PM10>=54){
            PM10Flag=1;
            qDebug()<<"innnn---PM10---超标";
        }else {
            PM10Flag=0;
        }
        break;
    case 9:
        for(int i=6;i<=7;i++){
            LocationSub.append(Data.at(i));
        }//?----用于同一个地方多个传感器的状态
        for(int i=8;i<=9;i++){
            LocationStatus.append(Data.at(i));
        }
        LocationAnalysis(Head,LocationStatus.toInt());
        qDebug()<<"位置"<<LocationSub.toInt()<<"状态："<<LocationStatus.toInt();
        break;
    }
    emit AirQuality_Data(Air);//新风显示
    emit SendToAir(Air.Temp,Air.Hum);//给空调判断
//    PM25Flag=1;
    //-----先在这里判断室内是否需要通风透气---然后再判断是否要开窗户或者新风
    if(PM25Flag==1||PM10Flag==1||HCHOFlag==1||TvcoFlag==1||Co2Flag==1){
        emit IndoorAirJudge(1);
//        qDebug()<<"innnn---開";
    }else if(PM25Flag==0&&PM10Flag==0&&HCHOFlag==0&&TvcoFlag==0&&Co2Flag==0) {//测试测试
        emit IndoorAirJudge(0);
        qDebug()<<"innnn---关";
    }
    LocationSub.clear();
    LocationStatus.clear();
}

void Analysis_Wind::Data_Update(Wind_Data Lastest)
{
    data=Lastest;
}

void Analysis_Wind::Wind_Decode(int Value)
{
    if(Value<=3)
    {
        data.Station=Value;
    }
    else {
        data.Mode=Value-4;
    }
    emit Wind_UiData(data,Value);
}

void Analysis_Wind::LocationAnalysis(QString sub, int data)
{
    if(sub=="A"){
        switch(LocationSub.toInt()){
        case 1:
            LocationMeetingL=data;
            break;
        case 2:
            LocationMeetingR=data;
            break;
        }
        if(LocationMeetingR==1||LocationMeetingL==1){
            emit SendToLocation(1,1);
        }else {
            emit SendToLocation(1,0);
        }
    }else if(sub=="B"){
        LocationBar=data;
        emit SendToLocation(2,data);
    }else if(sub=="C"){
        LocationOffice=data;
        emit SendToLocation(3,data);
    }
}
