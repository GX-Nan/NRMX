#include <WiFi.h>    //11.02完成

const char *ssid = "Raspberry Pi 6B";     //WiFi
const char *password = "Fs212123567"; //对应连接wifi密码

const IPAddress serverIP(192, 168, 31, 246); //将要访问的地址，监听地址
uint16_t serverPort = 6000;               //服务器端口号

WiFiClient client; //声明一个客户端对象，用于与服务器进行连接

byte buffer[17];     //存储型号SM300D2七合一传感器读取出的17个十六进制数值

int CO2 = 0, CH2O, TVOC, PM25, PM10, Temp, RH;

void setup() {
  Serial.begin(9600);

  WiFi.mode(WIFI_STA);
  WiFi.setSleep(false);     //关闭STA模式下wifi休眠，提高响应速度
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println("Connected");
  Serial.print("IP Address:");
  Serial.println(WiFi.localIP()); //打印自己的IP地址

}

void loop() {
  String myTemp, myCO2, myCH2O, myTVOC, myPM25, myPM10, myRH;
  if (client.connect(serverIP, serverPort))      //尝试访问目标地址
  {
    Serial.println("访问成功");
    client.print("Test");  //
    while (client.connected() || client.available()) //如果已连接或有收到的未读取的数据
    {
      delay(100);
      if (Serial.available() > 0) {

        Serial.readBytes(buffer, HEX);  //读出七合一传感器十六进制数值
        while (Serial.read() >= 0) {} //清除字节避免乱码，必不可少！！！

        String line = client.readStringUntil('\n'); //读取数据到换行符

        //delay(100);
        Temp = (buffer[12] + buffer[13] * 0.1);
        Serial.print("温度 ：");
        Serial.println(Temp);
        if (0 <= Temp && Temp < 10)
        {
          myTemp = String("ESPB02") + String("000") + String(Temp);
          client.print(myTemp);
        }
        else if (10 <= Temp && Temp < 100)
        {
          myTemp = String("ESPB02") + String("00") + String(Temp);
          client.print(myTemp);
        } else if (100 <= Temp && Temp < 1000)
        {
          myTemp = String("ESPB02") + String("0") + String(Temp);
          client.print(myTemp);
        } else if (1000 <= Temp && Temp < 10000)
        {
          myTemp = String("ESPB02") + String(Temp);
          client.print(myTemp);
        }

        delay(800);

        RH = (buffer[14] + buffer[15] * 0.1); //湿度指令ESPB03 +4位数据位
        Serial.print("湿度 ：");
        Serial.println(RH);
        if (0 <= RH && RH < 10)
        {
          myRH = String("ESPB03") + String("000") + String(RH);
          client.print(myRH);
          client.print('\n');
        } else if (10 <= RH && RH < 100)
        {
          myRH = String("ESPB03") + String("00") + String(RH);
          client.print(myRH);
          client.print('\n');
        } else if (100 <= RH && RH < 1000)
        {
          myRH = String("ESPB03") + String("0") + String(RH);
          client.print(myRH);
          client.print('\n');
        } else if (1000 <= RH && RH < 10000)
        {
          myRH = String("ESPB03") + String(RH);
          client.print(myRH);
          client.print('\n');
        }
        delay(800);

        PM25 = (buffer[8] * 256 + buffer[9]);
        Serial.print(" pm2.5 ：");
        Serial.println(PM25);
        if (0 <= PM25 && PM25 < 10)
        {
          myPM25 = String("ESPB04") + String("000") + String(PM25);
          client.print(myPM25);
          client.print('\n');
        } else if (10 <= PM25 && PM25 < 100)
        {
          myPM25 = String("ESPB04") + String("00") + String(PM25);
          client.print(myPM25);
          client.print('\n');
        } else if (100 <= PM25 && PM25 < 1000)
        {
          myPM25 = String("ESPB04") + String("0") + String(PM25);
          client.print(myPM25);
          client.print('\n');
        } else if (1000 <= RH && RH < 10000)
        {
          myPM25 = String("ESPB04") + String(PM25);
          client.print(myPM25);
          client.print('\n');
        }
        delay(800);


        CO2 = (buffer[2] * 256 + buffer[3]);
        Serial.print(" 二氧化碳：");
        Serial.println(CO2);
        if (0 <= CO2 && CO2 < 10)
        {
          myCO2 = String("ESPB05") + String("000") + String(CO2);
          client.print(myCO2);
          client.print('\n');
        } else if (10 <= CO2 && CO2 < 100)
        {
          myCO2 = String("ESPB05") + String("00") + String(CO2);
          client.print(myCO2);
          client.print('\n');
        } else if (100 <= CO2 && CO2 < 1000)
        {
          myCO2 = String("ESPB05") + String("0") + String(CO2);
          client.print(myCO2);
          client.print('\n');
        } else if (1000 <= CO2 && CO2 < 10000)
        {
          myCO2 = String("ESPB05") + String(CO2);
          client.print(myCO2);
          client.print('\n');
        }
        delay(800);

        TVOC = (buffer[6] * 256 + buffer[7]);
        Serial.print(" TVOC：");
        Serial.println(TVOC);
        if (0 <= TVOC && TVOC < 10)
        {
          myTVOC = String("ESPB06") + String("000") + String(TVOC);
          client.print(myTVOC);
          client.print('\n');
        } else if (10 <= TVOC && TVOC < 100)
        {
          myTVOC = String("ESPB06") + String("00") + String(TVOC);
          client.print(myTVOC);
          client.print('\n');
        } else if (100 <= TVOC && TVOC < 1000)
        {
          myTVOC = String("ESPB06") + String("0") + String(TVOC);
          client.print(myTVOC);
          client.print('\n');
        } else if (1000 <= TVOC && TVOC < 10000)
        {
          myTVOC = String("ESPB06") + String(TVOC);
          client.print(myTVOC);
          client.print('\n');
        }
        delay(800);


        CH2O = (buffer[4] * 256 + buffer[5]);
        Serial.print("CH2O ：");
        Serial.println(CH2O);
        if (0 <= CH2O && CH2O < 10)
        {
          myCH2O = String("ESPB07") + String("000") + String(CH2O);
          client.print(myCH2O);
          client.print('\n');
        } else if (10 <= CH2O && CH2O < 100)
        {
          myCH2O = String("ESPB07") + String("00") + String(CH2O);
          client.print(myCH2O);
          client.print('\n');
        } else if (100 <= CH2O && CH2O < 1000)
        {
          myCH2O = String("ESPB07") + String("0") + String(CH2O);
          client.print(myCH2O);
          client.print('\n');
        } else if (1000 <= CH2O && CH2O < 10000)
        {
          myCH2O = String("ESPB07") + String(CH2O);
          client.print(myCH2O);
          client.print('\n');
        }
        delay(800);

        PM10 = (buffer[10] * 256 + buffer[11]);
        Serial.print("PM10 ：");
        Serial.println(PM10);
        if (0 <= PM10 && PM10 < 10)
        {
          myPM10 = String("ESPB08") + String("000") + String(PM10);
          client.print(myPM10);
          client.print('\n');
        } else if (10 <= PM10 && PM10 < 100)
        {
          myPM10 = String("ESPB08") + String("00") + String(PM10);
          client.print(myPM10);
          client.print('\n');
        }
        else if (100 <= PM10 && PM10 < 1000) {
          myPM10 = String("ESPB08") + String("0") + String(PM10);
          client.print(myPM10);
          client.print('\n');
        }
        else if (1000 <= PM10 && PM10 < 10000)
        {
          myPM10 = String("ESPB08") + String(PM10);
          client.print(myPM10);
          client.print('\n');
        }
        delay(800);
        myTemp="";
        myCO2="";
        myCH2O="";
        myTVOC="";
        myPM25="";
        myPM10="";
        myRH="";
        //                下面可删
        //                client.write(line.c_str()); //将收到的数据回发
        //                Serial.print("读取到数据：");
        //                Serial.println(line);
      }
    }
    Serial.println("关闭当前连接");
    client.stop(); //关闭客户端
  }
  else
  {
    Serial.println("访问失败");
    client.stop();
  }
  delay(1000);
}
