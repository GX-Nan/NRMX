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
    QStackedWidget *PageBottom;
    QWidget *LightMain;
    QLabel *label_3;
    QLabel *BrightnessP2;
    QLabel *CurtainNumber;
    QGroupBox *ButtonBox;
    QPushButton *AllLed_Status;
    QPushButton *AiMode;
    QPushButton *BackMain;
    QPushButton *ModeChoice_2;
    QPushButton *AloneControl;
    QWidget *AloneLight;
    SwitchButton *Led_Switch;
    QSlider *Brightness_Slider;
    XProgressBar *Brightness_Xprogress;
    QSlider *Color_Slider;
    XProgressBar *Color_Xprogress;
    QLabel *InsidesBrightness;
    QLabel *label_4;
    QSlider *Device_Slider;
    QLabel *label_5;
    QLabel *label_7;
    QLabel *Brightness_Text;
    SwitchButton *Lux_All;
    SwitchButton *Color_All;
    QLabel *BrightnessP;
    QLabel *label_6;
    QPushButton *ModeChoice;
    QLabel *label_8;
    QLabel *Color_Text;
    QLabel *SelectedLed;

    void setupUi(QDialog *LightSystem)
    {
        if (LightSystem->objectName().isEmpty())
            LightSystem->setObjectName(QStringLiteral("LightSystem"));
        LightSystem->resize(511, 844);
        LightSystem->setStyleSheet(QLatin1String("QDialog#LightSystem{\n"
"background-color:rgb(178,178,178,255);\n"
"}"));
        bottom = new QFrame(LightSystem);
        bottom->setObjectName(QStringLiteral("bottom"));
        bottom->setGeometry(QRect(10, 20, 491, 811));
        bottom->setStyleSheet(QLatin1String("QFrame#bottom\n"
"{\n"
"	background-color:#ffffff;\n"
" \n"
"	border:none;\n"
"	border-radius:25px;\n"
"}"));
        bottom->setFrameShape(QFrame::StyledPanel);
        bottom->setFrameShadow(QFrame::Raised);
        PageBottom = new QStackedWidget(bottom);
        PageBottom->setObjectName(QStringLiteral("PageBottom"));
        PageBottom->setGeometry(QRect(0, 0, 491, 811));
        LightMain = new QWidget();
        LightMain->setObjectName(QStringLiteral("LightMain"));
        label_3 = new QLabel(LightMain);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(250, 320, 101, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("Adobe \351\273\221\344\275\223 Std R"));
        font.setPointSize(15);
        font.setBold(true);
        font.setWeight(75);
        label_3->setFont(font);
        label_3->setStyleSheet(QStringLiteral("color:#282A49"));
        label_3->setScaledContents(false);
        label_3->setAlignment(Qt::AlignCenter);
        label_3->setWordWrap(true);
        BrightnessP2 = new QLabel(LightMain);
        BrightnessP2->setObjectName(QStringLiteral("BrightnessP2"));
        BrightnessP2->setGeometry(QRect(140, 280, 100, 100));
        CurtainNumber = new QLabel(LightMain);
        CurtainNumber->setObjectName(QStringLiteral("CurtainNumber"));
        CurtainNumber->setGeometry(QRect(60, 10, 351, 321));
        QFont font1;
        font1.setFamily(QStringLiteral("PibotoLt"));
        font1.setPointSize(150);
        font1.setBold(true);
        font1.setItalic(false);
        font1.setWeight(75);
        CurtainNumber->setFont(font1);
        CurtainNumber->setStyleSheet(QStringLiteral(""));
        CurtainNumber->setAlignment(Qt::AlignCenter);
        ButtonBox = new QGroupBox(LightMain);
        ButtonBox->setObjectName(QStringLiteral("ButtonBox"));
        ButtonBox->setGeometry(QRect(90, 380, 331, 351));
        ButtonBox->setStyleSheet(QLatin1String("QGroupBox#ButtonBox{\n"
"border:none;\n"
"}"));
        AllLed_Status = new QPushButton(ButtonBox);
        AllLed_Status->setObjectName(QStringLiteral("AllLed_Status"));
        AllLed_Status->setGeometry(QRect(20, 210, 291, 91));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Adobe \351\273\221\344\275\223 Std R"));
        font2.setPointSize(15);
        AllLed_Status->setFont(font2);
        AllLed_Status->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	border-radius:15px;\n"
"	background:#FFFFFF;\n"
"}"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/new/Led/Led/All_Light_OFF.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon.addFile(QStringLiteral(":/new/Led/Led/AirSwitch-ON.png"), QSize(), QIcon::Normal, QIcon::On);
        AllLed_Status->setIcon(icon);
        AllLed_Status->setIconSize(QSize(100, 50));
        AllLed_Status->setCheckable(true);
        AllLed_Status->setAutoExclusive(true);
        AiMode = new QPushButton(ButtonBox);
        AiMode->setObjectName(QStringLiteral("AiMode"));
        AiMode->setGeometry(QRect(20, 50, 291, 91));
        AiMode->setFont(font2);
        AiMode->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	border-radius:15px;\n"
"	background:#FFFFFF;\n"
"}"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/new/Led/Led/AI_ON.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon1.addFile(QStringLiteral(":/new/Led/Led/AI_OFF.png"), QSize(), QIcon::Normal, QIcon::On);
        AiMode->setIcon(icon1);
        AiMode->setIconSize(QSize(70, 70));
        AiMode->setAutoRepeatDelay(300);
        AiMode->setAutoRepeatInterval(200);
        BackMain = new QPushButton(LightMain);
        BackMain->setObjectName(QStringLiteral("BackMain"));
        BackMain->setGeometry(QRect(430, 10, 50, 50));
        BackMain->setStyleSheet(QLatin1String("max-width:50px;\n"
" max-height:50px;\n"
" min-width:50px;\n"
" min-height:50px;\n"
"border-radius:25px;\n"
"background-color: white;\n"
" border-style: solid;"));
        ModeChoice_2 = new QPushButton(LightMain);
        ModeChoice_2->setObjectName(QStringLiteral("ModeChoice_2"));
        ModeChoice_2->setGeometry(QRect(380, 750, 50, 50));
        ModeChoice_2->setStyleSheet(QLatin1String("max-width:50px;\n"
" max-height:50px;\n"
" min-width:50px;\n"
" min-height:50px;\n"
"border-radius:25px;\n"
"background-color: white;\n"
" border-style: solid;"));
        AloneControl = new QPushButton(LightMain);
        AloneControl->setObjectName(QStringLiteral("AloneControl"));
        AloneControl->setGeometry(QRect(60, 750, 50, 50));
        AloneControl->setStyleSheet(QLatin1String("max-width:50px;\n"
" max-height:50px;\n"
" min-width:50px;\n"
" min-height:50px;\n"
"border-radius:25px;\n"
"background-color: white;\n"
" border-style: solid;"));
        PageBottom->addWidget(LightMain);
        AloneLight = new QWidget();
        AloneLight->setObjectName(QStringLiteral("AloneLight"));
        Led_Switch = new SwitchButton(AloneLight);
        Led_Switch->setObjectName(QStringLiteral("Led_Switch"));
        Led_Switch->setGeometry(QRect(210, 760, 91, 31));
        Brightness_Slider = new QSlider(AloneLight);
        Brightness_Slider->setObjectName(QStringLiteral("Brightness_Slider"));
        Brightness_Slider->setGeometry(QRect(30, 510, 351, 21));
        Brightness_Slider->setOrientation(Qt::Horizontal);
        Brightness_Xprogress = new XProgressBar(AloneLight);
        Brightness_Xprogress->setObjectName(QStringLiteral("Brightness_Xprogress"));
        Brightness_Xprogress->setGeometry(QRect(30, 435, 441, 21));
        Color_Slider = new QSlider(AloneLight);
        Color_Slider->setObjectName(QStringLiteral("Color_Slider"));
        Color_Slider->setGeometry(QRect(30, 630, 351, 21));
        Color_Slider->setOrientation(Qt::Horizontal);
        Color_Xprogress = new XProgressBar(AloneLight);
        Color_Xprogress->setObjectName(QStringLiteral("Color_Xprogress"));
        Color_Xprogress->setGeometry(QRect(30, 560, 441, 21));
        InsidesBrightness = new QLabel(AloneLight);
        InsidesBrightness->setObjectName(QStringLiteral("InsidesBrightness"));
        InsidesBrightness->setGeometry(QRect(60, 70, 371, 241));
        QFont font3;
        font3.setFamily(QStringLiteral("PibotoLt"));
        font3.setPointSize(150);
        font3.setBold(true);
        font3.setWeight(75);
        InsidesBrightness->setFont(font3);
        InsidesBrightness->setStyleSheet(QLatin1String("background-color:white;\n"
"border-radius:15px;"));
        InsidesBrightness->setAlignment(Qt::AlignCenter);
        label_4 = new QLabel(AloneLight);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(200, 340, 161, 31));
        QFont font4;
        font4.setFamily(QString::fromUtf8("Adobe \351\273\221\344\275\223 Std R"));
        font4.setPointSize(20);
        font4.setBold(true);
        font4.setWeight(75);
        label_4->setFont(font4);
        label_4->setStyleSheet(QStringLiteral("color:#282A49"));
        label_4->setScaledContents(false);
        label_4->setAlignment(Qt::AlignCenter);
        label_4->setWordWrap(true);
        Device_Slider = new QSlider(AloneLight);
        Device_Slider->setObjectName(QStringLiteral("Device_Slider"));
        Device_Slider->setGeometry(QRect(30, 720, 441, 20));
        Device_Slider->setMinimum(1);
        Device_Slider->setMaximum(6);
        Device_Slider->setOrientation(Qt::Horizontal);
        label_5 = new QLabel(AloneLight);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(200, 680, 111, 21));
        label_5->setFont(font);
        label_5->setStyleSheet(QStringLiteral("color:#282A49"));
        label_5->setScaledContents(false);
        label_5->setAlignment(Qt::AlignCenter);
        label_5->setWordWrap(true);
        label_7 = new QLabel(AloneLight);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(190, 460, 91, 29));
        label_7->setFont(font);
        label_7->setStyleSheet(QStringLiteral("color:#282A49"));
        label_7->setScaledContents(false);
        label_7->setAlignment(Qt::AlignCenter);
        label_7->setWordWrap(true);
        Brightness_Text = new QLabel(AloneLight);
        Brightness_Text->setObjectName(QStringLiteral("Brightness_Text"));
        Brightness_Text->setGeometry(QRect(270, 460, 31, 29));
        Brightness_Text->setFont(font);
        Brightness_Text->setStyleSheet(QStringLiteral("color:#282A49"));
        Brightness_Text->setScaledContents(false);
        Brightness_Text->setAlignment(Qt::AlignCenter);
        Brightness_Text->setWordWrap(true);
        Lux_All = new SwitchButton(AloneLight);
        Lux_All->setObjectName(QStringLiteral("Lux_All"));
        Lux_All->setGeometry(QRect(390, 500, 81, 31));
        Color_All = new SwitchButton(AloneLight);
        Color_All->setObjectName(QStringLiteral("Color_All"));
        Color_All->setGeometry(QRect(390, 620, 81, 31));
        BrightnessP = new QLabel(AloneLight);
        BrightnessP->setObjectName(QStringLiteral("BrightnessP"));
        BrightnessP->setGeometry(QRect(120, 320, 81, 71));
        BrightnessP->setAlignment(Qt::AlignCenter);
        label_6 = new QLabel(AloneLight);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(150, 670, 41, 41));
        ModeChoice = new QPushButton(AloneLight);
        ModeChoice->setObjectName(QStringLiteral("ModeChoice"));
        ModeChoice->setGeometry(QRect(440, 20, 50, 50));
        ModeChoice->setStyleSheet(QLatin1String("max-width:50px;\n"
" max-height:50px;\n"
" min-width:50px;\n"
" min-height:50px;\n"
"border-radius:25px;\n"
"background-color: white;\n"
" border-style: solid;"));
        label_8 = new QLabel(AloneLight);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(190, 590, 91, 29));
        label_8->setFont(font);
        label_8->setStyleSheet(QStringLiteral("color:#282A49"));
        label_8->setScaledContents(false);
        label_8->setAlignment(Qt::AlignCenter);
        label_8->setWordWrap(true);
        Color_Text = new QLabel(AloneLight);
        Color_Text->setObjectName(QStringLiteral("Color_Text"));
        Color_Text->setGeometry(QRect(270, 590, 31, 29));
        Color_Text->setFont(font);
        Color_Text->setStyleSheet(QStringLiteral("color:#282A49"));
        Color_Text->setScaledContents(false);
        Color_Text->setAlignment(Qt::AlignCenter);
        Color_Text->setWordWrap(true);
        SelectedLed = new QLabel(AloneLight);
        SelectedLed->setObjectName(QStringLiteral("SelectedLed"));
        SelectedLed->setGeometry(QRect(320, 675, 31, 31));
        SelectedLed->setFont(font);
        SelectedLed->setStyleSheet(QStringLiteral("color:#282A49"));
        SelectedLed->setScaledContents(false);
        SelectedLed->setAlignment(Qt::AlignCenter);
        SelectedLed->setWordWrap(true);
        PageBottom->addWidget(AloneLight);

        retranslateUi(LightSystem);

        QMetaObject::connectSlotsByName(LightSystem);
    } // setupUi

    void retranslateUi(QDialog *LightSystem)
    {
        LightSystem->setWindowTitle(QApplication::translate("LightSystem", "Dialog", nullptr));
        label_3->setText(QApplication::translate("LightSystem", "\345\256\244\345\206\205\344\272\256\345\272\246", nullptr));
        BrightnessP2->setText(QApplication::translate("LightSystem", "TextLabel", nullptr));
        CurtainNumber->setText(QApplication::translate("LightSystem", "100", nullptr));
        ButtonBox->setTitle(QString());
        AllLed_Status->setText(QString());
        AiMode->setText(QString());
        BackMain->setText(QApplication::translate("LightSystem", "B", nullptr));
        ModeChoice_2->setText(QApplication::translate("LightSystem", "Mode", nullptr));
        AloneControl->setText(QApplication::translate("LightSystem", "N", nullptr));
        InsidesBrightness->setText(QApplication::translate("LightSystem", "832", nullptr));
        label_4->setText(QApplication::translate("LightSystem", "\345\256\244\345\206\205\344\272\256\345\272\246", nullptr));
        label_5->setText(QApplication::translate("LightSystem", "\345\275\223\345\211\215\347\201\257\345\205\211:", nullptr));
        label_7->setText(QApplication::translate("LightSystem", "\344\272\256\345\272\246\357\274\232", nullptr));
        Brightness_Text->setText(QApplication::translate("LightSystem", "80", nullptr));
        BrightnessP->setText(QApplication::translate("LightSystem", "TextLabel", nullptr));
        label_6->setText(QApplication::translate("LightSystem", "TextLabel", nullptr));
        ModeChoice->setText(QApplication::translate("LightSystem", "Main", nullptr));
        label_8->setText(QApplication::translate("LightSystem", "\350\211\262\346\270\251\357\274\232", nullptr));
        Color_Text->setText(QApplication::translate("LightSystem", "80", nullptr));
        SelectedLed->setText(QApplication::translate("LightSystem", "1", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LightSystem: public Ui_LightSystem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LIGHTSYSTEM_H
