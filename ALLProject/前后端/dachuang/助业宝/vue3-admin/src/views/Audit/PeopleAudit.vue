<!-- 身份审核 -->
<template>
  <el-cascader :options="options" :show-all-levels="false" @change="handleCascaderChange" />

  <!-- 动态切换表格 -->
  <div :class="selectedValue === 'firm' ? 'Table' : 'newTable'">
    <!-- 根据selectedValue显示对应表格的内容 -->
    <!-- 如果是公司，则显示常规表格内容 -->
    <!-- 如果是个人，则显示新的表格样式内容 -->
  </div>

  <div class="Table" v-if="selectedValue === 'firm'">
    <el-table :data="firmData" stripe style="width: 100%">
      <el-table-column prop="username" label="机构账号" width="150" />
      <el-table-column prop="name" label="机构名称" width="170" />
      <el-table-column prop="email" label="邮箱"  />
      <!-- <el-table-column prop="address" label="地址" width="150" /> -->
      <el-table-column label="资质证明">
        <template #default="{ row }">
          <el-button type="" @click="firmProof(row)">查看证明</el-button> 
        </template>
      </el-table-column>
      <el-table-column label="操作">
        <template #default="{ row }">
          <el-button type="primary" @click="handleAction(row)" size="small">通过</el-button>
          <el-button type="danger" @click="handleReject(row)" size="small">驳回</el-button>
        </template>
      </el-table-column>
    </el-table>
  </div>

  <div class="newTable" v-else>
    <el-table :data="individualData" stripe style="width: 100%">
      <el-table-column prop="username" label="学号" width="100" />
      <el-table-column prop="name" label="姓名" width="100" />
      <el-table-column prop="phone" label="联系方式" width="150" />
      <el-table-column prop="university" label="学校名称"/>
      <el-table-column prop="college" label="学院"  />
      <el-table-column prop="major" label="专业" />
      <el-table-column label="资质证明">
        <template #default="{ row }">
          <el-button type="" @click="viewProof(row)">查看证明</el-button> 
        </template>
      </el-table-column>
      <el-table-column label="操作">
        <template #default="{ row }">
          <el-button type="primary" @click="handleAction(row)" size="small">通过</el-button>
          <el-button type="danger" @click="handleReject(row)" size="small">驳回</el-button>
        </template>
      </el-table-column>
    </el-table>
  </div>
  <el-pagination
    :page-sizes="[5, 10, 15, 20]"
    :page-size="pageSize"
    :total="individualData.length"
  />
</template>

<script lang="ts" setup>
import { ref } from 'vue';
import { useRouter , useRoute} from 'vue-router';
import { getStudent } from '../../api/zyb/administration';
import { getInstitution } from '../../api/zyb/administration';

const router = useRouter();
const route = useRoute();

const params = ref({
  newType:''
})

const studentInit = async () => {
  individualData.value = []
  const res = await getStudent(params.value)
  // @ts-ignore
  console.log('身份审核个人接受的数据： ', res.data)
  // @ts-ignore
  individualData.value = res.data
  console.log('individualData: ', individualData.value)
}

const newParams = ref({
  type:''
})
const institutionInit = async () => {
  firmData.value = []
  const res = await getInstitution(newParams.value)  
  // @ts-ignore
  console.log('身份审核公司接受的数据： ', res.data)
  // @ts-ignore
  firmData.value = res.data
  console.log('firmData: ', firmData.value)
}


function viewProof(row) {
  console.log('router传参值： ', router);
  console.log('row的值：', row)
  router.push({
    name:'身份查看',
    path: '/Audit/PeopleAudit/auditLook',
    query: {
      username: row.username
    }
  })
}

function firmProof(row) {
  console.log('router传参值： ', router);
  console.log('row的值：', row)
  router.push({
    name:'机构查看',
    path: '/Audit/Institution/InstitutionLook',
    query: {
      id: 10
    }
  })
}




const options = [
  {
    value: 'individual',
    label: '个人',
    children: [
      {
        value: '1',
        label: '志愿者',
      },
      {
        value: '2',
        label: '普通学生',
      },
      {
        value: '3',
        label: '专业人才',
      },
    ],
  },
  {
    value: 'firm',
    label: '公司',
    children: [
      {
        value: '1',
        label: '大众公司',

      },
      {
        value: '2',
        label: '政府机构',

      },
      {
        value: '3',
        label: '兼职机构',
      },
      {
        value: '4',
        label: '其他机构',
      }
    ],
  }
];

// const filteredData =[]

const individualData = ref([]);
const firmData = ref([]);
const pageSize = ref(5);
const selectedType = ref('');

const selectedValue = ref(''); // 存储选中的value

async function handleCascaderChange(value) {
  if (value.length === 2) {
    selectedValue.value = value[0]; // 获取顶级类别，这里是 'firm' 或 'individual'
    if (selectedValue.value === 'individual') {
      params.value.newType = value[1];
      await studentInit();
      
    } else if (selectedValue.value === 'firm') {
      //调用公司
      newParams.value.type = value[1];
      await institutionInit(); // 如果需要传入二级选项值
      
    }
  } else {
    selectedValue.value = '';
  }
}



function handleReject(row) {
  console.log('row的值：', row)
}
function handleAction(row) {
  console.log('row的值：', row)
}
</script>



<style lang="scss">
// 表格样式
.Table {
  position: relative;
  top: 40px;
}
.newTable{
  position: relative;
  top: 40px;
}

.el-button--primary {
  background-color: #409EFF; // 蓝色
  border-color: #409EFF;
}

.el-button--danger {
  background-color: #F56C6C; // 红色
  border-color: #F56C6C;
}

.el-button--mini {
  font-size: 12px; // 缩小按钮大小
}

// 分页条样式
.el-pagination {
  // margin-top: 15px; /* 设置分页条与表格之间的间距 */
  position: absolute;
  bottom: 20px; /* 控制分页条相对于父元素的位置，根据实际情况调整 */
  width: 80%;
  right: 1;
  z-index: 1; /* 确保分页条位于表格上方，避免被遮挡 */
}
</style>
