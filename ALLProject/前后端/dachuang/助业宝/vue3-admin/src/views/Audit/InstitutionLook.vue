<!-- 政府证明的查看 -->
<template>
  <div>
    <h1 style="text-align: center; font-size: 24px;">某某人民政府</h1>
    
    <el-divider style="border-color: brown;border-width: 2px;"></el-divider>
    <el-divider style="border-color: brown;border-width: 2px;"></el-divider>

    <h2 style="font-size: 20px;">实习证明</h2>
    
    <div style="margin-top: 20px;">
      <p>根据《某某人民政府实习证明》的有关规定，特此出具实习证明：</p>
      <div class="content">
        <p>本人**，性别**，身份证号码**，于**至**在我局实习，实习期间表现优秀，工作认真负责，遵守纪律，与同事相处融洽。</p>
      <p>特此证明。</p>
      </div>
      
      <div class="foot">
             <p style="margin-top: 20px;">某某人民政府</p>
      <p>日期：年 月 日</p>
      </div>
 
    </div>
  </div>
</template>

<script>
// 在这里添加相关的逻辑代码，如需要的话
import { useRouter , useRoute} from 'vue-router';

const router = useRouter();
const route = useRoute();


const init = () => {
  console.log('route接受值：',route)
}
</script>

<style>
/* 在这里添加需要的样式，如需自定义样式 */
h1{
  color: brown;
  
}

h2{
            text-align: center;
        }
.content{
  margin-top: 20px;
  margin-left:30px;
}

.foot{
  text-align: right;
}
</style>
