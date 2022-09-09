/********************************************************************************
** Form generated from reading UI file 'windowsystem.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOWSYSTEM_H
#define UI_WINDOWSYSTEM_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include "xprogressbar.h"

QT_BEGIN_NAMESPACE

class Ui_WindowSystem
{
public:
    QFrame *bottom;
    QLabel *WeatherStatus;
    QPushButton *BackMain;
    QLabel *CurrentTemp;
    QLabel *LocalArea;
    QLabel *MinTemp;
    QLabel *MaxTemp_;
    XProgressBar *TempRange_Xprogress;
    QGroupBox *ButtonBox;
    QPushButton *WindowClose;
    QPushButton *WindowStop;
    QPushButton *WindowOpen;
    XProgressBar *OutSideCo2_Xprogress;
    XProgressBar *OutsideHumi_XprogressBar;
    XProgressBar *OutSidePM25_Xprogress;
    QLabel *PM25P;
    QLabel *Co2P;
    QLabel *HumiP;
    QLabel *MaxTemp_2;
    QLabel *MaxTemp_3;
    QLabel *MaxTemp_4;
    QLabel *TempHumi;
    QLabel *WeatherStatus_3;
    QLabel *label_5;
    QLabel *label_6;
    QSlider *Device_Qslider;
    QLabel *WeatherStatus_4;
    QLabel *CurrentWindow;
    QLabel *WeatherStatus_6;
    QLabel *WeatherStatus_7;

    void setupUi(QDialog *WindowSystem)
    {
        if (WindowSystem->objectName().isEmpty())
            WindowSystem->setObjectName(QStringLiteral("WindowSystem"));
        WindowSystem->resize(1091, 721);
        WindowSystem->setStyleSheet(QLatin1String("QDialog#WindowSystem\n"
"{\n"
"	background-color:rgb(178,178,178,255);\n"
"}"));
        bottom = new QFrame(WindowSystem);
        bottom->setObjectName(QStringLiteral("bottom"));
        bottom->setGeometry(QRect(10, 10, 1070, 701));
        bottom->setStyleSheet(QLatin1String("QFrame#bottom\n"
"{\n"
"	background-color:#ffffff;\n"
" \n"
"	border:none;\n"
"	border-radius:25px;\n"
"}"));
        bottom->setFrameShape(QFrame::StyledPanel);
        bottom->setFrameShadow(QFrame::Raised);
        WeatherStatus = new QLabel(bottom);
        WeatherStatus->setObjectName(QStringLiteral("WeatherStatus"));
        WeatherStatus->setGeometry(QRect(220, 350, 61, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("Adobe \351\273\221\344\275\223 Std R"));
        font.setPointSize(15);
        font.setBold(true);
        font.setWeight(75);
        WeatherStatus->setFont(font);
        WeatherStatus->setStyleSheet(QStringLiteral("color:#282A49"));
        WeatherStatus->setAlignment(Qt::AlignCenter);
        BackMain = new QPushButton(bottom);
        BackMain->setObjectName(QStringLiteral("BackMain"));
        BackMain->setGeometry(QRect(1010, 20, 50, 50));
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
        CurrentTemp = new QLabel(bottom);
        CurrentTemp->setObjectName(QStringLiteral("CurrentTemp"));
        CurrentTemp->setGeometry(QRect(80, 100, 321, 251));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Adobe \351\273\221\344\275\223 Std R"));
        font1.setPointSize(200);
        CurrentTemp->setFont(font1);
        CurrentTemp->setAlignment(Qt::AlignCenter);
        LocalArea = new QLabel(bottom);
        LocalArea->setObjectName(QStringLiteral("LocalArea"));
        LocalArea->setGeometry(QRect(200, 30, 111, 41));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Adobe \351\273\221\344\275\223 Std R"));
        font2.setPointSize(25);
        font2.setBold(true);
        font2.setWeight(75);
        LocalArea->setFont(font2);
        LocalArea->setStyleSheet(QStringLiteral("color:#282A49"));
        LocalArea->setAlignment(Qt::AlignCenter);
        MinTemp = new QLabel(bottom);
        MinTemp->setObjectName(QStringLiteral("MinTemp"));
        MinTemp->setGeometry(QRect(60, 420, 51, 31));
        MinTemp->setFont(font);
        MinTemp->setStyleSheet(QStringLiteral("color:#282A49"));
        MinTemp->setAlignment(Qt::AlignCenter);
        MaxTemp_ = new QLabel(bottom);
        MaxTemp_->setObjectName(QStringLiteral("MaxTemp_"));
        MaxTemp_->setGeometry(QRect(390, 420, 51, 31));
        MaxTemp_->setFont(font);
        MaxTemp_->setStyleSheet(QStringLiteral("color:#282A49"));
        MaxTemp_->setAlignment(Qt::AlignCenter);
        TempRange_Xprogress = new XProgressBar(bottom);
        TempRange_Xprogress->setObjectName(QStringLiteral("TempRange_Xprogress"));
        TempRange_Xprogress->setGeometry(QRect(60, 390, 371, 21));
        ButtonBox = new QGroupBox(bottom);
        ButtonBox->setObjectName(QStringLiteral("ButtonBox"));
        ButtonBox->setGeometry(QRect(490, 70, 551, 181));
        ButtonBox->setStyleSheet(QLatin1String("QGroupBox#ButtonBox{\n"
"border:none;\n"
"}"));
        WindowClose = new QPushButton(ButtonBox);
        WindowClose->setObjectName(QStringLiteral("WindowClose"));
        WindowClose->setGeometry(QRect(25, 30, 131, 131));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Adobe \351\273\221\344\275\223 Std R"));
        font3.setPointSize(15);
        WindowClose->setFont(font3);
        WindowClose->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	border-radius:15px;\n"
"	background:#FFFFFF;\n"
"}"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/new/Curtain/Curtain/Down_OFF.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon1.addFile(QStringLiteral(":/new/Curtain/Curtain/Down_ON.png"), QSize(), QIcon::Normal, QIcon::On);
        WindowClose->setIcon(icon1);
        WindowClose->setIconSize(QSize(200, 100));
        WindowClose->setCheckable(true);
        WindowClose->setAutoExclusive(true);
        WindowStop = new QPushButton(ButtonBox);
        WindowStop->setObjectName(QStringLiteral("WindowStop"));
        WindowStop->setGeometry(QRect(210, 30, 131, 131));
        WindowStop->setFont(font3);
        WindowStop->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	border-radius:15px;\n"
"	background:#FFFFFF;\n"
"}"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/new/Curtain/Curtain/Stop_OFF.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon2.addFile(QStringLiteral(":/new/Curtain/Curtain/Stop_ON.png"), QSize(), QIcon::Normal, QIcon::On);
        WindowStop->setIcon(icon2);
        WindowStop->setIconSize(QSize(200, 80));
        WindowStop->setCheckable(true);
        WindowStop->setAutoExclusive(true);
        WindowOpen = new QPushButton(ButtonBox);
        WindowOpen->setObjectName(QStringLiteral("WindowOpen"));
        WindowOpen->setGeometry(QRect(390, 30, 131, 131));
        WindowOpen->setFont(font3);
        WindowOpen->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	border-radius:15px;\n"
"	background:#FFFFFF;\n"
"}"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/new/Curtain/Curtain/Up_OFF.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon3.addFile(QStringLiteral(":/new/Curtain/Curtain/Up_ON.png"), QSize(), QIcon::Normal, QIcon::On);
        WindowOpen->setIcon(icon3);
        WindowOpen->setIconSize(QSize(200, 120));
        WindowOpen->setCheckable(true);
        WindowOpen->setAutoExclusive(true);
        OutSideCo2_Xprogress = new XProgressBar(bottom);
        OutSideCo2_Xprogress->setObjectName(QStringLiteral("OutSideCo2_Xprogress"));
        OutSideCo2_Xprogress->setGeometry(QRect(590, 520, 421, 21));
        OutsideHumi_XprogressBar = new XProgressBar(bottom);
        OutsideHumi_XprogressBar->setObjectName(QStringLiteral("OutsideHumi_XprogressBar"));
        OutsideHumi_XprogressBar->setGeometry(QRect(590, 610, 421, 21));
        OutSidePM25_Xprogress = new XProgressBar(bottom);
        OutSidePM25_Xprogress->setObjectName(QStringLiteral("OutSidePM25_Xprogress"));
        OutSidePM25_Xprogress->setGeometry(QRect(590, 420, 421, 21));
        PM25P = new QLabel(bottom);
        PM25P->setObjectName(QStringLiteral("PM25P"));
        PM25P->setGeometry(QRect(500, 390, 81, 81));
        Co2P = new QLabel(bottom);
        Co2P->setObjectName(QStringLiteral("Co2P"));
        Co2P->setGeometry(QRect(500, 490, 81, 81));
        HumiP = new QLabel(bottom);
        HumiP->setObjectName(QStringLiteral("HumiP"));
        HumiP->setGeometry(QRect(500, 590, 81, 81));
        MaxTemp_2 = new QLabel(bottom);
        MaxTemp_2->setObjectName(QStringLiteral("MaxTemp_2"));
        MaxTemp_2->setGeometry(QRect(750, 460, 91, 21));
        QFont font4;
        font4.setFamily(QStringLiteral("PibotoLt"));
        font4.setPointSize(15);
        font4.setBold(true);
        font4.setItalic(false);
        font4.setWeight(75);
        MaxTemp_2->setFont(font4);
        MaxTemp_2->setStyleSheet(QStringLiteral("color:#282A49"));
        MaxTemp_2->setAlignment(Qt::AlignCenter);
        MaxTemp_3 = new QLabel(bottom);
        MaxTemp_3->setObjectName(QStringLiteral("MaxTemp_3"));
        MaxTemp_3->setGeometry(QRect(750, 560, 91, 21));
        MaxTemp_3->setFont(font4);
        MaxTemp_3->setStyleSheet(QStringLiteral("color:#282A49"));
        MaxTemp_3->setAlignment(Qt::AlignCenter);
        MaxTemp_4 = new QLabel(bottom);
        MaxTemp_4->setObjectName(QStringLiteral("MaxTemp_4"));
        MaxTemp_4->setGeometry(QRect(750, 650, 91, 21));
        MaxTemp_4->setFont(font4);
        MaxTemp_4->setStyleSheet(QStringLiteral("color:#282A49"));
        MaxTemp_4->setAlignment(Qt::AlignCenter);
        TempHumi = new QLabel(bottom);
        TempHumi->setObjectName(QStringLiteral("TempHumi"));
        TempHumi->setGeometry(QRect(70, 490, 231, 121));
        QFont font5;
        font5.setFamily(QString::fromUtf8("Adobe \351\273\221\344\275\223 Std R"));
        font5.setPointSize(60);
        TempHumi->setFont(font5);
        TempHumi->setAlignment(Qt::AlignCenter);
        WeatherStatus_3 = new QLabel(bottom);
        WeatherStatus_3->setObjectName(QStringLiteral("WeatherStatus_3"));
        WeatherStatus_3->setGeometry(QRect(120, 620, 121, 31));
        WeatherStatus_3->setFont(font);
        WeatherStatus_3->setStyleSheet(QStringLiteral("color:#282A49"));
        WeatherStatus_3->setAlignment(Qt::AlignCenter);
        label_5 = new QLabel(bottom);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(350, 470, 81, 81));
        label_6 = new QLabel(bottom);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(350, 570, 81, 81));
        Device_Qslider = new QSlider(bottom);
        Device_Qslider->setObjectName(QStringLiteral("Device_Qslider"));
        Device_Qslider->setGeometry(QRect(510, 330, 501, 22));
        Device_Qslider->setMinimum(0);
        Device_Qslider->setMaximum(6);
        Device_Qslider->setOrientation(Qt::Horizontal);
        WeatherStatus_4 = new QLabel(bottom);
        WeatherStatus_4->setObjectName(QStringLiteral("WeatherStatus_4"));
        WeatherStatus_4->setGeometry(QRect(700, 280, 71, 31));
        WeatherStatus_4->setFont(font);
        WeatherStatus_4->setStyleSheet(QStringLiteral("color:#282A49"));
        WeatherStatus_4->setAlignment(Qt::AlignCenter);
        CurrentWindow = new QLabel(bottom);
        CurrentWindow->setObjectName(QStringLiteral("CurrentWindow"));
        CurrentWindow->setGeometry(QRect(760, 280, 41, 31));
        QFont font6;
        font6.setFamily(QString::fromUtf8("Adobe \351\273\221\344\275\223 Std R"));
        font6.setPointSize(15);
        font6.setBold(true);
        font6.setWeight(75);
        font6.setKerning(true);
        CurrentWindow->setFont(font6);
        CurrentWindow->setStyleSheet(QStringLiteral("color:#282A49"));
        CurrentWindow->setAlignment(Qt::AlignCenter);
        WeatherStatus_6 = new QLabel(bottom);
        WeatherStatus_6->setObjectName(QStringLiteral("WeatherStatus_6"));
        WeatherStatus_6->setGeometry(QRect(680, 370, 141, 31));
        WeatherStatus_6->setFont(font);
        WeatherStatus_6->setStyleSheet(QStringLiteral("color:#282A49"));
        WeatherStatus_6->setAlignment(Qt::AlignCenter);
        WeatherStatus_7 = new QLabel(bottom);
        WeatherStatus_7->setObjectName(QStringLiteral("WeatherStatus_7"));
        WeatherStatus_7->setGeometry(QRect(820, 370, 41, 31));
        WeatherStatus_7->setFont(font);
        WeatherStatus_7->setStyleSheet(QStringLiteral("color:#282A49"));
        WeatherStatus_7->setAlignment(Qt::AlignCenter);

        retranslateUi(WindowSystem);

        QMetaObject::connectSlotsByName(WindowSystem);
    } // setupUi

    void retranslateUi(QDialog *WindowSystem)
    {
        WindowSystem->setWindowTitle(QApplication::translate("WindowSystem", "Dialog", nullptr));
        WeatherStatus->setText(QApplication::translate("WindowSystem", "\346\231\264\346\234\227", nullptr));
        BackMain->setText(QString());
        CurrentTemp->setText(QApplication::translate("WindowSystem", "24", nullptr));
        LocalArea->setText(QApplication::translate("WindowSystem", "\347\217\240\346\265\267\345\270\202", nullptr));
        MinTemp->setText(QApplication::translate("WindowSystem", "16\302\260", nullptr));
        MaxTemp_->setText(QApplication::translate("WindowSystem", "24\302\260", nullptr));
        ButtonBox->setTitle(QString());
        WindowClose->setText(QString());
        WindowStop->setText(QString());
        WindowOpen->setText(QString());
        PM25P->setText(QApplication::translate("WindowSystem", "TextLabel", nullptr));
        Co2P->setText(QApplication::translate("WindowSystem", "TextLabel", nullptr));
        HumiP->setText(QApplication::translate("WindowSystem", "TextLabel", nullptr));
        MaxTemp_2->setText(QApplication::translate("WindowSystem", "PM2.5", nullptr));
        MaxTemp_3->setText(QApplication::translate("WindowSystem", "CO2", nullptr));
        MaxTemp_4->setText(QApplication::translate("WindowSystem", "\346\271\277\345\272\246", nullptr));
        TempHumi->setText(QApplication::translate("WindowSystem", "24/30", nullptr));
        WeatherStatus_3->setText(QApplication::translate("WindowSystem", "\345\256\244\345\206\205\346\270\251\346\271\277\345\272\246", nullptr));
        label_5->setText(QApplication::translate("WindowSystem", "TextLabel", nullptr));
        label_6->setText(QApplication::translate("WindowSystem", "TextLabel", nullptr));
        WeatherStatus_4->setText(QApplication::translate("WindowSystem", "\347\252\227\346\210\267\357\274\232", nullptr));
        CurrentWindow->setText(QApplication::translate("WindowSystem", "1", nullptr));
        WeatherStatus_6->setText(QApplication::translate("WindowSystem", "\346\210\267\345\244\226\347\251\272\346\260\224\350\264\250\351\207\217\357\274\232", nullptr));
        WeatherStatus_7->setText(QApplication::translate("WindowSystem", "\344\274\230", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WindowSystem: public Ui_WindowSystem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOWSYSTEM_H
