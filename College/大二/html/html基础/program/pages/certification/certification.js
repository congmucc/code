

// pages/forget/forget.js
Page({

  /**
   * 页面的初始数据
   */
  data: {
    select:false,
    peopleSelectWay:'请选择你的身份',
    showImage_url:''
  },

  // 下拉框
  bindShowMsg() {
    this.setData({
      select:!this.data.select
    })
  },
  // 下拉框
  mySelect(e) {
    var name = e.currentTarget.dataset.name;
    this.setData({
      peopleSelectWay:name,
      select:false
    })
  },

  // 上传图片至后台
  uploadimg: function(e) {
    var that = this;
    //选择图片
    wx.chooseImage({
      count: 9, // 默认9
      sizeType: ['original', 'compressed'], // 可以指定是原图还是压缩图，默认二者都有
      sourceType: ['album', 'camera'], // 可以指定来源是相册还是相机，默认二者都有
      success: function(res) {
        // 返回选定照片的本地文件路径列表，tempFilePath可以作为img标签的src属性显示图片
        var tempFilePaths = res.tempFilePaths[0]
        that.setData({
          showImage_url: tempFilePaths
        })
        //图片上传
        wx.uploadFile({
          url: '',//调用后台接口的路径
          method:'POST',
          filePath: that.data.showImage_url,
          name: 'file',//此处注意要与后台保持一致
          header: {
            "Content-Type": false,
          },
          //formdata:adds,
          success: function(res) {}
        })
      }
    })
  },

  // formsubmit: function(e) {
  //   this.setData({
  //     orderImage: e.detail.value.orderImage,
  //     orderText: e.detail.value.orderText
  //   })
  //   const wxreq = wx.request({
  //     url: '',//后台接口路径
  //     data: {
  //       'orderText': this.data.orderText,
  //       'orderImage': this.data.showImage_url
  //     },
  //     method: 'POST', // OPTIONS, GET, HEAD, POST, PUT, DELETE, TRACE, CONNECT  
  //     header: {
  //       'Content-Type': "application/x-www-form-urlencoded",
  //       'Cookie': 'SESSION=' + wx.getStorageSync("sessionId")
  //     }, // 设置请求的 header 
  //     success: function (res) {
  //       console.log("提交任务成功");
  //       wx.navigateTo({//页面跳转
  //         url: '/pages/index/index',
  //       })
  //       wx.showModal({//提示弹框
  //         title: '提示',
  //         content: '提交成功，请耐心等待审核。',
  //         showCancel: false, //是否显示取消按钮 
  //         fail: function (res) { }, //接口调用失败的回调函数
  //         complete: function (res) { }, //接口调用结束的回调函数（调用成功、失败都会执行）
  //       })
  //     },
  //     fail: function () {
  //       console.log("请求数据失败");
  //     }
  //   })
    
  // },


  jumpActivity:function(){
    wx.navigateTo({
      url: '/pages/activity/activity',
    })
  }

})