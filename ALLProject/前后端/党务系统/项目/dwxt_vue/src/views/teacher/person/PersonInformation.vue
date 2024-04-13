<script setup>
import { ref } from 'vue'
import { Base64 } from 'js-base64'
import { Search, Edit } from '@element-plus/icons-vue'
import { personGetInformationService, personById } from '../../../api/person'
import { updateStuInformation } from '@/api/user.js'
import { pcaTextArr } from 'element-china-area-data'
import * as Xlsx from 'xlsx'
import { ElMessage } from 'element-plus'
// import { pa } from 'element-plus/es/locale'
//import { Search } from '@element-plus/icons-vue'

//分页、表格
const total = ref(0)
const params = ref({
  pagenum: 1,
  pagesize: 10,
  id: '',
  name: '',
  status: '',
  grade: '',
  major: '',
  class_num: '',
  id_num: '',
  hometown: '',
  phone_num: '',
  joining_time: '',
  joining_school: '',
  home_adress: '',
  sub_time: '',
  pub_tiem: '',
  det_time: '',
  del_time: '',
  fil_time: '',
  cul_people: '',
  condition: '',
  tra_time: '',
  com_time: '',
  qua: '',
  isAllInformation: false
})
//
const activatorForm = ref({
  name: '',
  id: '',
  status: '',
  grade: '',
  major: '',
  classNum: '',
  idNum: '',
  birthday: '',
  sex: '',
  hometown: '',
  phoneNum: '',
  joiningTime: '',
  joiningSchool: '',
  homeAddress: '',
  subTime: '',
  pubTime: '',
  detTime: '',
  delTime: '',
  filTime: '',
  culPeople: '',
  condition: '',
  traTime: '',
  comTime: '',
  qua: ''
})

//获取列表
const loading = ref(false)
const informationList = ref([])
// 是否显示身份证和手机号
const dialogDisplayVisible = ref(false)
// 信息导出显示
const dialogExcelVisible = ref(false)
const isShow = ref(false)
const displayPassword = ref()
const display = (type) => {
  if (type === 'View') {
    // isShow.value = true
    // getInformationList()
    dialogDisplayVisible.value = true
  } else if (type === 'Hide') {
    isShow.value = false
    getInformationList()
  }
}

// 手机、身份证验证
const displayData = () => {
  if (displayPassword.value === 'KCxgdw2021') {
    isShow.value = true
    timeoutId()
    dialogDisplayVisible.value = false
    getInformationList()
  } else {
    ElMessage.error('密码错误')
  }
}

// excel验证
const outExcelCheck = () => {
  if (displayPassword.value === 'KCxgdw2021') {
    OutExcel()
    dialogExcelVisible.value = false
  } else {
    ElMessage.error('密码错误')
  }
}

const timeoutId = () => {
  setTimeout(() => {
    isShow.value = false
    getInformationList()
  }, 60000)
}

const getInformationList = async () => {
  loading.value = true
  const res = await personGetInformationService(params.value)
  // console.log(params.value)
  informationList.value = res.data.data.rows
  informationList.value.map((n) => {
    if (n.idNum != null) {
      n.idNum = Base64.decode(n.idNum)
    }
    if (n.idNum != null && !isShow.value) {
      n.idNum = n.idNum.replace(/^(\w{2})(\w+)(\w{2})$/, '$1**************$3')
    }
    if (n.phoneNum !== null && !isShow.value) {
      n.phoneNum = n.phoneNum.replace(/^(\w{3})\w{4}(\w{4})$/, '$1****$2')
    }
    if (n.hometown !== null) {
      n.hometown = n.hometown.replace(/,/g, '')
    }
    if (n.pubTime !== null) {
      n.pubTime = n.pubTime.replace(/-/g, '.').replace(',', '--')
    }
  })
  total.value = res.data.data.total
  loading.value = false
}
getInformationList()

const onSizeChange = (size) => {
  //console.log('当前页条数', size)
  params.value.pagenum = 1
  params.value.pagesize = size
  getInformationList()
}
const onCurrentChange = (page) => {
  //console.log('页码变化', page)
  params.value.pagenum = page
  getInformationList()
}

