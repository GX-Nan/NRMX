#ifndef WINDSYSTEM_H
#define WINDSYSTEM_H

#include <QDialog>
#include "windairquality.h"
#include "QDebug"
#include"windmode.h"
#include "analysis_wind.h"

namespace Ui {
class WindSystem;
}

class WindSystem : public QDialog
{
    Q_OBJECT

public:
    explicit WindSystem(QWidget *parent = nullptr);
    ~WindSystem();
    WindAirQuality *AirSubUi=nullptr;
    WindMode *ModeSubUi=nullptr;
    Wind_Data data;
    int SingleFalg=1;
signals:
    void SendClose();
    void Clear();
    void Enable(bool Falg);
    void RadioBroadcast(const QString);
    void Class_Update(const Wind_Data data);//报废--之后再删除
    void Xprogress_Update(const AirQuality data);
    void SendToWx(QString,int);
    void ModeCtrl(int);//控制模式



private slots:
    void on_pushButton_2_clicked();
    void ButtonStyle(QPushButton* Name,int Offset,int BlurRadius);
    void on_StopMode_clicked();
    void on_MinMode_clicked();
    void on_MidMode_clicked();
    void on_MixMode_clicked();
    void ButtonStylePlan(int,int,int,int);
    void Image_Init();
    void BackgroundPlan(int i, int i2, int i3, int i4);
    void SetInstruction(int);

public:
    void ShowSubUi();
    void Shadow();
public slots:
    void ReceiveData(const Wind_Data VarValue,int);


private:
    Ui::WindSystem *ui;
};

#endif // WINDSYSTEM_H
