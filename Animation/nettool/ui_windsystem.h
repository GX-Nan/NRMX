/********************************************************************************
** Form generated from reading UI file 'windsystem.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
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
    QPushButton *MaxMode;
    QPushButton *MinMode;
    QLabel *label_4;
    QPushButton *pushButton_2;
    QLabel *Pirture;
    QPushButton *AutoSwitch;

    void setupUi(QDialog *WindSystem)
    {
        if (WindSystem->objectName().isEmpty())
            WindSystem->setObjectName(QStringLiteral("WindSystem"));
        WindSystem->resize(371, 917);
        WindSystem->setStyleSheet(QLatin1String("QDialog#WindSystem{\n"
"	background-color:rgb(178,178,178,255);\n"
"}"));
        bottom = new QFrame(WindSystem);
        bottom->setObjectName(QStringLiteral("bottom"));
        bottom->setGeometry(QRect(10, 10, 351, 901));
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
        label_3->setGeometry(QRect(125, 270, 101, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("Adobe \351\273\221\344\275\223 Std R"));
        font.setPointSize(15);
        font.setBold(true);
        font.setWeight(75);
        label_3->setFont(font);
        label_3->setStyleSheet(QStringLiteral("color:#282A49"));
        label_3->setAlignment(Qt::AlignCenter);
        ButtonBox = new QGroupBox(bottom);
        ButtonBox->setObjectName(QStringLiteral("ButtonBox"));
        ButtonBox->setGeometry(QRect(65, 330, 231, 441));
        ButtonBox->setStyleSheet(QLatin1String("QGroupBox#ButtonBox{\n"
"border:none;\n"
"}"));
        StopMode = new QPushButton(ButtonBox);
        StopMode->setObjectName(QStringLiteral("StopMode"));
        StopMode->setGeometry(QRect(20, 20, 181, 81));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Adobe \351\273\221\344\275\223 Std R"));
        font1.setPointSize(15);
        StopMode->setFont(font1);
        StopMode->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	border-radius:15px;\n"
"	background:#FFFFFF;\n"
"}"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/new/Curtain/Curtain/Stop_OFF.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon.addFile(QStringLiteral(":/new/Curtain/Curtain/Stop_ON.png"), QSize(), QIcon::Normal, QIcon::On);
        StopMode->setIcon(icon);
        StopMode->setIconSize(QSize(100, 50));
        StopMode->setCheckable(true);
        StopMode->setChecked(false);
        StopMode->setAutoExclusive(true);
        MidMode = new QPushButton(ButtonBox);
        MidMode->setObjectName(QStringLiteral("MidMode"));
        MidMode->setGeometry(QRect(20, 240, 181, 81));
        MidMode->setFont(font1);
        MidMode->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	border-radius:15px;\n"
"	background:#FFFFFF;\n"
"}"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/new/Wind/Wind/Mid_OFF.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon1.addFile(QStringLiteral(":/new/Wind/Wind/Mid_OFF.png"), QSize(), QIcon::Disabled, QIcon::Off);
        MidMode->setIcon(icon1);
        MidMode->setIconSize(QSize(100, 50));
        MidMode->setCheckable(true);
        MidMode->setChecked(false);
        MidMode->setAutoExclusive(true);
        MaxMode = new QPushButton(ButtonBox);
        MaxMode->setObjectName(QStringLiteral("MaxMode"));
        MaxMode->setGeometry(QRect(20, 350, 181, 81));
        MaxMode->setFont(font1);
        MaxMode->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	border-radius:15px;\n"
"	background:#FFFFFF;\n"
"}"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/new/Wind/Wind/High_OFF.png"), QSize(), QIcon::Normal, QIcon::Off);
        MaxMode->setIcon(icon2);
        MaxMode->setIconSize(QSize(100, 50));
        MaxMode->setCheckable(true);
        MaxMode->setChecked(false);
        MaxMode->setAutoExclusive(true);
        MinMode = new QPushButton(ButtonBox);
        MinMode->setObjectName(QStringLiteral("MinMode"));
        MinMode->setGeometry(QRect(20, 130, 181, 81));
        MinMode->setFont(font1);
        MinMode->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	border-radius:15px;\n"
"	background:#FFFFFF;\n"
"}"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/new/Wind/Wind/Low_OFF.png"), QSize(), QIcon::Normal, QIcon::Off);
        MinMode->setIcon(icon3);
        MinMode->setIconSize(QSize(100, 50));
        MinMode->setCheckable(true);
        MinMode->setChecked(false);
        MinMode->setAutoExclusive(true);
        label_4 = new QLabel(bottom);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(125, 300, 101, 31));
        label_4->setFont(font);
        label_4->setStyleSheet(QStringLiteral("color:#282A49"));
        label_4->setAlignment(Qt::AlignCenter);
        pushButton_2 = new QPushButton(bottom);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(290, 10, 50, 50));
        pushButton_2->setStyleSheet(QLatin1String("max-width:50px;\n"
" max-height:50px;\n"
" min-width:50px;\n"
" min-height:50px;\n"
"border-radius:25px;\n"
"background-color: white;\n"
" border-style: solid;"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/new/Main/Air/Back.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_2->setIcon(icon4);
        pushButton_2->setIconSize(QSize(50, 50));
        Pirture = new QLabel(bottom);
        Pirture->setObjectName(QStringLiteral("Pirture"));
        Pirture->setGeometry(QRect(70, 50, 211, 211));
        QFont font2;
        font2.setPointSize(50);
        Pirture->setFont(font2);
        Pirture->setAlignment(Qt::AlignCenter);
        AutoSwitch = new QPushButton(bottom);
        AutoSwitch->setObjectName(QStringLiteral("AutoSwitch"));
        AutoSwitch->setGeometry(QRect(85, 790, 181, 81));
        AutoSwitch->setFont(font1);
        AutoSwitch->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	border-radius:15px;\n"
"	background:#FFFFFF;\n"
"}"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/new/Led/Led/AI_ON.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon5.addFile(QStringLiteral(":/new/Led/Led/AI_OFF.png"), QSize(), QIcon::Normal, QIcon::On);
        AutoSwitch->setIcon(icon5);
        AutoSwitch->setIconSize(QSize(100, 50));
        AutoSwitch->setCheckable(true);
        AutoSwitch->setChecked(false);
        AutoSwitch->setAutoExclusive(true);

        retranslateUi(WindSystem);

        QMetaObject::connectSlotsByName(WindSystem);
    } // setupUi

    void retranslateUi(QDialog *WindSystem)
    {
        WindSystem->setWindowTitle(QApplication::translate("WindSystem", "Dialog", nullptr));
        label_3->setText(QApplication::translate("WindSystem", "\346\226\260\351\243\216\345\274\272\345\272\246", nullptr));
        ButtonBox->setTitle(QString());
        StopMode->setText(QString());
        MidMode->setText(QString());
        MaxMode->setText(QString());
        MinMode->setText(QString());
        label_4->setText(QApplication::translate("WindSystem", "\351\200\211\346\213\251", nullptr));
        pushButton_2->setText(QString());
        Pirture->setText(QString());
        AutoSwitch->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class WindSystem: public Ui_WindSystem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDSYSTEM_H
