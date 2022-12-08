/********************************************************************************
** Form generated from reading UI file 'windowbox.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOWBOX_H
#define UI_WINDOWBOX_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>

QT_BEGIN_NAMESPACE

class Ui_WindowBox
{
public:
    QGroupBox *Bottom;
    QLabel *CurrentText;
    QPushButton *Stop;
    QLabel *label;
    QPushButton *Close;
    QPushButton *Open;
    QSlider *Device_Slider;
    QPushButton *Back;

    void setupUi(QDialog *WindowBox)
    {
        if (WindowBox->objectName().isEmpty())
            WindowBox->setObjectName(QStringLiteral("WindowBox"));
        WindowBox->resize(808, 317);
        WindowBox->setStyleSheet(QLatin1String("QDialog#WindowBox{\n"
"background-color:rgb(178,178,178,255);\n"
"	border:none;\n"
"	border-radius:25px;\n"
"}"));
        Bottom = new QGroupBox(WindowBox);
        Bottom->setObjectName(QStringLiteral("Bottom"));
        Bottom->setGeometry(QRect(10, 10, 791, 301));
        Bottom->setStyleSheet(QLatin1String("QGroupBox#Bottom{\n"
"background-color:white;\n"
"border-radius:25px;\n"
"}"));
        CurrentText = new QLabel(Bottom);
        CurrentText->setObjectName(QStringLiteral("CurrentText"));
        CurrentText->setGeometry(QRect(440, 205, 31, 21));
        QFont font;
        font.setFamily(QString::fromUtf8("Adobe \351\273\221\344\275\223 Std R"));
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        CurrentText->setFont(font);
        CurrentText->setAlignment(Qt::AlignCenter);
        Stop = new QPushButton(Bottom);
        Stop->setObjectName(QStringLiteral("Stop"));
        Stop->setGeometry(QRect(330, 30, 121, 121));
        Stop->setStyleSheet(QLatin1String("\n"
"border-radius:8px;\n"
"background:#FFFFFF;"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/new/Curtains/Curtains/Stop_OFF.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon.addFile(QStringLiteral(":/new/Curtains/Curtains/Stop_ON.png"), QSize(), QIcon::Normal, QIcon::On);
        Stop->setIcon(icon);
        Stop->setIconSize(QSize(80, 80));
        label = new QLabel(Bottom);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(310, 205, 141, 21));
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);
        Close = new QPushButton(Bottom);
        Close->setObjectName(QStringLiteral("Close"));
        Close->setGeometry(QRect(610, 30, 121, 121));
        Close->setStyleSheet(QLatin1String("\n"
"border-radius:8px;\n"
"background:#FFFFFF;"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/new/Window/Window/Close.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon1.addFile(QStringLiteral(":/new/Window/Window/Close_White.png"), QSize(), QIcon::Normal, QIcon::On);
        Close->setIcon(icon1);
        Close->setIconSize(QSize(80, 80));
        Open = new QPushButton(Bottom);
        Open->setObjectName(QStringLiteral("Open"));
        Open->setGeometry(QRect(50, 30, 121, 121));
        Open->setStyleSheet(QLatin1String("\n"
"border-radius:8px;\n"
"background:#FFFFFF;"));
        Open->setIcon(icon1);
        Open->setIconSize(QSize(80, 80));
        Device_Slider = new QSlider(Bottom);
        Device_Slider->setObjectName(QStringLiteral("Device_Slider"));
        Device_Slider->setGeometry(QRect(50, 170, 701, 21));
        Device_Slider->setMaximum(2);
        Device_Slider->setOrientation(Qt::Horizontal);
        Back = new QPushButton(Bottom);
        Back->setObjectName(QStringLiteral("Back"));
        Back->setGeometry(QRect(370, 240, 50, 50));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Adobe \351\273\221\344\275\223 Std R"));
        font1.setPointSize(15);
        Back->setFont(font1);
        Back->setStyleSheet(QLatin1String("max-width:50px;\n"
" max-height:50px;\n"
" min-width:50px;\n"
" min-height:50px;\n"
"border-radius:25px;\n"
"background-color: white;\n"
" border-style: solid;"));
        Back->setIconSize(QSize(70, 70));

        retranslateUi(WindowBox);

        QMetaObject::connectSlotsByName(WindowBox);
    } // setupUi

    void retranslateUi(QDialog *WindowBox)
    {
        WindowBox->setWindowTitle(QApplication::translate("WindowBox", "Dialog", nullptr));
        Bottom->setTitle(QString());
        CurrentText->setText(QApplication::translate("WindowBox", "0", nullptr));
        Stop->setText(QString());
        label->setText(QApplication::translate("WindowBox", "\345\275\223\345\211\215\346\216\247\345\210\266\347\232\204\347\252\227\346\210\267\357\274\232", nullptr));
        Close->setText(QString());
        Open->setText(QString());
        Back->setText(QApplication::translate("WindowBox", "B", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WindowBox: public Ui_WindowBox {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOWBOX_H
