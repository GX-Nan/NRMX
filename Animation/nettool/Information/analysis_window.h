#ifndef ANALYSIS_WINDOW_H
#define ANALYSIS_WINDOW_H

#include <QObject>
#include <QTimer>
#include <QMultiMap>
#include <QDebug>
class OutSideWeather{
private:
    int Temp=0;
    int PM25=0;
    int Humi=0;
    int AQi=0;
    int Co2=0;
    QList<int>test;
public:
     void SetStatus(int Temp,int PM25,int Humi,int AQi)
     {
         this->Temp=Temp;
         this->PM25=PM25;
         this->Humi=Humi;
         this->AQi=AQi;
     }
     void setTemp(int Temp)
     {
        this->Temp=Temp;
     }
     void setPM25(int PM25)
     {
        this->PM25=PM25;
     }
     void setHumi(int Humi)
     {
        this->Humi=Humi;
     }
     void setAQi(int AQi)
     {
        this->AQi=AQi;
     }
     void setCo2(int Co2)
     {
        this->Co2=Co2;
     }
//     QList<int> getStatus()//写个友元搞搞吧
//     {
//         test.insert(1,Temp);
//         test.insert(2,PM25);
//         test.insert(3,Humi);
//         test.insert(4,AQi);
//         return test;
//     }
};
class Analysis_Window : public QObject ,public OutSideWeather
{
    Q_OBJECT
public:
    explicit Analysis_Window(QObject *parent = nullptr);
    ~Analysis_Window();
public slots:
    void Receive_Data(QMultiMap<int,QString> Data);
    void Handle_Data(QString Data);
    void Handle_Air(QString Data);
    void AirQuality_Decode(int Function,int Sub,int Value);
signals:
    void Window_Data(int,int);
    void AirQuality_Data(int,int,int);
};

#endif // ANALYSIS_WINDOW_H
