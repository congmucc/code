import type { App } from 'vue'
import NProgress from '@/utils/progress'
import { getHistoryMode, ascending } from './utils'
// import { sessionKey, type DataInfo, getUserInfo } from '@/utils/auth'
import { useUserStoreHook } from '@/store/modules/user'
import { createRouter, RouteRecordRaw } from 'vue-router'
import { message } from '@/utils/message'
import remainingRouter from './modules/remaining'
import Cookies from 'js-cookie'

/** 原始静态路由（未做任何处理） */
const routes = []

/** 自动导入全部静态路由，无需再手动引入！匹配 src/router/modules 目录（任何嵌套级别）中具有 .ts 扩展名的所有文件，除了 remaining.ts 文件
 * 如何匹配所有文件请看：https://github.com/mrmlnc/fast-glob#basic-syntax
 * 如何排除文件请看：https://cn.vitejs.dev/guide/features.html#negative-patterns
 */
const modules: Record<string, any> = import.meta.glob(
	['./modules/**/*.ts', '!./modules/**/remaining.ts'],
	{
		eager: true
	}
)

Object.keys(modules).forEach((key) => {
	const routeModule = modules[key].default
	if (
		(routeModule &&
			routeModule.meta &&
			routeModule.meta.permission === useUserStoreHook().GET_STATE()) ||
		routeModule.meta.permission === 'all'
	) {
		routes.push(routeModule)
	}
})

/** 添加用户的动态router */
export const addRouter = () => {
	resetRouter()
	Object.keys(modules).forEach((key) => {
		const routeModule = modules[key].default
		if (
			routeModule &&
			routeModule.meta &&
			routeModule.meta.permission === useUserStoreHook().GET_STATE()
		) {
			router.addRoute(routeModule)
		}
	})
}

/** 用于渲染菜单，保持原始层级 */
export const constantMenus: readonly RouteRecordRaw[] = ascending(routes.flat(Infinity)).concat(
	...remainingRouter
)

/** 不参与菜单的路由 */
export const remainingPaths = Object.keys(remainingRouter).map((v) => {
	return remainingRouter[v].path
})

/** 创建路由实例 */
export const router = createRouter({
	history: getHistoryMode(import.meta.env.VITE_ROUTER_HISTORY),
	routes: constantMenus.concat(...(remainingRouter as any)),
	strict: true,
	// @ts-ignore
	scrollBehavior(to, from, savedPosition) {
		return new Promise((resolve) => {
			if (savedPosition) {
				return savedPosition
			} else {
				if (from.meta.saveSrollTop) {
					const top: number = document.documentElement.scrollTop || document.body.scrollTop
					resolve({ left: 0, top })
				}
			}
		})
	}
})

/* 初始化路由表 */
export function resetRouter() {
	router.getRoutes().forEach((route) => {
		const { name } = route
		if (name) {
			router.hasRoute(name) && router.removeRoute(name)
		}
	})
}

/* 导出 setupRouter */
export const setupRouter = (app: App<Element>) => {
	app.use(router)
}

/* 路由前置守卫 */
router.beforeEach(async (to: any) => {
	// 这里改了，下面三行
	// const userInfo = storageSession().getItem<DataInfo<number>>(sessionKey)
	// NProgress.start()
	// if (userInfo) {
	// 	// 无权限跳转403
	// }
	// const state = useUserStoreHook().GET_STATE()
	// console.log('state: ', state)
	NProgress.start()
	if (!Cookies.get('userInfo')) {
		if (to.path !== '/login') {
			if (!Cookies.get('authorized-token')) message('登录过期', { type: 'error' })
			return '/login'
		}
	} else {
		if (to.path === '/login') {
			message('您需要点击退出登录才能退出', { type: 'error' })
			return ''
		}
	}
})

/* 路由后置守卫 */
router.afterEach(() => {
	NProgress.done()
})

export default router
