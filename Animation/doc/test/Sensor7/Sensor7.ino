#include <SoftwareSerial.h>
#include <WiFi.h>
#include <Wire.h>   // I2C library
#include "iAQcore.h"
#include <math.h>
#include "PMS.h"

iAQcore iaqcore;

HardwareSerial SerialPMS(1);
PMS pms(SerialPMS);
PMS::DATA data;

#define RXD1 2
#define TXD1 0

int rxPin = 32;
int txPin = 33;
 
#define Addr 0x44
#define WZ_S_START_TAG 0Xff
#define WZ_S_SIZE 9
SoftwareSerial swSerial(rxPin, txPin); //  // RX, TX 90 Bytes buffer, enough for up to 10 packets..

const char *ssid = "Raspberry Pi 6B";//
const char *password = "qwerty123567";

const IPAddress serverIP(192, 168, 31, 25); //欲访问的地址
uint16_t serverPort = 6000;         //服务器端口号

WiFiClient client; //声明一个客户端对象，用于与服务器进行连接


float r2;
byte CO2req[] = {0xFE, 0X44, 0X00, 0X08, 0X02, 0X9F, 0X25};
byte CO2out[] = {0, 0, 0, 0, 0, 0, 0};

void RequestCO2 ();

void setup() {
  Wire.begin();
  Serial.begin(9600);
  Serial.flush();
  Serial.println();

  WiFi.mode(WIFI_STA);
  WiFi.setSleep(false); //关闭STA模式下wifi休眠，提高响应速度
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println("Connected");
  Serial.print("IP Address:");
  Serial.println(WiFi.localIP());

  //Wire.setClock(1000);

  swSerial.begin(9600);
  swSerial.flush();
  SerialPMS.begin(9600, SERIAL_8N1, RXD1, TXD1);
  pms.passiveMode();
  Serial2.begin(9600, SERIAL_8N1, 18, 19);
  // iaqcore.begin();
  // Serial1.begin(115200);
}


