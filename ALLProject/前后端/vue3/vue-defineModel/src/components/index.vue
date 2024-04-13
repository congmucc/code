<template>
  <div id="app" style="height: 100%;">
    <!-- 页面头部 -->
    <div id="header" style="background-color: #ffffff;position: fixed;top: 0px;left: 5%;z-index: 1000">
      <div class="header-left">
        <a href="#" class="logo" style="margin-right: 13px">LOGO</a>
        <!-- 导航按钮 -->
        <button @click="goToLearningActivities">学习活动</button>
        <button @click="goToLearningMaterials">学习资料</button>
        <button @click="goToLearningExchange">学习交流</button>
      </div>
      <div class="header-right">
        <div v-if="!user">
          <a @click="goToLogin">登录</a><span style="color: #999999;"> | </span>
          <a @click="goToRegistry">注册</a>
        </div>
        <div v-else>
          <el-button @click="publish = true" icon="el-icon-circle-plus-outline" style="margin-right: 30px">发布</el-button>
          {{ user.username }} <a @click="logout" style="margin-left: 5px">退出登录</a>
        </div>
      </div>
    </div>
    <div style="display: flex; flex-direction: column; width: 90%; margin-left: 7%;border-radius: 15px;
    height: 100%;margin-top: 70px">
      <div style="display: flex;">
<!--          <el-image-->
<!--            src="https://gimg2.baidu.com/image_search/src=http%3A%2F%2Fc-ssl.duitang.com%2Fuploads%2Fitem%2F201908%2F12%2F20190812093610_nhlgu.jpg&refer=http%3A%2F%2Fc-ssl.duitang.com&app=2002&size=f9999,10000&q=a80&n=0&g=0n&fmt=auto?sec=1707808409&t=fcc7d79277bcd2b0d94be5a307708335"-->
<!--            fit="cover" style="height: 35%;width: 80%;"></el-image>-->
        <div style="width: 65%;flex-direction: column;margin-bottom: 10px;margin-top: 10px;" >
          <div v-for="item in exchangeList" class="tieziList">
            <div style="height: 140px;width: 90%;margin-left: 5%;border-color: #f5f5f6;padding-top: 2px" @click="openCard(item.id)">
              <p style="font-size: 18px;color: #222226;margin-left: 20px">{{item.title}}</p>
              <p class="infoP" v-html="item.info"></p>
              <div style="width: 100%;margin-left: 20px">
                 <span style="font-size: 14px;color: #6d6e7c; padding-top: 5px;"></span>
              <div style="width: 100%">
                 <span style="font-size: 14px;color: #6d6e7c; margin-left: 50%;padding-top: 5px">
                作者：{{ item.username }}
              </span>
                <span style="font-size: 14px;color: #6d6e7c;margin-left: 20px;padding-top: 5px">
                修改时间：{{item.ctime}}
              </span>
              </div>
            </div>
            <div style="width: 100%;background-color: #f5f5f6;height: 2px"></div>
          </div>

        </div>

        <el-card class="box-card" style="width: 26vw; top: 80px;position: fixed;right: 6%;height: 450px ">
          <div style="display: flex;align-items: center;width: 100%">
            <el-calendar v-model="this.value" :range="[this.startDate,this.endDate]" style="font-size: 13px">
              <template
                slot="dateCell"
                slot-scope="{date, data}">
                <p style="text-align: center;">
                  {{ data.day.split('-').slice(1).join('-') }}
                  <span v-if="datesValue[data.day]" style="color: green;font-size: 10px;">
              ✔️
            </span>
                </p>
              </template>
            </el-calendar>

          </div>
          <el-button style="position: relative;height: 50px;width: 60%;margin-left: 20%" type="success" round size="small"
                     v-if="!datesValue[getCurrentFormattedDate()]" @click="clockInto"
          >
            打卡
          </el-button>
          <el-button style="position: relative;height: 50px;width: 60%;margin-left: 20%" disabled type="info" round
                     size="small" v-else
          >
            已打卡
          </el-button>
          <div>
            <h3 style="margin-left: 3%">学习动态:</h3>
          </div>
          <div style="height: 200px; overflow: hidden;">
            <div id="scrollContainer" style="animation: scroll 20s linear infinite;">
              <!-- 第一份内容 -->
              <div v-for="o in test1" :key="o" class="text item" style="margin-left: 3%">
                <div style="height: 45px; width: 95%; background-color: #f1f3fd; margin-bottom: 10px; border-radius: 15px; font-size: 15px; display: flex; align-items: center">
                  <span style="margin-left: 5%">{{ o }}</span>
                </div>
              </div>
              <!-- 第二份相同的内容 -->
              <div v-for="o in test1" :key="o+'copy'" class="text item" style="margin-left: 3%">
                <div style="height: 45px; width: 95%; background-color: #f1f3fd; margin-bottom: 10px; border-radius: 15px; font-size: 15px; display: flex; align-items: center">
                  <span style="margin-left: 5%">{{ o }}</span>
                </div>
              </div>
            </div>
          </div>
