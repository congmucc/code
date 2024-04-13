// pages/01/01.js
Page({
  onLoad(options) {

  },
  tapMe1: function(e) {
    // 信息提示框API
    wx.showToast({
      title: 'title',
      duration: 1500,
      icon: 'success',
      image: '',
      mask: true,
      success: (res) => {
        console.log(res)
      },
      fail: (res) => {},
      complete: (res) => {},
    })
  },

  tapMe2: function(e) {
    // 模态框API
    wx.showModal({
      title: '标题',
      content: '内容',
      showCancel:'true',
      cancelText:'取消',
      cancelColor:'#00ff00',
      complete: (res) => {
        if (res.cancel) {
          
        }
    
        if (res.confirm) {
          console.log("点击了确定")
        }
      }
    })
  },

  tapMe3: function(e) {
    // loading提示框
    wx.showLoading({
      title: 'title',
      mask: true,
      success: (res) => {
        console.log("需要手动关闭loading框"),
        // 设定一个定时器。在定时到期以后执行注册的回调函数
        setTimeout(() => {
          wx.hideLoading()
        }, 2000)
      },
      fail: (res) => {},
      complete: (res) => {},
    })
  },

  tapMe4: function(e) {
    // 显示菜单提示框
    wx.showActionSheet({
      itemList: ['a', 'b', 'c'],
    })
  },

})
