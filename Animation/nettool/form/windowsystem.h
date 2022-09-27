#ifndef WINDOWSYSTEM_H
#define WINDOWSYSTEM_H

#include <QDialog>

#include <analysis_window.h>

namespace Ui {
class WindowSystem;
}

class StatusWindow{
private:
    QMap<QString,int> MessageCurtains;
public:
    StatusWindow(){
        MessageCurtains.insert("1",0);
        MessageCurtains.insert("2",0);
    };
    void MessageInsert(QString Key,int Value)
    {
       MessageCurtains.insert(Key,Value);
    }
    int GetMessage(QString Key)
    {
        return MessageCurtains.value(Key);
    }
    QList<int> Values()
    {
        return MessageCurtains.values();
    }
};

class WindowSystem : public QDialog
{
    Q_OBJECT

public:
    explicit WindowSystem(QWidget *parent = nullptr);
    ~WindowSystem();
    int WindowStatus=0;
    QMap<int,int>data;
    StatusWindow status;
private:
    int SingleFalg=1;
signals:
    void SendClose();
    void RadioBroadcast(QString);
    void OutsideStatus(int,int,int);
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
    void WindowsStatus(int value);

public slots:
    void AirQuality_Status(int,int,int);
    void Window_Status(int,int,int);
    void SetInstruction(int);
    void Button_Init();
private:
    Ui::WindowSystem *ui;
};

#endif // WINDOWSYSTEM_H
