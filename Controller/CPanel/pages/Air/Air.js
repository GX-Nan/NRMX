// pages/Air/Control.js
// pages/LED/LED.js
const app = getApp()
// const apikey = "eNIzhrJ8mW0Pol4phyvUZj6EKRA="//我的
// const deviceid = '501311474'//我的
const apikey = '7h6qKecs94Z=ZIKq=yutanCVh30=' //开启老版模式才有
// const deviceid = '798017394'//
const deviceid = '998964151' //

var deviceConnected = false
var StopSend = false
const deviceInfoURL = "https://api.heclouds.com/devices/" + deviceid
const getDataStreamURL = "https://api.heclouds.com/devices/" + deviceid + "/datastreams"
const sendCommandURL = "https://api.heclouds.com/cmds"

function SendData(hardware_id) //发送指令----发送指令没有影响
{
    if (StopSend == false) {
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
            data: hardware_id, //可以直接把：去掉
            success(res) {
                console.log("控制成功")
                console.log(res)
            }
        })
    }
}

function Page_Init(that) {
    var AirData = wx.getStorageSync('Air')
    StopSend = true
    if (AirData != "") {
        that.setData({
            Air_status: AirData[0].AirStatus,
            Air_Temp: AirData[0].AirTemp,
            Air_Mode: AirData[0].AirMode,
            Air_Speed: AirData[0].AirFan,
        })
        if (that.data.Air_status == 1) {
            that.setData({
                Air_Switch_background: "#000000",
                Air_Swtich_Color: "#ffffff"
            })
        } else {
            that.setData({
                Air_Switch_background: "#ffffff",
                Air_Swtich_Color: "#000000"
            })
        }
        if (that.data.Air_status == 1) {
            switch (that.data.Air_Mode) {
                case 1:
                    that.Button_Cold()
                    break;
                case 2:
                    that.Button_Heat()
                    break;
                case 3:
                    that.Button_Dehumidify()
                    break;
                case 4:
                    that.Button_Wind()
                    break;
            }
            switch (that.data.Air_Speed) {
                case 0: //自动
                    break;
                case 1:
                    that.Low_Switch()
                    break;
                case 2:
                    that.Mid_Switch()
                    break;
                case 3:
                    that.High_Switch()
                    break;
            }
        } else {
            that.setData({
                //-----------
                Air_Switch_background: "#ffffff",
                Air_Swtich_Color: "#000000",
                //-----
                Low_Background: "#ffffff",
                Low_color: "#000000",
                //-----
                Mid_Background: "#ffffff",
                Mid_color: "#000000",
                //-----
                High_Background: "#ffffff",
                High_color: "#000000",
                //------
                Auto_Background: "#ffffff",
                Auto_color: "#000000",
                //------
                Heat_Background: "#ffffff",
                Heat_color: "#000000",
                //------
                Cold_Background: "#ffffff",
                Cold_color: "#000000",
                //------
                Wind_Background: "#ffffff",
                Wind_color: "#000000",
                //------
                Dehumidify_Background: "#ffffff",
                Dehumidify_color: "#000000",
            })
        }
    }
    StopSend = false
}
Page({

    /**
     * 生命周期函数--监听页面加载
     */
    onLoad: function (options) {

    },
    /**
     * 生命周期函数--监听页面初次渲染完成
     */
    onReady: function () {

    },
    /**
     * 生命周期函数--监听页面显示
     */
    onShow: function () {
        var that = this
        var timer = setInterval(function () {
            Page_Init(that)
        }, 1500) //最好的是1000
    },
    /**
     * 生命周期函数--监听页面隐藏
     */
    onHide: function () {

    },
    /**
     * 生命周期函数--监听页面卸载
     */
    onUnload: function () {

    },
    /**
     * 页面相关事件处理函数--监听用户下拉动作
     */
    onPullDownRefresh: function () {

    },
    /**
     * 页面上拉触底事件的处理函数
     */
    onReachBottom: function () {

    },
    /**
     * 用户点击右上角分享
     */
    onShareAppMessage: function () {

    },
    /**
     * 页面的初始数据
     */
    data: {
        Air_status: 0,
        Air_Mode: 0,
        Air_Speed: 0,
        Air_Temp: 26,
        //-----------
        Air_Switch_background: "#ffffff",
        Air_Swtich_Color: "#000000",
        //-----
        Low_Background: "#ffffff",
        Low_color: "#000000",
        //-----
        Mid_Background: "#ffffff",
        Mid_color: "#000000",
        //-----
        High_Background: "#ffffff",
        High_color: "#000000",
        //------
        Auto_Background: "#ffffff",
        Auto_color: "#000000",
        //------
        Heat_Background: "#ffffff",
        Heat_color: "#000000",
        //------
        Cold_Background: "#ffffff",
        Cold_color: "#000000",
        //------
        Wind_Background: "#ffffff",
        Wind_color: "#000000",
        //------
        Dehumidify_Background: "#ffffff",
        Dehumidify_color: "#000000",
    },
    Slider_Temp: function (e) {
        this.setData({
            Air_Temp: e.detail.value
        })
    },
    Button_AirSwitch: function () {
        var data = this.data.Air_Switch_background
        if (data == "#ffffff") { //开
            this.setData({
                Air_Switch_background: "#000000",
                Air_Swtich_Color: "#ffffff"
            })
            SendData(2020101)
        } else {
            this.setData({ //关
                Air_Switch_background: "#ffffff",
                Air_Swtich_Color: "#000000"
                //-------------------

            })
            SendData(2020100)
        }
    },
    Low_Switch: function () {
        var data = this.data.Low_Background
        if (data == "#ffffff") {
            this.setData({
                Low_Background: "#000000",
                Low_color: "#ffffff",
                //----------------
                Mid_Background: "#ffffff",
                Mid_color: "#000000",
                //----------------
                High_Background: "#ffffff",
                High_color: "#000000",
                //----------------
                Auto_Background: "#ffffff",
                Auto_color: "#000000",
            })
            SendData(2020102)
        }
    },
    Mid_Switch: function () {
        var data = this.data.Mid_Background
        if (data == "#ffffff") {
            this.setData({

                Low_Background: "#ffffff",
                Low_color: "#000000",
                //----------------
                Mid_Background: "#000000",
                Mid_color: "#ffffff",
                //----------------
                High_Background: "#ffffff",
                High_color: "#000000",
                //----------------
                Auto_Background: "#ffffff",
                Auto_color: "#000000",
            })
            SendData(2020103)
        }
    },
    High_Switch: function () {
        var data = this.data.High_Background
        if (data == "#ffffff") {
            this.setData({

                Low_Background: "#ffffff",
                Low_color: "#000000",
                //----------------
                Mid_Background: "#ffffff",
                Mid_color: "#000000",
                //----------------
                High_Background: "#000000",
                High_color: "#ffffff",
                //----------------
                Auto_Background: "#ffffff",
                Auto_color: "#000000",
            })
            SendData(2020104)
        }
    },
    Auto_Switch: function () {
        var data = this.data.Auto_Background
        if (data == "#ffffff") {
            this.setData({
                Low_Background: "#ffffff",
                Low_color: "#000000",
                //----------------
                Mid_Background: "#ffffff",
                Mid_color: "#000000",
                //----------------
                High_Background: "#ffffff",
                High_color: "#000000",
                //----------------
                Auto_Background: "#000000",
                Auto_color: "#ffffff",
            })
            SendData(2020113)
        }
    },

    Button_Cold: function () {
        var data = this.data.Cold_Background
        if (data == "#ffffff") {
            this.setData({

                Cold_Background: "#000000",
                Cold_color: "#ffffff",
                //----------------
                Wind_Background: "#ffffff",
                Wind_color: "#000000",
                //----------------
                Dehumidify_Background: "#ffffff",
                Dehumidify_color: "#000000",
                //----------------
                Heat_Background: "#ffffff",
                Heat_color: "#000000",
            })
            SendData(2020109)
        }
    },
    Button_Wind: function () {
        var data = this.data.Wind_Background
        if (data == "#ffffff") {
            this.setData({

                Cold_Background: "#ffffff",
                Cold_color: "#000000",
                //----------------
                Wind_Background: "#000000",
                Wind_color: "#ffffff",
                //----------------
                Dehumidify_Background: "#ffffff",
                Dehumidify_color: "#000000",
                //----------------
                Heat_Background: "#ffffff",
                Heat_color: "#000000",
            })
            SendData(2020114)
        }
    },

    Button_Heat: function () {
        var data = this.data.Heat_Background
        if (data == "#ffffff") {
            this.setData({

                Cold_Background: "#ffffff",
                Cold_color: "#000000",
                //----------------
                Wind_Background: "#ffffff",
                Wind_color: "#000000",
                //----------------
                Dehumidify_Background: "#ffffff",
                Dehumidify_color: "#000000",
                //----------------
                Heat_Background: "#000000",
                Heat_color: "#ffffff",
            })
            SendData(2020111)
        }
    },

    Button_Dehumidify: function () {
        var data = this.data.Dehumidify_Background
        if (data == "#ffffff") {
            this.setData({

                Cold_Background: "#ffffff",
                Cold_color: "#000000",
                //----------------
                Wind_Background: "#ffffff",
                Wind_color: "#000000",
                //----------------
                Dehumidify_Background: "#000000",
                Dehumidify_color: "#ffffff",
                //----------------
                Heat_Background: "#ffffff",
                Heat_color: "#000000",
            })
            SendData(2020110)
        }
    },
    Air_Temp: function (e) {
        var data = e.detail.value 
        var SendToRasp
        SendToRasp = "20201"  + data
        SendData(SendToRasp)
    }
})