/********************************************************************************
** Form generated from reading UI file 'curtainsbox.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CURTAINSBOX_H
#define UI_CURTAINSBOX_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>

QT_BEGIN_NAMESPACE

class Ui_CurtainsBox
{
public:
    QGroupBox *Bottom;
    QLabel *label;
    QPushButton *Down;
    QPushButton *Stop;
    QSlider *Device_Slider;
    QPushButton *Up;
    QPushButton *Close;
    QLabel *CurrentText;

    void setupUi(QDialog *CurtainsBox)
    {
        if (CurtainsBox->objectName().isEmpty())
            CurtainsBox->setObjectName(QStringLiteral("CurtainsBox"));
        CurtainsBox->resize(810, 339);
        CurtainsBox->setStyleSheet(QLatin1String("QDialog#CurtainsBox{\n"
"background-color:rgb(178,178,178,255);\n"
"	border:none;\n"
"	border-radius:25px;\n"
"}\n"
""));
        Bottom = new QGroupBox(CurtainsBox);
        Bottom->setObjectName(QStringLiteral("Bottom"));
        Bottom->setGeometry(QRect(10, 10, 791, 321));
        Bottom->setStyleSheet(QLatin1String("QGroupBox#Bottom{\n"
"background-color:white;\n"
"border-radius:25px;\n"
"}"));
        label = new QLabel(Bottom);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(310, 220, 141, 21));
        QFont font;
        font.setFamily(QString::fromUtf8("Adobe \351\273\221\344\275\223 Std R"));
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);
        Down = new QPushButton(Bottom);
        Down->setObjectName(QStringLiteral("Down"));
        Down->setGeometry(QRect(620, 40, 121, 121));
        Down->setStyleSheet(QLatin1String("\n"
"border-radius:8px;\n"
"background:#FFFFFF;"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/new/Curtains/Curtains/Down_OFF.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon.addFile(QStringLiteral(":/new/Curtains/Curtains/Down_ON.png"), QSize(), QIcon::Normal, QIcon::On);
        Down->setIcon(icon);
        Down->setIconSize(QSize(80, 80));
        Down->setCheckable(true);
        Down->setAutoExclusive(true);
        Stop = new QPushButton(Bottom);
        Stop->setObjectName(QStringLiteral("Stop"));
        Stop->setGeometry(QRect(330, 40, 121, 121));
        Stop->setStyleSheet(QLatin1String("\n"
"border-radius:8px;\n"
"background:#FFFFFF;"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/new/Curtains/Curtains/Stop_OFF.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon1.addFile(QStringLiteral(":/new/Curtains/Curtains/Stop_ON.png"), QSize(), QIcon::Normal, QIcon::On);
        Stop->setIcon(icon1);
        Stop->setIconSize(QSize(80, 80));
        Stop->setCheckable(true);
        Stop->setAutoExclusive(true);
        Device_Slider = new QSlider(Bottom);
        Device_Slider->setObjectName(QStringLiteral("Device_Slider"));
        Device_Slider->setGeometry(QRect(50, 180, 711, 21));
        Device_Slider->setMaximum(3);
        Device_Slider->setOrientation(Qt::Horizontal);
        Up = new QPushButton(Bottom);
        Up->setObjectName(QStringLiteral("Up"));
        Up->setGeometry(QRect(50, 40, 121, 121));
        Up->setStyleSheet(QLatin1String("\n"
"border-radius:8px;\n"
"background:#FFFFFF;"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/new/Curtains/Curtains/Up_OFF.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon2.addFile(QStringLiteral(":/new/Curtains/Curtains/Up_ON.png"), QSize(), QIcon::Normal, QIcon::On);
        Up->setIcon(icon2);
        Up->setIconSize(QSize(80, 80));
        Up->setCheckable(true);
        Up->setAutoExclusive(true);
        Close = new QPushButton(Bottom);
        Close->setObjectName(QStringLiteral("Close"));
        Close->setGeometry(QRect(370, 260, 50, 50));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Adobe \351\273\221\344\275\223 Std R"));
        font1.setPointSize(15);
        Close->setFont(font1);
        Close->setStyleSheet(QLatin1String("max-width:50px;\n"
" max-height:50px;\n"
" min-width:50px;\n"
" min-height:50px;\n"
"border-radius:25px;\n"
"background-color: white;\n"
" border-style: solid;"));
        Close->setIconSize(QSize(70, 70));
        CurrentText = new QLabel(Bottom);
        CurrentText->setObjectName(QStringLiteral("CurrentText"));
        CurrentText->setGeometry(QRect(450, 220, 31, 21));
        CurrentText->setFont(font);
        CurrentText->setAlignment(Qt::AlignCenter);

        retranslateUi(CurtainsBox);

        QMetaObject::connectSlotsByName(CurtainsBox);
    } // setupUi

    void retranslateUi(QDialog *CurtainsBox)
    {
        CurtainsBox->setWindowTitle(QApplication::translate("CurtainsBox", "Dialog", nullptr));
        Bottom->setTitle(QString());
        label->setText(QApplication::translate("CurtainsBox", "\345\275\223\345\211\215\346\216\247\345\210\266\347\232\204\347\252\227\345\270\230\357\274\232", nullptr));
        Down->setText(QString());
        Stop->setText(QString());
        Up->setText(QString());
        Close->setText(QApplication::translate("CurtainsBox", "B", nullptr));
        CurrentText->setText(QApplication::translate("CurtainsBox", "0", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CurtainsBox: public Ui_CurtainsBox {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CURTAINSBOX_H
