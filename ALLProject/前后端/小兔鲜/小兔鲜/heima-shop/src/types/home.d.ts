import type { GoodsItem } from './global'

/** 首页-广告区域数据类型 */
export type BannerItem = {
  /** 跳转链接 */
  hrefUrl: string
  /** id */
  id: string
  /** 图片链接 */
  imgUrl: string
  /** 跳转类型 */
  type: number
}

/** 首页-前台类目数据类型 */
export type CategoryItem = {
  /** id */
  id: string
  /** 按钮图片 */
  icon: string
  /** 按钮名称 */
  name: string
}

/** 首页-热门推荐数据类型 */
export type HotItem = {
  /** id */
  id: string
  /** 推荐说明 */
  alt: string
  /** 图片集合 */
  pictures: string[]
  /** 跳转地址 */
  target: string
  /** 推荐标题 */
  title: stirng
  /** 推荐类型 */
  type: string
}

/** 猜你喜欢-商品类型 */
export type GuessItem = GoodsItem
