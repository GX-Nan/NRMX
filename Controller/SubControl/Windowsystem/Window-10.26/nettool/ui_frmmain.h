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
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include "xprogressbar.h"

QT_BEGIN_NAMESPACE

class Ui_frmMain
{
public:
    QFrame *Bottom;
    QGroupBox *WeatherPage;
    QProgressBar *After_1;
    QProgressBar *After_2;
    QProgressBar *After_3;
    QProgressBar *After_4;
    QProgressBar *After_5;
    QProgressBar *After_6;
    QProgressBar *After_7;
    QProgressBar *After_8;
    QProgressBar *After_9;
    QProgressBar *After_10;
    QProgressBar *After_11;
    QLabel *AfterP_1;
    QLabel *AfterP_2;
    QLabel *AfterP_3;
    QLabel *AfterP_4;
    QLabel *AfterP_5;
    QLabel *AfterP_6;
    QLabel *AfterP_7;
    QLabel *AfterP_8;
    QLabel *AfterP_10;
    QLabel *AfterP_9;
    QLabel *AfterP_11;
    QLabel *AfterTime_1;
    QLabel *AfterTime_2;
    QLabel *AfterTime_3;
    QLabel *AfterTime_4;
    QLabel *AfterTime_5;
    QLabel *AfterTime_6;
    QLabel *AfterTime_11;
    QLabel *AfterTime_10;
    QLabel *AfterTime_7;
    QLabel *AfterTime_9;
    QLabel *AfterTime_8;
    QLabel *AfterTemp_1;
    QLabel *AfterTemp_2;
    QLabel *AfterTemp_3;
    QLabel *AfterTemp_4;
    QLabel *AfterTemp_5;
    QLabel *AfterTemp_6;
    QLabel *AfterTemp_7;
    QLabel *AfterTemp_8;
    QLabel *AfterTemp_9;
    QLabel *AfterTemp_10;
    QLabel *AfterTemp_11;
    QGroupBox *WeatherBox;
    QLabel *CurrentWeatherP;
    QLabel *label_47;
    QFrame *WindowPage;
    QFrame *AllWindow_Page;
    QPushButton *AllWindow_Stop;
    QPushButton *AllWindow_Close;
    QPushButton *AllWindow_Open;
    QFrame *SuitableBox;
    QLabel *Suitable1;
    QLabel *SuitableHome;
    QLabel *label_29;
    QLabel *SuitableSport;
    QLabel *Suitable2;
    QLabel *label_31;
    QLabel *Suitable3;
    QLabel *SuitableClothes;
    QLabel *label_36;
    QPushButton *WindowBox;
    QGroupBox *OutAirQuality;
    QLabel *label;
    QLabel *AirQualityLevel;
    QLabel *label_3;
    QLabel *TipsLabel;
    QGroupBox *UltravioletBox;
    XProgressBar *So2_Xprogress;
    QLabel *label_15;
    QLabel *label_44;
    XProgressBar *PM25_Xprogress;
    QLabel *label_45;
    XProgressBar *PM10_Xprogress;
    XProgressBar *No2_Xprogress;
    QLabel *label_46;
    QFrame *CurtainsPage;
    QFrame *AllCurtains_Page;
    QPushButton *AllCurtains_Up;
    QPushButton *AllCurtains_Stop;
    QPushButton *AllCurtains_Down;
    QPushButton *CurtainsBox;
    QGroupBox *TempAndHumi;
    QLabel *TempP;
    QLabel *HumP;
    QLabel *TempLabel;
    QLabel *label_9;
    QLabel *HumLabel;
    QLabel *label_11;

