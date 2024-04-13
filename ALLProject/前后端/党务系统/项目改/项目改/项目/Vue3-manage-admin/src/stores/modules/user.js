import { defineStore } from 'pinia'
import { ref, computed } from 'vue'
import { userGetInforService, getStudentByid } from '../../api/user'
import jwtDecode from 'jwt-decode'

//用户模块 token setToken removeToken
export const useUserStore = defineStore(
  'userlist',
  () => {
    const userRole = ref('')
    const token = ref('')
    const removeToken = () => {
      token.value = ''
      user.value.id = ''
      user.value.jwt = ''
      user.value.email = ''
      user.value.name = ''
    }

    const user = ref({})
    const getUser = async () => {
      //console.log('调用')
      const res = await userGetInforService(user.value.username)
      user.value = res.data.data
    }
    const getStudent = async () => {
      //console.log('调用')
      const res = await getStudentByid(user.value.username)
      user.value = res.data.data
    }
    const setUser = (obj) => {
      user.value = obj
      token.value = obj.jwt
    }
    const checked = ref('')
    const setJzw = (obj) => {
      checked.value = obj.checked
    }
    //token是否过期
    const isTokenExpired = computed(() => {
      if (token.value) {
        try {
          const decodedToken = jwtDecode(token.value)
          const currentTime = Date.now() / 1000 // Convert to seconds
          return decodedToken.exp < currentTime
        } catch (error) {
          // Handle any potential errors in decoding
          return true
        }
      }
      return true
    })

    const clearUser = () => {
      user.value = {}
    }

    const getPassword = () => {
      return user.value.password
    }

    return {
      checked,
      setJzw,
      userRole,
      token,
      removeToken,
      isTokenExpired,
      user,
      getUser,
      getStudent,
      setUser,
      clearUser,
      getPassword
    }
  },

  {
    persist: true
  }
)
