#ifndef FRMMAIN_H
#define FRMMAIN_H

#include <QWidget>
#include"frmtcpclient.h"
#include"serversreach.h"
#include"qlistwidgetmouse.h"
#include <QMouseEvent>
#include"uiTcpClient.h"
#include"uitcpserver.h"
#include<QPainter>
#include"windsystem.h"
#include"doorsystem.h"
#include"curtainsystem.h"
#include"airsystem.h"
#include"lightsystem.h"
#include"windowsystem.h"
#include "wxreceive.h"
#include "wxsend.h"
#include "weathercrawler.h"


namespace Ui {
class frmMain;
}

class frmMain : public QWidget
{
    Q_OBJECT

public:
    explicit frmMain(QWidget *parent = 0);
    ~frmMain();

    QPainter *painter;
    QWidget *shade = nullptr;
    WindSystem *WindUi=nullptr;
    DoorSystem *DoorUi=nullptr;
    CurtainSystem *CurtainUi=nullptr;
    AirSystem *AirUi=nullptr;
    LightSystem *LightUi=nullptr;
    WindowSystem *WindowUi=nullptr;
    frmTcpServer *TaskTcpServer=nullptr;
    //------------
    Analysis_Air *Analysis_air=nullptr;
    Analysis_Wind *Analysis_wind=nullptr;
    Analysis_Light *Analysis_light=nullptr;
    Analysis_Window *Analysis_window=nullptr;
    Analysis_Cutarin *Analysis_cutarin=nullptr;
    WxReceive *WxMsg=nullptr;
    WxSend *WxSd=nullptr;
    //-------
    WeatherCrawler *Crawler=nullptr;
    //-------
    void InterfaceUpdate();//界面更新
    void paintEvent(QPaintEvent*) override;//画图
    void Shadow();
    bool eventFilter(QObject *obj,QEvent *event) override;
    void MainBackground();//主界面背景
    void ControlPage();//控制界面背景
    void TcpTaskInit();
    void IPForm();

private slots:
    void on_tabWidget_currentChanged(int index);
    void saveConfig();
    void initConfig();
    void on_UISreachIP_clicked();
    void on_Server_clicked();
    void on_GoMain_clicked();
    void on_GoControlPage_clicked();
    void on_CurtainSystem_clicked();
    void on_DoorSystem_clicked();
    void on_WindSystem_clicked();
    void on_LightSystem_clicked();
    void on_AirSystem_clicked();
    void on_WindowSystem_clicked();

signals:
    void Show_SubUi();
    void Show_Window_SubUi();
    //TCP 信号
    void SendData();
    void ServerListen();
    void ServerClose();
    void OneNetStart();
    void SendToOneNet(QString,int);
    void StartCrawl();
protected:

private:
    Ui::frmMain *ui;
};


#endif // FRMMAIN_H
