/********************************************************************************
** Form generated from reading UI file 'frmudpclient.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRMUDPCLIENT_H
#define UI_FRMUDPCLIENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_frmUdpClient
{
public:
    QTextEdit *txtMain;
    QFrame *frame;
    QCheckBox *ckHexReceive;
    QCheckBox *ckHexSend;
    QCheckBox *ckAscii;
    QCheckBox *ckShow;
    QCheckBox *ckDebug;
    QPushButton *btnSave;
    QPushButton *btnClear;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QLabel *labServerIP;
    QLineEdit *txtServerIP;
    QLabel *labServerPort;
    QLineEdit *txtServerPort;
    QWidget *widget1;
    QVBoxLayout *verticalLayout_2;
    QCheckBox *ckAutoSend;
    QComboBox *cboxInterval;
    QWidget *widget2;
    QPushButton *btnSend;
    QComboBox *cboxData;

    void setupUi(QWidget *frmUdpClient)
    {
        if (frmUdpClient->objectName().isEmpty())
            frmUdpClient->setObjectName(QStringLiteral("frmUdpClient"));
        frmUdpClient->resize(433, 612);
        txtMain = new QTextEdit(frmUdpClient);
        txtMain->setObjectName(QStringLiteral("txtMain"));
        txtMain->setGeometry(QRect(9, 9, 211, 509));
        txtMain->setReadOnly(true);
        frame = new QFrame(frmUdpClient);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(240, 10, 181, 591));
        frame->setMinimumSize(QSize(170, 0));
        frame->setMaximumSize(QSize(200, 16777215));
        frame->setFrameShape(QFrame::Box);
        frame->setFrameShadow(QFrame::Sunken);
        ckHexReceive = new QCheckBox(frame);
        ckHexReceive->setObjectName(QStringLiteral("ckHexReceive"));
        ckHexReceive->setGeometry(QRect(11, 11, 171, 27));
        ckHexSend = new QCheckBox(frame);
        ckHexSend->setObjectName(QStringLiteral("ckHexSend"));
        ckHexSend->setGeometry(QRect(11, 44, 171, 27));
        ckAscii = new QCheckBox(frame);
        ckAscii->setObjectName(QStringLiteral("ckAscii"));
        ckAscii->setGeometry(QRect(11, 77, 129, 27));
        ckShow = new QCheckBox(frame);
        ckShow->setObjectName(QStringLiteral("ckShow"));
        ckShow->setGeometry(QRect(11, 110, 95, 27));
        ckDebug = new QCheckBox(frame);
        ckDebug->setObjectName(QStringLiteral("ckDebug"));
        ckDebug->setGeometry(QRect(11, 143, 95, 27));
        btnSave = new QPushButton(frame);
        btnSave->setObjectName(QStringLiteral("btnSave"));
        btnSave->setGeometry(QRect(11, 474, 85, 30));
        btnClear = new QPushButton(frame);
        btnClear->setObjectName(QStringLiteral("btnClear"));
        btnClear->setGeometry(QRect(11, 510, 85, 30));
        widget = new QWidget(frame);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(10, 310, 146, 128));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        labServerIP = new QLabel(widget);
        labServerIP->setObjectName(QStringLiteral("labServerIP"));

        verticalLayout->addWidget(labServerIP);

        txtServerIP = new QLineEdit(widget);
        txtServerIP->setObjectName(QStringLiteral("txtServerIP"));

        verticalLayout->addWidget(txtServerIP);

        labServerPort = new QLabel(widget);
        labServerPort->setObjectName(QStringLiteral("labServerPort"));

        verticalLayout->addWidget(labServerPort);

        txtServerPort = new QLineEdit(widget);
        txtServerPort->setObjectName(QStringLiteral("txtServerPort"));

        verticalLayout->addWidget(txtServerPort);

        widget1 = new QWidget(frame);
        widget1->setObjectName(QStringLiteral("widget1"));
        widget1->setGeometry(QRect(10, 190, 97, 67));
        verticalLayout_2 = new QVBoxLayout(widget1);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        ckAutoSend = new QCheckBox(widget1);
        ckAutoSend->setObjectName(QStringLiteral("ckAutoSend"));

        verticalLayout_2->addWidget(ckAutoSend);

        cboxInterval = new QComboBox(widget1);
        cboxInterval->setObjectName(QStringLiteral("cboxInterval"));

        verticalLayout_2->addWidget(cboxInterval);

        widget2 = new QWidget(frmUdpClient);
        widget2->setObjectName(QStringLiteral("widget2"));
        widget2->setGeometry(QRect(10, 530, 211, 32));
        btnSend = new QPushButton(frmUdpClient);
        btnSend->setObjectName(QStringLiteral("btnSend"));
        btnSend->setGeometry(QRect(140, 570, 80, 30));
        btnSend->setMinimumSize(QSize(80, 0));
        btnSend->setMaximumSize(QSize(80, 16777215));
        cboxData = new QComboBox(frmUdpClient);
        cboxData->setObjectName(QStringLiteral("cboxData"));
        cboxData->setGeometry(QRect(10, 530, 211, 32));
        QSizePolicy sizePolicy(QSizePolicy::Ignored, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(cboxData->sizePolicy().hasHeightForWidth());
        cboxData->setSizePolicy(sizePolicy);
        cboxData->setEditable(true);

        retranslateUi(frmUdpClient);

        QMetaObject::connectSlotsByName(frmUdpClient);
    } // setupUi

    void retranslateUi(QWidget *frmUdpClient)
    {
        frmUdpClient->setWindowTitle(QApplication::translate("frmUdpClient", "Form", nullptr));
        ckHexReceive->setText(QApplication::translate("frmUdpClient", "Encrypted reception", nullptr));
        ckHexSend->setText(QApplication::translate("frmUdpClient", "Encrypted send", nullptr));
        ckAscii->setText(QApplication::translate("frmUdpClient", "Ascii\346\216\247\345\210\266\345\255\227\347\254\246", nullptr));
        ckShow->setText(QApplication::translate("frmUdpClient", "\346\232\202\345\201\234\346\230\276\347\244\272", nullptr));
        ckDebug->setText(QApplication::translate("frmUdpClient", "\346\250\241\346\213\237\350\256\276\345\244\207", nullptr));
        btnSave->setText(QApplication::translate("frmUdpClient", "\344\277\235\345\255\230", nullptr));
        btnClear->setText(QApplication::translate("frmUdpClient", "\346\270\205\347\251\272", nullptr));
        labServerIP->setText(QApplication::translate("frmUdpClient", "\350\277\234\347\250\213\345\234\260\345\235\200", nullptr));
        labServerPort->setText(QApplication::translate("frmUdpClient", "\350\277\234\347\250\213\347\253\257\345\217\243", nullptr));
        ckAutoSend->setText(QApplication::translate("frmUdpClient", "\345\256\232\346\227\266\345\217\221\351\200\201", nullptr));
        btnSend->setText(QApplication::translate("frmUdpClient", "\345\217\221\351\200\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class frmUdpClient: public Ui_frmUdpClient {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRMUDPCLIENT_H
