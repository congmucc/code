// pages/02/02.js
Page({
  tapMe: function() {
    wx.showNavigationBarLoading(),
    wx.setNavigationBarColor({
      frontColor: '#ffffff',
      backgroundColor: '#ff0000',
      animation: {
        duration: 400,
        timingFunc: 'easeIn'
      }
    }),
    setTimeout(() => {
      wx.hideNavigationBarLoading()
    }, 3000)
  }
})