#ifndef WINDMODE_H
#define WINDMODE_H

#include <QDialog>
#include <QDebug>

namespace Ui {
class WindMode;
}

class WindMode : public QDialog
{
    Q_OBJECT

public:
    explicit WindMode(QWidget *parent = nullptr);
    ~WindMode();
    void ShawDowm();
    void ButtonStyle(QPushButton *Name, int Offset, int BlurRadius);
public slots:
    void Clear();
    void Enable(bool Falg);
public slots://回头改成友元函数
    void on_SeaMode_clicked();
    void on_SurroundMode_clicked();
    void on_NaturalMode_clicked();
    void on_StereoscopicMode_clicked();
    void ButtonStylePlan(int,int,int,int,int);
    void BackgroundPlan(int,int,int,int,int);
    void ModeCtrl(int);
signals:
    void RadioBroadcast(QString);
    void SendToWx(QString,int);
private slots:
    void on_CloseMode_clicked();

private:
    Ui::WindMode *ui;
};

#endif // WINDMODE_H
