// 人员管理
const Layout = () => import('@/layout/index.vue')
export default {
	path: '/',
	name: 'Manage',
	redirect: '/Manage',
	component: Layout,
	meta: {
		rank: 3,
		title: '',
		permission: '1'
	},
	children: [
		{
			path: '/Manage',
			component: () => import('@/views/Manage/PeopleManage.vue'),
			meta: {
				isShow: true,
				title: '人员管理',
				icon: 'home',
				rank: 3
			}
		},
		{
			name: '管理员',
			path: '/Audit/PeopleManage/Manager',
			component: () => import('@/views/Manage/Manager.vue'),
			meta: {
				title: '管理员'
			}
		}
	]
} as RouteConfigsTable
