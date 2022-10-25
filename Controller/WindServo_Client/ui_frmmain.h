/********************************************************************************
** Form generated from reading UI file 'frmmain.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRMMAIN_H
#define UI_FRMMAIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>
#include "frmtcpclient.h"
#include "frmtcpserver.h"
#include "frmudpclient.h"
#include "frmudpserver.h"

QT_BEGIN_NAMESPACE

class Ui_frmMain
{
public:
    QGroupBox *groupBox;
    QTabWidget *tabWidget;
    frmTcpClient *tabTcpClient;
    frmTcpServer *tabTcpServer;
    frmUdpClient *tabUdpClient;
    frmUdpServer *tabUdpServer;

    void setupUi(QWidget *frmMain)
    {
        if (frmMain->objectName().isEmpty())
            frmMain->setObjectName(QStringLiteral("frmMain"));
        frmMain->resize(1520, 815);
        groupBox = new QGroupBox(frmMain);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(0, 70, 1081, 671));
        tabWidget = new QTabWidget(groupBox);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(0, 20, 1141, 641));
        tabWidget->setMinimumSize(QSize(300, 605));
        tabWidget->setStyleSheet(QStringLiteral(""));
        tabWidget->setTabPosition(QTabWidget::South);
        tabTcpClient = new frmTcpClient();
        tabTcpClient->setObjectName(QStringLiteral("tabTcpClient"));
        tabWidget->addTab(tabTcpClient, QString());
        tabTcpServer = new frmTcpServer();
        tabTcpServer->setObjectName(QStringLiteral("tabTcpServer"));
        tabWidget->addTab(tabTcpServer, QString());
        tabUdpClient = new frmUdpClient();
        tabUdpClient->setObjectName(QStringLiteral("tabUdpClient"));
        tabWidget->addTab(tabUdpClient, QString());
        tabUdpServer = new frmUdpServer();
        tabUdpServer->setObjectName(QStringLiteral("tabUdpServer"));
        tabWidget->addTab(tabUdpServer, QString());

        retranslateUi(frmMain);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(frmMain);
    } // setupUi

    void retranslateUi(QWidget *frmMain)
    {
        frmMain->setWindowTitle(QApplication::translate("frmMain", "Form", nullptr));
        groupBox->setTitle(QApplication::translate("frmMain", "Communication", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabTcpClient), QApplication::translate("frmMain", "TCP\345\256\242\346\210\267\347\253\257", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabTcpServer), QApplication::translate("frmMain", "TCP\346\234\215\345\212\241\345\231\250", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabUdpClient), QApplication::translate("frmMain", "UDP\345\256\242\346\210\267\347\253\257", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabUdpServer), QApplication::translate("frmMain", "UDP\346\234\215\345\212\241\345\231\250", nullptr));
    } // retranslateUi

};

namespace Ui {
    class frmMain: public Ui_frmMain {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRMMAIN_H
