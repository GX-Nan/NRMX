// pages/Room_C_Control/Control.js

const app = getApp()
// const apikey = "eNIzhrJ8mW0Pol4phyvUZj6EKRA="//我的
// const deviceid = '501311474'//我的
const apikey = '7h6qKecs94Z=ZIKq=yutanCVh30=' //开启老版模式才有
// const deviceid = '798017394'//
const deviceid = '998964151' //

var deviceConnected = false

const deviceInfoURL = "https://api.heclouds.com/devices/" + deviceid
const getDataStreamURL = "https://api.heclouds.com/devices/" + deviceid + "/datastreams"
const sendCommandURL = "https://api.heclouds.com/cmds"

var ControlConnect = true
var AirControl = false
var SupplyControl = false
var PumingControl = false
var StopBack = true

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
                //console.log(res)
                deviceInit(that) //初始化按钮
                deviceConnected = true
                if (deviceConnected == true && ControlConnect == true) {
                    wx.showToast({
                        title: '设备已连接', // 标题
                        icon: 'success', // 图标类型，默认success
                        duration: 900 // 提示窗停留时间，默认1500ms
                    })
                    ControlConnect = false
                }
            } else {
                //console.log("设备还未连接")
                deviceConnected = false
                if (deviceConnected == false && ControlConnect == false) {
                    wx.showToast({
                        title: '设备未连接', // 标题
                        icon: 'success', // 图标类型，默认success
                        duration: 900 // 提示窗停留时间，默认1500ms
                    })
                    ControlConnect = true
                } 
            }  
        }, 

        fail(res) {
            console.log("请求失败---2")
            wx.showToast({
                title: '设备未连接', // 标题
                icon: 'false', // 图标类型，默认success
                duration: 900 // 提示窗停留时间，默认1500ms
            })
            deviceConnected = false
        },
        complete() {
            if (deviceConnected) {
                that.setData({
                    deviceConnected: true
                })

            } else {
                that.setData({
                    deviceConnected: false
                })
            }
        }
    })
}

function deviceInit(that) //对信息的回传
{
    //初始化各个硬件的状态
    wx.request({
        url: getDataStreamURL,
        header: {
            'content-type': 'application/x-www-form-urlencoded',
            "api-key": apikey
        },
        data: {
            data: 0
        },
        success(res) {
            var datattest
            datattest = res.data.data[2].current_value
            //console.log(res.data.data);
            let LightData = [{
                Chandelier1: res.data.data[6].current_value, //吊灯开灯状态
                Chandelier2: res.data.data[7].current_value,
                ChanderierStatus2: res.data.data[20].current_value, //吊灯状态
                SpotMeet1: res.data.data[8].current_value,
                SpotMeet2: res.data.data[9].current_value,
                SpotBar1: res.data.data[10].current_value,
                SpotBar2: res.data.data[11].current_value,
                SpotOffice1: res.data.data[12].current_value,
                SpotOffice2: res.data.data[13].current_value,
                Auxiliary_Bright_1: res.data.data[21].current_value,
                Auxiliary_Bright_2: res.data.data[22].current_value,
                Auxiliary_Bright_3: res.data.data[23].current_value,
                Auxiliary_Bright_4: res.data.data[24].current_value,
                Auxiliary_Bright_5: res.data.data[25].current_value,
                Auxiliary_Bright_6: res.data.data[26].current_value,
                Auxiliary_Color_1: res.data.data[27].current_value,
                Auxiliary_Color_2: res.data.data[28].current_value,
                Auxiliary_Color_3: res.data.data[29].current_value,
                Auxiliary_Color_4: res.data.data[30].current_value,
                Auxiliary_Color_5: res.data.data[31].current_value,
                Auxiliary_Color_6: res.data.data[32].current_value,
                AllAuxiliary_Color: res.data.data[37].current_value,
                AllAuxiliary_Bright: res.data.data[36].current_value,
                AllSpotLight: res.data.data[39].current_value,
            }]
            let LedData = [{
                All_Led_0: res.data.data[46].current_value,
                LedMeet1: res.data.data[40].current_value,
                LedMeet2: res.data.data[41].current_value,
                LedBar1: res.data.data[42].current_value,
                LedBar2: res.data.data[43].current_value,
                LedOffice1: res.data.data[44].current_value,
                LedOffice2: res.data.data[45].current_value,
            }]
            let AirData = [{
                AirStatus: res.data.data[1].current_value,
                AirFan: res.data.data[2].current_value,
                Air_LR: res.data.data[3].current_value,
                Air_UD: res.data.data[4].current_value,
                AirMode: res.data.data[5].current_value,
                AirTemp: res.data.data[19].current_value,
                OutSideTemp:res.data.data[47].current_value,
                OutSideTemp:res.data.data[48].current_value,
            }]
            let CurtainsData = [{
                Curtain_Status_1: res.data.data[14].current_value,
                Curtain_Status_2: res.data.data[15].current_value,
                Curtain_Status_3: res.data.data[16].current_value,
                AllCurtain_Status: res.data.data[35].current_value,
            }]
            let WindowData = [{
                Window_Status_1: res.data.data[33].current_value,
                Window_Status_2: res.data.data[34].current_value,
                AllWindow_Status: res.data.data[33].current_value,//暂时是33---第一幅窗
            }]
            let WindData = [{ 
                WindSpeed: res.data.data[17].current_value,
                WindMode: res.data.data[18].current_value,
                Weather:res.data.data[49].current_value,
            }] 
            //--------------------------------主界面赋值--灯光
            that.setData({ 
                AllAuxiliary_Bright: res.data.data[36].current_value,
                AirStatus: res.data.data[1].current_value,
                AirTemp:res.data.data[19].current_value
            }) 
            //看是否要全开所有灯
            if ( res.data.data[36].current_value > 0) { //这个里面是没有判断led灯是否开了的状态
                that.setData({
                    AllLight: true,
                })
            } else { 
                that.setData({
                    AllLight: false, 
                }) 
            }
            //------窗帘
            switch (res.data.data[35].current_value) {
                case 1: //下
                    that.setData({
                        AllCurtains: 1
                    })
                    break;
                case 0: //上
                    that.setData({
                        AllCurtains: 0
                    })
                    break;
            }
            //----窗户---暂时改成33
            switch (res.data.data[33].current_value) {
                case 1: //开
                    that.setData({
                        AllWindow: 1
                    })
                    break;
                case 2: //关
                    that.setData({
                        AllWindow: 0
                    })
                    break; 
            }
            //----新风
            if (res.data.data[17].current_value > 0) {
                that.setData({
                    WindStatus: 1
                }) 
            } else {
                that.setData({
                    WindStatus: 0
                })
            }
            //----
            switch (that.data.AirMode) {
                case 1:
                    that.setData({
                        AirMode:"制冷"
                    })
                    break;
                case 2:
                    that.setData({
                        AirMode:"制热"
                    })
                    break;
                case 3:
                    that.setData({
                        AirMode:"除湿"
                    })
                    break;
                case 4:
                    that.setData({
                        AirMode:"送风"
                    })
                    break;
            }
            //----------------------------------------------------
            //本地缓存数据----并整理成包  
            wx.setStorageSync('Light', LightData)
            wx.setStorageSync('Air', AirData)
            wx.setStorageSync('Curtains', CurtainsData)
            wx.setStorageSync('Window', WindowData)
            wx.setStorageSync('Wind', WindData)
            wx.setStorageSync('LedData', LedData)
        }
    })
}

