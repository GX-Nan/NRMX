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
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>
#include "switchbutton.h"

QT_BEGIN_NAMESPACE

class Ui_frmMain
{
public:
    QFrame *Bottom;
    QGroupBox *AirPage;
    SwitchButton *AirSwitch;
    QPushButton *AirSubUi;
    QSlider *AirSlider;
    QLabel *label_12;
    QLabel *AirTemp;
    QGroupBox *MainPage;
    QLabel *AirQuality;
    QLabel *label_17;
    QLabel *label_18;
    QLabel *AirQualityP;
    QGroupBox *LightPage;
    SwitchButton *AllLightSwitch;
    QPushButton *LightSubUi;
    QSlider *AuxiliarySlider;
    QLabel *label_10;
    QLabel *AllAuxiliaryValue;
    QFrame *AirQualityPage;
    QGroupBox *groupBox_7;
    QLabel *TvcoP;
    QLabel *label_23;
    QLabel *label_24;
    QLabel *label_30;
    QGroupBox *groupBox_4;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_27;
    QLabel *HumP;
    QGroupBox *groupBox_2;
    QLabel *PM25P;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_26;
    QGroupBox *groupBox;
    QLabel *TempP;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_25;
    QGroupBox *groupBox_5;
    QLabel *HchoP;
    QLabel *label_14;
    QLabel *label_15;
    QLabel *label_28;
    QGroupBox *groupBox_6;
    QLabel *Co2P;
    QLabel *label_20;
    QLabel *label_21;
    QLabel *label_29;
    QGroupBox *OutSideTemp;
    QLabel *TempP2;
    QLabel *label_19;
    QLabel *OutSideTempLabel;
    QGroupBox *OutSideHum;
    QLabel *HumP2;
    QLabel *OutSideHumLabel;
    QLabel *label_32;

