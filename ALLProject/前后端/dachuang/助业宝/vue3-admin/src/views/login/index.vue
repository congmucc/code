<script lang="ts" setup>
import Motion from './utils/motion'
import { useRouter } from 'vue-router'
import { message } from '@/utils/message'
import { toRaw, reactive, ref } from 'vue'
import type { FormInstance } from 'element-plus'
import { loginRules } from './utils/rule'
import { bg, picture } from './utils/static'
import update from './components/updata.vue'
import { computed } from 'vue'
import { useUserStoreHook } from '@/store/modules/user'
import { useRenderIcon } from '@/components/ReIcon/src/hooks'
import User from '@iconify-icons/ep/user'
import Lock from '@iconify-icons/ep/lock'
import { addRouter } from '@/router'

const router = useRouter()
const loading = ref(false)
const ruleFormRef = ref<FormInstance>()

const currentPage = computed(() => {
	return useUserStoreHook().currentPage
})

const ruleForm = reactive({
	state: '',
	username: '',
	password: ''
})

const onLogin = async (formEl: FormInstance | undefined) => {
	loading.value = true
	if (!formEl) return
	await formEl.validate((valid, fields) => {
		if (valid) {
			useUserStoreHook()
				.login({ state: ruleForm.state, username: ruleForm.username, password: ruleForm.password })
				.then((res) => {
					if (res.code == 1) {
						message(res.message, { type: 'error' })
					}
					if (res.message == 'success') {
						message('登录成功', { type: 'success' })
						addRouter()
						router.push('/home')
					}
					loading.value = false
				})
		} else {
			loading.value = false
			return fields
		}
	})
}
</script>

<template>
	<div class="canvas">
		<img :src="bg" class="bg" />
		<div class="login-container">
			<div class="img">
				<!-- 图片大小为500X380 -->
				<component :is="toRaw(picture)" />
			</div>
			<div class="login-box">
				<div class="login-form">
					<Motion>
						<h2>登录</h2>
					</Motion>
					<el-form ref="ruleFormRef" :rules="loginRules" :model="ruleForm" v-if="currentPage === 0">
						<Motion :delay="100">
							<el-form-item prop="state">
								<el-select v-model="ruleForm.state" placeholder="请选择您的身份">
									<el-option label="管理员" value="1" />
									<el-option label="机构人员" value="2" />
								</el-select>
							</el-form-item>
						</Motion>
						<Motion :delay="100">
							<el-form-item prop="username">
								<el-input
									:prefix-icon="useRenderIcon(User)"
									placeholder="请输入用户名 "
									v-model="ruleForm.username"></el-input>
							</el-form-item>
						</Motion>

						<Motion :delay="150">
							<el-form-item prop="password">
								<el-input
									:prefix-icon="useRenderIcon(Lock)"
									v-model="ruleForm.password"
									placeholder="请输入密码"
									show-password></el-input>
							</el-form-item>
						</Motion>

						<Motion :delay="250">
							<el-form-item class="flex">
								<div class="flex">
									<el-button
										link
										type="primary"
										:underline="false"
										@click="useUserStoreHook().SET_CURRENTPAGE(1)">
										忘记密码？
									</el-button>
								</div>
							</el-form-item>
						</Motion>

						<Motion :delay="300">
							<el-button
								class="btn"
								size="default"
								type="primary"
								:loading="loading"
								@click="onLogin(ruleFormRef)">
								登录
							</el-button>
						</Motion>
					</el-form>
					<!-- 忘记密码 -->
					<update v-if="currentPage === 1" />
				</div>
			</div>
		</div>
	</div>
</template>

<style scoped>
@import '@/style/login.css';
</style>

<style lang="scss" scoped>
:deep(.el-input-group__append, .el-input-group__prepend) {
	padding: 0;
}
</style>
