// index.js
// 获取应用实例

var array=[]
var num=""
Page({
  data:{
    array:[1,2,3]
  },
  
  zz(event){
    num=event.detail.value
    console.log("用户输入的是：",num)
  },

  add(){
    var newArray=[]
    newArray=this.data.array
    newArray.push(num)
    this.setData({
      array: newArray
    })
  },
  del(){
    var newArray=[]
    var arr=this.data.array
    for(var i=0;i<arr.length;i++){
      if(arr[i]!=num){
        newArray.push(arr[i])
      }
    }
    this.setData({
      array: newArray
    })
  }
})
