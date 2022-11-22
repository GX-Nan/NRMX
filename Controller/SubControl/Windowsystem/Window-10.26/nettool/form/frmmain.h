#ifndef FRMMAIN_H
#define FRMMAIN_H

#include <QWidget>
#include"frmtcpclient.h"
#include <QMouseEvent>
#include <curtainsbox.h>
#include <windowbox.h>
#include <weathercrawler.h>
#include <QMap>
#include<QLabel>
namespace Ui {
class frmMain;
}

class frmMain : public QWidget
{
    Q_OBJECT

public:
    explicit frmMain(QWidget *parent = 0);
    ~frmMain();
    QWidget *shade = nullptr;
    CurtainsBox *Curtains=nullptr;
    WindowBox *Windows=nullptr;
    frmTcpClient *client=nullptr;
    WeatherCrawler *Weather=nullptr;
    int StopReturn=0;
    bool eventFilter(QObject *obj,QEvent *event) override;
private slots:
    void on_tabWidget_currentChanged(int index);
    void ClientConfig();
    void ShadowInit();
    void paintEvent(QPaintEvent *);
    void ProgressInit();
    void on_WindowBox_clicked();
    void on_CurtainsBox_clicked();
    void BackdropInit();
    void BackgroundInit();
    void ButtonStyle_Button(QPushButton *Name, int Offset, int BlurRadius);
    void on_AllWindow_Open_clicked();
    void on_AllWindow_Stop_clicked();
    void on_AllWindow_Close_clicked();
    void ButtonStylePlan_Window(int,int,int);
    void ButtonStylePlan_Curtains(int,int,int);
    void on_AllCurtains_Up_clicked();
    void on_AllCurtains_Stop_clicked();
    void on_AllCurtains_Down_clicked();
    void Curtains_SetInstruction(int);
    void Window_SetInstruction(int);
    void IconSet(QString,QLabel*);
signals:
    void ShowUiSreachIP();
    void ExecUiSreachIP();
    void ClientConnect();
    void RadioBroadcast(QString);
    void Curtains_Sync(int);
    void Window_Sync(int);
    void StartCrawl();
    void EndSignals();

public:


protected:

private:
    Ui::frmMain *ui;
};


#endif // FRMMAIN_H
