<!-- 人员管理 -->
<template>
	<div class="header">
		<div class="search">
			<el-cascader :options="options" :show-all-levels="false" @change="handleCascaderChange" />
		</div>

		<div class="switch-button">
			<el-button @click="switchToAdminPage">切换管理员</el-button>
		</div>
	</div>

	<!-- 动态切换表格 -->
	<div :class="selectedValue === 'firm' ? 'Table' : 'newTable'">
		<!-- 根据selectedValue显示对应表格的内容 -->
		<!-- 如果是公司，则显示常规表格内容 -->
		<!-- 如果是个人，则显示新的表格样式内容 -->
	</div>

	<div class="Table" v-if="selectedValue === 'firm'">
		<el-table :data="firmData" stripe style="width: 100%">
			<el-table-column prop="name" label="机构名称" width="150" />
			<el-table-column prop="username" label="账号" width="150" />
			<el-table-column prop="password" label="密码" width="150" />
			<el-table-column prop="email" label="邮箱" width="150" />
			<el-table-column label="状态" width="150">
				<template #default="scope">
					<span v-if="scope.row.blacklist === 0">正常</span>
					<span v-else>黑名单</span>
				</template>
			</el-table-column>
			<!-- <el-table-column prop="address" label="地址"  /> -->
			<!-- <el-table-column label="资质证明">
        <template #default="{ row }">
          <el-button @click="viewProof(row)">查看证明</el-button>
        </template>
      </el-table-column> 你先看这一个页面 你看啊 -->
			<el-table-column label="操作">
				<template #default="{ row }">
					<!-- <el-button type="primary" @click="deleteFirm(row)" size="small">删除</el-button>
          <el-button type="danger" @click="handleReject(row)" size="small">禁用</el-button>
          <el-button type="success" @click="handleApprove(row)" size="small">启用</el-button> -->
					<el-row :gutter="16">
						<el-col :span="5">
							<el-button type="danger" @click="deleteFirm(row)" size="small">删除</el-button>
						</el-col>
						<el-col :span="5">
							<el-button type="primary" @click="handleReject(row)" size="small">禁用</el-button>
						</el-col>
						<el-col :span="5">
							<el-button type="success" @click="handleApprove(row)" size="small">启用</el-button>
						</el-col>
					</el-row>
				</template>
			</el-table-column>
		</el-table>
	</div>

	<div class="newTable" v-else>
		<el-table :data="individualData" stripe style="width: 100%">
			<el-table-column prop="username" label="学号" width="100" />
			<el-table-column prop="name" label="姓名" width="100" />
			<el-table-column prop="phone" label="联系方式" width="150" />
			<el-table-column prop="university" label="学校名称" />
			<el-table-column prop="college" label="学院" />
			<el-table-column prop="major" label="专业" />
			<el-table-column prop="profess" label="状态" width="90">
				<template #default="{ row }">
					<span v-if="row.profess === '0'">正常</span>
					<span v-else>黑名单</span>
				</template>
			</el-table-column>
			<!-- <el-table-column label="资质证明">
        <template #default="{ row }">
          <el-button type="" @click="viewProof(row)">查看证明</el-button>
        </template>
      </el-table-column> -->
			<el-table-column label="操作">
				<template #default="{ row }">
					<!-- <el-button type="primary" @click="deletePeople(row)" size="small">删除</el-button>
          <el-button type="danger" @click="peopleReject(row)" size="small">禁用</el-button>
          <el-button type="success" @click="peopleApprove(row)" size="small">启用</el-button> -->
					<el-row :gutter="20">
						<el-col :span="8">
							<el-button type="danger" @click="deletePeople(row)" size="small">删除</el-button>
						</el-col>
						<el-col :span="8">
							<el-button type="primary" @click="peopleReject(row)" size="small">禁用</el-button>
						</el-col>
						<el-col :span="8">
							<el-button type="success" @click="peopleApprove(row)" size="small">启用</el-button>
						</el-col>
					</el-row>
				</template>
			</el-table-column>
		</el-table>
	</div>
	<el-pagination
		:page-sizes="[5, 10, 15, 20]"
		:page-size="pageSize"
		:total="individualData.length" />
</template>

<script lang="ts" setup>
import { ref } from 'vue'
import { useRouter } from 'vue-router'
import { getStudent } from '../../api/zyb/administration'
import { getInstitution } from '../../api/zyb/administration'
import { deleteStu } from '@/api/zyb/administration'
import { deleteInst } from '@/api/zyb/administration'
import { ElMessageBox } from 'element-plus'
import { message } from '@/utils/message'
import { updateInst } from '@/api/zyb/administration'
import { updateStu } from '@/api/zyb/administration'
import { ApproveInst } from '@/api/zyb/administration'
import { ApproveStu } from '@/api/zyb/administration'
const router = useRouter()

const params = ref({
	newType: ''
})

// inti中的代码放入选择中，不过可以封装一下
const studentInit = async () => {
	individualData.value = []
	const res = await getStudent(params.value)
	// @ts-ignore
	console.log('人员管理个人接受的数据： ', res.data)
	// @ts-ignore
	individualData.value = res.data
	console.log('individualData: ', individualData.value)
}

const newParams = ref({
	type: ''
})
const institutionInit = async () => {
	firmData.value = []
	const res = await getInstitution(newParams.value)
	// @ts-ignore
	console.log('人员管理公司接受的数据： ', res.data)
	// @ts-ignore
	firmData.value = res.data
	console.log('firmData: ', firmData.value)
}

