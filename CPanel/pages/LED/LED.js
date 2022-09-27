// pages/LED/LED.js
Page({

    /**
     * 页面的初始数据
     */
    data: {
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
        Chandelier_1: 0,
        Chandelier_2: 0,
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
    Chandelier_Status: function (e) {

        var data = e.currentTarget.id;
        console.log(data);
        if (data == "Up") {
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
        } else if (data == "Stop") {
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
        } else if (data == "Down") {
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
        console.log("change：", e.detail.value)
    },
    //----辅灯色温
    slider1change_Color: function (e) {
        console.log("change：", e.detail.value)
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
        var data = e.detail.value
        this.setData({
            Spotlight_All: data
        })
        console.log(data)
    },
    Chandelier_All(e) {
        var data = e.detail.value
        this.setData({
            Chandelier_All: data
        })
        console.log(data)
    },
    AuxiliaryLight_All(e) {
        var data = e.detail.value
        this.setData({
            AuxiliaryLight_All: data
        })
        console.log(data)
    },
    Led_All(e) {
        var data = e.detail.value
        this.setData({
            Led_All: data
        })
        console.log(data)
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
        console.log(index)
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
        var data = e.detail.value
        var Item = this.data.selectItemIndex
        console.log(e)
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
        console.log(index)
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
        var data = e.detail.value
        var Item = this.data.Led_selectItemIndex
        console.log(e)
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
        console.log(index)
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
    Auxiliary_Slider_Color: function (e) {
        var data = e.detail.value
        var Item = this.data.Auxiliary_selectItemIndex
        console.log(e)
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
    Auxiliary_Slider_Bright: function (e) {
        var data = e.detail.value
        var Item = this.data.Auxiliary_selectItemIndex
        console.log(e)
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
        console.log(index)
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
                break;
            case 1:
                this.setData({
                    ChandelierIcon: "iconfont icon-jiuba",
                    ChandelierText: "吧台吊灯"
                })
                break;

        }
    },
    Chandelier_Judge: function (e) {
        var data = e.detail.value
        var Item = this.data.Chandelier_selectItemIndex
        console.log(e)
        switch (Item) {
            case 0:
                this.setData({
                    Chandelier_Missing_1: data,
                })
                break;
            case 1:
                this.setData({
                    Chandelier_Missing_2: data,
                })
                break;
        }
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