<script setup lang="ts">
import { reactive, ref } from 'vue'
import type { UploadProps, UploadUserFile } from 'element-plus'
import { ElMessage, ElMessageBox } from 'element-plus'
import { getInstitutionInfo, updateInsitutionPartInfo, updateAuthen } from '@/api/zyb/institution'
import { getUserInfo } from '@/utils/auth'
import arrowRight from '@iconify-icons/ep/arrow-right'
import { useRenderIcon } from '@/components/ReIcon/src/hooks'

import { getToken, formatToken } from '@/utils/auth'

const init = async () => {
	const res = await getInstitutionInfo(JSON.parse(getUserInfo()).id)
	Object.assign(institution, res.data)

	// 修改机构类型
	if (institution.type === '1') {
		institution.type = '政府机构'
	} else if (institution.type === '2') {
		institution.type = '大众公司'
	} else if (institution.type === '3') {
		institution.type = '其他机构'
	}


	// @ts-ignore
	let imgs: string[] = res.data.certify.split(',')
  console.log('imgs的值： ', imgs)
  if (imgs[0] === '') imgs = []
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
	certify: string // 认证材料
}

// 创建一个Institution类型的变量并初始化测试数据
const institution = reactive<Institution>({
	id: null,
	name: '',
	email: '',
	type: '',
	certify: ''
})

const submit = () => {
	ElMessageBox.confirm('是否要提交申请?', '提示', {
		confirmButtonText: '是',
		cancelButtonText: '否',
		type: 'warning'
	}).then(async () => {
		institution.certify = fileList.value.map((ele) => ele.url).join(',')
		const res = await updateAuthen(institution)
		console.log('修改res: ', res)
		ElMessage({
			type: 'success',
			message: '提交成功'
		})
		dialogVisible2.value = false
	})
}

/**
 * 预览图片
 */
const dialogImageUrl = ref('')
const dialogVisible = ref(false)
const dialogVisible2 = ref(false)
const dialogVisible3 = ref(false)

const changeEdit = ref<string>('')
const tempKey = ref<string>('')

/** 点击修改按钮 */
const handleEditBtn = (it: string) => {
	tempKey.value = it
	if (it === 'name') changeEdit.value = institution.name
	else if (it === 'email') changeEdit.value = institution.email
	dialogVisible3.value = true
}
/** 点击修改信息 */
const handleEdit = async () => {
	if (tempKey.value === 'name') institution.name = changeEdit.value
	else if (tempKey.value === 'email') institution.email = changeEdit.value
	// todo 发送信息修改

	institution.certify = fileList.value.map((ele) => ele.url).join(',')
	const res = await updateInsitutionPartInfo(institution)
	if (res.code === 0) {
		ElMessage({
			type: 'success',
			message: res.data as string
		})
	} else {
		ElMessage({
			type: 'success',
			message: '出现错误'
		})
	}
	dialogVisible3.value = false
}

/** 点击取消 */
const cancelExit = () => {
	fileList.value = []
	institution.type = ''
	dialogVisible2.value = false
}

/** 上传图片成功回调 */
const handleSuccess = (res: any) => {
	console.log('上传成功回调： ', res)
	const lastIndex = fileList.value.length - 1
	fileList.value[lastIndex] = {
		name: res.data,
		url: res.data
	}
	console.log('fileList: ', fileList.value)
}

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
		<el-space direction="vertical" :fill="true" :size="50" class="activity-ruleForm">
			<el-row>
				<el-col :span="7">机构名称：</el-col>
				<el-col :span="9">
					<el-text v-if="institution.name">{{ institution.name }}</el-text>
					<el-text v-else>空</el-text>
				</el-col>
				<el-col :span="5">
					<el-button @click="handleEditBtn('name')">修改</el-button>
				</el-col>
			</el-row>
			<el-row>
				<el-col :span="7">邮箱地址：</el-col>
				<el-col :span="9">
					<el-text v-if="institution.email">{{ institution.email }}</el-text>
					<el-text v-else>空</el-text>
				</el-col>
				<el-col :span="5">
					<el-button @click="handleEditBtn('email')">修改</el-button>
				</el-col>
			</el-row>
			<el-row v-if="institution.type === ''">
				<el-col :span="7">机构类型：</el-col>
				<el-col :span="12">
					<el-link @click="dialogVisible2 = true">
						申请认证
						<component :is="useRenderIcon(arrowRight)" />
					</el-link>
				</el-col>
			</el-row>
			<el-row v-else>
				<el-col :span="7">机构类型：</el-col>
				<el-col :span="9">{{ institution.type }}</el-col>
				<el-col :span="5">
					<el-link @click="ElMessage.warning('当前暂不支持修改认证')">
						修改认证
						<component :is="useRenderIcon(arrowRight)" />
					</el-link>
				</el-col>
			</el-row>
		</el-space>

		<el-dialog v-model="dialogVisible2" title="请填写认证信息" width="500">
			<el-form :model="institution">
				<el-form-item label="机构类型" prop="type">
					<el-select v-model="institution.type" placeholder="请选择您的机构类型">
						<el-option label="政府机构" value="政府机构" />
						<el-option label="大众公司" value="大众公司" />
						<el-option label="其他机构" value="其他机构" />
					</el-select>
				</el-form-item>
				<el-upload
					class="avatar-uploader"
					action="
http://localhost:8090/zyb/institution/upload"
					:headers="{
						Authorization: formatToken(getToken().accessToken)
					}"
					v-model:file-list="fileList"
					:show-file-list="true"
					:on-success="handleSuccess"
					list-type="picture-card"
					:on-preview="handlePictureCardPreview"
					:on-exceed="handleExceed"
					:on-remove="handleRemove"
					:limit="5">
					+
				</el-upload>
			</el-form>
			<template #footer>
				<div class="dialog-footer">
					<el-button @click="cancelExit">取消</el-button>
					<el-button type="primary" @click="submit">提交</el-button>
				</div>
			</template>
		</el-dialog>

		<el-dialog v-model="dialogVisible3" width="500">
			<el-form-item>
				<el-input v-model="changeEdit" :autosize="{ minRows: 2, maxRows: 4 }" type="textarea" />
			</el-form-item>
			<template #footer>
				<div class="dialog-footer">
					<el-button @click="dialogVisible3 = false">取消</el-button>
					<el-button type="primary" @click="handleEdit">提交</el-button>
				</div>
			</template>
		</el-dialog>

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
