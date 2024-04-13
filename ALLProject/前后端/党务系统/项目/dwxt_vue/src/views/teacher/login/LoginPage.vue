<script setup>
import { ref, onMounted } from 'vue'
import {
  userLoginService,
  getCodeByTeaEmail,
  updateTeacherPassword
} from '@/api/user.js'
import { useUserStore } from '@/stores'
import { ElMessage } from 'element-plus'
import { Base64 } from 'js-base64'
import { useRouter } from 'vue-router'
import {
  Promotion,
  Comment,
  User,
  Lock,
  Loading
} from '@element-plus/icons-vue'
const userStore = useUserStore()

onMounted(() => {
  userStore.removeToken()
})

const form1 = ref()
const form2 = ref()
const form3 = ref()
const formModel = ref({
  value: '1',
  username: '',
  password: ''
})
const checked = ref(false)
const emailModel = ref({})
let passwordModel = ref({})
const rules1 = {
  username: [
    { required: true, message: '请输入用户名', trigger: 'blur' },
    {
      pattern: /^\S{2,15}$/,
      message: '用户名必须是给定编号',
      trigger: 'blur'
    }
  ],
  password: [
    { required: true, message: '请输入密码', trigger: 'blur' },
    {
      pattern: /^\S{6,15}$/,
      message: '密码必须是6-15位的非空字符',
      trigger: 'blur'
    }
  ]
}
const rules2 = {
  username: [
    { required: true, message: '请输入用户名', trigger: 'blur' },
    { pattern: /^\S{2,15}$/, message: '用户名必须是给定编号', trigger: 'blur' }
  ],
  email: [
    { required: true, message: '请输入邮箱', trigger: 'blur' },
    {
      pattern: /^[a-zA-Z0-9._-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,4}$/,
      message: '您填写的内容不符合邮箱规范',
      trigger: 'blur'
    }
  ],
  code: [{ required: true, message: '请输入验证码' }]
}
const checkNewSame = (rule, value, cb) => {
  if (value !== passwordModel.value.new_pwd) {
    cb(new Error('新密码和确认再次输入的新密码不一样!'))
  } else {
    cb()
  }
}
const load = async () => {
  const PWD = await JSON.parse(localStorage.getItem('userlist'))

  if (
    PWD.user.username !== '' &&
    PWD.user.password !== '' &&
    PWD.checked === 1
  ) {
    formModel.value.username = PWD.user.username
    formModel.value.password = Base64.decode(PWD.user.password)
    console.log(formModel.value.password)
    checked.value = true
  }
}

load()
const rules3 = {
  // 新密码
  new_pwd: [
    { required: true, message: '请输入新密码', trigger: 'blur' },
    {
      pattern: /^(?=.*[a-z])(?=.*[A-Z])(?=.*\d)[^]{8,15}$/,
      message: '密码必须包含大小写字母和数字且长度为8-15位',
      trigger: 'blur'
    }
  ],
  // 确认新密码
  re_pwd: [
    { required: true, message: '请再次确认新密码', trigger: 'blur' },
    {
      pattern: /^(?=.*[a-z])(?=.*[A-Z])(?=.*\d)[^]{8,15}$/,
      message: '密码必须包含大小写字母和数字且长度为8-15位',
      trigger: 'blur'
    },
    { validator: checkNewSame, trigger: 'blur' }
  ]
}

const router = useRouter()
//登录密码检测
const login = async () => {
  await form1.value.validate()
  if (checked.value) {
    const checked = {
      checked: 1
    }
    userStore.setJzw(checked)
  } else {
    const checked = {
      checked: 0
    }
    userStore.setJzw(checked)
  }
  const res = await userLoginService(formModel.value)
  userStore.setUser(res.data.data)
  if (formModel.value.password == '123456') {
    ElMessage.success('登录成功,请先修改初始密码')
    router.push('/user/password')
  } else {
    ElMessage.success('登录成功')
    router.push('/teacher')
  }
}

