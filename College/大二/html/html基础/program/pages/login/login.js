// pages/login/login.js
Page({

  /**
   * 页面的初始数据
   */
  data: {
    passwordTest: true
  },

  jumpRegister: function() {
    wx.navigateTo({
      url: '/pages/register/register',
    })
  },

  jumpForget:function() {
    wx.navigateTo({
      url: '/pages/forget/forget',
    })
  },

  jumpUserXY:function() {
    wx.navigateTo({
      url: '/pages/xieyi/xieyi',
    })
  },
  
  jumpCertification : function() {
    wx.navigateTo({
      url: '/pages/certification/certification',
    })
  },

  changePasswordMode: function() {
    if ( this.data.passwordTest == true) {
      this.setData({
        passwordTest: false
      })
    } else {
      this.setData({
        passwordTest: true
      })
    }
  }
  
})