/********************************************************************************
** Form generated from reading UI file 'indoortemphumi.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INDOORTEMPHUMI_H
#define UI_INDOORTEMPHUMI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_IndoorTempHumi
{
public:
    QFrame *bottom;
    QLabel *label_7;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;

    void setupUi(QDialog *IndoorTempHumi)
    {
        if (IndoorTempHumi->objectName().isEmpty())
            IndoorTempHumi->setObjectName(QString::fromUtf8("IndoorTempHumi"));
        IndoorTempHumi->resize(378, 728);
        bottom = new QFrame(IndoorTempHumi);
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
        label_7 = new QLabel(bottom);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(110, 600, 101, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("Adobe \351\273\221\344\275\223 Std R"));
        font.setPointSize(15);
        font.setBold(true);
        font.setWeight(75);
        label_7->setFont(font);
        label_7->setStyleSheet(QString::fromUtf8("color:#282A49"));
        label_7->setAlignment(Qt::AlignCenter);
        label = new QLabel(bottom);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(100, 50, 121, 121));
        label_2 = new QLabel(bottom);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(100, 260, 121, 121));
        label_3 = new QLabel(bottom);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(100, 450, 121, 121));

        retranslateUi(IndoorTempHumi);

        QMetaObject::connectSlotsByName(IndoorTempHumi);
    } // setupUi

    void retranslateUi(QDialog *IndoorTempHumi)
    {
        IndoorTempHumi->setWindowTitle(QCoreApplication::translate("IndoorTempHumi", "Dialog", nullptr));
        label_7->setText(QCoreApplication::translate("IndoorTempHumi", "\351\200\202\345\256\234\346\264\273\345\212\250", nullptr));
        label->setText(QCoreApplication::translate("IndoorTempHumi", "TextLabel", nullptr));
        label_2->setText(QCoreApplication::translate("IndoorTempHumi", "TextLabel", nullptr));
        label_3->setText(QCoreApplication::translate("IndoorTempHumi", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class IndoorTempHumi: public Ui_IndoorTempHumi {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INDOORTEMPHUMI_H