const dialogVisible = ref(false)
const currentPage = ref(0)
// 步骤配置
//const steps = ref([{ title: '邮箱验证' }, { title: '密码重置' }])
// 总页数
const totalPage = 1
// 上一页
// const prevPage = () => {
//   currentPage.value--
// }
// 下一页
const nextPage = async () => {
  await form2.value.validate()
  if (checkCode.value.data != emailModel.value.code) {
    ElMessage.error('验证码错误！')
    return
  }
  currentPage.value++
}

let obj = ref({
  dis: false, //disabled
  show: 0, // 0为显示发送验证码， 1为中间等待显示， 2为显示多少秒
  // isGrey: false, //按钮样式
  timer: null, //设置计时器,
  count: ''
})
let checkCode = ref()
//获取验证码
const getCode = async () => {
  if (!emailModel.value.username || !emailModel.value.email) {
    await form2.value.validate()
    return
  }
  obj.value.dis = true
  obj.value.show = 1
  checkCode.value = await getCodeByTeaEmail(
    emailModel.value.username,
    emailModel.value.email
  )
  console.log(checkCode)
  // console.log(obj.value.dis)

  if (!obj.value.timer) {
    obj.value.count = 60
    // obj.isGrey = true
    obj.value.show = 2
    obj.value.timer = setInterval(() => {
      if (obj.value.count > 0 && obj.value.count <= 60) {
        obj.value.count--
      } else {
        obj.value.dis = false
        // obj.isGrey = false
        obj.value.show = 0
        clearInterval(obj.value.timer)
        obj.value.timer = null
      }
    }, 1000)
  }
  ElMessage({ type: 'success', message: '获取验证码成功，请前往邮箱查看' })
}
const loadingPsw = ref(false)
const onsubmit = async () => {
  const valid = await form3.value.validate()
  if (valid) {
    loadingPsw.value = true //console.log(emailModel.value.username)
    await updateTeacherPassword(
      emailModel.value.username,
      passwordModel.value.new_pwd
    ) // console.log(checkCode.data)
    loadingPsw.value = false
    if (++currentPage.value > 1) currentPage.value = 0
    dialogVisible.value = false
    ElMessage({ type: 'success', message: '修改密码成功' })
  }
}
const clearForm = () => {
  //console.log(1111)
  emailModel.value = {}
  passwordModel.value = {}
  form2.value.clearValidate()
  form3.value.clearValidate()
  //currentPage.value = 1
}
const handleClose = (done) => {
  currentPage.value = 0
  done()
}

const options = [
  {
    value: '1',
    label: '管理员'
  },
  {
    value: '0',
    label: '学生'
  }
]
// userStore.userRole = options[0].value
const handleOptionChange = (value) => {
  userStore.userRole = value
  // console.log(userStore.userRole)
  router.push('/student')
}
</script>

