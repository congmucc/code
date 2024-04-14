import { defineStore } from 'pinia'
import router, { resetRouter } from '@/router'
import { store } from '@/store'
import { storageSession } from '@pureadmin/utils'
import { Result } from '@/api/base'
import type { userType } from './types'
import {
	type DataInfo,
	sessionKey,
	setToken,
	setUserInfo,
	removeUserInfo,
	removeToken
} from '@/utils/auth'
import { RefreshTokenResult } from '@/api/user' // 类型
import { refreshTokenApi } from '@/api/user' // api接口
import { login } from '@/api/zyb/login'
import Cookies from 'js-cookie'

export type LoginRequest = {
	state: string
	username: string
	password: string
}

export const useUserStore = defineStore({
	id: 'dc-user',
	state: (): userType => ({
		// 判断登录页面显示哪个组件（0：登录（默认）、1：忘记密码）
		currentPage: 0,
		// 用户名
		username: storageSession().getItem<DataInfo<number>>(sessionKey)?.username ?? '',
		state: JSON.parse(Cookies.get('userInfo') ?? '{}')?.state ?? ''
	}),
	actions: {
		/** 存储登录页面显示哪个组件 */
		SET_CURRENTPAGE(value: number) {
			this.currentPage = value
		},
		/** 存储用户名 */
		SET_USERNAME(username: string) {
			this.username = username
		},
		SET_STATE(state: string) {
			this.state = state
		},
		GET_STATE() {
			return this.state
		},
		/** 登入 */
		login(data: LoginRequest): Promise<Result<any>> {
			// 这里是登录，如果选择的是1那就是管理员，2就是机构，这是发送请求
			return login(data.state === '1' ? 'administration' : 'institution', {
				username: data.username,
				password: data.password
			}).then((res: any) => {
				if (res.code === 0) {
					// 添加token
					setToken({
						username: data.username,
						accessToken: res.data.token,
						expires: Date.now() + 3600 * 1000 * 1000,
						refreshToken: res.data
					})
					// todo添加信息
					setUserInfo({
						username: data.username,
						state: data.state,
						id: res.data.id
					})
					this.SET_STATE(data.state)
				}
				return Promise.resolve(res)
			})
		},
		/** 前端登出（不调用接口） */
		logOut() {
			this.username = ''
			this.state = ''
			// todo 这里是添加的
			removeUserInfo()
			resetRouter()
			removeToken()
			router.push('/login')
		},
		info() {
			// todo 这里需要根据state改一下
			if (this.state === '2') router.push('/institution/application')
			else if (this.state === '1') null
		},
		/** 刷新`token` */
		async handRefreshToken(data) {
			return new Promise<RefreshTokenResult>((resolve, reject) => {
				refreshTokenApi(data)
					.then((data) => {
						if (data) {
							// @ts-ignore
							setToken(data.data)
							resolve(data)
						}
					})
					.catch((error) => {
						reject(error)
					})
			})
		}
	}
})

export function useUserStoreHook() {
	return useUserStore(store)
}
