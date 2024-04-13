<template>
    <div class="home">
        <div class="home-cont">
            <div class="home-cont-left">
                <div class="home-cont-left-top">
                    <img src="https://th.bing.com/th/id/OIP.Zte3ljd4g6kqrWWyg-8fhAHaEo?w=314&h=196&c=7&r=0&o=5&dpr=1.5&pid=1.7"
                        class="home-cont-left-img">
                    <router-link tag="div" to="/list" class="home-icon">
                        <el-icon size="25" color="#9F9D99">
                            <ChatDotSquare />
                        </el-icon>
                    </router-link>

                    <router-link tag="div" to="/add" class="home-icon">
                        <el-icon size="25" color="#9F9D99">
                            <User />
                        </el-icon>
                    </router-link>
                </div>
                <div class="home-cont-left-boom" @click="loginout">
                    <el-icon size="25"><SwitchButton /></el-icon>
                </div>
            </div>
            <div class="home-cont-right">
                <router-view></router-view>
            </div>
        </div>

    </div>
</template>

<script setup>
import router from '../router';


const loginout = () => {
    localStorage.removeItem('user-token');
    router.push('/login');
}

</script>

<style scoped>
.home {
    width: 100vw;
    height: 100vh;
    display: flex;
    justify-content: center;
    align-items: center;
}

.home-cont {
    border-radius: 10px;
    width: 70vw;
    height: 70vh;
    background: #FFFFFF;
    display: flex;
    box-shadow: 0 2px 12px 0 rgba(0, 0, 0, 0.1);
}

.home-cont-left {
    flex: 1;
    border-right: 1px solid #eeeeee;
    background-color: rgb(247, 247, 247);
    display: flex;
    flex-direction: column;
    align-items: center;
    justify-content: space-between;
    padding-bottom: 10px;
}

.home-cont-right {
    flex: 15;
}

.home-cont-left-img {
    border-radius: 5px;
    margin-top: 20px;
    width: 50px;
    height: 50px;
}

.home-cont-left-top {
    display: flex;
    flex-direction: column;
    align-items: center;
    height: 200px;
}

.home-icon {
    margin-top: 20px;
    cursor: pointer;
    flex: 1;
}


.router-link-active i {
        color: blue;
}
</style>