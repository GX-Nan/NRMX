#ifndef LIGHTSYSTEM_H
#define LIGHTSYSTEM_H

#include <QDialog>
#include <QLabel>
#include <QDebug>

class Status{

private:
    int Color=0;
    int Lux=0;
    int Station=0;
    QMap<QString,QString> MessageLight;
public:
    Status(){
        MessageLight.insert("SpotBar1","0");
        MessageLight.insert("SpotBar2","0");
        MessageLight.insert("LedBar1","0");
        MessageLight.insert("LedBar2","0");
        MessageLight.insert("SpotOffice1","0");
        MessageLight.insert("SpotOffice2","0");
        MessageLight.insert("LedOffice1","0");
        MessageLight.insert("LedOffice2","0");
        MessageLight.insert("SpotMeet1","0");
        MessageLight.insert("SpotMeet2","0");
        MessageLight.insert("LedMeet1","0");
        MessageLight.insert("LedMeet2","0");
        MessageLight.insert("Chandelier1","0");
        MessageLight.insert("Chandelier2","0");
    }
    ~Status(){

    }
    void SetColor(int color)
    {
        this->Color=color;
    }
    void SetLux(int lux)
    {
        this->Lux=lux;
    }
    void SetStation(int Station)
    {
        this->Station=Station;
    }
    int GetLux()
    {
        return Lux;
    }
    int GetColor()
    {
        return  Color;
    }
    int GetStation()
    {
        return  Station;
    }
    void InsertMessage(QString Key,QString Value){
        MessageLight.insert(Key,Value);
    }
    QString GetMessage(QString Key){
        return MessageLight.value(Key);
    }
    void RemoveMessage(QString Key){
        MessageLight.remove(Key);
    }
};

Q_DECLARE_METATYPE(Status);

namespace Ui {
class LightSystem;
}

class LightSystem : public QDialog
{
    Q_OBJECT

public:
    explicit LightSystem(QWidget *parent = nullptr);
    ~LightSystem();
    void Shawdow();
    void Switch_Ifconfig();
    void XprogressbarIfconfig();
    int AiMode_Falg=0;
    QMap<int,Status>data;
    Status status;
    int LuxFalg=-1;
    int ColorFalg=-1;
    int AllLight_Status=0;
    int AllSpot_Status=0;
    int AllLed_Status=0;
    int SpotStopFalg=0;
    int LedStopFlag=0;
signals:
    void SendClose();
    void RadioBroadcast(QString);
    void SendToWx(QString,int);
private slots:
    void on_BackMain_clicked();
    void ButtonStyle_Label(QLabel* Name,int Offset,int BlurRadius);
    void ButtonStyle_Button(QPushButton* Name,int Offset,int BlurRadius);
    void on_Brightness_Slider_valueChanged(int value);
    void on_Color_Slider_valueChanged(int value);
    void Trigger_BrightnessQslider();
    void Trigger_ColorQslider();
    void Trigger_DeviceQslider();
    void on_AllLed_Status_clicked();
    void on_AiMode_clicked();
    void InstructionSet(int Function, int Value);
    void Light_Init();
    void on_Device_Slider_valueChanged(int value);
    void Light_Switch(int Falg);
    void Image_Init();
    void SpotInstructionSet(int,int);
    void LedInstructionSet(int,int);


    void on_LedChoice_clicked();
    void on_SpotChoice_clicked();
    void on_ChandChoice_clicked();
    void on_ChandeDown2_clicked();
    void on_ChandeStop2_clicked();
    void on_ChandeUp2_clicked();
    void on_ChandelierSwitch2_clicked();
    void ButtonStyle_Chandelier_1(QString Name,int Falg);
    void ButtonStyle_Chandelier_2(QString Name,int Falg);
    void on_ChandeDown1_clicked();
    void on_ChandeStop1_clicked();
    void on_ChandeUp1_clicked();
    void on_ChandelierSwitch1_clicked();

    void on_SpotMeet1_clicked();

    void on_SpotMeet2_clicked();

    void on_SpotOffice1_clicked();

    void on_SpotOffice2_clicked();

    void on_SpotBar1_clicked();

    void on_SpotBar2_clicked();

    void on_LedMeet1_clicked();

    void on_LedMeet2_clicked();

    void on_LedBar1_clicked();

    void on_LedBar2_clicked();

    void on_LedOffice1_clicked();

    void on_LedOffice2_clicked();

    void on_LedAll_clicked();

    void on_SpotAll_clicked();

public slots:
    void Light_Status(int Function,int Sub,int Value);

private:
    Ui::LightSystem *ui;
};

#endif // LIGHTSYSTEM_H
