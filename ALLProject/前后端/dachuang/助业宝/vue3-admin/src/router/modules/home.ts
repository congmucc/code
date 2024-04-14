const Layout = () => import('@/layout/index.vue')
export default {
	path: '/',
	redirect: '/home',
	component: Layout,
	meta: {
		rank: 0,
		title: '主页',
		permission: 'all'
	},
	children: [
		{
			path: '/home',
			component: () => import('@/views/home/index.vue'),
			meta: {
				isShow: true,
				title: '首页',
				icon: 'home'
			}
		}
	]
} as RouteConfigsTable
