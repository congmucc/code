// index.js
// 获取应用实例
const app = getApp()

Page({
  data: {
  },
  onTap: function(e){
    wx.switchTab({
      url: '/pages/home/home'
    })
  }
})
