/********************************************************************************
** Form generated from reading UI file 'frmmain.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRMMAIN_H
#define UI_FRMMAIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_frmMain
{
public:
    QGroupBox *groupBox;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QGroupBox *TempAndHumi;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QGroupBox *groupBox_3;
    QGroupBox *groupBox_4;
    QGroupBox *groupBox_5;
    QGroupBox *WeatherPage;
    QGroupBox *groupBox_16;
    QGroupBox *groupBox_17;
    QGroupBox *groupBox_20;
    QGroupBox *groupBox_21;
    QGroupBox *groupBox_22;
    QGroupBox *groupBox_23;
    QGroupBox *groupBox_18;
    QGroupBox *groupBox_19;
    QGroupBox *groupBox_24;
    QLabel *label_15;
    QLabel *label_16;
    QLabel *label_17;
    QLabel *label_18;
    QLabel *label_19;
    QLabel *label_20;
    QLabel *label_22;
    QLabel *label_21;
    QLabel *label_24;
    QLabel *label_23;
    QGroupBox *groupBox_8;
    QLabel *label_4;
    QGroupBox *groupBox_9;
    QGroupBox *groupBox_10;
    QLabel *label_5;
    QGroupBox *groupBox_11;
    QGroupBox *groupBox_12;
    QLabel *label_12;
    QGroupBox *groupBox_13;
    QGroupBox *groupBox_14;
    QLabel *label_13;
    QGroupBox *groupBox_15;
    QFrame *CurtainsPage;
    QFrame *frame;
    QPushButton *AllCurtains_Open;
    QPushButton *AllCurtains_Stop;
    QPushButton *AllCurtains_Close;
    QPushButton *WindowBox;
    QPushButton *CurtainsBox;
    QFrame *WindowPage;
    QFrame *frame_2;
    QPushButton *AllWindow_Stop_3;
    QPushButton *AllWindow_Close_3;
    QPushButton *AllWindow_Open_3;

    void setupUi(QWidget *frmMain)
    {
        if (frmMain->objectName().isEmpty())
            frmMain->setObjectName(QString::fromUtf8("frmMain"));
        frmMain->resize(1920, 1080);
        frmMain->setStyleSheet(QString::fromUtf8("background-color:white"));
        groupBox = new QGroupBox(frmMain);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(100, 70, 431, 681));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(130, 500, 181, 61));
        QFont font;
        font.setFamily(QString::fromUtf8("Adobe \351\273\221\344\275\223 Std R"));
        font.setPointSize(20);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(40, 120, 361, 321));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Adobe \351\273\221\344\275\223 Std R"));
        font1.setPointSize(250);
        label_2->setFont(font1);
        label_2->setAlignment(Qt::AlignCenter);
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(170, 580, 101, 41));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Adobe \351\273\221\344\275\223 Std R"));
        font2.setPointSize(12);
        font2.setBold(true);
        font2.setWeight(75);
        label_3->setFont(font2);
        label_3->setAlignment(Qt::AlignCenter);
        TempAndHumi = new QGroupBox(frmMain);
        TempAndHumi->setObjectName(QString::fromUtf8("TempAndHumi"));
        TempAndHumi->setGeometry(QRect(100, 840, 721, 161));
        TempAndHumi->setStyleSheet(QString::fromUtf8("QGroupBox#TempAndHumi{\n"
"border-radius:8px;\n"
"background:#FFFFFF;\n"
"}"));
        label_6 = new QLabel(TempAndHumi);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(40, 30, 101, 101));
        label_6->setAlignment(Qt::AlignCenter);
        label_7 = new QLabel(TempAndHumi);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(390, 30, 101, 101));
        label_7->setAlignment(Qt::AlignCenter);
        label_8 = new QLabel(TempAndHumi);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(160, 50, 161, 61));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Adobe \351\273\221\344\275\223 Std R"));
        font3.setPointSize(25);
        font3.setBold(true);
        font3.setWeight(75);
        label_8->setFont(font3);
        label_8->setAlignment(Qt::AlignCenter);
        label_9 = new QLabel(TempAndHumi);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(190, 100, 81, 31));
        QFont font4;
        font4.setFamily(QString::fromUtf8("Adobe \351\273\221\344\275\223 Std R"));
        font4.setPointSize(10);
        font4.setBold(true);
        font4.setWeight(75);
        label_9->setFont(font4);
        label_9->setAlignment(Qt::AlignCenter);
        label_10 = new QLabel(TempAndHumi);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(500, 50, 161, 61));
        label_10->setFont(font3);
        label_10->setAlignment(Qt::AlignCenter);
        label_11 = new QLabel(TempAndHumi);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(540, 100, 81, 31));
        label_11->setFont(font4);
        label_11->setAlignment(Qt::AlignCenter);
        groupBox_3 = new QGroupBox(frmMain);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(650, 70, 171, 171));
        groupBox_4 = new QGroupBox(frmMain);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setGeometry(QRect(650, 320, 171, 171));
        groupBox_5 = new QGroupBox(frmMain);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        groupBox_5->setGeometry(QRect(650, 580, 171, 171));
        WeatherPage = new QGroupBox(frmMain);
        WeatherPage->setObjectName(QString::fromUtf8("WeatherPage"));
        WeatherPage->setGeometry(QRect(930, 40, 901, 231));
        WeatherPage->setStyleSheet(QString::fromUtf8("QGroupBox#WeatherPage{\n"
"border-radius:8px;\n"
"}\n"
""));
        groupBox_16 = new QGroupBox(WeatherPage);
        groupBox_16->setObjectName(QString::fromUtf8("groupBox_16"));
        groupBox_16->setGeometry(QRect(180, 60, 16, 71));
        groupBox_17 = new QGroupBox(WeatherPage);
        groupBox_17->setObjectName(QString::fromUtf8("groupBox_17"));
        groupBox_17->setGeometry(QRect(370, 60, 16, 71));
        groupBox_20 = new QGroupBox(WeatherPage);
        groupBox_20->setObjectName(QString::fromUtf8("groupBox_20"));
        groupBox_20->setGeometry(QRect(30, 40, 111, 111));
        groupBox_21 = new QGroupBox(WeatherPage);
        groupBox_21->setObjectName(QString::fromUtf8("groupBox_21"));
        groupBox_21->setGeometry(QRect(230, 40, 111, 111));
        groupBox_22 = new QGroupBox(WeatherPage);
        groupBox_22->setObjectName(QString::fromUtf8("groupBox_22"));
        groupBox_22->setGeometry(QRect(410, 40, 111, 111));
        groupBox_23 = new QGroupBox(WeatherPage);
        groupBox_23->setObjectName(QString::fromUtf8("groupBox_23"));
        groupBox_23->setGeometry(QRect(590, 40, 111, 111));
        groupBox_18 = new QGroupBox(WeatherPage);
        groupBox_18->setObjectName(QString::fromUtf8("groupBox_18"));
        groupBox_18->setGeometry(QRect(550, 60, 16, 71));
        groupBox_19 = new QGroupBox(WeatherPage);
        groupBox_19->setObjectName(QString::fromUtf8("groupBox_19"));
        groupBox_19->setGeometry(QRect(720, 60, 16, 71));
        groupBox_24 = new QGroupBox(WeatherPage);
        groupBox_24->setObjectName(QString::fromUtf8("groupBox_24"));
        groupBox_24->setGeometry(QRect(760, 40, 111, 111));
        label_15 = new QLabel(WeatherPage);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(50, 160, 81, 31));
        label_15->setFont(font2);
        label_15->setAlignment(Qt::AlignCenter);
        label_16 = new QLabel(WeatherPage);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(50, 190, 81, 20));
        label_16->setAlignment(Qt::AlignCenter);
        label_17 = new QLabel(WeatherPage);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setGeometry(QRect(250, 160, 81, 31));
        label_17->setFont(font2);
        label_17->setAlignment(Qt::AlignCenter);
        label_18 = new QLabel(WeatherPage);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setGeometry(QRect(250, 190, 81, 20));
        label_18->setAlignment(Qt::AlignCenter);
        label_19 = new QLabel(WeatherPage);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setGeometry(QRect(430, 160, 81, 31));
        label_19->setFont(font2);
        label_19->setAlignment(Qt::AlignCenter);
        label_20 = new QLabel(WeatherPage);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setGeometry(QRect(430, 190, 81, 20));
        label_20->setAlignment(Qt::AlignCenter);
        label_22 = new QLabel(WeatherPage);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setGeometry(QRect(610, 190, 81, 20));
        label_22->setAlignment(Qt::AlignCenter);
        label_21 = new QLabel(WeatherPage);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setGeometry(QRect(610, 160, 81, 31));
        label_21->setFont(font2);
        label_21->setAlignment(Qt::AlignCenter);
        label_24 = new QLabel(WeatherPage);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        label_24->setGeometry(QRect(780, 190, 81, 20));
        label_24->setAlignment(Qt::AlignCenter);
        label_23 = new QLabel(WeatherPage);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setGeometry(QRect(780, 160, 81, 31));
        label_23->setFont(font2);
        label_23->setAlignment(Qt::AlignCenter);
        groupBox_8 = new QGroupBox(frmMain);
        groupBox_8->setObjectName(QString::fromUtf8("groupBox_8"));
        groupBox_8->setGeometry(QRect(940, 330, 141, 151));
        label_4 = new QLabel(groupBox_8);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(20, 20, 101, 111));
        label_4->setAlignment(Qt::AlignCenter);
        groupBox_9 = new QGroupBox(frmMain);
        groupBox_9->setObjectName(QString::fromUtf8("groupBox_9"));
        groupBox_9->setGeometry(QRect(940, 500, 141, 31));
        groupBox_10 = new QGroupBox(frmMain);
        groupBox_10->setObjectName(QString::fromUtf8("groupBox_10"));
        groupBox_10->setGeometry(QRect(1200, 330, 141, 151));
        label_5 = new QLabel(groupBox_10);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(20, 20, 101, 111));
        label_5->setAlignment(Qt::AlignCenter);
        groupBox_11 = new QGroupBox(frmMain);
        groupBox_11->setObjectName(QString::fromUtf8("groupBox_11"));
        groupBox_11->setGeometry(QRect(1200, 500, 141, 31));
        groupBox_12 = new QGroupBox(frmMain);
        groupBox_12->setObjectName(QString::fromUtf8("groupBox_12"));
        groupBox_12->setGeometry(QRect(1450, 330, 141, 151));
        label_12 = new QLabel(groupBox_12);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(20, 20, 101, 111));
        label_12->setAlignment(Qt::AlignCenter);
        groupBox_13 = new QGroupBox(frmMain);
        groupBox_13->setObjectName(QString::fromUtf8("groupBox_13"));
        groupBox_13->setGeometry(QRect(1450, 500, 141, 31));
        groupBox_14 = new QGroupBox(frmMain);
        groupBox_14->setObjectName(QString::fromUtf8("groupBox_14"));
        groupBox_14->setGeometry(QRect(1690, 330, 141, 151));
        label_13 = new QLabel(groupBox_14);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(20, 20, 101, 111));
        label_13->setAlignment(Qt::AlignCenter);
        groupBox_15 = new QGroupBox(frmMain);
        groupBox_15->setObjectName(QString::fromUtf8("groupBox_15"));
        groupBox_15->setGeometry(QRect(1690, 500, 141, 31));
        CurtainsPage = new QFrame(frmMain);
        CurtainsPage->setObjectName(QString::fromUtf8("CurtainsPage"));
        CurtainsPage->setGeometry(QRect(940, 840, 742, 181));
        CurtainsPage->setStyleSheet(QString::fromUtf8("QFrame#CurtainsPage{\n"
"border-radius:8px;\n"
"/*background-color:transparent;*/\n"
"}"));
        CurtainsPage->setFrameShape(QFrame::StyledPanel);
        CurtainsPage->setFrameShadow(QFrame::Raised);
        frame = new QFrame(CurtainsPage);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(10, 10, 721, 161));
        frame->setStyleSheet(QString::fromUtf8("background-color:transparent"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        AllCurtains_Open = new QPushButton(frame);
        AllCurtains_Open->setObjectName(QString::fromUtf8("AllCurtains_Open"));
        AllCurtains_Open->setGeometry(QRect(40, 20, 131, 121));
        AllCurtains_Open->setStyleSheet(QString::fromUtf8("\n"
"border-radius:8px;\n"
"background:#FFFFFF;\n"
"/*border:1px solid black;"));
        AllCurtains_Stop = new QPushButton(frame);
        AllCurtains_Stop->setObjectName(QString::fromUtf8("AllCurtains_Stop"));
        AllCurtains_Stop->setGeometry(QRect(300, 20, 131, 121));
        AllCurtains_Stop->setStyleSheet(QString::fromUtf8("\n"
"border-radius:8px;\n"
"background:#FFFFFF;\n"
"/*border:1px solid black;"));
        AllCurtains_Close = new QPushButton(frame);
        AllCurtains_Close->setObjectName(QString::fromUtf8("AllCurtains_Close"));
        AllCurtains_Close->setGeometry(QRect(550, 20, 131, 121));
        AllCurtains_Close->setStyleSheet(QString::fromUtf8("\n"
"border-radius:8px;\n"
"background:#FFFFFF;\n"
"/*border:1px solid black;"));
        WindowBox = new QPushButton(frmMain);
        WindowBox->setObjectName(QString::fromUtf8("WindowBox"));
        WindowBox->setGeometry(QRect(950, 600, 61, 181));
        WindowBox->setStyleSheet(QString::fromUtf8("\n"
"border-radius:8px;\n"
"background:#FFFFFF;"));
        CurtainsBox = new QPushButton(frmMain);
        CurtainsBox->setObjectName(QString::fromUtf8("CurtainsBox"));
        CurtainsBox->setGeometry(QRect(1760, 840, 61, 181));
        CurtainsBox->setStyleSheet(QString::fromUtf8("\n"
"border-radius:8px;\n"
"background:#FFFFFF;"));
        WindowPage = new QFrame(frmMain);
        WindowPage->setObjectName(QString::fromUtf8("WindowPage"));
        WindowPage->setGeometry(QRect(1090, 600, 741, 181));
        WindowPage->setStyleSheet(QString::fromUtf8("border-radius:8px;"));
        WindowPage->setFrameShape(QFrame::StyledPanel);
        WindowPage->setFrameShadow(QFrame::Raised);
        frame_2 = new QFrame(WindowPage);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setGeometry(QRect(10, 10, 721, 161));
        frame_2->setStyleSheet(QString::fromUtf8("background-color:transparent"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        AllWindow_Stop_3 = new QPushButton(frame_2);
        AllWindow_Stop_3->setObjectName(QString::fromUtf8("AllWindow_Stop_3"));
        AllWindow_Stop_3->setGeometry(QRect(300, 20, 131, 121));
        AllWindow_Stop_3->setStyleSheet(QString::fromUtf8("\n"
"border-radius:8px;\n"
"background:#FFFFFF;\n"
"/*border:1px solid black;"));
        AllWindow_Close_3 = new QPushButton(frame_2);
        AllWindow_Close_3->setObjectName(QString::fromUtf8("AllWindow_Close_3"));
        AllWindow_Close_3->setGeometry(QRect(540, 20, 131, 121));
        AllWindow_Close_3->setStyleSheet(QString::fromUtf8("\n"
"border-radius:8px;\n"
"background:#FFFFFF;\n"
"/*border:1px solid black;"));
        AllWindow_Open_3 = new QPushButton(frame_2);
        AllWindow_Open_3->setObjectName(QString::fromUtf8("AllWindow_Open_3"));
        AllWindow_Open_3->setGeometry(QRect(60, 20, 131, 121));
        AllWindow_Open_3->setStyleSheet(QString::fromUtf8("\n"
"border-radius:8px;\n"
"background:#FFFFFF;\n"
"/*border:1px solid black;"));

        retranslateUi(frmMain);

        QMetaObject::connectSlotsByName(frmMain);
    } // setupUi

    void retranslateUi(QWidget *frmMain)
    {
        frmMain->setWindowTitle(QCoreApplication::translate("frmMain", "Form", nullptr));
        groupBox->setTitle(QString());
        label->setText(QCoreApplication::translate("frmMain", "\346\210\267\345\244\226\347\251\272\346\260\224\350\264\250\351\207\217", nullptr));
        label_2->setText(QCoreApplication::translate("frmMain", "25", nullptr));
        label_3->setText(QCoreApplication::translate("frmMain", "AirQuality", nullptr));
        TempAndHumi->setTitle(QString());
        label_6->setText(QCoreApplication::translate("frmMain", "TempP", nullptr));
        label_7->setText(QCoreApplication::translate("frmMain", "HumiP", nullptr));
        label_8->setText(QCoreApplication::translate("frmMain", "25/26\302\260C", nullptr));
        label_9->setText(QCoreApplication::translate("frmMain", "\345\256\244\345\206\205/\345\244\226", nullptr));
        label_10->setText(QCoreApplication::translate("frmMain", "25/26%", nullptr));
        label_11->setText(QCoreApplication::translate("frmMain", "\345\256\244\345\206\205/\345\244\226", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("frmMain", "\351\200\202\345\256\234\346\264\273\345\212\250", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("frmMain", "\351\200\202\345\256\234\346\264\273\345\212\250", nullptr));
        groupBox_5->setTitle(QCoreApplication::translate("frmMain", "\351\200\202\345\256\234\346\264\273\345\212\250", nullptr));
        WeatherPage->setTitle(QString());
        groupBox_16->setTitle(QString());
        groupBox_17->setTitle(QString());
        groupBox_20->setTitle(QString());
        groupBox_21->setTitle(QString());
        groupBox_22->setTitle(QString());
        groupBox_23->setTitle(QString());
        groupBox_18->setTitle(QString());
        groupBox_19->setTitle(QString());
        groupBox_24->setTitle(QString());
        label_15->setText(QCoreApplication::translate("frmMain", "\351\233\250\345\244\251", nullptr));
        label_16->setText(QCoreApplication::translate("frmMain", "14\357\274\23200", nullptr));
        label_17->setText(QCoreApplication::translate("frmMain", "\351\233\250\345\244\251", nullptr));
        label_18->setText(QCoreApplication::translate("frmMain", "14\357\274\23200", nullptr));
        label_19->setText(QCoreApplication::translate("frmMain", "\351\233\250\345\244\251", nullptr));
        label_20->setText(QCoreApplication::translate("frmMain", "14\357\274\23200", nullptr));
        label_22->setText(QCoreApplication::translate("frmMain", "14\357\274\23200", nullptr));
        label_21->setText(QCoreApplication::translate("frmMain", "\351\233\250\345\244\251", nullptr));
        label_24->setText(QCoreApplication::translate("frmMain", "14\357\274\23200", nullptr));
        label_23->setText(QCoreApplication::translate("frmMain", "\351\233\250\345\244\251", nullptr));
        groupBox_8->setTitle(QString());
        label_4->setText(QCoreApplication::translate("frmMain", "No2", nullptr));
        groupBox_9->setTitle(QString());
        groupBox_10->setTitle(QString());
        label_5->setText(QCoreApplication::translate("frmMain", "CO2", nullptr));
        groupBox_11->setTitle(QString());
        groupBox_12->setTitle(QString());
        label_12->setText(QCoreApplication::translate("frmMain", "Pm2.5", nullptr));
        groupBox_13->setTitle(QString());
        groupBox_14->setTitle(QString());
        label_13->setText(QCoreApplication::translate("frmMain", "lux", nullptr));
        groupBox_15->setTitle(QString());
        AllCurtains_Open->setText(QCoreApplication::translate("frmMain", "\345\274\200", nullptr));
        AllCurtains_Stop->setText(QCoreApplication::translate("frmMain", "\345\201\234", nullptr));
        AllCurtains_Close->setText(QCoreApplication::translate("frmMain", "\345\205\263", nullptr));
        WindowBox->setText(QCoreApplication::translate("frmMain", "x", nullptr));
        CurtainsBox->setText(QCoreApplication::translate("frmMain", "x", nullptr));
        AllWindow_Stop_3->setText(QCoreApplication::translate("frmMain", "\345\201\234", nullptr));
        AllWindow_Close_3->setText(QCoreApplication::translate("frmMain", "\345\205\263", nullptr));
        AllWindow_Open_3->setText(QCoreApplication::translate("frmMain", "\345\274\200", nullptr));
    } // retranslateUi

};

namespace Ui {
    class frmMain: public Ui_frmMain {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRMMAIN_H
