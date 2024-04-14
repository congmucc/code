<!-- 个人身份审核查看 -->
<template>
  <div>
    <h2>个人简历</h2>
    <el-table :data="personalInfoData" style="width: 100%">
      <el-table-column label="项目" prop="item"></el-table-column>
      <el-table-column label="详情" prop="detail"></el-table-column>
      
    </el-table>
  </div>
</template>

<script setup lang="ts">
import { ref } from 'vue';
import { useRouter , useRoute} from 'vue-router';

const router = useRouter();
const route = useRoute();


const init = () => {
  console.log('route接受值：', route)
  
}

init()
const personalInfoData = ref([
  { item: '姓名', detail: '张三' },
  { item: '电话号码', detail: '123456789' },
  { item: '学校名称', detail: '河南开封科技传媒学院' },
  { item: '年级专业', detail: '2021级软件工程' },
  { item: '证件照', detail: '<img src="certificate.jpg" alt="Certificate Photo" style="width: 80px; height: 80px;" rowspan="2">' },
]);
</script>

<style>
/* 在这里添加 Element Plus 的样式，可以根据需要自定义样式 */
</style>
