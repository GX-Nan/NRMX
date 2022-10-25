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
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_frmMain
{
public:
    QGroupBox *groupBox;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QGroupBox *groupBox_2;
    QGroupBox *groupBox_3;
    QGroupBox *groupBox_4;
    QGroupBox *groupBox_5;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QSlider *horizontalSlider;
    QLabel *label_4;
    QLabel *label_5;
    QGroupBox *groupBox_6;
    QGroupBox *groupBox_7;
    QGroupBox *groupBox_8;

    void setupUi(QWidget *frmMain)
    {
        if (frmMain->objectName().isEmpty())
            frmMain->setObjectName(QString::fromUtf8("frmMain"));
        frmMain->resize(1920, 1080);
        groupBox = new QGroupBox(frmMain);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(120, 70, 431, 681));
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
        groupBox_2 = new QGroupBox(frmMain);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(130, 830, 681, 161));
        groupBox_3 = new QGroupBox(frmMain);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(640, 70, 171, 171));
        groupBox_4 = new QGroupBox(frmMain);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setGeometry(QRect(640, 320, 171, 171));
        groupBox_5 = new QGroupBox(frmMain);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        groupBox_5->setGeometry(QRect(640, 580, 171, 171));
        pushButton = new QPushButton(frmMain);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(970, 80, 181, 171));
        pushButton_2 = new QPushButton(frmMain);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(1310, 80, 181, 171));
        pushButton_3 = new QPushButton(frmMain);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(1640, 80, 181, 171));
        horizontalSlider = new QSlider(frmMain);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(970, 300, 851, 22));
        horizontalSlider->setOrientation(Qt::Horizontal);
        label_4 = new QLabel(frmMain);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(1250, 350, 161, 41));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Adobe \351\273\221\344\275\223 Std R"));
        font3.setPointSize(15);
        label_4->setFont(font3);
        label_4->setAlignment(Qt::AlignCenter);
        label_5 = new QLabel(frmMain);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(1430, 350, 41, 41));
        label_5->setFont(font3);
        label_5->setAlignment(Qt::AlignCenter);
        groupBox_6 = new QGroupBox(frmMain);
        groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
        groupBox_6->setGeometry(QRect(950, 430, 881, 161));
        groupBox_7 = new QGroupBox(frmMain);
        groupBox_7->setObjectName(QString::fromUtf8("groupBox_7"));
        groupBox_7->setGeometry(QRect(950, 640, 881, 161));
        groupBox_8 = new QGroupBox(frmMain);
        groupBox_8->setObjectName(QString::fromUtf8("groupBox_8"));
        groupBox_8->setGeometry(QRect(950, 870, 881, 161));

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
        groupBox_2->setTitle(QString());
        groupBox_3->setTitle(QCoreApplication::translate("frmMain", "GroupBox", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("frmMain", "GroupBox", nullptr));
        groupBox_5->setTitle(QCoreApplication::translate("frmMain", "GroupBox", nullptr));
        pushButton->setText(QCoreApplication::translate("frmMain", "PushButton", nullptr));
        pushButton_2->setText(QCoreApplication::translate("frmMain", "PushButton", nullptr));
        pushButton_3->setText(QCoreApplication::translate("frmMain", "PushButton", nullptr));
        label_4->setText(QCoreApplication::translate("frmMain", "\345\275\223\345\211\215\346\216\247\345\210\266\347\232\204\347\252\227\345\270\230\357\274\232", nullptr));
        label_5->setText(QCoreApplication::translate("frmMain", "0", nullptr));
        groupBox_6->setTitle(QCoreApplication::translate("frmMain", "GroupBox", nullptr));
        groupBox_7->setTitle(QCoreApplication::translate("frmMain", "GroupBox", nullptr));
        groupBox_8->setTitle(QCoreApplication::translate("frmMain", "GroupBox", nullptr));
    } // retranslateUi

};

namespace Ui {
    class frmMain: public Ui_frmMain {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRMMAIN_H
