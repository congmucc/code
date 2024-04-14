<!-- 机构活动审核 -->
<template>
	<div>
		<!-- 菜单 -->
		<el-menu
			:default-active="activeIndex2"
			class="el-menu-demo"
			mode="horizontal"
			background-color="#fff"
			text-color="#000000"
			active-text-color="#36a0ff"
			@select="handleSelect">
			<el-menu-item index="0">全部活动</el-menu-item>
			<el-menu-item index="1">待审核</el-menu-item>
			<el-menu-item index="2">已发布</el-menu-item>
			<el-menu-item index="3">已驳回</el-menu-item>
		</el-menu>

		<div v-if="activeIndex === '0'">
			<div>
				<el-table :data="allActivities" style="width: 100%">
					<!-- 表格列配置 -->
					<el-table-column prop="index" label="序号"></el-table-column>
					<!-- <el-table-column prop="email" label="申办方邮箱"></el-table-column> -->
					<el-table-column prop="time" label="活动时间"></el-table-column>
					<el-table-column prop="place" label="活动地点"></el-table-column>
					<el-table-column prop="name" label="活动主题"></el-table-column>
					<el-table-column label="操作">
						<template #default="{ row }">
							<!-- 假设每个活动都有一个唯一的id，用于标识活动详情页 -->
							<!-- <el-button @click="viewActivityDetail( item.ID)">查看</el-button> -->
							<el-button @click="viewProof(row)" type="primary">查看</el-button>
						</template>
					</el-table-column>
				</el-table>

				<el-pagination
					@size-change="handleSizeChange"
					@current-change="handleCurrentChange"
					:current-page="currentPage"
					:page-sizes="[5, 10, 15, 20]"
					:page-size="pageSize"
					layout="total, sizes, prev, pager, next, jumper"
					:total="allActivities.length" />
			</div>
		</div>
		<div v-else-if="activeIndex === '1'">
			<div>
				<el-table :data="allActivities" style="width: 100%">
					<!-- 表格列配置 -->
					<el-table-column prop="index" label="序号"></el-table-column>
					<!-- <el-table-column prop="email" label="申办方邮箱"></el-table-column> -->
					<el-table-column prop="time" label="活动时间"></el-table-column>
					<el-table-column prop="place" label="活动地点"></el-table-column>
					<el-table-column prop="name" label="活动主题"></el-table-column>
					>
					<el-table-column label="操作">
						<template #default="{ row }">
							<!-- 假设每个活动都有一个唯一的id，用于标识活动详情页 -->
							<!-- <el-button @click="viewActivityDetail( item.ID)">查看</el-button> -->
							<el-button @click="viewProof(row)" type="primary">查看</el-button>
						</template>
					</el-table-column>
				</el-table>

				<el-pagination
					@size-change="handleSizeChange"
					@current-change="handleCurrentChange"
					:current-page="currentPage"
					:page-sizes="[5, 10, 15, 20]"
					:page-size="pageSize"
					layout="total, sizes, prev, pager, next, jumper"
					:total="allActivities.length" />
			</div>
		</div>
		<div v-else-if="activeIndex === '2'">
			<div>
				<el-table :data="allActivities" style="width: 100%">
					<!-- 表格列配置 -->
					<el-table-column prop="index" label="序号"></el-table-column>
					<!-- <el-table-column prop="email" label="申办方邮箱"></el-table-column> -->
					<el-table-column prop="time" label="活动时间"></el-table-column>
					<el-table-column prop="place" label="活动地点"></el-table-column>
					<el-table-column prop="name" label="活动主题"></el-table-column>
					<el-table-column label="操作">
						<template #default="{ row }">
							<!-- 假设每个活动都有一个唯一的id，用于标识活动详情页 -->
							<!-- <el-button @click="viewActivityDetail( item.ID)">查看</el-button> -->
							<el-button @click="viewProof(row)" type="primary">查看</el-button>
						</template>
					</el-table-column>
				</el-table>

				<el-pagination
					@size-change="handleSizeChange"
					@current-change="handleCurrentChange"
					:current-page="currentPage"
					:page-sizes="[5, 10, 15, 20]"
					:page-size="pageSize"
					layout="total, sizes, prev, pager, next, jumper"
					:total="allActivities.length" />
			</div>
		</div>
		<div v-else>
			<div>
				<el-table :data="allActivities" style="width: 100%">
					<!-- 表格列配置 -->
					<el-table-column prop="index" label="序号"></el-table-column>
					<!-- <el-table-column prop="email" label="申办方邮箱"></el-table-column> -->
					<el-table-column prop="time" label="活动时间"></el-table-column>
					<el-table-column prop="place" label="活动地点"></el-table-column>
					<el-table-column prop="name" label="活动主题"></el-table-column>
					<el-table-column label="操作">
						<template #default="{ row }">
							<!-- 假设每个活动都有一个唯一的id，用于标识活动详情页 -->
							<!-- <el-button @click="viewActivityDetail( item.ID)">查看</el-button> -->
							<el-button @click="viewProof(row)" type="primary">查看</el-button>
						</template>
					</el-table-column>
				</el-table>

				<el-pagination
					@size-change="handleSizeChange"
					@current-change="handleCurrentChange"
					:current-page="currentPage"
					:page-sizes="[5, 10, 15, 20]"
					:page-size="pageSize"
					layout="total, sizes, prev, pager, next, jumper"
					:total="allActivities.length" />
			</div>
		</div>
	</div>
</template>

<script lang="ts" setup>
import { ref } from 'vue'
import { onMounted } from 'vue'
import { useRouter } from 'vue-router'
import { getActivityList } from '@/api/zyb/institution'

const router = useRouter()
const activeIndex = ref('0')
const activeIndex2 = ref('0')
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
// const params = ref({  state: '', page: 1, pageSize: 10 })
const params = ref({
	state: '',
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
		index: job.id,
		name: job.name,
		time: job.time,
		place: job.place,
		id: job.id
	}))
	allActivities.value = currentItem
}

function viewProof(row) {
	console.log('router传参值： ', router.getRoutes())
	console.log('row的值：', row)
	router.push({
		path: '/ActivityManage/Await/AwaitLook',
		query: {
			id: row.id
		}
	})
}
// 全部活动数据
const allActivities = ref([])
const handleSelect = (key: string, keyPath: string[]) => {
	console.log(key, keyPath)
	activeIndex.value = key
	if (key === '1') {
		///发送请求、 要求
		params.value.state = '1'
	} else if (key === '2') {
		params.value.state = '2'
	} else if (key === '3') {
		params.value.state = '3'
	} else {
		params.value.state = '0'
		activeIndex.value = '0'
	}
	init()
}
</script>
