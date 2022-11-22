#ifndef FRMMAIN_H
#define FRMMAIN_H

#include <QWidget>
#include"frmtcpclient.h"
#include <QMouseEvent>
#include<QGraphicsDropShadowEffect>
#include<QPushButton>


namespace Ui {
class frmMain;
}

class frmMain : public QWidget
{
    Q_OBJECT

public:
    explicit frmMain(QWidget *parent = 0);
    ~frmMain();
    frmTcpClient *client=nullptr;

private slots:
    void on_tabWidget_currentChanged(int index);
    void initConfig();
    void paintEvent(QPaintEvent *)override;
    void Shade_Init();
    void Xprogress_Init();
    void on_Low_clicked();
    void on_Mid_clicked();
    void on_High_clicked();
    void ButtonStyle_Button(QPushButton *Name, int Offset, int BlurRadius);
    void ButtonStylePlan_Fan(int,int,int);
    void ButtonStylePlan_Mode(int,int,int,int);
    void on_Nature_clicked();
    void on_Sea_clicked();
    void on_Solid_clicked();
    void on_Surround_clicked();
    void StyleSheet_Plan_Mode(int);
    void StyleSheet_Plan_Fan(int);
    void SetInstruction(int);
    void Updata_Ui(int);
    void AirQualityIcon_Init();
    void XprogressbarIfconfig();
    void Fan_StylePlan(int);
    void Mode_StylePlan(int);
    void Icon_Clear();
    void Icon_Clear_Fan();
signals:
    void ShowUiSreachIP();
    void ExecUiSreachIP();
    void ClientConnect();
    void RadioBroadcast(QString);
    void EndSignals();
    void StartSignals();
public:


protected:

private:
    int Fan_status=0;
    int Mode_status=0;

    Ui::frmMain *ui;
};


#endif // FRMMAIN_H
