#include <B_LUX_V30.h> 
#include <Wire.h>
#include <WiFi.h>  
#define SDA 32
#define SCL 33
#define EN  27

//---wifi
const char *ssid = "Fs";     //WiFi
const char *password = "Fs212123567"; //对应连接wifi密码

const IPAddress serverIP(192, 168, 1, 109); //将要访问的地址，监听地址
uint16_t serverPort = 6000;               //服务器端口号

WiFiClient client; //声明一个客户端对象，用于与服务器进行连接


B_LUX_V30 lux(SDA, SCL);//SDA=2; SCL=3  
void setup() {
  //Wire.begin(SDA, SCL, 200000);
  Serial.begin(115200);
  pinMode(EN,OUTPUT);
  while (!Serial) ;;;
  Serial.print("OK!");
  digitalWrite(EN,HIGH);
  
  // put your setup code here, to run once:
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
	//Serial.println(lux.read());
  String IndoorLux,Head,Message,Fill="";
  Head="ESPA01";
  // put your main code here, to run repeatedly:
  String Transit;
  int LuxValue,Luxlength;
  if (client.connect(serverIP, serverPort))      //尝试访问目标地址
  {
    Serial.println("访问成功");
    client.print("Test");  //
    while (client.connected() || client.available()) //如果已连接或有收到的未读取的数据
    {
        LuxValue=lux.read();
        delay(2000);
        Transit=String(LuxValue);
        Luxlength=Transit.length();
        for(int i=1;i<=(4-Luxlength);i++){
          Fill=Fill+"0";
        }
        Message=Head+Fill+Transit;

        Serial.println(Message);
        client.print(Message);  
        Fill="";
        
    }
  }
	
}
