// index.js
// 获取应用实例
const app = getApp()
var a =null
var b=null
var jieguo=null
Page({
  
    getFirstnumber(number1){
     a=number1.detail.value
     console.log("第一个数是：",a)
    },
    getScondnumber(number2){
      b=number2.detail.value
      console.log("第二个数是：",b)
    },
    nume(){
      jieguo=Number(a)+Number(b)
      this.setData({
        sum:jieguo
      })
    }
})
