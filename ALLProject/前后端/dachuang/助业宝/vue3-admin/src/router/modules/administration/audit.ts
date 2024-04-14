// 人员管理
const Layout = () => import('@/layout/index.vue')
export default {
	path: '/',
	name: 'Audit',
	redirect: '/Audit',
	component: Layout,
	meta: {
		isShow: true,
		rank: 2,
		title: '审核',
		icon: 'error',
		permission: '1'
	},
	children: [
		{
			path: '/Audit',
			name: '身份审核',
			component: () => import('@/views/Audit/PeopleAudit.vue'),
			meta: {
				title: '身份审核'
			}
		},
		{
			path: '/Audit/Institution',
			name: '机构活动审核',
			component: () => import('@/views/Audit/Institution.vue'),
			meta: {
				title: '机构活动审核'
			}
		},
		{
			path: '/Audit/Adjunct.vue',
			name: '兼职审核',
			component: () => import('@/views/Audit/Adjunct.vue'),
			meta: {
				title: '兼职审核'
			}
		}
	]
} as RouteConfigsTable
