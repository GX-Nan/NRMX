#include "windowbox.h"
#include "ui_windowbox.h"

WindowBox::WindowBox(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WindowBox)
{
    ui->setupUi(this);
}

WindowBox::~WindowBox()
{
    delete ui;
}
