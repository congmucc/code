<script setup>
import { ref } from 'vue'
import { Search } from '@element-plus/icons-vue'
import {
  personGetAccountService,
  personDelAccountService,
  personPutAccountService
} from '../../../api/person'
import PopWindow from '../../../components/PopWindow.vue'

const accountList = ref([]) //账号列表
const total = ref(0)
const loading = ref(false)
const dialog = ref()
//请求对象
const params = ref({
  pagenum: 1,
  pagesize: 10,
  username: ''
})

const getAccountList = async () => {
  loading.value = true
  const res = await personGetAccountService(params.value)
  accountList.value = res.data.data.rows
  res.data.data.rows.forEach((element) => {
    element.password =
      element.password.charAt(0) +
      '*'.repeat(element.password.length - 2) +
      element.password.charAt(element.password.length - 1)
    if (element.status) {
      element.status = '允许'
    } else {
      element.status = '禁止'
    }
  })
  total.value = res.data.data.total
  loading.value = false
}
getAccountList()

//搜索与重置
const onSearch = () => {
  params.value.pagenum = 1
  params.value.username = input.value
  getAccountList()
}

const onReset = () => {
  params.value.pagenum = 1
  params.value.username = ''
  input.value = ''
  getAccountList()
}

//密码重置
const onResetAccount = async (row) => {
  await ElMessageBox.confirm('是否要重置', '注意', {
    type: 'warning',
    confirmButtonText: '确认',
    cancelButtonText: '取消'
  })
  await personPutAccountService(row.id)
  ElMessage.success('重置成功')
  getAccountList()
}
//删除
const delBtnStatus = ref(true)
const multipleSelection = ref([])
const selectedIds = ref([])
const selectChange = (selection) => {
  multipleSelection.value = selection
  delBtnStatus.value = selection.length == 0
}
const onDeleteAccount = async (row) => {
  await ElMessageBox.confirm('是否要删除', '注意', {
    type: 'warning',
    confirmButtonText: '确认',
    cancelButtonText: '取消'
  })
  if (row) {
    selectedIds.value.push(row.username)
  } else {
    selectedIds.value = multipleSelection.value.map((row) => row.username)
  }
  console.log('selectedIds.value' + selectedIds.value)

  await personDelAccountService(selectedIds.value)
  selectedIds.value = []
  ElMessage.success('删除成功')
  getAccountList()
}

const input = ref('')
//处理分页
const onSizeChange = (size) => {
  //console.log('当前页条数', size)
  params.value.pagenum = 1
  params.value.pagesize = size
  getAccountList()
}
const onCurrentChange = (page) => {
  //console.log('页码变化', page)
  params.value.pagenum = page
  getAccountList()
}

import TimeWindow from '../../../components/TimeWindow.vue'
const dialog2 = ref()

// 修改时间段
const onChangeTime = () => {
  dialog2.value.open()
  // dialogVisible.value = true
}

//添加人员
const onAddAccount = (row) => {
  dialog.value.open(row)
  //getAccountList()
}
const onSuccess = () => {
  getAccountList()
}
</script>

<template>
  <page-container title="人员账号管理">
    <template #extra>
      <!-- 修改 -->
      <el-button @click="onChangeTime">权限管理</el-button>
      <el-button @click="onAddAccount">人员添加</el-button>
      <el-button
        type="danger"
        :disabled="delBtnStatus"
        @click="onDeleteAccount(row)"
        >批量删除</el-button
      >
    </template>
    <el-form inline>
      <el-form-item label="学号:">
        <el-input
          :prefix-icon="Search"
          v-model="input"
          placeholder="请输入学号"
        ></el-input>
      </el-form-item>
      <el-form-item>
        <el-button @click="onSearch" type="primary">搜索</el-button>
        <el-button @click="onReset">重置</el-button>
      </el-form-item>
    </el-form>
    <el-table
      :data="accountList"
      style="width: 100%"
      v-loading="loading"
      height="528"
      @selection-change="selectChange"
    >
      <el-table-column type="selection" width="55"></el-table-column>
      <el-table-column label="序号" prop="id" width="100"></el-table-column>
      <el-table-column label="学号" prop="username"></el-table-column>
      <el-table-column label="姓名" prop="name"></el-table-column>
      <!-- <el-table-column label="密码" prop="password"></el-table-column> -->
      <el-table-column label="登录权限" prop="status"></el-table-column>
      <el-table-column label="操作" width="200">
        <template #default="{ row }">
          <el-button @click="onResetAccount(row)">重置</el-button>
          <el-button type="danger" @click="onDeleteAccount(row)"
            >删除</el-button
          >
        </template>
      </el-table-column>
      <template #empty>
        <el-empty description="空" :image-size="200"></el-empty>
      </template>
    </el-table>
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
    <TimeWindow ref="dialog2" @success="onSuccess"></TimeWindow>
    <PopWindow ref="dialog" @success="onSuccess"></PopWindow>
  </page-container>
</template>

<style lang="scss" scoped>
.el-card_body {
  padding-top: 0;
}
.block {
  text-align: center;
}
</style>
