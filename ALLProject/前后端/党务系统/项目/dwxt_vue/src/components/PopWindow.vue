<script setup>
import { ref } from 'vue'
import { personAddAccountService, checkUsernameExists } from '@/api/person.js'
import { ImportExcel } from '@/api/user.js'
import { ElMessage } from 'element-plus'
import * as XLSX from 'xlsx'
const tableName = ref('模板')
const createExcel = () => {
  const excelData = [
    ['学号', '姓名'],
    ['0123456789', '张三'],
    ['0123456798', '李四']
    // 可以添加更多的行数据
  ]
  const ws = XLSX.utils.aoa_to_sheet(excelData)
  const headerStyle = {
    font: { name: 'Arial', sz: 12, bold: false },
    alignment: { vertical: 'left' }
  }
  XLSX.utils.format_cell(ws[('A1', 'B1')], headerStyle)
  const wb = XLSX.utils.book_new()
  XLSX.utils.book_append_sheet(wb, ws, 'Sheet1')

  // 将工作簿转换为Blob对象
  const blob = new Blob(
    [s2ab(XLSX.write(wb, { bookType: 'xlsx', type: 'binary' }))],
    {
      type: 'application/vnd.openxmlformats-officedocument.spreadsheetml.sheet'
    }
  )

  // 创建一个虚拟链接并点击以下载
  const url = URL.createObjectURL(blob)
  const a = document.createElement('a')
  a.href = url
  a.download = `${tableName.value}.xlsx`
  a.click()

  // 释放虚拟链接
  URL.revokeObjectURL(url)
}

// 字符串转ArrayBuffer函数
const s2ab = (s) => {
  const buf = new ArrayBuffer(s.length)
  const view = new Uint8Array(buf)
  for (let i = 0; i !== s.length; ++i) view[i] = s.charCodeAt(i) & 0xff
  return buf
}
const dialogVisible = ref(false)
const formRef = ref()
const formModel = ref({
  name: '',
  username: ''
})

const rules = {
  name: [
    { required: true, message: '请输入用户名', trigger: 'blur' },
    { pattern: /^\S{2,5}$/, message: '名字为2-5位非空字符', trigger: 'blur' }
  ],
  username: [
    { required: true, message: '请输入学号', trigger: 'blur' },
    { pattern: /^[0-9]{10}$/, message: '学号为10位数字', trigger: 'blur' },
    {
      validator: async (rule, value, callback) => {
        //console.log('value ' + value)
        if (!value) {
          callback()
          return
        }
        const exists = await checkUsernameExists(value)
        if (exists.data.data) {
          callback(new Error('学号已存在'))
        } else {
          callback()
        }
      },
      trigger: 'blur'
    }
  ]
}

const open = (row) => {
  console.log(row)
  dialogVisible.value = true
}
defineExpose({
  open
})

const add = defineEmits(['success'])
const onSubmit = async () => {
  await formRef.value.validate()
  await personAddAccountService(formModel.value)
  ElMessage.success('添加成功')
  dialogVisible.value = false
  add('success')
}
const submitUpload = async () => {
  const uploadInput = document.querySelector('.el-upload__input')
  if (uploadInput.files.length > 0) {
    const file = uploadInput.files[0]
    const formData = new FormData()
    formData.append('file', file)
    try {
      await ImportExcel(formData)
      ElMessage.success('导入成功')
      dialogVisible.value = false
      add('success')
    } catch (error) {
      ElMessage.error('导入失败')
    }
  } else {
    ElMessage.error('请选择文件')
  }
}

const handleClose = (done) => {
  formModel.value = {}
  done()
}
</script>

<template>
  <el-dialog
    v-model="dialogVisible"
    title="新增人员"
    width="30%"
    :before-close="handleClose"
  >
    <el-form
      ref="formRef"
      :model="formModel"
      label-width="100px"
      :rules="rules"
      style="padding-right: 50px"
    >
      <el-form-item label="学号:" prop="username">
        <el-input
          v-model="formModel.username"
          placeholder="请输入学号"
        ></el-input>
      </el-form-item>
      <el-form-item label="姓名:" prop="name">
        <el-input v-model="formModel.name" placeholder="请输入姓名"></el-input>
      </el-form-item>
    </el-form>
    <div style="text-align: center">
      <div>
        <!-- <el-button @click="dialogVisible = false">取消</el-button> -->
        <el-button type="primary" @click="onSubmit"> 确认 </el-button>
      </div>
    </div>
    <el-divider />
    <el-upload
      :limit="1"
      :auto-upload="false"
      accept=".xlsx, .xls"
      style="width: 100%"
    >
      <div style="width: 100%">
        <el-text tag="b" size="large">文件批量增加人员</el-text>
        <br />
        <el-text type="danger" size="small"
          >注意:只能上传.xlsx和.xls文件,学号为第一列,姓名为第二列</el-text
        >
        <br />
        <div style="margin-top: 20px; width: 100%; text-align: center">
          <el-button>上传文件</el-button>
        </div>
      </div>
    </el-upload>
    <div style="text-align: center">
      <el-button @click="createExcel">下载模板</el-button>
      <el-button type="primary" @click="submitUpload"> 确定上传 </el-button>
    </div>
  </el-dialog>
</template>

<style lang="scss" scoped>
::v-deep .el-upload {
  display: initial;
}
</style>