<!--          <el-card class="box-card" style="align: center;text-align: center;">-->
<!--            <div slot="header" class="clearfix">-->
<!--              <span>学习动态</span>-->
<!--&lt;!&ndash;              <el-button style="float: right; padding: 3px 0" type="text">操作按钮</el-button>&ndash;&gt;-->
<!--            </div>-->

<!--          </el-card>-->
        </el-card>
      </div>
    </div>
<!--    发布-->
    <el-dialog
      :visible.sync="publish"
      width="50%"
      >
      <div class="myTitle">
        <el-input style="border-radius: 15px;width: 60%" v-model="publishStudy.title" ></el-input>
        <el-button type="primary" round style="margin-left: 5%" @click="publishExchange">发布文章</el-button>
      </div>
<!--      <el-select v-model="publishStudy.sort" placeholder="请选择" style="margin-top: 10px">-->

<!--      </el-select>-->
        <div ref="editorBox" class="editorBox" style="margin-top: 10px">
          <vue-wangeditor
            ref="editor"
            id="editor"
            v-model="publishStudy.info"
            :menus="menus"
            width="100%"
          />
        </div>

      <el-tag
        style="margin-top: 20px"
      :key="tag"
      v-for="tag in tags"
      closable
      :disable-transitions="false"
        @close="handleClose(tag)"
      >
      {{tag}}
      </el-tag>
      <el-select
        v-model="tags"
        multiple
        collapse-tags
        style="margin-top: 20px"
        placeholder="请选择" v-if="publishSort">
        <el-option
          v-for="item in sortList"
          :key="item.id"
          :label="item.name"
          :value="item.name">
        </el-option>
      </el-select>

      <el-button v-else class="button-new-tag" size="small" @click="showInput" style="margin-top: 20px">选择标签</el-button>
    </el-dialog>

    </div>
  </div>
</template>

