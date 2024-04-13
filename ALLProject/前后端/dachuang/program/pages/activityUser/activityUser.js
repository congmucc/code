import {
  requestUtil
} from '../../utils/requestUtil.js'


// pages/activityUser/activityUser.js
Page({

  /**
   * 页面的初始数据
   */
  data: {
    avatarUrl: '',
    nickName: '',
  },


  // 活动申请
  goActivity: function () {
    wx.navigateTo({
      url: '/pages/activity/activity',
    })
  },

  // 申请状态
  goState: function () {
    wx.navigateTo({
      url: '/pages/activityState/activityState',
    })
  },

  // 活动管理
  goActManagement: function () {
    wx.navigateTo({
      url: '/pages/actManagement/actManagement',
    })
  },

  goActFeedback: function () {
    wx.navigateTo({
      url: '/pages/actFeedback/actFeedback',
    })
  },

  /**
   * 生命周期函数--监听页面加载
   */
  onLoad(options) {
    const token = wx.getStorageSync('openid');
    this.setData({
      avatarUrl: token.avatarUrl,
      nickName: token.nickName
    })
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