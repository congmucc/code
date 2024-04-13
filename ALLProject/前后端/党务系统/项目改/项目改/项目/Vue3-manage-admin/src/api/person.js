import request from '@/utils/request'

//账号管理
export const personGetAccountService = (params) =>
  request.get('teacher/person/account', { params })
//通过id查询回显
export const personById = (id) =>
  request.get('teacher/person/information/' + id)

//删除
export const personDelAccountService = (username) =>
  request.delete('teacher/person/account/' + username)

//重置
export const personPutAccountService = (id) =>
  request.put('teacher/person/account/' + id)

//新增
export const personAddAccountService = (data) =>
  request.post('teacher/person/account', data)

//修改权限状态
export const userUpdateStatus = (t, username) =>
  request.put(
    '/teacher/person/account/put/status?t=' + t + '&username=' + username
  )

//存在判断
export const checkUsernameExists = (data) =>
  request.get('teacher/person/account/exist?username=' + data)

//信息管理
export const personGetInformationService = (params) =>
  request.get('teacher/person/information', { params })

//老师修改时间
export const updateTeacherTime = (data) => request.put('/time/put', data)

//老师修改时间后执行task任务
export const startCronTask = () => request.get('/quartz/task/startCron')

//老师如果是在时间段中关闭时间，那就关闭task任务
export const stopCronTask = () => request.get('/quartz/task/stopCron')

// 获取学生的修改的时间,后期可修改多个
export const getUserTime = () => request.get('/time/get')