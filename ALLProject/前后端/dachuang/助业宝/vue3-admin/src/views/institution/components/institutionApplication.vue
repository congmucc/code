<script setup lang="ts">
import { reactive, ref } from 'vue'
import { useRouter } from 'vue-router'
import type { FormInstance, FormRules, UploadProps, UploadUserFile } from 'element-plus'
import { ElMessage, ElMessageBox } from 'element-plus'
import { updateInstitutionInfo, getInstitutionInfo } from '@/api/zyb/institution'
import { getUserInfo } from '@/utils/auth'

const router = useRouter()
const init = async () => {
	const res = await getInstitutionInfo(JSON.parse(getUserInfo()).id)
	Object.assign(institution, res.data)

	// 修改机构类型
	if (institution.type === '1') {
		institution.type = '政府机构'
	} else if (institution.type === '2') {
		institution.type = '大众公司'
	} else {
		institution.type = '其他机构'
	}

	// @ts-ignore
	const imgs: string[] = res.data.certify.split(',')
	console.log('imgs的值： ', imgs)
	// @ts-ignore
	if (imgs.length >= 1 && imgs[0].url !== '')
		imgs.forEach((ele) => {
			fileList.value.push({
				name: ele,
				url: ele
			})
		})

	// console.log('institution的值： ', institution)
	// console.log('fileList的值： ', fileList)
}

init()
// 定义活动数据模型
interface Institution {
	id: number // 主键非空
	name: string // 机构名称
	email: string // 邮箱
	type: string // 机构类型
}

const ruleForm = ref<FormInstance>()

// 创建一个Institution类型的变量并初始化测试数据
const institution = reactive<Institution>({
	id: null,
	name: '',
	email: '',
	type: ''
})

const formRules = reactive<FormRules<Institution>>({})

const submit = async (formEl: FormInstance | undefined) => {
	if (!formEl) return
	await formEl.validate((valid, fields) => {
		if (valid) {
			ElMessageBox.confirm('是否要提交申请?', '提示', {
				confirmButtonText: '是',
				cancelButtonText: '否',
				type: 'warning'
			}).then(async () => {
				const formData = new FormData()

				console.log('fileList', fileList.value)

				fileList.value.forEach((ele) => {
					if (ele.status === 'ready') formData.append('files', ele.raw)
				})

				console.log('deleteFiles: ', deleteFiles.value)

				deleteFiles.value.forEach((ele) => {
					formData.append('deleteFiles', ele.url)
				})

				formData.append('id', institution.id.toString())
				formData.append('name', institution.name)
				formData.append('email', institution.email)
				formData.append('type', institution.type)

				// 检查是否存在 'files' 键，如果不存在则添加一个空值
				formData.get('files') ||
					formData.append('files', new File([], 'zhuyebao_empty', { type: 'text/plain' }))

				// 检查是否存在 'deleteFiles' 键，如果不存在则添加一个空值
				formData.get('deleteFiles') || formData.append('deleteFiles', '')

				await updateInstitutionInfo(formData)
				ElMessage({
					type: 'success',
					message: '提交成功'
				})
			})
		} else {
			console.log('error submit!', fields)
		}
	})
}

/**
 * 预览图片
 */
const dialogImageUrl = ref('')
const dialogVisible = ref(false)
/**
 * 上传图片
 */
const fileList = ref<UploadUserFile[]>([])

// 删除图片记录
const deleteFiles = ref<UploadUserFile[]>([])

/**
 * 预览图片
 */
const handlePictureCardPreview: UploadProps['onPreview'] = (uploadFile) => {
	console.log('fileList: ', fileList.value)
	dialogImageUrl.value = uploadFile.url!
	dialogVisible.value = true
}

/**
 * 达到限制之后进行提醒,可以添加,加个逻辑就行
 */
const handleExceed: UploadProps['onExceed'] = () => {
	ElMessage.warning('当前限制上传5张图片')
}

/**
 * 删除图片时的钩子
 */
const handleRemove: UploadProps['onRemove'] = (file, uploadFiles) => {
	console.log(file, uploadFiles)
	if (file.status === 'success') deleteFiles.value.push(file)
	// console.log('fileList: ', fileList.value)
}
</script>

<template>
	<div class="container">
		<el-form
			ref="ruleForm"
			:rules="formRules"
			label-position="top"
			:model="institution"
			class="activity-ruleForm">
			<el-form-item label="机构名称" prop="name">
				<el-input v-model="institution.name" placeholder="请输入机构名称" />
			</el-form-item>
			<el-form-item label="邮箱地址" prop="email">
				<el-input v-model="institution.email" placeholder="请输入联系邮箱" />
			</el-form-item>
			<el-form-item label="机构类型" prop="type">
				<el-select v-model="institution.type" placeholder="请选择您的机构类型">
					<el-option label="政府机构" value="政府机构" />
					<el-option label="大众公司" value="大众公司" />
					<el-option label="其他机构" value="其他机构" />
				</el-select>
			</el-form-item>
			<el-upload
				class="avatar-uploader"
				upload=""
				v-model:file-list="fileList"
				:show-file-list="true"
				list-type="picture-card"
				:on-preview="handlePictureCardPreview"
				:auto-upload="false"
				:on-exceed="handleExceed"
				:on-remove="handleRemove"
				:limit="5">
				+
			</el-upload>
			<el-form-item>
				<el-button class="btn-cancel" @click="router.go(-1)">返回</el-button>
				<el-button type="primary" @click="submit(ruleForm)">提交</el-button>
			</el-form-item>
		</el-form>

		<el-dialog v-model="dialogVisible">
			<img w-full :src="dialogImageUrl" alt="Preview Image" />
		</el-dialog>
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
