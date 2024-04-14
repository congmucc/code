import { Result, deleteRequest, get, post, put } from '../base'
import { baseUrlApi } from './utils'

/**
 * 登录
 * @param username
 * @param password
 * @returns
 */
export function login(data?: object) {
	return post<any, Result<any>>(baseUrlApi('administration/login'), { data })
}
