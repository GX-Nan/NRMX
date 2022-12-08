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


class CrawlMessage{

public:
    QMap<QString,QString> OutSideAir;
    QMap<QString,QString> WeatherNow;
    QMap<QString,QString> Activity;
    QMap<QString,QString> HoulyTemp;
    QMap<QString,QString> HoulyHum;
    QMap<QString,QString> HoulyWeather;

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
