#ifndef AIRSYSTEM_H
#define AIRSYSTEM_H

#include <QDialog>
#include"switchbutton.h"
#include <QDebug>
#include "app.h"
#include <QTimer>


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

namespace Ui {
class AirSystem;
}

class AirSystem : public QDialog
{
    Q_OBJECT
public:
    explicit AirSystem(QWidget *parent = nullptr);
    ~AirSystem();
    void Switch_Ifconfig();
    void Shawdow();
    Data data;
private:
    int Falg_Update=0;
    int Falg_AirSwitch=1;
    int StopFalg=0;

public slots:
    //-----UiData
    void ReceiveData(int);
    void ButtonClear(int Switch);
    void Ui_Update();
    void SwitchButton_U_D(int Falg);
    void SwitchButton_L_R(int Falg);
    void SetInstruction(int Order);
    void Trigger_TempQslider();
    void Implement();
    void Main_AirTemp(int);
    void Main_AirSwitch(int);
signals:
    void SendClose();
    void RadioBroadcast(QString);
    void Air_Sync(int);
    void AirTemp_Sync(int);
    void EndSignal();
    void StartSignal();

private slots:
    void on_BackMain_clicked();
    void on_AirSwitch_clicked();
    void on_Fan_Low_clicked();
    void on_Fan_Mid_clicked();
    void on_Fan_High_clicked();
    void on_Cold_clicked();
    void on_Heat_clicked();
    void on_Dry_clicked();
    void on_Fan_clicked();
    void on_TempQslider_valueChanged(int value);
    void ButtonStyle_Button(QPushButton* Name,int Offset,int BlurRadius);
    void ButtonStyle_Label(QLabel* Name,int Offset,int BlurRadius);
    void StyleSheet(int,int,int,int);
    void Image_Init();

private:
    Ui::AirSystem *ui;
};

#endif // AIRSYSTEM_H
