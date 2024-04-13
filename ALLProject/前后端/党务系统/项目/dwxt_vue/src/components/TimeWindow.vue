<script setup>
import { ref } from 'vue'
import {
  userUpdateStatus,
  updateTeacherTime,
  startCronTask,
  stopCronTask,
  getUserTime
} from '../api/person'
const dialogVisible = ref(false)

const value1 = ref({})
let changeTime = {}
const defaultTime1 = new Date(2000, 1, 1, 0, 0, 0) // '00:00:00'
const  open = async () => {
  dialogVisible.value = true
  const res = await getUserTime()
  value1.value.date = res.data.data.date.split(',')

}

defineExpose({
  open
})
const add = defineEmits(['success'])
const onReject = async () => {
  await userUpdateStatus(0, '')
  await stopCronTask()
  ElMessage.success('权限已关闭')
  dialogVisible.value = false
  add('success')
}


const onSubmit = async () => {
  changeTime.date = value1.value.date.toString()
  changeTime.id = 1
  await updateTeacherTime(changeTime)
  await startCronTask()
  ElMessage.success('修改成功')
  dialogVisible.value = false
  add('success')
}

const handleClose = (done) => {
  done()
}
</script>

<template>
  <el-dialog
    v-model="dialogVisible"
    title="选择可登录时间"
    width="30%"
    :before-close="handleClose"
  >
    <div class="block">
      <el-date-picker
        v-model="value1.date"
        type="datetimerange"
        start-placeholder="开始时间"
        end-placeholder="结束时间"
        :default-time="defaultTime1"
        value-format="YYYY-MM-DD HH:mm:ss"
      />
    </div>
    <div style="text-align: center; margin-top: 60px">
      <el-button @click="onSubmit"> 开启权限 </el-button>
      <el-button type="info" @click="onReject"> 关闭权限 </el-button>
    </div>
  </el-dialog>
</template>

<style scoped>
.block {
  text-align: center;
}
</style>
