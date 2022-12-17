#include <B_LUX_V30.h>
#include <Wire.h>
#include <WiFi.h>
#define SDA 32
#define SCL 33
#define EN  27

const char* ssid = "Fs";
const char* password =  "Fs212123567";
//IPAddress 类型变量
IPAddress staticIP(192, 168, 1, 141);//A----140 B----141
IPAddress gateway(192, 168, 1, 1);
IPAddress subnet(255, 255, 255, 0);
IPAddress dns(192, 168, 1, 1);

const IPAddress serverIP(192, 168, 1, 109); //将要访问的地址，监听地址
uint16_t serverPort = 6000;               //服务器端口号

WiFiClient client; //声明一个客户端对象，用于与服务器进行连接
B_LUX_V30 lux(SDA, SCL);//SDA=2; SCL=3
void setup() {
  Serial.begin(115200);
  pinMode(EN, OUTPUT);
  digitalWrite(EN, HIGH);
  //传入参数静态IP地址,网关.DNS1,和2
  if (WiFi.config(staticIP, gateway, subnet, dns, dns) == false) {
    Serial.println("Configuration failed.");
  }
  WiFi.mode(WIFI_STA);
  WiFi.setSleep(false);     //关闭STA模式下wifi休眠，提高响应速度
  //连接网络
  WiFi.begin(ssid, password);
  //等待连接
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print("Connecting...\n\n");
  }
}

void loop() {
  //Serial.println(lux.read());
  String IndoorLux, Head, Message, Fill = "";
  Head = "ESPB01";
  // put your main code here, to run repeatedly:
  String Transit;
  int LuxValue, Luxlength;
  if (client.connect(serverIP, serverPort))      //尝试访问目标地址
  {
    Serial.println("访问成功");
    client.print("Test");  //
    while (client.connected() || client.available()) //如果已连接或有收到的未读取的数据
    {
      LuxValue = lux.read();
      delay(2000);
      Transit = String(LuxValue);
      Luxlength = Transit.length();
      for (int i = 1; i <= (4 - Luxlength); i++) {
        Fill = Fill + "0";
      }
      Message = Head + Fill + Transit;

      Serial.println(Message);
      client.print(Message);
      Fill = "";
    }
  }
}