//下拉框
const qua = ref('')
const status = ref('')
const quaoptions = [
  {
    value: '合格',
    label: '合格'
  },
  {
    value: '不合格',
    label: '不合格'
  }
]
const enNameToCnName = {
  id: '学号',
  name: '姓名',
  status: '身份',
  grade: '年级',
  major: '专业',
  classNum: '班级',
  idNum: '身份证号',
  birthday: '年龄',
  sex: '性别',
  hometown: '籍贯',
  phoneNum: '手机号',
  joiningTime: '入团日期',
  joiningSchool: '入团学校名称',
  homeAddress: '家庭详细地址',
  subTime: '提交入党申请书时间',
  pubTime: '入党申请公示时间',
  detTime: '确定积极分子时间',
  delTime: '审议时间',
  filTime: '上级党委备案时间',
  culPeople: '入党培养人',
  condition: '参加培训情况',
  traTime: '参加培训时间',
  comTime: '结业时间',
  qua: '培训是否合格'
}
const staoptions = [
  {
    value: '积极分子',
    label: '积极分子'
  },
  {
    value: '预备党员',
    label: '预备党员'
  },
  {
    value: '党员',
    label: '党员'
  }
]

//回显
// const checkGrade = (rule, value, cb) => {
//   if (
//     value &&
//     (value.length !== 5 || value.substring(value.length - 1) !== '级')
//   ) {
//     return cb(new Error('格式为20xx级'))
//   }
//   cb()
// }

const checkClassNum = (rule, value, cb) => {
  if (value) {
    if (
      value.substring(value.length - 1) !== '班' ||
      isNaN(
        Number.parseInt(value.substring(value.length - 2, value.length - 1))
      )
    ) {
      return cb(new Error('格式错误'))
    }
  }
  cb()
}

const rules = {
  phoneNum: [
    { min: 11, max: 11, message: '手机号必须是11位长度', trigger: 'blur' }
  ],
  idNum: [
    { min: 18, max: 18, message: '身份证号必须是18位长度', trigger: 'blur' }
  ],
  grade: [
    {
      pattern: /^20\d\d级$/,
      message: '格式为20xx级',
      trigger: 'blur'
    }
  ],

  classNum: [{ validator: checkClassNum, trigger: 'blur' }]
  //hometown: [{ required: true, message: '请选择籍贯', trigger: 'change' }]
}
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
const tempData = ref({
  idNum: '',
  phoneNum: ''
})
//编辑对话框
let dialogVisible = ref(false)
const onResetAccount = async (id) => {
  const oneForm = await personById(id)
  activatorForm.value = oneForm.data.data
  if (activatorForm.value.idNum != null && activatorForm.value.idNum != '') {
    activatorForm.value.idNum = Base64.decode(activatorForm.value.idNum)
  }
  tempData.value.phoneNum = activatorForm.value.phoneNum
  tempData.value.idNum = activatorForm.value.idNum
  if (activatorForm.value.idNum != null) {
    activatorForm.value.idNum = activatorForm.value.idNum.replace(
      /^(\w{2})(\w+)(\w{2})$/,
      '$1**************$3'
    )
  }
  if (activatorForm.value.phoneNum != null) {
    activatorForm.value.phoneNum = activatorForm.value.phoneNum.replace(
      /^(\w{3})\w{4}(\w{4})$/,
      '$1****$2'
    )
  }
  if (activatorForm.value.pubTime !== null) {
    activatorForm.value.pubTime = activatorForm.value.pubTime.split(',')
  }
  if (activatorForm.value.hometown !== null) {
    activatorForm.value.hometown = activatorForm.value.hometown.split(',')
  }

  dialogVisible.value = true
}
//提交
const activatorRef = ref()
const saveStuInfo = async () => {
  await activatorRef.value.validate()
  if (activatorForm.value.hometown != null) {
    activatorForm.value.hometown = activatorForm.value.hometown.toString()
  }
  if (activatorForm.value.pubTime != null) {
    activatorForm.value.pubTime = activatorForm.value.pubTime.toString()
  }
  if (
    tempData.value.phoneNum !== null &&
    activatorForm.value.phoneNum.includes('*')
  ) {
    activatorForm.value.phoneNum = changeId(
      tempData.value.phoneNum,
      activatorForm.value.phoneNum
    )
  }
  if (
    tempData.value.idNum !== null &&
    activatorForm.value.idNum.includes('*')
  ) {
    activatorForm.value.idNum = changeId(
      tempData.value.idNum,
      activatorForm.value.idNum
    )
  }
  const res = await updateStuInformation(activatorForm.value)
  if (res.data.message == '身份证号有误') {
    onResetAccount(activatorForm.value.id)
    return
  }
  ElMessage.success('操作成功')
  getInformationList() // 更新表格
  dialogVisible.value = false
}