    void setupUi(QWidget *frmMain)
    {
        if (frmMain->objectName().isEmpty())
            frmMain->setObjectName(QStringLiteral("frmMain"));
        frmMain->resize(1920, 1080);
        frmMain->setStyleSheet(QStringLiteral(""));
        Bottom = new QFrame(frmMain);
        Bottom->setObjectName(QStringLiteral("Bottom"));
        Bottom->setGeometry(QRect(-10, 0, 1931, 1081));
        Bottom->setStyleSheet(QStringLiteral("background-color:white;"));
        Bottom->setFrameShape(QFrame::StyledPanel);
        Bottom->setFrameShadow(QFrame::Raised);
        WeatherPage = new QGroupBox(Bottom);
        WeatherPage->setObjectName(QStringLiteral("WeatherPage"));
        WeatherPage->setGeometry(QRect(960, 270, 901, 321));
        WeatherPage->setStyleSheet(QLatin1String("QGroupBox#WeatherPage{\n"
"border-radius:8px;\n"
"}\n"
""));
        After_1 = new QProgressBar(WeatherPage);
        After_1->setObjectName(QStringLiteral("After_1"));
        After_1->setGeometry(QRect(35, 20, 16, 155));
        After_1->setStyleSheet(QLatin1String("QProgressBar:vertical{\n"
"background-color:#ffffff;\n"
"text-align:center;\n"
"}\n"
"QProgressBar::chunk:vertical{\n"
"background-color:#407AFF;\n"
"margin:1px;\n"
"border-radius:5px;\n"
"}\n"
"QProgressBar{\n"
"border:none;\n"
"}"));
        After_1->setValue(24);
        After_2 = new QProgressBar(WeatherPage);
        After_2->setObjectName(QStringLiteral("After_2"));
        After_2->setGeometry(QRect(120, 20, 16, 155));
        After_2->setStyleSheet(QLatin1String("QProgressBar:vertical{\n"
"background-color:#ffffff;\n"
"text-align:center;\n"
"}\n"
"QProgressBar::chunk:vertical{\n"
"background-color:#407AFF;\n"
"margin:1px;\n"
"border-radius:5px;\n"
"}\n"
"QProgressBar{\n"
"border:none;\n"
"}"));
        After_2->setValue(24);
        After_3 = new QProgressBar(WeatherPage);
        After_3->setObjectName(QStringLiteral("After_3"));
        After_3->setGeometry(QRect(205, 20, 16, 155));
        After_3->setStyleSheet(QLatin1String("QProgressBar:vertical{\n"
"background-color:#ffffff;\n"
"text-align:center;\n"
"}\n"
"QProgressBar::chunk:vertical{\n"
"background-color:#407AFF;\n"
"margin:1px;\n"
"border-radius:5px;\n"
"}\n"
"QProgressBar{\n"
"border:none;\n"
"}"));
        After_3->setValue(24);
        After_4 = new QProgressBar(WeatherPage);
        After_4->setObjectName(QStringLiteral("After_4"));
        After_4->setGeometry(QRect(290, 20, 16, 155));
        After_4->setStyleSheet(QLatin1String("QProgressBar:vertical{\n"
"background-color:#ffffff;\n"
"text-align:center;\n"
"}\n"
"QProgressBar::chunk:vertical{\n"
"background-color:#407AFF;\n"
"margin:1px;\n"
"border-radius:5px;\n"
"}\n"
"QProgressBar{\n"
"border:none;\n"
"}"));
        After_4->setValue(24);
        After_5 = new QProgressBar(WeatherPage);
        After_5->setObjectName(QStringLiteral("After_5"));
        After_5->setGeometry(QRect(370, 20, 16, 155));
        After_5->setStyleSheet(QLatin1String("QProgressBar:vertical{\n"
"background-color:#ffffff;\n"
"text-align:center;\n"
"}\n"
"QProgressBar::chunk:vertical{\n"
"background-color:#407AFF;\n"
"margin:1px;\n"
"border-radius:5px;\n"
"}\n"
"QProgressBar{\n"
"border:none;\n"
"}"));
        After_5->setValue(24);
        After_6 = new QProgressBar(WeatherPage);
        After_6->setObjectName(QStringLiteral("After_6"));
        After_6->setGeometry(QRect(450, 20, 16, 155));
        After_6->setStyleSheet(QLatin1String("QProgressBar:vertical{\n"
"background-color:#ffffff;\n"
"text-align:center;\n"
"}\n"
"QProgressBar::chunk:vertical{\n"
"background-color:#407AFF;\n"
"margin:1px;\n"
"border-radius:5px;\n"
"}\n"
"QProgressBar{\n"
"border:none;\n"
"}"));
        After_6->setValue(24);
        After_7 = new QProgressBar(WeatherPage);
        After_7->setObjectName(QStringLiteral("After_7"));
        After_7->setGeometry(QRect(525, 20, 16, 155));
        After_7->setStyleSheet(QLatin1String("QProgressBar:vertical{\n"
"background-color:#ffffff;\n"
"text-align:center;\n"
"}\n"
"QProgressBar::chunk:vertical{\n"
"background-color:#407AFF;\n"
"margin:1px;\n"
"border-radius:5px;\n"
"}\n"
"QProgressBar{\n"
"border:none;\n"
"}"));
        After_7->setValue(24);
        After_8 = new QProgressBar(WeatherPage);
        After_8->setObjectName(QStringLiteral("After_8"));
        After_8->setGeometry(QRect(610, 20, 16, 155));
        After_8->setStyleSheet(QLatin1String("QProgressBar:vertical{\n"
"background-color:#ffffff;\n"
"text-align:center;\n"
"}\n"
"QProgressBar::chunk:vertical{\n"
"background-color:#407AFF;\n"
"margin:1px;\n"
"border-radius:5px;\n"
"}\n"
"QProgressBar{\n"
"border:none;\n"
"}"));
        After_8->setValue(24);
        After_9 = new QProgressBar(WeatherPage);
        After_9->setObjectName(QStringLiteral("After_9"));
        After_9->setGeometry(QRect(690, 20, 16, 155));
        After_9->setStyleSheet(QLatin1String("QProgressBar:vertical{\n"
"background-color:#ffffff;\n"
"text-align:center;\n"
"}\n"
"QProgressBar::chunk:vertical{\n"
"background-color:#407AFF;\n"
"margin:1px;\n"
"border-radius:5px;\n"
"}\n"
"QProgressBar{\n"
"border:none;\n"
"}"));
        After_9->setValue(24);
        After_10 = new QProgressBar(WeatherPage);
        After_10->setObjectName(QStringLiteral("After_10"));
        After_10->setGeometry(QRect(770, 20, 16, 155));
        After_10->setStyleSheet(QLatin1String("QProgressBar:vertical{\n"
"background-color:#ffffff;\n"
"text-align:center;\n"
"}\n"
"QProgressBar::chunk:vertical{\n"
"background-color:#407AFF;\n"
"margin:1px;\n"
"border-radius:5px;\n"
"}\n"
"QProgressBar{\n"
"border:none;\n"
"}"));
        After_10->setValue(24);
        After_11 = new QProgressBar(WeatherPage);
        After_11->setObjectName(QStringLiteral("After_11"));
        After_11->setGeometry(QRect(845, 20, 16, 155));
        After_11->setStyleSheet(QLatin1String("QProgressBar:vertical{\n"
"background-color:#ffffff;\n"
"text-align:center;\n"
"}\n"
"QProgressBar::chunk:vertical{\n"
"background-color:#407AFF;\n"
"margin:1px;\n"
"border-radius:5px;\n"
"}\n"
"QProgressBar{\n"
"border:none;\n"
"}"));
        After_11->setValue(24);
        AfterP_1 = new QLabel(WeatherPage);
        AfterP_1->setObjectName(QStringLiteral("AfterP_1"));
        AfterP_1->setGeometry(QRect(23, 230, 41, 41));
        AfterP_2 = new QLabel(WeatherPage);
        AfterP_2->setObjectName(QStringLiteral("AfterP_2"));
        AfterP_2->setGeometry(QRect(105, 230, 41, 41));
        AfterP_3 = new QLabel(WeatherPage);
        AfterP_3->setObjectName(QStringLiteral("AfterP_3"));
        AfterP_3->setGeometry(QRect(190, 230, 41, 41));
        AfterP_4 = new QLabel(WeatherPage);
        AfterP_4->setObjectName(QStringLiteral("AfterP_4"));
        AfterP_4->setGeometry(QRect(275, 230, 41, 41));
        AfterP_5 = new QLabel(WeatherPage);
        AfterP_5->setObjectName(QStringLiteral("AfterP_5"));
        AfterP_5->setGeometry(QRect(355, 230, 41, 41));
        AfterP_6 = new QLabel(WeatherPage);
        AfterP_6->setObjectName(QStringLiteral("AfterP_6"));
        AfterP_6->setGeometry(QRect(435, 230, 41, 41));
        AfterP_7 = new QLabel(WeatherPage);
        AfterP_7->setObjectName(QStringLiteral("AfterP_7"));
        AfterP_7->setGeometry(QRect(515, 230, 41, 41));
        AfterP_8 = new QLabel(WeatherPage);
        AfterP_8->setObjectName(QStringLiteral("AfterP_8"));
        AfterP_8->setGeometry(QRect(595, 230, 41, 41));
        AfterP_10 = new QLabel(WeatherPage);
        AfterP_10->setObjectName(QStringLiteral("AfterP_10"));
        AfterP_10->setGeometry(QRect(760, 230, 41, 41));
        AfterP_9 = new QLabel(WeatherPage);
        AfterP_9->setObjectName(QStringLiteral("AfterP_9"));
        AfterP_9->setGeometry(QRect(675, 230, 41, 41));
        AfterP_11 = new QLabel(WeatherPage);
        AfterP_11->setObjectName(QStringLiteral("AfterP_11"));
        AfterP_11->setGeometry(QRect(835, 230, 41, 41));
        AfterTime_1 = new QLabel(WeatherPage);
        AfterTime_1->setObjectName(QStringLiteral("AfterTime_1"));
        AfterTime_1->setGeometry(QRect(10, 280, 70, 21));
        AfterTime_1->setAlignment(Qt::AlignCenter);
        AfterTime_2 = new QLabel(WeatherPage);
        AfterTime_2->setObjectName(QStringLiteral("AfterTime_2"));
        AfterTime_2->setGeometry(QRect(90, 280, 70, 21));
        AfterTime_2->setAlignment(Qt::AlignCenter);
        AfterTime_3 = new QLabel(WeatherPage);
        AfterTime_3->setObjectName(QStringLiteral("AfterTime_3"));
        AfterTime_3->setGeometry(QRect(180, 280, 70, 21));
        AfterTime_3->setAlignment(Qt::AlignCenter);
        AfterTime_4 = new QLabel(WeatherPage);
        AfterTime_4->setObjectName(QStringLiteral("AfterTime_4"));
        AfterTime_4->setGeometry(QRect(260, 280, 70, 21));
        AfterTime_4->setAlignment(Qt::AlignCenter);
        AfterTime_5 = new QLabel(WeatherPage);
        AfterTime_5->setObjectName(QStringLiteral("AfterTime_5"));
        AfterTime_5->setGeometry(QRect(340, 280, 70, 21));
        AfterTime_5->setAlignment(Qt::AlignCenter);
        AfterTime_6 = new QLabel(WeatherPage);
        AfterTime_6->setObjectName(QStringLiteral("AfterTime_6"));
        AfterTime_6->setGeometry(QRect(420, 280, 70, 21));
        AfterTime_6->setAlignment(Qt::AlignCenter);
        AfterTime_11 = new QLabel(WeatherPage);
        AfterTime_11->setObjectName(QStringLiteral("AfterTime_11"));
        AfterTime_11->setGeometry(QRect(820, 280, 70, 21));
        AfterTime_11->setAlignment(Qt::AlignCenter);
        AfterTime_10 = new QLabel(WeatherPage);
        AfterTime_10->setObjectName(QStringLiteral("AfterTime_10"));
        AfterTime_10->setGeometry(QRect(745, 280, 70, 21));
        AfterTime_10->setAlignment(Qt::AlignCenter);
        AfterTime_7 = new QLabel(WeatherPage);
        AfterTime_7->setObjectName(QStringLiteral("AfterTime_7"));
        AfterTime_7->setGeometry(QRect(500, 280, 70, 21));
        AfterTime_7->setAlignment(Qt::AlignCenter);
        AfterTime_9 = new QLabel(WeatherPage);
        AfterTime_9->setObjectName(QStringLiteral("AfterTime_9"));
        AfterTime_9->setGeometry(QRect(660, 280, 70, 21));
        AfterTime_9->setAlignment(Qt::AlignCenter);
        AfterTime_8 = new QLabel(WeatherPage);
        AfterTime_8->setObjectName(QStringLiteral("AfterTime_8"));
        AfterTime_8->setGeometry(QRect(585, 280, 70, 21));
        AfterTime_8->setAlignment(Qt::AlignCenter);
        AfterTemp_1 = new QLabel(WeatherPage);
        AfterTemp_1->setObjectName(QStringLiteral("AfterTemp_1"));
        AfterTemp_1->setGeometry(QRect(25, 200, 41, 16));
        QFont font;
        font.setFamily(QString::fromUtf8("Adobe \351\273\221\344\275\223 Std R"));
        font.setPointSize(12);
        AfterTemp_1->setFont(font);
        AfterTemp_1->setAlignment(Qt::AlignCenter);
        AfterTemp_2 = new QLabel(WeatherPage);
        AfterTemp_2->setObjectName(QStringLiteral("AfterTemp_2"));
        AfterTemp_2->setGeometry(QRect(110, 200, 41, 16));
        AfterTemp_2->setFont(font);
        AfterTemp_2->setAlignment(Qt::AlignCenter);
        AfterTemp_3 = new QLabel(WeatherPage);
        AfterTemp_3->setObjectName(QStringLiteral("AfterTemp_3"));
        AfterTemp_3->setGeometry(QRect(190, 200, 41, 16));
        AfterTemp_3->setFont(font);
        AfterTemp_3->setAlignment(Qt::AlignCenter);
        AfterTemp_4 = new QLabel(WeatherPage);
        AfterTemp_4->setObjectName(QStringLiteral("AfterTemp_4"));
        AfterTemp_4->setGeometry(QRect(280, 200, 41, 16));
        AfterTemp_4->setFont(font);
        AfterTemp_4->setAlignment(Qt::AlignCenter);
        AfterTemp_5 = new QLabel(WeatherPage);
        AfterTemp_5->setObjectName(QStringLiteral("AfterTemp_5"));
        AfterTemp_5->setGeometry(QRect(360, 200, 41, 16));
        AfterTemp_5->setFont(font);
        AfterTemp_5->setAlignment(Qt::AlignCenter);
        AfterTemp_6 = new QLabel(WeatherPage);
        AfterTemp_6->setObjectName(QStringLiteral("AfterTemp_6"));
        AfterTemp_6->setGeometry(QRect(440, 200, 41, 16));
        AfterTemp_6->setFont(font);
        AfterTemp_6->setAlignment(Qt::AlignCenter);
        AfterTemp_7 = new QLabel(WeatherPage);
        AfterTemp_7->setObjectName(QStringLiteral("AfterTemp_7"));
        AfterTemp_7->setGeometry(QRect(515, 200, 41, 16));
        AfterTemp_7->setFont(font);
        AfterTemp_7->setAlignment(Qt::AlignCenter);
        AfterTemp_8 = new QLabel(WeatherPage);
        AfterTemp_8->setObjectName(QStringLiteral("AfterTemp_8"));
        AfterTemp_8->setGeometry(QRect(600, 200, 41, 16));
        AfterTemp_8->setFont(font);
        AfterTemp_8->setAlignment(Qt::AlignCenter);
        AfterTemp_9 = new QLabel(WeatherPage);
        AfterTemp_9->setObjectName(QStringLiteral("AfterTemp_9"));
        AfterTemp_9->setGeometry(QRect(680, 200, 41, 16));
        AfterTemp_9->setFont(font);
        AfterTemp_9->setAlignment(Qt::AlignCenter);
        AfterTemp_10 = new QLabel(WeatherPage);
        AfterTemp_10->setObjectName(QStringLiteral("AfterTemp_10"));
        AfterTemp_10->setGeometry(QRect(760, 200, 41, 16));
        AfterTemp_10->setFont(font);
        AfterTemp_10->setAlignment(Qt::AlignCenter);
        AfterTemp_11 = new QLabel(WeatherPage);
        AfterTemp_11->setObjectName(QStringLiteral("AfterTemp_11"));
        AfterTemp_11->setGeometry(QRect(840, 200, 41, 16));
        AfterTemp_11->setFont(font);
        AfterTemp_11->setAlignment(Qt::AlignCenter);
        WeatherBox = new QGroupBox(Bottom);
        WeatherBox->setObjectName(QStringLiteral("WeatherBox"));
        WeatherBox->setGeometry(QRect(960, 50, 271, 181));
        WeatherBox->setStyleSheet(QStringLiteral("border-radius:8px;"));
        CurrentWeatherP = new QLabel(WeatherBox);
        CurrentWeatherP->setObjectName(QStringLiteral("CurrentWeatherP"));
        CurrentWeatherP->setGeometry(QRect(75, 20, 121, 121));
        CurrentWeatherP->setAlignment(Qt::AlignCenter);
        label_47 = new QLabel(WeatherBox);
        label_47->setObjectName(QStringLiteral("label_47"));
        label_47->setGeometry(QRect(85, 150, 101, 21));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Adobe \351\273\221\344\275\223 Std R"));
        font1.setPointSize(12);
        font1.setBold(true);
        font1.setWeight(75);
        label_47->setFont(font1);
        label_47->setAlignment(Qt::AlignCenter);
        WindowPage = new QFrame(Bottom);
        WindowPage->setObjectName(QStringLiteral("WindowPage"));
        WindowPage->setGeometry(QRect(1100, 640, 761, 181));
        WindowPage->setStyleSheet(QStringLiteral("border-radius:8px;"));
        WindowPage->setFrameShape(QFrame::StyledPanel);
        WindowPage->setFrameShadow(QFrame::Raised);
        AllWindow_Page = new QFrame(WindowPage);
        AllWindow_Page->setObjectName(QStringLiteral("AllWindow_Page"));
        AllWindow_Page->setGeometry(QRect(20, 10, 731, 161));
        AllWindow_Page->setStyleSheet(QStringLiteral("background-color:transparent"));
        AllWindow_Page->setFrameShape(QFrame::StyledPanel);
        AllWindow_Page->setFrameShadow(QFrame::Raised);
        AllWindow_Stop = new QPushButton(AllWindow_Page);
        AllWindow_Stop->setObjectName(QStringLiteral("AllWindow_Stop"));
        AllWindow_Stop->setGeometry(QRect(300, 20, 131, 121));
        AllWindow_Stop->setStyleSheet(QLatin1String("\n"
"border-radius:8px;\n"
"background:#FFFFFF;\n"
"/*border:1px solid black;"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/new/Curtains/Curtains/Stop_OFF.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon.addFile(QStringLiteral(":/new/Curtains/Curtains/Stop_ON.png"), QSize(), QIcon::Normal, QIcon::On);
        AllWindow_Stop->setIcon(icon);
        AllWindow_Stop->setIconSize(QSize(80, 80));
        AllWindow_Stop->setCheckable(true);
        AllWindow_Stop->setAutoExclusive(true);
        AllWindow_Close = new QPushButton(AllWindow_Page);
        AllWindow_Close->setObjectName(QStringLiteral("AllWindow_Close"));
        AllWindow_Close->setGeometry(QRect(540, 20, 131, 121));
        AllWindow_Close->setStyleSheet(QLatin1String("\n"
"border-radius:8px;\n"
"background:#FFFFFF;\n"
"/*border:1px solid black;"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/new/Window/Window/Close.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon1.addFile(QStringLiteral(":/new/Window/Window/Close_White.png"), QSize(), QIcon::Normal, QIcon::On);
        AllWindow_Close->setIcon(icon1);
        AllWindow_Close->setIconSize(QSize(80, 80));
        AllWindow_Close->setCheckable(true);
        AllWindow_Close->setAutoExclusive(true);
        AllWindow_Open = new QPushButton(AllWindow_Page);
        AllWindow_Open->setObjectName(QStringLiteral("AllWindow_Open"));
        AllWindow_Open->setGeometry(QRect(60, 20, 131, 121));
        AllWindow_Open->setStyleSheet(QLatin1String("\n"
"border-radius:8px;\n"
"background:#FFFFFF;\n"
"/*border:1px solid black;"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/new/Window/Window/Open.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon2.addFile(QStringLiteral(":/new/Window/Window/Open_White.png"), QSize(), QIcon::Normal, QIcon::On);
        AllWindow_Open->setIcon(icon2);
        AllWindow_Open->setIconSize(QSize(80, 80));
        AllWindow_Open->setCheckable(true);
        AllWindow_Open->setAutoExclusive(true);
        SuitableBox = new QFrame(Bottom);
        SuitableBox->setObjectName(QStringLiteral("SuitableBox"));
        SuitableBox->setGeometry(QRect(630, 60, 221, 741));
        SuitableBox->setStyleSheet(QStringLiteral("border-radius:8px;"));
        SuitableBox->setFrameShape(QFrame::StyledPanel);
        SuitableBox->setFrameShadow(QFrame::Raised);
        Suitable1 = new QLabel(SuitableBox);
        Suitable1->setObjectName(QStringLiteral("Suitable1"));
        Suitable1->setGeometry(QRect(45, 10, 131, 131));
        Suitable1->setAlignment(Qt::AlignCenter);
        SuitableHome = new QLabel(SuitableBox);
        SuitableHome->setObjectName(QStringLiteral("SuitableHome"));
        SuitableHome->setGeometry(QRect(70, 660, 81, 31));
        SuitableHome->setFont(font1);
        SuitableHome->setAlignment(Qt::AlignCenter);
        label_29 = new QLabel(SuitableBox);
        label_29->setObjectName(QStringLiteral("label_29"));
        label_29->setGeometry(QRect(70, 190, 81, 20));
        label_29->setAlignment(Qt::AlignCenter);
        SuitableSport = new QLabel(SuitableBox);
        SuitableSport->setObjectName(QStringLiteral("SuitableSport"));
        SuitableSport->setGeometry(QRect(50, 410, 121, 31));
        SuitableSport->setFont(font1);
        SuitableSport->setAlignment(Qt::AlignCenter);
        Suitable2 = new QLabel(SuitableBox);
        Suitable2->setObjectName(QStringLiteral("Suitable2"));
        Suitable2->setGeometry(QRect(45, 260, 131, 131));
        Suitable2->setAlignment(Qt::AlignCenter);
        label_31 = new QLabel(SuitableBox);
        label_31->setObjectName(QStringLiteral("label_31"));
        label_31->setGeometry(QRect(70, 440, 81, 20));
        label_31->setAlignment(Qt::AlignCenter);
        Suitable3 = new QLabel(SuitableBox);
        Suitable3->setObjectName(QStringLiteral("Suitable3"));
        Suitable3->setGeometry(QRect(45, 510, 131, 131));
        Suitable3->setAlignment(Qt::AlignCenter);
        SuitableClothes = new QLabel(SuitableBox);
        SuitableClothes->setObjectName(QStringLiteral("SuitableClothes"));
        SuitableClothes->setGeometry(QRect(40, 160, 141, 31));
        SuitableClothes->setFont(font1);
        SuitableClothes->setAlignment(Qt::AlignCenter);
        label_36 = new QLabel(SuitableBox);
        label_36->setObjectName(QStringLiteral("label_36"));
        label_36->setGeometry(QRect(70, 690, 81, 20));
        label_36->setAlignment(Qt::AlignCenter);
        WindowBox = new QPushButton(Bottom);
        WindowBox->setObjectName(QStringLiteral("WindowBox"));
        WindowBox->setGeometry(QRect(960, 640, 61, 181));
        WindowBox->setStyleSheet(QLatin1String("\n"
"border-radius:8px;\n"
"background:#FFFFFF;"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/Window/Mode.png"), QSize(), QIcon::Normal, QIcon::Off);
        WindowBox->setIcon(icon3);
        WindowBox->setIconSize(QSize(40, 40));
        OutAirQuality = new QGroupBox(Bottom);
        OutAirQuality->setObjectName(QStringLiteral("OutAirQuality"));
        OutAirQuality->setGeometry(QRect(120, 60, 431, 741));
        label = new QLabel(OutAirQuality);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(130, 500, 181, 61));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Adobe \351\273\221\344\275\223 Std R"));
        font2.setPointSize(20);
        font2.setBold(true);
        font2.setWeight(75);
        label->setFont(font2);
        label->setAlignment(Qt::AlignCenter);
        AirQualityLevel = new QLabel(OutAirQuality);
        AirQualityLevel->setObjectName(QStringLiteral("AirQualityLevel"));
        AirQualityLevel->setGeometry(QRect(40, 120, 361, 321));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Adobe \351\273\221\344\275\223 Std R"));
        font3.setPointSize(210);
        AirQualityLevel->setFont(font3);
        AirQualityLevel->setAlignment(Qt::AlignCenter);
        label_3 = new QLabel(OutAirQuality);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(170, 580, 101, 41));
        label_3->setFont(font1);
        label_3->setAlignment(Qt::AlignCenter);
        TipsLabel = new QLabel(OutAirQuality);
        TipsLabel->setObjectName(QStringLiteral("TipsLabel"));
        TipsLabel->setGeometry(QRect(5, 640, 421, 51));
        QFont font4;
        font4.setFamily(QString::fromUtf8("Adobe \351\273\221\344\275\223 Std R"));
        font4.setPointSize(15);
        font4.setBold(true);
        font4.setWeight(75);
        TipsLabel->setFont(font4);
        TipsLabel->setAlignment(Qt::AlignCenter);
        UltravioletBox = new QGroupBox(Bottom);
        UltravioletBox->setObjectName(QStringLiteral("UltravioletBox"));
        UltravioletBox->setGeometry(QRect(1280, 50, 581, 181));
        UltravioletBox->setStyleSheet(QStringLiteral("border-radius:8px;"));
        So2_Xprogress = new XProgressBar(UltravioletBox);
        So2_Xprogress->setObjectName(QStringLiteral("So2_Xprogress"));
        So2_Xprogress->setGeometry(QRect(360, 30, 161, 16));
        label_15 = new QLabel(UltravioletBox);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(390, 150, 101, 21));
        label_15->setFont(font1);
        label_15->setAlignment(Qt::AlignCenter);
        label_44 = new QLabel(UltravioletBox);
        label_44->setObjectName(QStringLiteral("label_44"));
        label_44->setGeometry(QRect(390, 60, 101, 21));
        label_44->setFont(font1);
        label_44->setAlignment(Qt::AlignCenter);
        PM25_Xprogress = new XProgressBar(UltravioletBox);
        PM25_Xprogress->setObjectName(QStringLiteral("PM25_Xprogress"));
        PM25_Xprogress->setGeometry(QRect(360, 120, 161, 16));
        label_45 = new QLabel(UltravioletBox);
        label_45->setObjectName(QStringLiteral("label_45"));
        label_45->setGeometry(QRect(120, 60, 101, 21));
        label_45->setFont(font1);
        label_45->setAlignment(Qt::AlignCenter);
        PM10_Xprogress = new XProgressBar(UltravioletBox);
        PM10_Xprogress->setObjectName(QStringLiteral("PM10_Xprogress"));
        PM10_Xprogress->setGeometry(QRect(90, 30, 161, 16));
        No2_Xprogress = new XProgressBar(UltravioletBox);
        No2_Xprogress->setObjectName(QStringLiteral("No2_Xprogress"));
        No2_Xprogress->setGeometry(QRect(90, 120, 161, 16));
        label_46 = new QLabel(UltravioletBox);
        label_46->setObjectName(QStringLiteral("label_46"));
        label_46->setGeometry(QRect(120, 150, 101, 21));
        label_46->setFont(font1);
        label_46->setAlignment(Qt::AlignCenter);
        CurtainsPage = new QFrame(Bottom);
        CurtainsPage->setObjectName(QStringLiteral("CurtainsPage"));
        CurtainsPage->setGeometry(QRect(960, 860, 751, 181));
        CurtainsPage->setStyleSheet(QLatin1String("QFrame#CurtainsPage{\n"
"border-radius:8px;\n"
"/*background-color:transparent;*/\n"
"}"));
        CurtainsPage->setFrameShape(QFrame::StyledPanel);
        CurtainsPage->setFrameShadow(QFrame::Raised);
        AllCurtains_Page = new QFrame(CurtainsPage);
        AllCurtains_Page->setObjectName(QStringLiteral("AllCurtains_Page"));
        AllCurtains_Page->setGeometry(QRect(20, 10, 721, 161));
        AllCurtains_Page->setStyleSheet(QLatin1String("background-color:transparent;\n"
"border:none"));
        AllCurtains_Page->setFrameShape(QFrame::StyledPanel);
        AllCurtains_Page->setFrameShadow(QFrame::Raised);
        AllCurtains_Up = new QPushButton(AllCurtains_Page);
        AllCurtains_Up->setObjectName(QStringLiteral("AllCurtains_Up"));
        AllCurtains_Up->setGeometry(QRect(40, 20, 131, 121));
        AllCurtains_Up->setStyleSheet(QLatin1String("\n"
"border-radius:8px;\n"
"background:#FFFFFF;\n"
"/*border:1px solid black;"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/new/Curtains/Curtains/Up_OFF.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon4.addFile(QStringLiteral(":/new/Curtains/Curtains/Up_ON.png"), QSize(), QIcon::Normal, QIcon::On);
        AllCurtains_Up->setIcon(icon4);
        AllCurtains_Up->setIconSize(QSize(80, 80));
        AllCurtains_Up->setCheckable(true);
        AllCurtains_Up->setAutoExclusive(true);
        AllCurtains_Stop = new QPushButton(AllCurtains_Page);
        AllCurtains_Stop->setObjectName(QStringLiteral("AllCurtains_Stop"));
        AllCurtains_Stop->setGeometry(QRect(300, 20, 131, 121));
        AllCurtains_Stop->setStyleSheet(QLatin1String("\n"
"border-radius:8px;\n"
"background:#FFFFFF;\n"
"/*border:1px solid black;"));
        AllCurtains_Stop->setIcon(icon);
        AllCurtains_Stop->setIconSize(QSize(80, 80));
        AllCurtains_Stop->setCheckable(true);
        AllCurtains_Stop->setAutoExclusive(true);
        AllCurtains_Down = new QPushButton(AllCurtains_Page);
        AllCurtains_Down->setObjectName(QStringLiteral("AllCurtains_Down"));
        AllCurtains_Down->setGeometry(QRect(550, 20, 131, 121));
        AllCurtains_Down->setStyleSheet(QLatin1String("\n"
"border-radius:8px;\n"
"background:#FFFFFF;\n"
"/*border:1px solid black;"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/new/Curtains/Curtains/Down_OFF.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon5.addFile(QStringLiteral(":/new/Curtains/Curtains/Down_ON.png"), QSize(), QIcon::Normal, QIcon::On);
        AllCurtains_Down->setIcon(icon5);
        AllCurtains_Down->setIconSize(QSize(80, 80));
        AllCurtains_Down->setCheckable(true);
        AllCurtains_Down->setAutoExclusive(true);
        CurtainsBox = new QPushButton(Bottom);
        CurtainsBox->setObjectName(QStringLiteral("CurtainsBox"));
        CurtainsBox->setGeometry(QRect(1790, 860, 61, 181));
        CurtainsBox->setStyleSheet(QLatin1String("\n"
"border-radius:8px;\n"
"background:#FFFFFF;"));
        CurtainsBox->setIcon(icon3);
        CurtainsBox->setIconSize(QSize(40, 40));
        TempAndHumi = new QGroupBox(Bottom);
        TempAndHumi->setObjectName(QStringLiteral("TempAndHumi"));
        TempAndHumi->setGeometry(QRect(120, 870, 731, 161));
        TempAndHumi->setStyleSheet(QLatin1String("QGroupBox#TempAndHumi{\n"
"border-radius:8px;\n"
"background:#FFFFFF;\n"
"}"));
        TempP = new QLabel(TempAndHumi);
        TempP->setObjectName(QStringLiteral("TempP"));
        TempP->setGeometry(QRect(40, 30, 101, 101));
        TempP->setAlignment(Qt::AlignCenter);
        HumP = new QLabel(TempAndHumi);
        HumP->setObjectName(QStringLiteral("HumP"));
        HumP->setGeometry(QRect(400, 30, 101, 101));
        HumP->setAlignment(Qt::AlignCenter);
        TempLabel = new QLabel(TempAndHumi);
        TempLabel->setObjectName(QStringLiteral("TempLabel"));
        TempLabel->setGeometry(QRect(160, 50, 161, 61));
        QFont font5;
        font5.setFamily(QString::fromUtf8("Adobe \351\273\221\344\275\223 Std R"));
        font5.setPointSize(25);
        font5.setBold(true);
        font5.setWeight(75);
        TempLabel->setFont(font5);
        TempLabel->setAlignment(Qt::AlignCenter);
        label_9 = new QLabel(TempAndHumi);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(190, 100, 81, 31));
        QFont font6;
        font6.setFamily(QString::fromUtf8("Adobe \351\273\221\344\275\223 Std R"));
        font6.setPointSize(10);
        font6.setBold(true);
        font6.setWeight(75);
        label_9->setFont(font6);
        label_9->setAlignment(Qt::AlignCenter);
        HumLabel = new QLabel(TempAndHumi);
        HumLabel->setObjectName(QStringLiteral("HumLabel"));
        HumLabel->setGeometry(QRect(510, 50, 161, 61));
        HumLabel->setFont(font5);
        HumLabel->setAlignment(Qt::AlignCenter);
        label_11 = new QLabel(TempAndHumi);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(550, 100, 81, 31));
        label_11->setFont(font6);
        label_11->setAlignment(Qt::AlignCenter);

        retranslateUi(frmMain);

        QMetaObject::connectSlotsByName(frmMain);
    } // setupUi

    void retranslateUi(QWidget *frmMain)
    {
        frmMain->setWindowTitle(QApplication::translate("frmMain", "Form", nullptr));
        WeatherPage->setTitle(QString());
        AfterP_1->setText(QApplication::translate("frmMain", "TextLabel", nullptr));
        AfterP_2->setText(QApplication::translate("frmMain", "TextLabel", nullptr));
        AfterP_3->setText(QApplication::translate("frmMain", "TextLabel", nullptr));
        AfterP_4->setText(QApplication::translate("frmMain", "TextLabel", nullptr));
        AfterP_5->setText(QApplication::translate("frmMain", "TextLabel", nullptr));
        AfterP_6->setText(QApplication::translate("frmMain", "TextLabel", nullptr));
        AfterP_7->setText(QApplication::translate("frmMain", "TextLabel", nullptr));
        AfterP_8->setText(QApplication::translate("frmMain", "TextLabel", nullptr));
        AfterP_10->setText(QApplication::translate("frmMain", "TextLabel", nullptr));
        AfterP_9->setText(QApplication::translate("frmMain", "TextLabel", nullptr));
        AfterP_11->setText(QApplication::translate("frmMain", "TextLabel", nullptr));
        AfterTime_1->setText(QApplication::translate("frmMain", "11am", nullptr));
        AfterTime_2->setText(QApplication::translate("frmMain", "12am", nullptr));
        AfterTime_3->setText(QApplication::translate("frmMain", "1pm", nullptr));
        AfterTime_4->setText(QApplication::translate("frmMain", "3pm", nullptr));
        AfterTime_5->setText(QApplication::translate("frmMain", "5pm", nullptr));
        AfterTime_6->setText(QApplication::translate("frmMain", "7pm", nullptr));
        AfterTime_11->setText(QApplication::translate("frmMain", "7am", nullptr));
        AfterTime_10->setText(QApplication::translate("frmMain", "5am", nullptr));
        AfterTime_7->setText(QApplication::translate("frmMain", "11pm", nullptr));
        AfterTime_9->setText(QApplication::translate("frmMain", "3am", nullptr));
        AfterTime_8->setText(QApplication::translate("frmMain", "1am", nullptr));
        AfterTemp_1->setText(QApplication::translate("frmMain", "24\302\260", nullptr));
        AfterTemp_2->setText(QApplication::translate("frmMain", "24\302\260", nullptr));
        AfterTemp_3->setText(QApplication::translate("frmMain", "24\302\260", nullptr));
        AfterTemp_4->setText(QApplication::translate("frmMain", "24\302\260", nullptr));
        AfterTemp_5->setText(QApplication::translate("frmMain", "24\302\260", nullptr));
        AfterTemp_6->setText(QApplication::translate("frmMain", "24\302\260", nullptr));
        AfterTemp_7->setText(QApplication::translate("frmMain", "24\302\260", nullptr));
        AfterTemp_8->setText(QApplication::translate("frmMain", "24\302\260", nullptr));
        AfterTemp_9->setText(QApplication::translate("frmMain", "24\302\260", nullptr));
        AfterTemp_10->setText(QApplication::translate("frmMain", "24\302\260", nullptr));
        AfterTemp_11->setText(QApplication::translate("frmMain", "24\302\260", nullptr));
        WeatherBox->setTitle(QString());
        CurrentWeatherP->setText(QApplication::translate("frmMain", "\345\244\251\346\260\224", nullptr));
        label_47->setText(QApplication::translate("frmMain", "\346\210\267\345\244\226\345\244\251\346\260\224", nullptr));
        AllWindow_Stop->setText(QString());
        AllWindow_Close->setText(QString());
        AllWindow_Open->setText(QString());
        Suitable1->setText(QApplication::translate("frmMain", "\350\241\243\346\234\215", nullptr));
        SuitableHome->setText(QApplication::translate("frmMain", "\345\261\205\345\256\266", nullptr));
        label_29->setText(QApplication::translate("frmMain", "clothes", nullptr));
        SuitableSport->setText(QApplication::translate("frmMain", "\350\277\220\345\212\250", nullptr));
        Suitable2->setText(QApplication::translate("frmMain", "\345\261\205\345\256\266", nullptr));
        label_31->setText(QApplication::translate("frmMain", "Sport", nullptr));
        Suitable3->setText(QApplication::translate("frmMain", "\350\277\220\345\212\250", nullptr));
        SuitableClothes->setText(QApplication::translate("frmMain", "\346\231\276\350\241\243\346\234\215", nullptr));
        label_36->setText(QApplication::translate("frmMain", "tourism", nullptr));
        WindowBox->setText(QString());
        OutAirQuality->setTitle(QString());
        label->setText(QApplication::translate("frmMain", "\346\210\267\345\244\226\347\251\272\346\260\224\350\264\250\351\207\217", nullptr));
        AirQualityLevel->setText(QApplication::translate("frmMain", "25", nullptr));
        label_3->setText(QApplication::translate("frmMain", "AirQuality", nullptr));
        TipsLabel->setText(QApplication::translate("frmMain", "\346\210\267\345\244\226\347\251\272\346\260\224\350\264\250\351\207\217", nullptr));
        UltravioletBox->setTitle(QString());
        label_15->setText(QApplication::translate("frmMain", "PM2.5", nullptr));
        label_44->setText(QApplication::translate("frmMain", "So2", nullptr));
        label_45->setText(QApplication::translate("frmMain", "PM10", nullptr));
        label_46->setText(QApplication::translate("frmMain", "No2", nullptr));
        AllCurtains_Up->setText(QString());
        AllCurtains_Stop->setText(QString());
        AllCurtains_Down->setText(QString());
        CurtainsBox->setText(QString());
        TempAndHumi->setTitle(QString());
        TempP->setText(QApplication::translate("frmMain", "TempP", nullptr));
        HumP->setText(QApplication::translate("frmMain", "HumiP", nullptr));
        TempLabel->setText(QApplication::translate("frmMain", "25/26\302\260C", nullptr));
        label_9->setText(QApplication::translate("frmMain", "\345\256\244\345\206\205/\345\244\226", nullptr));
        HumLabel->setText(QApplication::translate("frmMain", "25/26%", nullptr));
        label_11->setText(QApplication::translate("frmMain", "\345\256\244\345\206\205/\345\244\226", nullptr));
    } // retranslateUi

};

namespace Ui {
    class frmMain: public Ui_frmMain {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRMMAIN_H
