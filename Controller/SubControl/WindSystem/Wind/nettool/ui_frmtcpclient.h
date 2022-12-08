/********************************************************************************
** Form generated from reading UI file 'frmtcpclient.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRMTCPCLIENT_H
#define UI_FRMTCPCLIENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_frmTcpClient
{
public:
    QTextEdit *txtMain;
    QFrame *frame;
    QComboBox *cboxInterval;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QCheckBox *ckHexReceive;
    QCheckBox *ckHexSend;
    QCheckBox *ckAscii;
    QCheckBox *ckShow;
    QCheckBox *ckDebug;
    QCheckBox *ckAutoSend;
    QWidget *widget1;
    QGridLayout *gridLayout;
    QLabel *labServerIP;
    QLineEdit *txtServerIP;
    QLabel *labServerPort;
    QLineEdit *txtServerPort;
    QWidget *widget2;
    QVBoxLayout *verticalLayout_2;
    QPushButton *btnConnect;
    QPushButton *btnSave;
    QPushButton *btnClear;
    QWidget *widget3;
    QHBoxLayout *layTcpClient;
    QPushButton *btnSend;
    QComboBox *cboxData;

    void setupUi(QWidget *frmTcpClient)
    {
        if (frmTcpClient->objectName().isEmpty())
            frmTcpClient->setObjectName(QString::fromUtf8("frmTcpClient"));
        frmTcpClient->resize(433, 612);
        txtMain = new QTextEdit(frmTcpClient);
        txtMain->setObjectName(QString::fromUtf8("txtMain"));
        txtMain->setGeometry(QRect(10, 10, 211, 511));
        txtMain->setReadOnly(true);
        frame = new QFrame(frmTcpClient);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(230, 10, 196, 591));
        frame->setMinimumSize(QSize(170, 400));
        frame->setMaximumSize(QSize(200, 16777215));
        frame->setFrameShape(QFrame::Box);
        frame->setFrameShadow(QFrame::Sunken);
        cboxInterval = new QComboBox(frame);
        cboxInterval->setObjectName(QString::fromUtf8("cboxInterval"));
        cboxInterval->setGeometry(QRect(10, 240, 111, 32));
        widget = new QWidget(frame);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(11, 11, 174, 221));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        ckHexReceive = new QCheckBox(widget);
        ckHexReceive->setObjectName(QString::fromUtf8("ckHexReceive"));

        verticalLayout->addWidget(ckHexReceive);

        ckHexSend = new QCheckBox(widget);
        ckHexSend->setObjectName(QString::fromUtf8("ckHexSend"));

        verticalLayout->addWidget(ckHexSend);

        ckAscii = new QCheckBox(widget);
        ckAscii->setObjectName(QString::fromUtf8("ckAscii"));

        verticalLayout->addWidget(ckAscii);

        ckShow = new QCheckBox(widget);
        ckShow->setObjectName(QString::fromUtf8("ckShow"));

        verticalLayout->addWidget(ckShow);

        ckDebug = new QCheckBox(widget);
        ckDebug->setObjectName(QString::fromUtf8("ckDebug"));

        verticalLayout->addWidget(ckDebug);

        ckAutoSend = new QCheckBox(widget);
        ckAutoSend->setObjectName(QString::fromUtf8("ckAutoSend"));

        verticalLayout->addWidget(ckAutoSend);

        widget1 = new QWidget(frame);
        widget1->setObjectName(QString::fromUtf8("widget1"));
        widget1->setGeometry(QRect(12, 284, 171, 161));
        gridLayout = new QGridLayout(widget1);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        labServerIP = new QLabel(widget1);
        labServerIP->setObjectName(QString::fromUtf8("labServerIP"));

        gridLayout->addWidget(labServerIP, 0, 0, 1, 1);

        txtServerIP = new QLineEdit(widget1);
        txtServerIP->setObjectName(QString::fromUtf8("txtServerIP"));

        gridLayout->addWidget(txtServerIP, 1, 0, 1, 1);

        labServerPort = new QLabel(widget1);
        labServerPort->setObjectName(QString::fromUtf8("labServerPort"));

        gridLayout->addWidget(labServerPort, 2, 0, 1, 1);

        txtServerPort = new QLineEdit(widget1);
        txtServerPort->setObjectName(QString::fromUtf8("txtServerPort"));

        gridLayout->addWidget(txtServerPort, 3, 0, 1, 1);

        widget2 = new QWidget(frame);
        widget2->setObjectName(QString::fromUtf8("widget2"));
        widget2->setGeometry(QRect(10, 460, 171, 121));
        verticalLayout_2 = new QVBoxLayout(widget2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        btnConnect = new QPushButton(widget2);
        btnConnect->setObjectName(QString::fromUtf8("btnConnect"));

        verticalLayout_2->addWidget(btnConnect);

        btnSave = new QPushButton(widget2);
        btnSave->setObjectName(QString::fromUtf8("btnSave"));

        verticalLayout_2->addWidget(btnSave);

        btnClear = new QPushButton(widget2);
        btnClear->setObjectName(QString::fromUtf8("btnClear"));

        verticalLayout_2->addWidget(btnClear);

        widget3 = new QWidget(frmTcpClient);
        widget3->setObjectName(QString::fromUtf8("widget3"));
        widget3->setGeometry(QRect(10, 530, 211, 32));
        layTcpClient = new QHBoxLayout(widget3);
        layTcpClient->setObjectName(QString::fromUtf8("layTcpClient"));
        layTcpClient->setContentsMargins(0, 0, 0, 0);
        btnSend = new QPushButton(frmTcpClient);
        btnSend->setObjectName(QString::fromUtf8("btnSend"));
        btnSend->setGeometry(QRect(140, 570, 80, 30));
        btnSend->setMinimumSize(QSize(80, 0));
        btnSend->setMaximumSize(QSize(80, 16777215));
        cboxData = new QComboBox(frmTcpClient);
        cboxData->setObjectName(QString::fromUtf8("cboxData"));
        cboxData->setGeometry(QRect(10, 530, 211, 32));
        QSizePolicy sizePolicy(QSizePolicy::Ignored, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(cboxData->sizePolicy().hasHeightForWidth());
        cboxData->setSizePolicy(sizePolicy);
        cboxData->setEditable(true);

        retranslateUi(frmTcpClient);

        QMetaObject::connectSlotsByName(frmTcpClient);
    } // setupUi

    void retranslateUi(QWidget *frmTcpClient)
    {
        frmTcpClient->setWindowTitle(QCoreApplication::translate("frmTcpClient", "Form", nullptr));
        ckHexReceive->setText(QCoreApplication::translate("frmTcpClient", "Encrypted reception", nullptr));
        ckHexSend->setText(QCoreApplication::translate("frmTcpClient", "Encrypted send", nullptr));
        ckAscii->setText(QCoreApplication::translate("frmTcpClient", "Ascii\346\216\247\345\210\266\345\255\227\347\254\246", nullptr));
        ckShow->setText(QCoreApplication::translate("frmTcpClient", "\346\232\202\345\201\234\346\230\276\347\244\272", nullptr));
        ckDebug->setText(QCoreApplication::translate("frmTcpClient", "\346\250\241\346\213\237\350\256\276\345\244\207", nullptr));
        ckAutoSend->setText(QCoreApplication::translate("frmTcpClient", "\345\256\232\346\227\266\345\217\221\351\200\201", nullptr));
        labServerIP->setText(QCoreApplication::translate("frmTcpClient", "\346\234\215\345\212\241\345\231\250\345\234\260\345\235\200", nullptr));
        labServerPort->setText(QCoreApplication::translate("frmTcpClient", "\346\234\215\345\212\241\345\231\250\347\253\257\345\217\243", nullptr));
        btnConnect->setText(QCoreApplication::translate("frmTcpClient", "\350\277\236\346\216\245", nullptr));
        btnSave->setText(QCoreApplication::translate("frmTcpClient", "\344\277\235\345\255\230", nullptr));
        btnClear->setText(QCoreApplication::translate("frmTcpClient", "\346\270\205\347\251\272", nullptr));
        btnSend->setText(QCoreApplication::translate("frmTcpClient", "\345\217\221\351\200\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class frmTcpClient: public Ui_frmTcpClient {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRMTCPCLIENT_H
