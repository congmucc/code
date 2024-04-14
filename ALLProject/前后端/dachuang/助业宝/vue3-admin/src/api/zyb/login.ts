import { Result, deleteRequest, get, post, put } from '../base'
import { baseUrlApi } from './utils'

/**
 * 登录
 * @param username
 * @param password
 * @returns
 */
export function login(url: string, data?: any) {
	return post<any, Result<any>>(
		baseUrlApi(`${url}/login?username=${data.username}&password=${data.password}`)
	)
}
