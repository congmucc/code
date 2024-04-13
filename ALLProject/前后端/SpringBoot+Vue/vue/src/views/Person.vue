<template>
    <el-card style="width: 500px; position: relative; left: 250px;">
        <el-form label-width="60px" size="small">
            <el-form-item label="用户名">
                <el-input v-model="form.username" autocomplete="off"></el-input>
            </el-form-item>
            <el-form-item label="密码">
                <el-input v-model="form.password" autocomplete="off"></el-input>
            </el-form-item>
            <el-form-item label="昵称">
                <el-input v-model="form.nickname" autocomplete="off"></el-input>
            </el-form-item>
            <el-form-item label="邮箱">
                <el-input v-model="form.email" autocomplete="off"></el-input>
            </el-form-item>
            <el-form-item label="电话">
                <el-input v-model="form.phone" autocomplete="off"></el-input>
            </el-form-item>
            <el-form-item label="地址">
                <el-input v-model="form.address" autocomplete="off"></el-input>
            </el-form-item>
            <div style=" display: flex; justify-content: space-evenly;">
                <el-button @click="$router.back()">取 消</el-button>
                <el-button type="primary" @click="save">确 定</el-button>
            </div>
        </el-form>

    </el-card>
</template>

<script>
export default {
    name: "Person",
    data() {
        return {
            form: {},
            user:localStorage.getItem("user") ? JSON.parse(localStorage.getItem("user")) : {}
        }
    },
    created() {
        this.request.get(`/user/username/${this.user.username}`).then(res => {
            if (res.code === '200') {
                this.form = res.data
            }
            console.log(res.data)
            console.log("form: "+this.form)
        })
    },
    methods: {
        // 确定保存
        save() {
            console.log(this.form);
            this.request.post("/user/post", this.form).then((res) => {
                if (res) {
                    this.$message.success("保存成功");
                } else {
                    this.$message.error("保存失败");
                }
            });
        },
    }

}
</script>

<style></style>