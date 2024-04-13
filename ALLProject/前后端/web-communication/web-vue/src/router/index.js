import { createRouter, createWebHistory } from 'vue-router'
const routes = [
    {
        path: "/",
        name: "home",
        component: () => import("../layout/index.vue"),
        children: [
            {
                path: "/list",
                name: "list",
                component: () => import("../views/user/UserList.vue"),
                children: [
                    {
                        path: "/chat",
                        name: "list",
                        component: () => import("../views/chat/chat.vue")
                    }
                ]
            }, {
                path:'/add',
                name:"add",
                component:()=>import("../views/user/userAdd.vue"),
                children:[
                    {
                        path:'/userAdd',
                        name:"userAdd",
                        component:()=>import("../views/user/add.vue"),
                    },
                ]
            },
        ]
    },
    {
        path: "/login",
        name: "login",
        component: () => import("../views/login/Login.vue")
    }
]


// 你可以在这里输入更多的配置，但我们在这里
// 暂时保持简单
const router = createRouter({
    history: createWebHistory(import.meta.env.BASE_URL),
    routes
})

router.beforeEach((to, from, next) => {
    let token = localStorage.getItem("user-token");
    if (to.name !== 'login') {
        if (!token) {
            next({name:"login"})
        } else {
            next()
        }
    } else {
        next()
    }
})

export default router