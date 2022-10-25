#ifndef FRMMAIN_H
#define FRMMAIN_H

#include <QWidget>
#include"frmtcpclient.h"
#include <QMouseEvent>

namespace Ui {
class frmMain;
}

class frmMain : public QWidget
{
    Q_OBJECT

public:
    explicit frmMain(QWidget *parent = 0);
    ~frmMain();
private slots:
    void on_tabWidget_currentChanged(int index);
    void saveConfig();
    void initConfig();
    void ClientConfig();
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
