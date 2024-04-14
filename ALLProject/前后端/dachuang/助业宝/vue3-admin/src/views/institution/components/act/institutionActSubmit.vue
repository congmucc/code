<script setup lang="ts">
import { reactive, ref } from 'vue'
import { useRoute, useRouter } from 'vue-router'
import type { FormInstance, FormRules } from 'element-plus'
import { ElMessage, ElMessageBox } from 'element-plus'
import { getActById, updateAct } from '@/api/zyb/institution'
import type { Activity } from '@/../types/institution/Institution'

const route = useRoute()
const router = useRouter()

// 或者更安全地进行非空判断
const init = async () => {
	if (route.query.id != undefined) {
		const res = await getActById(route.query.id as string)
		Object.assign(activities, res.data)
		activities.time = activities.time.split(',')
	}
}

init()

const ruleForm = ref<FormInstance>()

// 创建一个Activity类型的变量并初始化测试数据
const activities = reactive<Activity>({
	id: 0,
	name: '',
	time: null,
	content: '',
	place: '',
	goods: '',
	number: null,
	group: '',
	state: null
})

const formRules = reactive<FormRules<Activity>>({
	name: [{ required: true, message: '请输入活动名称', trigger: 'blur' }],
	time: [{ required: true, message: '请输入活动时间', trigger: 'blur' }],
	content: [{ required: true, message: '请输入活动内容', trigger: 'blur' }],
	place: [{ required: true, message: '请输入活动场地', trigger: 'blur' }],
	goods: [{ required: true, message: '请输入活动物资', trigger: 'blur' }],
	number: [{ required: true, message: '请输入人员需求', trigger: 'blur' }],
	group: [{ required: true, message: '请输入活动类型', trigger: 'blur' }]
})

const submit = async (formEl: FormInstance | undefined) => {
	if (!formEl) return
	await formEl.validate((valid, fields) => {
		if (valid) {
			ElMessageBox.confirm('是否要提交活动?', '提示', {
				confirmButtonText: '是',
				cancelButtonText: '否',
				type: 'warning'
			}).then(() => {
				let time = activities.time
				activities.time = activities.time.join(',')
				const res = updateAct(activities)
				console.log('res的值： ', res)
				activities.time = time[0] + ',' + time[1]
				console.log('act表单的值： ', activities)
				ElMessage({
					type: 'success',
					message: '提交成功'
				})
				activities.time = time
			})
		} else {
			console.log('error submit!', fields)
		}
	})
}
</script>

<template>
	<div class="container">
		<el-form ref="ruleForm" :rules="formRules" :model="activities" class="activity-ruleForm">
			<el-form-item label="活动名称" prop="name">
				<el-input v-model="activities.name" placeholder="请输入活动名称" />
			</el-form-item>
			<el-form-item style="font-weight: bold" label="活动时间" prop="time">
				<el-date-picker
					v-model="activities.time"
					type="daterange"
					format="YYYY-MM-DD"
					value-format="YYYY-MM-DD"
					range-separator="To"
					start-placeholder="开始时间"
					end-placeholder="结束时间" />
			</el-form-item>
			<el-form-item label="活动内容" prop="content">
				<el-input
					v-model="activities.content"
					placeholder="请输入活动内容"
					type="textarea"
					:autosize="{ minRows: 4, maxRows: 8 }" />
			</el-form-item>
			<el-form-item label="活动场地" prop="place">
				<el-input v-model="activities.place" placeholder="请输入活动场地" />
			</el-form-item>
			<el-form-item label="活动物资" prop="goods">
				<el-input v-model="activities.goods" placeholder="请输入活动物资" />
			</el-form-item>
			<el-form-item label="人员需求" prop="number">
				<el-input v-model="activities.number" placeholder="请输入人员需求人数" type="number" />
			</el-form-item>
			<el-form-item label="人员类型" prop="group">
				<el-select v-model="activities.group" placeholder="请选择您需要的人员类型">
					<el-option label="只需要志愿者" value="0" />
					<el-option label="只需要专业人才" value="1" />
					<el-option label="都需要" value="2" />
				</el-select>
			</el-form-item>
			<el-form-item>
				<el-button class="btn-cancel" @click="router.go(-1)">返回</el-button>
				<el-button type="primary" @click="submit(ruleForm)">提交</el-button>
			</el-form-item>
		</el-form>
	</div>
</template>

<style lang="scss" scoped>
.container {
	display: flex;
	justify-content: center;
	align-items: center;
}

.activity-ruleForm {
	width: 600px;
}

.btn-cancel {
	margin-left: 30%;
	margin-right: 15%;
}
</style>
