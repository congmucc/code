<!-- 已通过 -->
<template>
	<div class="pending-approval-page">
		<h1>已驳回</h1>

		<div class="table-container">
			<div class="table-wrapper">
				<el-table :data="tableData" stripe style="width: 100%">
					<el-table-column label="序号" type="index" width="70" />
					<el-table-column prop="name" label="活动名称" width="150" />
					<el-table-column prop="time" label="活动时间" width="150" />
					<el-table-column prop="place" label="活动地点" width="160" />
					<el-table-column prop="content" label="活动主题" />
					<el-table-column label="操作">
						<template #default="{ row }">
							<el-button type="primary" @click="handleView(row)">查看</el-button>
						</template>
					</el-table-column>
				</el-table>
			</div>
			<el-pagination
				@size-change="handleSizeChange"
				@current-change="handleCurrentChange"
				:page-sizes="[5, 10, 15, 20]"
				:page-size="pageSize"
				:total="tableData.length"
				class="pagination-bar" />
		</div>
	</div>
</template>

<script lang="ts" setup>
import { ref } from 'vue'
import { onMounted } from 'vue'
import { useRouter } from 'vue-router'
import { getActivityList } from '@/api/zyb/institution'

const router = useRouter()
// 表格函数
const pageSize = ref(10)
const currentPage = ref(1)

onMounted(() => {
	init()
})
// 在handleSizeChange和handleCurrentChange函数中调用init
const handleSizeChange = (val: number) => {
	pageSize.value = val
	currentPage.value = 1
	init() // 改变每页数量后重新获取数据
}
const handleCurrentChange = (val: number) => {
	currentPage.value = val
	init() // 切换页码后重新获取数据
}

//@param state 状态非空（0全部，1审核中，2驳回，3申请成功）、默认：0
// const params = ref({  state: '', page: 1, pageSize: })
const params = ref({
	state: '2',
	page: currentPage.value,
	pageSize: pageSize.value
})

const init = async () => {
	params.value.page = currentPage.value // 更新请求中的当前页码
	params.value.pageSize = pageSize.value // 更新请求中的每页大小
	const res = await getActivityList(params.value)
	// @ts-ignore
	console.log('机构活动审核接受的数据： ', res.data)
	// @ts-ignore
	const currentItem = res.data.rows.map((job) => ({
		id: job.id,
		name: job.name,
		time: job.time,
		place: job.place,
		content: job.content,
		state: job.state
	}))

	tableData.value = currentItem
}

const tableData = ref([])

function handleView(row) {
	console.log('router传参值： ', router.getRoutes())
	console.log('row的值：', row)
	router.push({
		path: '/ActivityManage/Rejected/RejectLook',
		query: {
			id: row.id
		}
	})
}
</script>

<style>
.pending-approval-page {
	padding: 20px;
}

.table-container {
	position: relative;
}

.table-wrapper {
	max-height: 400px; /* 设置表格容器的最大高度，可以根据实际情况调整 */
	overflow-y: auto; /* 在表格容器高度不够时显示垂直滚动条 */
	position: relative;
}

.pagination-bar {
	position: absolute;
	bottom: -50px; /* 控制分页条与表格容器底部的间距，根据实际情况调整 */
	right: 0;
}
</style>
