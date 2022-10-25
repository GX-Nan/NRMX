/********************************************************************************
** Form generated from reading UI file 'frmudpclient.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
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
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *labServerIP;
    QLineEdit *txtServerIP;
    QLabel *labServerPort;
    QLineEdit *txtServerPort;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_2;
    QCheckBox *ckAutoSend;
    QComboBox *cboxInterval;
    QWidget *widget;
    QPushButton *btnSend;
    QComboBox *cboxData;

    void setupUi(QWidget *frmUdpClient)
    {
        if (frmUdpClient->objectName().isEmpty())
            frmUdpClient->setObjectName(QString::fromUtf8("frmUdpClient"));
        frmUdpClient->resize(433, 612);
        txtMain = new QTextEdit(frmUdpClient);
        txtMain->setObjectName(QString::fromUtf8("txtMain"));
        txtMain->setGeometry(QRect(9, 9, 211, 509));
        txtMain->setReadOnly(true);
        frame = new QFrame(frmUdpClient);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(240, 10, 181, 591));
        frame->setMinimumSize(QSize(170, 0));
        frame->setMaximumSize(QSize(200, 16777215));
        frame->setFrameShape(QFrame::Box);
        frame->setFrameShadow(QFrame::Sunken);
        ckHexReceive = new QCheckBox(frame);
        ckHexReceive->setObjectName(QString::fromUtf8("ckHexReceive"));
        ckHexReceive->setGeometry(QRect(11, 11, 171, 27));
        ckHexSend = new QCheckBox(frame);
        ckHexSend->setObjectName(QString::fromUtf8("ckHexSend"));
        ckHexSend->setGeometry(QRect(11, 44, 171, 27));
        ckAscii = new QCheckBox(frame);
        ckAscii->setObjectName(QString::fromUtf8("ckAscii"));
        ckAscii->setGeometry(QRect(11, 77, 129, 27));
        ckShow = new QCheckBox(frame);
        ckShow->setObjectName(QString::fromUtf8("ckShow"));
        ckShow->setGeometry(QRect(11, 110, 95, 27));
        ckDebug = new QCheckBox(frame);
        ckDebug->setObjectName(QString::fromUtf8("ckDebug"));
        ckDebug->setGeometry(QRect(11, 143, 95, 27));
        btnSave = new QPushButton(frame);
        btnSave->setObjectName(QString::fromUtf8("btnSave"));
        btnSave->setGeometry(QRect(11, 474, 85, 30));
        btnClear = new QPushButton(frame);
        btnClear->setObjectName(QString::fromUtf8("btnClear"));
        btnClear->setGeometry(QRect(11, 510, 85, 30));
        layoutWidget = new QWidget(frame);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 310, 146, 128));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        labServerIP = new QLabel(layoutWidget);
        labServerIP->setObjectName(QString::fromUtf8("labServerIP"));

        verticalLayout->addWidget(labServerIP);

        txtServerIP = new QLineEdit(layoutWidget);
        txtServerIP->setObjectName(QString::fromUtf8("txtServerIP"));

        verticalLayout->addWidget(txtServerIP);

        labServerPort = new QLabel(layoutWidget);
        labServerPort->setObjectName(QString::fromUtf8("labServerPort"));

        verticalLayout->addWidget(labServerPort);

        txtServerPort = new QLineEdit(layoutWidget);
        txtServerPort->setObjectName(QString::fromUtf8("txtServerPort"));

        verticalLayout->addWidget(txtServerPort);

        layoutWidget1 = new QWidget(frame);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 190, 97, 67));
        verticalLayout_2 = new QVBoxLayout(layoutWidget1);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        ckAutoSend = new QCheckBox(layoutWidget1);
        ckAutoSend->setObjectName(QString::fromUtf8("ckAutoSend"));

        verticalLayout_2->addWidget(ckAutoSend);

        cboxInterval = new QComboBox(layoutWidget1);
        cboxInterval->setObjectName(QString::fromUtf8("cboxInterval"));

        verticalLayout_2->addWidget(cboxInterval);

        widget = new QWidget(frmUdpClient);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(10, 530, 211, 32));
        btnSend = new QPushButton(frmUdpClient);
        btnSend->setObjectName(QString::fromUtf8("btnSend"));
        btnSend->setGeometry(QRect(140, 570, 80, 30));
        btnSend->setMinimumSize(QSize(80, 0));
        btnSend->setMaximumSize(QSize(80, 16777215));
        cboxData = new QComboBox(frmUdpClient);
        cboxData->setObjectName(QString::fromUtf8("cboxData"));
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
        frmUdpClient->setWindowTitle(QCoreApplication::translate("frmUdpClient", "Form", nullptr));
        ckHexReceive->setText(QCoreApplication::translate("frmUdpClient", "Encrypted reception", nullptr));
        ckHexSend->setText(QCoreApplication::translate("frmUdpClient", "Encrypted send", nullptr));
        ckAscii->setText(QCoreApplication::translate("frmUdpClient", "Ascii\346\216\247\345\210\266\345\255\227\347\254\246", nullptr));
        ckShow->setText(QCoreApplication::translate("frmUdpClient", "\346\232\202\345\201\234\346\230\276\347\244\272", nullptr));
        ckDebug->setText(QCoreApplication::translate("frmUdpClient", "\346\250\241\346\213\237\350\256\276\345\244\207", nullptr));
        btnSave->setText(QCoreApplication::translate("frmUdpClient", "\344\277\235\345\255\230", nullptr));
        btnClear->setText(QCoreApplication::translate("frmUdpClient", "\346\270\205\347\251\272", nullptr));
        labServerIP->setText(QCoreApplication::translate("frmUdpClient", "\350\277\234\347\250\213\345\234\260\345\235\200", nullptr));
        labServerPort->setText(QCoreApplication::translate("frmUdpClient", "\350\277\234\347\250\213\347\253\257\345\217\243", nullptr));
        ckAutoSend->setText(QCoreApplication::translate("frmUdpClient", "\345\256\232\346\227\266\345\217\221\351\200\201", nullptr));
        btnSend->setText(QCoreApplication::translate("frmUdpClient", "\345\217\221\351\200\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class frmUdpClient: public Ui_frmUdpClient {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRMUDPCLIENT_H
