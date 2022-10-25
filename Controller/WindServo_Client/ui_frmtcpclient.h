/********************************************************************************
** Form generated from reading UI file 'frmtcpclient.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
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
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QCheckBox *ckHexReceive;
    QCheckBox *ckHexSend;
    QCheckBox *ckAscii;
    QCheckBox *ckShow;
    QCheckBox *ckDebug;
    QCheckBox *ckAutoSend;
    QWidget *layoutWidget1;
    QGridLayout *gridLayout;
    QLabel *labServerIP;
    QLineEdit *txtServerIP;
    QLabel *labServerPort;
    QLineEdit *txtServerPort;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout_2;
    QPushButton *btnConnect;
    QPushButton *btnSave;
    QPushButton *btnClear;
    QWidget *widget;
    QHBoxLayout *layTcpClient;
    QPushButton *btnSend;
    QComboBox *cboxData;
    QWidget *layoutWidget3;
    QVBoxLayout *verticalLayout_3;
    QLineEdit *WindPower;
    QLabel *labServerIP_3;
    QPushButton *pushButton_2;
    QLineEdit *ServoAngle;
    QLabel *labServerIP_2;
    QPushButton *pushButton;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QLineEdit *Pin1;
    QLineEdit *Pin2;
    QLabel *labServerIP_4;
    QLabel *labServerIP_5;
    QLabel *labServerIP_6;
    QLineEdit *GroupAngle;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QLineEdit *GroupAngle_2;
    QLabel *labServerIP_7;

    void setupUi(QWidget *frmTcpClient)
    {
        if (frmTcpClient->objectName().isEmpty())
            frmTcpClient->setObjectName(QStringLiteral("frmTcpClient"));
        frmTcpClient->resize(1187, 612);
        txtMain = new QTextEdit(frmTcpClient);
        txtMain->setObjectName(QStringLiteral("txtMain"));
        txtMain->setGeometry(QRect(10, 10, 211, 511));
        txtMain->setReadOnly(true);
        frame = new QFrame(frmTcpClient);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(230, 10, 200, 591));
        frame->setMinimumSize(QSize(170, 400));
        frame->setMaximumSize(QSize(200, 16777215));
        frame->setFrameShape(QFrame::Box);
        frame->setFrameShadow(QFrame::Sunken);
        cboxInterval = new QComboBox(frame);
        cboxInterval->setObjectName(QStringLiteral("cboxInterval"));
        cboxInterval->setGeometry(QRect(10, 240, 111, 32));
        layoutWidget = new QWidget(frame);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(11, 11, 174, 221));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        ckHexReceive = new QCheckBox(layoutWidget);
        ckHexReceive->setObjectName(QStringLiteral("ckHexReceive"));

        verticalLayout->addWidget(ckHexReceive);

        ckHexSend = new QCheckBox(layoutWidget);
        ckHexSend->setObjectName(QStringLiteral("ckHexSend"));

        verticalLayout->addWidget(ckHexSend);

        ckAscii = new QCheckBox(layoutWidget);
        ckAscii->setObjectName(QStringLiteral("ckAscii"));

        verticalLayout->addWidget(ckAscii);

        ckShow = new QCheckBox(layoutWidget);
        ckShow->setObjectName(QStringLiteral("ckShow"));

        verticalLayout->addWidget(ckShow);

        ckDebug = new QCheckBox(layoutWidget);
        ckDebug->setObjectName(QStringLiteral("ckDebug"));

        verticalLayout->addWidget(ckDebug);

        ckAutoSend = new QCheckBox(layoutWidget);
        ckAutoSend->setObjectName(QStringLiteral("ckAutoSend"));

        verticalLayout->addWidget(ckAutoSend);

        layoutWidget1 = new QWidget(frame);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(12, 284, 171, 161));
        gridLayout = new QGridLayout(layoutWidget1);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        labServerIP = new QLabel(layoutWidget1);
        labServerIP->setObjectName(QStringLiteral("labServerIP"));

        gridLayout->addWidget(labServerIP, 0, 0, 1, 1);

        txtServerIP = new QLineEdit(layoutWidget1);
        txtServerIP->setObjectName(QStringLiteral("txtServerIP"));

        gridLayout->addWidget(txtServerIP, 1, 0, 1, 1);

        labServerPort = new QLabel(layoutWidget1);
        labServerPort->setObjectName(QStringLiteral("labServerPort"));

        gridLayout->addWidget(labServerPort, 2, 0, 1, 1);

        txtServerPort = new QLineEdit(layoutWidget1);
        txtServerPort->setObjectName(QStringLiteral("txtServerPort"));

        gridLayout->addWidget(txtServerPort, 3, 0, 1, 1);

        layoutWidget2 = new QWidget(frame);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(10, 460, 171, 121));
        verticalLayout_2 = new QVBoxLayout(layoutWidget2);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        btnConnect = new QPushButton(layoutWidget2);
        btnConnect->setObjectName(QStringLiteral("btnConnect"));

        verticalLayout_2->addWidget(btnConnect);

        btnSave = new QPushButton(layoutWidget2);
        btnSave->setObjectName(QStringLiteral("btnSave"));

        verticalLayout_2->addWidget(btnSave);

        btnClear = new QPushButton(layoutWidget2);
        btnClear->setObjectName(QStringLiteral("btnClear"));

        verticalLayout_2->addWidget(btnClear);

        widget = new QWidget(frmTcpClient);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(10, 530, 211, 32));
        layTcpClient = new QHBoxLayout(widget);
        layTcpClient->setObjectName(QStringLiteral("layTcpClient"));
        layTcpClient->setContentsMargins(0, 0, 0, 0);
        btnSend = new QPushButton(frmTcpClient);
        btnSend->setObjectName(QStringLiteral("btnSend"));
        btnSend->setGeometry(QRect(140, 570, 80, 30));
        btnSend->setMinimumSize(QSize(80, 0));
        btnSend->setMaximumSize(QSize(80, 16777215));
        cboxData = new QComboBox(frmTcpClient);
        cboxData->setObjectName(QStringLiteral("cboxData"));
        cboxData->setGeometry(QRect(10, 530, 211, 32));
        QSizePolicy sizePolicy(QSizePolicy::Ignored, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(cboxData->sizePolicy().hasHeightForWidth());
        cboxData->setSizePolicy(sizePolicy);
        cboxData->setEditable(true);
        layoutWidget3 = new QWidget(frmTcpClient);
        layoutWidget3->setObjectName(QStringLiteral("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(480, 10, 110, 148));
        verticalLayout_3 = new QVBoxLayout(layoutWidget3);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        WindPower = new QLineEdit(layoutWidget3);
        WindPower->setObjectName(QStringLiteral("WindPower"));

        verticalLayout_3->addWidget(WindPower);

        labServerIP_3 = new QLabel(layoutWidget3);
        labServerIP_3->setObjectName(QStringLiteral("labServerIP_3"));
        labServerIP_3->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(labServerIP_3);

        pushButton_2 = new QPushButton(layoutWidget3);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        verticalLayout_3->addWidget(pushButton_2);

        ServoAngle = new QLineEdit(layoutWidget3);
        ServoAngle->setObjectName(QStringLiteral("ServoAngle"));

        verticalLayout_3->addWidget(ServoAngle);

        labServerIP_2 = new QLabel(layoutWidget3);
        labServerIP_2->setObjectName(QStringLiteral("labServerIP_2"));
        labServerIP_2->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(labServerIP_2);

        pushButton = new QPushButton(layoutWidget3);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout_3->addWidget(pushButton);

        pushButton_3 = new QPushButton(frmTcpClient);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(640, 10, 80, 22));
        pushButton_4 = new QPushButton(frmTcpClient);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(640, 50, 80, 22));
        pushButton_5 = new QPushButton(frmTcpClient);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(830, 290, 80, 22));
        Pin1 = new QLineEdit(frmTcpClient);
        Pin1->setObjectName(QStringLiteral("Pin1"));
        Pin1->setGeometry(QRect(570, 190, 108, 22));
        Pin2 = new QLineEdit(frmTcpClient);
        Pin2->setObjectName(QStringLiteral("Pin2"));
        Pin2->setGeometry(QRect(570, 240, 108, 22));
        labServerIP_4 = new QLabel(frmTcpClient);
        labServerIP_4->setObjectName(QStringLiteral("labServerIP_4"));
        labServerIP_4->setGeometry(QRect(570, 220, 108, 21));
        labServerIP_4->setAlignment(Qt::AlignCenter);
        labServerIP_5 = new QLabel(frmTcpClient);
        labServerIP_5->setObjectName(QStringLiteral("labServerIP_5"));
        labServerIP_5->setGeometry(QRect(570, 270, 108, 21));
        labServerIP_5->setAlignment(Qt::AlignCenter);
        labServerIP_6 = new QLabel(frmTcpClient);
        labServerIP_6->setObjectName(QStringLiteral("labServerIP_6"));
        labServerIP_6->setGeometry(QRect(570, 320, 108, 21));
        labServerIP_6->setAlignment(Qt::AlignCenter);
        GroupAngle = new QLineEdit(frmTcpClient);
        GroupAngle->setObjectName(QStringLiteral("GroupAngle"));
        GroupAngle->setGeometry(QRect(570, 290, 108, 22));
        pushButton_6 = new QPushButton(frmTcpClient);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(580, 380, 80, 22));
        pushButton_7 = new QPushButton(frmTcpClient);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setGeometry(QRect(580, 420, 80, 22));
        GroupAngle_2 = new QLineEdit(frmTcpClient);
        GroupAngle_2->setObjectName(QStringLiteral("GroupAngle_2"));
        GroupAngle_2->setGeometry(QRect(700, 290, 108, 22));
        labServerIP_7 = new QLabel(frmTcpClient);
        labServerIP_7->setObjectName(QStringLiteral("labServerIP_7"));
        labServerIP_7->setGeometry(QRect(700, 320, 108, 21));
        labServerIP_7->setAlignment(Qt::AlignCenter);

        retranslateUi(frmTcpClient);

        QMetaObject::connectSlotsByName(frmTcpClient);
    } // setupUi

    void retranslateUi(QWidget *frmTcpClient)
    {
        frmTcpClient->setWindowTitle(QApplication::translate("frmTcpClient", "Form", nullptr));
        ckHexReceive->setText(QApplication::translate("frmTcpClient", "Encrypted reception", nullptr));
        ckHexSend->setText(QApplication::translate("frmTcpClient", "Encrypted send", nullptr));
        ckAscii->setText(QApplication::translate("frmTcpClient", "Ascii\346\216\247\345\210\266\345\255\227\347\254\246", nullptr));
        ckShow->setText(QApplication::translate("frmTcpClient", "\346\232\202\345\201\234\346\230\276\347\244\272", nullptr));
        ckDebug->setText(QApplication::translate("frmTcpClient", "\346\250\241\346\213\237\350\256\276\345\244\207", nullptr));
        ckAutoSend->setText(QApplication::translate("frmTcpClient", "\345\256\232\346\227\266\345\217\221\351\200\201", nullptr));
        labServerIP->setText(QApplication::translate("frmTcpClient", "\346\234\215\345\212\241\345\231\250\345\234\260\345\235\200", nullptr));
        labServerPort->setText(QApplication::translate("frmTcpClient", "\346\234\215\345\212\241\345\231\250\347\253\257\345\217\243", nullptr));
        btnConnect->setText(QApplication::translate("frmTcpClient", "\350\277\236\346\216\245", nullptr));
        btnSave->setText(QApplication::translate("frmTcpClient", "\344\277\235\345\255\230", nullptr));
        btnClear->setText(QApplication::translate("frmTcpClient", "\346\270\205\347\251\272", nullptr));
        btnSend->setText(QApplication::translate("frmTcpClient", "\345\217\221\351\200\201", nullptr));
        labServerIP_3->setText(QApplication::translate("frmTcpClient", "\351\243\216\351\200\237", nullptr));
        pushButton_2->setText(QApplication::translate("frmTcpClient", "Wind", nullptr));
        labServerIP_2->setText(QApplication::translate("frmTcpClient", "\350\247\222\345\272\246", nullptr));
        pushButton->setText(QApplication::translate("frmTcpClient", "Turn", nullptr));
        pushButton_3->setText(QApplication::translate("frmTcpClient", "Stop Timer", nullptr));
        pushButton_4->setText(QApplication::translate("frmTcpClient", "start Timer", nullptr));
        pushButton_5->setText(QApplication::translate("frmTcpClient", "ServoTurn", nullptr));
        labServerIP_4->setText(QApplication::translate("frmTcpClient", "Pin1", nullptr));
        labServerIP_5->setText(QApplication::translate("frmTcpClient", "Pin2", nullptr));
        labServerIP_6->setText(QApplication::translate("frmTcpClient", "Angle1", nullptr));
        pushButton_6->setText(QApplication::translate("frmTcpClient", "whileTrun", nullptr));
        pushButton_7->setText(QApplication::translate("frmTcpClient", "whileTrunClose", nullptr));
        labServerIP_7->setText(QApplication::translate("frmTcpClient", "Angle2", nullptr));
    } // retranslateUi

};

namespace Ui {
    class frmTcpClient: public Ui_frmTcpClient {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRMTCPCLIENT_H
