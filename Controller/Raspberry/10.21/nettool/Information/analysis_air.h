#ifndef ANALYSIS_AIR_H
#define ANALYSIS_AIR_H

#include <QObject>
#include <QThread>
#include <QTimer>
#include <QMultiMap>
#include <QDebug>
#include "app.h"
#include <QMetaType>
#include <QVariant>
class Data
{
public:
    int Station=0;
    int Temp=26;
    int Swing_L_R=0;
    int Swing_U_D=0;
    int Mode =1;//1--制冷 2--制热 3--除湿 4--送风 0--自动
    int Fan =1;
    Data operator =(const Data &t){
       Station=t.Station;
       Temp=t.Temp;
       Mode=t.Mode;
       Fan=t.Fan;
       Swing_U_D=t.Swing_U_D;
       Swing_L_R=t.Swing_L_R;
       return t;
    }
};
Q_DECLARE_METATYPE(Data);
class Analysis_Air : public QObject ,Data
{
    Q_OBJECT
public:
    explicit Analysis_Air(QObject *parent = nullptr);
    ~Analysis_Air();
    Data data;
public slots:
    void Receive_Data(QMultiMap<int,QString> Data);
    void Handle_Data(QString Data);
    void Data_Update(Data Lastest);
public:
    int binary_search(int *arr,int p,int q,int ele);
    void Air_Decode(int Value);
signals:
    void Air_UiValue(const Data Data,int);
};

#endif // ANALYSIS_AIR_H
