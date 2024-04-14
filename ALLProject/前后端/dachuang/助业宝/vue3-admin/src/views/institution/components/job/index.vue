<script setup lang="ts">
import { ref } from 'vue'
import { ElCard, ElMessageBox } from 'element-plus'
import { useRouter } from 'vue-router'
import type { Job } from '@/../types/institution/Institution'
import { getJobList, deleteJob } from '@/api/zyb/institution'
import { ElMessage } from 'element-plus'
import { useRenderIcon } from '@/components/ReIcon/src/hooks'
import closebold from '@iconify-icons/ep/close-bold'
import { message } from '@/utils/message'

const router = useRouter()

/**
 * 初始化
 */
// 示例：生成一些测试数据（数组形式）
const jobList = ref<Job[]>([])

const params = ref({ institutionId: 0, state: '0', page: 1, pageSize: 10 })

const total = ref({
	total: 0,
	flag: false
})

const init = async () => {
	const res = await getJobList(params.value)
	// @ts-ignore
	total.value.total = res.data.total
	// 处理数据，移除institutionId字段
	// @ts-ignore
	const currentItem = res.data.rows.map((job) => ({
		id: job.id,
		name: job.name,
		time: job.time,
		content: job.content,
		place: job.place,
		demand: job.demand,
		phone: job.phone,
		salary: job.salary,
		state: job.state
	}))
	console.log('currentItem', currentItem)

	jobList.value.push(...currentItem)
}

init()

/**
 * 选择展示活动
 */
const activeIndex = ref('0')
const handleSelect = (key: string) => {
	if (key === '1') {
		//发送请求、 要求
		params.value.state = '1'
	} else if (key === '2') {
		params.value.state = '2'
	} else if (key === '3') {
		params.value.state = '3'
	} else {
		params.value.state = '0'
		activeIndex.value = '0'
	}
	jobList.value = []
	total.value.flag = false
	total.value.total = 0
	params.value.page = 1
	init()
}
const contentDetail = (item: Job) => {
	console.log('item: ', item.id)
	router.push({ path: '/institution/job/details', query: { id: item.id } })
}

/**
 * 获取状态文字
 * @param state
 */
function getStateText(state) {
	switch (state) {
		case '1':
			return '审核中'
		case '2':
			return '驳回'
		case '3':
			return '申请成功'
		// 添加其他状态分支...
		default:
			return '未知状态'
	}
}

/**
 * 滑动到底部之后进行更新数据
 */
const load = () => {
	if (total.value.flag || jobList.value.length === 0) return
	console.log('jobList.value.length', jobList.value.length, 'total.value.total', total.value.total)
	if (jobList.value.length < total.value.total) {
		params.value.page++
		init()
	} else {
		total.value.flag = true
		ElMessage({
			showClose: true,
			message: '数据已经全部加载了',
			type: 'success'
		})
	}
}

const deleteArticle = async (item: Job) => {
	ElMessageBox.confirm('是否要删除兼职?', '提示', {
		confirmButtonText: '是',
		cancelButtonText: '否',
		type: 'warning'
	}).then(async () => {
		await deleteJob(item.id)

		message('删除成功', { type: 'success' })

		// 刷新列表
		handleSelect(activeIndex.value)
	})
}
</script>

<template>
	<!-- 切换状态 -->
	<el-menu
		:default-active="activeIndex"
		class="el-menu-demo"
		mode="horizontal"
		@select="handleSelect">
		<el-menu-item index="0">全部兼职</el-menu-item>
		<el-menu-item index="1">审核</el-menu-item>
		<el-menu-item index="2">驳回</el-menu-item>
		<el-menu-item index="3">申请成功</el-menu-item>
	</el-menu>
	<el-empty description="内容为空，或者网络有问题" v-show="jobList.length === 0" />
	<div class="custom-card-father" v-infinite-scroll="load" :infinite-scroll-distance="30">
		<!-- 使用ElCard展示单篇文章 -->
		<ElCard
			class="custom-card"
			v-for="(item, index) in jobList"
			:key="index"
			@click="contentDetail(item)">
			<p class="card-state">
				·{{ getStateText(item.state) }}
				<span class="card-state-radius"></span>
			</p>
			<h2 class="card-name">{{ item.name }}</h2>
			<el-button
				class="card-delete"
				@click.stop="deleteArticle(item)"
				:icon="useRenderIcon(closebold)" />
			<el-scrollbar class="card-content">
				<div>{{ item.content }}</div>
			</el-scrollbar>
			<p class="card-text">
				<!-- <span>时间：</span> -->
				<span class="card-text-span">{{ item.time }}</span>
				<!-- <span>地点：</span> -->
				<span class="card-text-span">{{ item.place }}</span>
			</p>
		</ElCard>
	</div>
</template>

<style scoped>
/** 卡片的父元素样式 */
.custom-card-father {
	display: flex;
	flex-wrap: wrap;
	/* justify-content: flex-start; */
	/* height: 80vh; */
}

/* 卡片的样式 */
.custom-card {
	margin: 3px;
	display: flex;
	border-radius: 5px;
	position: relative;
	min-height: 400px;
	max-height: 40vh;
}

/* 媒体查询：小屏幕下每行显示1个卡片 */
@media (max-width: 768px) {
	.custom-card {
		width: calc(100% - 6px); /* 每行只显示1个卡片 */
	}
}

/* 媒体查询：中屏幕下每行显示2个卡片 */
@media (min-width: 769px) and (max-width: 1200px) {
	.custom-card {
		width: calc(50% - 6px); /* 每行显示2个卡片 */
	}
}

/* 媒体查询：大屏幕下每行显示3个卡片 */
@media (min-width: 1201px) and (max-width: 1920px) {
	.custom-card {
		width: calc(33.33% - 6px); /* 每行显示3个卡片 */
	}
}

/* 媒体查询：超大屏幕下每行显示4个卡片 */
@media (min-width: 1921px) {
	.custom-card {
		width: calc(25% - 6px); /* 每行显示4个卡片 */
	}
}

/* 卡片鼠标停留样式 */
.custom-card:hover {
	box-shadow: 0 4px 8px #aaa;
	cursor: pointer;
}

/** 卡片状态样式 */
.card-state {
	position: absolute;
	top: 3px;
	left: 3px;
	margin: 0;
	color: rgb(134, 215, 184);
	display: inline-block;
	border: 1px solid rgb(173, 141, 204);
	border-radius: 130px;
}

/**卡片小圆点 */
.card-state-radius {
	display: inline-block;
	border-radius: 100%;
	background-color: rgb(222, 109, 151);
	width: 10px;
	height: 10px;
	margin-right: 2px;
}

/** 标题样式 */
.card-name {
	margin-top: 8px;
	white-space: nowrap;
	overflow: hidden;
	text-overflow: ellipsis;
	max-width: 23vw;
}

/** 活动删除 */
.card-delete {
	position: absolute;
	top: 3px;
	right: 3px;
	margin: 0;
	padding: 0.5em;
	line-height: 1;
}

/** 卡片属性样式 */
.card-text-span {
	color: #928e8e;
	font-size: 10px;
	white-space: nowrap;
	overflow: hidden;
	text-overflow: ellipsis;
}

/**卡片属性变量样式 */
.card-text {
	position: absolute;
	display: flex;
	justify-content: space-between;
	width: 90%;
	top: 93%;
}

.card-content {
	max-height: 84%;
}

/* 卡片内容样式 */
.card-content-div {
	color: rgb(85, 85, 86);
	/* height: 300px; */
	height: 70%;
	font-size: 14px;
}
</style>
