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
    QGroupBox *TempGroupBox;
    QLabel *InHum;
    QLabel *label_14;
    QLabel *HumiP;
    QLabel *label_16;
    QLabel *SystemScore;
    QLabel *label;
    QGroupBox *HumidityGroupBox;
    QLabel *LuxP;
    QLabel *label_18;
    QLabel *label_19;
    QLabel *InBrightness;
    QLabel *label_21;
    QGroupBox *Pm25GroupBox;
    QLabel *TempP;
    QLabel *InTemp;
    QLabel *label_11;
    QLabel *label_12;
    QPushButton *HouseIntelligence;
    QGroupBox *LuxGroupBox;
    QLabel *Pm25P;
    QLabel *label_23;
    QLabel *label_24;
    QLabel *InPm25;
    QLabel *label_2;
    QGroupBox *WhiteGroupBox;
    QGroupBox *WhiteGroupBox2;
    QGroupBox *WhiteGroupBox3;
    QGroupBox *WhiteGroupBox4;
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
        SystemOptimization->setGeometry(QRect(140, 990, 181, 51));
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
        label_4->setGeometry(QRect(470, 850, 91, 91));
        TempGroupBox = new QGroupBox(Main);
        TempGroupBox->setObjectName(QStringLiteral("TempGroupBox"));
        TempGroupBox->setGeometry(QRect(1200, 420, 111, 451));
        TempGroupBox->setStyleSheet(QLatin1String("QGroupBox#TempGroupBox\n"
"{\n"
"	border-radius:8px;\n"
"	background:#FFFFFF;\n"
"}"));
        InHum = new QLabel(TempGroupBox);
        InHum->setObjectName(QStringLiteral("InHum"));
        InHum->setGeometry(QRect(10, 140, 91, 81));
        QFont font1;
        font1.setPointSize(55);
        font1.setBold(true);
        font1.setWeight(75);
        InHum->setFont(font1);
        InHum->setAlignment(Qt::AlignCenter);
        label_14 = new QLabel(TempGroupBox);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(10, 350, 91, 81));
        QFont font2;
        font2.setPointSize(20);
        font2.setBold(true);
        font2.setWeight(75);
        label_14->setFont(font2);
        label_14->setAlignment(Qt::AlignCenter);
        HumiP = new QLabel(TempGroupBox);
        HumiP->setObjectName(QStringLiteral("HumiP"));
        HumiP->setGeometry(QRect(15, 20, 81, 91));
        HumiP->setAlignment(Qt::AlignCenter);
        label_16 = new QLabel(TempGroupBox);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(10, 260, 91, 81));
        QFont font3;
        font3.setPointSize(18);
        font3.setBold(true);
        font3.setWeight(75);
        label_16->setFont(font3);
        label_16->setAlignment(Qt::AlignCenter);
        SystemScore = new QLabel(Main);
        SystemScore->setObjectName(QStringLiteral("SystemScore"));
        SystemScore->setGeometry(QRect(60, 300, 671, 481));
        QFont font4;
        font4.setFamily(QString::fromUtf8("Adobe \351\273\221\344\275\223 Std R"));
        font4.setPointSize(420);
        SystemScore->setFont(font4);
        SystemScore->setStyleSheet(QStringLiteral("color:#282A49"));
        SystemScore->setAlignment(Qt::AlignCenter);
        label = new QLabel(Main);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(140, 850, 261, 41));
        QFont font5;
        font5.setFamily(QString::fromUtf8("Adobe \351\273\221\344\275\223 Std R"));
        font5.setPointSize(30);
        font5.setBold(true);
        font5.setWeight(75);
        label->setFont(font5);
        HumidityGroupBox = new QGroupBox(Main);
        HumidityGroupBox->setObjectName(QStringLiteral("HumidityGroupBox"));
        HumidityGroupBox->setGeometry(QRect(1460, 180, 111, 451));
        HumidityGroupBox->setStyleSheet(QLatin1String("QGroupBox#HumidityGroupBox\n"
"{\n"
"	border-radius:8px;\n"
"	background:#FFFFFF;\n"
"}"));
        LuxP = new QLabel(HumidityGroupBox);
        LuxP->setObjectName(QStringLiteral("LuxP"));
        LuxP->setGeometry(QRect(15, 20, 81, 91));
        LuxP->setAlignment(Qt::AlignCenter);
        label_18 = new QLabel(HumidityGroupBox);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setGeometry(QRect(10, 290, 91, 81));
        label_18->setFont(font3);
        label_18->setAlignment(Qt::AlignCenter);
        label_19 = new QLabel(HumidityGroupBox);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setGeometry(QRect(10, 370, 91, 81));
        QFont font6;
        font6.setPointSize(15);
        font6.setBold(true);
        font6.setWeight(75);
        label_19->setFont(font6);
        label_19->setAlignment(Qt::AlignCenter);
        InBrightness = new QLabel(HumidityGroupBox);
        InBrightness->setObjectName(QStringLiteral("InBrightness"));
        InBrightness->setGeometry(QRect(10, 200, 91, 81));
        InBrightness->setFont(font1);
        InBrightness->setAlignment(Qt::AlignCenter);
        label_21 = new QLabel(HumidityGroupBox);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setGeometry(QRect(10, 110, 91, 81));
        label_21->setFont(font6);
        label_21->setAlignment(Qt::AlignCenter);
        Pm25GroupBox = new QGroupBox(Main);
        Pm25GroupBox->setObjectName(QStringLiteral("Pm25GroupBox"));
        Pm25GroupBox->setGeometry(QRect(950, 120, 111, 451));
        Pm25GroupBox->setStyleSheet(QLatin1String("QGroupBox#Pm25GroupBox\n"
"{\n"
"	border-radius:8px;\n"
"	background:#FFFFFF;\n"
"}"));
        TempP = new QLabel(Pm25GroupBox);
        TempP->setObjectName(QStringLiteral("TempP"));
        TempP->setGeometry(QRect(15, 30, 81, 91));
        TempP->setAlignment(Qt::AlignCenter);
        InTemp = new QLabel(Pm25GroupBox);
        InTemp->setObjectName(QStringLiteral("InTemp"));
        InTemp->setGeometry(QRect(10, 150, 91, 81));
        InTemp->setFont(font1);
        InTemp->setAlignment(Qt::AlignCenter);
        label_11 = new QLabel(Pm25GroupBox);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(10, 270, 91, 81));
        label_11->setFont(font3);
        label_11->setAlignment(Qt::AlignCenter);
        label_12 = new QLabel(Pm25GroupBox);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(10, 360, 91, 81));
        label_12->setFont(font2);
        label_12->setAlignment(Qt::AlignCenter);
        HouseIntelligence = new QPushButton(Main);
        HouseIntelligence->setObjectName(QStringLiteral("HouseIntelligence"));
        HouseIntelligence->setGeometry(QRect(430, 990, 181, 51));
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
        LuxGroupBox->setGeometry(QRect(1710, 390, 111, 451));
        LuxGroupBox->setStyleSheet(QLatin1String("QGroupBox#LuxGroupBox\n"
"{\n"
"	border-radius:8px;\n"
"	background:#FFFFFF;\n"
"}"));
        Pm25P = new QLabel(LuxGroupBox);
        Pm25P->setObjectName(QStringLiteral("Pm25P"));
        Pm25P->setGeometry(QRect(15, 30, 81, 91));
        Pm25P->setAlignment(Qt::AlignCenter);
        label_23 = new QLabel(LuxGroupBox);
        label_23->setObjectName(QStringLiteral("label_23"));
        label_23->setGeometry(QRect(10, 270, 91, 81));
        label_23->setFont(font3);
        label_23->setAlignment(Qt::AlignCenter);
        label_24 = new QLabel(LuxGroupBox);
        label_24->setObjectName(QStringLiteral("label_24"));
        label_24->setGeometry(QRect(10, 360, 91, 81));
        label_24->setFont(font2);
        label_24->setAlignment(Qt::AlignCenter);
        InPm25 = new QLabel(LuxGroupBox);
        InPm25->setObjectName(QStringLiteral("InPm25"));
        InPm25->setGeometry(QRect(10, 150, 91, 81));
        InPm25->setFont(font1);
        InPm25->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(Main);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(140, 910, 271, 41));
        QFont font7;
        font7.setFamily(QString::fromUtf8("Adobe \351\273\221\344\275\223 Std R"));
        font7.setPointSize(15);
        font7.setBold(true);
        font7.setWeight(75);
        label_2->setFont(font7);
        label_2->setStyleSheet(QStringLiteral("color:#282A49"));
        WhiteGroupBox = new QGroupBox(Main);
        WhiteGroupBox->setObjectName(QStringLiteral("WhiteGroupBox"));
        WhiteGroupBox->setGeometry(QRect(950, 610, 111, 51));
        WhiteGroupBox->setStyleSheet(QLatin1String("QGroupBox#WhiteGroupBox\n"
"{\n"
"	border-radius:8px;\n"
"	background:#FFFFFF;\n"
"}"));
        WhiteGroupBox2 = new QGroupBox(Main);
        WhiteGroupBox2->setObjectName(QStringLiteral("WhiteGroupBox2"));
        WhiteGroupBox2->setGeometry(QRect(1200, 330, 111, 51));
        WhiteGroupBox2->setStyleSheet(QLatin1String("QGroupBox#WhiteGroupBox2\n"
"{\n"
"	border-radius:8px;\n"
"	background:#FFFFFF;\n"
"}"));
        WhiteGroupBox3 = new QGroupBox(Main);
        WhiteGroupBox3->setObjectName(QStringLiteral("WhiteGroupBox3"));
        WhiteGroupBox3->setGeometry(QRect(1460, 670, 111, 51));
        WhiteGroupBox3->setStyleSheet(QLatin1String("QGroupBox#WhiteGroupBox3\n"
"{\n"
"	border-radius:8px;\n"
"	background:#FFFFFF;\n"
"}"));
        WhiteGroupBox4 = new QGroupBox(Main);
        WhiteGroupBox4->setObjectName(QStringLiteral("WhiteGroupBox4"));
        WhiteGroupBox4->setGeometry(QRect(1710, 300, 111, 51));
        WhiteGroupBox4->setStyleSheet(QLatin1String("QGroupBox#WhiteGroupBox4\n"
"{\n"
"	border-radius:8px;\n"
"	background:#FFFFFF;\n"
"}"));
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
        label_8->setFont(font7);
        label_8->setStyleSheet(QStringLiteral("color:#282A49"));
        label_7 = new QLabel(group);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(340, 770, 271, 41));
        label_7->setFont(font7);
        label_7->setStyleSheet(QStringLiteral("color:#282A49"));
        label_6 = new QLabel(group);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(330, 650, 261, 41));
        label_6->setFont(font5);
        label_5 = new QLabel(group);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(330, 710, 271, 41));
        label_5->setFont(font7);
        label_5->setStyleSheet(QStringLiteral("color:#282A49"));
        label_9 = new QLabel(group);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(210, 800, 121, 41));
        label_9->setFont(font7);
        label_9->setStyleSheet(QStringLiteral("color:#282A49"));
        SystemScore_ControlPage = new QLabel(group);
        SystemScore_ControlPage->setObjectName(QStringLiteral("SystemScore_ControlPage"));
        SystemScore_ControlPage->setGeometry(QRect(0, 20, 761, 611));
        QFont font8;
        font8.setFamily(QString::fromUtf8("Adobe \351\273\221\344\275\223 Std R"));
        font8.setPointSize(500);
        SystemScore_ControlPage->setFont(font8);
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
        GoMain->setGeometry(QRect(5, 480, 100, 100));
        GoMain->setStyleSheet(QLatin1String("max-width:100px;\n"
" max-height:100px;\n"
" min-width:100px;\n"
" min-height:100px;\n"
"border-radius:50px;\n"
"background-color: white;\n"
" border-style: solid;"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/new/Main/Main/Home.png"), QSize(), QIcon::Normal, QIcon::Off);
        GoMain->setIcon(icon2);
        GoMain->setIconSize(QSize(70, 70));
        ButtonBox = new QGroupBox(ControlPage);
        ButtonBox->setObjectName(QStringLiteral("ButtonBox"));
        ButtonBox->setGeometry(QRect(250, 30, 731, 1031));
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
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/new/Main/Main/DoorPage.png"), QSize(), QIcon::Normal, QIcon::Off);
        DoorSystem->setIcon(icon3);
        DoorSystem->setIconSize(QSize(90, 90));
        LightSystem = new QPushButton(ButtonBox);
        LightSystem->setObjectName(QStringLiteral("LightSystem"));
        LightSystem->setGeometry(QRect(430, 320, 251, 153));
        LightSystem->setFont(font);
        LightSystem->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	border-radius:15px;\n"
"	background:#FFFFFF;\n"
"}"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/new/Main/Main/LightPage.png"), QSize(), QIcon::Normal, QIcon::Off);
        LightSystem->setIcon(icon4);
        LightSystem->setIconSize(QSize(100, 100));
        AIControlPage = new QPushButton(ButtonBox);
        AIControlPage->setObjectName(QStringLiteral("AIControlPage"));
        AIControlPage->setGeometry(QRect(60, 840, 621, 131));
        AIControlPage->setFont(font);
        AIControlPage->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	border-radius:15px;\n"
"	background:#FFFFFF;\n"
"}"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/new/Led/Led/AI_ON.png"), QSize(), QIcon::Normal, QIcon::Off);
        AIControlPage->setIcon(icon5);
        AIControlPage->setIconSize(QSize(90, 100));
        AirSystem = new QPushButton(ButtonBox);
        AirSystem->setObjectName(QStringLiteral("AirSystem"));
        AirSystem->setGeometry(QRect(60, 590, 251, 153));
        AirSystem->setFont(font);
        AirSystem->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	border-radius:15px;\n"
"	background:#FFFFFF;\n"
"}"));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/new/Main/Main/AirPage.png"), QSize(), QIcon::Normal, QIcon::Off);
        AirSystem->setIcon(icon6);
        AirSystem->setIconSize(QSize(100, 100));
        WindowSystem = new QPushButton(ButtonBox);
        WindowSystem->setObjectName(QStringLiteral("WindowSystem"));
        WindowSystem->setGeometry(QRect(430, 590, 251, 153));
        WindowSystem->setFont(font);
        WindowSystem->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	border-radius:15px;\n"
