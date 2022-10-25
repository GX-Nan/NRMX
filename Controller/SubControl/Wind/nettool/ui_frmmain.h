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
    QGroupBox *groupBox_4;
    QGroupBox *groupBox_5;
    QPushButton *pushButton;
    QGroupBox *groupBox_6;
    QLabel *label_4;
    QLabel *label_5;

    void setupUi(QWidget *frmMain)
    {
        if (frmMain->objectName().isEmpty())
            frmMain->setObjectName(QString::fromUtf8("frmMain"));
        frmMain->resize(1920, 1080);
        groupBox = new QGroupBox(frmMain);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(140, 70, 631, 691));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(70, 100, 481, 441));
        QFont font;
        font.setFamily(QString::fromUtf8("Adobe \351\273\221\344\275\223 Std R"));
        font.setPointSize(350);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(220, 570, 181, 31));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Adobe \351\273\221\344\275\223 Std R"));
        font1.setPointSize(20);
        label_2->setFont(font1);
        label_2->setAlignment(Qt::AlignCenter);
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(260, 620, 101, 21));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Adobe \351\273\221\344\275\223 Std R"));
        font2.setPointSize(10);
        label_3->setFont(font2);
        label_3->setAlignment(Qt::AlignCenter);
        groupBox_2 = new QGroupBox(frmMain);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(140, 870, 631, 121));
        groupBox_4 = new QGroupBox(frmMain);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setGeometry(QRect(970, 870, 881, 111));
        groupBox_5 = new QGroupBox(frmMain);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        groupBox_5->setGeometry(QRect(970, 650, 881, 111));
        pushButton = new QPushButton(frmMain);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(970, 70, 31, 461));
        groupBox_6 = new QGroupBox(frmMain);
        groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
        groupBox_6->setGeometry(QRect(1050, 70, 801, 461));
        label_4 = new QLabel(frmMain);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(1370, 800, 91, 21));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Adobe \351\273\221\344\275\223 Std R"));
        font3.setPointSize(15);
        label_4->setFont(font3);
        label_4->setAlignment(Qt::AlignCenter);
        label_5 = new QLabel(frmMain);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(1370, 1010, 91, 21));
        label_5->setFont(font3);
        label_5->setAlignment(Qt::AlignCenter);

        retranslateUi(frmMain);

        QMetaObject::connectSlotsByName(frmMain);
    } // setupUi

    void retranslateUi(QWidget *frmMain)
    {
        frmMain->setWindowTitle(QCoreApplication::translate("frmMain", "Form", nullptr));
        groupBox->setTitle(QString());
        label->setText(QCoreApplication::translate("frmMain", "25", nullptr));
        label_2->setText(QCoreApplication::translate("frmMain", "\345\256\244\345\206\205\347\251\272\346\260\224\350\264\250\351\207\217", nullptr));
        label_3->setText(QCoreApplication::translate("frmMain", "AirQuality", nullptr));
        groupBox_2->setTitle(QString());
        groupBox_4->setTitle(QString());
        groupBox_5->setTitle(QString());
        pushButton->setText(QString());
        groupBox_6->setTitle(QString());
        label_4->setText(QCoreApplication::translate("frmMain", "\351\243\216\351\200\237", nullptr));
        label_5->setText(QCoreApplication::translate("frmMain", "\346\250\241\345\274\217\351\200\211\346\213\251", nullptr));
    } // retranslateUi

};

namespace Ui {
    class frmMain: public Ui_frmMain {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRMMAIN_H
