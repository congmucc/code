<template>
  <page-container title="人员信息管理">
    <template #extra>
      <template v-if="isShow === false">
        <el-button @click="display('View')">显示隐藏信息</el-button>
      </template>
      <template v-if="isShow === true">
        <el-button @click="display('Hide')">隐藏信息</el-button>
      </template>
    </template>
    <el-form
      :model="state.form"
      size="default"
      ref="formRef"
      :rules="rules"
      label-width="160px"
    >
      <el-row>
        <el-col :span="13">
          <el-form-item label="姓名:">
            <el-input
              v-model="state.form.name"
              disabled
              autocomplete="off"
              style="width: 220px"
            />
          </el-form-item>
          <el-form-item label="学号:">
            <el-input v-model="state.form.id" disabled style="width: 220px" />
          </el-form-item>
          <el-form-item label="身份证号:" prop="idNum">
            <el-input v-model="state.form.idNum" style="width: 220px" />
          </el-form-item>
          <el-form-item label="出生年月:" prop="birthday">
            <el-input
              v-model="state.form.birthday"
              disabled
              style="width: 220px"
              placeholder="提交后会计算"
            />
          </el-form-item>
          <el-form-item label="籍贯:" prop="hometown">
            <el-cascader
              :options="state.pcaTextArr"
              v-model="state.form.hometown"
            >
            </el-cascader>
          </el-form-item>
          <el-form-item label="手机号:" prop="phoneNum">
            <el-input v-model="state.form.phoneNum" style="width: 220px" />
          </el-form-item>

          <el-form-item label="家庭详细地址:" prop="homeAddress">
            <el-input v-model="state.form.homeAddress" style="width: 440px" />
          </el-form-item>
          <el-form-item label="身份:" prop="status">
            <el-select v-model="state.form.status" placeholder="请选择">
              <el-option label="积极分子" value="积极分子" />
              <el-option label="发展对象" value="发展对象" />
              <el-option label="预备党员" value="预备党员"></el-option>
            </el-select>
          </el-form-item>
          <el-form-item label="年级:" prop="grade">
            <el-input
              v-model="state.form.grade"
              placeholder="例如:2021级"
              style="width: 220px"
            />
          </el-form-item>
          <el-form-item label="专业:" prop="major">
            <el-input
              v-model="state.form.major"
              placeholder="例如:软件工程"
              style="width: 220px"
            />
          </el-form-item>
          <el-form-item label="班级:" prop="classNum">
            <el-input
              v-model="state.form.classNum"
              placeholder="例如:1班"
              style="width: 220px"
            />
          </el-form-item>
          <el-form-item label="入团时间:" prop="joiningTime">
            <el-tooltip
              effect="light"
              content="不清楚具体日期的话，填写1号，如是节假日为4号"
              placement="bottom-start"
            >
              <el-col :span="13">
                <el-date-picker
                  type="date"
                  placeholder="选择日期"
                  v-model="state.form.joiningTime"
                  value-format="YYYY-MM-DD"
                />
              </el-col>
            </el-tooltip>
          </el-form-item>
        </el-col>
        <el-col :span="11">
          <el-form-item
            label="入团学校名称:"
            prop="joiningSchool"
            width="160px"
          >
            <el-input v-model="state.form.joiningSchool" style="width: 220px" />
          </el-form-item>
          <el-form-item label="提交入党申请书时间:" prop="subTime">
            <el-col :span="13">
              <el-date-picker
                type="date"
                placeholder="选择日期"
                v-model="state.form.subTime"
                value-format="YYYY-MM-DD"
              />
            </el-col>
          </el-form-item>
          <el-form-item label="入党申请书公示时间:" prop="pubTime">
            <el-col :span="13">
              <el-date-picker
                type="daterange"
                placeholder="选择日期"
                range-separator="至"
                start-placeholder="开始时间"
                end-placeholder="结束时间"
                v-model="state.form.pubTime"
                value-format="YYYY-MM-DD"
              />
            </el-col>
          </el-form-item>
          <el-form-item label="确定积极分子时间:" prop="detTime">
            <el-col :span="13">
              <el-date-picker
                type="date"
                placeholder="选择日期"
                v-model="state.form.detTime"
                value-format="YYYY-MM-DD"
              />
            </el-col>
          </el-form-item>
          <el-form-item label="党总支审议时间:" prop="delTime">
            <el-tooltip
              effect="light"
              content="如果暂时不知道，请等老师通知"
              placement="right"
            >
              <el-col :span="13">
                <el-date-picker
                  type="date"
                  style="width: 100%"
                  placeholder="选择日期"
                  v-model="state.form.delTime"
                  value-format="YYYY-MM-DD"
                />
              </el-col>
            </el-tooltip>
          </el-form-item>

          <el-form-item label="上级党委备案时间:" prop="filTime">
            <el-tooltip
              effect="light"
              content="如果暂时不知道，请等老师通知"
              placement="right"
            >
              <el-col :span="13">
                <el-date-picker
                  type="date"
                  style="width: 100%"
                  placeholder="选择日期"
                  v-model="state.form.filTime"
                  value-format="YYYY-MM-DD"
                />
              </el-col>
            </el-tooltip>
          </el-form-item>
          <el-form-item label="入党培养人:" prop="culPeople">
            <el-input v-model="state.form.culPeople" style="width: 220px" />
          </el-form-item>

          <el-form-item label="党课培训情况:" prop="condition">
            <el-select
              v-model="state.form.condition"
              placeholder="请选择"
              :disabled="isDisabled"
            >
              <el-option label="优秀" value="优秀" />
              <el-option label="不合格" value="不合格" />
            </el-select>
          </el-form-item>

          <el-form-item label="参加党课时间:" prop="traTime">
            <el-col :span="13">
              <el-date-picker
                type="date"
                placeholder="选择日期"
                v-model="state.form.traTime"
                value-format="YYYY-MM-DD"
                :disabled="isDisabled"
              />
            </el-col>
          </el-form-item>
          <el-form-item label="结业时间:" prop="comTime">
            <el-col :span="13">
              <el-date-picker
                type="date"
                placeholder="选择日期"
                v-model="state.form.comTime"
                value-format="YYYY-MM-DD"
                :disabled="isDisabled"
              />
            </el-col>
          </el-form-item>
          <el-form-item label="党课考试是否合格:" prop="qua">
            <el-select
              v-model="state.form.qua"
              placeholder="请选择"
              :disabled="isDisabled"
            >
              <el-option label="合格" value="合格" />
              <el-option label="不合格" value="不合格" />
            </el-select>
          </el-form-item>
        </el-col>
      </el-row>
    </el-form>
    <div style="text-align: center">
      <el-button @click="onsubmit" type="primary" style="margin-top: 10px"
        >提交</el-button
      >
    </div>
    <!-- 身份证和手机号对话框显示 -->
    <el-dialog v-model="dialogDisplayVisible" title="密码验证">
      <el-form-item label="请输入密码">
        <el-input type="password" show-password v-model="displayPassword" />
      </el-form-item>
      <template #footer>
        <span class="dialog-footer">
          <el-button @click="dialogDisplayVisible = false">取消</el-button>
          <el-button type="primary" @click="displayData"> 验证 </el-button>
        </span>
      </template>
    </el-dialog>
  </page-container>