<template>
  <el-row class="login-page">
    <el-col :span="12" class="bg"></el-col>
    <el-col :span="6" :offset="3" class="form">
      <el-form
        :model="formModel"
        ref="form1"
        :rules="rules1"
        size="large"
        autocomplete="off"
        @keyup.enter="login"
      >
        <el-form-item>
          <h1>登录</h1>
        </el-form-item>
        <el-form-item>
          <el-select
            v-model="formModel.value"
            placeholder="请选择身份"
            style="width: 100%"
            @change="handleOptionChange"
          >
            <el-option
              v-for="item in options"
              :key="item.value"
              :label="item.label"
              :value="item.value"
            />
          </el-select>
        </el-form-item>
        <el-form-item prop="username">
          <el-input
            v-model="formModel.username"
            :prefix-icon="User"
            placeholder="请输入用户名 "
          ></el-input>
        </el-form-item>
        <el-form-item prop="password">
          <el-input
            v-model="formModel.password"
            name="password"
            :prefix-icon="Lock"
            type="password"
            placeholder="请输入密码"
            show-password
          ></el-input>
        </el-form-item>
        <el-form-item class="flex">
          <div class="flex">
            <el-checkbox v-model="checked">记住我</el-checkbox>
            <el-link
              type="primary"
              :underline="false"
              @click="dialogVisible = true"
              >忘记密码？</el-link
            >
          </div>
        </el-form-item>
        <el-form-item>
          <el-button
            @click="login"
            class="button"
            type="primary"
            auto-insert-space
            >登录</el-button
          >
        </el-form-item>
      </el-form>
    </el-col>
  </el-row>

  <el-dialog
    v-model="dialogVisible"
    title="重置密码"
    style="width: 30%"
    @close="clearForm"
    :before-close="handleClose"
  >
    <div style="margin: 30px 20px">
      <el-steps :active="currentPage" finish-status="success" align-center>
        <el-step title="邮箱验证" />
        <el-step title="重置密码" />
      </el-steps>
    </div>

    <div v-show="currentPage === 0">
      <el-form
        label-width="50px"
        style="margin-top: 10px"
        :rules="rules2"
        :model="emailModel"
        ref="form2"
        v-loading="loading"
      >
        <el-form-item prop="username">
          <el-input
            v-model="emailModel.username"
            :prefix-icon="User"
            style="width: 320px"
            placeholder="请输入教职工号"
          />
        </el-form-item>
        <el-form-item prop="email">
          <el-input
            v-model="emailModel.email"
            :prefix-icon="Comment"
            style="width: 320px"
            placeholder="请输入邮箱"
          />
        </el-form-item>
        <el-form-item inline prop="code">
          <el-input
            v-model="emailModel.code"
            placeholder="请输入验证码"
            style="width: 200px"
            :prefix-icon="Promotion"
          />
          <el-button
            style="margin-left: 19px; width: 100px"
            @click="getCode"
            v-bind:disabled="obj.dis"
            ><span v-if="obj.show === 0">发送验证码</span>
            <span v-else-if="obj.show === 1"
              ><el-icon><Loading /></el-icon
            ></span>
            <span v-else-if="obj.show === 2"
              >重新发送{{ obj.count }}s</span
            ></el-button
          >
        </el-form-item>
      </el-form>
    </div>
    <div v-show="currentPage === 1">
      <el-form
        style="margin-top: 10px"
        label-width="100px"
        :rules="rules3"
        :model="passwordModel"
        ref="form3"
        v-loading="loadingPsw"
      >
        <el-form-item label="新密码" prop="new_pwd">
          <el-input
            v-model="passwordModel.new_pwd"
            type="password"
            style="width: 320px"
            show-password
          ></el-input>
        </el-form-item>
        <el-form-item label="确认新密码" prop="re_pwd">
          <el-input
            v-model="passwordModel.re_pwd"
            type="password"
            style="width: 320px"
            show-password
          ></el-input>
        </el-form-item>
      </el-form>
    </div>
    <div style="text-align: center">
      <!-- <el-button
        v-if="currentPage > 0"
        @click="prevPage"
        style="margin-top: 10px"
        >上一页</el-button
      > -->
      <el-button
        v-if="currentPage < totalPage"
        @click="nextPage"
        style="margin-top: 10px"
        >下一步</el-button
      >
      <el-button
        v-else
        @click="onsubmit"
        type="primary"
        style="margin-top: 10px"
        >提交</el-button
      >
    </div>
  </el-dialog>
</template>
<style lang="scss" scoped>
.login-page {
  height: 100vh;
  background-color: #fff;

  .bg {
    background:
      url('@/assets/logo2.png') no-repeat center / 500px auto,
      url('@/assets/login_bg.jpg') no-repeat center / cover;
    border-radius: 0 20px 20px 0;
  }

  .form {
    display: flex;
    flex-direction: column;
    justify-content: center;
    user-select: none;

    .title {
      margin: 0 auto;
    }

    .button {
      width: 100%;
    }

    .flex {
      width: 100%;
      display: flex;
      justify-content: space-between;
    }
  }
} /* 没有到达 */
// ::v-deep .el-step__head.is-process {
//   margin-right: 0px;
//   color: #ddd !important;
//   border-color: #ddd !important;
// }
// /*  文字*/
// ::v-deep .el-step__title.is-process {
//   text-align: center;
//   color: #ddd;
// }
// /* 对勾 */
// ::v-deep .el-step__head.is-success {
//   color: rgb(52, 158, 250);
//   border-color: rgb(52, 158, 250);
//   margin-left: 18px;
// }
// /*  文字*/
// ::v-deep .el-step__title.is-success {
//   color: rgb(52, 158, 250);
// }
</style>
