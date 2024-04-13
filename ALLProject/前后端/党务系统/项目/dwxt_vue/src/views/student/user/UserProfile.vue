<script setup>
import { useUserStore } from '@/stores'
import { ref } from 'vue'
import { studentUpdateInfoService } from '../../../api/user'
import { ElMessage } from 'element-plus' // 添加这行导入
const {
  user: { username, name, email, id },
  getStudent
} = useUserStore()

const userInfo = ref({ username, name, email, id })
const rules = {
  email: [
    { required: true, message: '请输入邮箱', trigger: 'blur' },
    {
      pattern: /^[a-zA-Z0-9._-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,4}$/,
      message: '您填写的内容不符合邮箱规范',
      trigger: 'blur'
    }
  ]
}
const formRef = ref()
const onSubmit = async () => {
  const valid = await formRef.value.validate()
  if (valid) {
    await studentUpdateInfoService(userInfo.value)
    await getStudent()
    ElMessage.success('修改成功')
  }
}
</script>

<template>
  <page-container title="基本资料">
    <el-row>
      <el-col :span="12">
        <el-form
          :model="userInfo"
          :rules="rules"
          ref="formRef"
          label-width="100px"
          size="large"
        >
          <el-form-item label="账号">
            <el-input v-model="userInfo.username" disabled></el-input>
          </el-form-item>
          <el-form-item label="姓名">
            <el-input v-model="userInfo.name" disabled></el-input>
          </el-form-item>
          <el-form-item label="邮箱" prop="email">
            <el-input v-model="userInfo.email"></el-input>
          </el-form-item>
          <el-form-item>
            <el-button type="primary" @click="onSubmit">提交修改</el-button>
          </el-form-item>
        </el-form>
      </el-col>
    </el-row>
  </page-container>
</template>
