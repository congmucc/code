<template>
	<div class="info-list">
		<el-menu
			:default-active="activeIndex"
			class="el-menu-demo"
			mode="horizontal"
			@select="handleSelect">
			<el-menu-item index="1">全部</el-menu-item>
			<el-menu-item index="2">已回复</el-menu-item>
			<el-menu-item index="3">未回复</el-menu-item>
		</el-menu>
		<el-card v-for="info in infoList" :key="info.id" class="info-card">
			<div class="info-item">
				<span class="info-label">校园活动：</span>
				<span class="info-value">{{ info.institutionId }}</span>
			</div>
			<div class="info-item">
				<span class="info-label">学号：</span>
				<span class="info-value">{{ info.username }}</span>
			</div>
			<div class="info-item">
				<span class="info-label">记录：</span>
				<span class="info-value">{{ info.content }}</span>
			</div>
			<div class="info-item">
				<span class="info-label">学生反馈：</span>
				<span class="info-value">{{ info.feedbackStu }}</span>
			</div>
			<div class="info-item">
				<span class="info-label">机构反馈：</span>
				<span class="info-value">{{ info.feedbackInstitution || '无' }}</span>
			</div>
			<el-button
				type="primary"
				class="feedback-button"
				v-if="!info.feedbackInstitution"
				@click="addFeedback(info)">
				添加反馈记录
			</el-button>
			<el-button type="success" class="feedback-button" v-else @click="modifyFeedback(info)">
				修改反馈记录
			</el-button>
		</el-card>
		<el-dialog v-model="dialogFormVisible" title="请输入反馈" width="500">
			<el-form-item>
				<el-input
					v-model="info.feedbackInstitution"
					:autosize="{ minRows: 2, maxRows: 4 }"
					type="textarea" />
			</el-form-item>
			<template #footer>
				<div class="dialog-footer">
					<el-button @click="dialogFormVisible = false">取消</el-button>
					<el-button type="primary" @click="dialogChange">提交</el-button>
				</div>
			</template>
		</el-dialog>
	</div>
</template>

<script setup lang="ts">
import { ref } from 'vue'
import { getstuActivityEdList, updateActEndFeeback } from '@/api/zyb/institution'
import type { Feedback } from '@/../types/institution/Institution'
import { ElMessageBox } from 'element-plus'
import { message } from '@/utils/message'
import { getUserInfo } from '@/utils/auth'

const infoList = ref<Feedback[]>([])

const dialogFormVisible = ref(false)

const info = ref<Feedback>({
	id: 0,
	campusId: 0,
	username: '',
	content: '',
	feedbackStu: '',
	feedbackInstitution: '',
	institutionId: 0
})

/**
 * 初始化
 */
const init = async () => {
	infoList.value = []
	const userInfo = JSON.parse(getUserInfo())
	info.value.id = userInfo.id
	const res = await getstuActivityEdList(userInfo.id)
	if (activeIndex.value === '1') {
		// @ts-ignore
		infoList.value = res.data
	} else if (activeIndex.value === '2') {
		// @ts-ignore
		infoList.value = res.data.filter((item) => item.feedbackInstitution)
	} else if (activeIndex.value === '3') {
		// @ts-ignore
		infoList.value = res.data.filter((item) => !item.feedbackInstitution)
	}
}

init()

/**
 * 选择展示活动
 */
const activeIndex = ref('1')
const handleSelect = async (key: string) => {
	if (key === '1') {
		activeIndex.value = '1'
		init()
	} else if (key === '2') {
		activeIndex.value = '2'
		init()
	} else if (key === '3') {
		activeIndex.value = '3'
		init()
	}
}

/**
 * 点击确认
 */
const dialogChange = async () => {
	dialogFormVisible.value = false
	ElMessageBox.confirm('是否要提交?', '提示', {
		confirmButtonText: '是',
		cancelButtonText: '否',
		type: 'warning'
	}).then(async () => {
		const res = await updateActEndFeeback(info.value)
		if (res.code === 0) {
			message(res.data, { type: 'success' })
			init()
		} else {
			message('提交失败', { type: 'error' })
		}
	})
}

/**
 * 点击添加反馈记录
 * @param item
 */
const addFeedback = async (item: Feedback) => {
	dialogFormVisible.value = true
	info.value.id = item.id
	info.value.feedbackInstitution = item.feedbackInstitution
}

/**
 * 点击修改反馈记录
 * @param item
 */
const modifyFeedback = (item: Feedback) => {
	dialogFormVisible.value = true
	info.value.id = item.id
	info.value.feedbackInstitution = item.feedbackInstitution
}
</script>

<style scoped>
.info-list {
	display: flex;
	flex-direction: column;
	gap: 20px;
}

.info-card {
	width: 100%;
	padding: 20px;
	box-shadow: 0 2px 4px rgba(0, 0, 0, 0.1);
	border-radius: 8px;
}

.info-item {
	margin-bottom: 12px;
	display: flex;
	align-items: flex-start; /* 垂直顶部对齐 */
}

.info-label {
	font-weight: bold;
	color: #666;
	min-width: 100px; /* 设置最小宽度 */
	flex: 0 0 auto; /* 不填充剩余空间 */
}

.info-value {
	color: #333;
	flex: 1; /* 填充剩余空间 */
	word-break: break-word; /* 换行处理 */
}

.feedback-button {
	margin-top: 12px;
	align-self: flex-end;
}
</style>
