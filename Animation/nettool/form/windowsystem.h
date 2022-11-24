#ifndef WINDOWSYSTEM_H
#define WINDOWSYSTEM_H

#include <QDialog>
#include <analysis_window.h>
#include <weathercrawler.h>
#include <QMetaType>
#include <QVariant>
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
    QMap<int,int>data;
signals:
    void SendClose();
    void RadioBroadcast(QString);
    void OutsideStatus(int,int,int);
    void SendToWx(QString,int);
    void SendWeather(int);
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

public slots:
    void AirQuality_Status(int,int,int);
    void Window_Status(int,int);
    void SetInstruction(int);
    void Button_Init();
    void CrawlAir(QMap<QString,QString>);
    void CrawlWeather(QMap<QString,QString>);
    void CrawlActive(QMap<QString,QString>);
    void testVoid(const CrawlMessage);


private:
    Ui::WindowSystem *ui;
};

#endif // WINDOWSYSTEM_H
