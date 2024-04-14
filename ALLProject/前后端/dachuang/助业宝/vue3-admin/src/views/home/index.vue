<script lang="ts" setup>
// import { useRouter } from 'vue-router'

// const router = useRouter()

// function init() {
// 	console.log('获取路由的值 ：', router.getRoutes())
// }
// init()
</script>
<template>
	<!-- 背景 -->
	<div>
		<img src="../image/信工.png" alt="" />
	</div>
</template>
背景
<style lang="scss" scoped>
* {
	margin: 0;
	padding: 0;
}
div {
	display: flex;
	align-items: center;
	justify-content: center;
}
div img {
	display: flex;
	flex-direction: column;
	align-items: center;
	justify-content: center;
	position: relative;
	top: 20px;
	width: 400px;
	filter: opacity(0.4);
}
</style>