    void setupUi(QWidget *frmMain)
    {
        if (frmMain->objectName().isEmpty())
            frmMain->setObjectName(QStringLiteral("frmMain"));
        frmMain->resize(1920, 1080);
        Bottom = new QFrame(frmMain);
        Bottom->setObjectName(QStringLiteral("Bottom"));
        Bottom->setGeometry(QRect(0, 0, 1921, 1081));
        Bottom->setFrameShape(QFrame::StyledPanel);
        Bottom->setFrameShadow(QFrame::Raised);
        AirPage = new QGroupBox(Bottom);
        AirPage->setObjectName(QStringLiteral("AirPage"));
        AirPage->setGeometry(QRect(1010, 930, 831, 151));
        AirPage->setStyleSheet(QLatin1String("QGroupBox#AirPage{\n"
"	border-top-left-radius:10px;\n"
"	border-top-right-radius:10px;\n"
"	background-color:white;\n"
"}"));
        AirSwitch = new SwitchButton(AirPage);
        AirSwitch->setObjectName(QStringLiteral("AirSwitch"));
        AirSwitch->setGeometry(QRect(240, 55, 121, 31));
        AirSubUi = new QPushButton(AirPage);
        AirSubUi->setObjectName(QStringLiteral("AirSubUi"));
        AirSubUi->setGeometry(QRect(50, 20, 121, 111));
        AirSubUi->setStyleSheet(QLatin1String("border-radius:8px;\n"
"background:#FFFFFF;"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/new/Air/Air/AirP.png"), QSize(), QIcon::Normal, QIcon::Off);
        AirSubUi->setIcon(icon);
        AirSubUi->setIconSize(QSize(70, 70));
        AirSlider = new QSlider(AirPage);
        AirSlider->setObjectName(QStringLiteral("AirSlider"));
        AirSlider->setGeometry(QRect(400, 60, 411, 22));
        AirSlider->setMinimum(16);
        AirSlider->setMaximum(31);
        AirSlider->setOrientation(Qt::Horizontal);
        label_12 = new QLabel(AirPage);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(530, 100, 131, 20));
        QFont font;
        font.setFamily(QString::fromUtf8("Adobe \351\273\221\344\275\223 Std R"));
        font.setPointSize(13);
        label_12->setFont(font);
        label_12->setAlignment(Qt::AlignCenter);
        AirTemp = new QLabel(AirPage);
        AirTemp->setObjectName(QStringLiteral("AirTemp"));
        AirTemp->setGeometry(QRect(660, 100, 41, 20));
        AirTemp->setFont(font);
        AirTemp->setAlignment(Qt::AlignCenter);
        MainPage = new QGroupBox(Bottom);
        MainPage->setObjectName(QStringLiteral("MainPage"));
        MainPage->setGeometry(QRect(120, 60, 741, 651));
        MainPage->setStyleSheet(QLatin1String("QGroupBox#MainPage{\n"
"	background-color:white;\n"
"	border-radius:15px;\n"
"}"));
        AirQuality = new QLabel(MainPage);
        AirQuality->setObjectName(QStringLiteral("AirQuality"));
        AirQuality->setGeometry(QRect(90, 60, 551, 391));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Adobe \351\273\221\344\275\223 Std R"));
        font1.setPointSize(220);
        font1.setBold(false);
        font1.setWeight(50);
        AirQuality->setFont(font1);
        AirQuality->setAlignment(Qt::AlignCenter);
        label_17 = new QLabel(MainPage);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(345, 500, 241, 41));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Adobe \351\273\221\344\275\223 Std R"));
        font2.setPointSize(25);
        font2.setBold(true);
        font2.setWeight(75);
        label_17->setFont(font2);
        label_17->setAlignment(Qt::AlignCenter);
        label_18 = new QLabel(MainPage);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setGeometry(QRect(350, 560, 231, 51));
        QFont font3;
        font3.setPointSize(15);
        font3.setBold(true);
        font3.setWeight(75);
        label_18->setFont(font3);
        label_18->setAlignment(Qt::AlignCenter);
        AirQualityP = new QLabel(MainPage);
        AirQualityP->setObjectName(QStringLiteral("AirQualityP"));
        AirQualityP->setGeometry(QRect(180, 510, 100, 100));
        LightPage = new QGroupBox(Bottom);
        LightPage->setObjectName(QStringLiteral("LightPage"));
        LightPage->setGeometry(QRect(80, 930, 831, 151));
        LightPage->setLayoutDirection(Qt::LeftToRight);
        LightPage->setStyleSheet(QLatin1String("QGroupBox#LightPage{\n"
"	border-top-left-radius:10px;\n"
"	border-top-right-radius:10px;\n"
"	background-color:white;\n"
"}"));
        AllLightSwitch = new SwitchButton(LightPage);
        AllLightSwitch->setObjectName(QStringLiteral("AllLightSwitch"));
        AllLightSwitch->setGeometry(QRect(220, 60, 121, 31));
        LightSubUi = new QPushButton(LightPage);
        LightSubUi->setObjectName(QStringLiteral("LightSubUi"));
        LightSubUi->setGeometry(QRect(50, 20, 121, 111));
        LightSubUi->setStyleSheet(QLatin1String("border-radius:8px;\n"
"background:#FFFFFF;"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/new/Led/Led/Brightness.png"), QSize(), QIcon::Normal, QIcon::Off);
        LightSubUi->setIcon(icon1);
        LightSubUi->setIconSize(QSize(90, 90));
        AuxiliarySlider = new QSlider(LightPage);
        AuxiliarySlider->setObjectName(QStringLiteral("AuxiliarySlider"));
        AuxiliarySlider->setGeometry(QRect(390, 65, 411, 22));
        AuxiliarySlider->setMaximum(100);
        AuxiliarySlider->setOrientation(Qt::Horizontal);
        label_10 = new QLabel(LightPage);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(520, 100, 131, 20));
        label_10->setFont(font);
        label_10->setAlignment(Qt::AlignCenter);
        AllAuxiliaryValue = new QLabel(LightPage);
        AllAuxiliaryValue->setObjectName(QStringLiteral("AllAuxiliaryValue"));
        AllAuxiliaryValue->setGeometry(QRect(650, 100, 41, 20));
        AllAuxiliaryValue->setFont(font);
        AllAuxiliaryValue->setAlignment(Qt::AlignCenter);
        AirQualityPage = new QFrame(Bottom);
        AirQualityPage->setObjectName(QStringLiteral("AirQualityPage"));
        AirQualityPage->setGeometry(QRect(970, 20, 891, 861));
        AirQualityPage->setStyleSheet(QStringLiteral("border:none"));
        AirQualityPage->setFrameShape(QFrame::StyledPanel);
        AirQualityPage->setFrameShadow(QFrame::Raised);
        groupBox_7 = new QGroupBox(AirQualityPage);
        groupBox_7->setObjectName(QStringLiteral("groupBox_7"));
        groupBox_7->setGeometry(QRect(520, 660, 341, 171));
        groupBox_7->setStyleSheet(QLatin1String("border-radius:13px;\n"
"background-color:white\n"
""));
        TvcoP = new QLabel(groupBox_7);
        TvcoP->setObjectName(QStringLiteral("TvcoP"));
        TvcoP->setGeometry(QRect(40, 20, 91, 91));
        TvcoP->setAlignment(Qt::AlignCenter);
        label_23 = new QLabel(groupBox_7);
        label_23->setObjectName(QStringLiteral("label_23"));
        label_23->setGeometry(QRect(0, 120, 191, 16));
        QFont font4;
        font4.setFamily(QString::fromUtf8("Adobe \351\273\221\344\275\223 Std R"));
        font4.setPointSize(11);
        font4.setBold(true);
        font4.setWeight(75);
        label_23->setFont(font4);
        label_23->setAlignment(Qt::AlignCenter);
        label_24 = new QLabel(groupBox_7);
        label_24->setObjectName(QStringLiteral("label_24"));
        label_24->setGeometry(QRect(25, 140, 131, 16));
        label_24->setAlignment(Qt::AlignCenter);
        label_30 = new QLabel(groupBox_7);
        label_30->setObjectName(QStringLiteral("label_30"));
        label_30->setGeometry(QRect(180, 40, 141, 81));
        QFont font5;
        font5.setFamily(QString::fromUtf8("Adobe \351\273\221\344\275\223 Std R"));
        font5.setPointSize(50);
        label_30->setFont(font5);
        label_30->setAlignment(Qt::AlignCenter);
        groupBox_4 = new QGroupBox(AirQualityPage);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setGeometry(QRect(40, 340, 341, 171));
        groupBox_4->setStyleSheet(QLatin1String("border-radius:13px;\n"
"background-color:white\n"
""));
        label_8 = new QLabel(groupBox_4);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(40, 120, 91, 16));
        label_8->setFont(font4);
        label_8->setAlignment(Qt::AlignCenter);
        label_9 = new QLabel(groupBox_4);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(30, 140, 111, 21));
        label_9->setAlignment(Qt::AlignCenter);
        label_27 = new QLabel(groupBox_4);
        label_27->setObjectName(QStringLiteral("label_27"));
        label_27->setGeometry(QRect(160, 40, 151, 91));
        label_27->setFont(font5);
        label_27->setAlignment(Qt::AlignCenter);
        HumP = new QLabel(groupBox_4);
        HumP->setObjectName(QStringLiteral("HumP"));
        HumP->setGeometry(QRect(40, 20, 91, 91));
        HumP->setAlignment(Qt::AlignCenter);
        groupBox_2 = new QGroupBox(AirQualityPage);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(520, 40, 341, 171));
        groupBox_2->setStyleSheet(QLatin1String("border-radius:13px;\n"
"background-color:white\n"
""));
        PM25P = new QLabel(groupBox_2);
        PM25P->setObjectName(QStringLiteral("PM25P"));
        PM25P->setGeometry(QRect(40, 20, 91, 91));
        PM25P->setAlignment(Qt::AlignCenter);
        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(-5, 140, 201, 16));
        label_5->setAlignment(Qt::AlignCenter);
        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(10, 120, 151, 16));
        label_6->setFont(font4);
        label_6->setAlignment(Qt::AlignCenter);
        label_26 = new QLabel(groupBox_2);
        label_26->setObjectName(QStringLiteral("label_26"));
        label_26->setGeometry(QRect(170, 40, 151, 91));
        label_26->setFont(font5);
        label_26->setAlignment(Qt::AlignCenter);
        groupBox = new QGroupBox(AirQualityPage);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(40, 40, 341, 171));
        groupBox->setStyleSheet(QLatin1String("border-radius:13px;\n"
"background-color:white\n"
""));
        TempP = new QLabel(groupBox);
        TempP->setObjectName(QStringLiteral("TempP"));
        TempP->setGeometry(QRect(40, 20, 91, 91));
        TempP->setAlignment(Qt::AlignCenter);
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(40, 120, 91, 16));
        label_3->setFont(font4);
        label_3->setAlignment(Qt::AlignCenter);
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(40, 140, 91, 16));
        label_4->setAlignment(Qt::AlignCenter);
        label_25 = new QLabel(groupBox);
        label_25->setObjectName(QStringLiteral("label_25"));
        label_25->setGeometry(QRect(160, 40, 151, 91));
        label_25->setFont(font5);
        label_25->setAlignment(Qt::AlignCenter);
        groupBox_5 = new QGroupBox(AirQualityPage);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        groupBox_5->setGeometry(QRect(520, 340, 341, 171));
        groupBox_5->setStyleSheet(QLatin1String("border-radius:13px;\n"
"background-color:white\n"
""));
        HchoP = new QLabel(groupBox_5);
        HchoP->setObjectName(QStringLiteral("HchoP"));
        HchoP->setGeometry(QRect(40, 20, 91, 91));
        HchoP->setAlignment(Qt::AlignCenter);
        label_14 = new QLabel(groupBox_5);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(40, 120, 91, 16));
        label_14->setFont(font4);
        label_14->setAlignment(Qt::AlignCenter);
        label_15 = new QLabel(groupBox_5);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(15, 140, 141, 16));
        label_15->setAlignment(Qt::AlignCenter);
        label_28 = new QLabel(groupBox_5);
        label_28->setObjectName(QStringLiteral("label_28"));
        label_28->setGeometry(QRect(170, 40, 151, 91));
        label_28->setFont(font5);
        label_28->setAlignment(Qt::AlignCenter);
        groupBox_6 = new QGroupBox(AirQualityPage);
        groupBox_6->setObjectName(QStringLiteral("groupBox_6"));
        groupBox_6->setGeometry(QRect(40, 660, 341, 171));
        groupBox_6->setStyleSheet(QLatin1String("border-radius:13px;\n"
"background-color:white\n"
""));
        Co2P = new QLabel(groupBox_6);
        Co2P->setObjectName(QStringLiteral("Co2P"));
        Co2P->setGeometry(QRect(40, 20, 91, 91));
        Co2P->setAlignment(Qt::AlignCenter);
        label_20 = new QLabel(groupBox_6);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setGeometry(QRect(30, 120, 121, 16));
        label_20->setFont(font4);
        label_20->setAlignment(Qt::AlignCenter);
        label_21 = new QLabel(groupBox_6);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setGeometry(QRect(40, 140, 91, 21));
        label_21->setAlignment(Qt::AlignCenter);
        label_29 = new QLabel(groupBox_6);
        label_29->setObjectName(QStringLiteral("label_29"));
        label_29->setGeometry(QRect(160, 40, 151, 91));
        label_29->setFont(font5);
        label_29->setAlignment(Qt::AlignCenter);
        OutSideTemp = new QGroupBox(Bottom);
        OutSideTemp->setObjectName(QStringLiteral("OutSideTemp"));
        OutSideTemp->setGeometry(QRect(120, 750, 321, 141));
        OutSideTemp->setStyleSheet(QLatin1String("QGroupBox#OutSideTemp{\n"
"	background-color:white;\n"
"	border-radius:15px;\n"
"}"));
        TempP2 = new QLabel(OutSideTemp);
        TempP2->setObjectName(QStringLiteral("TempP2"));
        TempP2->setGeometry(QRect(40, 20, 100, 100));
        label_19 = new QLabel(OutSideTemp);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setGeometry(QRect(170, 100, 111, 31));
        QFont font6;
        font6.setPointSize(13);
        font6.setBold(true);
        font6.setWeight(75);
        label_19->setFont(font6);
        label_19->setAlignment(Qt::AlignCenter);
        OutSideTempLabel = new QLabel(OutSideTemp);
        OutSideTempLabel->setObjectName(QStringLiteral("OutSideTempLabel"));
        OutSideTempLabel->setGeometry(QRect(180, 20, 111, 81));
        QFont font7;
        font7.setPointSize(40);
        font7.setBold(true);
        font7.setWeight(75);
        OutSideTempLabel->setFont(font7);
        OutSideTempLabel->setAlignment(Qt::AlignCenter);
        OutSideHum = new QGroupBox(Bottom);
        OutSideHum->setObjectName(QStringLiteral("OutSideHum"));
        OutSideHum->setGeometry(QRect(540, 750, 321, 141));
        OutSideHum->setStyleSheet(QLatin1String("QGroupBox#OutSideHum{\n"
"	background-color:white;\n"
"	border-radius:15px;\n"
"}"));
        HumP2 = new QLabel(OutSideHum);
        HumP2->setObjectName(QStringLiteral("HumP2"));
        HumP2->setGeometry(QRect(40, 20, 100, 100));
        OutSideHumLabel = new QLabel(OutSideHum);
        OutSideHumLabel->setObjectName(QStringLiteral("OutSideHumLabel"));
        OutSideHumLabel->setGeometry(QRect(190, 20, 111, 81));
        OutSideHumLabel->setFont(font7);
        OutSideHumLabel->setAlignment(Qt::AlignCenter);
        label_32 = new QLabel(OutSideHum);
        label_32->setObjectName(QStringLiteral("label_32"));
        label_32->setGeometry(QRect(180, 100, 111, 31));
        label_32->setFont(font6);
        label_32->setAlignment(Qt::AlignCenter);

        retranslateUi(frmMain);

        QMetaObject::connectSlotsByName(frmMain);
    } // setupUi

    void retranslateUi(QWidget *frmMain)
    {
        frmMain->setWindowTitle(QApplication::translate("frmMain", "Form", nullptr));
        AirPage->setTitle(QString());
        AirSubUi->setText(QString());
        label_12->setText(QApplication::translate("frmMain", "\345\275\223\345\211\215\347\251\272\350\260\203\346\270\251\345\272\246\357\274\232", nullptr));
        AirTemp->setText(QApplication::translate("frmMain", "0", nullptr));
        MainPage->setTitle(QString());
        AirQuality->setText(QApplication::translate("frmMain", "100", nullptr));
        label_17->setText(QApplication::translate("frmMain", "\347\251\272 \346\260\224 \350\264\250 \351\207\217 \346\214\207 \346\225\260", nullptr));
        label_18->setText(QApplication::translate("frmMain", "Air quality index", nullptr));
        AirQualityP->setText(QApplication::translate("frmMain", "TextLabel", nullptr));
        LightPage->setTitle(QString());
        LightSubUi->setText(QString());
        label_10->setText(QApplication::translate("frmMain", "\345\275\223\345\211\215\350\276\205\347\201\257\344\272\256\345\272\246\357\274\232", nullptr));
        AllAuxiliaryValue->setText(QApplication::translate("frmMain", "0", nullptr));
        groupBox_7->setTitle(QString());
        TvcoP->setText(QApplication::translate("frmMain", "TextLabel", nullptr));
        label_23->setText(QApplication::translate("frmMain", "\346\214\245\345\217\221\346\200\247\346\234\211\346\234\272\345\214\226\345\220\210\347\211\251\357\274\232\351\200\202\345\256\234", nullptr));
        label_24->setText(QApplication::translate("frmMain", "TVCO", nullptr));
        label_30->setText(QApplication::translate("frmMain", "70%", nullptr));
        groupBox_4->setTitle(QString());
        label_8->setText(QApplication::translate("frmMain", "\346\271\277\345\272\246\357\274\232\346\255\243\345\270\270\n"
"", nullptr));
        label_9->setText(QApplication::translate("frmMain", "Humidity", nullptr));
        label_27->setText(QApplication::translate("frmMain", "30%", nullptr));
        HumP->setText(QApplication::translate("frmMain", "TextLabel", nullptr));
        groupBox_2->setTitle(QString());
        PM25P->setText(QApplication::translate("frmMain", "TextLabel", nullptr));
        label_5->setText(QApplication::translate("frmMain", "ParticulateMatter2.5", nullptr));
        label_6->setText(QApplication::translate("frmMain", "\351\242\227\347\262\222\347\211\251\346\265\223\345\272\246\357\274\232\344\275\216", nullptr));
        label_26->setText(QApplication::translate("frmMain", "20%", nullptr));
        groupBox->setTitle(QString());
        TempP->setText(QApplication::translate("frmMain", "TextLabel", nullptr));
        label_3->setText(QApplication::translate("frmMain", "\346\270\251\345\272\246\357\274\232\351\200\202\345\256\234", nullptr));
        label_4->setText(QApplication::translate("frmMain", "Temperature", nullptr));
        label_25->setText(QApplication::translate("frmMain", "20\302\260", nullptr));
        groupBox_5->setTitle(QString());
        HchoP->setText(QApplication::translate("frmMain", "TextLabel", nullptr));
        label_14->setText(QApplication::translate("frmMain", "\347\224\262\351\206\233\357\274\232\346\255\243\345\270\270", nullptr));
        label_15->setText(QApplication::translate("frmMain", "Temperature", nullptr));
        label_28->setText(QApplication::translate("frmMain", "59%", nullptr));
        groupBox_6->setTitle(QString());
        Co2P->setText(QApplication::translate("frmMain", "TextLabel", nullptr));
        label_20->setText(QApplication::translate("frmMain", "\344\272\214\346\260\247\345\214\226\347\242\263\357\274\232\346\255\243\345\270\270", nullptr));
        label_21->setText(QApplication::translate("frmMain", "Humidity", nullptr));
        label_29->setText(QApplication::translate("frmMain", "20%", nullptr));
        OutSideTemp->setTitle(QString());
        TempP2->setText(QApplication::translate("frmMain", "TextLabel", nullptr));
        label_19->setText(QApplication::translate("frmMain", "\346\210\267\345\244\226\346\270\251\345\272\246", nullptr));
        OutSideTempLabel->setText(QApplication::translate("frmMain", "27\302\260", nullptr));
        OutSideHum->setTitle(QString());
        HumP2->setText(QApplication::translate("frmMain", "TextLabel", nullptr));
        OutSideHumLabel->setText(QApplication::translate("frmMain", "27\302\260", nullptr));
        label_32->setText(QApplication::translate("frmMain", "\346\210\267\345\244\226\346\271\277\345\272\246", nullptr));
    } // retranslateUi

};

namespace Ui {
    class frmMain: public Ui_frmMain {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRMMAIN_H
