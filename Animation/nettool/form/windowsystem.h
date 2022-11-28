#ifndef WINDOWSYSTEM_H
#define WINDOWSYSTEM_H

#include <QDialog>
#include <analysis_window.h>
#include <weathercrawler.h>
#include <QMetaType>
#include <QVariant>
#include <QTimer>
namespace Ui {
class WindowSystem;
}

class WindowSystem : public QDialog
{
    Q_OBJECT

public:
    explicit WindowSystem(QWidget *parent = nullptr);
    ~WindowSystem();
    int WindowStatus=0;
    int SingleFalg=1;
    //---自动
    int IndoorTemp=0;
    int OutSideHum=0;
    int Weather=0;
    int AutoFlag=0;
    int WindowStopFlag=0;
    int location=0;
    int AQI=0;
    QTimer *AutoTime;
    //------
    QMap<int,int>data;
signals:
    void SendClose();
    void RadioBroadcast(QString);
    void OutsideStatus(int,int,int);
    void SendToWx(QString,int);
    void SendWeather(int);
    void SendAQI(int);
    void SendTempHum(int,int);
    void SendToWind(int);
    void AutoMode_Sync(int);
public:
    void Shadow();
private slots:
    void on_BackMain_clicked();
    void ButtonStyle(QPushButton* Name,int Offset,int BlurRadius);
    void on_WindowClose_clicked();
    void on_WindowOpen_clicked();
    void on_WindowStop_clicked();
    void ButtonStyle_Button(QPushButton* Name,int Offset,int BlurRadius);
    void on_Device_Qslider_valueChanged(int value);
    void Tigger_Device();
    void Clear();
    void XprogressbarIfconfig();
    void ButtonStylePlan(int,int,int);
    void Image_Init();
    void AutoMode();
    void on_AutoSwitch_clicked();
    void Icon_Plan(int);

public slots:
    void AirQuality_Status(int,int,int);
    void Window_Status(int,int);
    void SetInstruction(int);
    void Button_Init();
    void CrawlAir(QMap<QString,QString>);
    void CrawlWeather(QMap<QString,QString>);
    void CrawlActive(QMap<QString,QString>);
    void AirAutoTigger(int);
    void Auto_Sync(int);


private:
    Ui::WindowSystem *ui;
};

#endif // WINDOWSYSTEM_H
