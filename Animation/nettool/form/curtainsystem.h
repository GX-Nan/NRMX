#ifndef CURTAINSYSTEM_H
#define CURTAINSYSTEM_H

#include <QDialog>
#include <QMap>
#include <QDebug>
#include <QCoreApplication>
#include <unistd.h>
#include <QTimer>

namespace Ui {
class CurtainSystem;
}

class StatusCurtains{
private:
    QMap<QString,int> MessageCurtains;
public:
    StatusCurtains(){
        MessageCurtains.insert("0",0);
        MessageCurtains.insert("1",0);
        MessageCurtains.insert("2",0);
        MessageCurtains.insert("3",0);
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
class CurtainSystem : public QDialog
{
    Q_OBJECT
private:
public:
    explicit CurtainSystem(QWidget *parent = nullptr);
    ~CurtainSystem();
    void Shawdow();
    StatusCurtains status;
    int SingleFalg=0;
    QTimer *Timer;
    int AllCurtainsFalg=0;
    int AllCurtainsStop=1;
signals:
    void SendClose();
    void RadioBroadcast(QString);
    void SendToWx(QString,int);
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
    void CurtainsStatus(int value);
    void AllCurtains();

public slots:
    void ReceiveData(QString);
    void BrightnessShow(QString);
    void Ui_Update(int,int);

private:
    Ui::CurtainSystem *ui;
};

#endif // CURTAINSYSTEM_H
