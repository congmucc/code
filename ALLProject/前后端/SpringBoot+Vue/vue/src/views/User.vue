<template>
    <div>
        <div style="margin: 10px 0">
            <el-input style="width: 200px" prefix-icon="el-icon-search" placeholder="请输入名称" v-model="username"></el-input>
            <el-input style="width: 200px; margin-left: 5px" prefix-icon="el-icon-message" placeholder="请输入邮箱"
                v-model="email"></el-input>
            <el-input style="width: 200px; margin-left: 5px" prefix-icon="el-icon-position" placeholder="请输入地址"
                v-model="address"></el-input>
            <el-button style="margin-left: 5px" type="primary" @click="load">搜索</el-button>
            <el-button style="margin-left: 5px" type="warning" @click="reset">重置</el-button>
        </div>

        <div style="margin: 10px 0">
            <el-button type="primary" @click="handleAdd">新增 <i class="el-icon-circle-plus-outline"></i></el-button>
            <el-popconfirm style="margin-left: 5px" confirm-button-text="确定" cancel-button-text="取消" icon="el-icon-info"
                icon-color="red" title="您确定删除吗？" @confirm="delBatch">
                <el-button type="danger" slot="reference">批量删除 <i class="el-icon-remove-outline"></i></el-button>
            </el-popconfirm>
            <el-upload action="http://localhost:9090/user/import" :show-file-list="false" accept="xlsx"
                :on-success="handleExcelImportSuccess" style="display: inline-block">
                <el-button type="primary" style="margin-left: 15px">导入 <i class="el-icon-bottom"></i></el-button>
            </el-upload>
            <el-button type="primary" @click="exp" class="ml-5">导出 <i class="el-icon-top"></i></el-button>
        </div>

        <el-table :data="tableData" sptripe @selection-change="handleSelectionChange" style="background-color: red">
            <el-table-column type="selection" width="55"> </el-table-column>
            <el-table-column prop="username" label="用户名" width="140">
            </el-table-column>
            <el-table-column prop="nickname" label="昵称" width="120">
            </el-table-column>
            <el-table-column prop="email" label="邮箱"> </el-table-column>
            <el-table-column prop="phone" label="电话"> </el-table-column>
            <el-table-column prop="address" label="地址"> </el-table-column>
            <el-table-column>
                <template v-slot="scope">
                    <el-button type="warning" @click="handleEdit(scope.row)">编辑 <i class="el-icon-edit"></i></el-button>
                    <el-popconfirm style="margin-left: 5px" confirm-button-text="确定" cancel-button-text="取消"
                        icon="el-icon-info" icon-color="red" title="您确定删除吗？" @confirm="handleDelete(scope.row.id)">
                        <el-button type="danger" slot="reference">删除 <i class="el-icon-remove-outline"></i></el-button>
                    </el-popconfirm>
                </template>
            </el-table-column>
        </el-table>
        <div style="padding: 10px 0">
            <el-pagination @size-change="handleSizeChange" @current-change="handleCurrentChange" :current-page="pageNum"
                :page-sizes="[5, 10, 20, 30]" :page-size="pageSize" layout="total, sizes, prev, pager, next, jumper"
                :total="total">
            </el-pagination>
        </div>

        <!-- 对话框 -->
        <el-dialog title="用户信息" :visible.sync="dialogFormVisible">
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
            </el-form>
            <div slot="footer" class="dialog-footer">
                <el-button @click="dialogFormVisible = false">取 消</el-button>
                <el-button type="primary" @click="save">确 定</el-button>
            </div>
        </el-dialog>
    </div>
</template>

<script>
export default {
    name: "User",
    props: [],
    data() {
        return {
            // 表格数组
            tableData: [],
            // 数据库总数
            total: 0,
            // 数据库分页一页的个数
            pageSize: 5,
            // 数据库分页的页数(页码)
            pageNum: 1,
            // 查询用户名
            username: "",
            // 查询邮箱
            email: "",
            // 查询地址
            address: "",
            // 对话框
            form: {},
            // 对话框展示
            dialogFormVisible: false,
            // 多个删除数组
            multipleSelection: [],
        };
    },
    created() {
        this.load();
    },
    methods: {
        // 分页查询
        load() {
            // 请求分页查询的数据
            this.request
                .get(
                    `/user/page?pageNum=${this.pageNum}&pageSize=${this.pageSize}
    &username=${this.username}&email=${this.email}&address=${this.address}`
                )
                .then((res) => {
                    console.log(res);
                    this.tableData = res.records;
                    this.total = res.total;
                });
            this.form = {};
        },
        // 修改每页显示的数量
        handleSizeChange(val) {
            this.pageSize = val;
            this.load();
        },
        // 修改当前页码
        handleCurrentChange(val) {
            this.pageNum = val;
            this.load();
        },
        // 重置搜索框
        reset() {
            this.username = "";
            this.email = "";
            this.address = "";
            this.load();
        },
        // 增加
        handleAdd() {
            this.dialogFormVisible = true;
            this.form;
        },
        // 确定保存
        save() {
            console.log(this.form);
            this.request.post("/user/post", this.form).then((res) => {
                if (res) {
                    this.$message.success("保存成功");
                    console.log(res);
                    this.dialogFormVisible = false;
                    this.load();
                } else {
                    this.$message.error("保存失败");
                }
            });
        },
        // 编辑
        handleEdit(row) {
            this.form = row;
            this.dialogFormVisible = true;
        },
        // 删除
        handleDelete(id) {
            this.request.delete(`/suer/del/${id}`).then((res) => {
                if (res) {
                    this.$message.success("删除成功");
                    console.log(res);
                    this.load();
                } else {
                    this.$message.error("删除失败");
                }
            });
        },
        // 批量删除
        handleSelectionChange(val) {
            this.multipleSelection = val;
        },
        // 点击批量删除
        delBatch() {
            let ids = this.multipleSelection.map((v) => v.id);
            this.request.delete(`/user/batch/${ids}`).then((res) => {
                if (res) {
                    this.$message.success("删除成功");
                    console.log(res);
                    this.load();
                } else {
                    this.$message.error("删除失败");
                }
            });
        },
        // 导入
        handleExcelImportSuccess() {
            this.$message.success("导入成功")
            this.load()
        },
        // 导出
        exp() {
            window.open("http://localhost:9090/user/export")
        }
    },
};
</script>

<style></style>