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
public:
    void SetColor(int color)
    {
        this->Color=color;
    };
    void SetLux(int lux)
    {
        this->Lux=lux;
    };
    void SetStation(int Station)
    {
        this->Station=Station;
    };
    int GetLux()
    {
        return Lux;
    };
    int GetColor()
    {
        return  Color;
    }
    int GetStation()
    {
        return  Station;
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
signals:
    void SendClose();
    void RadioBroadcast(QString);
private slots:
    void on_BackMain_clicked();
    void on_AloneControl_clicked();
    void on_ModeChoice_clicked();
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

public slots:
    void Light_Status(int Function,int Sub,int Value);

private:
    Ui::LightSystem *ui;
};

#endif // LIGHTSYSTEM_H
