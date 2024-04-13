// TODO：完善此函数 显示红色颜色的灯
function red() {
    document.querySelector("#redlight").style.display = "inline-block";
}

// TODO：完善此函数  显示绿色颜色的灯
function green() {
    document.querySelector("#greenlight").style.display = "inline-block";
}

// TODO：完善此函数
function trafficlights() {
    function otherhide() {
        var imgs = document.querySelectorAll("#container>img");
        for (let index = 0; index < imgs.length; index++) {
            imgs[index].style.display = "none";
        }
    }
    setTimeout(function(){
        otherhide();
        red();
        setTimeout(function() {
            otherhide();
            green();
        }, 3000)
    }, 3000);
}

trafficlights();

