#include "analysis_window.h"

Analysis_Window::Analysis_Window(QObject *parent) : QObject(parent)
{

}

Analysis_Window::~Analysis_Window()
{

}

void Analysis_Window::Receive_Data(QMultiMap<int, QString> Data)
{

    QStringList StringList_Window=Data.values(1);
    QStringList StringList_AirQuality=Data.values(7);
    qDebug()<<"StringList_AirQuality:"<<StringList_AirQuality;
    /*
    --1 窗帘
//*/
    QString HandleData;
    int Number =StringList_Window.count();
    for(int i=0;i<Number;i++)
    {
        HandleData=StringList_Window.at(i);
        Handle_Data(HandleData);
    }
}

void Analysis_Window::Handle_Data(QString Data)
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
    //----得写转了多少 窗户的状态是多少
    qDebug()<<"Function---window:"<<Function;
    if(Function.toInt()==1){
        emit Window_Data(Sub.toInt(),Value.toInt());
    }
}

void Analysis_Window::Handle_Air(QString Data)
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

    AirQuality_Decode(Function.toInt(),Sub.toInt(),Value.toInt());

}

void Analysis_Window::AirQuality_Decode(int Function, int Sub, int Value)//sub 是地区---> 1---珠海
{
    qDebug()<<"AirQuality:"<<Value;
    switch (Function) {
    case 1:
        setTemp(Value);
        break;
    case 2:
        setPM25(Value);
        break;
    case 3:
        setHumi(Value);
        break;
    case 4:
        setCo2(Value);
        break;
    case 5:
        setAQi(Value);
        break;
    }
    emit AirQuality_Data(Function,Sub,Value);
}
