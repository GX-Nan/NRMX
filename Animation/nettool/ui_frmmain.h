/********************************************************************************
** Form generated from reading UI file 'frmmain.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRMMAIN_H
#define UI_FRMMAIN_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_frmMain
{
public:
    QStackedWidget *Bottom;
    QWidget *Main;
    QPushButton *SystemOptimization;
    QLabel *label_4;
    QPushButton *UISreachIP;
    QGroupBox *TempGroupBox;
    QPushButton *Server;
    QLabel *SystemScore;
    QLabel *label;
    QGroupBox *HumidityGroupBox;
    QGroupBox *Pm25GroupBox;
    QPushButton *HouseIntelligence;
    QGroupBox *LuxGroupBox;
    QLabel *label_2;
    QWidget *ControlPage;
    QGroupBox *group;
    QLabel *label_8;
    QLabel *label_7;
    QLabel *label_6;
    QLabel *label_5;
    QLabel *label_9;
    QLabel *SystemScore_ControlPage;
    QGroupBox *groupBox;
    QPushButton *GoMain;
    QPushButton *GoControlPage;
    QGroupBox *ButtonBox;
    QPushButton *DoorSystem;
    QPushButton *LightSystem;
    QPushButton *AIControlPage;
    QPushButton *AirSystem;
    QPushButton *WindowSystem;
    QPushButton *WindSystem;
    QPushButton *CurtainSystem;

    void setupUi(QWidget *frmMain)
    {
        if (frmMain->objectName().isEmpty())
            frmMain->setObjectName(QStringLiteral("frmMain"));
        frmMain->resize(1920, 1080);
        frmMain->setStyleSheet(QLatin1String("QWidget#frmMain{\n"
"	background:white;\n"
"}"));
        Bottom = new QStackedWidget(frmMain);
        Bottom->setObjectName(QStringLiteral("Bottom"));
        Bottom->setGeometry(QRect(0, 0, 1921, 1111));
        Main = new QWidget();
        Main->setObjectName(QStringLiteral("Main"));
        SystemOptimization = new QPushButton(Main);
        SystemOptimization->setObjectName(QStringLiteral("SystemOptimization"));
        SystemOptimization->setGeometry(QRect(110, 990, 181, 51));
        QFont font;
        font.setFamily(QString::fromUtf8("Adobe \351\273\221\344\275\223 Std R"));
        font.setPointSize(15);
        SystemOptimization->setFont(font);
        SystemOptimization->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	border-radius:8px;\n"
"	background:#FFFFFF;\n"
"}"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/C:/Users/Alumer/Desktop/SystemOp.png"), QSize(), QIcon::Normal, QIcon::Off);
        SystemOptimization->setIcon(icon);
        SystemOptimization->setIconSize(QSize(100, 50));
        label_4 = new QLabel(Main);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(440, 850, 91, 91));
        UISreachIP = new QPushButton(Main);
        UISreachIP->setObjectName(QStringLiteral("UISreachIP"));
        UISreachIP->setGeometry(QRect(60, 40, 101, 31));
        TempGroupBox = new QGroupBox(Main);
        TempGroupBox->setObjectName(QStringLiteral("TempGroupBox"));
        TempGroupBox->setGeometry(QRect(1200, 420, 111, 451));
        TempGroupBox->setStyleSheet(QLatin1String("QGroupBox#TempGroupBox\n"
"{\n"
"	border-radius:8px;\n"
"	background:#FFFFFF;\n"
"}"));
        Server = new QPushButton(Main);
        Server->setObjectName(QStringLiteral("Server"));
        Server->setGeometry(QRect(60, 90, 101, 31));
        SystemScore = new QLabel(Main);
        SystemScore->setObjectName(QStringLiteral("SystemScore"));
        SystemScore->setGeometry(QRect(30, 340, 671, 481));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Adobe \351\273\221\344\275\223 Std R"));
        font1.setPointSize(420);
        SystemScore->setFont(font1);
        SystemScore->setStyleSheet(QStringLiteral("color:#282A49"));
        SystemScore->setAlignment(Qt::AlignCenter);
        label = new QLabel(Main);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(110, 850, 261, 41));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Adobe \351\273\221\344\275\223 Std R"));
        font2.setPointSize(30);
        font2.setBold(true);
        font2.setWeight(75);
        label->setFont(font2);
        HumidityGroupBox = new QGroupBox(Main);
        HumidityGroupBox->setObjectName(QStringLiteral("HumidityGroupBox"));
        HumidityGroupBox->setGeometry(QRect(1460, 180, 111, 451));
        HumidityGroupBox->setStyleSheet(QLatin1String("QGroupBox#HumidityGroupBox\n"
"{\n"
"	border-radius:8px;\n"
"	background:#FFFFFF;\n"
"}"));
        Pm25GroupBox = new QGroupBox(Main);
        Pm25GroupBox->setObjectName(QStringLiteral("Pm25GroupBox"));
        Pm25GroupBox->setGeometry(QRect(950, 120, 111, 451));
        Pm25GroupBox->setStyleSheet(QLatin1String("QGroupBox#Pm25GroupBox\n"
"{\n"
"	border-radius:8px;\n"
"	background:#FFFFFF;\n"
"}"));
        HouseIntelligence = new QPushButton(Main);
        HouseIntelligence->setObjectName(QStringLiteral("HouseIntelligence"));
        HouseIntelligence->setGeometry(QRect(400, 990, 181, 51));
        HouseIntelligence->setFont(font);
        HouseIntelligence->setStyleSheet(QLatin1String("QPushButton#HouseIntelligence\n"
"{\n"
"	border-radius:8px;\n"
"	background:#FFFFFF\n"
"}"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/C:/Users/Alumer/Desktop/AI (2).png"), QSize(), QIcon::Normal, QIcon::Off);
        HouseIntelligence->setIcon(icon1);
        HouseIntelligence->setIconSize(QSize(50, 50));
        LuxGroupBox = new QGroupBox(Main);
        LuxGroupBox->setObjectName(QStringLiteral("LuxGroupBox"));
        LuxGroupBox->setGeometry(QRect(1710, 410, 111, 451));
        LuxGroupBox->setStyleSheet(QLatin1String("QGroupBox#LuxGroupBox\n"
"{\n"
"	border-radius:8px;\n"
"	background:#FFFFFF;\n"
"}"));
        label_2 = new QLabel(Main);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(110, 910, 271, 41));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Adobe \351\273\221\344\275\223 Std R"));
        font3.setPointSize(15);
        font3.setBold(true);
        font3.setWeight(75);
        label_2->setFont(font3);
        label_2->setStyleSheet(QStringLiteral("color:#282A49"));
        Bottom->addWidget(Main);
        ControlPage = new QWidget();
        ControlPage->setObjectName(QStringLiteral("ControlPage"));
        group = new QGroupBox(ControlPage);
        group->setObjectName(QStringLiteral("group"));
        group->setGeometry(QRect(1130, 160, 741, 851));
        group->setStyleSheet(QStringLiteral("border:none"));
        label_8 = new QLabel(group);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(80, 800, 121, 41));
        label_8->setFont(font3);
        label_8->setStyleSheet(QStringLiteral("color:#282A49"));
        label_7 = new QLabel(group);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(340, 770, 271, 41));
        label_7->setFont(font3);
        label_7->setStyleSheet(QStringLiteral("color:#282A49"));
        label_6 = new QLabel(group);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(330, 650, 261, 41));
        label_6->setFont(font2);
        label_5 = new QLabel(group);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(330, 710, 271, 41));
        label_5->setFont(font3);
        label_5->setStyleSheet(QStringLiteral("color:#282A49"));
        label_9 = new QLabel(group);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(210, 800, 121, 41));
        label_9->setFont(font3);
        label_9->setStyleSheet(QStringLiteral("color:#282A49"));
        SystemScore_ControlPage = new QLabel(group);
        SystemScore_ControlPage->setObjectName(QStringLiteral("SystemScore_ControlPage"));
        SystemScore_ControlPage->setGeometry(QRect(0, 20, 761, 611));
        QFont font4;
        font4.setFamily(QString::fromUtf8("Adobe \351\273\221\344\275\223 Std R"));
        font4.setPointSize(500);
        SystemScore_ControlPage->setFont(font4);
        SystemScore_ControlPage->setStyleSheet(QStringLiteral("color:#282A49"));
        SystemScore_ControlPage->setAlignment(Qt::AlignCenter);
        groupBox = new QGroupBox(ControlPage);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(0, 0, 111, 1081));
        groupBox->setStyleSheet(QLatin1String("QGroupBox#groupBox{\n"
"	border:none;\n"
"	background-color:#282A49;\n"
"	border-radius:15px;\n"
"}"));
        GoMain = new QPushButton(groupBox);
        GoMain->setObjectName(QStringLiteral("GoMain"));
        GoMain->setGeometry(QRect(5, 220, 100, 100));
        GoMain->setStyleSheet(QLatin1String("max-width:100px;\n"
" max-height:100px;\n"
" min-width:100px;\n"
" min-height:100px;\n"
"border-radius:50px;\n"
"background-color: white;\n"
" border-style: solid;"));
        GoControlPage = new QPushButton(groupBox);
        GoControlPage->setObjectName(QStringLiteral("GoControlPage"));
        GoControlPage->setGeometry(QRect(5, 650, 100, 100));
        GoControlPage->setStyleSheet(QLatin1String("max-width:100px;\n"
" max-height:100px;\n"
" min-width:100px;\n"
" min-height:100px;\n"
"border-radius:50px;\n"
"background-color: white;\n"
" border-style: solid;"));
        ButtonBox = new QGroupBox(ControlPage);
        ButtonBox->setObjectName(QStringLiteral("ButtonBox"));
        ButtonBox->setGeometry(QRect(250, 30, 731, 1001));
        ButtonBox->setContextMenuPolicy(Qt::PreventContextMenu);
        ButtonBox->setStyleSheet(QLatin1String("QGroupBox#ButtonBox{\n"
"	border:none;\n"
"}"));
        DoorSystem = new QPushButton(ButtonBox);
        DoorSystem->setObjectName(QStringLiteral("DoorSystem"));
        DoorSystem->setGeometry(QRect(430, 50, 251, 153));
        DoorSystem->setFont(font);
        DoorSystem->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	border-radius:15px;\n"
"	background:#FFFFFF;\n"
"}"));
        DoorSystem->setIcon(icon);
        DoorSystem->setIconSize(QSize(100, 50));
        LightSystem = new QPushButton(ButtonBox);
        LightSystem->setObjectName(QStringLiteral("LightSystem"));
        LightSystem->setGeometry(QRect(430, 320, 251, 153));
        LightSystem->setFont(font);
        LightSystem->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	border-radius:15px;\n"
"	background:#FFFFFF;\n"
"}"));
        LightSystem->setIcon(icon);
        LightSystem->setIconSize(QSize(100, 50));
        AIControlPage = new QPushButton(ButtonBox);
        AIControlPage->setObjectName(QStringLiteral("AIControlPage"));
        AIControlPage->setGeometry(QRect(60, 840, 621, 131));
        AIControlPage->setFont(font);
        AIControlPage->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	border-radius:15px;\n"
"	background:#FFFFFF;\n"
"}"));
        AIControlPage->setIcon(icon);
        AIControlPage->setIconSize(QSize(100, 50));
        AirSystem = new QPushButton(ButtonBox);
        AirSystem->setObjectName(QStringLiteral("AirSystem"));
        AirSystem->setGeometry(QRect(60, 590, 251, 153));
        AirSystem->setFont(font);
        AirSystem->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	border-radius:15px;\n"
"	background:#FFFFFF;\n"
"}"));
        AirSystem->setIcon(icon);
        AirSystem->setIconSize(QSize(100, 50));
        WindowSystem = new QPushButton(ButtonBox);
        WindowSystem->setObjectName(QStringLiteral("WindowSystem"));
        WindowSystem->setGeometry(QRect(430, 590, 251, 153));
        WindowSystem->setFont(font);
        WindowSystem->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	border-radius:15px;\n"
"	background:#FFFFFF;\n"
"}"));
        WindowSystem->setIcon(icon);
        WindowSystem->setIconSize(QSize(100, 50));
        WindSystem = new QPushButton(ButtonBox);
        WindSystem->setObjectName(QStringLiteral("WindSystem"));
        WindSystem->setGeometry(QRect(60, 320, 251, 153));
        WindSystem->setFont(font);
        WindSystem->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	border-radius:15px;\n"
"	background:#FFFFFF;\n"
"}"));
        WindSystem->setIcon(icon);
        WindSystem->setIconSize(QSize(100, 50));
        CurtainSystem = new QPushButton(ButtonBox);
        CurtainSystem->setObjectName(QStringLiteral("CurtainSystem"));
        CurtainSystem->setGeometry(QRect(60, 50, 251, 153));
        CurtainSystem->setFont(font);
        CurtainSystem->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	border-radius:15px;\n"
"	background:#FFFFFF;\n"
"}"));
        CurtainSystem->setIcon(icon);
        CurtainSystem->setIconSize(QSize(100, 50));
        Bottom->addWidget(ControlPage);

        retranslateUi(frmMain);

        QMetaObject::connectSlotsByName(frmMain);
    } // setupUi

    void retranslateUi(QWidget *frmMain)
    {
        frmMain->setWindowTitle(QApplication::translate("frmMain", "Form", nullptr));
        SystemOptimization->setText(QApplication::translate("frmMain", " \344\270\200 \351\224\256 \344\274\230 \345\214\226", nullptr));
        label_4->setText(QApplication::translate("frmMain", "TextLabel", nullptr));
        UISreachIP->setText(QApplication::translate("frmMain", "\345\256\242\346\210\267\347\253\257\347\225\214\351\235\242", nullptr));
        TempGroupBox->setTitle(QApplication::translate("frmMain", "s's's's", nullptr));
        Server->setText(QApplication::translate("frmMain", "\346\234\215\345\212\241\345\231\250\347\253\257", nullptr));
        SystemScore->setText(QApplication::translate("frmMain", "47", nullptr));
        label->setStyleSheet(QApplication::translate("frmMain", "color:#282A49", nullptr));
        label->setText(QApplication::translate("frmMain", "\347\263\273\347\273\237\345\201\245\345\272\267\350\257\204\345\210\206", nullptr));
        HumidityGroupBox->setTitle(QApplication::translate("frmMain", "s's's's", nullptr));
        Pm25GroupBox->setTitle(QApplication::translate("frmMain", "s's's's", nullptr));
        HouseIntelligence->setText(QApplication::translate("frmMain", " \345\205\250 \345\261\213 \346\231\272 \350\203\275", nullptr));
        LuxGroupBox->setTitle(QApplication::translate("frmMain", "s's's's", nullptr));
        label_2->setText(QApplication::translate("frmMain", "\350\257\204\344\273\267\347\263\273\347\273\237\345\275\223\345\211\215\347\232\204\350\200\227\350\203\275\344\270\216\345\256\211\345\205\250", nullptr));
        group->setTitle(QString());
        label_8->setText(QApplication::translate("frmMain", "\345\275\223\345\211\215\346\227\266\351\227\264\357\274\232", nullptr));
        label_7->setText(QApplication::translate("frmMain", "Integrated space\n"
"", nullptr));
        label_6->setStyleSheet(QApplication::translate("frmMain", "color:#282A49", nullptr));
        label_6->setText(QApplication::translate("frmMain", "\347\263\273\347\273\237\345\201\245\345\272\267\350\257\204\345\210\206", nullptr));
        label_5->setText(QApplication::translate("frmMain", "\350\257\204\344\273\267\347\263\273\347\273\237\345\275\223\345\211\215\347\232\204\350\200\227\350\203\275\344\270\216\345\256\211\345\205\250", nullptr));
        label_9->setText(QApplication::translate("frmMain", "2022.3.17", nullptr));
        SystemScore_ControlPage->setText(QApplication::translate("frmMain", "47", nullptr));
        groupBox->setTitle(QString());
        GoMain->setText(QApplication::translate("frmMain", "Main", nullptr));
        GoControlPage->setText(QApplication::translate("frmMain", "Control", nullptr));
        ButtonBox->setTitle(QString());
        DoorSystem->setText(QString());
        LightSystem->setText(QString());
        AIControlPage->setText(QString());
        AirSystem->setText(QString());
        WindowSystem->setText(QString());
        WindSystem->setText(QString());
        CurtainSystem->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class frmMain: public Ui_frmMain {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRMMAIN_H
