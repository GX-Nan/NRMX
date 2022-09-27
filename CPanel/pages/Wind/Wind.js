// pages/Air/Control.js
Page({

  /**
   * 页面的初始数据
   */
  data: {
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
  },

  Button_Sea:function()
  {
    this.Button_Color_Change(1)
  },
  Buttion_Arround:function()
  {
    this.Button_Color_Change(2)
  },
  Buttion_Natural:function()
  {
    this.Button_Color_Change(3)
  },
  Buttion_Solid:function()
  {
    this.Button_Color_Change(4)
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
        })
        break;
    }
  },


})