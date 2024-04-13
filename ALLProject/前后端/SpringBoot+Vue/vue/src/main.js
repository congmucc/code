import Vue from 'vue'
import App from './App.vue'
import router from './router'
// 导入elementui
import ElementUI from 'element-ui';
import 'element-ui/lib/theme-chalk/index.css';
import './assets/global.css';
import request from '@/utils/request';
import store from './store';


// 导入element-ui插件
Vue.use(ElementUI, {size: "small"});
Vue.prototype.request = request


Vue.config.productionTip = false

new Vue({
  router,
  store,
  render: h => h(App)
}).$mount('#app')
