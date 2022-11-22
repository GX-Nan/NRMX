/********************************************************************************
** Form generated from reading UI file 'uiipsreach.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UIIPSREACH_H
#define UI_UIIPSREACH_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <qlistwidgetmouse.h>

QT_BEGIN_NAMESPACE

class Ui_UiIPSreach
{
public:
    QLabel *labServerPort_4;
    QPushButton *ToConnect;
    QPushButton *Disconnect;
    QLabel *labServerPort_2;
    QListWidgetMouse *Mouselist;
    QLabel *labServerPort_3;
    QLineEdit *IP;
    QPushButton *FindIP;
    QLabel *labServerIP_2;
    QLabel *labServerPort_5;
    QPushButton *ClientSend;
    QLineEdit *Port;
    QTextEdit *MsgMain;
    QLineEdit *MainSend;
    QPushButton *pushButton;

    void setupUi(QDialog *UiIPSreach)
    {
        if (UiIPSreach->objectName().isEmpty())
            UiIPSreach->setObjectName(QString::fromUtf8("UiIPSreach"));
        UiIPSreach->resize(547, 525);
        labServerPort_4 = new QLabel(UiIPSreach);
        labServerPort_4->setObjectName(QString::fromUtf8("labServerPort_4"));
        labServerPort_4->setGeometry(QRect(350, 390, 81, 34));
        labServerPort_4->setAlignment(Qt::AlignCenter);
        ToConnect = new QPushButton(UiIPSreach);
        ToConnect->setObjectName(QString::fromUtf8("ToConnect"));
        ToConnect->setGeometry(QRect(260, 30, 75, 23));
        Disconnect = new QPushButton(UiIPSreach);
        Disconnect->setObjectName(QString::fromUtf8("Disconnect"));
        Disconnect->setGeometry(QRect(260, 90, 75, 23));
        labServerPort_2 = new QLabel(UiIPSreach);
        labServerPort_2->setObjectName(QString::fromUtf8("labServerPort_2"));
        labServerPort_2->setGeometry(QRect(400, 120, 81, 34));
        labServerPort_2->setAlignment(Qt::AlignCenter);
        Mouselist = new QListWidgetMouse(UiIPSreach);
        Mouselist->setObjectName(QString::fromUtf8("Mouselist"));
        Mouselist->setGeometry(QRect(30, 70, 181, 331));
        labServerPort_3 = new QLabel(UiIPSreach);
        labServerPort_3->setObjectName(QString::fromUtf8("labServerPort_3"));
        labServerPort_3->setGeometry(QRect(350, 310, 81, 34));
        labServerPort_3->setAlignment(Qt::AlignCenter);
        IP = new QLineEdit(UiIPSreach);
        IP->setObjectName(QString::fromUtf8("IP"));
        IP->setGeometry(QRect(370, 24, 144, 20));
        FindIP = new QPushButton(UiIPSreach);
        FindIP->setObjectName(QString::fromUtf8("FindIP"));
        FindIP->setGeometry(QRect(60, 430, 121, 31));
        QFont font;
        font.setPointSize(13);
        FindIP->setFont(font);
        labServerIP_2 = new QLabel(UiIPSreach);
        labServerIP_2->setObjectName(QString::fromUtf8("labServerIP_2"));
        labServerIP_2->setGeometry(QRect(400, 50, 71, 34));
        labServerIP_2->setAlignment(Qt::AlignCenter);
        labServerPort_5 = new QLabel(UiIPSreach);
        labServerPort_5->setObjectName(QString::fromUtf8("labServerPort_5"));
        labServerPort_5->setGeometry(QRect(60, 20, 111, 51));
        QFont font1;
        font1.setPointSize(15);
        labServerPort_5->setFont(font1);
        labServerPort_5->setAlignment(Qt::AlignCenter);
        ClientSend = new QPushButton(UiIPSreach);
        ClientSend->setObjectName(QString::fromUtf8("ClientSend"));
        ClientSend->setGeometry(QRect(310, 430, 161, 31));
        ClientSend->setFont(font);
        Port = new QLineEdit(UiIPSreach);
        Port->setObjectName(QString::fromUtf8("Port"));
        Port->setGeometry(QRect(370, 90, 144, 20));
        MsgMain = new QTextEdit(UiIPSreach);
        MsgMain->setObjectName(QString::fromUtf8("MsgMain"));
        MsgMain->setGeometry(QRect(260, 150, 271, 151));
        MsgMain->setReadOnly(true);
        MainSend = new QLineEdit(UiIPSreach);
        MainSend->setObjectName(QString::fromUtf8("MainSend"));
        MainSend->setGeometry(QRect(260, 350, 271, 41));
        pushButton = new QPushButton(UiIPSreach);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(200, 470, 121, 31));
        pushButton->setFont(font1);

        retranslateUi(UiIPSreach);

        QMetaObject::connectSlotsByName(UiIPSreach);
    } // setupUi

    void retranslateUi(QDialog *UiIPSreach)
    {
        UiIPSreach->setWindowTitle(QCoreApplication::translate("UiIPSreach", "Dialog", nullptr));
        labServerPort_4->setText(QCoreApplication::translate("UiIPSreach", "\345\217\221\351\200\201\344\277\241\346\201\257", nullptr));
        ToConnect->setText(QCoreApplication::translate("UiIPSreach", "\350\277\236\346\216\245", nullptr));
        Disconnect->setText(QCoreApplication::translate("UiIPSreach", "\346\226\255\345\274\200", nullptr));
        labServerPort_2->setText(QCoreApplication::translate("UiIPSreach", "\350\277\234\347\250\213\347\253\257\345\217\243", nullptr));
        labServerPort_3->setText(QCoreApplication::translate("UiIPSreach", "\346\216\245\345\217\227\344\277\241\346\201\257", nullptr));
        FindIP->setText(QCoreApplication::translate("UiIPSreach", "\346\220\234\347\264\242", nullptr));
        labServerIP_2->setText(QCoreApplication::translate("UiIPSreach", "\350\277\234\347\250\213\345\234\260\345\235\200", nullptr));
        labServerPort_5->setText(QCoreApplication::translate("UiIPSreach", "IP\345\234\260\345\235\200", nullptr));
        ClientSend->setText(QCoreApplication::translate("UiIPSreach", "\345\217\221\351\200\201", nullptr));
        pushButton->setText(QCoreApplication::translate("UiIPSreach", "\345\205\263\351\227\255", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UiIPSreach: public Ui_UiIPSreach {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UIIPSREACH_H
