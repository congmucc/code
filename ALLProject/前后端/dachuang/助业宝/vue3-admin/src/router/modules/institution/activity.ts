const Layout = () => import('@/layout/index.vue')
export default {
	path: '/institution/activity',
	name: 'activity',
	redirect: '/institution/activity',
	component: Layout,
	meta: {
		title: '活动管理',
		isShow: true,
		icon: 'activity',
		rank: 2,
		permission: '2'
	},
	children: [
		{
			path: '/institution/activity',
			component: () => import('@/views/institution/components/act/index.vue'),
			meta: {
				title: '活动状态'
			}
		},
		{
			path: '/institution/act/submit',
			component: () => import('@/views/institution/components/act/institutionActSubmit.vue'),
			meta: {
				title: '活动发布'
			}
		}
	]
}
