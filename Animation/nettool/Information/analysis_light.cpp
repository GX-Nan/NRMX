#include "analysis_light.h"

Analysis_Light::Analysis_Light(QObject *parent) : QObject(parent)
{

}

Analysis_Light::~Analysis_Light()
{

}

void Analysis_Light::Receive_Data(QMultiMap<int, QString> Data)
{
    QStringList DataStringList=Data.values(2);//选择键值
    /*
    --2 窗帘
*/
    qDebug()<<"DataStringList:"<<DataStringList;
    QString HandleData;
    int Number =DataStringList.count();
    for(int i=0;i<Number;i++)
    {
        HandleData=DataStringList.at(i);
        Handle_Data(HandleData);
    }
}

void Analysis_Light::Handle_Data(QString Data)
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
    if(Function.toInt()==0||Function.toInt()==1||Function.toInt()==3||Function.toInt()==4||Function.toInt()==5||Function.toInt()==6){
        emit StatusSignals(Function.toInt(),Sub.toInt(),Value.toInt());
        qDebug()<<"Function:"<<Function;
    }
}


