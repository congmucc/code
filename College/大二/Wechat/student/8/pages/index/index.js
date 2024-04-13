// index.js
var a=null;
var b=null;
var jieguo=null;
Page({

    numberFirst(event){
    a=event.detail.value
    console.log("第一个数",a)

    },
    numberSecond(event){
        b=event.detail.value
        console.log("第二个数",b)
    },
    qiuhe(){
                jieguo=Number(a)+Number(b)
                this.setData({
                    sum:jieguo
                })
    }
        
})
