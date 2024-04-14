// 查看
const Layout = () => import('@/layout/index.vue')
export default {
	path: '/',
	// name: 'Audit',
	// redirect: '/Audit',
	component: Layout,
	meta: {
		title: '',
		permission: '1',
		rank: 2
	},
	children: [
		// 审核页面的查看
		{
			name: '身份查看',
			path: '/Audit/PeopleAudit/auditLook',
			component: () => import('@/views/Audit/AuditLook.vue'),
			meta: {
				title: '身份查看',
				// 新增属性
				isInSidebar: false
			}
		},
		{
			name: '机构查看',
			path: '/Audit/Institution/InstitutionLook',
			component: () => import('@/views/Audit/InstitutionLook.vue'),
			meta: {
				title: '机构查看'
			}
		},
		{
			name: '兼职查看',
			path: '/Audit/Adjunct/AdjunctLook',
			component: () => import('@/views/Audit/AdjunctLook.vue'),
			meta: {
				title: '兼职查看'
			}
		},
		// 活动页面的查看
		{
			name: 'pendingRouteName',
			path: '/ActivityManage/Await/AwaitLook',
			component: () => import('@/views/ActivityManage/AwaitLook.vue'),
			meta: {
				title: '待审核查看'
			}
		},

		{
			name: 'publishedRouteName',
			path: '/ActivityManage/Pass/PassLook',
			component: () => import('@/views/ActivityManage/PassLook.vue'),
			meta: {
				title: '发布查看'
			}
		},
		{
			name: 'rejectedRouteName',
			path: '/ActivityManage/Rejected/RejectLook',
			component: () => import('@/views/ActivityManage/RejectLook.vue'),
			meta: {
				title: '驳回查看'
			}
		}
	]
} as RouteConfigsTable
