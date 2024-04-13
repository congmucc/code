import type { PageParams } from '@/types/global'
import type { HotResult } from '@/types/hot'
import { request } from '@/utils/request'

type HotParams = PageParams & { subType?: string }
/**
 * 通用热门推荐类型
 * @param url 请求地址
 * @param data 请求参数
 * @returns
 */
export const getHotRecommendAPI = (url: string, data?: HotParams) => {
  // console.log('url请求路径是： ', url)
  // console.log('data请求路径是： ', data)
  return request<HotResult>({
    method: 'GET',
    url,
    data,
  })
}
