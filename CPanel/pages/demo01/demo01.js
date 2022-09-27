// pages/demo01/demo01.js
const app = getApp()
// const apikey = "eNIzhrJ8mW0Pol4phyvUZj6EKRA="//我的
// const deviceid = '501311474'//我的
const apikey = 'yGocwss2O4w=VDqY5=0J=jaUUc4='//开启老版模式才有
const deviceid = '798017394'//

var deviceConnected = false

const deviceInfoURL = "https://api.heclouds.com/devices/" + deviceid
const getDataStreamURL = "https://api.heclouds.com/devices/" + deviceid + "/datastreams"
const sendCommandURL = "https://api.heclouds.com/cmds"

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
      // console.log(res)
      if (res.data.data.online) {
        console.log("设备已经连接")
        deviceInit(that)//初始化按钮
        deviceConnected = true
      } else {
        console.log("设备还未连接")
        deviceConnected = false
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
  console.log("开始初始化按钮")
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
      for(var i=0; i<res.data.data.length; i++) {
        var info = res.data.data[i]
        
        switch(info.id) {
          case "switch_One":
            if(info.current_value == 1) {
              that.setData({ Switch_One : true})
            } else {
              that.setData({ Switch_One : false})
            }
            break
          case "switch_Two":
            if (info.current_value == 1) {
              that.setData({ Switch_Two: true })
            } else {
              that.setData({ Switch_One: false })
            }
            break
        }
      }
    }
  })
}

  function controlLED(hardware_id ,switch_value) //发送指令
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
        // if(1) {
        //   alert("控制成功")
        // } else {
        //   alert("设备不在线")
        // }
      }
    })
  }

  Page({
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
      }, 3000)
    },
    change: function (event) {
      var cmdData = event.detail.value == true ? 1 : 0 //修改为约定的数据
      switch(event.currentTarget.id) {
        case 'ZC20301':
          console.log('房间C前灯')
          controlLED('ZC20301', cmdData)
          break;
        case 'ZC20102':
          console.log('房间C后灯')
          controlLED('ZC20302', cmdData)
          break;
      }
    }
  })
  