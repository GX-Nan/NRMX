#ifndef ANALYSIS_WIND_H
#define ANALYSIS_WIND_H

#include <QObject>
#include <QTimer>
#include <QMultiMap>
#include <QDebug>

class Wind_Data
{
public:
    int Station=1;//0--关闭 1---低档 2---中档 3----高档
    int Mode=0;//0----关闭模式 1----自然 2----立体 3---海洋 4---环绕 5---追踪
    int AiMode=0;//交互
    Wind_Data operator =(const Wind_Data &t)
    {
        Station=t.Station;
        Mode=t.Mode;
        AiMode=t.AiMode;
        return  t;
    }
};
class AirQuality
{
public:
    int PM25=0;
    int PM10=0;
    int Co2=0;
    int TVCO=0;
    int HCHO=0;
    int Temp=0;
    int Hum=0;
    int Brightness=0;
};
class Analysis_Wind : public QObject
{
    Q_OBJECT
public:
    explicit Analysis_Wind(QObject *parent = nullptr);
    ~Analysis_Wind();
    Wind_Data data;
    AirQuality Air;
    QString LocationStatus,LocationSub;
public slots:
    void Receive_Data(QMultiMap<int,QString> Data);
    void Handle_Data_Wind(QString Data);
    void Handle_Data_AirQuality(QString Data);
    void Data_Update(Wind_Data Lastest);
    void Wind_Decode(int Value);
signals:
    void Wind_UiData(const Wind_Data Data,int);
    void AirQuality_Data(const AirQuality Data);
    void IndoorAirJudge(int);
    void SendToAir(int,int);//发给空调 温度和湿度
    void SendToLight(int);//发给灯光 亮度 ---不过应该要分区域?
    void SendToLocation(int,int);
};

#endif // ANALYSIS_WIND_H

