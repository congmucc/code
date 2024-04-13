// pages/activityState/activityState.js
Page({

  /**
   * 页面的初始数据
   */
  data: {
    selectway:'选择',
    tabs:[{
        id:0,
        value:"审核中",
        icon:"icon-shenhezhong",
        isActive:true,
      }, {
        id:1,
        value:"驳回",
        icon:"icon-shibai",
        isActive:true,
      }, {
        id:2,
        value:"已通过",
        icon:"icon-yitongguo",
        isActive:true,
      }
    ],
    // 这个是接收数据的数组，用于存数据  已通过
    list:[{
      title:"老年人电子产品培训",
      content:"介绍老年人常用的电子产品，包括智能手机、平板电脑、电子书等，让老年人了解它们的基本功能和使用方法。为老年人提供电子产品操作培训课程，包括基础操作、应用程序安装和使用、常见问题解决等。提供电子产品安全教育，让老年人了解电子产品安全保护的重要性和解决方法，避免在使用电子产品时遇到安全问题。",
      confirmNumber:105,
      totalNumber:120,
      participantNumber:102,
      time:"2023.06.10",
      site:"河南开封顺河区",
    }, {
      title:"乡村教育扶持",
      content:"组织志愿者到乡村地区开展教育扶持工作，包括开设辅导班、捐赠教材等。通过这些工作，可以改善乡村教育条件，提升乡村居民的受教育水平。",
      confirmNumber:105,
      totalNumber:120,
      participantNumber:102,
      time:"2023.05.12",
      site:"河南开封鼓楼区",
    }, {
      title:"开封文化旅游规划",
      content:"根据开封特色和旅游资源，制定开封文化旅游规划，包括旅游路线、景点规划和旅游产品开发等。举办开封文化旅游节庆活动，包括民俗文化节、风情街区节、美食文化节等，吸引游客参与，增强开封文化旅游吸引力；保护开封文化遗产，包括历史建筑、文化古迹、传统技艺等，建立开封文化遗产保护区和开展文化遗产宣传教育活动。",
      confirmNumber:105,
      totalNumber:120,
      participantNumber:102,
      time:"2023.10.16",
      site:"河南开封龙亭区",
    }, ],
    // 这个是接收数据的数组，用于存数据  驳回
    list2:[{
    title:"慰问养老院或孤儿院",
    content:"组织慰问养老院或孤儿院等需社会关爱的特殊人群，以力所能及的活动形式为他们带去快乐和休闲的时光，提升他们的幸福指数，增强全社会关爱特殊人群的意识，形成和谐友善的社会氛围。",
    confirmNumber:105,
    totalNumber:120,
    participantNumber:102,
    time:"2023.10.30",
    site:"河南开封兰考县",
  }, {
    title:"信息化景区建设",
    content:"根据景区的特点和需求，制定信息化规划和设计方案，包括景区信息化系统建设、智能化设备引入和信息技术应用等。建设数字化导游服务平台，为游客提供定制导游服务，包括景区地图、语音讲解、VR体验等，提高游客体验和游览效果。利用景区大数据分析技术，对游客行为、景区资源利用等进行分析和预测，提高景区管理决策的科学性和精准性。",
    confirmNumber:105,
    totalNumber:120,
    participantNumber:102,
    time:"2023.05.05",
    site:"河南开封龙亭区",
  },],

    // 这个是接收数据的数组，用于存数据  审核
    list3:[{
      title:"健康公益",
      content:"组织健康公益活动，宣传健康知识，提供免费的健康检查服务，帮助有需要的人群解决健康问题。",
      confirmNumber:105,
      totalNumber:120,
      participantNumber:102,
      time:"2023.10.18",
      site:"河南开封龙亭区",
    }, {
      title:"临考学生心理健康",
      content:"组织各种形式的促进心理健康活动，如户外拓展、心理辅导、艺术创作等，让学生放松身心，缓解压力，提高心理健康水平。",
      confirmNumber:105,
      totalNumber:120,
      participantNumber:102,
      time:"2023.10.10",
      site:"河南开封祁县",
    }, {
      title:"人工智能与未来",
      content:"为学生和社会大众进行人工智能相关的学术讲座，并提供观看智能机器人舞蹈表演的平台，和探讨人工智能技术在未来的应用与发展趋势的环境。",
      confirmNumber:105,
      totalNumber:120,
      participantNumber:102,
      time:"2023.10.13",
      site:"河南开封通许县",
    },]
  },


  goSelect:function(){
    wx.navigateTo({
      url: '/pages/activity/activity',
    })
  },

  mySelect:function(e){
    var name = e.currentTarget.dataset.name;
    this.setData({
      selectway:name,
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