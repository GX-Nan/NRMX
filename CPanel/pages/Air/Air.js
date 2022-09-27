// pages/Air/Control.js
Page({

    /**
     * 页面的初始数据
     */
    data: {
        Air_status: 0,
        Air_Mode: 0,
        Air_Speed: 0,
        Air_Temp: 26,
        //-----------
        Air_Switch_background:"#ffffff",
        Air_Swtich_Color:"#000000",
        //-----
        Low_Background:"#ffffff",
        Low_color:"#000000",
        //-----
        Mid_Background:"#ffffff",
        Mid_color:"#000000",
        //-----
        High_Background:"#ffffff",
        High_color:"#000000",
        //------
        Auto_Background:"#ffffff",
        Auto_color:"#000000",
        //------
        Heat_Background:"#ffffff",
        Heat_color:"#000000",
        //------
        Cold_Background:"#ffffff",
        Cold_color:"#000000",
        //------
        Wind_Background:"#ffffff",
        Wind_color:"#000000",
        //------
        Dehumidify_Background:"#ffffff",
        Dehumidify_color:"#000000",
    },
    Slider_Temp: function (e) {
        this.setData({
            Air_Temp:e.detail.value
        })
    },
    Button_AirSwitch:function()
    {
        var data=this.data.Air_Switch_background
        if(data=="#ffffff")
        {
            this.setData({
                Air_Switch_background:"#000000",
                Air_Swtich_Color:"#ffffff"
            })
        }
        else
        {
            this.setData({
                Air_Switch_background:"#ffffff",
                Air_Swtich_Color:"#000000"
            })
        }
    },
    Low_Switch:function()
    {
        var data=this.data.Low_Background
         if(data=="#ffffff")
        {
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
        }
    },
    Mid_Switch:function()
    {
        var data=this.data.Mid_Background
         if(data=="#ffffff")
        {
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
        }
    },
    High_Switch:function()
    {
        var data=this.data.High_Background
         if(data=="#ffffff")
        {
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
        }
    },
    Auto_Switch:function()
    {
        var data=this.data.Auto_Background
         if(data=="#ffffff")
        {
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
        }
    },

    Button_Cold:function()
    {
        var data=this.data.Cold_Background
         if(data=="#ffffff")
        {
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
        }
    },
    Button_Wind:function()
    {
        var data=this.data.Wind_Background
         if(data=="#ffffff")
        {
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
        }
    },

    Button_Heat:function()
    {
        var data=this.data.Heat_Background
         if(data=="#ffffff")
        {
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
        }
    },

    Button_Dehumidify:function()
    {
        var data=this.data.Dehumidify_Background
         if(data=="#ffffff")
        {
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
        }
    },


})