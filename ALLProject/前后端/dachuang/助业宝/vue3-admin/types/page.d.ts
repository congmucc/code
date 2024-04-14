/** 通用分页结果类型 */
export type PageResult<T> = {
  /** 返回的总结果 */
  rows: T[]
  /**返回的总数量 */
  total: number
}


/** 通用分页参数类型 */
export type PageParams = {
  /** 页码：默认值为 1 */
  page?: number
  /** 页大小：默认值为 10 */
  pageSize?: number
}
