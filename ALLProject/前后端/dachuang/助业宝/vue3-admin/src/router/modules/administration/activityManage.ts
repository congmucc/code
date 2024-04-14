// 活动管理
const Layout = () => import('@/layout/index.vue')
export default {
	path: '/ActivityManage',
	name: 'ActivityManage',
	redirect: '/ActivityManage/Await',
	component: Layout,
	meta: {
		title: '活动管理',
		isShow: true,
		icon: 'error',
		rank: 2,
		permission: '1'
	},
	children: [
		{
			path: '/ActivityManage/Await',
			name: '待审核',
			component: () => import('@/views/ActivityManage/Await.vue'),
			meta: {
				title: '待审核'
			}
		},

		{
			path: '/ActivityManage/Pass',
			name: '已发布',
			component: () => import('@/views/ActivityManage/Pass.vue'),
			meta: {
				title: '已发布'
			}
		},

		{
			path: '/ActivityManage/Rejected',
			name: '已驳回',
			component: () => import('@/views/ActivityManage/Rejected.vue'),
			meta: {
				title: '已驳回'
			}
		}
	]
} as RouteConfigsTable
