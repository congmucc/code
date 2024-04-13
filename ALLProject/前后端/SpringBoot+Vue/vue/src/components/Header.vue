<template>
    <div style="display: flex; line-height: 60rpx">
        <div style="flex: 1; font-size: 20px ">
            <span :class="collapseBtnClass" style="cursor: pointer" @click="collapse"></span>

            <div style="display: inline-block; margin-left: 10px;">
                <el-breadcrumb separator="/" style="display: inline-block; margin-left: 10px">
                    <el-breadcrumb-item :to="'/'">首页</el-breadcrumb-item>
                    <el-breadcrumb-item>{{ currentPathName }}</el-breadcrumb-item>
                </el-breadcrumb>
            </div>
        </div>
        <el-dropdown trigger="click" style="cursor: pointer">
            <div style="display:inline-block">
                <img :src="user.avatar" alt="" style="width: 30px; border-radius: 50%; position: relative; top: 10px; right: 5px;">
                <span>{{ user.nickname }}</span><i class="el-icon-arrow-down" style="margin-left:5px"></i>
            </div>

            <el-dropdown-menu slot="dropdown" style="text-align:center; width:100px">
                <el-dropdown-item>
                    <router-link to="/person" style="text-decoration:none">个人信息</router-link>
                </el-dropdown-item>
                <el-dropdown-item>
                    <span style="text-decoration:none" @click="logout">退出</span>
                </el-dropdown-item>
            </el-dropdown-menu>
        </el-dropdown>
    </div>
</template>

<script>
export default {
    name: "Header",
    props: ["collapseBtnClass", "collapse"],
    data() {
        return {
            user:localStorage.getItem("user") ? JSON.parse(localStorage.getItem("user")) : {}
        }
    },
    computed: {
        currentPathName() {
            return this.$store.state.currentPathName;//需要监听的数据
        }
    },
    watch: {
        currentPathName(newVal, oldVal) {
            console.log(newVal)
        }
    },
    methods: {
        logout() {
            this.$router.push("/login")
            localStorage.removeItem("user")
            this.$message.success("退出成功")
        }
    }

};

</script>

<style></style>