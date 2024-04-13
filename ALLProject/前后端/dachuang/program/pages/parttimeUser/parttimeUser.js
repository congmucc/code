// pages/parttimeUser/parttimeUser.js
Page({

  /**
   * 页面的初始数据
   */
  data: {

  },

  // 发布申请
  goParttime:function() {
    wx.navigateTo({
      url: '/pages/parttime/parttime',
    })
  },

  // 发布状态
  goState:function(){
    wx.navigateTo({
      url: '/pages/parttimeState/parttimeState',
    })
  },

  // 兼职管理
  goParttimeManagement:function(){
    wx.navigateTo({
      url: '/pages/parttimeManagement/parttimeManagement',
    })
  },

  // 简直反馈
  goParttimeFeedback:function(){
    wx.navigateTo({
      url: '/pages/actFeedback/actFeedback',
    })
  },

  /**
   * 生命周期函数--监听页面加载
   */
  onLoad(options) {

  },

  /**
   * 生命周期函数--监听页面初次渲染完成
   */
  onReady() {

  },

  /**
   * 生命周期函数--监听页面显示
   */
  onShow() {

  },

  /**
   * 生命周期函数--监听页面隐藏
   */
  onHide() {

  },

  /**
   * 生命周期函数--监听页面卸载
   */
  onUnload() {

  },

  /**
   * 页面相关事件处理函数--监听用户下拉动作
   */
  onPullDownRefresh() {

  },

  /**
   * 页面上拉触底事件的处理函数
   */
  onReachBottom() {

  },

  /**
   * 用户点击右上角分享
   */
  onShareAppMessage() {

  }
})