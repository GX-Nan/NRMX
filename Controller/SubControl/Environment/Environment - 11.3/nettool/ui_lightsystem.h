/********************************************************************************
** Form generated from reading UI file 'lightsystem.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LIGHTSYSTEM_H
#define UI_LIGHTSYSTEM_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>
#include "switchbutton.h"
#include "xprogressbar.h"

QT_BEGIN_NAMESPACE

class Ui_LightSystem
{
public:
    QFrame *bottom;
    QLabel *BrightnessP2;
    QPushButton *BackMain;
    QLabel *CurtainNumber;
    QLabel *label_3;
    QGroupBox *ButtonBox;
    QPushButton *AllLed_Status;
    QPushButton *AiMode;
    QFrame *frame;
    QSlider *Brightness_Slider;
    QLabel *SelectedLed;
    QLabel *label_7;
    SwitchButton *Color_All;
    XProgressBar *Color_Xprogress;
    XProgressBar *Brightness_Xprogress;
    QLabel *Brightness_Text;
    SwitchButton *Lux_All;
    QLabel *label_8;
    QLabel *Color_Text;
    QSlider *Device_Slider;
    QSlider *Color_Slider;
    QLabel *label_5;
    QLabel *label_6;
    QGroupBox *ChandelierBox;
    QLabel *label_11;
    QPushButton *ChandChoice;
    QStackedWidget *ChanStackedWidget;
    QWidget *ChandelierFrame2;
    QPushButton *ChandelierSwitch2;
    QWidget *ChandeBottom_2;
    QPushButton *ChandeUp2;
    QPushButton *ChandeDown2;
    QPushButton *ChandeStop2;
    QWidget *ChandelierFrame1;
    QWidget *ChandeBottom;
    QPushButton *ChandeUp1;
    QPushButton *ChandeDown1;
    QPushButton *ChandeStop1;
    QPushButton *ChandelierSwitch1;
    QGroupBox *LEDBox;
    QPushButton *LedAll;
    QLabel *label_9;
    QPushButton *LedChoice;
    QGroupBox *SpotBox;
    QPushButton *SpotAll;
    QLabel *label_10;
    QPushButton *SpotChoice;
    QStackedWidget *LedSpot;
    QWidget *LED;
    QFrame *SpotFrame;
    QPushButton *SpotMeet1;
    QPushButton *SpotOffice1;
    QPushButton *SpotMeet2;
    QPushButton *SpotBar2;
    QPushButton *SpotOffice2;
    QPushButton *SpotBar1;
    QLabel *label_13;
    QWidget *SpotLight;
    QFrame *LedFrame;
    QPushButton *LedMeet1;
    QPushButton *LedOffice1;
    QPushButton *LedMeet2;
    QPushButton *LedBar2;
    QPushButton *LedOffice2;
    QPushButton *LedBar1;
    QLabel *label_12;

    void setupUi(QDialog *LightSystem)
    {
        if (LightSystem->objectName().isEmpty())
            LightSystem->setObjectName(QStringLiteral("LightSystem"));
        LightSystem->resize(1332, 893);
        LightSystem->setStyleSheet(QLatin1String("QDialog#LightSystem{\n"
"background-color:rgb(178,178,178,255);\n"
"}"));
        bottom = new QFrame(LightSystem);
        bottom->setObjectName(QStringLiteral("bottom"));
        bottom->setGeometry(QRect(30, 20, 1111, 841));
        bottom->setStyleSheet(QLatin1String("QFrame#bottom\n"
"{\n"
"	background-color:#ffffff;\n"
" \n"
"	border:none;\n"
"	border-radius:25px;\n"
"}"));
        bottom->setFrameShape(QFrame::StyledPanel);
        bottom->setFrameShadow(QFrame::Raised);
        BrightnessP2 = new QLabel(bottom);
        BrightnessP2->setObjectName(QStringLiteral("BrightnessP2"));
        BrightnessP2->setGeometry(QRect(120, 340, 100, 100));
        BackMain = new QPushButton(bottom);
        BackMain->setObjectName(QStringLiteral("BackMain"));
        BackMain->setGeometry(QRect(1040, 20, 50, 50));
        BackMain->setStyleSheet(QLatin1String("max-width:50px;\n"
" max-height:50px;\n"
" min-width:50px;\n"
" min-height:50px;\n"
"border-radius:25px;\n"
"background-color: white;\n"
" border-style: solid;"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/new/Main/Air/Back.png"), QSize(), QIcon::Normal, QIcon::Off);
        BackMain->setIcon(icon);
        BackMain->setIconSize(QSize(50, 50));
        CurtainNumber = new QLabel(bottom);
        CurtainNumber->setObjectName(QStringLiteral("CurtainNumber"));
        CurtainNumber->setGeometry(QRect(50, 50, 371, 281));
        QFont font;
        font.setFamily(QStringLiteral("PibotoLt"));
        font.setPointSize(170);
        font.setBold(true);
        font.setItalic(false);
        font.setWeight(75);
        CurtainNumber->setFont(font);
        CurtainNumber->setStyleSheet(QStringLiteral(""));
        CurtainNumber->setAlignment(Qt::AlignCenter);
        label_3 = new QLabel(bottom);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(260, 380, 101, 31));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Adobe \351\273\221\344\275\223 Std R"));
        font1.setPointSize(15);
        font1.setBold(true);
        font1.setWeight(75);
        label_3->setFont(font1);
        label_3->setStyleSheet(QStringLiteral("color:#282A49"));
        label_3->setScaledContents(false);
        label_3->setAlignment(Qt::AlignCenter);
        label_3->setWordWrap(true);
        ButtonBox = new QGroupBox(bottom);
        ButtonBox->setObjectName(QStringLiteral("ButtonBox"));
        ButtonBox->setGeometry(QRect(60, 490, 401, 291));
        ButtonBox->setStyleSheet(QLatin1String("QGroupBox#ButtonBox{\n"
"border:none;\n"
"}"));
        AllLed_Status = new QPushButton(ButtonBox);
        AllLed_Status->setObjectName(QStringLiteral("AllLed_Status"));
        AllLed_Status->setGeometry(QRect(20, 170, 371, 91));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Adobe \351\273\221\344\275\223 Std R"));
        font2.setPointSize(15);
        AllLed_Status->setFont(font2);
        AllLed_Status->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	border-radius:15px;\n"
"	background:#FFFFFF;\n"
"}"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/new/Led/Led/All_Light_OFF.png"), QSize(), QIcon::Normal, QIcon::Off);
        AllLed_Status->setIcon(icon1);
        AllLed_Status->setIconSize(QSize(100, 50));
        AllLed_Status->setCheckable(true);
        AllLed_Status->setAutoExclusive(true);
        AiMode = new QPushButton(ButtonBox);
        AiMode->setObjectName(QStringLiteral("AiMode"));
        AiMode->setGeometry(QRect(20, 20, 371, 91));
        AiMode->setFont(font2);
        AiMode->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	border-radius:15px;\n"
"	background:#FFFFFF;\n"
"}"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/new/Led/Led/AI_ON.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon2.addFile(QStringLiteral(":/new/Led/Led/AI_OFF.png"), QSize(), QIcon::Normal, QIcon::On);
        AiMode->setIcon(icon2);
        AiMode->setIconSize(QSize(70, 70));
        AiMode->setAutoRepeatDelay(300);
        AiMode->setAutoRepeatInterval(200);
        frame = new QFrame(bottom);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(520, 440, 551, 361));
        frame->setStyleSheet(QLatin1String("QFrame#frame\n"
"{\n"
"	border-radius:15px;\n"
"	background:#FFFFFF;\n"
"}"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        Brightness_Slider = new QSlider(frame);
        Brightness_Slider->setObjectName(QStringLiteral("Brightness_Slider"));
        Brightness_Slider->setGeometry(QRect(50, 100, 351, 21));
        Brightness_Slider->setMaximum(100);
        Brightness_Slider->setOrientation(Qt::Horizontal);
        SelectedLed = new QLabel(frame);
        SelectedLed->setObjectName(QStringLiteral("SelectedLed"));
        SelectedLed->setGeometry(QRect(340, 275, 31, 31));
        SelectedLed->setFont(font1);
        SelectedLed->setStyleSheet(QStringLiteral("color:#282A49"));
        SelectedLed->setScaledContents(false);
        SelectedLed->setAlignment(Qt::AlignCenter);
        SelectedLed->setWordWrap(true);
        label_7 = new QLabel(frame);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(210, 60, 91, 29));
        label_7->setFont(font1);
        label_7->setStyleSheet(QStringLiteral("color:#282A49"));
        label_7->setScaledContents(false);
        label_7->setAlignment(Qt::AlignCenter);
        label_7->setWordWrap(true);
        Color_All = new SwitchButton(frame);
        Color_All->setObjectName(QStringLiteral("Color_All"));
        Color_All->setGeometry(QRect(410, 220, 81, 31));
        Color_Xprogress = new XProgressBar(frame);
        Color_Xprogress->setObjectName(QStringLiteral("Color_Xprogress"));
        Color_Xprogress->setGeometry(QRect(50, 150, 441, 21));
        Brightness_Xprogress = new XProgressBar(frame);
        Brightness_Xprogress->setObjectName(QStringLiteral("Brightness_Xprogress"));
        Brightness_Xprogress->setGeometry(QRect(50, 30, 441, 21));
        Brightness_Text = new QLabel(frame);
        Brightness_Text->setObjectName(QStringLiteral("Brightness_Text"));
        Brightness_Text->setGeometry(QRect(290, 60, 51, 29));
        Brightness_Text->setFont(font1);
        Brightness_Text->setStyleSheet(QStringLiteral("color:#282A49"));
        Brightness_Text->setScaledContents(false);
        Brightness_Text->setAlignment(Qt::AlignCenter);
        Brightness_Text->setWordWrap(true);
        Lux_All = new SwitchButton(frame);
        Lux_All->setObjectName(QStringLiteral("Lux_All"));
        Lux_All->setGeometry(QRect(410, 90, 81, 31));
        label_8 = new QLabel(frame);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(210, 190, 91, 29));
        label_8->setFont(font1);
        label_8->setStyleSheet(QStringLiteral("color:#282A49"));
        label_8->setScaledContents(false);
        label_8->setAlignment(Qt::AlignCenter);
        label_8->setWordWrap(true);
        Color_Text = new QLabel(frame);
        Color_Text->setObjectName(QStringLiteral("Color_Text"));
        Color_Text->setGeometry(QRect(290, 190, 51, 29));
        Color_Text->setFont(font1);
        Color_Text->setStyleSheet(QStringLiteral("color:#282A49"));
        Color_Text->setScaledContents(false);
        Color_Text->setAlignment(Qt::AlignCenter);
        Color_Text->setWordWrap(true);
        Device_Slider = new QSlider(frame);
        Device_Slider->setObjectName(QStringLiteral("Device_Slider"));
        Device_Slider->setGeometry(QRect(50, 320, 441, 20));
        Device_Slider->setMinimum(1);
        Device_Slider->setMaximum(6);
        Device_Slider->setPageStep(6);
        Device_Slider->setOrientation(Qt::Horizontal);
        Color_Slider = new QSlider(frame);
        Color_Slider->setObjectName(QStringLiteral("Color_Slider"));
        Color_Slider->setGeometry(QRect(50, 230, 351, 21));
        Color_Slider->setMaximum(100);
        Color_Slider->setOrientation(Qt::Horizontal);
        label_5 = new QLabel(frame);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(220, 280, 111, 21));
        label_5->setFont(font1);
        label_5->setStyleSheet(QStringLiteral("color:#282A49"));
        label_5->setScaledContents(false);
        label_5->setAlignment(Qt::AlignCenter);
        label_5->setWordWrap(true);
        label_6 = new QLabel(frame);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(170, 270, 41, 41));
        ChandelierBox = new QGroupBox(bottom);
        ChandelierBox->setObjectName(QStringLiteral("ChandelierBox"));
        ChandelierBox->setGeometry(QRect(520, 250, 551, 151));
        ChandelierBox->setStyleSheet(QLatin1String("QGroupBox#ChandelierBox\n"
"{\n"
"	border-radius:15px;\n"
"	background:#FFFFFF;\n"
"}"));
        ChandelierBox->setAlignment(Qt::AlignCenter);
        label_11 = new QLabel(ChandelierBox);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(460, 110, 91, 41));
        label_11->setFont(font1);
        label_11->setStyleSheet(QStringLiteral("color:#282A49"));
        label_11->setScaledContents(false);
        label_11->setAlignment(Qt::AlignCenter);
        label_11->setWordWrap(true);
        ChandChoice = new QPushButton(ChandelierBox);
        ChandChoice->setObjectName(QStringLiteral("ChandChoice"));
        ChandChoice->setGeometry(QRect(490, 0, 51, 41));
        QFont font3;
        font3.setPointSize(20);
        font3.setBold(true);
        font3.setWeight(75);
        ChandChoice->setFont(font3);
        ChandChoice->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	border-radius:15px;\n"
"	background:#FFFFFF;\n"
"}"));
        ChanStackedWidget = new QStackedWidget(ChandelierBox);
        ChanStackedWidget->setObjectName(QStringLiteral("ChanStackedWidget"));
        ChanStackedWidget->setGeometry(QRect(10, 20, 491, 121));
        ChandelierFrame2 = new QWidget();
        ChandelierFrame2->setObjectName(QStringLiteral("ChandelierFrame2"));
        ChandelierSwitch2 = new QPushButton(ChandelierFrame2);
        ChandelierSwitch2->setObjectName(QStringLiteral("ChandelierSwitch2"));
        ChandelierSwitch2->setGeometry(QRect(390, 20, 91, 81));
        ChandelierSwitch2->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	border-radius:15px;\n"
"	background:#FFFFFF;\n"
"}"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/new/Air/Air/AirSwitch.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon3.addFile(QStringLiteral(":/new/Air/Air/AirSwitch-ON.png"), QSize(), QIcon::Normal, QIcon::On);
        ChandelierSwitch2->setIcon(icon3);
        ChandelierSwitch2->setIconSize(QSize(50, 50));
        ChandelierSwitch2->setCheckable(true);
        ChandelierSwitch2->setChecked(false);
        ChandelierSwitch2->setAutoRepeat(false);
        ChandelierSwitch2->setAutoExclusive(false);
        ChandeBottom_2 = new QWidget(ChandelierFrame2);
        ChandeBottom_2->setObjectName(QStringLiteral("ChandeBottom_2"));
        ChandeBottom_2->setGeometry(QRect(0, 5, 391, 121));
        ChandeUp2 = new QPushButton(ChandeBottom_2);
        ChandeUp2->setObjectName(QStringLiteral("ChandeUp2"));
        ChandeUp2->setGeometry(QRect(270, 15, 91, 81));
        ChandeUp2->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	border-radius:15px;\n"
"	background:#FFFFFF;\n"
"}"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/new/Led/Curtain/Up_OFF.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon4.addFile(QStringLiteral(":/new/Led/Curtain/Up_ON.png"), QSize(), QIcon::Normal, QIcon::On);
        ChandeUp2->setIcon(icon4);
        ChandeUp2->setIconSize(QSize(80, 80));
        ChandeUp2->setCheckable(true);
        ChandeUp2->setChecked(false);
        ChandeUp2->setAutoRepeat(true);
        ChandeUp2->setAutoExclusive(true);
        ChandeDown2 = new QPushButton(ChandeBottom_2);
        ChandeDown2->setObjectName(QStringLiteral("ChandeDown2"));
        ChandeDown2->setGeometry(QRect(30, 15, 91, 81));
        ChandeDown2->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	border-radius:15px;\n"
"	background:#FFFFFF;\n"
"}"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/new/Led/Curtain/Down_OFF.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon5.addFile(QStringLiteral(":/new/Led/Curtain/Down_ON.png"), QSize(), QIcon::Normal, QIcon::On);
        ChandeDown2->setIcon(icon5);
        ChandeDown2->setIconSize(QSize(80, 80));
        ChandeDown2->setCheckable(true);
        ChandeDown2->setChecked(false);
        ChandeDown2->setAutoRepeat(true);
        ChandeDown2->setAutoExclusive(true);
        ChandeStop2 = new QPushButton(ChandeBottom_2);
        ChandeStop2->setObjectName(QStringLiteral("ChandeStop2"));
        ChandeStop2->setGeometry(QRect(150, 15, 91, 81));
        ChandeStop2->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	border-radius:15px;\n"
"	background:#FFFFFF;\n"
"}"));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/new/Led/Curtain/Stop_OFF.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon6.addFile(QStringLiteral(":/new/Led/Curtain/Stop_ON.png"), QSize(), QIcon::Normal, QIcon::On);
        ChandeStop2->setIcon(icon6);
        ChandeStop2->setIconSize(QSize(60, 60));
        ChandeStop2->setCheckable(true);
        ChandeStop2->setChecked(false);
        ChandeStop2->setAutoRepeat(true);
        ChandeStop2->setAutoExclusive(true);
        ChanStackedWidget->addWidget(ChandelierFrame2);
        ChandelierFrame1 = new QWidget();
        ChandelierFrame1->setObjectName(QStringLiteral("ChandelierFrame1"));
        ChandeBottom = new QWidget(ChandelierFrame1);
        ChandeBottom->setObjectName(QStringLiteral("ChandeBottom"));
        ChandeBottom->setGeometry(QRect(0, 5, 391, 101));
        ChandeUp1 = new QPushButton(ChandeBottom);
        ChandeUp1->setObjectName(QStringLiteral("ChandeUp1"));
        ChandeUp1->setGeometry(QRect(270, 15, 91, 81));
        ChandeUp1->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	border-radius:15px;\n"
"	background:#FFFFFF;\n"
"}"));
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/new/Curtain/Curtain/Up_OFF.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon7.addFile(QStringLiteral(":/new/Led/Curtain/Up_OFF.png"), QSize(), QIcon::Normal, QIcon::On);
        icon7.addFile(QStringLiteral(":/new/Led/Curtain/Up_ON.png"), QSize(), QIcon::Disabled, QIcon::Off);
        ChandeUp1->setIcon(icon7);
        ChandeUp1->setIconSize(QSize(80, 80));
        ChandeUp1->setCheckable(true);
        ChandeUp1->setChecked(false);
        ChandeUp1->setAutoRepeat(true);
        ChandeUp1->setAutoExclusive(true);
        ChandeDown1 = new QPushButton(ChandeBottom);
        ChandeDown1->setObjectName(QStringLiteral("ChandeDown1"));
        ChandeDown1->setGeometry(QRect(30, 15, 91, 81));
        ChandeDown1->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	border-radius:15px;\n"
"	background:#FFFFFF;\n"
"}"));
        ChandeDown1->setIcon(icon5);
        ChandeDown1->setIconSize(QSize(80, 80));
        ChandeDown1->setCheckable(true);
        ChandeDown1->setChecked(false);
        ChandeDown1->setAutoRepeat(true);
        ChandeDown1->setAutoExclusive(true);
        ChandeStop1 = new QPushButton(ChandeBottom);
        ChandeStop1->setObjectName(QStringLiteral("ChandeStop1"));
        ChandeStop1->setGeometry(QRect(150, 15, 91, 81));
        ChandeStop1->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	border-radius:15px;\n"
"	background:#FFFFFF;\n"
"}"));
        ChandeStop1->setIcon(icon6);
        ChandeStop1->setIconSize(QSize(60, 60));
        ChandeStop1->setCheckable(true);
        ChandeStop1->setChecked(false);
        ChandeStop1->setAutoRepeat(true);
        ChandeStop1->setAutoExclusive(true);
        ChandelierSwitch1 = new QPushButton(ChandelierFrame1);
        ChandelierSwitch1->setObjectName(QStringLiteral("ChandelierSwitch1"));
        ChandelierSwitch1->setGeometry(QRect(390, 20, 91, 81));
        ChandelierSwitch1->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	border-radius:15px;\n"
"	background:#FFFFFF;\n"
"}"));
        ChandelierSwitch1->setIcon(icon3);
        ChandelierSwitch1->setIconSize(QSize(50, 50));
        ChandelierSwitch1->setCheckable(true);
        ChandelierSwitch1->setChecked(false);
        ChandelierSwitch1->setAutoRepeat(false);
        ChandelierSwitch1->setAutoExclusive(false);
        ChanStackedWidget->addWidget(ChandelierFrame1);
        ChandChoice->raise();
        ChanStackedWidget->raise();
        label_11->raise();
        LEDBox = new QGroupBox(bottom);
        LEDBox->setObjectName(QStringLiteral("LEDBox"));
        LEDBox->setGeometry(QRect(520, 80, 251, 131));
        LEDBox->setStyleSheet(QLatin1String("QGroupBox#LEDBox\n"
"{\n"
"	border-radius:15px;\n"
"	background:#FFFFFF;\n"
"}"));
        LedAll = new QPushButton(LEDBox);
        LedAll->setObjectName(QStringLiteral("LedAll"));
        LedAll->setGeometry(QRect(70, 20, 91, 91));
        LedAll->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	border-radius:15px;\n"
"	background:#FFFFFF;\n"
"}"));
        LedAll->setIcon(icon3);
        LedAll->setIconSize(QSize(60, 60));
        label_9 = new QLabel(LEDBox);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(170, 90, 91, 41));
        label_9->setFont(font1);
        label_9->setStyleSheet(QStringLiteral("color:#282A49"));
        label_9->setScaledContents(false);
        label_9->setAlignment(Qt::AlignCenter);
        label_9->setWordWrap(true);
        LedChoice = new QPushButton(LEDBox);
        LedChoice->setObjectName(QStringLiteral("LedChoice"));
        LedChoice->setGeometry(QRect(190, 10, 51, 41));
        LedChoice->setFont(font3);
        LedChoice->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	border-radius:15px;\n"
"	background:#FFFFFF;\n"
"}"));
        SpotBox = new QGroupBox(bottom);
        SpotBox->setObjectName(QStringLiteral("SpotBox"));
        SpotBox->setGeometry(QRect(820, 80, 251, 131));
        SpotBox->setStyleSheet(QLatin1String("QGroupBox#SpotBox\n"
"{\n"
"	border-radius:15px;\n"
"	background:#FFFFFF;\n"
"}"));
        SpotAll = new QPushButton(SpotBox);
        SpotAll->setObjectName(QStringLiteral("SpotAll"));
        SpotAll->setGeometry(QRect(80, 20, 91, 91));
        SpotAll->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	border-radius:15px;\n"
"	background:#FFFFFF;\n"
"}"));
        SpotAll->setIcon(icon3);
        SpotAll->setIconSize(QSize(60, 60));
        label_10 = new QLabel(SpotBox);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(170, 90, 91, 41));
        label_10->setFont(font1);
        label_10->setStyleSheet(QStringLiteral("color:#282A49"));
        label_10->setScaledContents(false);
        label_10->setAlignment(Qt::AlignCenter);
        label_10->setWordWrap(true);
        SpotChoice = new QPushButton(SpotBox);
        SpotChoice->setObjectName(QStringLiteral("SpotChoice"));
        SpotChoice->setGeometry(QRect(190, 10, 51, 41));
        SpotChoice->setFont(font3);
        SpotChoice->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	border-radius:15px;\n"
"	background:#FFFFFF;\n"
"}"));
        LedSpot = new QStackedWidget(LightSystem);
        LedSpot->setObjectName(QStringLiteral("LedSpot"));
        LedSpot->setGeometry(QRect(1180, 20, 131, 841));
        LedSpot->setStyleSheet(QLatin1String("QStackedWidget#LedSpot\n"
"{\n"
"	background-color:#ffffff;\n"
"	border:none;\n"
"	border-radius:15px;\n"
"}"));
        LED = new QWidget();
        LED->setObjectName(QStringLiteral("LED"));
        SpotFrame = new QFrame(LED);
        SpotFrame->setObjectName(QStringLiteral("SpotFrame"));
        SpotFrame->setGeometry(QRect(-15, -11, 161, 871));
        SpotFrame->setFrameShape(QFrame::StyledPanel);
        SpotFrame->setFrameShadow(QFrame::Raised);
        SpotMeet1 = new QPushButton(SpotFrame);
        SpotMeet1->setObjectName(QStringLiteral("SpotMeet1"));
        SpotMeet1->setGeometry(QRect(36, 30, 91, 91));
        SpotMeet1->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	border-radius:15px;\n"
"	background:#FFFFFF;\n"
"}"));
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/new/Led/Led/Meeting_OFF.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon8.addFile(QStringLiteral(":/new/Led/Led/Meeting_ON.png"), QSize(), QIcon::Normal, QIcon::On);
        SpotMeet1->setIcon(icon8);
        SpotMeet1->setIconSize(QSize(60, 60));
        SpotMeet1->setCheckable(true);
        SpotOffice1 = new QPushButton(SpotFrame);
        SpotOffice1->setObjectName(QStringLiteral("SpotOffice1"));
        SpotOffice1->setGeometry(QRect(36, 570, 91, 91));
        SpotOffice1->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	border-radius:15px;\n"
"	background:#FFFFFF;\n"
"}"));
        QIcon icon9;
        icon9.addFile(QStringLiteral(":/new/Led/Led/Office_OFF.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon9.addFile(QStringLiteral(":/new/Led/Led/Office_ON.png"), QSize(), QIcon::Normal, QIcon::On);
        SpotOffice1->setIcon(icon9);
        SpotOffice1->setIconSize(QSize(60, 60));
        SpotOffice1->setCheckable(true);
        SpotMeet2 = new QPushButton(SpotFrame);
        SpotMeet2->setObjectName(QStringLiteral("SpotMeet2"));
        SpotMeet2->setGeometry(QRect(36, 170, 91, 91));
        SpotMeet2->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	border-radius:15px;\n"
"	background:#FFFFFF;\n"
"}"));
        QIcon icon10;
        icon10.addFile(QStringLiteral(":/new/Led/Led/Meeting_OFF.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon10.addFile(QStringLiteral(":/new/Led/Led/Meeting_ON.png"), QSize(), QIcon::Normal, QIcon::On);
        icon10.addFile(QStringLiteral(":/new/Led/Led/Meeting_ON.png"), QSize(), QIcon::Disabled, QIcon::Off);
        SpotMeet2->setIcon(icon10);
        SpotMeet2->setIconSize(QSize(60, 60));
        SpotMeet2->setCheckable(true);
        SpotBar2 = new QPushButton(SpotFrame);
        SpotBar2->setObjectName(QStringLiteral("SpotBar2"));
        SpotBar2->setGeometry(QRect(36, 440, 91, 91));
        SpotBar2->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	border-radius:15px;\n"
"	background:#FFFFFF;\n"
"}"));
        QIcon icon11;
        icon11.addFile(QStringLiteral(":/new/Led/Led/Bar_OFF.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon11.addFile(QStringLiteral(":/new/Led/Led/Bar_ON.png"), QSize(), QIcon::Normal, QIcon::On);
        SpotBar2->setIcon(icon11);
        SpotBar2->setIconSize(QSize(60, 60));
        SpotBar2->setCheckable(true);
        SpotOffice2 = new QPushButton(SpotFrame);
        SpotOffice2->setObjectName(QStringLiteral("SpotOffice2"));
        SpotOffice2->setGeometry(QRect(36, 700, 91, 91));
        SpotOffice2->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	border-radius:15px;\n"
"	background:#FFFFFF;\n"
"}"));
        SpotOffice2->setIcon(icon9);
        SpotOffice2->setIconSize(QSize(60, 60));
        SpotOffice2->setCheckable(true);
        SpotBar1 = new QPushButton(SpotFrame);
        SpotBar1->setObjectName(QStringLiteral("SpotBar1"));
        SpotBar1->setGeometry(QRect(36, 310, 91, 91));
        SpotBar1->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	border-radius:15px;\n"
"	background:#FFFFFF;\n"
"}"));
        SpotBar1->setIcon(icon11);
        SpotBar1->setIconSize(QSize(60, 60));
        SpotBar1->setCheckable(true);
        label_13 = new QLabel(SpotFrame);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(40, 800, 91, 41));
        label_13->setFont(font1);
        label_13->setStyleSheet(QStringLiteral("color:#282A49"));
        label_13->setScaledContents(false);
        label_13->setAlignment(Qt::AlignCenter);
        label_13->setWordWrap(true);
        LedSpot->addWidget(LED);
        SpotLight = new QWidget();
        SpotLight->setObjectName(QStringLiteral("SpotLight"));
        LedFrame = new QFrame(SpotLight);
        LedFrame->setObjectName(QStringLiteral("LedFrame"));
        LedFrame->setGeometry(QRect(-5, -10, 151, 871));
        LedFrame->setFrameShape(QFrame::StyledPanel);
        LedFrame->setFrameShadow(QFrame::Raised);
        LedMeet1 = new QPushButton(LedFrame);
        LedMeet1->setObjectName(QStringLiteral("LedMeet1"));
        LedMeet1->setGeometry(QRect(26, 30, 91, 91));
        LedMeet1->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	border-radius:15px;\n"
"	background:#FFFFFF;\n"
"}"));
        LedMeet1->setIcon(icon8);
        LedMeet1->setIconSize(QSize(60, 60));
        LedMeet1->setCheckable(true);
        LedMeet1->setAutoExclusive(false);
        LedOffice1 = new QPushButton(LedFrame);
        LedOffice1->setObjectName(QStringLiteral("LedOffice1"));
        LedOffice1->setGeometry(QRect(26, 570, 91, 91));
        LedOffice1->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	border-radius:15px;\n"
"	background:#FFFFFF;\n"
"}"));
        LedOffice1->setIcon(icon9);
        LedOffice1->setIconSize(QSize(60, 60));
        LedOffice1->setCheckable(true);
        LedMeet2 = new QPushButton(LedFrame);
        LedMeet2->setObjectName(QStringLiteral("LedMeet2"));
        LedMeet2->setGeometry(QRect(26, 170, 91, 91));
        LedMeet2->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	border-radius:15px;\n"
"	background:#FFFFFF;\n"
"}"));
        LedMeet2->setIcon(icon10);
        LedMeet2->setIconSize(QSize(60, 60));
        LedMeet2->setCheckable(true);
        LedBar2 = new QPushButton(LedFrame);
        LedBar2->setObjectName(QStringLiteral("LedBar2"));
        LedBar2->setGeometry(QRect(26, 440, 91, 91));
        LedBar2->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	border-radius:15px;\n"
"	background:#FFFFFF;\n"
"}"));
        LedBar2->setIcon(icon11);
        LedBar2->setIconSize(QSize(60, 60));
        LedBar2->setCheckable(true);
        LedOffice2 = new QPushButton(LedFrame);
        LedOffice2->setObjectName(QStringLiteral("LedOffice2"));
        LedOffice2->setGeometry(QRect(26, 700, 91, 91));
        LedOffice2->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	border-radius:15px;\n"
"	background:#FFFFFF;\n"
"}"));
        LedOffice2->setIcon(icon9);
        LedOffice2->setIconSize(QSize(60, 60));
        LedOffice2->setCheckable(true);
        LedBar1 = new QPushButton(LedFrame);
        LedBar1->setObjectName(QStringLiteral("LedBar1"));
        LedBar1->setGeometry(QRect(26, 310, 91, 91));
        LedBar1->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	border-radius:15px;\n"
"	background:#FFFFFF;\n"
"}"));
        LedBar1->setIcon(icon11);
        LedBar1->setIconSize(QSize(60, 60));
        LedBar1->setCheckable(true);
        label_12 = new QLabel(LedFrame);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(30, 810, 91, 41));
        label_12->setFont(font1);
        label_12->setStyleSheet(QStringLiteral("color:#282A49"));
        label_12->setScaledContents(false);
        label_12->setAlignment(Qt::AlignCenter);
        label_12->setWordWrap(true);
        LedSpot->addWidget(SpotLight);

        retranslateUi(LightSystem);

        ChanStackedWidget->setCurrentIndex(0);
        LedSpot->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(LightSystem);
    } // setupUi

    void retranslateUi(QDialog *LightSystem)
    {
        LightSystem->setWindowTitle(QApplication::translate("LightSystem", "Dialog", nullptr));
        BrightnessP2->setText(QApplication::translate("LightSystem", "TextLabel", nullptr));
        BackMain->setText(QString());
        CurtainNumber->setText(QApplication::translate("LightSystem", "100", nullptr));
        label_3->setText(QApplication::translate("LightSystem", "\345\256\244\345\206\205\344\272\256\345\272\246", nullptr));
        ButtonBox->setTitle(QString());
        AllLed_Status->setText(QString());
        AiMode->setText(QString());
        SelectedLed->setText(QApplication::translate("LightSystem", "1", nullptr));
        label_7->setText(QApplication::translate("LightSystem", "\344\272\256\345\272\246\357\274\232", nullptr));
        Brightness_Text->setText(QApplication::translate("LightSystem", "0", nullptr));
        label_8->setText(QApplication::translate("LightSystem", "\350\211\262\346\270\251\357\274\232", nullptr));
        Color_Text->setText(QApplication::translate("LightSystem", "0", nullptr));
        label_5->setText(QApplication::translate("LightSystem", "\345\275\223\345\211\215\347\201\257\345\205\211:", nullptr));
        label_6->setText(QApplication::translate("LightSystem", "TextLabel", nullptr));
        ChandelierBox->setTitle(QString());
        label_11->setText(QApplication::translate("LightSystem", "\345\220\212\347\201\257--1", nullptr));
        ChandChoice->setText(QApplication::translate("LightSystem", "...", nullptr));
        ChandelierSwitch2->setText(QString());
        ChandeUp2->setText(QString());
        ChandeDown2->setText(QString());
        ChandeStop2->setText(QString());
        ChandeUp1->setText(QString());
        ChandeDown1->setText(QString());
        ChandeStop1->setText(QString());
        ChandelierSwitch1->setText(QString());
        LEDBox->setTitle(QString());
        LedAll->setText(QString());
        label_9->setText(QApplication::translate("LightSystem", "LED", nullptr));
        LedChoice->setText(QApplication::translate("LightSystem", "...", nullptr));
        SpotBox->setTitle(QString());
        SpotAll->setText(QString());
        label_10->setText(QApplication::translate("LightSystem", "\345\260\204\347\201\257", nullptr));
        SpotChoice->setText(QApplication::translate("LightSystem", "...", nullptr));
        SpotMeet1->setText(QString());
        SpotOffice1->setText(QString());
        SpotMeet2->setText(QString());
        SpotBar2->setText(QString());
        SpotOffice2->setText(QString());
        SpotBar1->setText(QString());
        label_13->setText(QApplication::translate("LightSystem", "\345\260\204\347\201\257", nullptr));
        LedMeet1->setText(QString());
        LedOffice1->setText(QString());
        LedMeet2->setText(QString());
        LedBar2->setText(QString());
        LedOffice2->setText(QString());
        LedBar1->setText(QString());
        label_12->setText(QApplication::translate("LightSystem", "LED", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LightSystem: public Ui_LightSystem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LIGHTSYSTEM_H
