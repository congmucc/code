import {
  requestUtil
} from '../../utils/requestUtil.js'
Page({

  /**
   * 页面的初始数据
   */
  data: {
    tabs: [{
      id: 0,
      value: "审核中",
      icon: "icon-shenhezhong",
      isActive: true,
    }, {
      id: 1,
      value: "驳回",
      icon: "icon-shibai",
      isActive: false,
    }, {
      id: 2,
      value: "已通过",
      icon: "icon-yitongguo",
      isActive: false,
    }],
  list: [],
  // 接口参数
  QueryParams: {
    userId: wx.getStorageSync('openid').id ? wx.getStorageSync('openid').id : '',
    type: 0,
    page: 1, // 第几页
    pageSize: 10 // 每页的活动数
  },
  // 总页数
  totalPage: 1,

  },

  goSelect: function () {
    wx.navigateTo({
      url: '/pages/activity/activity',
    })
  },



  //切换标题 
  handleItemTap(e) {
    const {
      index
    } = e.currentTarget.dataset;
    // console.log(index)
    //  切换标题
    let {
      tabs
    } = this.data;
    tabs.forEach((v, i) => i == index ? v.isActive = true : v.isActive = false);
    // 获取订单列表
    this.data.QueryParams.type = index;
    // 重置列表属性
    this.data.QueryParams.page = 1;
    this.setData({
      list: []
    })
    this.getActivity();
    this.setData({
      tabs
    })
  },

  /**
   * 获取活动数据
   */
  async getActivity() {

    // const res = await wx.request({
    //   url: 'http://localhost:8080/form/list',
    //   method: 'GET',
    //   data: this.data.QueryParams,
    //   success: (result) => {
    //     wx.hideLoading();
    //     console.log(result)
    //     this.setData({
    //       list: [...this.data.list, ...result.data.data.records],
    //       totalPage : result.data.data.total
    //     })
    //     console.log(this.data.list)
    //   },
    //   fail: (err) => {},
    // })
    console.log("asidfjh:", this.data.QueryParams)
    await requestUtil({url: '/form/list', method: 'GET', data: this.data.QueryParams}).then ((res)=>{
      console.log("StateRequest: ",res)
          this.setData({
          list: [...this.data.list, ...res.data.data.records],
          totalPage : res.data.data.total
        })
        console.log(this.data.list)
    })
  },

    /**
   * 生命周期函数--监听页面显示
   */
  onShow() {
    this.getActivity();
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
   * 页面相关事件处理函数--监听用户下拉动作
   */
  onPullDownRefresh() {
    console.log("下拉刷新")
    this.data.QueryParams.page = 1;
    this.setData({
      list:[]
    })
    this.getActivity();
    wx.stopPullDownRefresh({})
  },



})