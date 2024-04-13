<script setup>
import zhCn from 'element-plus/dist/locale/zh-cn.mjs'
// import { onMounted } from 'vue'
// import { useUserStore } from '@/stores'

// const userStore = useUserStore()

// onMounted(() => {
//   userStore.removeToken()
// })
</script>
<template>
  <div>
    <!-- 路由出口  -->
    <el-config-provider :locale="zhCn">
      <router-view></router-view>
    </el-config-provider>
  </div>
</template>

<style scoped></style>