void loop() {
  int a = 0;
  String log;
  Serial.println("尝试访问服务器");
  if (client.connect(serverIP, serverPort)) //尝试访问目标地址
  {
    Serial.println("访问成功");
    while (client.connected() || client.available()) //如果已连接或有收到的未读取的数据
    {

      delay(100);
      RequestCO2();
      unsigned long CO2 = CO2count();
      delay(100);
      Serial.print("CO2: ");
      Serial.println(CO2);
      if (0 <= CO2 && CO2 < 10)
      {
        String myCO2 = String("ESPB02") + String("000") + String(CO2);
        client.print(myCO2);
      }
      else if (10 <= CO2 && CO2 < 100)
      {
        String myCO2 = String("ESPB02") + String("00") + String(CO2);
        client.print(myCO2);
      }
      else if (100 <= CO2 && CO2 < 1000)
      {
        String myCO2 = String("ESPB02") + String("0") + String(CO2);
        client.print(myCO2);
      }
      else if (1000 <= CO2 && CO2 < 10000)
      {
        String myCO2 = String("ESPB02") + String(CO2);
        client.print(myCO2);
      }
      delay(100);
      pms.requestRead();
      if (pms.readUntil(data))
      {
        Serial.print("PM 1.0 (ug/m3): ");
        Serial.println(data.PM_AE_UG_1_0);
        Serial.print("PM 2.5 (ug/m3): ");
        Serial.println(data.PM_AE_UG_2_5);
        Serial.print("PM 10.0 (ug/m3): ");
        Serial.println(data.PM_AE_UG_10_0);

        int PM1_0 = data.PM_AE_UG_1_0;
        //Serial.print("3: ");
        //Serial.println(PM1_0);
        if (0 <= PM1_0 && PM1_0 < 10)
        {
          String myPM1_0 = String("ESPB03") + String("000") + String(PM1_0);
          client.print(myPM1_0);
        }
        else if (10 <= PM1_0 && PM1_0 < 100)
        {
          String myPM1_0 = String("ESPB03") + String("00") + String(PM1_0);
          client.print(myPM1_0);
        }
        else if (100 <= PM1_0 && PM1_0 < 1000)
        {
          String myPM1_0 = String("ESPB03") + String("0") + String(PM1_0);
          client.print(myPM1_0);
        }
        else if (1000 <= PM1_0 && PM1_0 < 10000)
        {
          String myPM1_0 = String("ESPB03") + String(PM1_0);
          client.print(myPM1_0);
        }
        delay(100);
        //---------------------------------------------
        int PM2_5 = data.PM_AE_UG_2_5;
        //Serial.print("4: ");
        //Serial.println(PM2_5);
        if (0 <= PM2_5 && PM2_5 < 10)
        {
          String myPM2_5 = String("ESPB04") + String("000") + String(PM2_5);
          client.print(myPM2_5);
        }
        else if (10 <= PM2_5 && PM2_5 < 100)
        {
          String myPM2_5 = String("ESPB04") + String("00") + String(PM2_5);
          client.print(myPM2_5);
        }
        else if (100 <= PM2_5 && PM2_5 < 1000)
        {
          String myPM2_5 = String("ESPB04") + String("0") + String(PM2_5);
          client.print(myPM2_5);
        }
        else if (1000 <= PM2_5 && PM2_5 < 10000)
        {
          String myPM2_5 = String("ESPB04") + String(PM2_5);
          client.print(myPM2_5);
        }
        delay(100);
        //-----------------------------------------------
        int PM10 = data.PM_AE_UG_10_0;
        //Serial.print("5: ");
        //Serial.println(PM10);
        if (0 <= PM10 && PM10 < 10)
        {
          String myPM10 = String("ESPB05") + String("000") + String(PM10);
          client.print(myPM10);
        }
        else if (10 <= PM10 && PM10 < 100)
        {
          String myPM10 = String("ESPB05") + String("00") + String(PM10);
          client.print(myPM10);
        }
        else if (100 <= PM10 && PM10 < 1000)
        {
          String myPM10 = String("ESPB05") + String("0") + String(PM10);
          client.print(myPM10);
        }
        else if (1000 <= PM10 && PM10 < 10000)
        {
          String myPM10 = String("ESPB05") + String(PM10);
          client.print(myPM10);
        }
        delay(100);
      }
      else
      {
        Serial.println("11111111111111111111111111111");
      }

      delay(200);
      boolean success = false;
      if (Plugin_200_PacketAvailable())
      {
        success = Plugin_200_process_data();
      }

      Wire.begin(25, 26);
      delay(500);
      unsigned int data2[6];
      Wire.beginTransmission(Addr);
      Wire.write(0x2C);
      Wire.write(0x06);

      Wire.endTransmission();
      delay(500);
      Wire.requestFrom(Addr, 6);

      if (Wire.available() == 6)
      {
        data2[0] = Wire.read();
        data2[1] = Wire.read();
        data2[2] = Wire.read();
        data2[3] = Wire.read();
        data2[4] = Wire.read();
        data2[5] = Wire.read();
      }
      Wire.flush();
      float cTemp = ((((data2[0] * 256.0) + data2[1]) * 175) / 65535.0) - 45;
      float hum = ((((data2[3] * 256.0) + data2[4]) * 100) / 65535.0);

      int temp_1 = int(cTemp);
      Serial.print("7: ");
      Serial.println(temp_1);
      if (0 <= temp_1 && temp_1 < 10)
      {
        String mytemp = String("ESPB07") + String("000") + String(temp_1);
        client.print(mytemp);
      }
      else if (10 <= temp_1 && temp_1 < 100)
      {
        String mytemp = String("ESPB07") + String("00") + String(temp_1);
        client.print(mytemp);
      }
      else if (100 <= temp_1 && temp_1 < 1000)
      {
        String mytemp = String("ESPB07") + String("0") + String(temp_1);
        client.print(mytemp);
      }
      else if (1000 <= temp_1 && temp_1 < 10000)
      {
        String mytemp = String("ESPB07") + String(temp_1);
        client.print(mytemp);
      }
      delay(100);
      //--------------------------------------------------------------
      int  rhum_1 = int(hum);
      Serial.print("8: ");
      Serial.println(rhum_1);
      if (0 <= rhum_1 && rhum_1 < 10)
      {
        String myrhum = String("ESPB08") + String("000") + String(rhum_1);
        client.print(myrhum);
      }
      else if (10 <= rhum_1 && rhum_1 < 100)
      {
        String myrhum = String("ESPB08") + String("00") + String(rhum_1);
        client.print(myrhum);
      }
      else if (100 <= rhum_1 && rhum_1 < 1000)
      {
        String myrhum = String("ESPB08") + String("0") + String(rhum_1);
        client.print(myrhum);
      }
      else if (1000 <= rhum_1 && rhum_1 < 10000)
      {
        String myrhum = String("ESPB08") + String(rhum_1);
        client.print(myrhum);
      }
      delay(100);
      uint16_t eco2;
      uint16_t stat;
      uint32_t resist;
      uint16_t etvoc;

      Wire.begin(21, 22);
      delay(1000);
      iaqcore.begin();
      iaqcore.read(&eco2, &stat, &resist, &etvoc);
      delay(300);
      Wire.endTransmission();
      Serial.print("9: ");
      Serial.println(etvoc);
      if (0 <= etvoc && etvoc < 10)
      {
        String myT = String("ESPB09") + String("000") + String(etvoc);
        client.print(myT);
      }
      else if (10 <= etvoc && etvoc < 100)
      {
        String myT = String("ESPB09") + String("00") + String(etvoc);
        client.print(myT);
      }
      else if (100 <= etvoc && etvoc < 1000)
      {
        String myT = String("ESPB09") + String("0") + String(etvoc);
        client.print(myT);
      }
      else if (1000 <= etvoc && etvoc < 10000)
      {
        String myT = String("ESPB09") + String(etvoc);
        client.print(myT);
      }
      delay(1000);
      Serial.flush();
      Wire.flush();
      client.flush();
      delay(1000);
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

void Plugin_200_SerialFlush() {
  if (swSerial != NULL) {
    swSerial.flush();
  }
  else {
    Serial.flush();
  }
}

boolean Plugin_200_PacketAvailable(void)
{
  if (swSerial != NULL) // Software serial
  {
    if (!swSerial.available()) return false;
    while ((swSerial.peek() != WZ_S_START_TAG) && swSerial.available()) {
      swSerial.read(); // Read until the buffer starts with the first byte of a message, or buffer empty.
    }
    if (swSerial.available() < WZ_S_SIZE) return false; // Not enough yet for a complete packet
  }
  else // Hardware serial
  {

  }
  return true;
}

boolean Plugin_200_process_data() {
  String log;
  uint8_t data[WZ_S_SIZE];
  if (swSerial != NULL)
  {
    for (int i = 0; i < WZ_S_SIZE; i++) {
      data[i] = swSerial.read();
      //Serial.println(data[i]);
    }
  }
  else
  {
  }
  uint8_t checksum = 0;
  for (int i = 1; i < WZ_S_SIZE - 1; i++)
    checksum += data[i];

  checksum = (~checksum) + 1;

  if (checksum != data[WZ_S_SIZE - 1])
  {
    log = F("WZ-S : checksum error.");
    Serial.println(log);
    //addLog(LOG_LEVEL_ERROR, log);
    return false;
  }
  float r1  = (float)(data[4] << 8 | data[5]);

  float r2 = r1 / 1000.0 * 1.3393;
  Plugin_200_SerialFlush(); // Make sure no data is lost due to full buffer.
  int r3 = r2 * 1000;
  Serial.println(r3);
  Serial.print("6: ");
  Serial.println(r3);
  if (0 <= r3 && r3 < 10)
  {
    String myH = String("ESPB06") + String("000") + String(r3);
    client.print(myH);
  }
  else if (10 <= r3 && r3 < 100)
  {
    String myH = String("ESPB06") + String("00") + String(r3);
    client.print(myH);
  }
  else if (100 <= r3 && r3 < 1000)
  {
    String myH = String("ESPB06") + String("0") + String(r3);
    client.print(myH);
  }
  else if (1000 <= r3 && r3 < 10000)
  {
    String myH = String("ESPB06") + String(r3);
    client.print(myH);
  }
  delay(100);
  log = F("WZ-S : ");
  log += r1;
  log += F("ppb, ");
  log += r2;
  log += F("mg/m³(calc) ");
  Serial.println(log);
  return true;
}
void RequestCO2 ()
{
  while (!Serial2.available())
  {
    Serial2.write(CO2req, 7);
    delay(50);
  }

  int timeout = 0;
  while (Serial2.available() < 7 )
  {
    timeout++;
    if (timeout > 10)
    {
      while (Serial2.available())
        Serial2.read();
      break;
    }
    delay(50);
  }

  for (int i = 0; i < 7; i++)
  {
    CO2out[i] = Serial2.read();
  }
}

unsigned long CO2count()
{
  int high = CO2out[3];
  int low = CO2out[4];
  unsigned long val = high * 256 + low;
  return val * 1; // S8 = 1. K-30 3% = 3, K-33 ICB = 10
}
