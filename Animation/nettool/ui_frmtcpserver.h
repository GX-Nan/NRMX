/********************************************************************************
** Form generated from reading UI file 'frmtcpserver.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRMTCPSERVER_H
#define UI_FRMTCPSERVER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_frmTcpServer
{
public:
    QTextEdit *txtMain;
    QFrame *frame;
    QCheckBox *ckDebug;
    QComboBox *cboxInterval;
    QLabel *labListenIP;
    QComboBox *cboxListenIP;
    QLabel *labListenPort;
    QLineEdit *txtListenPort;
    QLabel *labCount;
    QListWidget *listWidget;
    QCheckBox *ckSelectAll;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QPushButton *btnListen;
    QPushButton *btnClear;
    QPushButton *btnSave;
    QPushButton *btnClose;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout;
    QCheckBox *ckHexReceive;
    QCheckBox *ckHexSend;
    QCheckBox *ckAscii;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout_2;
    QCheckBox *ckShow;
    QCheckBox *ckAutoSend;
    QWidget *widget;
    QHBoxLayout *layTcpServer;
    QPushButton *btnSend;
    QComboBox *cboxData;

    void setupUi(QWidget *frmTcpServer)
    {
        if (frmTcpServer->objectName().isEmpty())
            frmTcpServer->setObjectName(QString::fromUtf8("frmTcpServer"));
        frmTcpServer->resize(433, 612);
        txtMain = new QTextEdit(frmTcpServer);
        txtMain->setObjectName(QString::fromUtf8("txtMain"));
        txtMain->setGeometry(QRect(10, 10, 211, 511));
        txtMain->setReadOnly(true);
        frame = new QFrame(frmTcpServer);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(230, 10, 201, 591));
        frame->setMinimumSize(QSize(170, 0));
        frame->setMaximumSize(QSize(250, 16777215));
        frame->setFrameShape(QFrame::Box);
        frame->setFrameShadow(QFrame::Sunken);
        ckDebug = new QCheckBox(frame);
        ckDebug->setObjectName(QString::fromUtf8("ckDebug"));
        ckDebug->setGeometry(QRect(100, 100, 95, 27));
        cboxInterval = new QComboBox(frame);
        cboxInterval->setObjectName(QString::fromUtf8("cboxInterval"));
        cboxInterval->setGeometry(QRect(110, 130, 83, 32));
        labListenIP = new QLabel(frame);
        labListenIP->setObjectName(QString::fromUtf8("labListenIP"));
        labListenIP->setGeometry(QRect(10, 166, 64, 22));
        cboxListenIP = new QComboBox(frame);
        cboxListenIP->setObjectName(QString::fromUtf8("cboxListenIP"));
        cboxListenIP->setGeometry(QRect(10, 194, 141, 32));
        labListenPort = new QLabel(frame);
        labListenPort->setObjectName(QString::fromUtf8("labListenPort"));
        labListenPort->setGeometry(QRect(10, 232, 64, 22));
        txtListenPort = new QLineEdit(frame);
        txtListenPort->setObjectName(QString::fromUtf8("txtListenPort"));
        txtListenPort->setGeometry(QRect(10, 260, 144, 32));
        labCount = new QLabel(frame);
        labCount->setObjectName(QString::fromUtf8("labCount"));
        labCount->setGeometry(QRect(10, 380, 148, 25));
        labCount->setMinimumSize(QSize(0, 25));
        labCount->setFrameShape(QFrame::Box);
        labCount->setFrameShadow(QFrame::Sunken);
        labCount->setAlignment(Qt::AlignCenter);
        listWidget = new QListWidget(frame);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(10, 410, 181, 141));
        ckSelectAll = new QCheckBox(frame);
        ckSelectAll->setObjectName(QString::fromUtf8("ckSelectAll"));
        ckSelectAll->setGeometry(QRect(10, 560, 171, 27));
        layoutWidget = new QWidget(frame);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 300, 178, 68));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        btnListen = new QPushButton(layoutWidget);
        btnListen->setObjectName(QString::fromUtf8("btnListen"));

        gridLayout->addWidget(btnListen, 0, 0, 1, 1);

        btnClear = new QPushButton(layoutWidget);
        btnClear->setObjectName(QString::fromUtf8("btnClear"));

        gridLayout->addWidget(btnClear, 0, 1, 1, 1);

        btnSave = new QPushButton(layoutWidget);
        btnSave->setObjectName(QString::fromUtf8("btnSave"));

        gridLayout->addWidget(btnSave, 1, 0, 1, 1);

        btnClose = new QPushButton(layoutWidget);
        btnClose->setObjectName(QString::fromUtf8("btnClose"));

        gridLayout->addWidget(btnClose, 1, 1, 1, 1);

        layoutWidget1 = new QWidget(frame);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 0, 174, 95));
        verticalLayout = new QVBoxLayout(layoutWidget1);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        ckHexReceive = new QCheckBox(layoutWidget1);
        ckHexReceive->setObjectName(QString::fromUtf8("ckHexReceive"));

        verticalLayout->addWidget(ckHexReceive);

        ckHexSend = new QCheckBox(layoutWidget1);
        ckHexSend->setObjectName(QString::fromUtf8("ckHexSend"));

        verticalLayout->addWidget(ckHexSend);

        ckAscii = new QCheckBox(layoutWidget1);
        ckAscii->setObjectName(QString::fromUtf8("ckAscii"));

        verticalLayout->addWidget(ckAscii);

        layoutWidget2 = new QWidget(frame);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(10, 100, 97, 62));
        verticalLayout_2 = new QVBoxLayout(layoutWidget2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        ckShow = new QCheckBox(layoutWidget2);
        ckShow->setObjectName(QString::fromUtf8("ckShow"));

        verticalLayout_2->addWidget(ckShow);

        ckAutoSend = new QCheckBox(layoutWidget2);
        ckAutoSend->setObjectName(QString::fromUtf8("ckAutoSend"));

        verticalLayout_2->addWidget(ckAutoSend);

        widget = new QWidget(frmTcpServer);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(10, 530, 201, 32));
        layTcpServer = new QHBoxLayout(widget);
        layTcpServer->setObjectName(QString::fromUtf8("layTcpServer"));
        layTcpServer->setContentsMargins(0, 0, 0, 0);
        btnSend = new QPushButton(frmTcpServer);
        btnSend->setObjectName(QString::fromUtf8("btnSend"));
        btnSend->setGeometry(QRect(140, 570, 80, 30));
        btnSend->setMinimumSize(QSize(80, 0));
        btnSend->setMaximumSize(QSize(80, 16777215));
        cboxData = new QComboBox(frmTcpServer);
        cboxData->setObjectName(QString::fromUtf8("cboxData"));
        cboxData->setGeometry(QRect(10, 530, 211, 32));
        QSizePolicy sizePolicy(QSizePolicy::Ignored, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(cboxData->sizePolicy().hasHeightForWidth());
        cboxData->setSizePolicy(sizePolicy);
        cboxData->setEditable(true);
        QWidget::setTabOrder(txtMain, ckHexReceive);
        QWidget::setTabOrder(ckHexReceive, ckAscii);
        QWidget::setTabOrder(ckAscii, ckShow);
        QWidget::setTabOrder(ckShow, ckDebug);
        QWidget::setTabOrder(ckDebug, ckAutoSend);
        QWidget::setTabOrder(ckAutoSend, cboxInterval);
        QWidget::setTabOrder(cboxInterval, cboxListenIP);
        QWidget::setTabOrder(cboxListenIP, txtListenPort);
        QWidget::setTabOrder(txtListenPort, btnListen);
        QWidget::setTabOrder(btnListen, btnSave);
        QWidget::setTabOrder(btnSave, btnClear);
        QWidget::setTabOrder(btnClear, btnClose);
        QWidget::setTabOrder(btnClose, listWidget);
        QWidget::setTabOrder(listWidget, ckSelectAll);

        retranslateUi(frmTcpServer);

        QMetaObject::connectSlotsByName(frmTcpServer);
    } // setupUi

    void retranslateUi(QWidget *frmTcpServer)
    {
        frmTcpServer->setWindowTitle(QCoreApplication::translate("frmTcpServer", "Form", nullptr));
        ckDebug->setText(QCoreApplication::translate("frmTcpServer", "\346\250\241\346\213\237\350\256\276\345\244\207", nullptr));
        labListenIP->setText(QCoreApplication::translate("frmTcpServer", "\347\233\221\345\220\254\345\234\260\345\235\200", nullptr));
        labListenPort->setText(QCoreApplication::translate("frmTcpServer", "\347\233\221\345\220\254\347\253\257\345\217\243", nullptr));
        labCount->setText(QCoreApplication::translate("frmTcpServer", "\345\205\261 0 \344\270\252\345\256\242\346\210\267\347\253\257", nullptr));
        ckSelectAll->setText(QCoreApplication::translate("frmTcpServer", "\345\257\271\346\211\200\346\234\211\345\256\242\346\210\267\347\253\257\345\217\221\351\200\201", nullptr));
        btnListen->setText(QCoreApplication::translate("frmTcpServer", "\347\233\221\345\220\254", nullptr));
        btnClear->setText(QCoreApplication::translate("frmTcpServer", "\346\270\205\347\251\272", nullptr));
        btnSave->setText(QCoreApplication::translate("frmTcpServer", "\344\277\235\345\255\230", nullptr));
        btnClose->setText(QCoreApplication::translate("frmTcpServer", "\346\226\255\345\274\200", nullptr));
        ckHexReceive->setText(QCoreApplication::translate("frmTcpServer", "Encrypted reception", nullptr));
        ckHexSend->setText(QCoreApplication::translate("frmTcpServer", "Encrypted send", nullptr));
        ckAscii->setText(QCoreApplication::translate("frmTcpServer", "Ascii\346\216\247\345\210\266\345\255\227\347\254\246", nullptr));
        ckShow->setText(QCoreApplication::translate("frmTcpServer", "\346\232\202\345\201\234\346\230\276\347\244\272", nullptr));
        ckAutoSend->setText(QCoreApplication::translate("frmTcpServer", "\345\256\232\346\227\266\345\217\221\351\200\201", nullptr));
        btnSend->setText(QCoreApplication::translate("frmTcpServer", "\345\217\221\351\200\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class frmTcpServer: public Ui_frmTcpServer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRMTCPSERVER_H