//搜索
const dettime = ref('')
const inputid = ref('')
const inputgrade = ref('')
const inputmajor = ref('')
const inputname = ref('')
const inputcul = ref('')
const inputbir = ref('')
const onSearch = () => {
  params.value.pagenum = 1
  params.value.id = inputid.value
  params.value.grade = inputgrade
  params.value.major = inputmajor
  params.value.name = inputname.value
  params.value.cul_people = inputcul.value
  params.value.det_time = dettime.value
  params.value.qua = qua.value
  params.value.status = status.value
  params.value.birthday = inputbir.value
  getInformationList()
}

//导出excel时通过身份证号获取年龄
const getAgeByIdCard = (idNum) => {
  let myDate = new Date()
  let month = myDate.getMonth() + 1
  let day = myDate.getDate()
  let age = myDate.getFullYear() - idNum.substring(6, 10) - 1
  if (
    idNum.substring(10, 12) < month ||
    (idNum.substring(10, 12) == month && idNum.substring(12, 14) <= day)
  ) {
    age++
  }
  return age
}
//导出excel时通过身份证号获取性别
const getSexByIdCard = (idNum) => {
  if (parseInt(idNum.substr(16, 1)) % 2 == 1) {
    return '男'
  } else {
    return '女'
  }
}
//判断日期值是否为null，不是则,改.
const DateIsNull = (value) => {
  if (value != null) {
    value = value.replace(/-/g, '.')
    return value
  }
}


// const loadingE = ref(false)
const OutExcel = async () => {
  loading.value = true
  params.value.pagenum = 1
  params.value.id = inputid.value
  params.value.grade = inputgrade
  params.value.major = inputmajor
  params.value.name = inputname.value
  params.value.cul_people = inputcul.value
  params.value.det_time = dettime.value
  params.value.qua = qua.value
  params.value.status = status.value
  params.value.isAllInformation = true
  const res = await personGetInformationService(params.value)
  let excelData = res.data.data.map((n) => {
    //通过身份证号获取年龄
    //如果是空值不做处理
    if (n.idNum != null) {
      n.idNum = Base64.decode(n.idNum)
      n.birthday = getAgeByIdCard(n.idNum)
      n.sex = getSexByIdCard(n.idNum)
    }
    if (n.pubTime != null) {
      n.pubTime = n.pubTime.replace(/-/g, '.').replace(',', '--')
    }
    if (n.hometown != null) {
      n.hometown = n.hometown.replace(/,/g, '')
    }
    n.joiningTime = DateIsNull(n.joiningTime)
    n.subTime = DateIsNull(n.subTime)
    n.delTime = DateIsNull(n.delTime)
    n.detTime = DateIsNull(n.delTime)
    n.filTime = DateIsNull(n.filTime)
    n.traTime = DateIsNull(n.traTime)
    n.comTime = DateIsNull(n.comTime)
    //更换日期格式 2023-01-15 -> 2023.01.15
    // this.changeDate(n.birthday)
    let newItem = []
    Object.keys(n).forEach((k) => {
      newItem[enNameToCnName[k]] = n[k]
    })
    return newItem
  })
  const xlsxObj = {
    SheetNames: ['sheet1'],
    Sheets: {
      ['sheet1']: Xlsx.utils.json_to_sheet(excelData)
    }
  }
  Xlsx.writeFile(xlsxObj, '积极分子信息表.xlsx')
  loading.value = false
}

