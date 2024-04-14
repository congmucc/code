<template>
  <view class="container">
    <view class="header">
      <view class="title">学生信息</view>
    </view>
    <view class="main">
      <uni-forms ref="formRules" :rules="rules" :modelValue="formData" label-position="top">
        <uni-card :is-shadow="false">
          <uni-forms-item class="form-card" label="姓名" name="name" required>
            <uni-easyinput type="text" v-model="formData.name" placeholder="请输入姓名" />
          </uni-forms-item>
        </uni-card>

        <uni-card :is-shadow="false">
          <uni-forms-item class="form-card" label="学校" name="university" required>
            <uni-easyinput v-model="formData.university" placeholder="请输入学校" />
          </uni-forms-item>
        </uni-card>
        <uni-card :is-shadow="false">
          <uni-forms-item class="form-card" label="选择头像" name="avator">
            <button class="avatar-wrapper" open-type="chooseAvatar" @chooseavatar="onChooseAvatar">
              <image class="avatar" :src="avatar"></image>
            </button>
          </uni-forms-item>
        </uni-card>
        <uni-card :is-shadow="false">
          <uni-forms-item class="form-card" label="学院" name="college" required>
            <uni-easyinput v-model="formData.college" placeholder="请输入学院" />
          </uni-forms-item>
        </uni-card>
        <uni-card :is-shadow="false">
          <uni-forms-item class="form-card" label="专业" name="major" required>
            <uni-easyinput v-model="formData.major" placeholder="请输入专业" />
          </uni-forms-item>
        </uni-card>
        <uni-card :is-shadow="false">
          <uni-forms-item class="form-card" label="联系电话" name="phone" required>
            <uni-easyinput v-model="formData.phone" placeholder="请输入联系电话" />
          </uni-forms-item>
        </uni-card>
        <uni-card :is-shadow="false">
          <uni-forms-item class="form-card" label="个人能力" name="ability" required>
            <uni-easyinput v-model="formData.ability" placeholder="请输入个人能力" />
          </uni-forms-item>
        </uni-card>
        <uni-card :is-shadow="false">
          <uni-forms-item class="form-card" label="身份证号" name="idCard" required>
            <uni-easyinput v-model="formData.idCard" placeholder="请输入身份证号" />
          </uni-forms-item>
        </uni-card>
        <uni-card :is-shadow="false">
          <uni-forms-item class="form-card" label="志愿者图片证明" name="volunCertify">
            <uni-file-picker v-model="formData.volunCertify" file-mediatype="image" mode="grid" :limit="9"
              @select="selectFileV" @delete="deleteFileV" />
          </uni-forms-item>
        </uni-card>
        <uni-card :is-shadow="false">

          <uni-forms-item class="form-card" label="专业人才图片证明" name="professCertify">
            <uni-file-picker v-model="formData.professCertify" file-mediatype="image" mode="grid" :limit="9"
              @select="selectFileP" @delete="deleteFileP" />
          </uni-forms-item></uni-card>
      </uni-forms>
      <button @click="submit(formRules)">Submit</button>


    </view>
    <view calss="footer"></view>
  </view>
</template>

<script lang="ts" setup>
import { ref, reactive } from 'vue'


interface StudentInfo {
  username: string; // 学号
  name: string; // 姓名
  avator: string; // 头像地址
  university: string; // 学校
  college: string; // 学院
  phone: string; // 联系电话
  major: string; // 专业
  idCard: string; // 身份证号
  ability: string; // 个人能力
  volunCertify: updatei[]; // 志愿者证明图片地址
  professCertify: updatei[]; // 专业人才证明图片地址
}
const formData = reactive<StudentInfo>({
  username: '1432',
  name: '1234',
  avator: '',
  university: '1234',
  college: '1234',
  phone: '1234',
  major: '1234',
  idCard: '111222333444555666',
  ability: '12344312',
  volunCertify: [],
  professCertify: []
})


interface updatei {
  name: string,
  extname: string,
  url: string,
  uuid: number
}




// 头像列表
const avatar = ref<string>('https://mmbiz.qpic.cn/mmbiz/icTdbqWNOwNRna42FI242Lcia07jQodd2FJGIYQfG0LAJGFxM4FbnQP6yfMxBgJ0F3YRqJCJ1aPAK2dQagdusBZg/0');
/**
 * 头像上传
 */
const onChooseAvatar = (e: any) => {
  const { avatarUrl } = e.detail
  // todo 进行删除
  avatar.value = upload({ username: formData.username, type: 3, url: avatarUrl })
}


// 上传类型
interface variable {
  username: string,
  type: number,
  url: string,
  uuid: string
}



/**
 * 选择图片
 */
const selectFileV = (res: any) => {
  let { tempFiles } = res;
  tempFiles.forEach((ele: any) => {
    let { url, uuid } = ele
    // @ts-ignore
    formData.volunCertify.push(upload({ username: formData.username, type: 3, url: url, uuid: uuid }))
  })
}

