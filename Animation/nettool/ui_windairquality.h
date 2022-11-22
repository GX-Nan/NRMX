/********************************************************************************
** Form generated from reading UI file 'windairquality.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDAIRQUALITY_H
#define UI_WINDAIRQUALITY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include "xprogressbar.h"

QT_BEGIN_NAMESPACE

class Ui_WindAirQuality
{
public:
    QFrame *bottom;
    QLabel *label_3;
    QLabel *Co2P;
    QLabel *HCHOP;
    QLabel *TVCOP;
    QLabel *PM25P;
    QLabel *PM10P;
    XProgressBar *Co2_Xprogress;
    XProgressBar *HCHO_Xprogress;
    XProgressBar *TVCO_Xprogress;
    XProgressBar *PM25_Xprogress;
    XProgressBar *PM10_Xprogress;
    QLabel *Pm25_Label;
    QLabel *Pm10_Label;
    QLabel *Tvco_Label;
    QLabel *HCHO_Label;
    QLabel *Co2_Label;

    void setupUi(QDialog *WindAirQuality)
    {
        if (WindAirQuality->objectName().isEmpty())
            WindAirQuality->setObjectName(QStringLiteral("WindAirQuality"));
        WindAirQuality->resize(321, 678);
        WindAirQuality->setStyleSheet(QLatin1String("QDialog#WindAirQuality\n"
"{\n"
"	background-color:rgb(178,178,178,255);\n"
"}"));
        bottom = new QFrame(WindAirQuality);
        bottom->setObjectName(QStringLiteral("bottom"));
        bottom->setGeometry(QRect(10, 10, 301, 661));
        QFont font;
        font.setFamily(QStringLiteral("Fixedsys"));
        bottom->setFont(font);
        bottom->setStyleSheet(QLatin1String("QFrame#bottom\n"
"{\n"
"	background-color:#ffffff;\n"
" \n"
"	border:none;\n"
"	border-radius:25px;\n"
"}"));
        bottom->setFrameShape(QFrame::StyledPanel);
        bottom->setFrameShadow(QFrame::Raised);
        label_3 = new QLabel(bottom);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(60, 610, 181, 31));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Adobe \351\273\221\344\275\223 Std R"));
        font1.setPointSize(15);
        font1.setBold(true);
        font1.setWeight(75);
        label_3->setFont(font1);
        label_3->setStyleSheet(QStringLiteral("color:#282A49"));
        label_3->setAlignment(Qt::AlignCenter);
        Co2P = new QLabel(bottom);
        Co2P->setObjectName(QStringLiteral("Co2P"));
        Co2P->setGeometry(QRect(10, 30, 70, 70));
        Co2P->setAlignment(Qt::AlignCenter);
        HCHOP = new QLabel(bottom);
        HCHOP->setObjectName(QStringLiteral("HCHOP"));
        HCHOP->setGeometry(QRect(10, 140, 70, 70));
        HCHOP->setAlignment(Qt::AlignCenter);
        TVCOP = new QLabel(bottom);
        TVCOP->setObjectName(QStringLiteral("TVCOP"));
        TVCOP->setGeometry(QRect(10, 260, 70, 70));
        TVCOP->setAlignment(Qt::AlignCenter);
        PM25P = new QLabel(bottom);
        PM25P->setObjectName(QStringLiteral("PM25P"));
        PM25P->setGeometry(QRect(10, 370, 70, 70));
        PM25P->setAlignment(Qt::AlignCenter);
        PM10P = new QLabel(bottom);
        PM10P->setObjectName(QStringLiteral("PM10P"));
        PM10P->setGeometry(QRect(10, 490, 70, 70));
        PM10P->setAlignment(Qt::AlignCenter);
        Co2_Xprogress = new XProgressBar(bottom);
        Co2_Xprogress->setObjectName(QStringLiteral("Co2_Xprogress"));
        Co2_Xprogress->setGeometry(QRect(85, 50, 201, 21));
        HCHO_Xprogress = new XProgressBar(bottom);
        HCHO_Xprogress->setObjectName(QStringLiteral("HCHO_Xprogress"));
        HCHO_Xprogress->setGeometry(QRect(85, 161, 201, 20));
        TVCO_Xprogress = new XProgressBar(bottom);
        TVCO_Xprogress->setObjectName(QStringLiteral("TVCO_Xprogress"));
        TVCO_Xprogress->setGeometry(QRect(85, 281, 201, 20));
        PM25_Xprogress = new XProgressBar(bottom);
        PM25_Xprogress->setObjectName(QStringLiteral("PM25_Xprogress"));
        PM25_Xprogress->setGeometry(QRect(85, 391, 201, 20));
        PM10_Xprogress = new XProgressBar(bottom);
        PM10_Xprogress->setObjectName(QStringLiteral("PM10_Xprogress"));
        PM10_Xprogress->setGeometry(QRect(85, 511, 201, 20));
        Pm25_Label = new QLabel(bottom);
        Pm25_Label->setObjectName(QStringLiteral("Pm25_Label"));
        Pm25_Label->setGeometry(QRect(140, 430, 91, 31));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Adobe \351\273\221\344\275\223 Std R"));
        font2.setPointSize(12);
        font2.setBold(true);
        font2.setWeight(75);
        Pm25_Label->setFont(font2);
        Pm25_Label->setAlignment(Qt::AlignCenter);
        Pm10_Label = new QLabel(bottom);
        Pm10_Label->setObjectName(QStringLiteral("Pm10_Label"));
        Pm10_Label->setGeometry(QRect(140, 550, 91, 31));
        Pm10_Label->setFont(font2);
        Pm10_Label->setAlignment(Qt::AlignCenter);
        Tvco_Label = new QLabel(bottom);
        Tvco_Label->setObjectName(QStringLiteral("Tvco_Label"));
        Tvco_Label->setGeometry(QRect(140, 310, 101, 31));
        Tvco_Label->setFont(font2);
        Tvco_Label->setAlignment(Qt::AlignCenter);
        HCHO_Label = new QLabel(bottom);
        HCHO_Label->setObjectName(QStringLiteral("HCHO_Label"));
        HCHO_Label->setGeometry(QRect(140, 190, 91, 31));
        HCHO_Label->setFont(font2);
        HCHO_Label->setAlignment(Qt::AlignCenter);
        Co2_Label = new QLabel(bottom);
        Co2_Label->setObjectName(QStringLiteral("Co2_Label"));
        Co2_Label->setGeometry(QRect(140, 80, 91, 31));
        Co2_Label->setFont(font2);
        Co2_Label->setAlignment(Qt::AlignCenter);

        retranslateUi(WindAirQuality);

        QMetaObject::connectSlotsByName(WindAirQuality);
    } // setupUi

    void retranslateUi(QDialog *WindAirQuality)
    {
        WindAirQuality->setWindowTitle(QApplication::translate("WindAirQuality", "Dialog", nullptr));
        label_3->setText(QApplication::translate("WindAirQuality", "\345\256\244\345\206\205\346\234\211\345\256\263\346\260\224\344\275\223\345\220\253\351\207\217", nullptr));
        Co2P->setText(QApplication::translate("WindAirQuality", "TextLabel", nullptr));
        HCHOP->setText(QApplication::translate("WindAirQuality", "TextLabel", nullptr));
        TVCOP->setText(QApplication::translate("WindAirQuality", "TextLabel", nullptr));
        PM25P->setText(QApplication::translate("WindAirQuality", "TextLabel", nullptr));
        PM10P->setText(QApplication::translate("WindAirQuality", "TextLabel", nullptr));
        Pm25_Label->setText(QApplication::translate("WindAirQuality", "0 /mg", nullptr));
        Pm10_Label->setText(QApplication::translate("WindAirQuality", "0 /mg", nullptr));
        Tvco_Label->setText(QApplication::translate("WindAirQuality", "0 /mg", nullptr));
        HCHO_Label->setText(QApplication::translate("WindAirQuality", "0 /mg", nullptr));
        Co2_Label->setText(QApplication::translate("WindAirQuality", "0 /mg", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WindAirQuality: public Ui_WindAirQuality {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDAIRQUALITY_H
