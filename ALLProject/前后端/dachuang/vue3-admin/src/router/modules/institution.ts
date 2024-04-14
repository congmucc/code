const Layout = () => import('@/layout/index.vue')
export default {
	path: '/',
	name: 'institution',
	redirect: '/institution',
	component: Layout,
	meta: {
		rank: 0,
		title: ''
	},
	children: [
		{
			path: '/institution',
			component: () => import('@/views/institution/index.vue'),
			meta: {
				isShow: true,
				title: '机构端',
				icon: 'home'
			}
		}
	]
} as RouteConfigsTable
