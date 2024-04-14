// 这里是登录成功之后进行获取用户信息的类型

export type UserInfo = {
	id: number // id
	username: string // 用户名字
	state: string // 根据state判断身份， 1 管理员， 2 机构
}