<script>
import { addExchange, clockIn, getClockIn, getExchange, getExchangeSort } from '@/api/front/front.js'
import { checkIfUserLoggedIn } from '@/utils/loginCheck.js'
import vueWangeditor from 'vue-wangeditor'
export default {
  name: "front",
  components: {
    vueWangeditor
  },
  data() {
    return {
      form:{
        test:"123"
      },
      testfuwenben: null,
      publishSort: false,
      tags: [],
      menus:[
        'source',	// 源码模式
        '|',
        'bold',	// 粗体
        'underline',	// 下划线
        'italic',	// 斜体
        'strikethrough',	// 中线
        'eraser',	// 清空格式
        'forecolor',	// 文字颜色
        'bgcolor',	// 背景颜色
        'quote',	// 引用
        'fontfamily',	// 字体
        'fontsize',	// 字号
        'head',	// 标题
        'unorderlist',	// 无序列表
        'orderlist',	// 有序列表
        'alignleft',	// 左对齐
        'aligncenter',	// 居中
        'alignright',	// 右对齐
        // '|',
        'link',	// 链接
        'unlink',	// 取消链接
        'table',	// 表格
        'emotion',	// 表情
        // '|',
        'location',	// 位置
        'insertcode',	// 插入代码
        // '|',
        'undo',	// 撤销
        'redo',	// 重做
        'fullscreen'	// 全屏
      ],
      publishStudy: {
        title: '【无标题】',
        sort: null,
        info: '12',
        uid: null,
        tags: null
      },
      //发布弹窗
      publish: false,
      message: '小影教育',
      value: new Date(),
      clockIn: false,
      datesValue: {},
      exchange: {
        id: null
      },
      startDate: null,
      endDate: null,
      test1: ['一分钟前学习了视频','2分钟前学习了视频','3分钟前学习了视频','4分钟前学习了视频','5分钟前学习了视频',],
      user: null,
      isUserLoggedIn: checkIfUserLoggedIn(),
      exchangeList:null,
      sortList:{},
      id: 1 ,
    }
  },
  created() {
    this.checkUser()
    this.getWeekStartEnd(this.getCurrentFormattedDate())
    this.getExchangeMd()
    this.getSort()
  },
  mounted() {
    this.checkUser()
    if (!this.isUserLoggedIn) {
      // 获取到未登录状态, 可以在其他地方做拦截校验
    }

  },
  methods: {
    publishExchange(){
      // for (let i = 0; i < this.tags.length; i++) {
      //   if (this.publishStudy.tags === null){
      //     this.publishStudy.tags = '#'+this.tags[i]
      //   }else {
      //     this.publishStudy.tags = this.publishStudy.tags+'#'+this.tags[i]
      //   }
      // }
      this.publishStudy.uid = this.user.id
      console.log(this.publishStudy)
      addExchange(this.publishStudy).then(res =>{
        if (res.code === 0){
          this.$message({
            type: "success",
            message: "发布成功",
          });
          this.publish = false
          this.tags = []
          this.publishStudy = this.$options.data().publishStudy
        }else {
          this.$message({
            type: "error",
            message: "发布失败",
          });
          this.publish = false
          this.tags = []
          this.publishStudy = this.$options.data().publishStudy
        }
      })
    },
    handleClose(tag) {
      this.tags.splice(this.tags.indexOf(tag), 1);
    },
    showInput(){
      this.publishSort = true;
      // this.$nextTick(_ => {
      //   this.$refs.saveTagInput.$refs.input.focus();
      // });
    },
    //获取帖子分类
    getSort(){
      console.log("分类",this.user)
      getExchangeSort().then(res =>{
        this.sortList = res.data
      })
    },
    //获取帖子列表
    getExchangeMd(){
      getExchange(this.exchange).then(res =>{
        this.exchangeList = res.data
      })
    },
    //打卡方法
    clockInto(){
      //根据时间获取打卡详情
      console.log(this.isUserLoggedIn)
      if (!this.isUserLoggedIn) {
        this.$message.error("当前未登录! 请先登录再进行操作")
        // setTimeout(() => {
        //   this.$router.push("/logined")
        //   console.log("跳转登录页面")
        // }, 1000)
        return
      }
      clockIn(this.user.id).then(res =>{
        if (res.code === 0){
          this.clockIn = true
          this.getWeekStartEnd(this.getCurrentFormattedDate())
        }
      })
    },
    // 获取并格式化当前日期
    getCurrentFormattedDate() {
      const today = new Date();
      const year = today.getFullYear();
      const month = String(today.getMonth() + 1).padStart(2, '0'); // 月份从0开始，所以加1
      const day = String(today.getDate()).padStart(2, '0');
      return `${year}-${month}-${day}`;
    },
    getWeekStartEnd(dateString) {
      let today = new Date(dateString);
      let dayOfWeek = today.getDay(); // 周日为 0, 周一为 1, ..., 周六为 6
      let startOfWeek, endOfWeek;

      // 如果今天是周日，getDay() 返回 0，需要特殊处理
      if (dayOfWeek === 0) {
        startOfWeek = new Date(today);
        startOfWeek.setDate(today.getDate() - 6); // 上周一
        endOfWeek = new Date(today); // 本周日
      } else {
        // 计算周一日期
        startOfWeek = new Date(today);
        startOfWeek.setDate(today.getDate() - (dayOfWeek - 1));

        // 计算周日日期
        endOfWeek = new Date(startOfWeek);
        endOfWeek.setDate(startOfWeek.getDate() + 6);
      }

      // 格式化日期
      let dd = (d) => (`0${d.getDate()}`).slice(-2);
      let mm = (d) => (`0${d.getMonth() + 1}`).slice(-2);
      let yyyy = (d) => d.getFullYear();
      this.startDate = `${yyyy(startOfWeek)}-${mm(startOfWeek)}-${dd(startOfWeek)}`
      this.endDate = `${yyyy(endOfWeek)}-${mm(endOfWeek)}-${dd(endOfWeek)}`
      getClockIn(this.user.id,this.startDate,this.endDate).then(res =>{
        if (res.code === 0){
          this.datesValue = { ...this.datesValue, ...res.data }
          console.log(this.datesValue)
        }
      })
    },
    goToLearningActivities() {
      console.log("学习活动")
    },
    goToLearningMaterials() {
      console.log("学习资料")
    },
    goToLearningExchange() {
      console.log("学习交流")
    },
    goToRegistry() {
      // this.$router.push("/registry")
      // 使用 window.location.href 进行页面重定向
      window.location.href = '/registry';
    },
    goToLogin() {
      this.$router.push("/logined")
    },
    logout() {
      this.$confirm('是否退出登录？', '退出登录').then(() => {
        // 退出登录时清除 localStorage 中的用户信息
        localStorage.removeItem('user');
        this.user = null;
        window.location.reload()
      }).catch(() => {
        // 取消确认，不做任何操作
      })
    },
    checkUser() {
      // 检查 localStorage 中是否有用户信息
      const storedUser = localStorage.getItem('user');
      if (storedUser) {
        // 如果有用户信息，则更新组件的 user 数据
        this.user = JSON.parse(storedUser);
      }
    },
    cancel(){
      this.publish = false
    },
    openCard(val) {
      this.$router.push( { name: 'exchange', params: { id: val }} )
    },
  }
};
</script>

