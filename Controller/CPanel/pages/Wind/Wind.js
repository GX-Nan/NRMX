// pages/Air/Control.js
const app = getApp()
// const apikey = "eNIzhrJ8mW0Pol4phyvUZj6EKRA="//我的
// const deviceid = '501311474'//我的
const apikey = '7h6qKecs94Z=ZIKq=yutanCVh30=' //开启老版模式才有
// const deviceid = '798017394'//
const deviceid = '998964151' //

var deviceConnected = false

var StopSend = false //取消回传

const deviceInfoURL = "https://api.heclouds.com/devices/" + deviceid
const getDataStreamURL = "https://api.heclouds.com/devices/" + deviceid + "/datastreams"
const sendCommandURL = "https://api.heclouds.com/cmds"

function SendData(hardware_id) //发送指令----发送指令没有影响
{
    if (StopSend == 0) {
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
    var WindData = wx.getStorageSync('Wind')

    if (WindData != "") {
        StopSend = true
        console.log(WindData)
        that.setData({
            WindSpeed: WindData[0].WindSpeed * 10,
            WindMode: WindData[0].WindMode,
            Weather:WindData[0].Weather
        })

        if (that.data.WindSpeed != 0) {
            switch (that.data.WindSpeed) {
                case 10:
                    that.setData({
                        WindSpeed_Text: "低速"
                    })
                    break
                case 20:
                    that.setData({
                        WindSpeed_Text: "中速"
                    })
                    break
                case 30:
                    that.setData({
                        WindSpeed_Text: "高速"
                    })
                    break
            }
            switch (that.data.WindMode) {
                case 0:
                    that.ModeButton_Clear()
                    break;
                case 5:
                    that.Button_Natural()
                    break;
                case 6:
                    that.Button_Solid()
                    break;
                case 7:
                    that.Button_Sea()
                    break;
                case 8:
                    that.Button_Arround()
                    break;
            }
            
        } else {
            that.ModeButton_Clear()
            that.setData({
                WindSpeed_Text: "无"
            })
        }
        StopSend = false
    }
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
        }, 1000) //最好的是1000
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
        WindSpeed: 0,
        WindMode: 0,
        WindSpeed_Text: "无",
        //----------
        Sea_Background: "#ffffff",
        Sea_color: "#000000",
        //-----------
        Arround_Background: "#ffffff",
        Arround_color: "#000000",
        //-----------
        Natural_Background: "#ffffff",
        Natural_color: "#000000",
        //-----------
        Solid_Background: "#ffffff",
        Solid_color: "#000000",
        //------
        Weather:0,
    },
    ModeButton_Clear: function () {
        this.setData({
            Sea_Background: "#ffffff",
            Sea_color: "#000000",
            //-----------
            Arround_Background: "#ffffff",
            Arround_color: "#000000",
            //-----------
            Natural_Background: "#ffffff",
            Natural_color: "#000000",
            //-----------
            Solid_Background: "#ffffff",
            Solid_color: "#000000",
        })
    },
    Slider_WindSpeedTest: function (e) {
        switch (e.detail.value) {
            case 0:
                this.setData({
                    WindSpeed_Text: "无"
                })
                break;
            case 10:
                this.setData({
                    WindSpeed_Text: "低速"
                })
                break;
            case 20:
                this.setData({
                    WindSpeed_Text: "中速"
                })
                break;
            case 30:
                this.setData({
                    WindSpeed_Text: "高速"
                })
                break;
        }
    },
    Slider_WindSpeed: function (e) {
        var SendToRasp
        switch (e.detail.value) {
            case 0:
                this.setData({
                    WindSpeed_Text: "无"
                })
                SendToRasp = "6010100"
                break;
            case 10:
                this.setData({
                    WindSpeed_Text: "低速"
                })
                SendToRasp = "6010101"
                break;
            case 20:
                this.setData({
                    WindSpeed_Text: "中速"
                })
                SendToRasp = "6010102"
                break;
            case 30:
                this.setData({
                    WindSpeed_Text: "高速"
                })
                SendToRasp = "6010103"
                break;
        }
        SendData(SendToRasp)
    },
    Button_Sea: function () {
        if (this.data.WindMode == 1) {
            this.ModeButton_Clear()
            this.setData({
                WindMode: 0
            })
            SendData("6010104")
        } else {
            this.Button_Color_Change(1)
            SendData("6010107")
        }
    },
    Button_Arround: function () { //8

        if (this.data.WindMode == 2) {
            this.ModeButton_Clear()
            this.setData({
                WindMode: 0
            })
            SendData("6010104")
        } else {
            this.Button_Color_Change(2)
            SendData("6010108")
        }
    },
    Button_Natural: function () { //5
        if (this.data.WindMode == 3) {
            this.ModeButton_Clear()
            this.setData({
                WindMode: 0
            })
            SendData("6010104")
        } else {
            this.Button_Color_Change(3)
            SendData("6010105")
        }
    },
    Button_Solid: function () { //6
        if (this.data.WindMode == 4) {
            this.ModeButton_Clear()
            this.setData({
                WindMode: 0
            })
            SendData("6010104")
        } else {
            this.Button_Color_Change(4)
            SendData("6010106")
        }
    },
    Button_Color_Change: function (e) {
        switch (e) {
            case 1:
                this.setData({
                    //--------
                    Sea_Background: "#000000",
                    Sea_color: "#ffffff",
                    //-----------
                    Arround_Background: "#ffffff",
                    Arround_color: "#000000",
                    //-----------
                    Natural_Background: "#ffffff",
                    Natural_color: "#000000",
                    //-----------
                    Solid_Background: "#ffffff",
                    Solid_color: "#000000",
                    WindMode: 1
                })
                break;
            case 2:
                this.setData({
                    //--------
                    Sea_Background: "#ffffff",
                    Sea_color: "#000000",
                    //-----------
                    Arround_Background: "#000000",
                    Arround_color: "#ffffff",
                    //-----------
                    Natural_Background: "#ffffff",
                    Natural_color: "#000000",
                    //-----------
                    Solid_Background: "#ffffff",
                    Solid_color: "#000000",
                    WindMode: 2
                })
                break;
            case 3:
                this.setData({
                    //--------
                    Sea_Background: "#ffffff",
                    Sea_color: "#000000",
                    //-----------
                    Arround_Background: "#ffffff",
                    Arround_color: "#000000",
                    //-----------
                    Natural_Background: "#000000",
                    Natural_color: "#ffffff",
                    //-----------
                    Solid_Background: "#ffffff",
                    Solid_color: "#000000",
                    WindMode: 3
                })
                break;
            case 4:
                this.setData({
                    //--------
                    Sea_Background: "#ffffff",
                    Sea_color: "#000000",
                    //-----------
                    Arround_Background: "#ffffff",
                    Arround_color: "#000000",
                    //-----------
                    Natural_Background: "#ffffff",
                    Natural_color: "#000000",
                    //-----------
                    Solid_Background: "#000000",
                    Solid_color: "#ffffff",
                    WindMode: 4
                })
                break;
        }
    },


})