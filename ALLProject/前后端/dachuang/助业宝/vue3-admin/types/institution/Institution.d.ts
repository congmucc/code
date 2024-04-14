export type Institution = {
	id: number
	username: string
	name: string
	password: string
	email: string
	state: string
	type: string
	certify: string
	blacklist: number
}

export type Job = {
	id: number // id
	name: string // 名称
	time: any // 兼职时间
	content: string // 兼职内容
	place: string // 兼职地点
	demand: string // 兼职要求
	phone: string // 联系电话
	salary: string // 薪资
	state: string // 兼职申请状态
}

export type Activity = {
	id: number // 主键、非空、自增，序号
	name: string // 活动名称，非空
	time: any // 活动时间，非空
	content: string // 活动内容，非空
	place: string // 活动场地，非空
	goods: string // 活动物资，非空
	number: number // 人员需求，非空
	state: string // 活动状态，非空（0:审核中，1:驳回，2:申请成功，3:申请失败，4:已结束）
	group: string // 非空（0:只需要志愿者，1：只需要专业人才，2：都需要）
}

export type Feedback = {
	id: number
	username: string
	institutionId: string | number
	campusId: string | number
	content: string
	feedbackStu: string
	feedbackInstitution: string
}
