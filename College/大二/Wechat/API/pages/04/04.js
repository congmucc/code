// pages/04/04.js
Page({
  onLoad(e) {
    wx.request({
      url: 'https://applet-base-api-t.itheima.net/api/get',
      method: 'GET',
      data: {
        name: 'za',
        age:223209814
      },
      success: (res) => {
        if (res.statusCode === 200) [
          console.log(res.data)
        ]
      }
    })
  }
})