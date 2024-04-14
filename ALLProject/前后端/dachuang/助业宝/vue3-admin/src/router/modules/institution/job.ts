const Layout = () => import('@/layout/index.vue')
export default {
	path: '/institution/job',
	name: 'job',
	component: Layout,
	meta: {
		rank: 1,
		isShow: true,
		title: '兼职活动',
		icon: 'job',
		permission: '2'
	},
	children: [
		{
			path: '/institution/job',
			component: () => import('@/views/institution/components/job/index.vue'),
			meta: {
				title: '兼职状态'
			}
		},
		{
			path: '/institution/job/submit',
			component: () => import('@/views/institution/components/job/institutionJobSubmit.vue'),
			meta: {
				title: '兼职发布'
			}
		}
	]
} as RouteConfigsTable