"	background:#FFFFFF;\n"
"}"));
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/new/Window/Window/Close.png"), QSize(), QIcon::Normal, QIcon::Off);
        WindowSystem->setIcon(icon7);
        WindowSystem->setIconSize(QSize(100, 100));
        WindSystem = new QPushButton(ButtonBox);
        WindSystem->setObjectName(QStringLiteral("WindSystem"));
        WindSystem->setGeometry(QRect(60, 320, 251, 153));
        WindSystem->setFont(font);
        WindSystem->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	border-radius:15px;\n"
"	background:#FFFFFF;\n"
"}"));
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/new/Wind/Wind/High_OFF.png"), QSize(), QIcon::Normal, QIcon::Off);
        WindSystem->setIcon(icon8);
        WindSystem->setIconSize(QSize(80, 100));
        CurtainSystem = new QPushButton(ButtonBox);
        CurtainSystem->setObjectName(QStringLiteral("CurtainSystem"));
        CurtainSystem->setGeometry(QRect(60, 50, 251, 153));
        CurtainSystem->setFont(font);
        CurtainSystem->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	border-radius:15px;\n"
"	background:#FFFFFF;\n"
"}"));
        QIcon icon9;
        icon9.addFile(QStringLiteral(":/new/Main/Main/CurtainsPage.png"), QSize(), QIcon::Normal, QIcon::Off);
        CurtainSystem->setIcon(icon9);
        CurtainSystem->setIconSize(QSize(80, 80));
        Bottom->addWidget(ControlPage);

        retranslateUi(frmMain);

        Bottom->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(frmMain);
    } // setupUi

    void retranslateUi(QWidget *frmMain)
    {
        frmMain->setWindowTitle(QApplication::translate("frmMain", "Form", nullptr));
        SystemOptimization->setText(QApplication::translate("frmMain", " \344\270\200 \351\224\256 \344\274\230 \345\214\226", nullptr));
        label_4->setText(QApplication::translate("frmMain", "TextLabel", nullptr));
        TempGroupBox->setTitle(QString());
        InHum->setText(QApplication::translate("frmMain", "60", nullptr));
        label_14->setText(QApplication::translate("frmMain", "%", nullptr));
        HumiP->setText(QApplication::translate("frmMain", "HumiP", nullptr));
        label_16->setText(QApplication::translate("frmMain", "\347\233\270 \345\257\271\n"
"\346\271\277 \345\272\246", nullptr));
        SystemScore->setText(QApplication::translate("frmMain", "47", nullptr));
        label->setStyleSheet(QApplication::translate("frmMain", "color:#282A49", nullptr));
        label->setText(QApplication::translate("frmMain", "\347\263\273\347\273\237\345\201\245\345\272\267\350\257\204\345\210\206", nullptr));
        HumidityGroupBox->setTitle(QString());
        LuxP->setText(QApplication::translate("frmMain", "LuxP", nullptr));
        label_18->setText(QApplication::translate("frmMain", "\344\272\256 \345\272\246", nullptr));
        label_19->setText(QApplication::translate("frmMain", "Lux", nullptr));
        InBrightness->setText(QApplication::translate("frmMain", "00", nullptr));
        label_21->setText(QApplication::translate("frmMain", "Lv1", nullptr));
        Pm25GroupBox->setTitle(QString());
        TempP->setText(QApplication::translate("frmMain", "TemP", nullptr));
        InTemp->setText(QApplication::translate("frmMain", "23", nullptr));
        label_11->setText(QApplication::translate("frmMain", "\345\256\244 \345\206\205\n"
"\346\270\251 \345\272\246", nullptr));
        label_12->setText(QApplication::translate("frmMain", "\302\260C", nullptr));
        HouseIntelligence->setText(QApplication::translate("frmMain", " \345\205\250 \345\261\213 \346\231\272 \350\203\275", nullptr));
        LuxGroupBox->setTitle(QString());
        Pm25P->setText(QApplication::translate("frmMain", "Pm2.5P", nullptr));
        label_23->setText(QApplication::translate("frmMain", "\351\242\227 \347\262\222\n"
"\346\265\223 \345\272\246", nullptr));
        label_24->setText(QApplication::translate("frmMain", "%", nullptr));
        InPm25->setText(QApplication::translate("frmMain", "24", nullptr));
        label_2->setText(QApplication::translate("frmMain", "\350\257\204\344\273\267\347\263\273\347\273\237\345\275\223\345\211\215\347\232\204\350\200\227\350\203\275\344\270\216\345\256\211\345\205\250", nullptr));
        WhiteGroupBox->setTitle(QString());
        WhiteGroupBox2->setTitle(QString());
        WhiteGroupBox3->setTitle(QString());
        WhiteGroupBox4->setTitle(QString());
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
        GoMain->setText(QString());
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
