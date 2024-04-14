<script setup lang="ts">
import { ref } from 'vue';
import { ElCard } from 'element-plus';

interface Article {
    title: string;
    content: string;
    publishTime: string;
    location: string;
    status: '审核中' | '驳回' | '已通过';
}



// 示例：生成一些测试数据（数组形式）
const articlesList = ref<Article[]>([
    // 基于article接口创建多个示例文章对象
    {
        title: '测试文章1',
        content: '这是测试文章的内容1',
        publishTime: '2022-01-01 - 2022-02-01',
        location: '北京',
        status: '审核中',
    },
    {
        title: '测试文章2',
        content: '这是测试文章的内容2',
        publishTime: '2022-02-01 - 2022-03-01',
        location: '上海',
        status: '已通过',
    },
    {
        title: '测试文章1',
        content: '这是测试文章的内容1',
        publishTime: '2022-01-01 - 2022-02-01',
        location: '北京',
        status: '审核中',
    },
    {
        title: '测试文章2',
        content: '这是测试文章的内容2',
        publishTime: '2022-02-01 - 2022-03-01',
        location: '上海',
        status: '已通过',
    },
    {
        title: '测试文章1',
        content: '这是测试文章的内容1',
        publishTime: '2022-01-01 - 2022-02-01',
        location: '北京',
        status: '审核中',
    },
    {
        title: '测试文章2',
        content: '这是测试文章的内容2',
        publishTime: '2022-02-01 - 2022-03-01',
        location: '上海',
        status: '已通过',
    },
    {
        title: '测试文章1',
        content: '这是测试文章的内容1',
        publishTime: '2022-01-01 - 2022-02-01',
        location: '北京',
        status: '审核中',
    },
    {
        title: '测试文章2',
        content: '这是测试文章的内容2',
        publishTime: '2022-02-01 - 2022-03-01',
        location: '上海',
        status: '已通过',
    },
    // 更多文章...
]);

</script>

<template>
    
    <hr />
    <div class="custom-card-father">
    <!-- 使用ElCard展示单篇文章 -->
        <ElCard class="custom-card" v-for="(item, index) in articlesList" :key="index">
            <div class="card-header">
                <h3>{{ item.title }}</h3>
                <p>时间：{{ item.publishTime }}</p>
                <p>地点：{{ item.location }}</p>
            </div>
            <div class="card-content">{{ item.content }}</div>
            <!-- 根据状态显示不同内容或样式 -->
        </ElCard>
    </div>

</template>

<style scoped>
/* ... 自定义样式代码 ... */
hr {
    color: #bbb;
    margin: 10px 20px;
}

/** 卡片的父元素样式 */
.custom-card-father {
    display: flex;
    flex-wrap: wrap;
    justify-content: center;
}

/* 卡片的样式 */
.custom-card {
    margin: 10px 15px;
    width: 41ch;
    height: 400px;
    display: flex;
    flex-wrap: wrap;

    
}

/* 卡片头部样式 */
.card-header {
    /* TODO */
}
</style>