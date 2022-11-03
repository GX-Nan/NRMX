#ifndef WINDOWBOX_H
#define WINDOWBOX_H

#include <QDialog>

namespace Ui {
class WindowBox;
}

class WindowBox : public QDialog
{
    Q_OBJECT

public:
    explicit WindowBox(QWidget *parent = nullptr);
    ~WindowBox();
signals:
    void CloseShawdown();
private:
    Ui::WindowBox *ui;
};

#endif // WINDOWBOX_H
