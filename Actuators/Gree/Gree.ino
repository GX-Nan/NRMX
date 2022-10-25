#include <Arduino.h>
#include <IRremoteESP8266.h>
#include <ir_Kelvinator.h>
#include <WiFi.h>
#include <Wire.h>
#include <String.h>
#include "SSD1306.h"

SSD1306 display(0x3c, 32, 33);  //address sda scl

static int AcSatation = 0;
static String AcMode = " ";
static int AcTemp = 26;
static int AcSwingVertical = 0;
static int AcSwingHorizontal = 0;
static int AcFan = 0;
static int LastBuf = 0;

const char *ssid = "Fs";
const char *password = "Fs212123567";
//const char *ssid = "Raspberry Pi 6B";
//const char *password = "qwerty123567";


const IPAddress serverIP(192, 168, 1, 109); //欲访问的地址
uint16_t serverPort = 6000;         //服务器端口号5

WiFiClient client; //声明一个客户端对象，用于与服务器进行连接

const uint16_t kIrLed = 5;  // ESP32 GPIO pin to use. Recommended: 5
IRKelvinatorAC ac(kIrLed);  // Set the GPIO to be used for sending messages.

void Function(int buf);


void setup()
{
  ac.begin();
  Serial.begin(115200);

  WiFi.mode(WIFI_STA);
  WiFi.setSleep(false); //关闭STA模式下wifi休眠，提高响应速度
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    //Serial.print(".");
  }
  display.init();
  delay(1000);
}

void loop()
{
  if (client.connect(serverIP, serverPort))
  {
    while (client.connected() || client.available())
    {
      if (client.available()) //如果有数据可读取
      {

        String line = client.readStringUntil('\n');
        String data_1;
        String data_2;
        int buf;
        for (int i = 0; i < line.length(); i++)
        {
          data_1 = line.substring(i, i + 7);
          if (data_1 == "ZB20201" )
          {
            data_2 = line.substring(i + 7, i + 9);
            buf = data_2.toInt();
            Function(buf);
          }
          else if (data_1 == "ZB20200")//同步
          {
            //            if()
            //            String Temp="ZB20201";
            //            Temp=Temp+AcTemp+"1";
            //            Serial.println(Temp);
            //            client.write(Temp.c_str());
          }
        }
      }
    }
    Serial.println("关闭当前连接");
    client.stop(); //关闭客户端
  }
  else
  {
    Serial.println("访问失败");
    client.stop(); //关闭客户端
  }
  delay(1000);
}
void Function(int buf)
{
  if (buf != LastBuf) {
    if (buf < 16) {
      switch (buf)
      {
        case 0:
          {
            ac.off();
            ac.send();
            AcSatation = 0;
            break;
          }
        case 1:
          {
            ac.on();
            //          ac.setFan(1);//风速
            //          ac.setMode(kKelvinatorCool);//模式//kKelvinatorDry除湿/kKelvinatorHeat制热/kKelvinatorCool制冷/kKelvinatorFan送风/kKelvinatorAuto自动
            //          ac.setTemp(26);  // 16-30C
            //          ac.setSwingVertical(0);//上下摆风
            //          ac.setSwingHorizontal(0);//左右摆风
            //----------------
            AcSatation = 1;
            //          AcMode = "Cool";
            //          AcTemp = 26;
            //          AcSwingVertical = 0;
            //          AcSwingHorizontal = 0;
            //          AcFan = 1;
            //---------------
            ac.send();
            break;
          }
        case 2:
          {
            ac.setFan(1);
            ac.send();
            AcFan = 1;
            delay(500);
            break;
          }
        case 3:
          {
            ac.setFan(2);
            AcFan = 2;
            ac.send();
            break;
          }
        case 4:
          {
            ac.setFan(3);
            ac.send();
            AcFan = 3;
            break;
          }
        case 5:
          {
            ac.setSwingHorizontal(1);
            AcSwingHorizontal = 1;
            ac.send();
            break;
          }
        case 6:
          {
            ac.setSwingHorizontal(0);
            AcSwingHorizontal = 0;
            ac.send();
            break;
          }
        case 7:
          {
            ac.setSwingVertical(1);
            AcSwingVertical = 1;
            ac.send();
            break;
          }
        case 8:
          {
            ac.setSwingVertical(0);
            ac.send();
            AcSwingVertical = 0;
            delay(500);
            break;
          }
        case 9:
          {
            ac.setMode(kKelvinatorCool);
            AcMode = "Cool";
            ac.send();
            break;
          }
        case 10:
          {
            ac.setMode(kKelvinatorDry);
            AcMode = "Dry";
            ac.send();
            delay(500);
            break;
          }
        case 11:
          {
            ac.setMode(kKelvinatorHeat);
            AcMode = "Heat";
            ac.send();
            break;
          }
        case 12:
          {
            ac.setMode(kKelvinatorAuto);
            AcMode = "Auto";
            ac.send();
            break;
          }
        case 13:
          {
            ac.setFan(0);
            AcFan = 0;
            ac.send();
            delay(500);
            break;
          }
        case 14:
          {
            ac.setMode(kKelvinatorFan);
            AcMode = "Fan";
            ac.send();
            break;
          }
        case 15:
          {
            break;
          }
      }
    }
    else {
      if (AcTemp != buf) {
        ac.setTemp(buf);
        AcTemp = buf;
        ac.send();
        Serial.println(AcTemp);
      }
    }
    LastBuf=buf;
  }
  display.clear();
  display.drawString(1, 5, "Air Station:" + String(AcSatation));
  display.drawString(1, 15, "Air Temp:" + String(AcTemp));
  display.drawString(1, 25, "AcSwingVertical:" + String(AcSwingVertical));
  display.drawString(1, 35, "AcSwingHorizontal:" + String(AcSwingHorizontal));
  display.drawString(1, 45, "Air Mode:" + String(AcMode));
  display.display();
}
