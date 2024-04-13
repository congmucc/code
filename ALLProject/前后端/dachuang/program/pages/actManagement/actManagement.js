import {
  requestUtil
} from "../../utils/requestUtil.js"
// pages/actManagement/actManagement.js
Page({

  /**
   * 页面的初始数据
   */
  data: {
    // 这个是接收数据的数组，用于存数据
    activity: [],
    // 接口参数
    QueryParams: {
      userId: wx.getStorageSync('openid').id ? wx.getStorageSync('openid').id : '',
      type: 2,
      page: 1, // 第几页
      pageSize: 10 // 每页的活动数
    },
    // 总页数
    totalPage: 1,
  },



  // 获取活动
  async getActivity() {
    // wx.showLoading({
    //   title: '加载中',
    // })
    // const res = await wx.request({
    //   // url: 'http://localhost:8080/form/list?type='+2+'&page='+1+'&pageSize='+10,
    //   url: 'http://localhost:8080/form/list',
    //   method: 'GET',
    //   data: this.data.QueryParams,
    //   success: (result) => {
    //     wx.hideLoading();
    //     console.log("type" + this.data.QueryParams.type)
    //     console.log(result)
    //     this.setData({
    //       activity: [...this.data.activity, ...result.data.data.records],
    //       totalPage: result.data.data.total
    //     })
    //     console.log(this.data.activity)
    //   },
    //   fail: (err) => {
    //     console.log(err)
    //   },
    // })
    console.log("getActivity")
    await requestUtil({url:'/form/list', method: 'GET',data: this.data.QueryParams}).then((res)=>{
        console.log("type" + this.data.QueryParams.type)
        console.log(res)
        this.setData({
          activity: [...this.data.activity, ...res.data.data.records],
          totalPage: res.data.data.total
        })
        console.log(this.data.activity)
  })

  },


  /**
   * 删除
   * @param {*} options 
   */
  async deleteActivity(e) {
    let _this = this;
    console.log(e.currentTarget.dataset.id)
    wx.showModal({
      title: '是否删除',
      content: '删除无法撤销',
      success: async(res) => {
        // wx.request({
        //   url: 'http://localhost:8080/form/del/' + e.currentTarget.dataset.id,
        //   method: 'DELETE',
        //   success: (res) => {
        //     if (res.data.code === '200') {
        //       wx.showToast({
        //         title: '删除成功',
        //         icon: 'none'
        //       })
        //       _this.data.QueryParams.page = 1;
        //       _this.setData({
        //         activity:[]
        //       })
        //       _this.getActivity()
        //     } else {
        //       wx.showToast({
        //         title: '删除失败，错误码' + res.data.code,
        //       })
        //     }
        //   },
        //   fail: (err) => {
        //     console.log("网络错误", err)
        //   }
        // })
       await requestUtil({url: '/form/del/'+ e.currentTarget.dataset.id, method: 'DELETE'}).then(res=>{
            if (res.data.code === '200') {
              wx.showToast({
                title: '删除成功',
                icon: 'none'
              })
              _this.data.QueryParams.page = 1;
              _this.setData({
                activity:[]
              })
              _this.getActivity()
            } else {
              wx.showToast({
                title: '删除失败，错误码' + res.data.code,
              })
            }
        }, (err)=>{
          console.log(err)
        })
      }      
    })

  },


  /**
   * 修改
   * @param {*} options 
   */

  changeActivity(e) {
    console.log(e)
    wx.navigateTo({
      url: '/pages/activity/activity?id='+e.currentTarget.dataset.id,
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
    this.getActivity();
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
    console.log("下拉刷新")
    this.data.QueryParams.page = 1;
    this.setData({
      activity:[]
    })
    this.getActivity()
    // 手动关闭等待效果
    wx.stopPullDownRefresh({})
  },

  /**
   * 页面上拉触底事件的处理函数
   */
  onReachBottom() {
    if (this.data.QueryParams.page >= this.data.totalPage) {
      // 没有下一页数据
      console.log("没有下一页数据")
    } else {
      console.log("有下一页数据");
      this.data.QueryParams.page++;
      this.getActivity();
    }
  },

  /**
   * 用户点击右上角分享
   */
  onShareAppMessage() {

  }
})