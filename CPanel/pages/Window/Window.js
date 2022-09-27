// pages/Window/Window.js
Page({


    onLoad: function (options) {
        console.log(options);
    },
    /**
     * 页面的初始数据
     */
    data: {
        Window_Status_1: 2,
        Window_Status_2: 2,
        index: 1,
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
        Window_Index_Background_1: "#000000",
        Window_Index_Color_1: "#ffffff",
        //---
        Window_Index_Background_2: "#ffffff",
        Window_Index_Color_2: "#000000",
        //--------------
        Window_Progress_Value_1:0,
        Window_Progress_Value_2:0,
    },

    Button_Up: function () {
        var Index = this.data.index
        switch (Index) {
            case 1:
                this.setData({
                    Window_Status_1: 1
                })
                break;
            case 2:
                this.setData({
                    Window_Status_2: 1
                })
                break;
        }
        this.Button_Color_Change(1)
    },
    Button_Stop: function () {
        var Index = this.data.index
        switch (Index) {
            case 1:
                this.setData({
                    Window_Status_1: 2
                })
                break;
            case 2:
                this.setData({
                    Window_Status_2: 2
                })
                break;
        }
        this.Button_Color_Change(2)
    },
    Button_Down: function () {
        var Index = this.data.index
        switch (Index) {
            case 1:
                this.setData({
                    Window_Status_1: 3
                })
                break;
            case 2:
                this.setData({
                    Window_Status_2: 3
                })
                break;
        }
        console.log(this.data.index)
        console.log(this.data.Window_Status_2)
        this.Button_Color_Change(3)
    },
    Window_Status_Change: function (e) {
        var id = e.currentTarget.id
        var status1 = this.data.Window_Status_1
        var status2 = this.data.Window_Status_2
        if (id == "Window_1") {
            switch (status1) {
                case 1:
                    this.Button_Color_Change(1)
                    break;
                case 2:
                    this.Button_Color_Change(2)
                    break
                case 3:
                    this.Button_Color_Change(3)
                    break;
            }
            this.setData({
                //---
                Window_Index_Background_1: "#000000",
                Window_Index_Color_1: "#ffffff",
                //---
                Window_Index_Background_2: "#ffffff",
                Window_Index_Color_2: "#000000",
                index:1
            })
        } else if (id == "Window_2") {
            switch (status2) {
                case 1:
                    this.Button_Color_Change(1)
                    break;
                case 2:
                    this.Button_Color_Change(2)
                    break
                case 3:
                    this.Button_Color_Change(3)
                    break;
            }
            this.setData({
                //---
                Window_Index_Background_1: "#ffffff",
                Window_Index_Color_1: "#000000",
                //---
                Window_Index_Background_2: "#000000",
                Window_Index_Color_2: "#ffffff",
                index:2
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
    Slider_Window:function(e){
        var data=e.detail.value
        this.setData({
            Window_Progress_Value_1:data
        })
    }
})