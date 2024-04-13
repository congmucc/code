// 外部引用js文件
// alert 是弹窗输出
// alert("我是外部引用的js文件");

var str = "hello";
var Str = " world";
var num = 100;
console.log(str + Str);
console.log(num);
console.log(typeof (str));
console.log(typeof (num));
var bol = 5 > 2;
console.log(bol);
console.log(typeof (bol));
var k, j = null;
console.log(k);
console.log(typeof (k));
console.log(j);
console.log(typeof (j));
// 双等于是仅仅结果，三等于是类型也需要等于 k没有赋值，所以undefine == null
console.log(k == j);
console.log(k === j);

var score = 83;
// if (score >= 90) alert("优秀");
// else if (score >= 80 && score < 90) alert("良好");
// else if (score >= 70 && score < 80) alert("一般");
// else if (score >= 60 && score < 70) alert("通过");
// else if (score < 60) alert("不及格");

switch(parseInt(score / 10)) {
    case 9 : console.log("优秀"); break;
    case 8 : console.log("良好"); break;
    case 7 : console.log("一般"); break;
    case 6 : console.log("通过"); break;
    default: console.log("不及格");
}



function Welcome(welcome) {
    alert(welcome);
}

function sumNumber(lVaule) {
    //通过id获取元素的值
    lVaule = document.getElementById('one').value;
    var i = 0, sum = 0;
    while(i < lVaule) {
        i ++;
        sum += i;
    }
    console.log("前" + lVaule + "个数字之和是：" + sum);
}

function userF() {
    var myform = document.getElementById("form1");
    var userValue = document.getElementById('user').value;
    var userPasswordValue = document.getElementById('userPassword').value;
    console.log("账号：" + userValue + "\n" + "密码：" + userPasswordValue);
    //使用这个的时候需要input的类型是submit
    if(userValue == "admin" && userPasswordValue == "123456") {
        alert("登陆成功");
        myform.action = "https://cn.bing.com/";
    } else {
        alert("登陆失败");
    }
    
}



//通过id获取元素 innerHTML是可以得到元素的文字
// var hElement = document.getElementById("h");
//     alert(hElement);

//通过标签获取元素
var pElement = document.getElementsByTagName('p');

console.log(pElement);


//innerHTML需要到html中的内部script中进行使用
// //通过选择器直接获取元素  加个all是选取所有元素，返回一个列表
// var ulElement = document.querySelector("#ulNode>li:nth-child(2)");

// ulElement.innerHTML="跳舞";

// //只有id 和querySelector这两个是获取单个元素，其他的获取多个元素