function SendData(hardware_id) //发送指令
{
    // console.log("发送命令：" + hardware_id + ":{" + switch_value + "}")
    //console.log("发送命令：" + hardware_id + ":" +switch_value )
    console.log(hardware_id)
    //按钮发送命令控制硬件
    wx.request({
        url: sendCommandURL + "?device_id=" + deviceid,
        method: 'POST',
        header: {
            'content-type': 'application/x-www-form-urlencoded', 
            "api-key": apikey
        },
        // data: hardware_id + ":{" + switch_value + "}",      //TODO 设计自定义语言 blueled:{V}, 预感这边可能会有问题
        //data: hardware_id + switch_value, //可以直接把：去掉
        data: hardware_id,
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
        AllLight: false,
        AllAuxiliary_Bright: 0,
        AirStatus: false,
        AllCurtains: false,
        AllWindow: false,
        WindStatus: false,
        AirMode:"制冷",
        AirTemp:26
    },
    onLoad: function () {
        //加载时完成1.检查设备是否连接2.连接成功将数据显示在界面
        var that = this //将当前对象赋值
        getDeviceInfo(that)
    },
    onShow: function () {
        //TODO依旧有问题
        var that = this
        var timer = setInterval(function () {
            getDeviceInfo(that)
        }, 500) //最好的是1000
        var timer2 = setInterval(function () {
            wx.clearStorageSync()
        }, 8000) //清理内存
    },
    //----------------------页面跳转 
    Window_NavigateTo: function () {
        wx.navigateTo({
            url: '../Window/Window?id='
        })
    },
    Light_NavigateTo: function () {
        wx.navigateTo({
            url: '../LED/LED?id='
        })
    },
    Cutrains_NavigateTo: function () {
        wx.navigateTo({
            url: '../Curtain/Curtain?id='
        })
    },
    Air_NavigateTo: function () {
        wx.navigateTo({
            url: '../Air/Air?id=' 
        })
    },
    Wind_NavigateTo: function () {
        wx.navigateTo({
            url: '../Wind/Wind?id='
        })
    },
    Switch_Light(e) {
        var data = e.detail.value
        var SendToRasp
        if (data == true) {
            this.setData({
                AllAuxiliary_Bright: 100
            }) 
            SendToRasp = "20300" + "99"
        } else { 
            this.setData({
                AllAuxiliary_Bright: 0
            })
            SendToRasp = "20300" + "00"
        }
        SendData(SendToRasp)
    },

    //--- 
    AuxiliaryLight_All(e) {
        var data = e.detail.value - 1
        var SendToRasp
        if (0 < data && data < 10) {
            data = "0" + data 
        } else if (data <= 0) {
            data = "00"
        }
        SendToRasp = "20300" + data
        SendData(SendToRasp)
    },
    //
    Switch_Wind(e) {
        var data = e.detail.value ? 1 : 0
        var SendToRasp
        SendToRasp = "601010" + data
        SendData(SendToRasp)
    },
    //----
    Switch_Air(e) {
        var data = e.detail.value ? 1 : 0
        var SendToRasp
        SendToRasp = "202010" + data
        SendData(SendToRasp)
    },
    Switch_Curtains(e) {
        var data = e.detail.value ? 1 : 0
        var SendToRasp
        SendToRasp = "102000" + data
        SendData(SendToRasp)
    },
    Switch_Window(e) {
        var data = e.detail.value ? 1 : 0
        if (data != 0) { 
            SendData(1010101)
        } else { 
            SendData(1010102)
        }
    }
})