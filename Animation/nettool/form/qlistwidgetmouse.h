#ifndef QLISTWIDGETMOUSE_H
#define QLISTWIDGETMOUSE_H

#include <QWidget>
#include<QListWidget>
#include<QDebug>

class QListWidgetMouse : public QListWidget
{
    Q_OBJECT
public:
    explicit QListWidgetMouse(QWidget *parent = nullptr);
protected:
    void enterEvent(QEvent *event) override;
    void mousePressEvent(QMouseEvent *ev) override;
signals:

};

#endif // QLISTWIDGETMOUSE_H
