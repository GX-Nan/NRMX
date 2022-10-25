#include "qlistwidgetmouse.h"

QListWidgetMouse::QListWidgetMouse(QWidget *parent) : QListWidget(parent)
{

}

void QListWidgetMouse::enterEvent(QEvent *event)
{
    QListWidget::enterEvent(event);
}

void QListWidgetMouse::mousePressEvent(QMouseEvent *ev)
{
    QListWidget::mousePressEvent(ev);
}
