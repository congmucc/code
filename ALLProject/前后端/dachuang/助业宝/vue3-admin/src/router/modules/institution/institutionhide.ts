const Layout = () => import('@/layout/index.vue')
export default {
	path: '/institution/hide',
	name: 'hide',
	component: Layout,
	meta: {
		title: '其他',
		isShow: false,
		rank: 2,
		permission: '2'
	},
	children: [
		{
			path: '/institution/application',
			component: () => import('@/views/institution/components/institutionApplication2.vue'),
			meta: {
				title: '机构认证'
			}
		},
		{
			path: '/institution/act/details',
			component: () => import('@/views/institution/components/look/actLook.vue'),
			meta: {
				title: '查看活动'
			}
		},
		{
			path: '/institution/job/details',
			component: () => import('@/views/institution/components/look/jobLook.vue'),
			meta: {
				title: '查看兼职'
			}
		}
	]
}
