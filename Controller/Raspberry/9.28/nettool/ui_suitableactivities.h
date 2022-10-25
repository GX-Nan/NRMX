/********************************************************************************
** Form generated from reading UI file 'suitableactivities.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SUITABLEACTIVITIES_H
#define UI_SUITABLEACTIVITIES_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include "xprogressbar.h"

QT_BEGIN_NAMESPACE

class Ui_SuitableActivities
{
public:
    QFrame *bottom;
    QLabel *TempHum;
    QLabel *label_2;
    XProgressBar *AirQualiity;
    QLabel *label_3;
    XProgressBar *OutSidePm25;
    XProgressBar *OutSideCO2;
    XProgressBar *OutSideHum;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_17;

    void setupUi(QDialog *SuitableActivities)
    {
        if (SuitableActivities->objectName().isEmpty())
            SuitableActivities->setObjectName(QString::fromUtf8("SuitableActivities"));
        SuitableActivities->resize(378, 754);
        bottom = new QFrame(SuitableActivities);
        bottom->setObjectName(QString::fromUtf8("bottom"));
        bottom->setGeometry(QRect(30, 10, 321, 661));
        bottom->setStyleSheet(QString::fromUtf8("QFrame#bottom\n"
"{\n"
"	background-color:#ffffff;\n"
" \n"
"	border:none;\n"
"	border-radius:25px;\n"
"}"));
        bottom->setFrameShape(QFrame::StyledPanel);
        bottom->setFrameShadow(QFrame::Raised);
        TempHum = new QLabel(bottom);
        TempHum->setObjectName(QString::fromUtf8("TempHum"));
        TempHum->setGeometry(QRect(0, 50, 321, 141));
        QFont font;
        font.setFamily(QString::fromUtf8("Adobe \351\273\221\344\275\223 Std R"));
        font.setPointSize(75);
        TempHum->setFont(font);
        TempHum->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(bottom);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(110, 200, 101, 31));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Adobe \351\273\221\344\275\223 Std R"));
        font1.setPointSize(15);
        font1.setBold(false);
        font1.setWeight(50);
        label_2->setFont(font1);
        AirQualiity = new XProgressBar(bottom);
        AirQualiity->setObjectName(QString::fromUtf8("AirQualiity"));
        AirQualiity->setGeometry(QRect(20, 310, 291, 21));
        label_3 = new QLabel(bottom);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 260, 101, 31));
        label_3->setFont(font1);
        OutSidePm25 = new XProgressBar(bottom);
        OutSidePm25->setObjectName(QString::fromUtf8("OutSidePm25"));
        OutSidePm25->setGeometry(QRect(100, 390, 201, 21));
        OutSideCO2 = new XProgressBar(bottom);
        OutSideCO2->setObjectName(QString::fromUtf8("OutSideCO2"));
        OutSideCO2->setGeometry(QRect(100, 480, 201, 21));
        OutSideHum = new XProgressBar(bottom);
        OutSideHum->setObjectName(QString::fromUtf8("OutSideHum"));
        OutSideHum->setGeometry(QRect(100, 570, 201, 21));
        label_4 = new QLabel(bottom);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(20, 370, 60, 60));
        label_5 = new QLabel(bottom);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(20, 460, 60, 60));
        label_6 = new QLabel(bottom);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(20, 550, 60, 60));
        label_7 = new QLabel(bottom);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(170, 430, 71, 21));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Adobe \351\273\221\344\275\223 Std R"));
        font2.setPointSize(10);
        font2.setBold(false);
        font2.setWeight(50);
        label_7->setFont(font2);
        label_7->setAlignment(Qt::AlignCenter);
        label_8 = new QLabel(bottom);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(170, 520, 71, 21));
        label_8->setFont(font2);
        label_8->setAlignment(Qt::AlignCenter);
        label_17 = new QLabel(bottom);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setGeometry(QRect(170, 600, 71, 21));
        label_17->setFont(font2);
        label_17->setAlignment(Qt::AlignCenter);

        retranslateUi(SuitableActivities);

        QMetaObject::connectSlotsByName(SuitableActivities);
    } // setupUi

    void retranslateUi(QDialog *SuitableActivities)
    {
        SuitableActivities->setWindowTitle(QCoreApplication::translate("SuitableActivities", "Dialog", nullptr));
        TempHum->setText(QCoreApplication::translate("SuitableActivities", "30/24", nullptr));
        label_2->setText(QCoreApplication::translate("SuitableActivities", "\345\256\244\345\206\205\346\270\251\346\271\277\345\272\246", nullptr));
        label_3->setText(QCoreApplication::translate("SuitableActivities", "AQI-30-\344\274\230", nullptr));
        label_4->setText(QCoreApplication::translate("SuitableActivities", "TextLabel", nullptr));
        label_5->setText(QCoreApplication::translate("SuitableActivities", "TextLabel", nullptr));
        label_6->setText(QCoreApplication::translate("SuitableActivities", "TextLabel", nullptr));
        label_7->setText(QCoreApplication::translate("SuitableActivities", "\346\210\267\345\244\226PM2.5", nullptr));
        label_8->setText(QCoreApplication::translate("SuitableActivities", "\346\210\267\345\244\226CO2", nullptr));
        label_17->setText(QCoreApplication::translate("SuitableActivities", "\346\210\267\345\244\226\346\271\277\345\272\246", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SuitableActivities: public Ui_SuitableActivities {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUITABLEACTIVITIES_H
