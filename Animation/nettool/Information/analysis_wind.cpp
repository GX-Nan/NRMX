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
        else if(Sub.toInt()==0)//自动交互
        {

        }
    }
}

void Analysis_Wind::Handle_Data_AirQuality(QString Data)
{
    QString Value;
    QString Function;
    int PM25Flag=0,Co2Flag=0,TvcoFlag=0,HCHOFlag=0,PM10Flag=0;
    //-----截取------------
    for(int i=4;i<=5;i++)
    {
        Function.append(Data.at(i));
    }
    for(int b=6;b<=9;b++)
    {
        Value.append(Data.at(b));
    }
    //------------------
    switch(Function.toInt())
    {
    case 1:
        Air.Brightness=Value.toInt();
        break;
    case 2:
        Air.Temp=Value.toInt();
        break;
    case 3:
        Air.Hum=Value.toInt();
        break;
    case 4:
        Air.PM25=Value.toInt();
        if(Value>=75){
            PM25Flag=1;
        }else {
            PM25Flag=0;
        }
        break;
    case 5:
        Air.Co2=Value.toInt();
        if(Value>=700){
            Co2Flag=1;
        }else {
            Co2Flag=0;
        }
        break;
    case 6:
        Air.TVCO=Value.toInt();
        if(Value>=2){
            TvcoFlag=1;
        }else {
            TvcoFlag=0;
        }
        break;
    case 7:
        Air.HCHO=Value.toInt();
        if(Value>=12){
            HCHOFlag=1;
        }else {
            HCHOFlag=0;
        }
        break;
    case 8:
        Air.PM10=Value.toInt();
        if(Value>=18){
            PM10Flag=1;
        }else {
            PM10Flag=0;
        }
        break;
    }
    emit AirQuality_Data(Air);//新风显示
    emit SendToAir(Air.Temp,Air.Hum);//给空调判断
    //-----先在这里判断室内是否需要通风透气---然后再判断是否要开窗户或者新风
    if(PM25Flag==1||PM10Flag==1||HCHOFlag==1||TvcoFlag==1||Co2Flag==1){
        emit IndoorAirJudge(1);
    }else {
        emit IndoorAirJudge(0);
    }
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
