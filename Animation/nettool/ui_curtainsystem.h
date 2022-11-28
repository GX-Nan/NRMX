/********************************************************************************
** Form generated from reading UI file 'curtainsystem.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CURTAINSYSTEM_H
#define UI_CURTAINSYSTEM_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>

QT_BEGIN_NAMESPACE

class Ui_CurtainSystem
{
public:
    QFrame *bottom;
    QPushButton *pushButton_2;
    QPushButton *BackMain;
    QLabel *InsideBrightness;
    QPushButton *Up;
    QPushButton *Stop;
    QPushButton *Down;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *CurrentNumber;
    QSlider *Device_Slider;
    QLabel *CurrentNumber_2;
    QPushButton *AutoSwitch;

    void setupUi(QDialog *CurtainSystem)
    {
        if (CurtainSystem->objectName().isEmpty())
            CurtainSystem->setObjectName(QStringLiteral("CurtainSystem"));
        CurtainSystem->resize(1093, 720);
        CurtainSystem->setStyleSheet(QLatin1String("QDialog#CurtainSystem\n"
"{\n"
"	background-color:rgb(178,178,178,255);\n"
"}"));
        bottom = new QFrame(CurtainSystem);
        bottom->setObjectName(QStringLiteral("bottom"));
        bottom->setGeometry(QRect(10, 10, 1071, 701));
        bottom->setStyleSheet(QLatin1String("QFrame#bottom\n"
"{\n"
"	background-color:#ffffff;\n"
" \n"
"	border:none;\n"
"	border-radius:25px;\n"
"}"));
        bottom->setFrameShape(QFrame::StyledPanel);
        bottom->setFrameShadow(QFrame::Raised);
        pushButton_2 = new QPushButton(bottom);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(150, 740, 50, 50));
        pushButton_2->setStyleSheet(QLatin1String("max-width:50px;\n"
" max-height:50px;\n"
" min-width:50px;\n"
" min-height:50px;\n"
"border-radius:25px;\n"
"background-color: white;\n"
" border-style: solid;"));
        BackMain = new QPushButton(bottom);
        BackMain->setObjectName(QStringLiteral("BackMain"));
        BackMain->setGeometry(QRect(1000, 20, 50, 50));
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
        InsideBrightness = new QLabel(bottom);
        InsideBrightness->setObjectName(QStringLiteral("InsideBrightness"));
        InsideBrightness->setGeometry(QRect(80, 30, 481, 361));
        QFont font;
        font.setFamily(QString::fromUtf8("Adobe \351\273\221\344\275\223 Std R"));
        font.setPointSize(250);
        font.setBold(true);
        font.setWeight(75);
        InsideBrightness->setFont(font);
        InsideBrightness->setAlignment(Qt::AlignCenter);
        Up = new QPushButton(bottom);
        Up->setObjectName(QStringLiteral("Up"));
        Up->setGeometry(QRect(630, 100, 381, 121));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Adobe \351\273\221\344\275\223 Std R"));
        font1.setPointSize(15);
        Up->setFont(font1);
        Up->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	border-radius:15px;\n"
"	background:#FFFFFF;\n"
"}"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/new/Curtain/Curtain/Up_OFF.png"), QSize(), QIcon::Normal, QIcon::Off);
        Up->setIcon(icon1);
        Up->setIconSize(QSize(300, 300));
        Up->setCheckable(true);
        Up->setAutoExclusive(true);
        Stop = new QPushButton(bottom);
        Stop->setObjectName(QStringLiteral("Stop"));
        Stop->setGeometry(QRect(630, 310, 381, 121));
        Stop->setFont(font1);
        Stop->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	border-radius:15px;\n"
"	background:#FFFFFF;\n"
"}"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/new/Curtain/Curtain/Stop_OFF.png"), QSize(), QIcon::Normal, QIcon::Off);
        Stop->setIcon(icon2);
        Stop->setIconSize(QSize(200, 100));
        Stop->setCheckable(true);
        Stop->setAutoExclusive(true);
        Down = new QPushButton(bottom);
        Down->setObjectName(QStringLiteral("Down"));
        Down->setGeometry(QRect(630, 520, 381, 121));
        Down->setFont(font1);
        Down->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	border-radius:15px;\n"
"	background:#FFFFFF;\n"
"}"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/new/Curtain/Curtain/Down_OFF.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon3.addFile(QStringLiteral(":/new/Curtain/Curtain/Down_ON.png"), QSize(), QIcon::Selected, QIcon::On);
        Down->setIcon(icon3);
        Down->setIconSize(QSize(200, 120));
        Down->setCheckable(true);
        Down->setAutoExclusive(true);
        label_5 = new QLabel(bottom);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(230, 400, 181, 51));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Adobe \351\273\221\344\275\223 Std R"));
        font2.setPointSize(30);
        font2.setBold(true);
        font2.setWeight(75);
        label_5->setFont(font2);
        label_5->setStyleSheet(QStringLiteral("color:#282A49"));
        label_5->setAlignment(Qt::AlignCenter);
        label_6 = new QLabel(bottom);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(300, 450, 41, 31));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Adobe \351\273\221\344\275\223 Std R"));
        font3.setPointSize(13);
        font3.setBold(true);
        font3.setWeight(75);
        label_6->setFont(font3);
        label_6->setStyleSheet(QStringLiteral("color:#282A49"));
        label_6->setAlignment(Qt::AlignCenter);
        CurrentNumber = new QLabel(bottom);
        CurrentNumber->setObjectName(QStringLiteral("CurrentNumber"));
        CurrentNumber->setGeometry(QRect(300, 490, 61, 51));
        QFont font4;
        font4.setFamily(QString::fromUtf8("Adobe \351\273\221\344\275\223 Std R"));
        font4.setPointSize(25);
        font4.setBold(true);
        font4.setWeight(75);
        CurrentNumber->setFont(font4);
        CurrentNumber->setStyleSheet(QStringLiteral("color:#282A49"));
        CurrentNumber->setAlignment(Qt::AlignCenter);
        Device_Slider = new QSlider(bottom);
        Device_Slider->setObjectName(QStringLiteral("Device_Slider"));
        Device_Slider->setGeometry(QRect(90, 550, 461, 22));
        Device_Slider->setMaximum(3);
        Device_Slider->setOrientation(Qt::Horizontal);
        CurrentNumber_2 = new QLabel(bottom);
        CurrentNumber_2->setObjectName(QStringLiteral("CurrentNumber_2"));
        CurrentNumber_2->setGeometry(QRect(80, 490, 241, 51));
        CurrentNumber_2->setFont(font4);
        CurrentNumber_2->setStyleSheet(QStringLiteral("color:#282A49"));
        CurrentNumber_2->setAlignment(Qt::AlignCenter);
        AutoSwitch = new QPushButton(bottom);
        AutoSwitch->setObjectName(QStringLiteral("AutoSwitch"));
        AutoSwitch->setGeometry(QRect(90, 600, 461, 71));
        AutoSwitch->setFont(font1);
        AutoSwitch->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	border-radius:15px;\n"
"	background:#FFFFFF;\n"
"}"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/new/Led/Led/AI_ON.png"), QSize(), QIcon::Normal, QIcon::Off);
        AutoSwitch->setIcon(icon4);
        AutoSwitch->setIconSize(QSize(50, 80));
        AutoSwitch->setCheckable(true);
        AutoSwitch->setAutoExclusive(true);

        retranslateUi(CurtainSystem);

        QMetaObject::connectSlotsByName(CurtainSystem);
    } // setupUi

    void retranslateUi(QDialog *CurtainSystem)
    {
        CurtainSystem->setWindowTitle(QApplication::translate("CurtainSystem", "Dialog", nullptr));
        pushButton_2->setText(QApplication::translate("CurtainSystem", "s", nullptr));
        BackMain->setText(QString());
        InsideBrightness->setText(QApplication::translate("CurtainSystem", "37", nullptr));
        Up->setText(QString());
        Stop->setText(QString());
        Down->setText(QString());
        label_5->setText(QApplication::translate("CurtainSystem", "\345\256\244\345\206\205\344\272\256\345\272\246", nullptr));
        label_6->setText(QApplication::translate("CurtainSystem", "Lux", nullptr));
        CurrentNumber->setText(QApplication::translate("CurtainSystem", "0", nullptr));
        CurrentNumber_2->setText(QApplication::translate("CurtainSystem", "\345\275\223\345\211\215\347\252\227\345\270\230\357\274\232", nullptr));
        AutoSwitch->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class CurtainSystem: public Ui_CurtainSystem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CURTAINSYSTEM_H
