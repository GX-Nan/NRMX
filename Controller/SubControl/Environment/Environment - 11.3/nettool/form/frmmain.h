#ifndef FRMMAIN_H
#define FRMMAIN_H

#include <QWidget>
#include"frmtcpclient.h"
#include <QMouseEvent>
#include <switchbutton.h>
#include <airsystem.h>
#include <lightsystem.h>

namespace Ui {
class frmMain;
}

class frmMain : public QWidget
{
    Q_OBJECT

public:
    explicit frmMain(QWidget *parent = 0);
    ~frmMain();
    AirSystem *AirUi=nullptr;
    LightSystem *LightUi=nullptr;
    frmTcpClient *client=nullptr;
    QWidget *shade = nullptr;
    int StopReturn=0;
private slots:
    void on_tabWidget_currentChanged(int index);

    void ClientConfig();
    void ShadowInit();
    void BackgroundInit();
    bool eventFilter(QObject *obj,QEvent *event) override;
    void SwitchInit();
    void BackdropInit();
    void on_LightSubUi_clicked();
    void on_AirSubUi_clicked();
    void AllLed_Switch(bool value);
    void Air_Switch(bool value);
    void Air_Order(int order);
    void Light_Order(int order);
    void on_AuxiliarySlider_valueChanged(int value);
    void on_AirSlider_valueChanged(int value);
    void AirQualityIcon_Init();

signals:
    void ShowUiSreachIP();
    void ExecUiSreachIP();
    void ClientConnect();
    void RadioBroadcast(QString);
    void AirSwitch_Sub(int);
    void LightSwitch_Sub(int,int,int);
    void Sub_Auxiliary(int);
    void Sub_AirTemp(int);
    void EndSignals();


public:


protected:

private:
    Ui::frmMain *ui;
};


#endif // FRMMAIN_H
