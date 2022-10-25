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

var Testdata = [{}]
var UpdateTime = 6

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

function Page_Init(that) {
    var LightData = wx.getStorageSync('Light')
    var LedData = wx.getStorageSync('LedData')

    if (LightData != "") {
        that.setData({
            //-----------------------------------------------------------//Missing辅灯
            AuxiliaryLight_AllBright: LightData[0].AllAuxiliary_Bright, //全部亮度--辅灯
            AuxiliaryLight_MissingBright_1: LightData[0].Auxiliary_Bright_1,
            AuxiliaryLight_MissingBright_2: LightData[0].Auxiliary_Bright_2,
            AuxiliaryLight_MissingBright_3: LightData[0].Auxiliary_Bright_3,
            AuxiliaryLight_MissingColor_1: LightData[0].Auxiliary_Color_1,
            AuxiliaryLight_MissingColor_2: LightData[0].Auxiliary_Color_2,
            AuxiliaryLight_MissingColor_3: LightData[0].Auxiliary_Color_3,
            //-----------------------------------------------------------//office辅灯
            AuxiliaryLight_AllColor: LightData[0].AllAuxiliary_Color + 1, //全部色温---辅灯
            AuxiliaryLight_OfficeBright_1: LightData[0].Auxiliary_Bright_4,
            AuxiliaryLight_OfficeBright_2: LightData[0].Auxiliary_Bright_5,
            AuxiliaryLight_OfficeBright_3: LightData[0].Auxiliary_Bright_6,
            AuxiliaryLight_OfficeColor_1: LightData[0].Auxiliary_Color_4,
            AuxiliaryLight_OfficeColor_2: LightData[0].Auxiliary_Color_5,
            AuxiliaryLight_OfficeColor_3: LightData[0].Auxiliary_Color_6,
            //------------------射灯--------------------
            Spotlight_All: LightData[0].AllSpotLight,
            SpotLight_Bar_1: LightData[0].SpotBar1,
            SpotLight_Bar_2: LightData[0].SpotBar2,
            SpotLight_Office_1: LightData[0].SpotOffice1,
            SpotLight_Office_2: LightData[0].SpotOffice2,
            SpotLight_Missing_1: LightData[0].SpotMeet1,
            SpotLight_Missing_2: LightData[0].SpotMeet2,
            //-----------------吊灯------------------
            Chandelier_Bar: LightData[0].Chandelier2,
            Chandelier_Status_2: LightData[0].ChanderierStatus2,
        })
        if (LedData != "") {
            that.setData({
                Led_All: LedData[0].All_Led_0,
                Led_Missing_1: LedData[0].LedMeet1, 
                Led_Missing_2: LedData[0].LedMeet2,
                Led_Bar_1: LedData[0].LedBar1,
                Led_Bar_2: LedData[0].LedBar2, 
                Led_Office_1: LedData[0].LedOffice1,
                Led_Office_2: LedData[0].LedOffice2,
            })
        } 
        //----------
        //吊灯
        that.Chandelier_Status(that.data.Chandelier_Status_1)
        that.Chandelier_Status(that.data.Chandelier_Status_2)
        //辅灯
        if (that.data.AuxiliaryLight_AllBright > 0) {
            that.setData({
                AuxiliaryLight_All: true
            })
        } else {
            that.setData({
                AuxiliaryLight_All: false
            })
        }
    }
    console.log(that.data.Spotlight_All)


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
    data: {
        //--缓存

        //---------办公模式-
        Office_BackgroundColor: '#ffffff', //原始白,
        Office_FontColor: '#000000',
        //----------------休闲模式
        Leisure_BackgroundColor: '#ffffff',
        Leisure_FontColor: '#000000',
        //-----------------酒吧模式
        Bar_BackgroundColor: '#ffffff',
        Bar_FontColor: '#000000',
        //-----------------Spotlight
        Spotlight_All: 0,
        SpotLight_Bar_1: 0,
        SpotLight_Bar_2: 0,
        SpotLight_Office_1: 0,
        SpotLight_Office_2: 0,
        SpotLight_Missing_1: 0,
        SpotLight_Missing_2: 0,
        //-----------------Chandelier
        Chandelier_All: 0,
        Chandelier_Missing: 0,
        Chandelier_Bar: 0,
        Chandelier_Status_1: 0,
        Chandelier_Status_2: 0,
        //-----------------auxiliary 辅灯
        AuxiliaryLight_All: 0,
        AuxiliaryLight_AllColor: 0,
        AuxiliaryLight_AllBright: 0,

        AuxiliaryLight_MissingColor_1: 0,
        AuxiliaryLight_MissingBright_1: 0,

        AuxiliaryLight_MissingColor_2: 0,
        AuxiliaryLight_MissingBright_2: 0,

        AuxiliaryLight_MissingColor_3: 0,
        AuxiliaryLight_MissingBright_3: 0,

        AuxiliaryLight_OfficeColor_1: 0,
        AuxiliaryLight_OfficeBright_1: 0,

        AuxiliaryLight_OfficeColor_2: 0,
        AuxiliaryLight_OfficeBright_2: 0,

        AuxiliaryLight_OfficeColor_3: 0,
        AuxiliaryLight_OfficeBright_3: 0,
        //-----------------LED
        Led_All: 0,
        Led_Missing_1: 0,
        Led_Missing_2: 0,
        Led_Office_1: 0,
        Led_Office_2: 0,
        Led_Bar_1: 0,
        Led_Bar_2: 0,
        //------------射灯弹窗
        Spotlight_Sub: 0,
        SpotIcon: "iconfont icon-gaoliangtoujingdadeng",
        SpotText: "会议射灯-1",
        //-----------------------射灯-滚动条数据
        TemporarySpot: 0,
        scrollLeft: 0,
        selectItemIndex: 0,
        itemview: 'item7',
        // value: '',
        datalist: [{
                date: "",
            },
            {
                date: "",
            },
            {
                date: "",
            },
            {
                date: "",
            },
            {
                date: "",
            },
            {
                date: "",
            },
        ],
        //------------LED弹窗
        Led_Sub: 0,
        LedIcon: "iconfont icon-gaoliangtoujingdadeng",
        LedText: "会议射灯-1",
        //-----------------------LED-滚动条数据
        Led_TemporarySpot: 0,
        Led_scrollLeft: 0,
        Led_selectItemIndex: 0,
        Led_itemview: 'item7',
        // value: '',
        Led_datalist: [{
                date: "",
            },
            {
                date: "",
            },
            {
                date: "",
            },
            {
                date: "",
            },
            {
                date: "",
            },
            {
                date: "",
            },
        ],
        //------------辅灯弹窗
        Auxiliary_Sub: 0,
        AuxiliaryIcon: "iconfont icon-gaoliangtoujingdadeng",
        AuxiliaryText: "会议射灯-1",
        //-----------------------AuxiliaryLight-滚动条数据
        Auxiliary_TemporarySpot: 0,
        Auxiliary_scrollLeft: 0,
        Auxiliary_selectItemIndex: 0,
        Auxiliary_itemview: 'item7',
        // value: '',
        Auxiliary_datalist: [{
                date: "",
            },
            {
                date: "",
            },
            {
                date: "",
            },
            {
                date: "",
            },
            {
                date: "",
            },
            {
                date: "",
            },
        ],
        //------------吊灯弹窗
        Chandelier_Sub: 0,
        ChandelierIcon: "iconfont icon-gaoliangtoujingdadeng",
        ChandelierText: "会议射灯-1",
        //------------------
        ChandelierColor_Font_Up: "#000000",
        ChandelierBackgroundColor_Up: "#ffffff",
        //------------------
        ChandelierColor_Font_Stop: "#ffffff",
        ChandelierBackgroundColor_Stop: "#000000",
        //------------------
        ChandelierColor_Font_Down: "#000000",
        ChandelierBackgroundColor_Down: "#ffffff",
        //-----------------------Chandelier-滚动条数据
        Chandelier_scrollLeft: 0,
        Chandelier_selectItemIndex: 0,
        Chandelier_itemview: 'item7',
        // value: '', 
        Chandelier_datalist: [{
                date: "",
            },
            {
                date: "",
            },
        ],


    },
    Chandelier_Status_Judge: function (e) {
        var data = e.currentTarget.id;
        var SendToRasp
        if (data == "MissingUp") {
            this.setData({
                Chandelier_Status_1: 1
            })
            this.Chandelier_Status(this.data.Chandelier_Status_1)
        } else if (data == "MissingStop") {
            this.setData({
                Chandelier_Status_1: 3
            })
            this.Chandelier_Status(this.data.Chandelier_Status_1)
        } else if (data == "MissingDown") {
            this.setData({
                Chandelier_Status_1: 2
            })
            this.Chandelier_Status(this.data.Chandelier_Status_1)
        } else if (data == "BarUp") {
            this.setData({
                Chandelier_Status_2: 1
            })
            SendToRasp="2040101"
            this.Chandelier_Status(this.data.Chandelier_Status_2)
        } else if (data == "BarStop") {
            this.setData({
                Chandelier_Status_2: 3
            })
            SendToRasp="2040103"
            this.Chandelier_Status(this.data.Chandelier_Status_2)
        } else if (data == "BarDown") {
            this.setData({
                Chandelier_Status_2: 2
            })
            SendToRasp="2040102"
            this.Chandelier_Status(this.data.Chandelier_Status_2)
        }
        SendData(SendToRasp)
    },
    Chandelier_Status: function (e) {
        if (e == 1) {
            this.setData({
                //------------------
                ChandelierColor_Font_Up: "#ffffff",
                ChandelierBackgroundColor_Up: "#000000",
                //------------------ 
                ChandelierColor_Font_Stop: "#000000",
                ChandelierBackgroundColor_Stop: "#ffffff",
                //------------------
                ChandelierColor_Font_Down: "#000000",
                ChandelierBackgroundColor_Down: "#ffffff",
            })
        } else if (e == 3) {
            this.setData({
                //------------------
                ChandelierColor_Font_Up: "#000000",
                ChandelierBackgroundColor_Up: "#ffffff",
                //------------------
                ChandelierColor_Font_Stop: "#ffffff",
                ChandelierBackgroundColor_Stop: "#000000",
                //------------------
                ChandelierColor_Font_Down: "#000000",
                ChandelierBackgroundColor_Down: "#ffffff",
            })
        } else if (e == 2) {
            this.setData({
                //------------------
                ChandelierColor_Font_Up: "#000000",
                ChandelierBackgroundColor_Up: "#ffffff",
                //------------------
                ChandelierColor_Font_Stop: "#000000",
                ChandelierBackgroundColor_Stop: "#ffffff",
                //------------------
                ChandelierColor_Font_Down: "#ffffff",
                ChandelierBackgroundColor_Down: "#000000",
            })
        }
    },
    //----辅灯亮度
    slider1change_Brightness: function (e) {
        var data = e.detail.value - 1
        var SendToRasp
        //----------------switch 开关
        if (e.detail.value > 0) {
            this.setData({
                AuxiliaryLight_All: true
            })
        } else {
            this.setData({
                AuxiliaryLight_All: false
            })
        }
        //----------------------------
        if (0 < data && data < 10) {
            data = "0" + data
        } else if (data <= 0) {
            data = "00"
        }
        SendToRasp = "20300" + data
        SendData(SendToRasp)
    },
    //----辅灯色温
    slider1change_Color: function (e) {
        var data = e.detail.value - 1
        var SendToRasp
        if (0 < data && data < 10) {
            data = "0" + data
        } else if (data <= 0) {
            data = "00"
        }
        SendToRasp = "20100" + data
        SendData(SendToRasp)
    },

    //工作模式
    OfficeChange: function () {
        var data = this.data.Office_BackgroundColor;
        var Falg = this.data.Mutex;
        if (data == '#ffffff') {
            this.setData({
                Office_BackgroundColor: '#DDAB1D', //#FBFB53
                Office_FontColor: '#ffffff',
                //-------------------
                Leisure_BackgroundColor: '#ffffff', //#FBFB53
                Leisure_FontColor: '#000000',
                //------------------
                Bar_BackgroundColor: '#ffffff', //#FBFB53
                Bar_FontColor: '#000000',
            });
        } else {
            this.setData({
                Office_BackgroundColor: '#ffffff',
                Office_FontColor: '#000000',
            });
        }
    },
    //休闲模式
    LsisureChange: function () {
        var data = this.data.Leisure_BackgroundColor;
        var Falg = this.data.Mutex;
        if (data == '#ffffff') {
            this.setData({
                Leisure_BackgroundColor: '#DDAB1D', //#FBFB53
                Leisure_FontColor: '#ffffff',
                //-------------------
                Office_BackgroundColor: '#ffffff', //#FBFB53
                Office_FontColor: '#000000',
                //------------------
                Bar_BackgroundColor: '#ffffff', //#FBFB53
                Bar_FontColor: '#000000',
            });
        } else {
            this.setData({
                Leisure_BackgroundColor: '#ffffff',
                Leisure_FontColor: '#000000',
            });
        }
    },

    //酒吧模式
    BarChange: function () {
        var data = this.data.Bar_BackgroundColor;
        var Falg = this.data.Mutex;
        if (data == '#ffffff') {
            this.setData({
                Bar_BackgroundColor: '#DDAB1D', //#FBFB53
                Bar_FontColor: '#ffffff',
                //-------------------
                Leisure_BackgroundColor: '#ffffff', //#FBFB53
                Leisure_FontColor: '#000000',
                //-------------------
                Office_BackgroundColor: '#ffffff', //#FBFB53
                Office_FontColor: '#000000',
            });
        } else {
            this.setData({
                Bar_BackgroundColor: '#ffffff',
                Bar_FontColor: '#000000',
            });
        }
    },
    //----------------------开关函数
    SpotLight_All(e) {
        var data = e.detail.value ? 1 : 0
        var data = "205000" + data
        SendData(data)
        this.setData({
            Spotlight_All: data
        })
    },
    Chandelier_All(e) {
        var data = e.detail.value ? 1 : 0
        var chanderData1 = "204010" + data
        var chanderData2 = "204020" + data
        SendData(chanderData1)
        SendData(chanderData2)
        this.setData({
            Chandelier_All: data
        })
    },
    Swtich_AuxiliaryLight_All(e) {
        var data = e.detail.value ? 1 : 0
        var SendToRasp
        if (data == true) {
            this.setData({
                AuxiliaryLight_AllBright: 100,
            })
            SendToRasp = "2030" + this.data.AuxiliaryLight_AllBright - 1
        } else {
            this.setData({
                AuxiliaryLight_AllBright: 0,
            })
            SendToRasp = "20300" + "00"
        }
        SendData(SendToRasp)
    },
    Led_All(e) {
        var data = e.detail.value ? 1 : 0
        var SendToRasp = "206000" + data
        this.setData({
            Led_All: data
        })
        SendData(SendToRasp)
    },
    //-------------------射灯弹窗触发
    Spotlight_Sub: function () {
        this.setData({
            Spotlight_Sub: true
        })
    },
    Spotlight_Sub_Close: function () {
        this.setData({
            Spotlight_Sub: false
        })
    },
    //------------------Led弹窗触发
    Led_Sub: function () {
        this.setData({
            Led_Sub: true
        })
    },
    Led_Sub_Close: function () {
        this.setData({
            Led_Sub: false
        })
    },
    //------------------辅灯弹窗触发
    Auxiliary_Sub: function () {
        this.setData({
            Auxiliary_Sub: true
        })
    },
    Auxiliary_Sub_Close: function () {
        this.setData({
            Auxiliary_Sub: false
        })
    },
    //------------------吊灯弹窗触发
    Chandelier_Sub: function () {
        this.setData({
            Chandelier_Sub: true
        })
    },
    Chandelier_Sub_Close: function () {
        this.setData({
            Chandelier_Sub: false
        })
    },

    //----------------------------------------------------------------------------------滚动条--射灯
    dianji: function (event) {
        var itemid = event.target.id;
        var index = event.target.dataset.index;
        this.setData({
            selectItemIndex: index,
        })
        var ele = itemid
        this.getRect('#' + ele)
        switch (index) {
            case 0:
                this.setData({
                    SpotIcon: "iconfont icon-gaoliangtoujingdadeng",
                    SpotText: "会议射灯-1"
                })
                break;
            case 1:
                this.setData({
                    SpotIcon: "iconfont icon-gaoliangtoujingdadeng",
                    SpotText: "会议射灯-2"
                })
                break;
            case 2:
                this.setData({
                    SpotIcon: "iconfont icon-jiuba",
                    SpotText: "吧台射灯-1"
                })
                break;
            case 3:
                this.setData({
                    SpotIcon: "iconfont icon-jiuba",
                    SpotText: "吧台射灯-2"
                })
                break;
            case 4:
                this.setData({
                    SpotIcon: "iconfont icon-bangongzhuo",
                    SpotText: "办公区射灯-1"
                })
                break;
            case 5:
                this.setData({
                    SpotIcon: "iconfont icon-bangongzhuo",
                    SpotText: "办公区射灯-2"
                })
                break;
        }
    },
    Judge: function (e) {
        var data = e.detail.value ? 1 : 0
        var Item = this.data.selectItemIndex
        var SendToRasp
        switch (Item) {
            case 0:
                this.setData({
                    SpotLight_Missing_1: data,
                })
                break;
            case 1:
                this.setData({
                    SpotLight_Missing_2: data,
                })
                break;
            case 2:
                this.setData({
                    SpotLight_Bar_1: data,
                })
                break;
            case 3:
                this.setData({
                    SpotLight_Bar_2: data,
                })
                break;
            case 4:
                this.setData({
                    SpotLight_Office_1: data,
                })
                break;
            case 5:
                this.setData({
                    SpotLight_Office_2: data,
                })
                break;
        }
        if (this.data.SpotLight_Missing_1 == this.data.SpotLight_Missing_2 == this.data.SpotLight_Bar_1 == this.data.SpotLight_Bar_2 == this.data.SpotLight_Office_1 == this.data.SpotLight_Office_2) {
            this.setData({
                SpotLight_All:this.data.SpotLight_Missing_1
            })
        }
        console.log("spotlight_all:"+this.data.SpotLight_All)
        SendToRasp = "2050" + String(Item + 1) + "0" + data
        SendData(SendToRasp)
    },
    getRect: function (ele) {
        var that = this
        wx.createSelectorQuery().select(ele).boundingClientRect(function (rect) {
            //   console.log(JSON.stringify(rect))--->详细的数据
            //获取屏幕的宽度的一半
            var screen = wx.getSystemInfoSync().windowWidth / 2;
            //获取点击item的左边坐标
            var left = rect.left;
            //获取item的宽度de 一半
            var subhalfwidth = rect.width / 2
            //需要scrollview 移动的距离是
            var juli = left - screen
            var zuizhongjuli = juli + subhalfwidth
            that.setData({
                scrollLeft: that.data.scrollLeft += zuizhongjuli
            })
        }).exec()
    },
    //转动滚轮时的计算离左边有多远
    scrollMove(e) {
        //  console.log(e)---->打印信息
        var scrollLeft = e.detail.scrollLeft;
        this.data.scrollLeft = scrollLeft
    },
    //-------------------------------------------------------------------------------------滚动条Led
    Led_Checked: function (event) {
        var itemid = event.target.id;
        var index = event.target.dataset.index;
        this.setData({
            Led_selectItemIndex: index,
        })
        var ele = itemid
        this.getRect('#' + ele)
        switch (index) {
            case 0:
                this.setData({
                    LedIcon: "iconfont icon-gaoliangtoujingdadeng",
                    LedText: "会议主灯-1"
                })
                break;
            case 1:
                this.setData({
                    LedIcon: "iconfont icon-gaoliangtoujingdadeng",
                    LedText: "会议主灯-2"
                })
                break;
            case 2:
                this.setData({
                    LedIcon: "iconfont icon-jiuba",
                    LedText: "吧台主灯-1"
                })
                break;
            case 3:
                this.setData({
                    LedIcon: "iconfont icon-jiuba",
                    LedText: "吧台主灯-2"
                })
                break;
            case 4:
                this.setData({
                    LedIcon: "iconfont icon-bangongzhuo",
                    LedText: "办公区主灯-1"
                })
                break;
            case 5:
                this.setData({
                    LedIcon: "iconfont icon-bangongzhuo",
                    LedText: "办公区主灯-2"
                })
                break;
        }
    },
    Led_Judge: function (e) {
        var data = e.detail.value ? 1 : 0
        var Item = this.data.Led_selectItemIndex
        var SendToRasp
        switch (Item) {
            case 0:
                this.setData({
                    Led_Missing_1: data,
                })
                break;
            case 1:
                this.setData({
                    Led_Missing_2: data,
                })
                break;
            case 2:
                this.setData({
                    Led_Bar_1: data,
                })
                break;
            case 3:
                this.setData({
                    Led_Bar_2: data,
                })
                break;
            case 4:
                this.setData({
                    Led_Office_1: data,
                })
                break;
            case 5:
                this.setData({
                    Led_Office_2: data,
                })
                break;
        }
        if (this.data.Led_Missing_1 == this.data.Led_Missing_1 == this.data.Led_Bar_1 == this.data.Led_Bar_2 == this.data.Led_Office_1 == this.data.Led_Office_2) {
            this.setData({
                Led_All: this.data.Led_Missing_1
            })
        }
        SendToRasp = "2060" + String(Item + 1) + "0" + data
        SendData(SendToRasp)
    },
    Led_getRect: function (ele) {
        var that = this
        wx.createSelectorQuery().select(ele).boundingClientRect(function (rect) {
            //   console.log(JSON.stringify(rect))--->详细的数据
            //获取屏幕的宽度的一半
            var screen = wx.getSystemInfoSync().windowWidth / 2;
            //获取点击item的左边坐标
            var left = rect.left;
            //获取item的宽度de 一半
            var subhalfwidth = rect.width / 2
            //需要scrollview 移动的距离是
            var juli = left - screen
            var zuizhongjuli = juli + subhalfwidth
            that.setData({
                Led_scrollLeft: that.data.scrollLeft += zuizhongjuli
            })
        }).exec()
    },
    //转动滚轮时的计算离左边有多远
    Led_scrollMove(e) {
        //  console.log(e)---->打印信息
        var scrollLeft = e.detail.scrollLeft;
        this.data.scrollLeft = Led_scrollLeft
    },
    //------------------------------------------------------------------------------------辅灯
    Auxiliary_Checked: function (event) {
        var itemid = event.target.id;
        var index = event.target.dataset.index;
        this.setData({
            Auxiliary_selectItemIndex: index,
        })
        var ele = itemid
        this.getRect('#' + ele)
        switch (index) {
            case 0:
                this.setData({
                    AuxiliaryIcon: "iconfont icon-gaoliangtoujingdadeng",
                    AuxiliaryText: "会议辅灯-1"
                })
                break;
            case 1:
                this.setData({
                    AuxiliaryIcon: "iconfont icon-gaoliangtoujingdadeng",
                    AuxiliaryText: "会议辅灯-2"
                })
                break;
            case 2:
                this.setData({
                    AuxiliaryIcon: "iconfont icon-gaoliangtoujingdadeng",
                    AuxiliaryText: "会议辅灯-3"
                })
                break;
            case 3:
                this.setData({
                    AuxiliaryIcon: "iconfont icon-bangongzhuo",
                    AuxiliaryText: "办公区辅灯-1"
                })
                break;
            case 4:
                this.setData({
                    AuxiliaryIcon: "iconfont icon-bangongzhuo",
                    AuxiliaryText: "办公区辅灯-2"
                })
                break;
            case 5:
                this.setData({
                    AuxiliaryIcon: "iconfont icon-bangongzhuo",
                    AuxiliaryText: "办公区辅灯-3"
                })
                break;
        }
    },
    Auxiliary_Slider_Color_ToRasp: function (e) {
        var data = e.detail.value - 1
        var Item = this.data.Auxiliary_selectItemIndex
        var SendToRasp
        if (0 < data && data < 10) {
            data = "0" + data
        } else if (data <= 0) {
            data = "00"
        }
        SendToRasp = "2010" + String(Item + 1) + data
        SendData(SendToRasp)
    },
    Auxiliary_Slider_Color: function (e) {
        var data = e.detail.value
        var Item = this.data.Auxiliary_selectItemIndex
        switch (Item) {
            case 0:
                this.setData({
                    AuxiliaryLight_MissingColor_1: data,
                })
                break;
            case 1:
                this.setData({
                    AuxiliaryLight_MissingColor_2: data,
                })
                break;
            case 2:
                this.setData({
                    AuxiliaryLight_MissingColor_3: data,
                })
                break;
            case 3:
                this.setData({
                    AuxiliaryLight_OfficeColor_1: data,
                })
                break;
            case 4:
                this.setData({
                    AuxiliaryLight_OfficeColor_2: data,
                })
                break;
            case 5:
                this.setData({
                    AuxiliaryLight_OfficeColor_3: data,
                })
                break;
        }
    },
    Auxiliary_Slider_Bright_ToRasp: function (e) {
        var data = e.detail.value - 1
        var Item = this.data.Auxiliary_selectItemIndex
        var SendToRasp
        if (0 < data && data < 10) {
            data = "0" + data
        } else if (data <= 0) {
            data = "00"
        }
        // console.log(e.detail.value-1)
        SendToRasp = "2030" + String(Item + 1) + data
        SendData(SendToRasp)
    },
    Auxiliary_Slider_Bright: function (e) {
        var data = e.detail.value
        var Item = this.data.Auxiliary_selectItemIndex
        switch (Item) {
            case 0:
                this.setData({
                    AuxiliaryLight_MissingBright_1: data,
                })
                break;
            case 1:
                this.setData({
                    AuxiliaryLight_MissingBright_2: data,
                })
                break;
            case 2:
                this.setData({
                    AuxiliaryLight_MissingBright_3: data,
                })
                break;
            case 3:
                this.setData({
                    AuxiliaryLight_OfficeBright_1: data,
                })
                break;
            case 4:
                this.setData({
                    AuxiliaryLight_OfficeBright_2: data,
                })
                break;
            case 5:
                this.setData({
                    AuxiliaryLight_OfficeBright_3: data,
                })
                break;
        }

    },
    Auxiliary_getRect: function (ele) {
        var that = this
        wx.createSelectorQuery().select(ele).boundingClientRect(function (rect) {
            //   console.log(JSON.stringify(rect))--->详细的数据
            //获取屏幕的宽度的一半
            var screen = wx.getSystemInfoSync().windowWidth / 2;
            //获取点击item的左边坐标
            var left = rect.left;
            //获取item的宽度de 一半
            var subhalfwidth = rect.width / 2
            //需要scrollview 移动的距离是
            var juli = left - screen
            var zuizhongjuli = juli + subhalfwidth
            that.setData({
                Auxiliary_scrollLeft: that.data.scrollLeft += zuizhongjuli
            })
        }).exec()
    },
    //转动滚轮时的计算离左边有多远
    Auxiliary_scrollMove(e) {
        //  console.log(e)---->打印信息
        var scrollLeft = e.detail.scrollLeft;
        this.data.scrollLeft = Auxiliary_scrollLeft
    },
    //-------------------------------------------------------------------吊灯-----滚动条
    Chandelier_Checked: function (event) {
        var itemid = event.target.id;
        var index = event.target.dataset.index;
        this.setData({
            Chandelier_selectItemIndex: index,
        })
        var ele = itemid
        this.getRect('#' + ele)
        switch (index) {
            case 0:
                this.setData({
                    ChandelierIcon: "iconfont icon-gaoliangtoujingdadeng",
                    ChandelierText: "会议吊灯"
                })
                this.Chandelier_Status(this.data.Chandelier_Status_1)
                break;
            case 1:
                this.setData({
                    ChandelierIcon: "iconfont icon-jiuba",
                    ChandelierText: "吧台吊灯"
                })
                this.Chandelier_Status(this.data.Chandelier_Status_2)
                break;

        }
    },
    Chandelier_Judge: function (e) {
        var data = e.detail.value ? 1 : 0
        var Item = this.data.Chandelier_selectItemIndex
        var SendToRasp
        switch (Item) {
            case 0:
                SendToRasp = "204020" + 5
                this.setData({
                    Chandelier_Missing: data,
                })
                SendToRasp = "204020" + 5
                break;
            case 1:
                this.setData({
                    Chandelier_Bar: data,
                })
                switch(data)
                {
                    case 0:
                        SendToRasp = "2040104" 
                        break;
                    case 1:
                        SendToRasp = "2040105"
                        break;
                }
                break;
        }
        SendData(SendToRasp)
    },
    Chandelier_getRect: function (ele) {
        var that = this
        wx.createSelectorQuery().select(ele).boundingClientRect(function (rect) {
            //   console.log(JSON.stringify(rect))--->详细的数据
            //获取屏幕的宽度的一半
            var screen = wx.getSystemInfoSync().windowWidth / 2;
            //获取点击item的左边坐标
            var left = rect.left;
            //获取item的宽度de 一半
            var subhalfwidth = rect.width / 2
            //需要scrollview 移动的距离是
            var juli = left - screen
            var zuizhongjuli = juli + subhalfwidth
            that.setData({
                Chandelier_scrollLeft: that.data.scrollLeft += zuizhongjuli
            })
        }).exec()
    },
    //转动滚轮时的计算离左边有多远
    Chandelier_scrollMove(e) {
        //  console.log(e)---->打印信息
        var scrollLeft = e.detail.scrollLeft;
        this.data.scrollLeft = Chandelier_scrollLeft
    },
})