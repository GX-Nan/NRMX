#include "analysis_cutarin.h"

Analysis_Cutarin::Analysis_Cutarin(QObject *parent) : QObject(parent)
{

}

Analysis_Cutarin::~Analysis_Cutarin()
{

}

void Analysis_Cutarin::Receive_Data(QMultiMap<int, QString> Data)
{
    QStringList StringList=Data.values(1);//选择键值----窗帘状态

    QString HandleData;
    int Number =StringList.count();
    for(int i=0;i<Number;i++)
    {
        HandleData=StringList.at(i);
        Handle_Data(HandleData);
    }
}

void Analysis_Cutarin::Handle_Data(QString Data)
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
    //----得写转了多少 窗帘的状态是多少
    qDebug()<<"Function---Curtain:"<<Function;
    if(Function.toInt()==2){
        emit StatusSignals(Sub.toInt(),Value.toInt());
    }
}

void Analysis_Cutarin::Handle_Data_Esp(QString Data)
{
    QString Value;
    QString Function;
    //-----截取------------
    for(int i=4;i<=5;i++)
    {
        Function.append(Data.at(i));
    }
    for(int b=6;b<=9;b++)
    {
        Value.append(Data.at(b));
    }
    if(Function.toInt()==1)
    {
        emit BrightnessSignals(Value);
    }
}
