<!-- 活动内容查看 -->
<template>
	<div class="activity">
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
				<el-menu-item index="0" data-name="info">兼职信息</el-menu-item>
				<el-menu-item index="1" data-name="content">兼职内容</el-menu-item>
				<el-menu-item index="2" data-name="requirements">兼职内容</el-menu-item>
				<!-- <el-menu-item index="3" data-name="cause">驳回原因</el-menu-item> -->
			</el-menu>
		</div>

		<el-card class="activity-section" header="兼职信息" id="infoCard">
			<div class="activity-info" v-if="activity">
				<!-- <h2>{{ activity.name }}</h2> -->
				<p>兼职时间: {{ activity.time }}</p>
				<p>兼职地点: {{ activity.place }}</p>
				<p>兼职电话: {{ activity.phone }}</p>
				<p>兼职待遇: {{ activity.salary }}</p>
				<!-- 其他活动信息内容 -->
			</div>
		</el-card>

		<el-card class="activity-section" header="兼职内容" id="contentCard">
			<div class="activity-content">
				<p>{{ activity.name }}</p>
			</div>
		</el-card>

		<el-card class="activity-section" header="兼职需求" id="requirementsCard">
			<div class="activity-requirements">
				<p>{{ activity.demand }}</p>
			</div>
		</el-card>

		<!-- <el-card class="activity-section" header="驳回原因" id="causeCard">
			<div class="activity-cause">
				<p>
					由于活动的内容和需求比较笼统， 无法让同学们根据内容进行更好的判断，存在迷惑学生的风险
					综合考虑予以驳回处理。
				</p>
			</div>
		</el-card> -->

		<div class="buttons">
			<el-button type="primary" @click="approve">
				{{ activity.state === '2' ? '申诉' : '修改' }}
			</el-button>
		</div>
	</div>
</template>

<script setup>
import { ref, onMounted } from 'vue'
import { getJobById } from '@/api/zyb/institution'
import { useRoute, useRouter } from 'vue-router'

const route = useRoute()
const router = useRouter()
const activityId = route.query.id
const activeIndex2 = ref('1')

const init = async () => {
	const res = await getJobById(activityId)
	activity.value = res.data
	console.log('job:', activity.value)
}

const activity = ref({})

// 当组件挂载时加载数据
onMounted(async () => {
	if (activityId) {
		await init()
	}
})
const handleSelect = (index) => {
	if (index === '0') {
		scrollToSection('infoCard')
	} else if (index === '1') {
		scrollToSection('contentCard')
	} else if (index === '2') {
		scrollToSection('requirementsCard')
	} else if (index === '3') {
		scrollToSection('causeCard')
	}
}

const scrollToSection = (sectionId) => {
	const section = document.getElementById(sectionId)
	section.scrollIntoView({ behavior: 'smooth' })
}

const approve = () => {
	// 处理通过按钮点击事件
	router.push({ path: '/institution/job/submit', query: { id: activity.value.id } })
}
</script>

<style scoped>
.activity {
	margin: 20px;
}

.activity-section {
	margin-bottom: 10px;
}

.buttons {
	text-align: right;
	margin-top: 20px;
}
</style>
