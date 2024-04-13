<template>
  <div class="home">
    <el-container style="min-height: 100vh">
      <el-aside :width="sideWidth + 'px'" style="background-color: rgb(238, 241, 246)">
        <Aside :isCollapse="isCollapse" :logoTextShow="logoTextShow" />
      </el-aside>

      <el-container>
        <el-header>
          <Header :collapseBtnClass="collapseBtnClass" :collapse="collapse" />
        </el-header>

        <el-main>
          <!-- 当前页面的子路由会在router-view中展示 -->
          <router-view />
        </el-main>
      </el-container>
    </el-container>
  </div>
</template>

<script>
import Aside from "@/components/Aside.vue";
import Header from '@/components/Header.vue';


export default {
  name: "Manage",
  components: {
    Aside,
    Header,
  },

  data() {
    return {
      collapseBtnClass: "el-icon-s-fold",
      isCollapse: false,
      sideWidth: 200,
      logoTextShow: true,
    };
  },
  methods: {
    collapse() {
      this.isCollapse = !this.isCollapse;
      if (this.isCollapse) {
        // 收缩
        (this.sideWidth = 64),
          (this.collapseBtnClass = "el-icon-s-unfold"),
          (this.logoTextShow = false);
      } else {
        // 展开
        (this.sideWidth = 200),
          (this.collapseBtnClass = "el-icon-s-fold"),
          (this.logoTextShow = true);
      }
    },

  },
};
</script>


<style>
.el-header {
  background-color: #eee;
  color: #333;
  line-height: 60px;
}

.el-aside {
  color: #333;
}
</style>