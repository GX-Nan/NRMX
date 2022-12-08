#ifndef WINDAIRQUALITY_H
#define WINDAIRQUALITY_H

#include <QDialog>
#include <xprogressbar.h>
#include "analysis_wind.h"
#include <QIcon>


namespace Ui {
class WindAirQuality;
}

class WindAirQuality : public QDialog
{
    Q_OBJECT

public:
    explicit WindAirQuality(QWidget *parent = nullptr);
    ~WindAirQuality();
    void ShawDowm();
    void Xprogressbar_Init();//初始化
public slots:
    void Xprogressbar_Update(AirQuality Data);
    void Image_Init();

private:
    Ui::WindAirQuality *ui;
};

#endif // WINDAIRQUALITY_H
