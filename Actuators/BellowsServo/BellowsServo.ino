#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

#include <WiFi.h>    //11.02完成

#define SDA 32
#define SCL 33

#define SERVO_0  102
#define SERVO_45  187
#define SERVO_90  280
#define SERVO_135  373
#define SERVO_180  510
#define SERVO_FREQ 50

// called this way, it uses the default address 0x40
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(0x40, Wire);

//---wifi
const char *ssid = "Fs";     //WiFi
const char *password = "Fs212123567"; //对应连接wifi密码

const IPAddress serverIP(192, 168, 1, 109); //将要访问的地址，监听地址
uint16_t serverPort = 6000;               //服务器端口号

WiFiClient client; //声明一个客户端对象，用于与服务器进行连接


void ServoPlan(int Order, int Sub);
// our servo # counter
uint8_t servonum = 0;
char comchar;


void setup() {
  Serial.begin(115200);
  Wire.begin(SDA, SCL, 100000);
  pwm.begin();
  pwm.setPWMFreq(50);
  delay(10);

  WiFi.mode(WIFI_STA);
  WiFi.setSleep(false);     //关闭STA模式下wifi休眠，提高响应速度
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(100);
    Serial.print(".");
  }
  Serial.println("Connected");
  Serial.print("IP Address:");
  Serial.println(WiFi.localIP()); //打印自己的IP地址

}

void loop() {
  String line, Head, Function, Sub, Order, logo, Transition;
  int Length, Times, Judge;
  if (client.connect(serverIP, serverPort))      //尝试访问目标地址
  {
    Serial.println("访问成功");
    while (client.connected() || client.available()) //如果已连接或有收到的未读取的数据
    {
      line = client.readStringUntil('\n'); //读取数据到换行符
      Length = line.length();
      Judge = Length % 10;
      Times = Length / 10;
      if (line != "" && Judge == 0) {
        Serial.println(line);
        for (int i = 0; i < Times; i++) {
          for (int a = 0; a <= 10; a++) {
            Transition = line.substring(i * 10, i * 10 + a);
          }
          Serial.println(Transition);
          logo = Transition.substring(0, 1);
          if (logo == "Z") {
            Head = Transition.substring(2, 3);
            Function = Transition.substring(3, 5);
            Sub = Transition.substring(5, 7);
            Order = Transition.substring(7, 9);
            if (Head.toInt() == 6) {
              if (Function.toInt() == 2) {
                ServoPlan(Order.toInt(), Sub.toInt());
                Serial.println("执行-------风量控制");
              }
            }
            Serial.println(Head);
            Serial.println(Function);
            Serial.println(Sub);
            Serial.println(Order);
          }
        }
        Head = "";
        Function = "";
        Sub = "";
        Order = "";
        logo = "";
        line = "";
      }
    }
  }
}
void ServoPlan(int Order, int Sub)
{
  if (Sub != 0) {
    switch (Order)
    {
      case 0:
        pwm.setPWM(Sub - 1, 0, SERVO_0);
        break;
      case 1:
        pwm.setPWM(Sub - 1, 0, SERVO_45);
        break;
      case 2:
        pwm.setPWM(Sub - 1, 0, SERVO_90);
        break;
      case 3:
        pwm.setPWM(Sub - 1, 0, SERVO_135);
        break;
      case 4:
        pwm.setPWM(Sub - 1, 0, SERVO_180);
        break;
    }
  }
  else {
    for (int i = 0; i < 6; i++) {
      switch (Order)
      {
        case 0:
          pwm.setPWM(i, 0, SERVO_0);
          break;
        case 1:
          pwm.setPWM(i, 0, SERVO_45);
          break;
        case 2:
          pwm.setPWM(i, 0, SERVO_90);
          break;
        case 3:
          pwm.setPWM(i, 0, SERVO_135);
          break;
        case 4:
          pwm.setPWM(i, 0, SERVO_180);
          break;
      }
      delay(50);
    }
  }
}
