import {requestUtil} from "../../utils/requestUtil.js"

Page({

  data: {
    imageSize: 3,
    select: false,
    peopleSelectWay: '请选择你的身份',
    peopleSelectWayres: ["普通学生", "志愿者", "专业人才", "政府机构", "其他机构", "大众公司"],
    peopleAttribute: [{
      title: "学校名字",
      attribute: 'university'
    }, {
      title: "学院",
      attribute: 'academy'
    }, {
      title: "专业",
      attribute: 'major'
    }, {
      title: "姓名",
      attribute: 'name'
    }, {
      title: "性别",
      attribute: 'gender'
    }, {
      title: "年级",
      attribute: 'grade'
    }, {
      title: "学号",
      attribute: 'studentNumber'
    }],
    governmentAttribute: [{
      title: "单位",
      attribute: 'unit'
    }, {
      title: "类型",
      attribute: 'type'
    }],
    checkboxItems: [{
        name: '男',
        value: '男',
        checked: 'true'
      },
      {
        name: '女',
        value: '女'
      }
    ],
    showImage_url: '',
    imgs: [], // 上传图片列表
    // imgPath: []
  },


  // 下拉框
  bindShowMsg() {
    this.setData({
      select: !this.data.select
    })
  },
  // 下拉框
  mySelect(e) {
    var name = e.currentTarget.dataset.name;
    this.setData({
      peopleSelectWay: name,
      select: false
    })
  },
  // https://blog.csdn.net/qq_44973159/article/details/105656915
  // 这个界面可以参考一下
  // 上传图片至后台
  uploadimg: function (e) {
    var that = this;
    //选择图片
    wx.chooseImage({
      count: 8, // 默认9
      sizeType: ['original', 'compressed'], // 可以指定是原图还是压缩图，默认二者都有
      sourceType: ['album', 'camera'], // 可以指定来源是相册还是相机，默认二者都有
      success: function (res) {
        // 返回选定照片的本地文件路径列表，tempFilePath可以作为img标签的src属性显示图片
        console.log(res.tempFilePaths);
        var tempFilePaths = res.tempFilePaths;
        that.setData({
          imgs: tempFilePaths,
        })
      }
    })
  },


  // 点击图片显示出来
  showImage: function (e) {
    let _this = this
    console.log(e)
    //  全屏显示图片
    wx.previewImage({
      current: e.currentTarget.dataset.name,
      showmenu: true,
      urls: _this.data.imgs
    })
  },

  // 删除图片
  deleteImg: function (e) {
    let that = this
    let {
      index
    } = e.currentTarget.dataset.index
    let {
      imgs
    } = this.data
    wx.showModal({
      title: '提示',
      content: '是否删除当前照片',
      success(res) {
        if (res.confirm) {
          imgs.splice(index, 1)
          that.setData({
            imgs
          })
        }
      }
    })
  },

  // 改变性别
  checkboxChange(e) {
    const checked = e.detail.value
    const changed = {}
    for (let i = 0; i < this.data.checkboxItems.length; i++) {
      if (checked.indexOf(this.data.checkboxItems[i].name) !== -1) {
        changed['checkboxItems[' + i + '].checked'] = true
      } else {
        changed['checkboxItems[' + i + '].checked'] = false
      }
    }
    this.setData(changed)
  },

  // 提交表单
  formSubmit(e) {
    let _this = this
    e.detail.value.level = 7;
    e.detail.value.imgs = _this.data.imgs
    console.log('form发生了submit事件，携带的数据为：', e.detail.value)

    // 汉字的正则表达式
    const chinese = /[^\u4E00-\u9FA5]/g

    // if (this.data.peopleSelectWay == '普通学生' || this.data.peopleSelectWay == '志愿者' || this.data.peopleSelectWay == '专业人才') {
    //   // 判断学校名字是否为空
    //   if (e.detail.value.university == '') {
    //     wx.showToast({
    //       title: '学校不能为空',
    //       icon: 'none'
    //     })
    //     return false
    //   }
    //   wx.request({
    //     url: `http://localhost:8080/api/school/get?name=${e.detail.value.university}`,
    //     method: 'GET',
    //     success: (res) => {
    //       console.log(res)
    //       if (res.data !== true) {
    //         wx.showToast({
    //           title: '请输入正确的学校名',
    //           icon: 'none'
    //         })
    //         return false
    //       } else {
    //         wx.showToast({
    //           title: '正确的学校名',
    //           icon: 'none'
    //         })
    //       }
    //     },
    //     error: (err) => {
    //       wx.showToast({
    //         title: '网络错误',
    //         icon: 'none'
    //       })
    //     }
    //   })

    //   // 判断学院名字是否为空
    //   if (e.detail.value.academy == '') {
    //     wx.showToast({
    //       title: '学院不能为空',
    //       icon: 'none'
    //     })
    //     return false
    //   }
    //   // 判断学院名字是否为非汉字
    //   if (chinese.test(e.detail.value.academy)) {
    //     wx.showToast({
    //       title: '学院有误',
    //       icon: 'none'
    //     })
    //     return false
    //   }
    //   // 判断专业名字是否为空
    //   if (e.detail.value.major == '') {
    //     wx.showToast({
    //       title: '专业不能为空',
    //       icon: 'none'
    //     })
    //     return false
    //   }
    //   // 判断专业名字是否为非汉字
    //   if (chinese.test(e.detail.value.major)) {
    //     wx.showToast({
    //       title: '专业有误',
    //       icon: 'none'
    //     })
    //     return false
    //   }

    //   // 判断姓名是否为空
    //   if (e.detail.value.name == '') {
    //     wx.showToast({
    //       title: '姓名不能为空',
    //       icon: 'none'
    //     })
    //     return false
    //   }
    //   // 判断姓名支持中英文
    //   if (!(/^[\u4E00-\u9FA5A-Za-z]+$/.test(e.detail.value.name))) {
    //     wx.showToast({
    //       title: '姓名有误',
    //       icon: 'none'
    //     })
    //     return false
    //   }

    //   // 判断年级是否为空
    //   if (e.detail.value.garde == '') {
    //     wx.showToast({
    //       title: '年级不能为空',
    //       icon: 'none'
    //     })
    //     return false
    //   }
    //   // 年级判断 
    //   if (!(/^\d{4}$/.test(e.detail.value.grade))) {
    //     wx.showToast({
    //       title: '请输入4位数字的入学年级',
    //       icon: 'none'
    //     })
    //     return false
    //   }

    //   // 判断学号是否为空
    //   if (e.detail.value.studentNumber == '') {
    //     wx.showToast({
    //       title: '学号输入不能为空',
    //       icon: 'none'
    //     })
    //     return false
    //   }
    //   // 学号判断 
    //   if (!(/[0-9]+/.test(e.detail.value.studentNumber))) {
    //     wx.showToast({
    //       title: '学号有误',
    //       icon: 'none'
    //     })
    //     return false
    //   }

    // }
    //  else {
    //   // 判断单位
    //   if (e.detail.value.governmentUnit == '' || e.detail.value.institutionalUnit == '' || e.detail.value.companyUnit == '') {
    //     wx.showToast({
    //       title: '单位输入不能为空',
    //       icon: 'none'
    //     })
    //     return false
    //   }
    //   // 判断类型是否为空
    //   if (e.detail.value.governmentType == '' || e.detail.value.institutionalType == '' || e.detail.value.companyType == '') {
    //     wx.showToast({
    //       title: '类型输入不能为空',
    //       icon: 'none'
    //     })
    //     return false
    //   }
    // }


    // 设置一个认证的辅助链接
    let CUrl;
    // if (this.data.peopleSelectWay == '普通学生' || this.data.peopleSelectWay == '志愿者' || this.data.peopleSelectWay == '专业人才') {
    //   CUrl = '/student/upload'
    // } else {
    //   CUrl = '/institution/upload'
    // }
    
    
    requestUtil({url: '/institution/upload', method: 'POST', data:e.detail.value,	header: {
      'Content-Type': 'multipart/form-data'
    },
  }).then((res) =>{
      console.log(res)
    })


  },




})