#ifndef AIRSYSTEM_H
#define AIRSYSTEM_H

#include <QDialog>
#include"switchbutton.h"
#include <QDebug>
#include "app.h"
#include <QTimer>
#include <analysis_air.h>
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
    void ReceiveData(const Data VarValue,int);
    void ButtonClear(int Switch);
    void Ui_Update();
    void SwitchButton_U_D(int Falg);
    void SwitchButton_L_R(int Falg);
    void SetInstruction(int Order);
    void Trigger_TempQslider();
    void Implement();
signals:
    void SendClose();
    void RadioBroadcast(QString);
    void SendToWx(QString,int);

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
