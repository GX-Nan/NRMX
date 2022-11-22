from threading import Thread
from time import sleep, ctime
import paho.mqtt.client as mqtt
import struct
import json
import urllib.request
import time
import datetime
import threading
from queue import Queue

q = Queue(maxsize = 10)

#修改成自己的即可
DEV_ID = "998964151" #设备ID
PRO_ID = "544764" #产品ID
AUTH_INFO = "7h6qKecs94Z=ZIKq=yutanCVh30="  #APIKEY 7


TYPE_JSON = 0x01
TYPE_FLOAT = 0x17

Order=3555

lock = threading.Lock()

#定义上传数据的json格式  该格式是oneNET规定好的  按格式修改其中变量即可
body = {
        "datastreams":[
                {
                    "id":"树莓派",  #对应OneNet的数据流名称
                    "datapoints":[
                        {
                            "at":"test", #数据提交时间，这里可通过函数来获取实时时间
                            "value":"已上线"   #数据值
                            }
                        ]
                    }
                ]
            }


def build_payload(type, payload):
    datatype = type
    packet = bytearray()
    packet.extend(struct.pack("!B", datatype))
    if isinstance(payload, str):
        udata = payload.encode('utf-8')
        length = len(udata)
        packet.extend(struct.pack("!H" + str(length) + "s", length, udata))
    return packet

    # 当客户端收到来自服务器的CONNACK响应时的回调。也就是申请连接，服务器返回结果是否成功等
def on_connect(client, userdata, flags, rc):
    print("连接结果:" + mqtt.connack_string(rc))
    #上传数据
    json_body = json.dumps(body)
    packet = build_payload(TYPE_JSON, json_body)
    client.publish("$dp", packet, qos=0)  #qos代表服务质量

    # 从服务器接收发布消息时的回调。
def on_message(client, userdata, msg):
#    print("温度:"+str(msg.payload,'utf-8')+"°C")
#    print(" 答案："+str(msg.payload,'utf-8'))
    q.put(msg.payload)

    #返回消息给QT
def CallBackToQt():
    Num=str(q.get())
    Num=int(Num[2:9])
    return Num
    #当消息已经被发送给中间人，on_publish()回调将会被触发
def on_publish(client, userdata, mid):
    print("mid--:" + str(mid))
def Connect():
    global Num
    client = mqtt.Client(client_id=DEV_ID, protocol=mqtt.MQTTv311)
    client.on_connect = on_connect
    client.on_publish = on_publish
    client.on_message = on_message

    client.username_pw_set(username=PRO_ID, password=AUTH_INFO)
    client.connect('183.230.40.39', port=6002, keepalive=120)

    client.loop_forever()

def func(name, sec):
    print('---开始---', name, '时间', ctime())
    time.sleep(0.1)
    return sec
def test(name,sec):
    while(True):{

    }
def Send(idData,Order):

    CurTime = datetime.datetime.now()
    url='http://api.heclouds.com/devices/998964151/datapoints'
    values={'datastreams':[{"id":idData,"datapoints":[{"at":CurTime.isoformat(),"value":Order}]}]}

#    print ("the time is:",CurTime.isoformat())
#    print ("The upload humidity value is:",Order)

    jdata = json.dumps(values).encode("utf-8")#格式转换
#    print (jdata)
    request = urllib.request.Request(url, jdata)

    request.add_header('api-key', AUTH_INFO)
    request.get_method = lambda:'POST'
    request = urllib.request.urlopen(request)

    return request.read()
def main():
    Task=threading.Thread(target=Connect)
    Task.start()
    # 或线程中程序的运行结果
#     print(t1.getResult())
#     print(t2.getResult())





