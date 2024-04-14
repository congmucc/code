<template>
  <div class="activity-header">
    <div class="switch-button">
      <el-button @click="switchToPeople">切换普通用户</el-button>
    </div>
  </div>
  <div class="activity">
    <div>
      <!-- 菜单 -->
      <el-menu
        :default-active="activeIndex2"
        class="el-menu-demo"
        mode="horizontal"
        background-color="#fff"
        text-color="#000000"
        active-text-color="#36a0ff"
        @select="handleSelect"
      >
        <el-menu-item index="0" data-name="ordinary">管理员</el-menu-item>
        <el-menu-item index="1" data-name="super">超级管理员</el-menu-item>
      </el-menu>
    </div>

    <!-- 管理员表格 -->
    <el-table
      v-if="activeIndex === '0'"
      :data="ordinaryAdminData"
      style="width: 100%"
      stripe
    >
      <el-table-column prop="username" label="账号"></el-table-column>
      <el-table-column prop="password" label="密码"></el-table-column>
      <el-table-column prop="email" label="邮箱"></el-table-column>
      <el-table-column label="操作">
        <template #default="{ row }">
          <el-button @click="handleEdit(row)">修改</el-button>
        </template>
      </el-table-column>
    </el-table>

    <!-- 超级管理员表格 -->
    <el-table
      v-else-if="activeIndex === '1'"
      :data="superAdminData"
      style="width: 100%"
      stripe
    >
      <el-table-column prop="username" label="账号"></el-table-column>
      <el-table-column prop="password" label="密码"></el-table-column>
      <el-table-column prop="email" label="邮箱"></el-table-column>
      <el-table-column label="操作">
        <template #default="{ row }">
          <el-button @click="handleEdit(row)">修改</el-button>
        </template>
      </el-table-column>
    </el-table>
  </div>
  <el-dialog
  title="修改管理员信息"
  v-model="editDialogVisible"
  width="30%"
>
  <el-form :model="editFormData" label-width="80px">
    <el-form-item label="账号" prop="username">
      <el-input v-model="editFormData.username"></el-input>
    </el-form-item>
    <el-form-item label="密码" prop="password">
      <el-input v-model="editFormData.password"></el-input>
    </el-form-item>
    <el-form-item label="邮箱" prop="email">
      <el-input v-model="editFormData.email"></el-input>
    </el-form-item>
    <el-form-item>
      <el-button type="primary" @click="saveChanges">保存修改</el-button>
    </el-form-item>
  </el-form>
</el-dialog>
</template>

<script lang="ts" setup>
import { ref } from 'vue';
import { log } from 'console';
import { useRouter , useRoute} from 'vue-router';
import { getAdministration } from '@/api/zyb/administration';

const router = useRouter();
const route = useRoute();


const init = async() => {
  const res = await getAdministration()
  // @ts-ignore
  console.log('管理员接受的type的数据： ', res.data)
  // @ts-ignore
  // 根据res.data中每个对象的type字段区分管理员类型
  res.data.forEach(item => {
    if (item.id === 1) { // 假设 type 为 1 表示普通管理员
      ordinaryAdminData.value.push(item);
    } else if (item.id === 0) { // 假设 type 为 0 表示超级管理员
      superAdminData.value.push(item);
    }
  });
}
init()


//切换到普通用户
function switchToPeople(row) {
      console.log('router传参值： ', router);
      console.log('row的值：', row)
      router.push({
        path: '/Manage',
        query: {
          id: 10
        }
    })
}

// 管理员表格的数据
const ordinaryAdminData = ref([]);
// 超级管理员表格的数据
const superAdminData = ref([]);

const activeIndex = ref('0');
const activeIndex2 = ref('0');
const handleSelect = (key: string, keyPath: string[]) => {
  console.log(key, keyPath);
  activeIndex.value = key;
};

// 添加以下变量
const editDialogVisible = ref(false);
const editFormData = ref({ email: '', username: '', password: '' });

// 添加以下方法
const handleEdit = (row) => {
  console.log('111');
  
  editFormData.value = { ...row };
  editDialogVisible.value = true;
};

const saveChanges = () => {
  let adminDataToUpdate;
  if (activeIndex.value === '0') {
    adminDataToUpdate = ordinaryAdminData.value;
  } else if (activeIndex.value === '1') {
    adminDataToUpdate = superAdminData.value;
  }

  // 找到要修改的管理员数据，更新数据
  const index = adminDataToUpdate.findIndex(admin => admin.username === editFormData.value.username);
  if (index !== -1) {
    adminDataToUpdate[index] = { ...editFormData.value };
  }

  // 关闭编辑对话框
  editDialogVisible.value = false;
};


</script>

<style scoped>
.activity-header {
  display: flex;
  justify-content: flex-end;
  align-items: center;
  padding-bottom: 20px;
}
</style>