const options = [
	{
		value: 'individual',
		label: '个人',
		children: [
			{
				value: '1',
				label: '志愿者'
			},
			{
				value: '2',
				label: '普通学生'
			},
			{
				value: '3',
				label: '专业人才'
			}
		]
	},
	{
		value: 'firm',
		label: '公司',
		children: [
			{
				value: '1',
				label: '大众公司'
			},
			{
				value: '2',
				label: '政府机构'
			},
			{
				value: '3',
				label: '兼职机构'
			},
			{
				value: '4',
				label: '其他机构'
			}
		]
	}
]

const individualData = ref([])
const firmData = ref([])
const pageSize = ref(5)

// 已有的变量和方法...
const selectedValue = ref('') // 存储选中的value

async function handleCascaderChange(value) {
	if (value.length === 2) {
		selectedValue.value = value[0] // 获取顶级类别，这里是 'firm' 或 'individual'
		if (selectedValue.value === 'individual') {
			params.value.newType = value[1]
			await studentInit()
		} else if (selectedValue.value === 'firm') {
			//调用公司
			newParams.value.type = value[1]
			await institutionInit() // 如果需要传入二级选项值
		}
	} else {
		selectedValue.value = ''
	}
}

function switchToAdminPage(row) {
	console.log('router传参值： ', router)
	console.log('row的值：', row)
	router.push({
		path: '/Audit/PeopleManage/Manager',
		query: {
			id: 10
		}
	})
}

function handleReject(row) {
	console.log('row的值：', row)
	if (row.blacklist === 0) {
		ElMessageBox.confirm('是否要禁用此机构?', '提示', {
			confirmButtonText: '是',
			cancelButtonText: '否',
			type: 'warning'
		}).then(async () => {
			// 直接使用item.username作为参数
			await updateInst(row.id)
			firmData.value.splice(firmData.value.indexOf(row), 1, { ...row, blacklist: 1 })
			message('禁用成功', { type: 'success' })
		})
	}
}

function handleApprove(row) {
	console.log('row的值：', row)
	if (row.blacklist === 1) {
		ElMessageBox.confirm('是否要启用此机构?', '提示', {
			confirmButtonText: '是',
			cancelButtonText: '否',
			type: 'warning'
		}).then(async () => {
			// 直接使用item.username作为参数
			await ApproveInst(row.id)
			firmData.value.splice(firmData.value.indexOf(row), 1, { ...row, blacklist: 0 })
			message('启用成功', { type: 'success' })
		})
	}
}

function peopleReject(row) {
	console.log('row的值：', row)
	if (row.profess === '0') {
		ElMessageBox.confirm('是否要禁用此人?', '提示', {
			confirmButtonText: '是',
			cancelButtonText: '否',
			type: 'warning'
		}).then(async () => {
			// 直接使用item.username作为参数
			await updateStu(row.username)

			// 更新本地数据状态
			// row.profess = '1';
			individualData.value.splice(individualData.value.indexOf(row), 1, { ...row, profess: 1 })
			message('禁用成功', { type: 'success' })
		})
	}
}

function peopleApprove(row) {
	if (row.profess === '1') {
		ElMessageBox.confirm('是否要启用此人?', '提示', {
			confirmButtonText: '是',
			cancelButtonText: '否',
			type: 'warning'
		}).then(async () => {
			// 直接使用item.username作为参数
			await ApproveStu(row.username)

			// 更新本地数据状态
			individualData.value.splice(individualData.value.indexOf(row), 1, { ...row, profess: '0' })
			message('启用成功', { type: 'success' })
		})
	}
}
interface Activity {
	id: number
	username: string
	name: string
	phone: string
	university: string
	college: string
	major: string
	blacklist: number
}
// 给你两个选择，一是写两个删除，两个禁用，二是通过判断options的value来判断他是个人还是公司，然后再进行删除鹤禁用
async function deleteFirm(item: Activity) {
	ElMessageBox.confirm('是否要删除此机构?', '提示', {
		confirmButtonText: '是',
		cancelButtonText: '否',
		type: 'warning'
	}).then(async () => {
		// 直接使用item.username作为参数
		await deleteInst(item.id)

		const index = firmData.value.findIndex((i) => i.id === item.id)
		if (index !== -1) {
			firmData.value.splice(index, 1)
		}
		message('删除成功', { type: 'success' })
		// 刷新或重新加载数据（根据实际需求）
		// handleSelect(activeIndex.value);
	})
}
async function deletePeople(item: Activity) {
	ElMessageBox.confirm('是否要删除此人?', '提示', {
		confirmButtonText: '是',
		cancelButtonText: '否',
		type: 'warning'
	}).then(async () => {
		// 直接使用item.username作为参数
		await deleteStu(item.username)

		const index = individualData.value.findIndex((i) => i.username === item.username)
		if (index !== -1) {
			individualData.value.splice(index, 1)
		}
		message('删除成功', { type: 'success' })
	})
}
</script>

<style lang="scss">
// 表格样式
.Table {
	position: relative;
	top: 40px;
}
.newTable {
	position: relative;
	top: 40px;
}
.el-button--primary {
	background-color: #409eff; // 蓝色
	border-color: #409eff;
}

.el-button--danger {
	background-color: #f56c6c; // 红色
	border-color: #f56c6c;
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
// 切换
.header {
	display: flex;
	justify-content: space-between;
}

.search {
	flex: 1;
	margin-right: 10px;
}

.switch-button {
	margin-left: 10px;
}
</style>
