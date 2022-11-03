#ifndef FRMMAIN_H
#define FRMMAIN_H

#include <QWidget>
#include"frmtcpclient.h"
#include <QMouseEvent>
#include <curtainsbox.h>
#include <windowbox.h>
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
private slots:
    void on_tabWidget_currentChanged(int index);
    void saveConfig();
    void initConfig();
    void on_UISreachIP_clicked();
    void ClientConfig();
    void ShadowInit();
    void paintEvent(QPaintEvent *);
    void ProgressInit();
    void on_WindowBox_clicked();
    void on_CurtainsBox_clicked();
    void BackdropInit();

signals:
    void ShowUiSreachIP();
    void ExecUiSreachIP();
    void ClientConnect();

public:


protected:

private:
    Ui::frmMain *ui;
};


#endif // FRMMAIN_H
