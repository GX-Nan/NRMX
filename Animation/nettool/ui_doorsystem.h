/********************************************************************************
** Form generated from reading UI file 'doorsystem.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DOORSYSTEM_H
#define UI_DOORSYSTEM_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_DoorSystem
{
public:
    QFrame *bottom;
    QLabel *label_3;
    QLabel *label_4;
    QPushButton *BackMain;
    QLabel *PassTimes;
    QLabel *label_2;
    QFrame *frame;
    QPushButton *OpenDoor;
    QPushButton *CloseDoor;

    void setupUi(QDialog *DoorSystem)
    {
        if (DoorSystem->objectName().isEmpty())
            DoorSystem->setObjectName(QString::fromUtf8("DoorSystem"));
        DoorSystem->resize(369, 821);
        DoorSystem->setStyleSheet(QString::fromUtf8("QDialog#DoorSystem{\n"
"background-color:rgb(178,178,178,255);\n"
"}"));
        bottom = new QFrame(DoorSystem);
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
        label_3->setGeometry(QRect(175, 300, 101, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("Adobe \351\273\221\344\275\223 Std R"));
        font.setPointSize(15);
        font.setBold(true);
        font.setWeight(75);
        label_3->setFont(font);
        label_3->setStyleSheet(QString::fromUtf8("color:#282A49"));
        label_3->setAlignment(Qt::AlignCenter);
        label_4 = new QLabel(bottom);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(175, 330, 101, 31));
        label_4->setFont(font);
        label_4->setStyleSheet(QString::fromUtf8("color:#282A49"));
        label_4->setAlignment(Qt::AlignCenter);
        BackMain = new QPushButton(bottom);
        BackMain->setObjectName(QString::fromUtf8("BackMain"));
        BackMain->setGeometry(QRect(155, 740, 50, 50));
        BackMain->setStyleSheet(QString::fromUtf8("max-width:50px;\n"
" max-height:50px;\n"
" min-width:50px;\n"
" min-height:50px;\n"
"border-radius:25px;\n"
"background-color: white;\n"
" border-style: solid;"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/Main/Air/Back.png"), QSize(), QIcon::Normal, QIcon::Off);
        BackMain->setIcon(icon);
        BackMain->setIconSize(QSize(50, 50));
        PassTimes = new QLabel(bottom);
        PassTimes->setObjectName(QString::fromUtf8("PassTimes"));
        PassTimes->setGeometry(QRect(75, 60, 211, 211));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Adobe \351\273\221\344\275\223 Std R"));
        font1.setPointSize(120);
        PassTimes->setFont(font1);
        PassTimes->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(bottom);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(65, 280, 100, 100));
        frame = new QFrame(bottom);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(50, 410, 261, 321));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        OpenDoor = new QPushButton(frame);
        OpenDoor->setObjectName(QString::fromUtf8("OpenDoor"));
        OpenDoor->setGeometry(QRect(40, 40, 181, 81));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Adobe \351\273\221\344\275\223 Std R"));
        font2.setPointSize(15);
        OpenDoor->setFont(font2);
        OpenDoor->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	border-radius:15px;\n"
"	background:#FFFFFF;\n"
"}"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/C:/Users/Alumer/Desktop/SystemOp.png"), QSize(), QIcon::Normal, QIcon::Off);
        OpenDoor->setIcon(icon1);
        OpenDoor->setIconSize(QSize(100, 50));
        OpenDoor->setCheckable(true);
        OpenDoor->setChecked(true);
        OpenDoor->setAutoExclusive(true);
        CloseDoor = new QPushButton(frame);
        CloseDoor->setObjectName(QString::fromUtf8("CloseDoor"));
        CloseDoor->setGeometry(QRect(40, 190, 181, 81));
        CloseDoor->setFont(font2);
        CloseDoor->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	border-radius:15px;\n"
"	background:#FFFFFF;\n"
"}"));
        CloseDoor->setIcon(icon1);
        CloseDoor->setIconSize(QSize(100, 50));

        retranslateUi(DoorSystem);

        QMetaObject::connectSlotsByName(DoorSystem);
    } // setupUi

    void retranslateUi(QDialog *DoorSystem)
    {
        DoorSystem->setWindowTitle(QCoreApplication::translate("DoorSystem", "Dialog", nullptr));
        label_3->setText(QCoreApplication::translate("DoorSystem", "\345\256\211\345\205\250\346\211\253\346\217\217", nullptr));
        label_4->setText(QCoreApplication::translate("DoorSystem", "\351\200\232\350\277\207\344\272\272\346\225\260", nullptr));
        BackMain->setText(QString());
        PassTimes->setText(QCoreApplication::translate("DoorSystem", "33", nullptr));
        label_2->setText(QCoreApplication::translate("DoorSystem", "TextLabel", nullptr));
        OpenDoor->setText(QCoreApplication::translate("DoorSystem", "s", nullptr));
        CloseDoor->setText(QCoreApplication::translate("DoorSystem", "s", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DoorSystem: public Ui_DoorSystem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DOORSYSTEM_H