const selectFileP = (res: any) => {
  let { tempFiles } = res;
  tempFiles.forEach(async (ele: any) => {
    let { url, uuid } = ele
    let temp = await upload({ username: formData.username, type: 3, url: url, uuid: uuid })
    // @ts-ignore
    formData.professCertify.push(temp)
    console.log("专业人才图片的值：", formData.professCertify)
    console.log("temp:", temp)
  })
  console.log("专业人才res的值： ", res)
}


// 删除图片
const deleteFileV = (res: any) => {
  // let { tempFile: { uuid } } = res
  // let tar = volunCertifyFileLists.value.findIndex((element: {
  //   name: '',
  //   url: '',
  //   uuid: '',
  //   file: ''
  // }) => element.uuid === uuid)
  // if (typeof tar === 'number') {
  //   volunCertifyFileLists.value.splice(tar, 1)
  // }

  console.log("图片的值：", res)

  console.log("志愿者图片的值：", formData.volunCertify)
  // 这里，获取值之后直接改改看看
  // console.log("志愿者图片的值：", volunCertifyFileLists.value)

}

const deleteFileP = (res: any) => {
  let { tempFile: { uuid } } = res

  // 获取uuid然后删除文件



  console.log("专业人才图片的值：", formData.professCertify)
  // console.log("专业技术人才图片的值：", professCertifyFileLists.value)
}


/**
 * 表单校验规则
 */
const rules = {
  name: {
    rules: [{ required: true, errorMessage: '请输入姓名' },]
  },
  university: {
    rules: [{ required: true, errorMessage: '请输入学校' }]
  },
  college: {
    rules: [{ required: true, errorMessage: '请输入学院' }]
  },
  phone: {
    rules: [{ required: true, errorMessage: '请输入联系电话' }]
  },
  major: {
    rules: [{ required: true, errorMessage: '请输入专业' }]
  },
  idCard: {
    rules: [
      { required: true, errorMessage: '请输入身份证号' },
      { pattern: '^\\d{17}[\\d|X|x]$', errorMessage: '请输入正确的身份证号码' }
    ]
  },
  ability: {
    rules: [{ required: true, errorMessage: '请输入个人能力' }]
  },
  // volunCertify: {
  //   rules: [{ required: true, errorMessage: '请上传志愿者证明图片' }]
  // },
  // professCertify: {
  //   rules: [{ required: true, errorMessage: '请上传专业人才证明图片' }]
  // }
}


// 表单校验
const formRules = ref<any>();

/**
 * 上传图片
 */
const upload = (file: variable) => {

  let { username, type, url, uuid } = file
  return new Promise((resolve, reject) => {
    uni.uploadFile({
      url: 'http://127.0.0.1:8090/zyb/student/upload/img',
      filePath: url,
      name: 'file',
      formData: {
        username: username,
        type: type,
        uuid: uuid
      },
      header: {
        'Content-Type': 'multipart/form-data'
      },
      success: function (res) {
        console.log('上传成功：', res.data)
        resolve(JSON.parse(res.data).data)
      },
      fail: function (err) {
        console.log('上传失败：', err)
        uni.showToast({
          title: '上传失败',
          icon: 'none'
        })
      },
    })
  })
}

/**
 * 删除图片
 */
const deleteImg = (file: variable) => {
  // 如果想删除图片只能用官方给的uuid
  let { username, type, url, uuid } = file
  uni.request({
    url: 'http://127.0.0.1:8090/zyb/student/delete/img',
    data: {
      username: username,
      type: type,
      url: url,
      uuid: uuid
    },
    success: (res) => {
      console.log("删除成功", res.data);
      uni.showToast({
        title: "删除成功",
        icon: 'none'
      })
    },
    fail: (err) => {
      console.log("删除失败", err)
      uni.showToast({
        title: '删除失败，请重试',
        icon: 'success'
      })
    }
  })
}



/**
 * 表单提交
 */
const submit = async (formRules: any) => {
  formRules.validate(async (valid: any, errors: any) => {
    if (!valid) {
      uni.showLoading({
        title: '提交中...',
        mask: true
      })

      // // 拼接图片
      // concat()
      // console.log("imgFiles.value的值：", imgFiles.value);
      // console.log("选择之后的数据： ", formData);
      // uploadFile(imgFiles.value)
      // uni.hideLoading()
    } else { // 当表单验证失败时

      console.log('表单校验失败', errors); // 输出错误详情

    }
  })
}

</script>

<style scoped>
.container {
  height: 100%;
  background-color: #fafafa;

}

.header {
  font-size: 20px;
  text-align: center;
}

.main {
  text-align: center;
  padding-top: 1px;
}

.avatar-wrapper {
  width: 64px;
  height: 64px;
  border-radius: 50%;
}

.avatar {
  width: 64px;
  height: 64px;
  border-radius: 50%;
  margin-left: -14px;
}
</style>