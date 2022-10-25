/********************************************************************************
** Form generated from reading UI file 'windmode.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDMODE_H
#define UI_WINDMODE_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_WindMode
{
public:
    QFrame *bottom;
    QFrame *frame;
    QLabel *label_4;
    QPushButton *StereoscopicMode;
    QPushButton *SurroundMode;
    QPushButton *NaturalMode;
    QLabel *label_6;
    QLabel *label_7;
    QPushButton *SeaMode;
    QLabel *label_5;
    QPushButton *CloseMode;
    QLabel *label_8;

    void setupUi(QDialog *WindMode)
    {
        if (WindMode->objectName().isEmpty())
            WindMode->setObjectName(QStringLiteral("WindMode"));
        WindMode->resize(341, 722);
        WindMode->setStyleSheet(QLatin1String("QDialog#WindMode\n"
"{\n"
"background-color:rgb(178,178,178,255);\n"
"}"));
        bottom = new QFrame(WindMode);
        bottom->setObjectName(QStringLiteral("bottom"));
        bottom->setGeometry(QRect(10, 10, 321, 701));
        bottom->setStyleSheet(QLatin1String("QFrame#bottom\n"
"{\n"
"	background-color:#ffffff;\n"
" \n"
"	border:none;\n"
"	border-radius:25px;\n"
"}"));
        bottom->setFrameShape(QFrame::StyledPanel);
        bottom->setFrameShadow(QFrame::Raised);
        frame = new QFrame(bottom);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(10, 10, 301, 681));
        frame->setStyleSheet(QStringLiteral("border:none;"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        label_4 = new QLabel(frame);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(100, 115, 101, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("Adobe \351\273\221\344\275\223 Std R"));
        font.setPointSize(15);
        font.setBold(true);
        font.setWeight(75);
        label_4->setFont(font);
        label_4->setStyleSheet(QStringLiteral("color:#282A49"));
        label_4->setAlignment(Qt::AlignCenter);
        StereoscopicMode = new QPushButton(frame);
        StereoscopicMode->setObjectName(QStringLiteral("StereoscopicMode"));
        StereoscopicMode->setGeometry(QRect(60, 420, 181, 81));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Adobe \351\273\221\344\275\223 Std R"));
        font1.setPointSize(15);
        StereoscopicMode->setFont(font1);
        StereoscopicMode->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	border-radius:15px;\n"
"	background:#FFFFFF;\n"
"}"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/new/Wind/Wind/Solid_OFF.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon.addFile(QStringLiteral(":/new/Wind/Wind/Solid_ON.png"), QSize(), QIcon::Normal, QIcon::On);
        StereoscopicMode->setIcon(icon);
        StereoscopicMode->setIconSize(QSize(100, 50));
        StereoscopicMode->setCheckable(true);
        StereoscopicMode->setChecked(false);
        StereoscopicMode->setAutoExclusive(true);
        SurroundMode = new QPushButton(frame);
        SurroundMode->setObjectName(QStringLiteral("SurroundMode"));
        SurroundMode->setGeometry(QRect(60, 150, 181, 81));
        SurroundMode->setFont(font1);
        SurroundMode->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	border-radius:15px;\n"
"	background:#FFFFFF;\n"
"}"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/new/Wind/Wind/Surround_OFF.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon1.addFile(QStringLiteral(":/new/Wind/Wind/Surround_ON.png"), QSize(), QIcon::Normal, QIcon::On);
        SurroundMode->setIcon(icon1);
        SurroundMode->setIconSize(QSize(100, 50));
        SurroundMode->setCheckable(true);
        SurroundMode->setChecked(false);
        SurroundMode->setAutoExclusive(true);
        NaturalMode = new QPushButton(frame);
        NaturalMode->setObjectName(QStringLiteral("NaturalMode"));
        NaturalMode->setGeometry(QRect(60, 290, 181, 81));
        NaturalMode->setFont(font1);
        NaturalMode->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	border-radius:15px;\n"
"	background:#FFFFFF;\n"
"}"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/new/Wind/Wind/Natural_OFF.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon2.addFile(QStringLiteral(":/new/Wind/Wind/Natural_ON.png"), QSize(), QIcon::Normal, QIcon::On);
        NaturalMode->setIcon(icon2);
        NaturalMode->setIconSize(QSize(100, 50));
        NaturalMode->setCheckable(true);
        NaturalMode->setChecked(false);
        NaturalMode->setAutoExclusive(true);
        label_6 = new QLabel(frame);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(100, 380, 101, 31));
        label_6->setFont(font);
        label_6->setStyleSheet(QStringLiteral("color:#282A49"));
        label_6->setAlignment(Qt::AlignCenter);
        label_7 = new QLabel(frame);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(100, 510, 101, 31));
        label_7->setFont(font);
        label_7->setStyleSheet(QStringLiteral("color:#282A49"));
        label_7->setAlignment(Qt::AlignCenter);
        SeaMode = new QPushButton(frame);
        SeaMode->setObjectName(QStringLiteral("SeaMode"));
        SeaMode->setGeometry(QRect(60, 20, 181, 81));
        SeaMode->setFont(font1);
        SeaMode->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	border-radius:15px;\n"
"	background:#FFFFFF;\n"
"}"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/new/Wind/Wind/Sea_OFF.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon3.addFile(QStringLiteral(":/new/Wind/Wind/Sea_ON.png"), QSize(), QIcon::Normal, QIcon::On);
        SeaMode->setIcon(icon3);
        SeaMode->setIconSize(QSize(100, 50));
        SeaMode->setCheckable(true);
        SeaMode->setChecked(false);
        SeaMode->setAutoExclusive(true);
        label_5 = new QLabel(frame);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(100, 250, 101, 31));
        label_5->setFont(font);
        label_5->setStyleSheet(QStringLiteral("color:#282A49"));
        label_5->setAlignment(Qt::AlignCenter);
        CloseMode = new QPushButton(frame);
        CloseMode->setObjectName(QStringLiteral("CloseMode"));
        CloseMode->setGeometry(QRect(60, 550, 181, 81));
        CloseMode->setFont(font1);
        CloseMode->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	border-radius:15px;\n"
"	background:#FFFFFF;\n"
"}"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/new/Air/Air/AirSwitch.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon4.addFile(QStringLiteral(":/new/Air/Air/AirSwitch-ON.png"), QSize(), QIcon::Normal, QIcon::On);
        CloseMode->setIcon(icon4);
        CloseMode->setIconSize(QSize(100, 50));
        CloseMode->setCheckable(true);
        CloseMode->setChecked(false);
        CloseMode->setAutoExclusive(true);
        label_8 = new QLabel(frame);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(100, 640, 101, 31));
        label_8->setFont(font);
        label_8->setStyleSheet(QStringLiteral("color:#282A49"));
        label_8->setAlignment(Qt::AlignCenter);

        retranslateUi(WindMode);

        QMetaObject::connectSlotsByName(WindMode);
    } // setupUi

    void retranslateUi(QDialog *WindMode)
    {
        WindMode->setWindowTitle(QApplication::translate("WindMode", "Dialog", nullptr));
        label_4->setText(QApplication::translate("WindMode", "\346\265\267\346\264\213", nullptr));
        StereoscopicMode->setText(QString());
        SurroundMode->setText(QString());
        NaturalMode->setText(QString());
        label_6->setText(QApplication::translate("WindMode", "\350\207\252\347\204\266", nullptr));
        label_7->setText(QApplication::translate("WindMode", "\347\253\213\344\275\223", nullptr));
        SeaMode->setText(QString());
        label_5->setText(QApplication::translate("WindMode", "\347\216\257\347\273\225", nullptr));
        CloseMode->setText(QString());
        label_8->setText(QApplication::translate("WindMode", "\345\205\263\351\227\255", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WindMode: public Ui_WindMode {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDMODE_H
