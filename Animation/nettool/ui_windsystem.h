/********************************************************************************
** Form generated from reading UI file 'windsystem.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDSYSTEM_H
#define UI_WINDSYSTEM_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_WindSystem
{
public:
    QFrame *bottom;
    QLabel *label_3;
    QGroupBox *ButtonBox;
    QPushButton *StopMode;
    QPushButton *MidMode;
    QPushButton *HighMode;
    QPushButton *MinMode;
    QLabel *label_4;
    QPushButton *pushButton_2;
    QLabel *Pirture;

    void setupUi(QDialog *WindSystem)
    {
        if (WindSystem->objectName().isEmpty())
            WindSystem->setObjectName(QString::fromUtf8("WindSystem"));
        WindSystem->resize(371, 819);
        WindSystem->setStyleSheet(QString::fromUtf8("QDialog#WindSystem{\n"
"	background-color:rgb(178,178,178,255);\n"
"}"));
        bottom = new QFrame(WindSystem);
        bottom->setObjectName(QString::fromUtf8("bottom"));
        bottom->setGeometry(QRect(10, 10, 351, 801));
        bottom->setStyleSheet(QString::fromUtf8("QFrame#bottom\n"
"{\n"
"	background-color:#ffffff;\n"
" \n"
"	border:none;\n"
"	border-radius:25px;\n"
"}"));
        bottom->setFrameShape(QFrame::StyledPanel);
        bottom->setFrameShadow(QFrame::Raised);
        label_3 = new QLabel(bottom);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(125, 270, 101, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("Adobe \351\273\221\344\275\223 Std R"));
        font.setPointSize(15);
        font.setBold(true);
        font.setWeight(75);
        label_3->setFont(font);
        label_3->setStyleSheet(QString::fromUtf8("color:#282A49"));
        label_3->setAlignment(Qt::AlignCenter);
        ButtonBox = new QGroupBox(bottom);
        ButtonBox->setObjectName(QString::fromUtf8("ButtonBox"));
        ButtonBox->setGeometry(QRect(65, 330, 231, 461));
        ButtonBox->setStyleSheet(QString::fromUtf8("QGroupBox#ButtonBox{\n"
"border:none;\n"
"}"));
        StopMode = new QPushButton(ButtonBox);
        StopMode->setObjectName(QString::fromUtf8("StopMode"));
        StopMode->setGeometry(QRect(20, 20, 181, 81));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Adobe \351\273\221\344\275\223 Std R"));
        font1.setPointSize(15);
        StopMode->setFont(font1);
        StopMode->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	border-radius:15px;\n"
"	background:#FFFFFF;\n"
"}"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/Curtain/Curtain/Stop_OFF.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon.addFile(QString::fromUtf8(":/new/Curtain/Curtain/Stop_ON.png"), QSize(), QIcon::Normal, QIcon::On);
        StopMode->setIcon(icon);
        StopMode->setIconSize(QSize(100, 50));
        StopMode->setCheckable(true);
        StopMode->setChecked(false);
        StopMode->setAutoExclusive(true);
        MidMode = new QPushButton(ButtonBox);
        MidMode->setObjectName(QString::fromUtf8("MidMode"));
        MidMode->setGeometry(QRect(20, 240, 181, 81));
        MidMode->setFont(font1);
        MidMode->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	border-radius:15px;\n"
"	background:#FFFFFF;\n"
"}"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/new/Wind/Wind/Mid_OFF.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon1.addFile(QString::fromUtf8(":/new/Wind/Wind/Mid_ON.png"), QSize(), QIcon::Normal, QIcon::On);
        icon1.addFile(QString::fromUtf8(":/new/Wind/Wind/Mid_OFF.png"), QSize(), QIcon::Disabled, QIcon::Off);
        MidMode->setIcon(icon1);
        MidMode->setIconSize(QSize(100, 50));
        MidMode->setCheckable(true);
        MidMode->setChecked(false);
        MidMode->setAutoExclusive(true);
        HighMode = new QPushButton(ButtonBox);
        HighMode->setObjectName(QString::fromUtf8("HighMode"));
        HighMode->setGeometry(QRect(20, 350, 181, 81));
        HighMode->setFont(font1);
        HighMode->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	border-radius:15px;\n"
"	background:#FFFFFF;\n"
"}"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/new/Wind/Wind/High_OFF.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon2.addFile(QString::fromUtf8(":/new/Wind/Wind/High_ON.png"), QSize(), QIcon::Normal, QIcon::On);
        HighMode->setIcon(icon2);
        HighMode->setIconSize(QSize(100, 50));
        HighMode->setCheckable(true);
        HighMode->setChecked(false);
        HighMode->setAutoExclusive(true);
        MinMode = new QPushButton(ButtonBox);
        MinMode->setObjectName(QString::fromUtf8("MinMode"));
        MinMode->setGeometry(QRect(20, 130, 181, 81));
        MinMode->setFont(font1);
        MinMode->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	border-radius:15px;\n"
"	background:#FFFFFF;\n"
"}"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/new/Wind/Wind/Low_OFF.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon3.addFile(QString::fromUtf8(":/new/Wind/Wind/Low_ON.png"), QSize(), QIcon::Normal, QIcon::On);
        icon3.addFile(QString::fromUtf8(":/new/Wind/Wind/Mid_OFF.png"), QSize(), QIcon::Disabled, QIcon::Off);
        MinMode->setIcon(icon3);
        MinMode->setIconSize(QSize(100, 50));
        MinMode->setCheckable(true);
        MinMode->setChecked(false);
        MinMode->setAutoExclusive(true);
        label_4 = new QLabel(bottom);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(125, 300, 101, 31));
        label_4->setFont(font);
        label_4->setStyleSheet(QString::fromUtf8("color:#282A49"));
        label_4->setAlignment(Qt::AlignCenter);
        pushButton_2 = new QPushButton(bottom);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(290, 10, 50, 50));
        pushButton_2->setStyleSheet(QString::fromUtf8("max-width:50px;\n"
" max-height:50px;\n"
" min-width:50px;\n"
" min-height:50px;\n"
"border-radius:25px;\n"
"background-color: white;\n"
" border-style: solid;"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/new/Main/Air/Back.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_2->setIcon(icon4);
        pushButton_2->setIconSize(QSize(50, 50));
        Pirture = new QLabel(bottom);
        Pirture->setObjectName(QString::fromUtf8("Pirture"));
        Pirture->setGeometry(QRect(70, 50, 211, 211));
        QFont font2;
        font2.setPointSize(50);
        Pirture->setFont(font2);
        Pirture->setAlignment(Qt::AlignCenter);

        retranslateUi(WindSystem);

        QMetaObject::connectSlotsByName(WindSystem);
    } // setupUi

    void retranslateUi(QDialog *WindSystem)
    {
        WindSystem->setWindowTitle(QCoreApplication::translate("WindSystem", "Dialog", nullptr));
        label_3->setText(QCoreApplication::translate("WindSystem", "\346\226\260\351\243\216\345\274\272\345\272\246", nullptr));
        ButtonBox->setTitle(QString());
        StopMode->setText(QString());
        MidMode->setText(QString());
        HighMode->setText(QString());
        MinMode->setText(QString());
        label_4->setText(QCoreApplication::translate("WindSystem", "\351\200\211\346\213\251", nullptr));
        pushButton_2->setText(QString());
        Pirture->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class WindSystem: public Ui_WindSystem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDSYSTEM_H
