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
      text:"好看",
      time:2,
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