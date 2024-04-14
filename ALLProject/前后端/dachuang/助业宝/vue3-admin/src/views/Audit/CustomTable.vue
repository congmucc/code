<!-- 机构表格 -->
<template>
	<div>
		<el-table :data="data" style="width: 100%" v-for="item in data" :key="item.ID">
			<!-- 表格列配置 -->
			<el-table-column prop="index" label="序号"></el-table-column>
			<el-table-column prop="contact" label="申办方联系方式"></el-table-column>
			<el-table-column prop="time" label="活动时间"></el-table-column>
			<el-table-column prop="location" label="活动地点"></el-table-column>
			<el-table-column prop="theme" label="活动主题"></el-table-column>
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
			:total="data.length" />
	</div>
</template>

<script lang="ts">
// import { I } from '@vueuse/motion/dist/nuxt-b4cb9b59';
import { defineComponent, ref } from 'vue'
import { useRouter, useRoute } from 'vue-router'

const router = useRouter()
const route = useRoute()

interface TableItem {
	name: string
	time: string
	place: string
	content: string
	number: string
	goods: string
	state: string
	ID: number
}

export default defineComponent({
	props: {
		data: {
			type: Array as () => TableItem[],
			required: true
		}
	},
	// methods: {
	//   viewActivityDetail(status) {
	//     // 触发一个自定义事件，将活动ID和状态作为参数传递出去
	//     this.$emit('view', {status});
	//   }
	// },
	setup(props) {
		const router = useRouter()
		const pageSize = ref(10)
		const currentPage = ref(1)
		const currentPageData = ref<TableItem[]>([])

		const handleSizeChange = (val: number) => {
			pageSize.value = val
			currentPage.value = 1
		}

		const handleCurrentChange = (val: number) => {
			currentPage.value = val
		}

		function viewProof(row) {
			console.log('router传参值： ', router)
			console.log('row的值：', row)
			router.push({
				path: '/ActivityManage/Rejected/RejectLook',
				query: {
					id: 10
				}
			})
		}

		currentPageData.value = props.data.slice(
			(currentPage.value - 1) * pageSize.value,
			currentPage.value * pageSize.value
		)

		return {
			pageSize,
			currentPage,
			currentPageData,
			handleSizeChange,
			handleCurrentChange,
			viewProof
		}
	}
})
</script>
