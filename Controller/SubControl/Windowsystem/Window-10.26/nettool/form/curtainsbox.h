#ifndef CURTAINSBOX_H
#define CURTAINSBOX_H

#include <QDialog>
#include<QGraphicsDropShadowEffect>
#include <QMap>
#include<QDebug>
class CurtainsData{//0---up 1--- down 4---stop
private:
    QMap<int,int> MessageLight;
public:
    CurtainsData(){
        MessageLight.insert(1,4);
        MessageLight.insert(2,4);
        MessageLight.insert(3,4);
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
class CurtainsBox;
}

class CurtainsBox : public QDialog
{
    Q_OBJECT

public:
    explicit CurtainsBox(QWidget *parent = nullptr);
    ~CurtainsBox();
    CurtainsData Data;
    int ReturnStop=0;
signals:
    void CloseShawdown();
    void RadioBroadcast(QString);
    void Curtains_Sub(int);
    void EndSignals();
    void StartSignals();
private slots:
    void on_Close_clicked();
    void ShadowInit();
    void on_Up_clicked();
    void on_Stop_clicked();
    void on_Down_clicked();
    void on_Device_Slider_valueChanged(int value);
    void ButtonStyle_Button(QPushButton *Name, int Offset, int BlurRadius);
    void Tigger_DeviceSlider();
    void ButtonStylePlan(int,int,int);
    void Update_Ui(int);

public slots:
    void SetInstruction(int);
    void ReceiveData(int,int);
    void Curtains_Sync(int);


private:
    Ui::CurtainsBox *ui;
};

#endif // CURTAINSBOX_H
