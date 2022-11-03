#ifndef CURTAINSBOX_H
#define CURTAINSBOX_H

#include <QDialog>

namespace Ui {
class CurtainsBox;
}

class CurtainsBox : public QDialog
{
    Q_OBJECT

public:
    explicit CurtainsBox(QWidget *parent = nullptr);
    ~CurtainsBox();

private:
    Ui::CurtainsBox *ui;
};

#endif // CURTAINSBOX_H
