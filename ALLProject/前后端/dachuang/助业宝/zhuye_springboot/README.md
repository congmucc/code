# 助业宝小程序

## Api接口

https://app.apifox.com/invite?token=h7JZFsA5t3M9xWy95kowe

## 数据库设计

### 学生账号student

| 参数名          | 类型    | 长度 | 补充                                                         | 说明                 |
| --------------- | ------- | ---- | :----------------------------------------------------------- | -------------------- |
| username        | varchar | 255  | 主键、非空                                                   | 学号                 |
| openid          | varchar | 255  |                                                              | 微信唯一标           |
| name            | varchar | 255  | 非空                                                         | 姓名                 |
| avator          | varchar | 255  |                                                              | 头像地址             |
| university      | varchar | 255  | 非空                                                         | 学校                 |
| college         | varchar | 255  | 非空                                                         | 学院                 |
| major           | varchar | 255  | 非空                                                         | 专业                 |
| phone           | varchar | 255  | 非空                                                         | 联系电话             |
| id_card         | varchar | 255  | 非空                                                         | 身份证号             |
| ability         | text    |      | 非空                                                         | 个人能力             |
| stu_id          | varchar | 255  | 非空（0不是学生、1是学生）默认：0                            | 学生资格             |
| stu_certify     | varchar | 255  |                                                              | 学生证证明图片地址   |
| volunteer       | varchar | 255  | 非空（0不是志愿者、1是志愿者）默认：0                        | 志愿者资格           |
| volun_certify   | varchar | 255  |                                                              | 志愿者证明图片地址   |
| profess         | varchar | 255  | 非空（0不是专业人才、1之后(包括1)为各类型专业人才代号标签）默认：0 | 专业人才             |
| profess_certify | varchar | 255  |                                                              | 专业人才证明图片地址 |
| blacklist       | int     | 11   | 非空（0：正常 ，1：被列为黑名单）默认：0                     | 黑名单标记           |



### 高校administration

| 参数名   | 类型    | 长度 | 补充                                 | 说明   |
| -------- | ------- | ---- | :----------------------------------- | ------ |
| id       | int     | 11   | 主键、非空（id=0的为超管，增删高校） | 高校id |
| username | varchar | 255  | 非空                                 | 帐号   |
| password | varchar | 255  | 非空、默认：12345678                 | 密码   |
| email    | varchar | 255  |                                      | 邮箱   |



### 机构表institution

| 参数名    | 类型    | 长度 | 补充                                     | 说明             |
| --------- | ------- | ---- | :--------------------------------------- | ---------------- |
| id        | int     | 11   | 主键、非空、自增                         | 机构ID           |
| username  | varchar | 255  | 非空                                     | 帐号             |
| name      | varchar | 255  | 非空                                     | 机构名称         |
| password  | varchar | 255  | 非空、默认：12345678                     | 密码             |
| email     | varchar | 255  |                                          | 邮箱             |
| state     | varchar | 255  | 非空(0:未认证，1：已认证)                |                  |
| type      | varchar | 255  | 非空                                     | 机构类型         |
| certify   | varchar | 255  | 非空                                     | 机构证明图片地址 |
| blacklist | int     | 11   | 非空（0：正常 ，1：被列为黑名单）默认：0 | 黑名单标记       |



### 校内活动表（待审核）campus_will

| 参数名         | 类型    | 长度 | 补充                                                 | 说明         |
| -------------- | ------- | ---- | :--------------------------------------------------- | ------------ |
| id             | int     | 11   | 主键、非空、自增                                     | 序号         |
| name           | varchar | 255  | 非空                                                 | 活动名称     |
| time           | varchar | 255  | 非空                                                 | 活动时间     |
| content        | text    |      | 非空                                                 | 活动内容     |
| place          | varchar | 255  | 非空                                                 | 活动场地     |
| goods          | varchar | 255  | 非空                                                 | 活动物资     |
| number         | int     | 11   | 非空                                                 | 人员需求     |
| institution_id | int     | 11   | 非空                                                 | 机构id       |
| state          | varchar | 255  | 非空（1审核中，2驳回，3申请成功，4已发布）、默认：1  | 活动申请状态 |
| reject         | text    |      |                                                      | 驳回原因     |
| group          | varchar | 255  | 非空（0:只需要志愿者，1：只需要专业人才，2：都需要） | 需求         |



### 校内活动表（进行中）campus_ing

| 参数名         | 类型    | 长度 | 补充             | 说明     |
| -------------- | ------- | ---- | :--------------- | -------- |
| id             | int     | 11   | 主键、非空、自增 | 序号     |
| name           | varchar | 255  | 非空             | 活动名称 |
| time           | varchar | 255  | 非空             | 活动时间 |
| content        | text    |      | 非空             | 活动内容 |
| place          | varchar | 255  | 非空             | 活动场地 |
| goods          | varchar | 255  | 非空             | 活动物资 |
| number         | int     | 11   | 非空             | 人员需求 |
| institution_id | int     | 11   | 非空             | 机构id   |
|                |         |      |                  |          |



