import {
  requestUtil,
  getWxLogin,
  getUserProfile
} from '../../utils/requestUtil.js'

// pages/login/login.js
Page({

  /**
   * 页面的初始数据
   */
  data: {
    passwordTest: true
  },

  // https://blog.csdn.net/cheng2290/article/details/102550829#:~:text=%E5%BE%AE%E4%BF%A1%E5%B0%8F%E7%A8%8B%E5%BA%8F--%E7%99%BB%E5%BD%95%E6%8E%88%E6%9D%83%EF%BC%8C%E4%B8%80%E9%94%AE%E8%8E%B7%E5%8F%96%E7%94%A8%E6%88%B7%E5%BE%AE%E4%BF%A1%E6%89%8B%E6%9C%BA%E5%8F%B7%E5%B9%B6%E7%99%BB%E5%BD%95%201%20%E5%B0%8F%E7%A8%8B%E5%BA%8F%E8%B0%83%E7%94%A8wx.login%20%28%29%20%E8%8E%B7%E5%8F%96%20%E4%B8%B4%E6%97%B6%E7%99%BB%E5%BD%95%E5%87%AD%E8%AF%81code%20%EF%BC%8C%E5%B9%B6%E5%9B%9E%E4%BC%A0%E5%88%B0%E5%BC%80%E5%8F%91%E8%80%85%E6%9C%8D%E5%8A%A1%E5%99%A8,2%20%E5%BC%80%E5%8F%91%E8%80%85%E6%9C%8D%E5%8A%A1%E5%99%A8%E4%BB%A5code%E6%8D%A2%E5%8F%96%20%E7%94%A8%E6%88%B7%E5%94%AF%E4%B8%80%E6%A0%87%E8%AF%86openid%20%E5%92%8C%20%E4%BC%9A%E8%AF%9D%E5%AF%86%E9%92%A5session_key%E3%80%82%203%20%E4%B8%B4%E6%97%B6%E7%99%BB%E5%BD%95%E5%87%AD%E8%AF%81code%E5%8F%AA%E8%83%BD%E4%BD%BF%E7%94%A8%E4%B8%80%E6%AC%A1

  /**
   * 登录获取用户token
   * 这里需要在Storage里面存储昵称和头像，获取头像可以通过
   * 设置一个底部弹窗
   */
  async login() {
    const token = wx.getStorageSync('token')
    if (!token) {
      // wx.login({
      //   success(res) {
      //     // 如果数据库中含有openid 则进行
      //     if (res.code) {
      //       //发起网络请求
      //       wx.request({
      //         url: 'http://localhost:8080/user/login',
      //         method: 'POST',
      //         data: {
      //           code: res.code,
      //           nickName: "微信用户",
      //           avatarUrl: "https://thirdwx.qlogo.cn/mmopen/vi_32/POgEwh4mIHO4nibH0KlMECNjjGxQUq24ZEaGT4poC6icRiccVGKSyXwibcPq4BWmiaIGuG1icwxaQX6grC9VemZoJ8rg/132"
      //         },
      //         success: (res) => {
      //           if (res.data.code === "200") {
      //             console.log('请求成功: ', res)
      //             wx.showToast({
      //               title: '登录成功',
      //             })
      //             // // 存token到缓存
      //             wx.setStorage({
      //               key:"openid",
      //               data:res.data.data
      //             })
      //             wx.navigateTo({
      //               url: '/pages/activityUser/activityUser',
      //             })
      //           } else {
      //             wx.showToast({
      //               title: '登录失败',
      //             })
      //           }

      //         },
      //         fail: (err) => {
      //           console.log('接口请求失败： ', err)
      //         }
      //       })
      //     } else {
      //       console.log('登录失败！' + res.errMsg)
      //     }
      //   },
      //   fail: (err) => {
      //     console.log("网络错误"+ err)
      //   }
      // })

      // let res = await getWxLogin();
      // let res2 = await getUserProfile();
      // console.log("asdifjh: ",res.code)
      Promise.all([getWxLogin(), getUserProfile()]).then((res) => {
        console.log(res)
        let loginParam = {
          code: res[0].code,
          nickName: res[1].userInfo.nickName,
          avatarUrl: res[1].userInfo.avatarUrl
        }
        wx.setStorageSync('userInfo', res[1].userInfo)
        this.wxlogin(loginParam)
      })


    } else {
      wx.navigateTo({
        url: '/pages/activityUser/activityUser',
      })
    }
  },

  /**
   * 请求后端获取用户token
   */

  async wxlogin(loginParam) {
    await requestUtil({
      url: "/user/login",
      data: loginParam,
      method: 'POST'
    }).then((res) => {
      console.log(res)
      if (res.data.code === "200") {
        console.log('请求成功: ', res)
        wx.showToast({
          title: '登录成功',
        })
        // // 存token到缓存
        wx.setStorage({
          key: "openid",
          data: res.data.data
        })
        wx.navigateTo({
          url: '/pages/activityUser/activityUser',
        })
      } else {
        wx.showToast({
          title: '登录失败',
        })
      }
    }, (err) => {
      wx.showToast({
        title: '网络错误',
      })
    })
  },



  gotoUserXY: function () {
    wx.navigateTo({
      url: '/pages/xieyi/xieyi',
    })
  },




})