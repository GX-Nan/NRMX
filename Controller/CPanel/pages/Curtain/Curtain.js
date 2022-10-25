// pages/Curtain/Curtain.js
// pages/Air/Control.js
// pages/LED/LED.js
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

function SendData(hardware_id) //发送指令----发送指令没有影响
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
        data: hardware_id, //可以直接把：去掉
        success(res) {
            console.log("控制成功")
            console.log(res)
        }
    })
}

function Page_Init(that) {
    var CurtainsData = wx.getStorageSync('Curtains')
    var CurtainsIndex
    if (CurtainsData != "") {
        that.setData({
            Curtain_Status_1: CurtainsData[0].Curtain_Status_1,
            Curtain_Status_2: CurtainsData[0].Curtain_Status_2,
            Curtain_Status_3: CurtainsData[0].Curtain_Status_3,
        })
        switch (that.data.Pageindex) {
            case 1:
                CurtainsIndex = that.data.Curtain_Status_1
                break;
            case 2:
                CurtainsIndex = that.data.Curtain_Status_2
                break;
            case 3:
                CurtainsIndex = that.data.Curtain_Status_3
                break
        }

        switch (CurtainsIndex) {
            case 0: //上
                that.Button_Color_Change(1)
                break;
            case 1: //下
                that.Button_Color_Change(3)
                break
            case 4: //停止
                that.Button_Color_Change(2)
                break;
        }
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
        Curtain_Status_1: null,
        Curtain_Status_2: null,
        Curtain_Status_3: null,
        Pageindex: 1,
        //-------------------
        Up_Background: "#ffffff",
        Up_color: "#000000",
        //-----
        Stop_Background: "#000000",
        Stop_color: "#ffffff",
        //-----
        Down_Background: "#ffffff",
        Down_color: "#000000",
        //---
        Curtain_Index_Background_1: "#000000",
        Curtain_Index_Color_1: "#ffffff",
        //---
        Curtain_Index_Background_2: "#ffffff",
        Curtain_Index_Color_2: "#000000",
        //---
        Curtain_Index_Background_3: "#ffffff",
        Curtain_Index_Color_3: "#000000",
        //--------------
        Curtain_Progress_Value_1: 0,
        Curtain_Progress_Value_2: 0,
    },

    Button_Up: function () {
        var Index = this.data.Pageindex
        var SendToRasp
        switch (Index) {
            case 1:
                this.setData({
                    Curtain_Status_1: 0
                })
                break;
            case 2:
                this.setData({
                    Curtain_Status_2: 0
                })
                break;
            case 3:
                this.setData({
                    Curtain_Status_3: 0
                })
        }
        SendToRasp = "1020" + Index + "0" + 0
        SendData(SendToRasp)
        this.Button_Color_Change(1)
    },
    Button_Stop: function () {
        var Index = this.data.Pageindex
        var SendToRasp
        switch (Index) {
            case 1:
                this.setData({
                    Curtain_Status_1: 4
                })
                break;
            case 2:
                this.setData({
                    Curtain_Status_2: 4
                })
                break;
            case 3:
                this.setData({
                    Curtain_Status_3: 4
                })
                break;
        }
        SendToRasp = "1020" + Index + "0" + 4
        SendData(SendToRasp)
        this.Button_Color_Change(2)
    },
    Button_Down: function () {
        var Index = this.data.Pageindex
        var SendToRasp
        switch (Index) {
            case 1:
                this.setData({
                    Curtain_Status_1: 1
                })
                break;
            case 2:
                this.setData({
                    Curtain_Status_2: 1
                })
                break;
            case 3:
                this.setData({
                    Curtain_Status_3: 1
                })
                break;
        }
        SendToRasp = "1020" + Index + "0" + 1
        SendData(SendToRasp)
        this.Button_Color_Change(3)
    },
    Curtain_Status_Change: function (e) {//切換序列数字后自动更新状态
        var id = e.currentTarget.id
        var status1 = this.data.Curtain_Status_1
        var status2 = this.data.Curtain_Status_2
        var status3 = this.data.Curtain_Status_3
        if (id == "Curtain_1") {
            switch (status1) {
                case 1:
                    this.Button_Color_Change(0)
                    break;
                case 2:
                    this.Button_Color_Change(4)
                    break
                case 3:
                    this.Button_Color_Change(1)
                    break;
            }
            this.setData({
                //---
                Curtain_Index_Background_1: "#000000",
                Curtain_Index_Color_1: "#ffffff",
                //---
                Curtain_Index_Background_2: "#ffffff",
                Curtain_Index_Color_2: "#000000",
                //---
                Curtain_Index_Background_3: "#ffffff",
                Curtain_Index_Color_3: "#000000",
                Pageindex: 1,
            })
        } else if (id == "Curtain_2") {
            switch (status2) {
                case 1:
                    this.Button_Color_Change(0)
                    break;
                case 2:
                    this.Button_Color_Change(4)
                    break
                case 3:
                    this.Button_Color_Change(1)
                    break;
            }
            this.setData({
                //---
                Curtain_Index_Background_1: "#ffffff",
                Curtain_Index_Color_1: "#000000",
                //---
                Curtain_Index_Background_2: "#000000",
                Curtain_Index_Color_2: "#ffffff",
                //---
                Curtain_Index_Background_3: "#ffffff",
                Curtain_Index_Color_3: "#000000",
                Pageindex: 2
            })
        } else if (id == "Curtain_3") {
            switch (status3) {
                case 1:
                    this.Button_Color_Change(0)
                    break;
                case 2:
                    this.Button_Color_Change(4)
                    break
                case 3:
                    this.Button_Color_Change(1)
                    break;
            }
            this.setData({
                //---
                Curtain_Index_Background_1: "#ffffff",
                Curtain_Index_Color_1: "#000000",
                //---
                Curtain_Index_Background_2: "#ffffff",
                Curtain_Index_Color_2: "#000000",
                //--- 
                Curtain_Index_Background_3: "#000000",
                Curtain_Index_Color_3: "#ffffff",
                Pageindex: 3
            })
        }
    }, 

    Button_Color_Change: function (e) {
        switch (e) {
            case 1:
                this.setData({
                    //-------------------
                    Up_Background: "#000000",
                    Up_color: "#ffffff",
                    //-----
                    Stop_Background: "#ffffff",
                    Stop_color: "#000000",
                    //-----
                    Down_Background: "#ffffff",
                    Down_color: "#000000",
                })
                break;
            case 2:
                this.setData({
                    //-------------------
                    Up_Background: "#ffffff",
                    Up_color: "#000000",
                    //-----
                    Stop_Background: "#000000",
                    Stop_color: "#ffffff",
                    //-----
                    Down_Background: "#ffffff",
                    Down_color: "#000000",
                })
                break;
            case 3:
                this.setData({
                    //-------------------
                    Up_Background: "#ffffff",
                    Up_color: "#000000",
                    //-----
                    Stop_Background: "#ffffff",
                    Stop_color: "#000000",
                    //-----
                    Down_Background: "#000000",
                    Down_color: "#ffffff",
                })
                break;
        }
    },
    Slider_Curtain: function (e) {
        var data = e.detail.value
        this.setData({
            Curtain_Progress_Value_1: data
        })
    }
})