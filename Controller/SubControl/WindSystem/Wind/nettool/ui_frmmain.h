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
#include <QtWidgets/QWidget>
#include "xprogressbar.h"

QT_BEGIN_NAMESPACE

class Ui_frmMain
{
public:
    QGroupBox *MainBox;
    QLabel *AirQualityLabel;
    QLabel *label_2;
    QLabel *label_3;
    XProgressBar *Temp_Xpro;
    QLabel *label_5;
    XProgressBar *Humi_Xpro;
    QLabel *label_28;
    QGroupBox *ModePage;
    QFrame *frame_2;
    QPushButton *Solid;
    QPushButton *Nature;
    QPushButton *Surround;
    QPushButton *Sea;
    QGroupBox *FanPage;
    QFrame *frame;
    QPushButton *Low;
    QPushButton *High;
    QPushButton *Mid;
    QGroupBox *OutDoorAir;
    QLabel *Pm10P;
    QLabel *label_7;
    QLabel *Pm25P;
    QLabel *label_9;
    QLabel *TVCOP;
    QLabel *label_11;
    QLabel *Co2P;
    QLabel *label_13;
    QLabel *HchoP;
    QLabel *label_15;
    XProgressBar *InsidePm10_Xpro;
    XProgressBar *InsidePm25_Xpro;
    XProgressBar *InsideTvco_Xpro;
    XProgressBar *InsideCo2_Xpro;
    XProgressBar *InsideHcho_Xpro;
    QGroupBox *InDoorBox;
    QGroupBox *OutDoorBox;
    QGroupBox *InDoorAir;
    QLabel *OutSideNo2;
    QLabel *label_17;
    QLabel *OutSidePm25;
    QLabel *label_19;
    QLabel *OutSidePm10;
    QLabel *label_21;
    QLabel *OutSideSo2;
    QLabel *label_25;
    XProgressBar *OutSideNo2_Xpro;
    XProgressBar *OutSidePm10_Xpro;
    XProgressBar *OutSideSo2_Xpro;
    XProgressBar *OutSidePm25_Xpro;
    QPushButton *AiMode;
    QLabel *label_4;

