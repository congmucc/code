import {requestUtil} from "../../utils/requestUtil.js"

let values={}
Page({
  /**
   * 组件的初始数据
   */
  data: {
    startTime:'2023-01-01',
    endTime:'2023-01-01',
    region: '河南省,开封市,龙亭区',
    nameType: [{
      title: "活动名称",
      attribuate: 'title',
      type: 'text',
      value:values.title
    }, {
      title: "活动开始时间",
      attribuate: 'startTime',
      type: '',
      value:values.startTime ? values.startTime : '2023-01-01' 
    }, {
      title: "活动结束时间",
      attribuate: 'endTime',
      type: '',
      value:values.endTime ? values.endTime : '2023-01-01'
    }, {
      title: "活动地点",
      attribuate: 'site',
      type: '',
      value:values.site ? value.site : '北京省,北京市,东城区'
    }, {
      title: "活动场地",
      attribuate: 'venue',
      type: 'text',
      value:values.venue
    }, {
      title: "活动内容",
      attribuate: 'content',
      type: '',
      value:values.content
    }, {
      title: "参与人数",
      attribuate: 'number',
      type: 'number',
      value:values.number
    }, {
      title: "活动物资",
      attribuate: 'material',
      type: 'text',
      value:values.material
    }, {
      title: "人员需求",
      attribuate: 'numberNeed',
      type: 'text',
      value:values.numberNeed
    }],
    
  },


  setValues(id) {
    // 网络请求
    requestUtil({url: '/form/get/'+id, method:"GET"}).then((res)=>{
      console.log(res.data.data)
      values = res.data.data
      this.setData({
        ['nameType[0].value']: values.title,
        ['nameType[1].value']: values.startTime,
        ['nameType[2].value']: values.endTime,
        ['nameType[3].value']: values.site,
        ['nameType[4].value']: values.venue,
        ['nameType[5].value']: values.content,
        ['nameType[6].value']: values.number,
        ['nameType[7].value']: values.material,
        ['nameType[8].value']: values.numberNeed,
      })
    })
  },

  /**
   * 生命周期函数--监听页面显示
   */
  onShow() {
    values = {};
    // 获取上个页面传过来的数据
    let pages = getCurrentPages();
    let currentPage = pages[pages.length - 1];
    let {id}=currentPage.options;
    // console.log(id)
    if (id || id == 0) {
      this.setValues(id)
    }
  },

// 开始时间
  bindDateChange: function(e) {
    console.log('picker发送选择改变，携带值为', e.detail.value)
    this.setData({
      ['nameType[1].value']: e.detail.value
    })
  },
  // 结束时间
  bindDateChange2: function(e) {
    console.log('picker发送选择改变，携带值为', e.detail.value)
    this.setData({
      ['nameType[2].value']: e.detail.value
    })
  },

// 地点
  bindRegionChange: function(e) {
    console.log('picker地址发送选择改变，携带值为', e.detail.value);
    this.setData({
      ['nameType[3].value']: e.detail.value
    })
  },
   async formSubmits(e) {
      let _this = this
      e.detail.value.id = values.id
      e.detail.value.site = _this.data.nameType[3].value
      e.detail.value.userId = wx.getStorageSync('openid').id
      // console.log("this.data.site: ", this.data.nameType[3].value)
      e.detail.value.number = parseInt(e.detail.value.number)
      console.log('form发生了submit事件，携带的数据为：', e.detail.value)

      // // 判断活动名称是否为空
      // if (e.detail.value.title == '') {
      //   wx.showToast({
      //     title: '活动名称不能为空',
      //     icon: 'none'
      //   })
      //   return false
      // }
      // // 判断活动场地是否为空
      // if (e.detail.value.venue == '') {
      //   wx.showToast({
      //     title: '活动场地不能为空',
      //     icon: 'none'
      //   })
      //   return false
      // }

      // // 判断活动内容是否为空
      // if (e.detail.value.content == '') {
      //   wx.showToast({
      //     title: '活动内容不能为空',
      //     icon: 'none'
      //   })
      //   return false
      // }

      // // 判断活动参与人数是否为空
      // if (e.detail.value.number == '') {
      //   wx.showToast({
      //     title: '参与人数不能为空',
      //     icon: 'none'
      //   })
      //   return false
      // }

      // // 判断活动物资是否为空
      // if (e.detail.value.material == '') {
      //   wx.showToast({
      //     title: '活动物资不能为空',
      //     icon: 'none'
      //   })
      //   return false
      // }

      // // 判断人员需求是否为空
      // if (e.detail.value.numberNeed == '') {
      //   wx.showToast({
      //     title: '人员需求不能为空',
      //     icon: 'none'
      //   })
      //   return false
      // }


    
      // wx.request({
      //   url: 'http://localhost:8080/form/add',
      //   method: 'POST',
      //   data: e.detail.value,
      //   success: (res) => {
      //     if (res.code === '200') {
      //       wx.showToast({
      //         title: '提交失败',
      //         icon: 'none'
      //       })
      //     }
      //     wx.showToast({
      //       title: '提交成功',
      //       icon: 'none'
      //     })
      //   },
      //   error: (err) => {
      //     wx.showToast({
      //       title: '提交失败',
      //       icon: 'none'
      //     })
      //     console.log("添加失败：", err)
      //   }
      // }),
      await requestUtil({url: '/form/add', method: 'POST', data:e.detail.value}).then((res)=>{
        if (res.data.code === '200') {
          wx.showToast({
            title: '提交成功',
            icon: 'none'
          })
        } else{
          wx.showToast({
            title: '提交失败',
            icon: 'none'
          })
        }
      })
    },


    

})