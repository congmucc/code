import request from '@/utils/request'

//登录接口
export const userLoginService = (data) => 
  request.post('/teacher/login', data)
  // return new Promise((resolve, reject) => {
  //   request
  //     .post('/teacher/login', data)
  //     .then((response) => {
  //       console.log(response.data)
  //       resolve(response.data)
  //     })
  //     .catch((error) => {
  //       reject(error)
  //     })
  // })


  //登录接口
export const studentLoginService = (data) =>
  request.post('/student/login', data)

//获取用户信息
export const userGetInforService = (data) =>
  request.get('/teacher/user/profile?username=' + data)

//更新个人信息
export const userUpdateInfoService = (data) =>
  request.put('/teacher/user/profile', data)

//重置密码
// export const userUpdatePassService = (data) =>
//   request.put('/teacher/user/psw', data)
//导出excel
export const ImportExcel = (data) =>
  request.post('/teacher/person/account/import', data)
//获得学生党员信息
export const getStudentInformation = (username) =>
  request.get('/student/information?username=' + username)
export const getStudentByid = (username) =>
  request.get('/student/accounts?username=' + username)
//学生更新信息
export const updateStuInformation = (data) =>
  request.put('/student/update', data)
//更新个人信息
export const studentUpdateInfoService = (data) =>
  request.put('/student/updateEmail', data)
//学生重置密码
export const updateStudentPassword = (username, password) =>
  request.put(
    '/student/user/password?username=' + username + '&' + 'password=' + password
  )
//学生发送邮箱
export const getCodeByStuEmail = (username, email) => {
  return new Promise((resolve, reject) => {
    request
      .get(
        '/student/user/getCode?username=' + username + '&' + 'email=' + email
      )
      .then((response) => {
        resolve(response.data)
      })
      .catch((error) => {
        reject(error)
      })
  })
}
//老师发送邮箱
export const getCodeByTeaEmail = (username, email) => {
  return new Promise((resolve, reject) => {
    request
      .get(
        '/teacher/user/getCode?username=' + username + '&' + 'email=' + email
      )
      .then((response) => {
        resolve(response.data)
      })
      .catch((error) => {
        reject(error)
      })
  })
}
//老师重置密码
export const updateTeacherPassword = (username, password) =>
  request.put(
    '/teacher/user/password?username=' + username + '&' + 'password=' + password
  )