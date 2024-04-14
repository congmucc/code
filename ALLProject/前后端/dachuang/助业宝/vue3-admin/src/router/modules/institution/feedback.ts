const Layout = () => import('@/layout/index.vue')
export default {
	path: '/institution/feedback',
	name: 'feedback',
	redirect: '/institution/feedback/actend',
	component: Layout,
	meta: {
		title: '学生反馈',
		isShow: true,
		icon: 'feedback',
		rank: 2,
		permission: '2'
	},
	children: [
		{
			path: '/institution/feedback/actend',
			name: '',
			component: () => import('@/views/institution/components/feedback/actendFeedback.vue'),
			meta: {
				title: '已完成活动反馈'
			}
		},
		{
			path: '/institution/feedback/acting',
			component: () => import('@/views/institution/components/feedback/actingFeedback.vue'),
			meta: {
				title: '进行中活动反馈'
			}
		},
		{
			path: '/institution/feedback/job',
			component: () => import('@/views/institution/components/feedback/jobFeedback.vue'),
			meta: {
				title: '兼职反馈'
			}
		}
	]
}