    void setupUi(QWidget *frmMain)
    {
        if (frmMain->objectName().isEmpty())
            frmMain->setObjectName(QStringLiteral("frmMain"));
        frmMain->resize(1920, 1080);
        MainBox = new QGroupBox(frmMain);
        MainBox->setObjectName(QStringLiteral("MainBox"));
        MainBox->setGeometry(QRect(140, 60, 631, 751));
        MainBox->setStyleSheet(QLatin1String("background-color:white;\n"
"border:none;\n"
"border-radius:8px;"));
        AirQualityLabel = new QLabel(MainBox);
        AirQualityLabel->setObjectName(QStringLiteral("AirQualityLabel"));
        AirQualityLabel->setGeometry(QRect(70, 70, 481, 441));
        QFont font;
        font.setFamily(QString::fromUtf8("Adobe \351\273\221\344\275\223 Std R"));
        font.setPointSize(300);
        AirQualityLabel->setFont(font);
        AirQualityLabel->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(MainBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(210, 550, 211, 31));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Adobe \351\273\221\344\275\223 Std R"));
        font1.setPointSize(25);
        label_2->setFont(font1);
        label_2->setAlignment(Qt::AlignCenter);
        label_3 = new QLabel(MainBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(260, 610, 101, 21));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Adobe \351\273\221\344\275\223 Std R"));
        font2.setPointSize(13);
        label_3->setFont(font2);
        label_3->setAlignment(Qt::AlignCenter);
        Temp_Xpro = new XProgressBar(MainBox);
        Temp_Xpro->setObjectName(QStringLiteral("Temp_Xpro"));
        Temp_Xpro->setGeometry(QRect(40, 670, 211, 21));
        label_5 = new QLabel(MainBox);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(110, 710, 71, 16));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Adobe \351\273\221\344\275\223 Std R"));
        font3.setPointSize(14);
        font3.setBold(true);
        font3.setWeight(75);
        label_5->setFont(font3);
        label_5->setAlignment(Qt::AlignCenter);
        Humi_Xpro = new XProgressBar(MainBox);
        Humi_Xpro->setObjectName(QStringLiteral("Humi_Xpro"));
        Humi_Xpro->setGeometry(QRect(370, 670, 221, 21));
        label_28 = new QLabel(MainBox);
        label_28->setObjectName(QStringLiteral("label_28"));
        label_28->setGeometry(QRect(450, 710, 71, 16));
        label_28->setFont(font3);
        label_28->setAlignment(Qt::AlignCenter);
        ModePage = new QGroupBox(frmMain);
        ModePage->setObjectName(QStringLiteral("ModePage"));
        ModePage->setGeometry(QRect(940, 840, 911, 171));
        ModePage->setStyleSheet(QLatin1String("QGroupBox#ModePage{\n"
"background-color:white;\n"
"border:none;\n"
"border-radius:8px;\n"
"}"));
        frame_2 = new QFrame(ModePage);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setGeometry(QRect(10, 10, 891, 151));
        frame_2->setStyleSheet(QLatin1String("border:none\n"
""));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        Solid = new QPushButton(frame_2);
        Solid->setObjectName(QStringLiteral("Solid"));
        Solid->setGeometry(QRect(510, 15, 120, 120));
        Solid->setStyleSheet(QLatin1String("max-width:120px;\n"
" max-height:120px;\n"
" min-width:120px;\n"
" min-height:120px;\n"
"border-radius:60px;\n"
"background-color: white;\n"
" border-style: solid;"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/Wind/Solid_OFF.png"), QSize(), QIcon::Normal, QIcon::Off);
        Solid->setIcon(icon);
        Solid->setIconSize(QSize(80, 80));
        Solid->setCheckable(false);
        Solid->setAutoRepeat(false);
        Solid->setAutoExclusive(false);
        Nature = new QPushButton(frame_2);
        Nature->setObjectName(QStringLiteral("Nature"));
        Nature->setGeometry(QRect(80, 15, 120, 120));
        Nature->setStyleSheet(QLatin1String("max-width:120px;\n"
" max-height:120px;\n"
" min-width:120px;\n"
" min-height:120px;\n"
"border-radius:60px;\n"
"background-color: white;\n"
" border-style: solid;"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/Wind/Natural_OFF.png"), QSize(), QIcon::Normal, QIcon::Off);
        Nature->setIcon(icon1);
        Nature->setIconSize(QSize(80, 80));
        Nature->setCheckable(false);
        Nature->setChecked(false);
        Nature->setAutoRepeat(false);
        Nature->setAutoExclusive(false);
        Surround = new QPushButton(frame_2);
        Surround->setObjectName(QStringLiteral("Surround"));
        Surround->setGeometry(QRect(710, 15, 120, 120));
        Surround->setStyleSheet(QLatin1String("max-width:120px;\n"
" max-height:120px;\n"
" min-width:120px;\n"
" min-height:120px;\n"
"border-radius:60px;\n"
"background-color: white;\n"
" border-style: solid;"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/Wind/Surround_OFF.png"), QSize(), QIcon::Normal, QIcon::Off);
        Surround->setIcon(icon2);
        Surround->setIconSize(QSize(80, 80));
        Surround->setCheckable(false);
        Surround->setAutoRepeat(false);
        Surround->setAutoExclusive(false);
        Sea = new QPushButton(frame_2);
        Sea->setObjectName(QStringLiteral("Sea"));
        Sea->setGeometry(QRect(300, 15, 120, 120));
        Sea->setStyleSheet(QLatin1String("max-width:120px;\n"
" max-height:120px;\n"
" min-width:120px;\n"
" min-height:120px;\n"
"border-radius:60px;\n"
"background-color: white;\n"
" border-style: solid;"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/Wind/Sea_OFF.png"), QSize(), QIcon::Normal, QIcon::Off);
        Sea->setIcon(icon3);
        Sea->setIconSize(QSize(80, 80));
        Sea->setCheckable(false);
        Sea->setAutoRepeat(false);
        Sea->setAutoExclusive(false);
        FanPage = new QGroupBox(frmMain);
        FanPage->setObjectName(QStringLiteral("FanPage"));
        FanPage->setGeometry(QRect(940, 600, 911, 171));
        FanPage->setStyleSheet(QLatin1String("QGroupBox#FanPage{\n"
"background-color:white;\n"
"border:none;\n"
"border-radius:8px;\n"
"}"));
        frame = new QFrame(FanPage);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(10, 10, 891, 151));
        frame->setStyleSheet(QLatin1String("background-color:transparent;\n"
"border:none\n"
""));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        Low = new QPushButton(frame);
        Low->setObjectName(QStringLiteral("Low"));
        Low->setGeometry(QRect(180, 15, 120, 120));
        Low->setStyleSheet(QLatin1String("max-width:120px;\n"
" max-height:120px;\n"
" min-width:120px;\n"
" min-height:120px;\n"
"border-radius:60px;\n"
"background-color: white;\n"
" border-style: solid;"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/Wind/Low_OFF.png"), QSize(), QIcon::Normal, QIcon::Off);
        Low->setIcon(icon4);
        Low->setIconSize(QSize(80, 80));
        Low->setCheckable(false);
        Low->setAutoExclusive(false);
        High = new QPushButton(frame);
        High->setObjectName(QStringLiteral("High"));
        High->setGeometry(QRect(610, 15, 120, 120));
        High->setStyleSheet(QLatin1String("max-width:120px;\n"
" max-height:120px;\n"
" min-width:120px;\n"
" min-height:120px;\n"
"border-radius:60px;\n"
"background-color: white;\n"
" border-style: solid;"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/Wind/High_OFF.png"), QSize(), QIcon::Normal, QIcon::Off);
        High->setIcon(icon5);
        High->setIconSize(QSize(80, 80));
        High->setCheckable(false);
        High->setAutoExclusive(false);
        Mid = new QPushButton(frame);
        Mid->setObjectName(QStringLiteral("Mid"));
        Mid->setGeometry(QRect(400, 15, 120, 120));
        Mid->setStyleSheet(QLatin1String("max-width:120px;\n"
" max-height:120px;\n"
" min-width:120px;\n"
" min-height:120px;\n"
"border-radius:60px;\n"
"background-color: white;\n"
" border-style: solid;"));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/Wind/Mid_OFF.png"), QSize(), QIcon::Normal, QIcon::Off);
        Mid->setIcon(icon6);
        Mid->setIconSize(QSize(80, 80));
        Mid->setCheckable(false);
        Mid->setAutoExclusive(false);
        OutDoorAir = new QGroupBox(frmMain);
        OutDoorAir->setObjectName(QStringLiteral("OutDoorAir"));
        OutDoorAir->setGeometry(QRect(1040, 330, 811, 201));
        OutDoorAir->setStyleSheet(QLatin1String("QGroupBox#OutDoorAir{\n"
"background-color:white;\n"
"border:none;\n"
"border-radius:8px;\n"
"}"));
        Pm10P = new QLabel(OutDoorAir);
        Pm10P->setObjectName(QStringLiteral("Pm10P"));
        Pm10P->setGeometry(QRect(60, 30, 91, 91));
        Pm10P->setAlignment(Qt::AlignCenter);
        label_7 = new QLabel(OutDoorAir);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(60, 140, 91, 21));
        QFont font4;
        font4.setFamily(QString::fromUtf8("Adobe \351\273\221\344\275\223 Std R"));
        font4.setPointSize(12);
        font4.setBold(true);
        font4.setWeight(75);
        label_7->setFont(font4);
        label_7->setAlignment(Qt::AlignCenter);
        Pm25P = new QLabel(OutDoorAir);
        Pm25P->setObjectName(QStringLiteral("Pm25P"));
        Pm25P->setGeometry(QRect(210, 30, 91, 91));
        Pm25P->setAlignment(Qt::AlignCenter);
        label_9 = new QLabel(OutDoorAir);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(210, 140, 91, 21));
        label_9->setFont(font4);
        label_9->setAlignment(Qt::AlignCenter);
        TVCOP = new QLabel(OutDoorAir);
        TVCOP->setObjectName(QStringLiteral("TVCOP"));
        TVCOP->setGeometry(QRect(360, 30, 91, 91));
        TVCOP->setAlignment(Qt::AlignCenter);
        label_11 = new QLabel(OutDoorAir);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(360, 140, 91, 21));
        label_11->setFont(font4);
        label_11->setAlignment(Qt::AlignCenter);
        Co2P = new QLabel(OutDoorAir);
        Co2P->setObjectName(QStringLiteral("Co2P"));
        Co2P->setGeometry(QRect(520, 30, 91, 91));
        Co2P->setAlignment(Qt::AlignCenter);
        label_13 = new QLabel(OutDoorAir);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(520, 140, 91, 21));
        label_13->setFont(font4);
        label_13->setAlignment(Qt::AlignCenter);
        HchoP = new QLabel(OutDoorAir);
        HchoP->setObjectName(QStringLiteral("HchoP"));
        HchoP->setGeometry(QRect(670, 30, 91, 91));
        HchoP->setAlignment(Qt::AlignCenter);
        label_15 = new QLabel(OutDoorAir);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(670, 140, 91, 21));
        label_15->setFont(font4);
        label_15->setAlignment(Qt::AlignCenter);
        InsidePm10_Xpro = new XProgressBar(OutDoorAir);
        InsidePm10_Xpro->setObjectName(QStringLiteral("InsidePm10_Xpro"));
        InsidePm10_Xpro->setGeometry(QRect(40, 170, 131, 16));
        InsidePm25_Xpro = new XProgressBar(OutDoorAir);
        InsidePm25_Xpro->setObjectName(QStringLiteral("InsidePm25_Xpro"));
        InsidePm25_Xpro->setGeometry(QRect(190, 170, 131, 16));
        InsideTvco_Xpro = new XProgressBar(OutDoorAir);
        InsideTvco_Xpro->setObjectName(QStringLiteral("InsideTvco_Xpro"));
        InsideTvco_Xpro->setGeometry(QRect(340, 170, 131, 16));
        InsideCo2_Xpro = new XProgressBar(OutDoorAir);
        InsideCo2_Xpro->setObjectName(QStringLiteral("InsideCo2_Xpro"));
        InsideCo2_Xpro->setGeometry(QRect(500, 170, 131, 16));
        InsideHcho_Xpro = new XProgressBar(OutDoorAir);
        InsideHcho_Xpro->setObjectName(QStringLiteral("InsideHcho_Xpro"));
        InsideHcho_Xpro->setGeometry(QRect(650, 170, 131, 16));
        InDoorBox = new QGroupBox(frmMain);
        InDoorBox->setObjectName(QStringLiteral("InDoorBox"));
        InDoorBox->setGeometry(QRect(940, 60, 51, 211));
        InDoorBox->setStyleSheet(QLatin1String("background-color:white;\n"
"border:none;\n"
"border-radius:8px;"));
        OutDoorBox = new QGroupBox(frmMain);
        OutDoorBox->setObjectName(QStringLiteral("OutDoorBox"));
        OutDoorBox->setGeometry(QRect(940, 330, 51, 201));
        OutDoorBox->setStyleSheet(QLatin1String("background-color:white;\n"
"border:none;\n"
"border-radius:8px;"));
        InDoorAir = new QGroupBox(frmMain);
        InDoorAir->setObjectName(QStringLiteral("InDoorAir"));
        InDoorAir->setGeometry(QRect(1040, 60, 811, 211));
        InDoorAir->setStyleSheet(QLatin1String("QGroupBox#InDoorAir{\n"
"background-color:white;\n"
"border:none;\n"
"border-radius:8px;\n"
"}"));
        OutSideNo2 = new QLabel(InDoorAir);
        OutSideNo2->setObjectName(QStringLiteral("OutSideNo2"));
        OutSideNo2->setGeometry(QRect(80, 30, 91, 91));
        OutSideNo2->setAlignment(Qt::AlignCenter);
        label_17 = new QLabel(InDoorAir);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(80, 140, 91, 21));
        label_17->setFont(font4);
        label_17->setAlignment(Qt::AlignCenter);
        OutSidePm25 = new QLabel(InDoorAir);
        OutSidePm25->setObjectName(QStringLiteral("OutSidePm25"));
        OutSidePm25->setGeometry(QRect(270, 30, 91, 91));
        OutSidePm25->setAlignment(Qt::AlignCenter);
        label_19 = new QLabel(InDoorAir);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setGeometry(QRect(270, 140, 91, 21));
        label_19->setFont(font4);
        label_19->setAlignment(Qt::AlignCenter);
        OutSidePm10 = new QLabel(InDoorAir);
        OutSidePm10->setObjectName(QStringLiteral("OutSidePm10"));
        OutSidePm10->setGeometry(QRect(470, 30, 91, 91));
        OutSidePm10->setAlignment(Qt::AlignCenter);
        label_21 = new QLabel(InDoorAir);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setGeometry(QRect(470, 140, 91, 21));
        label_21->setFont(font4);
        label_21->setAlignment(Qt::AlignCenter);
        OutSideSo2 = new QLabel(InDoorAir);
        OutSideSo2->setObjectName(QStringLiteral("OutSideSo2"));
        OutSideSo2->setGeometry(QRect(660, 30, 91, 91));
        OutSideSo2->setAlignment(Qt::AlignCenter);
        label_25 = new QLabel(InDoorAir);
        label_25->setObjectName(QStringLiteral("label_25"));
        label_25->setGeometry(QRect(660, 140, 91, 21));
        label_25->setFont(font4);
        label_25->setAlignment(Qt::AlignCenter);
        OutSideNo2_Xpro = new XProgressBar(InDoorAir);
        OutSideNo2_Xpro->setObjectName(QStringLiteral("OutSideNo2_Xpro"));
        OutSideNo2_Xpro->setGeometry(QRect(60, 180, 131, 16));
        OutSidePm10_Xpro = new XProgressBar(InDoorAir);
        OutSidePm10_Xpro->setObjectName(QStringLiteral("OutSidePm10_Xpro"));
        OutSidePm10_Xpro->setGeometry(QRect(450, 180, 131, 16));
        OutSideSo2_Xpro = new XProgressBar(InDoorAir);
        OutSideSo2_Xpro->setObjectName(QStringLiteral("OutSideSo2_Xpro"));
        OutSideSo2_Xpro->setGeometry(QRect(640, 180, 131, 16));
        OutSidePm25_Xpro = new XProgressBar(InDoorAir);
        OutSidePm25_Xpro->setObjectName(QStringLiteral("OutSidePm25_Xpro"));
        OutSidePm25_Xpro->setGeometry(QRect(260, 180, 131, 16));
        AiMode = new QPushButton(frmMain);
        AiMode->setObjectName(QStringLiteral("AiMode"));
        AiMode->setGeometry(QRect(140, 880, 631, 101));
        AiMode->setStyleSheet(QLatin1String("background-color:white;\n"
"border:none;\n"
"border-radius:15px;"));
        label_4 = new QLabel(frmMain);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(410, 1000, 91, 31));
        QFont font5;
        font5.setFamily(QString::fromUtf8("Adobe \351\273\221\344\275\223 Std R"));
        font5.setPointSize(15);
        font5.setBold(true);
        font5.setWeight(75);
        label_4->setFont(font5);
        label_4->setAlignment(Qt::AlignCenter);

        retranslateUi(frmMain);

        QMetaObject::connectSlotsByName(frmMain);
    } // setupUi

    void retranslateUi(QWidget *frmMain)
    {
        frmMain->setWindowTitle(QApplication::translate("frmMain", "Form", nullptr));
        MainBox->setTitle(QString());
        AirQualityLabel->setText(QApplication::translate("frmMain", "25", nullptr));
        label_2->setText(QApplication::translate("frmMain", "\345\256\244\345\206\205\347\251\272\346\260\224\350\264\250\351\207\217", nullptr));
        label_3->setText(QApplication::translate("frmMain", "AirQuality", nullptr));
        label_5->setText(QApplication::translate("frmMain", "\346\270\251\345\272\246", nullptr));
        label_28->setText(QApplication::translate("frmMain", "\346\271\277\345\272\246", nullptr));
        ModePage->setTitle(QString());
        Solid->setText(QString());
        Nature->setText(QString());
        Surround->setText(QString());
        Sea->setText(QString());
        FanPage->setTitle(QString());
        Low->setText(QString());
        High->setText(QString());
        Mid->setText(QString());
        OutDoorAir->setTitle(QString());
        Pm10P->setText(QApplication::translate("frmMain", "TextLabel", nullptr));
        label_7->setText(QApplication::translate("frmMain", "PM10", nullptr));
        Pm25P->setText(QApplication::translate("frmMain", "TextLabel", nullptr));
        label_9->setText(QApplication::translate("frmMain", "PM2.5", nullptr));
        TVCOP->setText(QApplication::translate("frmMain", "TextLabel", nullptr));
        label_11->setText(QApplication::translate("frmMain", "TVCO", nullptr));
        Co2P->setText(QApplication::translate("frmMain", "TextLabel", nullptr));
        label_13->setText(QApplication::translate("frmMain", "CO2", nullptr));
        HchoP->setText(QApplication::translate("frmMain", "TextLabel", nullptr));
        label_15->setText(QApplication::translate("frmMain", "\347\224\262\351\206\233", nullptr));
        InDoorBox->setTitle(QString());
        OutDoorBox->setTitle(QString());
        InDoorAir->setTitle(QString());
        OutSideNo2->setText(QApplication::translate("frmMain", "TextLabel", nullptr));
        label_17->setText(QApplication::translate("frmMain", "No2", nullptr));
        OutSidePm25->setText(QApplication::translate("frmMain", "TextLabel", nullptr));
        label_19->setText(QApplication::translate("frmMain", "PM2.5", nullptr));
        OutSidePm10->setText(QApplication::translate("frmMain", "TextLabel", nullptr));
        label_21->setText(QApplication::translate("frmMain", "PM10", nullptr));
        OutSideSo2->setText(QApplication::translate("frmMain", "TextLabel", nullptr));
        label_25->setText(QApplication::translate("frmMain", "So2", nullptr));
        AiMode->setText(QString());
        label_4->setText(QApplication::translate("frmMain", "AI\346\250\241\345\274\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class frmMain: public Ui_frmMain {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRMMAIN_H
