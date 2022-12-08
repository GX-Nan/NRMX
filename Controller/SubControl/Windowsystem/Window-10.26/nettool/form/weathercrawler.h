#ifndef WEATHERCRAWLER_H
#define WEATHERCRAWLER_H

#include <QObject>
#include <Python.h>
#include <QMap>
#include <QDebug>
#include <pythreadstatelock.h>
#include <QTimer>
#include <QMetaType>
#include <QVariant>
#include <QCoreApplication>
#include <QThread>

static int CrollerTimes=0;
static int HoulyTimes=0;
class CrawlMessage{

public:
    QMap<QString,QString> OutSideAir;
    QMap<QString,QString> WeatherNow;
    QMap<QString,QString> Activity;
//    QList<QString> HoulyTemp;
//    QList<QString> HoulyHum;
//    QList<QString> HoulyWeather;

    QMap<int,QString> HoulyTemp;
    QMap<int,QString> HoulyHum;
    QMap<int,QString> HoulyWeather;

};
Q_DECLARE_METATYPE(CrawlMessage);


class WeatherCrawler : public QObject
{
    Q_OBJECT
public:
    explicit WeatherCrawler(QObject *parent = nullptr);
    //注册参数类型

private:
    void Python_Init();//python初始化
    void Analysis(QStringList,int);
    void Crawl();
    CrawlMessage *Message;
    QTimer *Timer;
    QThread *Task;
signals:
    void SendMessage( const CrawlMessage*);
    void test(QString);
public slots:
    void TimeCatch();
};

#endif // WEATHERCRAWLER_H
