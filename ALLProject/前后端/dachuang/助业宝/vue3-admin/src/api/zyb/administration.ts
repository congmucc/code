import { Result, deleteRequest, get, post, put } from '../base'
import { baseUrlApi } from './utils'
import type { student } from '@/../types/administration'
/**
 * 根据type 获取机构列表
 * @param params 
 * @returns 
 */
export function getInstitution(params?: object) {
  return get<any, Result<any>>(baseUrlApi('administration/institution'), params)
}

/**
 * 根据值volunteer,volun_certify,profess值是否为1，0来判断，获取身份审核的数据
 * @param params 
 * @returns 
 */
export function getStudent(params?: object) {
  return get<any, Result<any>>(baseUrlApi('administration/student'), params)
}

/**
 * 根据id选择管理员信息
 * @param params 
 * @returns 
 */

export function getAdministration(params?: object) {
  return get<any, Result<any>>(baseUrlApi('administration/administration'), params)
}

/**
 * 删除公司
 * @param url
 * @param param
 * @param data
 * @returns
 */
export function deleteInst(id: number) {
  return deleteRequest(baseUrlApi(`administration/inst/del?id=${id}`))
}


/**
 * 公司禁用
 * @param url
 * @param param
 * @param data
 * @returns
 */
export function updateInst(id: number) {
  return put(baseUrlApi(`administration/inst/put?id=${id}`))
}

/**
 * 公司启用
 * @param url
 * @param param
 * @param data
 * @returns
 */
export function ApproveInst(id: number) {
  return put(baseUrlApi(`administration/approve/put?id=${id}`))
}


/**
 * 删除个人
 * @param url
 * @param param
 * @param data
 * @returns
 */
export function deleteStu(username: string) {
  return deleteRequest(baseUrlApi(`administration/stu/del?username=${username}`))
}
/**
 * 个人禁用
 * @param url
 * @param param
 * @param data
 * @returns
 */
export function updateStu(username: string) {
  return put(baseUrlApi(`administration/stu/put?username=${username}`))
}

/**
 * 个人启用
 * @param url
 * @param param
 * @param data
 * @returns
 */
export function ApproveStu(username: string) {
  return put(baseUrlApi(`administration/ApproveStu/put?username=${username}`))
}

/**
 * 通过username获取单个stu
 * @param url
 * @param params
 * @returns
 */
export function getStuByUsername(url?: string) {
  return get<any, Result<student>>(baseUrlApi(`administration/stu/${url}`))
}