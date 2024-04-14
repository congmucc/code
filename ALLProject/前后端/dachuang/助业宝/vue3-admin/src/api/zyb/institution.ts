import { Result, deleteRequest, get, post, put } from '../base'
import type { Institution, Feedback, Activity, Job } from '@/../types/institution/Institution'
import type { PageResult } from '@/../types/page'
import { baseUrlApi } from '@/api/zyb/utils'

/**
 * 获取活动列表
 * @param url
 * @param params
 * @returns
 */

export function getJobList(params?: any) {
	return get<any, Result<PageResult<Job>>>(baseUrlApi('institution/job'), params)
}

/**
 * 获取activity列表
 * @param url
 * @param params
 * @returns
 */
export function getActivityList(params?: any) {
	return get<any, Result<PageResult<Activity>>>(baseUrlApi('institution/act'), params)
}

/**
 * 通过id获取单个job
 * @param url
 * @param params
 * @returns
 */
export function getJobById(url?: string) {
	return get<any, Result<Job>>(baseUrlApi(`institution/job/${url}`))
}

/**
 * 更新或者插入job
 * @param url
 * @param data
 * @returns
 */
export function updateJob(data?: any) {
	return post(baseUrlApi('institution/job/update'), data)
}

/**
 * 通过id获取单个activity
 * @param url
 * @param params
 * @returns
 */
export function getActById(id?: string) {
	return get<any, Activity>(baseUrlApi(`institution/act/${id}`))
}

/**
 * 更新或者插入activity
 * @param url
 * @param data
 * @returns
 */
export function updateAct(data?: any) {
	return post(baseUrlApi('institution/act/update'), data)
}

/**
 * 更新institution信息
 * @param url
 * @param data
 */
export function updateInstitutionInfo(data?: any) {
	return post(baseUrlApi('institution/update/info'), data, {
		headers: { 'Content-Type': 'multipart/form-data' }
	})
}

/**
 * 修改个人信息
 * @param data
 * @returns
 */
export function updateInsitutionPartInfo(data?: any) {
	return post(baseUrlApi('institution/update/partinfo'), data)
}

/**
 * 修改认证信息
 * @param data
 * @returns
 */
export function updateAuthen(data?: any) {
	return put(baseUrlApi('institution/authen'), undefined, data)
}

/**
 * 根据id获取institution信息
 * @param id
 * @returns
 */
export function getInstitutionInfo(id: number) {
	return get<any, Result<Institution>>(baseUrlApi(`institution/authen?id=${id}`))
}

/**
 * 删除单个活动
 * @param url
 * @param param
 * @param data
 * @returns
 */
export function deleteAct(id: number) {
	return deleteRequest(baseUrlApi(`institution/act/del?id=${id}`))
}

/**
 * 删除单个job
 * @param url
 * @param param
 * @param data
 * @returns
 */
export function deleteJob(id: number) {
	return deleteRequest(baseUrlApi(`institution/job/del?id=${id}`))
}

/**
 * 根据id查询完成活动反馈列表
 * @param id
 * @returns
 */
export function getstuActivityEdList(id: number) {
	return get<any, Result<Feedback>>(baseUrlApi(`institution/actend/feedback?id=${id}`))
}

/**
 * 更新完成活动反馈
 * @param data
 * @returns
 */
export function updateActEndFeeback(data?: any) {
	return put(baseUrlApi('institution/activity/feedback'), undefined, data)
}

/**
 * 根据id查询正在进行活动反馈列表
 * @param id
 * @returns
 */
export function getstuActivityIngList(id: number) {
	return get<any, Result<Feedback>>(baseUrlApi(`institution/acting/feedback?id=${id}`))
}

/**
 * 更新正在进行活动反馈
 * @param data
 * @returns
 */
export function updateActIngFeeback(data?: any) {
	return put(baseUrlApi('institution/acting/feedback'), undefined, data)
}

/**
 * 根据id查询正在进行活动反馈列表
 * @param id
 * @returns
 */
export function getstuJobList(id: number) {
	return get<any, Result<Feedback>>(baseUrlApi(`institution/job/feedback?id=${id}`))
}

/**
 * 更新正在进行活动反馈
 * @param data
 * @returns
 */
export function updateJobFeeback(data?: any) {
	return put(baseUrlApi('institution/job/feedback'), undefined, data)
}
