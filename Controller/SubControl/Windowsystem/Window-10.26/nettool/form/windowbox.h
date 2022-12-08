#ifndef WINDOWBOX_H
#define WINDOWBOX_H

#include <QDialog>
#include<QGraphicsDropShadowEffect>
#include<QMap>
#include<QDebug>
class WindowData{//1---up 2--- down  3---stop
private:
    QMap<int,int> MessageLight;
public:
    WindowData(){
        MessageLight.insert(1,3);
        MessageLight.insert(2,3);
        MessageLight.insert(3,3);
    };
    int GetStatus(int Key)
    {
        return  MessageLight.value(Key);
    }
    void SetData(int Key,int Status)
    {
        MessageLight.insert(Key,Status);
    }
};


namespace Ui {
class WindowBox;
}

class WindowBox : public QDialog
{
    Q_OBJECT

public:
    explicit WindowBox(QWidget *parent = nullptr);
    ~WindowBox();
    WindowData Data;
    int ReturnStop=0;
signals:
    void CloseShawdown();
    void RadioBroadcast(QString);
    void Windows_Sub(int);
    void EndSignals();
    void StartSignals();
private slots:
    void on_Back_clicked();
    void Shadow_Init();
    void Tigger_DeviceSlider();
    void ButtonStylePlan(int,int,int);
    void ButtonStyle_Button(QPushButton *Name, int Offset, int BlurRadius);
    void Update_Ui(int);
    void on_Open_clicked();
    void on_Stop_clicked();
    void on_Close_clicked();
    void on_Device_Slider_valueChanged(int value);

public slots:
    void SetInstruction(int);
    void ReceiveData(int,int);
    void Windows_Sync(int);

private:
    Ui::WindowBox *ui;
};

#endif // WINDOWBOX_H
