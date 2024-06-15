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
        <!-- <uni-card :is-shadow="false">
          <uni-forms-item class="form-card" label="选择头像" name="avator" required>
            <uni-file-picker v-model="formData.avator" :limit="1" :del-icon="false" disable-preview
              :imageStyles="imageStyles" @select="selectFileA" file-mediatype="image">选择</uni-file-picker>
          </uni-forms-item>
        </uni-card> -->

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
            <uni-file-picker :auto-upload="false" v-model="volunCertifyFileLists" file-mediatype="image" mode="grid"
              :limit="9" @select="selectFileV" @delete="deleteFileV" />
          </uni-forms-item>
        </uni-card>
        <uni-card :is-shadow="false">

          <uni-forms-item class="form-card" label="专业人才图片证明" name="professCertify">
            <uni-file-picker :auto-upload="false" v-model="professCertifyFileLists" file-mediatype="image" mode="grid"
              :limit="9" @select="selectFileP" @delete="deleteFileP" />
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
  volunCertify: string | []; // 志愿者证明图片地址
  professCertify: string | []; // 专业人才证明图片地址
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
  professCertify: [],
})



// 头像列表
const avatar = ref<string>('https://mmbiz.qpic.cn/mmbiz/icTdbqWNOwNRna42FI242Lcia07jQodd2FJGIYQfG0LAJGFxM4FbnQP6yfMxBgJ0F3YRqJCJ1aPAK2dQagdusBZg/0');

const onChooseAvatar = (e: any) => {
  // console.log("e.detail的值： ", e)
  const { avatarUrl } = e.detail
  avatar.value = avatarUrl
  // console.log("新的头像值：", avatar.value)
}
/**
 * 两个图片列表
 */

const volunCertifyFileLists = ref<{
  name: '',
  url: '',
  uuid: '',
  file: ''
}[]>([]);
const professCertifyFileLists = ref<{
  name: '',
  url: '',
  uuid: '',
  file: ''
}[]>([]);

/**
 * 选择图片
 */
const selectFileV = (res: any) => {
  let { tempFiles } = res;
  tempFiles.forEach((element: any) => {
    let { name, url, uuid, file } = element;
    volunCertifyFileLists.value.push({
      name, url, uuid, file,
    })
  });
  console.log("志愿者图片的值：", volunCertifyFileLists.value)
}

const selectFileP = (res: any) => {
  let { tempFiles } = res;
  tempFiles.forEach((element: any) => {
    let { name, url, uuid, file } = element;
    professCertifyFileLists.value.push({
      name, url, uuid, file,
    })
  });
  console.log("专业技术人才图片的值：", professCertifyFileLists.value)

}


// 删除图片
const deleteFileV = (res: any) => {
  let { tempFile: { uuid } } = res
  let tar = volunCertifyFileLists.value.findIndex((element: {
    name: '',
    url: '',
    uuid: '',
    file: ''
  }) => element.uuid === uuid)
  if (typeof tar === 'number') {
    volunCertifyFileLists.value.splice(tar, 1)
  }
  console.log("志愿者图片的值：", volunCertifyFileLists.value)
}

const deleteFileP = (res: any) => {
  let { tempFile: { uuid } } = res
  let tar = professCertifyFileLists.value.findIndex((element: {
    name: '',
    url: '',
    uuid: '',
    file: ''
  }) => element.uuid === uuid)
  if (typeof tar === 'number') {
    professCertifyFileLists.value.splice(tar, 1)
  }
  console.log("专业技术人才图片的值：", professCertifyFileLists.value)
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

// 上传的图片数组
const imgFiles = ref<{ name: string, uri: string }[]>([])

/**
 * 拼接函数
 */

const concat = () => {
  imgFiles.value = [];
  // 拼接头像
  if (avatar.value != 'https://mmbiz.qpic.cn/mmbiz/icTdbqWNOwNRna42FI242Lcia07jQodd2FJGIYQfG0LAJGFxM4FbnQP6yfMxBgJ0F3YRqJCJ1aPAK2dQagdusBZg/0') {
    formData.avator = avatar.value;
  }

  // 拼接志愿者图片
  if (volunCertifyFileLists.value.length > 0) {
    volunCertifyFileLists.value.forEach((item, index) => {
      imgFiles.value.push({
        name: `volunteer${index + 1}`,
        uri: item.url
      })
    })

  }
  // 拼接专业人才证明图片
  if (professCertifyFileLists.value.length > 0) {
    professCertifyFileLists.value.forEach((item, index) => {
      imgFiles.value.push({
        name: `profess${index + 1}`,
        uri: item.url
      })
    })

  }
}

// 表单校验
const formRules = ref<any>();

/**
 * 进行轮询提交图片
 */

const uploadFile = (imgs: any[]) => {
  const uploadTasks = imgs.map((file: any, index: number) => {
    return new Promise((resolve, reject) => {
      const uploadTask = uni.uploadFile({
        url: 'http://127.0.0.1:8090/zyb/student/update/new',
        filePath: file.uri,
        name: 'imgFile',
        formData: formData,
        header: {
          'Content-Type': 'multipart/form-data'
        },
        success: function (res) {
          resolve(res.data)
        },
        fail: function (err) {
          reject(err)
        },

      });
      // 这里可以根据需要显示进度条
      uploadTask.onProgressUpdate((res) => {
        console.log('上传进度', res.progress)
        console.log('已经上传的数据长度', res.totalBytesSent)
        console.log('预期需要上传的数据总长度', res.totalBytesExpectedToSend)

      })
    })
  })
  Promise.all(uploadTasks)
    .then((res) => {
      console.log('上传成功', res)
      // 上传成功后的操作
    })
    .catch((err) => {
      console.log('上传失败', err)

      // 上传失败后的操作
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

      // 拼接图片
      concat()
      console.log("imgFiles.value的值：", imgFiles.value);
      console.log("选择之后的数据： ", formData);
      uploadFile(imgFiles.value)
      uni.hideLoading()
    } else { // 当表单验证失败时

      console.log('表单校验失败', errors); // 输出错误详情

    }
  })
}

</script>

<style scoped>
.container {
  height: 100vh;
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