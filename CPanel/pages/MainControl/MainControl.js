// pages/Room_C_Control/Control.js

const app = getApp()
// const apikey = "eNIzhrJ8mW0Pol4phyvUZj6EKRA="//我的
// const deviceid = '501311474'//我的
const apikey = '7h6qKecs94Z=ZIKq=yutanCVh30='//开启老版模式才有
// const deviceid = '798017394'//
const deviceid = '998964151'//

var deviceConnected = false

const deviceInfoURL = "https://api.heclouds.com/devices/" + deviceid
const getDataStreamURL = "https://api.heclouds.com/devices/" + deviceid + "/datastreams"
const sendCommandURL = "https://api.heclouds.com/cmds" 

var ControlConnect=true
var AirControl=false
var SupplyControl=false
var PumingControl=false
var StopBack=true

function getDeviceInfo(that) {
    //查看设备连接状态，并刷新按钮状态
    wx.request({
      url: deviceInfoURL,
      header: {
        'content-type': 'application/x-www-form-urlencoded',
        "api-key": apikey
      },
      data: {
  
      },
      success(res) {
        console.log(res)
        if (res.data.data.online) { 
          console.log("设备已经连接")
          deviceInit(that)//初始化按钮
          deviceConnected = true
          if(deviceConnected==true&&ControlConnect==true)
          {
            wx.showToast({
              title: '设备已连接', // 标题
              icon: 'success',  // 图标类型，默认success
              duration: 900  // 提示窗停留时间，默认1500ms
            })
            ControlConnect = false
          }
        } else {
        //  console.log("设备还未连接")
          deviceConnected = false
          if(deviceConnected==false&&ControlConnect==false)
          {
            wx.showToast({
              title: '设备已连接', // 标题
              icon: 'success',  // 图标类型，默认success
              duration: 900  // 提示窗停留时间，默认1500ms
            })
            ControlConnect = true
          }
        }
      },
      
      fail(res) {
        console.log("请求失败")
        deviceConnected = false
      },
      complete() {
      if (deviceConnected) {
        that.setData({ deviceConnected: true })
       
      } else {
         that.setData({ deviceConnected: false })
      }
      }
    })
  }
  
  function deviceInit(that)//对信息的回传
   {
   // console.log("开始初始化按钮")
    //初始化各个硬件的状态
    wx.request({
      url: getDataStreamURL,
      header: {
        'content-type': 'application/x-www-form-urlencoded',
        "api-key": apikey
      },
      data: {
        
      },
      success(res) {
        
         

       
      }
    })
  }
  
    function SendData(hardware_id ,switch_value) //发送指令
    {
      // console.log("发送命令：" + hardware_id + ":{" + switch_value + "}")
      //console.log("发送命令：" + hardware_id + ":" +switch_value )
      console.log(hardware_id + ":" +switch_value )
      //按钮发送命令控制硬件
      wx.request({
        url: sendCommandURL + "?device_id=" + deviceid,
        method: 'POST',
        header: {
          'content-type': 'application/x-www-form-urlencoded',
          "api-key": apikey
        },
        // data: hardware_id + ":{" + switch_value + "}",      //TODO 设计自定义语言 blueled:{V}, 预感这边可能会有问题
        data: hardware_id + ":" + switch_value ,
        success(res) {
          console.log("控制成功")
          console.log(res)
      
        }
      })
    }
//===========================================================初始化


Page({
    /**
     * 页面的初始数据
     */
    data: {
       
    },

      onLoad: function () {
        //加载时完成1.检查设备是否连接2.连接成功将数据显示在界面
        var that = this //将当前对象赋值
        getDeviceInfo(that)
      },
      onShow: function() {
        //TODO依旧有问题
        var that = this
        var timer = setInterval(function(){
          getDeviceInfo(that)
        }, 1500) //最好的是1000
      },
    //----------------------页面跳转
    Window_NavigateTo:function(){
      wx.navigateTo({
        url: '../Window/Window?id='
        })
    },
    Light_NavigateTo:function(){
      wx.navigateTo({
        url: '../LED/LED?id='
        })
    },
    Cutrains_NavigateTo:function(){
      wx.navigateTo({
        url: '../Curtain/Curtain?id='
        })
    },
    Air_NavigateTo:function(){
      wx.navigateTo({
        url: '../Air/Air?id='
        })
    },
    Wind_NavigateTo:function(){
      wx.navigateTo({
        url: '../Wind/Wind?id='
        })
    },

 
})