</template>
<script setup>
// import request from './../utils/request'
import { reactive, ref } from 'vue'
import { Base64 } from 'js-base64'
import { useUserStore } from '@/stores'
import { pcaTextArr } from 'element-china-area-data'
import { getStudentInformation, updateStuInformation } from '@/api/user.js'
const userStore = useUserStore()
import { ElMessage, ElMessageBox } from 'element-plus'
const dialogFormVisible = ref(false)
//const currentPage = ref(1)
// // 是否显示身份证和手机号
const dialogDisplayVisible = ref(false)
const isShow = ref(false)
const displayPassword = ref()
const display = (type) => {
  if (type === 'View') {
    dialogDisplayVisible.value = true
  } else if (type === 'Hide') {
    isShow.value = false
    load()
  }
}

const displayData = () => {
  if (displayPassword.value === atob(userStore.user.password)) {
    isShow.value = true
    timeoutId()
    dialogDisplayVisible.value = false
    load()
  } else {
    ElMessage.error('密码错误')
  }
}

const timeoutId = () => {
  setTimeout(() => {
    // 与数据库原数不相同那就不刷新
    if (
      state.form.phoneNum !== tempData.value.phoneNum ||
      state.form.idNum !== tempData.value.idNum
    ) {
      clearTimeout(timeoutId)
      return // 立即退出函数
    }
    isShow.value = false
    // 刷新
    if (state.form.idNum != null && !isShow.value) {
      state.form.idNum = state.form.idNum.replace(
        /^(\w{2})(\w+)(\w{2})$/,
        '$1**************$3'
      )
    }
    if (state.form.phoneNum != null && !isShow.value) {
      state.form.phoneNum = state.form.phoneNum.replace(
        /^(\w{3})\w{4}(\w{4})$/,
        '$1****$2'
      )
    }
  }, 60000)
}

