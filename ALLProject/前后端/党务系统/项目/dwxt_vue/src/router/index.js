import { createRouter, createWebHistory } from 'vue-router'
import { useUserStore } from '@/stores'
import { ElMessage } from 'element-plus'
//createRouter创建路由事例
//history模式（地址栏不带井号）web  hash模式webhash
//console.log(import.meta.env.DEV)
const router = createRouter({
  //vite中环境变量
  history: createWebHistory(import.meta.env.BASE_URL),
  routes: [
    {
      path: '/student/login',
      component: () => import('@/views/student/login/LoginPage.vue')
    },
    {
      path: '/teacher/login',
      component: () => import('@/views/teacher/login/LoginPage.vue')
    },
    {
      path: '/teacher',
      component: () => import('@/views/teacher/layout/LayoutContainer.vue'),
      redirect: '/home',
      children: [
        {
          path: '/person/account',
          component: () => import('@/views/teacher/person/PersonAccount.vue')
        },
        {
          path: '/person/information',
          component: () =>
            import('@/views/teacher/person/PersonInformation.vue')
        },
        {
          path: '/home',
          component: () => import('@/views/teacher/person/PersonHome.vue')
        },
        {
          path: '/user/profile',
          component: () => import('@/views/teacher/user/UserProfile.vue')
        },
        {
          path: '/user/password',
          component: () => import('@/views/teacher/user/UserPassword.vue')
        }
      ]
    },
    {
      path: '/student',
      component: () => import('@/views/student/layout/LayoutContainer.vue'),
      redirect: '/studentHome',
      children: [
        {
          path: '/studentHome',
          component: () => import('@/views/student/person/PersonHome.vue')
        },
        {
          path: '/student/information',
          component: () =>
            import('@/views/student/person/PersonInformation.vue')
        },
        {
          path: '/student/profile',
          component: () => import('@/views/student/user/UserProfile.vue')
        },
        {
          path: '/student/password',
          component: () => import('@/views/student/user/UserPassword.vue')
        }
      ]
    }
  ]
})
// 路由守卫
router.beforeEach((to) => {
  const useStore = useUserStore()
  if (to.path === '/') {
    useStore.removeToken()
    useStore.clearUser()
    if (useStore.userRole == 1) {
      return '/teacher/login'
    } else {
      return '/student/login'
    }
  }
  if (useStore.token != '' && useStore.isTokenExpired) {
    useStore.removeToken()
    useStore.clearUser()
    if (useStore.userRole == 1) {
      if (to.path !== '/teacher/login') {
        ElMessage.warning('登录验证过期，请重新登录')
        return '/teacher/login'
      }
    } else {
      if (to.path !== '/student/login') {
        ElMessage.warning('登录验证过期，请重新登录')
        return '/student/login'
      }
    }
  }
  if (useStore.userRole == 1) {
    if (!useStore.token && to.path !== '/teacher/login') {
      useStore.clearUser()
      return '/teacher/login'
    }
  } else {
    if (!useStore.token && to.path !== '/student/login') {
      useStore.clearUser()
      return '/student/login'
    }
  }

  if (
    useStore.userRole === '0' &&
    (to.path == '/person/account' ||
      to.path == '/person/information' ||
      to.path == '/home' ||
      to.path == '/user/profile' ||
      to.path == '/user/password')
  ) {
    return '/student/login'
  }

  if (useStore.token != '' && useStore.getPassword() == '123456') {
    if (useStore.userRole == 1) {
      if (to.path !== '/user/password') {
        ElMessage.warning('密码安全性太低，请先重置您的密码')
        return '/user/password'
      }
    } else {
      if (to.path !== '/student/password') {
        ElMessage.warning('密码安全性太低，请先重置您的密码')
        return '/student/password'
      }
    }
  }
})

export default router
