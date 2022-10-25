/********************************************************************************
** Form generated from reading UI file 'frmudpserver.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRMUDPSERVER_H
#define UI_FRMUDPSERVER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_frmUdpServer
{
public:
    QTextEdit *txtMain;
    QFrame *frame;
    QCheckBox *ckHexReceive;
    QCheckBox *ckHexSend;
    QCheckBox *ckAscii;
    QCheckBox *ckShow;
    QCheckBox *ckDebug;
    QCheckBox *ckAutoSend;
    QComboBox *cboxInterval;
    QLabel *labCount;
    QListWidget *listWidget;
    QCheckBox *ckSelectAll;
    QWidget *widget;
    QGridLayout *gridLayout;
    QLabel *labListenIP;
    QComboBox *cboxListenIP;
    QLabel *labListenPort;
    QLineEdit *txtListenPort;
    QWidget *widget1;
    QVBoxLayout *verticalLayout;
    QPushButton *btnListen;
    QPushButton *btnSave;
    QPushButton *btnClear;
    QWidget *widget2;
    QPushButton *btnSend;
    QComboBox *cboxData;

    void setupUi(QWidget *frmUdpServer)
    {
        if (frmUdpServer->objectName().isEmpty())
            frmUdpServer->setObjectName(QStringLiteral("frmUdpServer"));
        frmUdpServer->resize(433, 612);
        txtMain = new QTextEdit(frmUdpServer);
        txtMain->setObjectName(QStringLiteral("txtMain"));
        txtMain->setGeometry(QRect(9, 9, 211, 511));
        txtMain->setReadOnly(true);
        frame = new QFrame(frmUdpServer);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(230, 10, 200, 591));
        frame->setMinimumSize(QSize(170, 0));
        frame->setMaximumSize(QSize(200, 16777215));
        frame->setFrameShape(QFrame::Box);
        frame->setFrameShadow(QFrame::Sunken);
        ckHexReceive = new QCheckBox(frame);
        ckHexReceive->setObjectName(QStringLiteral("ckHexReceive"));
        ckHexReceive->setGeometry(QRect(11, 1, 171, 27));
        ckHexSend = new QCheckBox(frame);
        ckHexSend->setObjectName(QStringLiteral("ckHexSend"));
        ckHexSend->setGeometry(QRect(11, 34, 161, 27));
        ckAscii = new QCheckBox(frame);
        ckAscii->setObjectName(QStringLiteral("ckAscii"));
        ckAscii->setGeometry(QRect(11, 67, 129, 27));
        ckShow = new QCheckBox(frame);
        ckShow->setObjectName(QStringLiteral("ckShow"));
        ckShow->setGeometry(QRect(11, 100, 95, 27));
        ckDebug = new QCheckBox(frame);
        ckDebug->setObjectName(QStringLiteral("ckDebug"));
        ckDebug->setGeometry(QRect(11, 133, 95, 27));
        ckAutoSend = new QCheckBox(frame);
        ckAutoSend->setObjectName(QStringLiteral("ckAutoSend"));
        ckAutoSend->setGeometry(QRect(11, 166, 95, 27));
        cboxInterval = new QComboBox(frame);
        cboxInterval->setObjectName(QStringLiteral("cboxInterval"));
        cboxInterval->setGeometry(QRect(110, 160, 83, 32));
        labCount = new QLabel(frame);
        labCount->setObjectName(QStringLiteral("labCount"));
        labCount->setGeometry(QRect(10, 448, 178, 25));
        labCount->setMinimumSize(QSize(0, 25));
        labCount->setFrameShape(QFrame::Box);
        labCount->setFrameShadow(QFrame::Sunken);
        labCount->setAlignment(Qt::AlignCenter);
        listWidget = new QListWidget(frame);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(10, 479, 178, 75));
        ckSelectAll = new QCheckBox(frame);
        ckSelectAll->setObjectName(QStringLiteral("ckSelectAll"));
        ckSelectAll->setGeometry(QRect(10, 560, 159, 27));
        widget = new QWidget(frame);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(10, 200, 181, 128));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        labListenIP = new QLabel(widget);
        labListenIP->setObjectName(QStringLiteral("labListenIP"));

        gridLayout->addWidget(labListenIP, 0, 0, 1, 1);

        cboxListenIP = new QComboBox(widget);
        cboxListenIP->setObjectName(QStringLiteral("cboxListenIP"));

        gridLayout->addWidget(cboxListenIP, 1, 0, 1, 1);

        labListenPort = new QLabel(widget);
        labListenPort->setObjectName(QStringLiteral("labListenPort"));

        gridLayout->addWidget(labListenPort, 2, 0, 1, 1);

        txtListenPort = new QLineEdit(widget);
        txtListenPort->setObjectName(QStringLiteral("txtListenPort"));

        gridLayout->addWidget(txtListenPort, 3, 0, 1, 1);

        widget1 = new QWidget(frame);
        widget1->setObjectName(QStringLiteral("widget1"));
        widget1->setGeometry(QRect(10, 338, 181, 104));
        verticalLayout = new QVBoxLayout(widget1);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        btnListen = new QPushButton(widget1);
        btnListen->setObjectName(QStringLiteral("btnListen"));

        verticalLayout->addWidget(btnListen);

        btnSave = new QPushButton(widget1);
        btnSave->setObjectName(QStringLiteral("btnSave"));

        verticalLayout->addWidget(btnSave);

        btnClear = new QPushButton(widget1);
        btnClear->setObjectName(QStringLiteral("btnClear"));

        verticalLayout->addWidget(btnClear);

        widget2 = new QWidget(frmUdpServer);
        widget2->setObjectName(QStringLiteral("widget2"));
        widget2->setGeometry(QRect(10, 530, 191, 32));
        btnSend = new QPushButton(frmUdpServer);
        btnSend->setObjectName(QStringLiteral("btnSend"));
        btnSend->setGeometry(QRect(140, 570, 80, 30));
        btnSend->setMinimumSize(QSize(80, 0));
        btnSend->setMaximumSize(QSize(80, 16777215));
        cboxData = new QComboBox(frmUdpServer);
        cboxData->setObjectName(QStringLiteral("cboxData"));
        cboxData->setGeometry(QRect(8, 530, 211, 32));
        QSizePolicy sizePolicy(QSizePolicy::Ignored, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(cboxData->sizePolicy().hasHeightForWidth());
        cboxData->setSizePolicy(sizePolicy);
        cboxData->setEditable(true);
        QWidget::setTabOrder(txtMain, ckHexReceive);
        QWidget::setTabOrder(ckHexReceive, ckHexSend);
        QWidget::setTabOrder(ckHexSend, ckAscii);
        QWidget::setTabOrder(ckAscii, ckShow);
        QWidget::setTabOrder(ckShow, ckDebug);
        QWidget::setTabOrder(ckDebug, ckAutoSend);
        QWidget::setTabOrder(ckAutoSend, cboxInterval);
        QWidget::setTabOrder(cboxInterval, cboxListenIP);
        QWidget::setTabOrder(cboxListenIP, txtListenPort);
        QWidget::setTabOrder(txtListenPort, btnListen);
        QWidget::setTabOrder(btnListen, btnSave);
        QWidget::setTabOrder(btnSave, btnClear);

        retranslateUi(frmUdpServer);

        QMetaObject::connectSlotsByName(frmUdpServer);
    } // setupUi

    void retranslateUi(QWidget *frmUdpServer)
    {
        frmUdpServer->setWindowTitle(QApplication::translate("frmUdpServer", "Form", nullptr));
        ckHexReceive->setText(QApplication::translate("frmUdpServer", "Encrypted reception", nullptr));
        ckHexSend->setText(QApplication::translate("frmUdpServer", "Encrypted send", nullptr));
        ckAscii->setText(QApplication::translate("frmUdpServer", "Ascii\346\216\247\345\210\266\345\255\227\347\254\246", nullptr));
        ckShow->setText(QApplication::translate("frmUdpServer", "\346\232\202\345\201\234\346\230\276\347\244\272", nullptr));
        ckDebug->setText(QApplication::translate("frmUdpServer", "\346\250\241\346\213\237\350\256\276\345\244\207", nullptr));
        ckAutoSend->setText(QApplication::translate("frmUdpServer", "\345\256\232\346\227\266\345\217\221\351\200\201", nullptr));
        labCount->setText(QApplication::translate("frmUdpServer", "\345\205\261 0 \344\270\252\345\256\242\346\210\267\347\253\257", nullptr));
        ckSelectAll->setText(QApplication::translate("frmUdpServer", "\345\257\271\346\211\200\346\234\211\345\256\242\346\210\267\347\253\257\345\217\221\351\200\201", nullptr));
        labListenIP->setText(QApplication::translate("frmUdpServer", "\347\233\221\345\220\254\345\234\260\345\235\200", nullptr));
        labListenPort->setText(QApplication::translate("frmUdpServer", "\347\233\221\345\220\254\347\253\257\345\217\243", nullptr));
        btnListen->setText(QApplication::translate("frmUdpServer", "\347\233\221\345\220\254", nullptr));
        btnSave->setText(QApplication::translate("frmUdpServer", "\344\277\235\345\255\230", nullptr));
        btnClear->setText(QApplication::translate("frmUdpServer", "\346\270\205\347\251\272", nullptr));
        btnSend->setText(QApplication::translate("frmUdpServer", "\345\217\221\351\200\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class frmUdpServer: public Ui_frmUdpServer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRMUDPSERVER_H