<style>
.myTitle .el-input--medium .el-input__inner {
  border-radius: 15px;
}
.tieziList {
  background-color: #ffffff
}
.tieziList:hover {
  cursor: pointer;
  background-color: #f5f5f6;
}
.infoP {
  margin-left: 20px;
  margin-right: 20px;
  margin-top: -20px;
  color: #6d6e7c;
   /* 定义段落的宽度 */
  display: -webkit-box;
  -webkit-box-orient: vertical;
  -webkit-line-clamp: 2; /* 保留3行文本 */
  overflow: hidden;
  text-overflow: ellipsis;
  line-height: 1.4; /* 可根据需要调整行高 */
  height: calc(1.8em * 2); /* 根据行高和行数计算高度 */
}
@keyframes scroll {
  0% {
    transform: translateY(0);
  }
  100% {
    transform: translateY(-50%);
  }
}
.el-calendar__body {
  padding-bottom: 15px;
}
.el-calendar-table .el-calendar-day {
  height: 65px;
}
.date-active {
  color: green !important;
}
.el-calendar__header {
  display: none;
}

/* 全局样式设置 */
body, html {
  background-color: #e2e1e4;
  height: 100%;
  margin: 0;
  padding: 0;
  font-family: 'Segoe UI', Tahoma, Geneva, Verdana, sans-serif;
}
/* 容器样式，使其小于视口宽度并居中 */
#header {
  display: flex;
  width: 90%;
  height: 70px;
  align-items: center;
  margin: 0 auto;
  padding: 10px 0;
  box-shadow: 0 2px 4px rgba(0, 0, 0, 0.1); /* 简单的阴影效果 */
  justify-content: space-between; /* 左右两部分分别对齐到两边 */
}

/* 左侧头部样式 */
.header-left {
  /* 根据实际内容添加样式 */
  padding: 0 50px; /* 左右内边距 */
  border-color: red;
}

/* 右侧头部样式 */
.header-right {
  padding: 0 50px;
}

/* 去除默认样式 */
a {
  color: inherit;
  text-decoration: none;
}

a:hover, a:active, a:focus {
  text-decoration: none;
}

.header-right a {
  color: #999999;
}

.header-right a:hover {
  color: #272727;
}

#header .header-left button {
  background: none;
  border: none;
  color: #999999;
  font-family: inherit;
  font-size: 1em;
  padding: 0.5em 1em;
  cursor: pointer;
}

#header .header-left button:hover {
  text-decoration: none;
  color: #272727;
}

#studyData {
  display: flex;
  //justify-content: center;
  margin-top: 20px;
  width: 80%;
  /* background-color: aqua; */
}

#app {
  height: 100%;
  display: flex;
  flex-direction: column;
  //background-image: url('../../../assets/images/bc1.jpg');background-size: cover;
  background-attachment: fixed;
}

/* 添加一些响应式设计，当屏幕尺寸减小时，减少容器宽度 */
@media (max-width: 768px) {
  #app > div {
    width: 95%; /* 在小屏幕上容器宽度更大 */
  }
}
</style>
