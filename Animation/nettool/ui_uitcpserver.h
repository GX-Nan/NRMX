/********************************************************************************
** Form generated from reading UI file 'uitcpserver.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UITCPSERVER_H
#define UI_UITCPSERVER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_uiTcpServer
{
public:
    QTextEdit *txtMain;
    QLineEdit *SendText;
    QPushButton *SendData;
    QWidget *layoutWidget_2;
    QVBoxLayout *verticalLayout;
    QComboBox *cboxListenIP;
    QSpacerItem *verticalSpacer;
    QLineEdit *txtListenPort;
    QSpacerItem *verticalSpacer_2;
    QListWidget *listWidget;
    QSpacerItem *verticalSpacer_3;
    QLabel *labCount;
    QPushButton *Listen;
    QPushButton *DisListen;
    QPushButton *Close_Ui;

    void setupUi(QDialog *uiTcpServer)
    {
        if (uiTcpServer->objectName().isEmpty())
            uiTcpServer->setObjectName(QStringLiteral("uiTcpServer"));
        uiTcpServer->resize(536, 469);
        txtMain = new QTextEdit(uiTcpServer);
        txtMain->setObjectName(QStringLiteral("txtMain"));
        txtMain->setGeometry(QRect(30, 30, 211, 341));
        txtMain->setReadOnly(true);
        SendText = new QLineEdit(uiTcpServer);
        SendText->setObjectName(QStringLiteral("SendText"));
        SendText->setGeometry(QRect(30, 390, 211, 31));
        SendData = new QPushButton(uiTcpServer);
        SendData->setObjectName(QStringLiteral("SendData"));
        SendData->setGeometry(QRect(330, 390, 121, 31));
        layoutWidget_2 = new QWidget(uiTcpServer);
        layoutWidget_2->setObjectName(QStringLiteral("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(300, 10, 191, 371));
        verticalLayout = new QVBoxLayout(layoutWidget_2);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        cboxListenIP = new QComboBox(layoutWidget_2);
        cboxListenIP->setObjectName(QStringLiteral("cboxListenIP"));

        verticalLayout->addWidget(cboxListenIP);

        verticalSpacer = new QSpacerItem(20, 17, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        txtListenPort = new QLineEdit(layoutWidget_2);
        txtListenPort->setObjectName(QStringLiteral("txtListenPort"));

        verticalLayout->addWidget(txtListenPort);

        verticalSpacer_2 = new QSpacerItem(20, 17, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        listWidget = new QListWidget(layoutWidget_2);
        listWidget->setObjectName(QStringLiteral("listWidget"));

        verticalLayout->addWidget(listWidget);

        verticalSpacer_3 = new QSpacerItem(20, 17, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);

        labCount = new QLabel(layoutWidget_2);
        labCount->setObjectName(QStringLiteral("labCount"));
        labCount->setMinimumSize(QSize(0, 25));
        labCount->setFrameShape(QFrame::Box);
        labCount->setFrameShadow(QFrame::Sunken);
        labCount->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(labCount);

        Listen = new QPushButton(layoutWidget_2);
        Listen->setObjectName(QStringLiteral("Listen"));

        verticalLayout->addWidget(Listen);

        DisListen = new QPushButton(layoutWidget_2);
        DisListen->setObjectName(QStringLiteral("DisListen"));

        verticalLayout->addWidget(DisListen);

        Close_Ui = new QPushButton(uiTcpServer);
        Close_Ui->setObjectName(QStringLiteral("Close_Ui"));
        Close_Ui->setGeometry(QRect(210, 430, 121, 31));

        retranslateUi(uiTcpServer);

        QMetaObject::connectSlotsByName(uiTcpServer);
    } // setupUi

    void retranslateUi(QDialog *uiTcpServer)
    {
        uiTcpServer->setWindowTitle(QApplication::translate("uiTcpServer", "Dialog", nullptr));
        SendData->setText(QApplication::translate("uiTcpServer", "\345\217\221\351\200\201", nullptr));
        labCount->setText(QApplication::translate("uiTcpServer", "\345\205\261 0 \344\270\252\345\256\242\346\210\267\347\253\257", nullptr));
        Listen->setText(QApplication::translate("uiTcpServer", "\345\274\200\345\247\213\347\233\221\345\220\254", nullptr));
        DisListen->setText(QApplication::translate("uiTcpServer", "\346\226\255\345\274\200", nullptr));
        Close_Ui->setText(QApplication::translate("uiTcpServer", "\345\205\263\351\227\255", nullptr));
    } // retranslateUi

};

namespace Ui {
    class uiTcpServer: public Ui_uiTcpServer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UITCPSERVER_H