### 校内活动表（已完成）campus_ed

| 参数名         | 类型    | 长度 | 补充             | 说明     |
| -------------- | ------- | ---- | :--------------- | -------- |
| id             | int     | 11   | 主键、非空、自增 | 序号     |
| name           | varchar | 255  | 非空             | 活动名称 |
| time           | varchar | 255  | 非空             | 活动时间 |
| content        | text    |      | 非空             | 活动内容 |
| place          | varchar | 255  | 非空             | 活动场地 |
| goods          | varchar | 255  | 非空             | 活动物资 |
| number         | int     | 11   | 非空             | 人员需求 |
| institution_id | int     | 11   | 非空             | 机构id   |
|                |         |      |                  |          |



### 兼职活动表job

| 参数名         | 类型    | 长度 | 补充                                                | 说明         |
| -------------- | ------- | ---- | :-------------------------------------------------- | ------------ |
| id             | int     | 11   | 主键、非空、自增                                    | 序号         |
| name           | varchar | 255  | 非空                                                | 兼职名称     |
| time           | varchar | 255  | 非空                                                | 兼职时间     |
| content        | text    |      | 非空                                                | 兼职内容     |
| place          | varchar | 255  | 非空                                                | 兼职地点     |
| demand         | text    |      |                                                     | 兼职要求     |
| phone          | varchar | 255  | 非空                                                | 兼职电话     |
| institution_id | int     | 11   | 非空                                                | 机构id       |
| salary         | varchar | 255  | 非空                                                | 薪资待遇     |
| state          | varchar | 255  | 非空（1审核中，2驳回，3申请成功，4已发布）、默认：1 | 活动申请状态 |
| reject         | text    |      |                                                     | 驳回原因     |



### 学生校园活动表(进行中)stu_activity_sh

| 参数名         | 类型    | 长度 | 补充                                         | 说明                 |
| -------------- | ------- | ---- | :------------------------------------------- | -------------------- |
| id             | int     | 11   | 主键、非空、自增                             | 序号                 |
| username       | varchar | 255  | 非空                                         | 学号                 |
| institution_id | int     | 11   | 非空                                         |                      |
| campus_id      | int     | 11   | 非空                                         | 校园活动id           |
| content        | text    |      |                                              | 记录活动该学生干了什 |
| state          | varchar | 255  | 非空（1审核中，2未通过，3报名成功）、默认：1 | 报名审核             |
|                |         |      |                                              |                      |



### 学生校园活动表(进行中)stu_activity_ing

| 参数名               | 类型    | 长度 | 补充             | 说明                 |
| -------------------- | ------- | ---- | :--------------- | -------------------- |
| id                   | int     | 11   | 主键、非空、自增 | 序号                 |
| username             | varchar | 255  | 非空             | 学号                 |
| institution_id       | int     | 11   | 非空             |                      |
| campus_id            | int     | 11   | 非空             | 校园活动id           |
| content              | text    |      |                  | 记录活动该学生干了什 |
| feedback_stu         | text    |      |                  | 学生反馈             |
| feedback_institution | text    |      |                  | 机构反馈             |



### 学生校园活动表(已完成)stu_activity_ed

| 参数名               | 类型    | 长度 | 补充             | 说明                 |
| -------------------- | ------- | ---- | :--------------- | -------------------- |
| id                   | int     | 11   | 主键、非空、自增 | 序号                 |
| username             | varchar | 255  | 非空             | 学号                 |
| institution_id       | int     | 11   | 非空             |                      |
| campus_id            | int     | 11   | 非空             | 校园活动id           |
| content              | text    |      |                  | 记录活动该学生干了什 |
| feedback_stu         | text    |      |                  | 学生反馈             |
| feedback_institution | text    |      |                  | 机构反馈             |
| stu_act              | varchar | 255  |                  | 证书图片地址         |



### 学生兼职活动表stu_job_activity

| 参数名               | 类型    | 长度 | 补充             | 说明                 |
| -------------------- | ------- | ---- | :--------------- | -------------------- |
| id                   | int     | 11   | 主键、非空、自增 | 序号                 |
| username             | varchar | 255  | 非空             | 学号                 |
| institution_id       | int     | 11   | 非空             | 机构id               |
| job_id               | int     | 11   | 非空             | 兼职活动id           |
| content              | text    |      |                  | 记录活动该学生干了什 |
| feedback_stu         | text    |      |                  | 学生反馈             |
| feedback_institution | text    |      |                  | 机构反馈             |