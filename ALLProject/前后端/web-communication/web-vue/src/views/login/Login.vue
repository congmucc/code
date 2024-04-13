<template>
    <div class="container">
        <div class="login-container">
            <el-form class="login-form" :model="ruleForm" :rules="rules" ref="form">
                <h3 class="form-title">登录</h3>
                <el-form-item label="账号：" prop="username">
                    <el-input :prefix-icon="User" v-model="ruleForm.username" placeholder="请输入账号" />
                </el-form-item>
                <el-form-item label="密码：" prop="password">
                    <el-input :prefix-icon="Lock" v-model="ruleForm.password" type="password" placeholder="请输入密码" />
                </el-form-item>
                <el-form-item>
                    <el-button style="width: 100%" type="primary" @click="onSubmit">登录</el-button>
                </el-form-item>
            </el-form>
        </div>
    </div>
</template>

<script setup>
import { ref } from 'vue'
import { Lock, User } from '@element-plus/icons-vue'
import { useRouter } from 'vue-router'
import { login } from '../../api/login'

const router = useRouter()

const form = ref()
const ruleForm = ref({
    username: '',
    password: '',
})


const rules = ref({
    username: [
        { required: true, message: 'Please input Activity username', trigger: 'blur' },
        { min: 3, max: 5, message: 'Length should be 3 to 5', trigger: 'blur' },
    ],
    password: [
        { required: true, message: 'Please input Activity password', trigger: 'blur' },
    ]

})

// 登录
const onSubmit = async () => {
    await form.value.validate()
    const res = await login(ruleForm.value)
    console.log("返回值： ", res)
    localStorage.setItem('user-token', res.data)
    router.push('/')
}

</script>

<style scoped>
.container {
    width: 100vw;
    height: 100vh;
}

.login-container {
    display: flex;
    justify-content: center;
    align-items: center;
    height: 100%;
}

.login-form {
    box-shadow: 0 0 15px #ccc;
    border-radius: 15px;
    width: 250px;
    padding: 15px 35px;
    background-color: #ffffff;
}

.form-title {
    text-align: center;
}
</style>