#ifndef CURTAINSYSTEM_H
#define CURTAINSYSTEM_H

#include <QDialog>

namespace Ui {
class CurtainSystem;
}

class CurtainSystem : public QDialog
{
    Q_OBJECT

public:
    explicit CurtainSystem(QWidget *parent = nullptr);
    ~CurtainSystem();
    void Shawdow();
signals:
    void SendClose();
    void RadioBroadcast(QString);
private slots:
    void on_BackMain_clicked();
    void ButtonStyle(QPushButton* Name,int Offset,int BlurRadius);
    void on_Up_clicked();
    void on_Stop_clicked();
    void on_Down_clicked();
    void ButtonStylePlan(int,int,int);
    void SetInstruction(int);
    void on_Device_Slider_valueChanged(int value);

    void on_horizontalSlider_2_valueChanged(int value);

public slots:
    void ReceiveData(QString);
    void BrightnessShow(QString);

private:
    Ui::CurtainSystem *ui;
};

#endif // CURTAINSYSTEM_H
