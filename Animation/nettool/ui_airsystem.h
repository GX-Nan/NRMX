/********************************************************************************
** Form generated from reading UI file 'airsystem.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AIRSYSTEM_H
#define UI_AIRSYSTEM_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include "switchbutton.h"

QT_BEGIN_NAMESPACE

class Ui_AirSystem
{
public:
    QFrame *bottom;
    QPushButton *AirSwitch;
    QSlider *TempQslider;
    QLabel *label_3;
    QLabel *AirTemp;
    QLabel *label;
    QPushButton *BackMain;
    QFrame *FunctionPanel;
    SwitchButton *SwingUpDown;
    SwitchButton *SwingLeftRight;
    QLabel *label_5;
    QLabel *label_6;
    QGroupBox *Group_Fan;
    QPushButton *Fan_Low;
    QPushButton *Fan_Mid;
    QPushButton *Fan_High;
    QLabel *label_4;
    QGroupBox *Group_Mode;
    QPushButton *Dry;
    QPushButton *Cold;
    QPushButton *Fan;
    QPushButton *Heat;
    QLabel *AirMode;
    QLabel *SwingUD_P;
    QLabel *SwingLR_P;

    void setupUi(QDialog *AirSystem)
    {
        if (AirSystem->objectName().isEmpty())
            AirSystem->setObjectName(QString::fromUtf8("AirSystem"));
        AirSystem->resize(1086, 720);
        AirSystem->setStyleSheet(QString::fromUtf8("QDialog#AirSystem{\n"
"background-color:rgb(178,178,178,255);\n"
"	border:none;\n"
"	border-radius:25px;\n"
"}"));
        bottom = new QFrame(AirSystem);
        bottom->setObjectName(QString::fromUtf8("bottom"));
        bottom->setGeometry(QRect(10, 10, 1070, 701));
        QFont font;
        font.setFamily(QString::fromUtf8("Adobe \351\273\221\344\275\223 Std R"));
        bottom->setFont(font);
        bottom->setStyleSheet(QString::fromUtf8("QFrame#bottom\n"
"{\n"
"	background-color:#ffffff;\n"
" \n"
"	border:none;\n"
"	border-radius:25px;\n"
"}"));
        bottom->setFrameShape(QFrame::StyledPanel);
        bottom->setFrameShadow(QFrame::Raised);
        AirSwitch = new QPushButton(bottom);
        AirSwitch->setObjectName(QString::fromUtf8("AirSwitch"));
        AirSwitch->setGeometry(QRect(100, 570, 441, 91));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Adobe \351\273\221\344\275\223 Std R"));
        font1.setPointSize(15);
        AirSwitch->setFont(font1);
        AirSwitch->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	border-radius:15px;\n"
"	background:#FFFFFF;\n"
"}"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/Air/Air/AirSwitch.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon.addFile(QString::fromUtf8(":/new/Air/Air/AirSwitch-ON.png"), QSize(), QIcon::Normal, QIcon::On);
        AirSwitch->setIcon(icon);
        AirSwitch->setIconSize(QSize(100, 50));
        TempQslider = new QSlider(bottom);
        TempQslider->setObjectName(QString::fromUtf8("TempQslider"));
        TempQslider->setGeometry(QRect(100, 520, 441, 22));
        TempQslider->setMinimum(16);
        TempQslider->setMaximum(31);
        TempQslider->setOrientation(Qt::Horizontal);
        label_3 = new QLabel(bottom);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(280, 450, 141, 31));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Adobe \351\273\221\344\275\223 Std R"));
        font2.setPointSize(15);
        font2.setBold(true);
        font2.setWeight(75);
        label_3->setFont(font2);
        label_3->setStyleSheet(QString::fromUtf8("color:#282A49"));
        label_3->setAlignment(Qt::AlignCenter);
        AirTemp = new QLabel(bottom);
        AirTemp->setObjectName(QString::fromUtf8("AirTemp"));
        AirTemp->setGeometry(QRect(40, 40, 531, 391));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Adobe \351\273\221\344\275\223 Std R"));
        font3.setPointSize(300);
        font3.setBold(true);
        font3.setWeight(75);
        AirTemp->setFont(font3);
        AirTemp->setStyleSheet(QString::fromUtf8("/*border:5px solid black;\n"
"border-radius:15px;\n"
""));
        AirTemp->setAlignment(Qt::AlignCenter);
        label = new QLabel(bottom);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(200, 430, 71, 71));
        BackMain = new QPushButton(bottom);
        BackMain->setObjectName(QString::fromUtf8("BackMain"));
        BackMain->setGeometry(QRect(20, 20, 50, 50));
        BackMain->setStyleSheet(QString::fromUtf8("max-width:50px;\n"
" max-height:50px;\n"
" min-width:50px;\n"
" min-height:50px;\n"
"border-radius:25px;\n"
"background-color: white;\n"
" border-style: solid;"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/new/Main/Air/Back.png"), QSize(), QIcon::Normal, QIcon::Off);
        BackMain->setIcon(icon1);
        BackMain->setIconSize(QSize(50, 50));
        FunctionPanel = new QFrame(bottom);
        FunctionPanel->setObjectName(QString::fromUtf8("FunctionPanel"));
        FunctionPanel->setGeometry(QRect(640, -10, 421, 701));
        FunctionPanel->setStyleSheet(QString::fromUtf8("border:none;"));
        FunctionPanel->setFrameShape(QFrame::StyledPanel);
        FunctionPanel->setFrameShadow(QFrame::Raised);
        SwingUpDown = new SwitchButton(FunctionPanel);
        SwingUpDown->setObjectName(QString::fromUtf8("SwingUpDown"));
        SwingUpDown->setGeometry(QRect(230, 485, 121, 41));
        SwingLeftRight = new SwitchButton(FunctionPanel);
        SwingLeftRight->setObjectName(QString::fromUtf8("SwingLeftRight"));
        SwingLeftRight->setGeometry(QRect(230, 380, 121, 41));
        label_5 = new QLabel(FunctionPanel);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(140, 470, 71, 71));
        QFont font4;
        font4.setFamily(QString::fromUtf8("Adobe \351\273\221\344\275\223 Std R"));
        font4.setPointSize(20);
        font4.setBold(false);
        font4.setWeight(50);
        label_5->setFont(font4);
        label_5->setStyleSheet(QString::fromUtf8("color:#282A49"));
        label_5->setAlignment(Qt::AlignCenter);
        label_5->setWordWrap(true);
        label_6 = new QLabel(FunctionPanel);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(140, 230, 141, 31));
        label_6->setFont(font2);
        label_6->setStyleSheet(QString::fromUtf8("color:#282A49"));
        label_6->setAlignment(Qt::AlignCenter);
        Group_Fan = new QGroupBox(FunctionPanel);
        Group_Fan->setObjectName(QString::fromUtf8("Group_Fan"));
        Group_Fan->setGeometry(QRect(30, 570, 361, 101));
        Group_Fan->setStyleSheet(QString::fromUtf8("border:none;\n"
"background-color:#ffffff;\n"
"border-radius:15px;"));
        Fan_Low = new QPushButton(Group_Fan);
        Fan_Low->setObjectName(QString::fromUtf8("Fan_Low"));
        Fan_Low->setGeometry(QRect(40, 20, 60, 60));
        QFont font5;
        font5.setFamily(QString::fromUtf8("Berlin Sans FB Demi"));
        font5.setPointSize(20);
        Fan_Low->setFont(font5);
        Fan_Low->setStyleSheet(QString::fromUtf8("max-width:60px;\n"
" max-height:60px;\n"
" min-width:60px;\n"
" min-height:60px;\n"
"border-radius:30px;\n"
"background-color: white;\n"
" border-style: solid;"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/new/Air/Air/Low_OFF.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon2.addFile(QString::fromUtf8(":/new/Air/Air/Low_ON.png"), QSize(), QIcon::Normal, QIcon::On);
        icon2.addFile(QString::fromUtf8(":/new/Air/Air/Low_OFF.png"), QSize(), QIcon::Disabled, QIcon::On);
        icon2.addFile(QString::fromUtf8(":/new/Air/Air/Low_ON.png"), QSize(), QIcon::Active, QIcon::On);
        Fan_Low->setIcon(icon2);
        Fan_Low->setIconSize(QSize(44, 44));
        Fan_Low->setCheckable(true);
        Fan_Low->setAutoExclusive(true);
        Fan_Mid = new QPushButton(Group_Fan);
        Fan_Mid->setObjectName(QString::fromUtf8("Fan_Mid"));
        Fan_Mid->setGeometry(QRect(150, 20, 60, 60));
        Fan_Mid->setFont(font5);
        Fan_Mid->setStyleSheet(QString::fromUtf8("max-width:60px;\n"
" max-height:60px;\n"
" min-width:60px;\n"
" min-height:60px;\n"
"border-radius:30px;\n"
"background-color: white;\n"
" border-style: solid;"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/new/Air/Air/Mid_OFF.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon3.addFile(QString::fromUtf8(":/new/Air/Air/Mid_ON.png"), QSize(), QIcon::Normal, QIcon::On);
        icon3.addFile(QString::fromUtf8(":/new/Air/Air/Mid_ON.png"), QSize(), QIcon::Active, QIcon::On);
        Fan_Mid->setIcon(icon3);
        Fan_Mid->setIconSize(QSize(44, 44));
        Fan_Mid->setCheckable(true);
        Fan_Mid->setAutoExclusive(true);
        Fan_High = new QPushButton(Group_Fan);
        Fan_High->setObjectName(QString::fromUtf8("Fan_High"));
        Fan_High->setGeometry(QRect(250, 20, 60, 60));
        Fan_High->setFont(font5);
        Fan_High->setStyleSheet(QString::fromUtf8("max-width:60px;\n"
" max-height:60px;\n"
" min-width:60px;\n"
" min-height:60px;\n"
"border-radius:30px;\n"
"background-color: white;\n"
" border-style: solid;"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/new/Air/Air/High_OFF.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon4.addFile(QString::fromUtf8(":/new/Air/Air/High_ON.png"), QSize(), QIcon::Normal, QIcon::On);
        icon4.addFile(QString::fromUtf8(":/new/Air/Air/High_OFF.png"), QSize(), QIcon::Disabled, QIcon::On);
        Fan_High->setIcon(icon4);
        Fan_High->setIconSize(QSize(44, 44));
        Fan_High->setCheckable(true);
        Fan_High->setAutoExclusive(true);
        label_4 = new QLabel(FunctionPanel);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(140, 370, 71, 71));
        label_4->setFont(font4);
        label_4->setStyleSheet(QString::fromUtf8("color:#282A49"));
        label_4->setAlignment(Qt::AlignCenter);
        label_4->setWordWrap(true);
        Group_Mode = new QGroupBox(FunctionPanel);
        Group_Mode->setObjectName(QString::fromUtf8("Group_Mode"));
        Group_Mode->setGeometry(QRect(30, 270, 351, 81));
        Group_Mode->setStyleSheet(QString::fromUtf8("border:none;"));
        Dry = new QPushButton(Group_Mode);
        Dry->setObjectName(QString::fromUtf8("Dry"));
        Dry->setGeometry(QRect(100, 10, 60, 60));
        Dry->setFont(font5);
        Dry->setStyleSheet(QString::fromUtf8("max-width:60px;\n"
" max-height:60px;\n"
" min-width:60px;\n"
" min-height:60px;\n"
"border-radius:30px;\n"
"background-color: white;\n"
" border-style: solid;\n"
""));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/new/Air/Air/Dry_OFF.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon5.addFile(QString::fromUtf8(":/new/Air/Air/Dry_ON.png"), QSize(), QIcon::Normal, QIcon::On);
        icon5.addFile(QString::fromUtf8(":/new/Air/Air/Dry_OFF.png"), QSize(), QIcon::Disabled, QIcon::On);
        icon5.addFile(QString::fromUtf8(":/new/Air/Air/Dry_OFF.png"), QSize(), QIcon::Active, QIcon::Off);
        icon5.addFile(QString::fromUtf8(":/new/Air/Air/Dry_ON.png"), QSize(), QIcon::Active, QIcon::On);
        icon5.addFile(QString::fromUtf8(":/new/Air/Air/Dry_OFF.png"), QSize(), QIcon::Selected, QIcon::Off);
        icon5.addFile(QString::fromUtf8(":/new/Air/Air/Dry_ON.png"), QSize(), QIcon::Selected, QIcon::On);
        Dry->setIcon(icon5);
        Dry->setIconSize(QSize(44, 44));
        Dry->setCheckable(true);
        Dry->setAutoExclusive(true);
        Cold = new QPushButton(Group_Mode);
        Cold->setObjectName(QString::fromUtf8("Cold"));
        Cold->setGeometry(QRect(190, 10, 60, 60));
        Cold->setFont(font5);
        Cold->setStyleSheet(QString::fromUtf8("max-width:60px;\n"
" max-height:60px;\n"
" min-width:60px;\n"
" min-height:60px;\n"
"border-radius:30px;\n"
"background-color: white;\n"
" border-style: solid;\n"
""));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/new/Air/Air/Cold_OFF.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon6.addFile(QString::fromUtf8(":/new/Air/Air/Cold_ON.png"), QSize(), QIcon::Normal, QIcon::On);
        icon6.addFile(QString::fromUtf8(":/new/Air/Air/Cold_OFF.png"), QSize(), QIcon::Disabled, QIcon::On);
        icon6.addFile(QString::fromUtf8(":/new/Air/Air/Cold_OFF.png"), QSize(), QIcon::Active, QIcon::Off);
        icon6.addFile(QString::fromUtf8(":/new/Air/Air/Cold_ON.png"), QSize(), QIcon::Active, QIcon::On);
        icon6.addFile(QString::fromUtf8(":/new/Air/Air/Cold_OFF.png"), QSize(), QIcon::Selected, QIcon::Off);
        icon6.addFile(QString::fromUtf8(":/new/Air/Air/Cold_ON.png"), QSize(), QIcon::Selected, QIcon::On);
        Cold->setIcon(icon6);
        Cold->setIconSize(QSize(44, 44));
        Cold->setCheckable(true);
        Cold->setAutoExclusive(true);
        Fan = new QPushButton(Group_Mode);
        Fan->setObjectName(QString::fromUtf8("Fan"));
        Fan->setGeometry(QRect(10, 10, 60, 60));
        Fan->setFont(font5);
        Fan->setStyleSheet(QString::fromUtf8("max-width:60px;\n"
" max-height:60px;\n"
" min-width:60px;\n"
" min-height:60px;\n"
"border-radius:30px;\n"
"background-color: white;\n"
" border-style: solid;\n"
""));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/new/Air/Air/Fan_OFF.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon7.addFile(QString::fromUtf8(":/new/Air/Air/Fan_ON.png"), QSize(), QIcon::Normal, QIcon::On);
        icon7.addFile(QString::fromUtf8(":/new/Air/Air/Fan_OFF.png"), QSize(), QIcon::Disabled, QIcon::On);
        Fan->setIcon(icon7);
        Fan->setIconSize(QSize(44, 44));
        Fan->setCheckable(true);
        Fan->setAutoExclusive(true);
        Heat = new QPushButton(Group_Mode);
        Heat->setObjectName(QString::fromUtf8("Heat"));
        Heat->setGeometry(QRect(280, 10, 60, 60));
        Heat->setFont(font5);
        Heat->setStyleSheet(QString::fromUtf8("max-width:60px;\n"
" max-height:60px;\n"
" min-width:60px;\n"
" min-height:60px;\n"
"border-radius:30px;\n"
"background-color: white;\n"
" border-style: solid;\n"
""));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/new/Air/Air/Heat_OFF.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon8.addFile(QString::fromUtf8(":/new/Air/Air/Heat_ON.png"), QSize(), QIcon::Normal, QIcon::On);
        icon8.addFile(QString::fromUtf8(":/new/Air/Air/Heat_OFF.png"), QSize(), QIcon::Disabled, QIcon::On);
        icon8.addFile(QString::fromUtf8(":/new/Air/Air/Heat_OFF.png"), QSize(), QIcon::Selected, QIcon::Off);
        icon8.addFile(QString::fromUtf8(":/new/Air/Air/Heat_ON.png"), QSize(), QIcon::Selected, QIcon::On);
        Heat->setIcon(icon8);
        Heat->setIconSize(QSize(44, 44));
        Heat->setCheckable(true);
        Heat->setAutoExclusive(true);
        AirMode = new QLabel(FunctionPanel);
        AirMode->setObjectName(QString::fromUtf8("AirMode"));
        AirMode->setGeometry(QRect(120, 50, 181, 171));
        AirMode->setStyleSheet(QString::fromUtf8("background-color:#ffffff;\n"
"border:none;\n"
"border-radius:25px;"));
        AirMode->setPixmap(QPixmap(QString::fromUtf8(":/new/Air/Air/Mode.png")));
        AirMode->setScaledContents(false);
        AirMode->setAlignment(Qt::AlignCenter);
        SwingUD_P = new QLabel(FunctionPanel);
        SwingUD_P->setObjectName(QString::fromUtf8("SwingUD_P"));
        SwingUD_P->setGeometry(QRect(30, 460, 81, 81));
        SwingUD_P->setAlignment(Qt::AlignCenter);
        SwingLR_P = new QLabel(FunctionPanel);
        SwingLR_P->setObjectName(QString::fromUtf8("SwingLR_P"));
        SwingLR_P->setGeometry(QRect(30, 360, 81, 81));
        SwingLR_P->setAlignment(Qt::AlignCenter);

        retranslateUi(AirSystem);

        QMetaObject::connectSlotsByName(AirSystem);
    } // setupUi

    void retranslateUi(QDialog *AirSystem)
    {
        AirSystem->setWindowTitle(QCoreApplication::translate("AirSystem", "Dialog", nullptr));
        AirSwitch->setText(QString());
        label_3->setText(QCoreApplication::translate("AirSystem", "\347\251\272 \350\260\203 \346\270\251 \345\272\246", nullptr));
        AirTemp->setText(QCoreApplication::translate("AirSystem", "18", nullptr));
        label->setText(QCoreApplication::translate("AirSystem", "TextLabel", nullptr));
        BackMain->setText(QString());
        label_5->setText(QCoreApplication::translate("AirSystem", "\344\270\212\344\270\213\346\221\206\351\243\216", nullptr));
        label_6->setText(QCoreApplication::translate("AirSystem", "\347\251\272\350\260\203\346\250\241\345\274\217", nullptr));
        Group_Fan->setTitle(QString());
        Fan_Low->setText(QString());
        Fan_Mid->setText(QString());
        Fan_High->setText(QString());
        label_4->setText(QCoreApplication::translate("AirSystem", "\345\267\246\345\217\263\346\221\206\351\243\216", nullptr));
        Group_Mode->setTitle(QString());
        Dry->setText(QString());
        Cold->setText(QString());
        Fan->setText(QString());
        Heat->setText(QString());
        AirMode->setText(QString());
        SwingUD_P->setText(QCoreApplication::translate("AirSystem", "Mode", nullptr));
        SwingLR_P->setText(QCoreApplication::translate("AirSystem", "Mode", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AirSystem: public Ui_AirSystem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AIRSYSTEM_H
