#include "curtainsbox.h"
#include "ui_curtainsbox.h"

CurtainsBox::CurtainsBox(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CurtainsBox)
{
    ui->setupUi(this);
}

CurtainsBox::~CurtainsBox()
{
    delete ui;
}
