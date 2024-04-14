<script setup lang="ts">
import { reactive, ref } from 'vue'
import { useRoute, useRouter } from 'vue-router'
import type { FormInstance, FormRules } from 'element-plus'
import { ElMessage, ElMessageBox } from 'element-plus'
import { getJobById, updateJob } from '@/api/zyb/institution'
import type { Job } from '@/../types/institution/Institution'

const route = useRoute()
const router = useRouter()

// 初始化
const init = async () => {
	if (route.query.id != undefined) {
		const res = await getJobById(route.query.id as string)
		Object.assign(job, res.data)
		job.time = job.time.split(',')
		console.log('最开始的： ', job)
	}
}
init()

const ruleForm = ref<FormInstance>()

// 创建一个Activity类型的变量并初始化测试数据
const job = reactive<Job>({
	id: 0,
	name: '',
	time: null,
	content: '',
	place: '',
	demand: '',
	phone: null,
	salary: '',
	state: null
})

const formRules = reactive<FormRules<Job>>({
	id: [{ required: true, message: '请输入ID', trigger: 'blur' }],
	name: [{ required: true, message: '请输入职位名称', trigger: 'blur' }],
	time: [{ required: true, message: '请输入兼职时间', trigger: 'blur' }],
	content: [{ required: true, message: '请输入兼职内容', trigger: 'blur' }],
	place: [{ required: true, message: '请输入兼职地点', trigger: 'blur' }],
	demand: [{ required: true, message: '请输入兼职要求', trigger: 'blur' }],
	phone: [{ required: true, message: '请输入联系电话', trigger: 'blur' }],
	salary: [{ required: true, message: '请输入兼职薪资', trigger: 'blur' }],
	state: [{ required: true, message: '请输入申请状态', trigger: 'blur' }]
})

const submit = async (formEl: FormInstance | undefined) => {
	if (!formEl) return
	await formEl.validate(async (valid, fields) => {
		if (valid) {
			ElMessageBox.confirm('是否要提交兼职?', '提示', {
				confirmButtonText: '是',
				cancelButtonText: '否',
				type: 'warning'
			}).then(async () => {
				let time = job.time
				job.time = job.time.join(',')
				const res = await updateJob(job)
				console.log('res的值： ', res)
				job.time = time[0] + ',' + time[1]
				console.log('job表单的值： ', job)
				ElMessage({
					type: 'success',
					message: '提交成功'
				})
				job.time = time
			})
		} else {
			console.log('error submit!', fields)
		}
	})
}
</script>

<template>
	<div class="container">
		<el-form ref="ruleForm" :rules="formRules" :model="job" class="activity-ruleForm">
			<el-form-item label="兼职名称" prop="name">
				<el-input v-model="job.name" placeholder="请输入兼职名称" />
			</el-form-item>
			<el-form-item style="font-weight: bold" label="兼职时间" prop="time">
				<el-date-picker
					v-model="job.time"
					type="daterange"
					format="YYYY-MM-DD"
					value-format="YYYY-MM-DD"
					range-separator="To"
					start-placeholder="开始时间"
					end-placeholder="结束时间" />
			</el-form-item>
			<el-form-item label="兼职内容" prop="content">
				<el-input
					v-model="job.content"
					placeholder="请输入兼职内容"
					type="textarea"
					:autosize="{ minRows: 4, maxRows: 8 }" />
			</el-form-item>
			<el-form-item label="兼职场地" prop="place">
				<el-input v-model="job.place" placeholder="请输入兼职场地" />
			</el-form-item>
			<el-form-item label="兼职要求" prop="demand">
				<el-input
					v-model="job.demand"
					type="textarea"
					:autosize="{ minRows: 4, maxRows: 8 }"
					placeholder="请输入兼职要求" />
			</el-form-item>
			<el-form-item label="联系电话" prop="phone">
				<el-input v-model="job.phone" placeholder="请输入联系电话" />
			</el-form-item>
			<el-form-item label="兼职薪资" prop="salary">
				<el-input v-model="job.salary" placeholder="请输入兼职薪资" />
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
