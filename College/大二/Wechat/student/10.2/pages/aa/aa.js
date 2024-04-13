// pages/aa/aa.js
var a=null
var video=null
var danmuvalue=""
Page({

  /**
   * 页面的初始数据
   */
  data: {

    danmulist:[

    {
      text:"我吉祥实名开导",
      time:2,
    },
    {
      text:"我一波实名开导",
      time:4,
    },
    {
      text:"我凯凯实名开导",
      time:3,
    },
    {
      text:"我杨杨实名开导",
      time:1,
    },
    {
      text:"我欣欣实名开导",
      time:6,
    }

    ],



  },

  getdanmu(e)
  {
    danmuvalue=e.detail.value
    console.log("第一个数",danmuvalue)
  },
  send()
  {
    video.sendDanmu({
      text:danmuvalue
    })
  },
  /**
   * 生命周期函数--监听页面加载
   */
  onLoad: function (options) {

  },

  /**
   * 生命周期函数--监听页面初次渲染完成
   */
  onReady: function () {
    video=wx.createVideoContext('dance')
  },

  /**
   * 生命周期函数--监听页面显示
   */
  onShow: function () {

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

  }
})