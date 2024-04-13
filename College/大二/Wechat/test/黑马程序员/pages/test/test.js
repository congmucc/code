// pages/test/test.js
Page({

  /**
   * 页面的初始数据
   */
  data: {
    randomNumber: Math.random() * 10,
    name:"京东",
    msg:"hello world",

    arr1:['苹果', '华为', '小米'],
    userList:[
      {id:1, name:'小红'},
      {id:2, name:'小黄'},
      {id:3, name:'小白'}
    ]
  },

  buttonTop(e){
    console.log(this.data.name);          //data里面的name属性
    console.log(e);
    console.log(e.target);
    console.log(e.target.dataset);        //包含data-所有传进来的值
    console.log(e.target.dataset.name1);
    console.log(e.target.dataset.name2);
    //具体的参数值

    // 修改淘宝和京东
    if (this.data.name == "京东") {
      this.setData({
        name:e.target.dataset.name1
      })
    } else {
      this.setData({
        name:e.target.dataset.name2
      })
    }
    

  },

  // bindinput
  buttonInput(e){
    console.log(e.detail.value);
    this.setData({
      age:e.detail.value
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