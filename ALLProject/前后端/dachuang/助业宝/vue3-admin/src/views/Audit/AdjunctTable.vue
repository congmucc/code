<!-- 兼职表格组件 -->
<template>
	<div>
		<el-table :data="data" style="width: 100%">
			<!-- 表格列配置 -->
			<el-table-column prop="index" label="序号"></el-table-column>
			<el-table-column prop="name" label="兼职名称"></el-table-column>
			<el-table-column prop="phone" label="兼职电话"></el-table-column>
			<el-table-column prop="time" label="兼职时间"></el-table-column>
			<el-table-column prop="place" label="兼职地点"></el-table-column>
			<el-table-column prop="content" label="兼职内容"></el-table-column>
			<el-table-column prop="salary" label="薪资待遇"></el-table-column>
			<el-table-column label="操作">
				<template #default="{ row }">
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
import { defineComponent, ref } from 'vue'
import { useRouter } from 'vue-router'
interface TableItem {
	name: string
	index: number
	contact: string
	time: string
	location: string
	theme: string
	money: string
}

export default defineComponent({
	props: {
		data: {
			type: Array as () => TableItem[],
			required: true
		}
	},
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
				path: '/Audit/Adjunct/AdjunctLook',
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
