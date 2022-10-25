#ifndef DOORSYSTEM_H
#define DOORSYSTEM_H

#include <QDialog>

namespace Ui {
class DoorSystem;
}

class DoorSystem : public QDialog
{
    Q_OBJECT

public:
    explicit DoorSystem(QWidget *parent = nullptr);
    ~DoorSystem();
    void Shawdow();

private slots:
    void on_BackMain_clicked();
    void on_OpenDoor_clicked();
    void on_CloseDoor_clicked();
    void ButtonStyle(QPushButton* Name,int Offset,int BlurRadius);
private:
    int Door_Flag=0;

signals:
    void SendClose();
private:
    Ui::DoorSystem *ui;
};

#endif // DOORSYSTEM_H