// 表单数据
const isDisabled = ref(true)
const state = reactive({
  pcaTextArr,
  form: {
    id: '',
    name: '',
    status: '',
    grade: '',
    major: '',
    classNum: '',
    idNum: '',
    birthday: '',
    hometown: '',
    phoneNum: '',
    joiningTime: '',
    joiningSchool: '',
    homeAddress: '',
    subTime: '',
    pubTime: [],
    detTime: '',
    delTime: '',
    filTime: '',
    culPeople: '',
    condition: '',
    traTime: '',
    comTime: '',
    qua: ''
  }
})

const checkGrade = (rule, value, cb) => {
  if (!value) {
    return cb(new Error('年级不能为空'))
  } else {
    if (
      value.length != 5 ||
      value.substring(value.length - 1, value.length) != '级'
    ) {
      return cb(new Error('格式为20xx级'))
    } else {
      cb()
    }
  }
}
const checkClassNum = (rule, value, cb) => {
  if (!value) {
    return cb(new Error('班级不能为空'))
  } else {
    if (
      value.substring(value.length - 1, value.length) != '班' ||
      Number.isNaN(
        Number.parseInt(value.substring(value.length - 2, value.length - 1))
      )
    ) {
      return cb(new Error('格式错误'))
    } else {
      cb()
    }
  }
}
//判断身份并且通过身份更改isDisabled
const checkStatus = (rule, value, cb) => {
  if (!value) {
    return cb(new Error('身份不能为空'))
  } else {
    if (value == '积极分子') {
      isDisabled.value = true
      cb()
    } else {
      isDisabled.value = false
      cb()
    }
  }
}

const rules = {
  phoneNum: [
    { required: true, message: '手机号不能为空', trigger: 'blur' },
    { min: 11, max: 11, message: '手机号必须是11位长度', trigger: 'blur' }
  ],
  idNum: [
    { required: true, message: '身份证号不能为空', trigger: 'blur' },
    { min: 18, max: 18, message: '身份证号必须是18位长度', trigger: 'blur' }
  ],
  // 其余字段不能为空
  grade: [{ required: true, validator: checkGrade, trigger: 'blur' }],
  major: [{ required: true, message: '专业不能为空', trigger: 'blur' }],
  classNum: [{ required: true, validator: checkClassNum, trigger: 'blur' }],
  hometown: [{ required: true, message: '请选择籍贯', trigger: 'blur' }],
  homeAddress: [
    { required: true, message: '家庭详细地址不能为空', trigger: 'blur' }
  ],
  status: [{ required: true, validator: checkStatus, trigger: 'change' }],
  culPeople: [
    { required: true, message: '入党培养人不能为空', trigger: 'blur' }
  ],
  joiningSchool: [
    { required: true, message: '入团学校名称不能为空', trigger: 'blur' }
  ],
  joiningTime: [
    { required: true, message: '入团时间不能为空', trigger: 'change' }
  ],
  subTime: [
    { required: true, message: '提交入党申请书时间不能为空', trigger: 'blur' }
  ],
  pubTime: [{ required: true, message: '入党申请书公示时间', trigger: 'blur' }],
  userPC: [
    { required: true, message: '党课培训情况不能为空', trigger: 'change' }
  ],
  detTime: [
    { required: true, message: '确定积极分子时间不能为空', trigger: 'change' }
  ],
  userQ: [{ required: true, message: '是否合格不能为空', trigger: 'change' }],
  userPCT: [{ required: true, message: '结业时间不能为空', trigger: 'change' }]
}
// 步骤配置
// const steps = ref([
//   { title: '第一页' },
//   { title: '第二页' },
//   { title: '第三页' }
// ])