const onReset = () => {
  params.value.pagenum = 1
  params.value.id = ''
  params.value.grade = ''
  params.value.major = ''
  params.value.name = ''
  params.value.cul_people = ''
  params.value.qua = ''
  params.value.det_time = ''
  params.value.status = ''
  params.value.birthday = ''
  inputid.value = ''
  inputgrade.value = ''
  inputmajor.value = ''
  inputname.value = ''
  inputcul.value = ''
  qua.value = ''
  dettime.value = ''
  status.value = ''
  inputbir.value = ''
  getInformationList()
}
</script>
<template>
  <page-container title="人员信息管理">
    <template #extra>
      <template v-if="isShow === false">
        <el-button @click="display('View')">显示隐藏信息</el-button>
      </template>
      <template v-if="isShow === true">
        <el-button @click="display('Hide')">隐藏信息</el-button>
      </template>

      <el-button @click="dialogExcelVisible = true">信息导出</el-button>
    </template>
    <!-- 搜索栏 -->
    <el-collapse>
      <el-collapse-item title="搜索菜单">
        <div>
          <el-form inline>
            <el-form-item label="学号:">
              <el-input
                :prefix-icon="Search"
                v-model="inputid"
                placeholder="请输入学号"
              ></el-input>
            </el-form-item>
            <el-form-item label="年级:">
              <el-input
                :prefix-icon="Search"
                v-model="inputgrade"
                placeholder="请输入年级"
              ></el-input>
            </el-form-item>
            <el-form-item label="专业:">
              <el-input
                :prefix-icon="Search"
                v-model="inputmajor"
                placeholder="请输入专业"
              ></el-input>
            </el-form-item>
            <el-form-item label="姓名:">
              <el-input
                :prefix-icon="Search"
                v-model="inputname"
                placeholder="请输入姓名"
              ></el-input>
            </el-form-item>
            <el-form-item label="身份:">
              <el-select v-model="status" clearable placeholder="请选择">
                <el-option
                  v-for="item in staoptions"
                  :key="item.value"
                  :label="item.label"
                  :value="item.value"
                />
              </el-select>
            </el-form-item>
            <el-form-item label="确定积极分子时间:">
              <el-date-picker
                v-model="dettime"
                format="YYYY-MM-DD"
                value-format="YYYY-MM-DD"
                type="date"
                placeholder="请选择时间"
              />
            </el-form-item>
            <el-form-item label="入党培养人:">
              <el-input
                :prefix-icon="Search"
                v-model="inputcul"
                placeholder="请输入培养人姓名"
              ></el-input>
            </el-form-item>
            <el-form-item label="培训是否合格:">
              <el-select v-model="qua" clearable placeholder="请选择">
                <el-option
                  v-for="item in quaoptions"
                  :key="item.value"
                  :label="item.label"
                  :value="item.value"
                />
              </el-select>
            </el-form-item>
            <el-form-item label="出生日期时间:">
              <el-date-picker
                v-model="inputbir"
                format="YYYY-MM-DD"
                value-format="YYYY-MM-DD"
                type="date"
                placeholder="请选择时间"
              />
            </el-form-item>
            <div style="text-align: center">
              <el-form-item>
                <el-button @click="onSearch" type="primary">搜索</el-button>
                <el-button @click="onReset">重置</el-button>
              </el-form-item>
            </div>
          </el-form>
        </div>
      </el-collapse-item>
    </el-collapse>
    <!-- 表格 -->
    <el-table
      :data="informationList"
      style="width: 100%"
      v-loading="loading"
      height="550"
    >
      <el-table-column label="姓名" prop="name" fixed></el-table-column>
      <el-table-column label="学号" prop="id" width="120"></el-table-column>
      <el-table-column label="身份" prop="status"></el-table-column>
      <el-table-column label="年级" prop="grade"></el-table-column>
      <el-table-column label="专业" prop="major"></el-table-column>
      <el-table-column label="班级" prop="classNum"></el-table-column>
      <el-table-column
        label="身份证号"
        prop="idNum"
        width="180"
      ></el-table-column>
      <el-table-column
        label="出生日期"
        prop="birthday"
        width="110"
      ></el-table-column>
      <el-table-column
        label="籍贯"
        prop="hometown"
        width="180"
      ></el-table-column>
      <el-table-column
        label="手机号"
        prop="phoneNum"
        width="120"
      ></el-table-column>
      <el-table-column
        label="入团时间"
        prop="joiningTime"
        width="120"
      ></el-table-column>
      <el-table-column
        label="入团学校"
        prop="joiningSchool"
        width="180"
      ></el-table-column>
      <el-table-column
        label="家庭住址"
        prop="homeAddress"
        width="200"
      ></el-table-column>
      <el-table-column
        label="提交入党申请书时间"
        prop="subTime"
        width="200"
      ></el-table-column>
      <el-table-column
        label="入党申请公示时间"
        prop="pubTime"
        width="300"
      ></el-table-column>
      <el-table-column
        label="确定积极分子时间"
        prop="detTime"
        width="200"
      ></el-table-column>
      <el-table-column
        label="审议时间"
        prop="delTime"
        width="200"
      ></el-table-column>
      <el-table-column
        label="上级党委备案时间"
        prop="filTime"
        width="200"
      ></el-table-column>
      <el-table-column
        label="入党培养人"
        prop="culPeople"
        width="120"
      ></el-table-column>
      <el-table-column
        label="参加培训情况"
        prop="condition"
        width="200"
      ></el-table-column>
      <el-table-column
        label="参加培训时间"
        prop="traTime"
        width="200"
      ></el-table-column>
      <el-table-column
        label="结业时间"
        prop="comTime"
        width="200"
      ></el-table-column>
      <el-table-column
        label="培训是否合格"
        prop="qua"
        width="110"
      ></el-table-column>
      <el-table-column label="操作" width="70" fixed="right">
        <template #default="{ row }">
          <el-button :icon="Edit" @click="onResetAccount(row.id)"></el-button>
        </template>
      </el-table-column>
      <template #empty>
        <el-empty description="空" :image-size="200"></el-empty>
      </template>
    </el-table>
    <!--编辑对话框表单111111-->
    <el-dialog
      destroy-on-close
      title="修改积极分子信息"
      v-model="dialogVisible"
      width="90%"
      :append-to-body="true"
    >
      <el-form
        ref="activatorRef"
        :model="activatorForm"
        label-width="160px"
        :rules="rules"
      >
        <el-row>
          <el-col :span="8">
            <el-form-item label="姓名" prop="name">
              <el-input
                v-model="activatorForm.name"
                style="width: 220px"
                disabled
              ></el-input>
            </el-form-item>
            <el-form-item label="学号" prop="id">
              <el-input
                v-model="activatorForm.id"
                style="width: 220px"
                disabled
              ></el-input>
            </el-form-item>
            <el-form-item label="身份:" prop="status">
              <el-select v-model="activatorForm.status" placeholder="请选择">
                <el-option label="积极分子" value="积极分子" />
                <el-option label="发展对象" value="发展对象" />
                <el-option label="预备党员" value="预备党员"></el-option>
              </el-select>
            </el-form-item>
            <el-form-item label="年级" prop="grade">
              <el-input
                v-model="activatorForm.grade"
                style="width: 220px"
                placeholder="xxxx级"
              ></el-input>
            </el-form-item>
            <el-form-item label="专业" prop="major">
              <el-input
                v-model="activatorForm.major"
                style="width: 220px"
              ></el-input>
            </el-form-item>
            <el-form-item label="班级" prop="classNum">
              <el-input
                v-model="activatorForm.classNum"
                style="width: 220px"
                placeholder="例：1班"
              ></el-input>
            </el-form-item>
            <el-form-item label="身份证号" prop="idNum">
              <el-input
                v-model="activatorForm.idNum"
                style="width: 220px"
              ></el-input>
            </el-form-item>
            <el-form-item label="出生日期" prop="birthday">
              <el-date-picker
                disabled
                v-model="activatorForm.birthday"
                type="date"
                placeholder="提交后会计算"
              ></el-date-picker>
            </el-form-item>
          </el-col>
          <el-col :span="8">
            <el-form-item label="籍贯:" prop="hometown">
              <el-cascader
                :options="pcaTextArr"
                v-model="activatorForm.hometown"
              >
              </el-cascader>
              <!-- <el-input v-model="state.form.hometown" /> -->
            </el-form-item>
            <el-form-item label="手机号" prop="phoneNum">
              <el-input
                v-model="activatorForm.phoneNum"
                style="width: 220px"
              ></el-input>
            </el-form-item>
            <el-form-item label="入团日期" prop="joiningTime">
              <el-date-picker
                v-model="activatorForm.joiningTime"
                type="date"
                placeholder="选择日期"
                value-format="YYYY-MM-DD"
              ></el-date-picker>
            </el-form-item>
            <el-form-item label="入团学校" prop="joiningSchool">
              <el-input
                v-model="activatorForm.joiningSchool"
                style="width: 220px"
              ></el-input>
            </el-form-item>
            <el-form-item label="家庭住址" prop="homeAddress">
              <el-input
                v-model="activatorForm.homeAddress"
                style="width: 460px"
              ></el-input>
            </el-form-item>
            <el-form-item label="提交入党申请书时间" prop="subTime">
              <el-date-picker
                v-model="activatorForm.subTime"
                clearable
                type="date"
                placeholder="选择日期"
                value-format="YYYY-MM-DD"
              ></el-date-picker>
            </el-form-item>
            <el-form-item label="入党申请书公示时间:" prop="pubTime">
              <el-col>
                <el-date-picker
                  type="daterange"
                  placeholder="选择日期"
                  range-separator="至"
                  start-placeholder="开始时间"
                  end-placeholder="结束时间"
                  v-model="activatorForm.pubTime"
                  value-format="YYYY-MM-DD"
                  style="width: 100%"
                />
              </el-col>
            </el-form-item>
          </el-col>
          <el-col :span="8">
            <el-form-item label="确定积极分子时间" prop="detTime">
              <el-date-picker
                v-model="activatorForm.detTime"
                clearable
                type="date"
                placeholder="选择日期"
                value-format="YYYY-MM-DD"
              ></el-date-picker>
            </el-form-item>
            <el-form-item label="审议时间" prop="delTime">
              <el-date-picker
                v-model="activatorForm.delTime"
                clearable
                type="date"
                placeholder="选择日期"
                value-format="YYYY-MM-DD"
              ></el-date-picker>
            </el-form-item>
            <el-form-item label="上级党委备案时间" prop="filTime">
              <el-date-picker
                v-model="activatorForm.filTime"
                clearable
                type="date"
                placeholder="选择日期"
                value-format="YYYY-MM-DD"
              ></el-date-picker>
            </el-form-item>
            <el-form-item label="入党培养人" prop="culPeople">
              <el-input
                v-model="activatorForm.culPeople"
                style="width: 220px"
              ></el-input>
            </el-form-item>
            <el-form-item label="党课培训情况:" prop="condition">
              <el-select v-model="activatorForm.condition" placeholder="请选择">
                <el-option label="优秀" value="优秀" />
                <el-option label="不合格" value="不合格" />
              </el-select>
            </el-form-item>
            <el-form-item label="参加培训时间" prop="traTime">
              <el-date-picker
                v-model="activatorForm.traTime"
                clearable
                type="date"
                placeholder="选择日期"
                value-format="YYYY-MM-DD"
              ></el-date-picker>
            </el-form-item>
            <el-form-item label="结业时间" prop="comTime">
              <el-date-picker
                v-model="activatorForm.comTime"
                clearable
                type="date"
                placeholder="选择日期"
                value-format="YYYY-MM-DD"
              ></el-date-picker>
            </el-form-item>
            <el-form-item label="党课考试是否合格:" prop="qua">
              <el-select v-model="activatorForm.qua" placeholder="请选择">
                <el-option label="合格" value="合格" />
                <el-option label="不合格" value="不合格" />
              </el-select>
            </el-form-item>
          </el-col>
        </el-row>
        <div style="text-align: center">
          <el-button @click="dialogVisible = false">取消</el-button>
          <el-button type="primary" @click="saveStuInfo">提交</el-button>
        </div>
      </el-form>
    </el-dialog>

    <!-- 身份证和手机号对话框显示 -->
    <el-dialog v-model="dialogDisplayVisible" title="二级密码验证">
      <el-form-item label="请输入二级密码">
        <el-input type="password" show-password v-model="displayPassword" />
      </el-form-item>
      <template #footer>
        <span class="dialog-footer">
          <el-button @click="dialogDisplayVisible = false">取消</el-button>
          <el-button type="primary" @click="displayData"> 验证 </el-button>
        </span>
      </template>
    </el-dialog>
    <!-- excel对话框显示 -->
    <el-dialog v-model="dialogExcelVisible" title="二级密码验证">
      <el-form-item label="请输入二级密码">
        <el-input type="password" show-password v-model="displayPassword" />
      </el-form-item>
      <template #footer>
        <span class="dialog-footer">
          <el-button @click="dialogExcelVisible = false">取消</el-button>
          <el-button type="primary" @click="outExcelCheck"> 验证 </el-button>
        </span>
      </template>
    </el-dialog>
    <!-- 分页 -->
    <el-pagination
      v-model:current-page="params.pagenum"
      v-model:page-size="params.pagesize"
      :page-sizes="[10, 15, 20]"
      :background="true"
      layout="total, sizes, prev, pager, next"
      :total="total"
      @size-change="onSizeChange"
      @current-change="onCurrentChange"
      style="margin-top: 25px; justify-content: flex-end"
    />
  </page-container>
</template>

<style lang="scss" scoped>
:deep(.el-card__body) {
  padding-top: 0;
}
</style>
