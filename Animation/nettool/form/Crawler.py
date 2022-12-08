#!/usr/bin/env python
# -*- coding: utf-8 -*-
import requests
import json
# 填入 请求
# url = 'https://devapi.qweather.com/v7/air/now'#空气质量
# url = 'https://devapi.qweather.com/v7/weather/now' #实时天气
# url = 'https://devapi.qweather.com/v7/weather/24h' #逐时
# url = 'https://devapi.qweather.com/v7/indices/1d?type=0' #当天生活指数

AirNow = 'air/now'
WeatherNow = 'weather/now'
Weather24H = 'weather/24h'
LivingIndex = 'indices/1d?type=0'

url = 'https://devapi.qweather.com/v7/'
# 建立列表
KeyList = [AirNow, WeatherNow, Weather24H, LivingIndex]
# # 建立获取的字典
# AirDict,WeatherNowDict,Weather24HDict,LivingDict
# 填入 地址 和 你的KEY
value = {
    'location': '101280701',
    'key': '2c8cbbd7896847cb8d513e3d12c86dc2',
    #'key': '1f51a47ba23341acaa76629705dcbe4d',
    #'key': '941ab42e996a45b3aa01fbe047bc85b8',
    #
    #    'lang': 'zh'
}

# print(type(sds))  # 取回来的是字典

def Analyse():
    del AirDict['pubTime']#删除时间
    del WeatherNowDict['obsTime']#删除时间
#    Air=json.dumps(AirDict,ensure_ascii=False)
#    Now=json.dumps(WeatherNowDict,ensure_ascii=False)
#    Hourly=json.dumps(Weather24HDict,ensure_ascii=False)
#    Living=json.dumps(LivingDict,ensure_ascii=False)
#    ReturnList="14,"+"15"

    AQi = AirDict["aqi"]
    AqiLevel = AirDict["level"]
    Pm10 = AirDict["pm10"]
    Pm25 = AirDict["pm2p5"]
    No2 = AirDict["no2"]
    so2 = AirDict["so2"]
    co = AirDict["co"]
    Humi = WeatherNowDict["humidity"]
    Temp = WeatherNowDict["temp"]
    Weather = WeatherNowDict["text"]
    Airlist = "AQi" + "," + AQi + "," + "AqiLevel" + "," + AqiLevel + "," + "Pm10" + "," + Pm10 + "," + "Pm25" + "," + Pm25 + "," + "No2" + "," + No2 + "," + "so2" + "," + so2 + "," + "co" + "," + co
    NowList= "Hum" + "," + Humi + "," + "Temp" + "," + Temp + "," + Weather
    ReturnList=[Airlist,NowList]
    for i in range(4):
        Transition=LivingDict[i]["name"]+","+LivingDict[0]["level"]
        ReturnList.append(Transition)
    for i in range(12):
        Transition = Weather24HDict[i]["fxTime"] + "," + Weather24HDict[i]["text"]+ "," + Weather24HDict[i]["temp"]+ "," + Weather24HDict[i]["humidity"]
        ReturnList.append(Transition)
    return ReturnList

# 从网址内获取指定数据
# 具体 关键词 详见官方 API 手册的解释
def GetMessage(List):
    global AirDict, WeatherNowDict, Weather24HDict, LivingDict
    for i in range(4):
        CurrentUrl = url + KeyList[i]
        sd = requests.get(CurrentUrl, params=value)
        sds = sd.json()
        if i == 0:
            AirDict = sds['now']
        elif i == 1:
            WeatherNowDict = sds['now']
        elif i == 2:
            Weather24HDict = sds['hourly']
        elif i == 3:
            LivingDict = sds['daily']
    return Analyse()

def Hello():
    return 1