// 总页数
//const totalPage = steps.value.length

// 下一页
// const nextPage = () => {
//   currentPage.value++
// }

// 上一页
// const prevPage = () => {
//   currentPage.value--
// }
//身份证号和手机号处理--解*
const changeId = (oldId, newId) => {
  let id = ''
  for (let index = 0; index < oldId.length; index++) {
    if (newId.at(index) == '*') {
      id = id + oldId.at(index)
    } else {
      id = id + newId.at(index)
    }
  }
  return id
}
const formRef = ref(null)
const onsubmit = async () => {
  formRef.value.validate(async (valid) => {
    if (valid) {
      // 表单校验通过，进行网络请求
      try {
        await ElMessageBox.confirm('确定提交数据吗?', '提示', {
          confirmButtonText: '确定',
          cancelButtonText: '取消',
          type: 'warning'
        })
        state.form.hometown = state.form.hometown.toString()
        state.form.pubTime = state.form.pubTime.toString()
        if (
          tempData.value.phoneNum !== null &&
          state.form.phoneNum.includes('*')
        ) {
          state.form.phoneNum = changeId(
            tempData.value.phoneNum,
            state.form.phoneNum
          )
        }
        if (tempData.value.idNum !== null && state.form.idNum.includes('*')) {
          state.form.idNum = changeId(tempData.value.idNum, state.form.idNum)
        }
        await updateStuInformation(state.form)
        ElMessage.success('操作成功')
        load() // 更新表格
        // displayArr.idNum = false
        // displayArr.phoneNum = false
        dialogFormVisible.value = false
      } catch (error) {
        // 处理异常情况
        console.error(error)
      }
    } else {
      // 表单校验不通过，提示错误信息
      ElMessage.error('请填写正确的表单信息')
    }
  })
}
const tempData = ref({
  phoneNum: '',
  idNum: ''
})
const load = async () => {
  const res = await getStudentInformation(userStore.user.username)
  state.form = res.data.data
  if (state.form.idNum != null && state.form.idNum != '') {
    state.form.idNum = Base64.decode(state.form.idNum)
  }
  tempData.value.phoneNum = res.data.data.phoneNum
  tempData.value.idNum = state.form.idNum

  if (state.form.idNum != null && !isShow.value) {
    state.form.idNum = state.form.idNum.replace(
      /^(\w{2})(\w+)(\w{2})$/,
      '$1**************$3'
    )
  }
  if (state.form.phoneNum != null && !isShow.value) {
    state.form.phoneNum = state.form.phoneNum.replace(
      /^(\w{3})\w{4}(\w{4})$/,
      '$1****$2'
    )
  }
  if (state.form.pubTime != null) {
    state.form.pubTime = state.form.pubTime.split(',')
  }
  if (state.form.hometown != null) {
    state.form.hometown = state.form.hometown.split(',')
  }
}
load()
</script>

<style scoped>
/* .el-col-13 {
  flex: none !important;
} */

/* .student {
  background-color: #fff;
  margin: 10px;
  padding: 72px;
  height: 610px;
} */
/* .el-form {
  margin-top: 20px;
  margin-bottom: 30px;
  height: 350px;
} */

/* .foster {
  display: flex;
  justify-content: space-between;
  width: auto;
  margin: -36px, 0, 0, 0;
  padding: 10, 0, 0, 0;
} */
/* 没有到达 */
/* ::v-deep .el-step__head.is-process {
  color: #ddd !important;
  border-color: #ddd !important;
} */
/*  文字*/
/* ::v-deep .el-step__title.is-process {
  font-weight: bold;
  color: #ddd;
} */
/* 对勾 */
/* ::v-deep .el-step__head.is-success {
  color: rgb(52, 158, 250);
  border-color: rgb(52, 158, 250);
} */
/*  文字*/
/* ::v-deep .el-step__title.is-success {
  font-weight: bold;
  color: rgb(52, 158, 250);
} */
</style>
