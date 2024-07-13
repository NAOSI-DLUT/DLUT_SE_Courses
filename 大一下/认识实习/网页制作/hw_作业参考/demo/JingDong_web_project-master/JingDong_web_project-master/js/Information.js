/*导航栏的第一个下拉框开始*/
$(".li1").mouseover(function () {
    $(".Information1").css("display", "block");
    $(".li1").css("background-color", "#fff");
    $(".li1").css("border-left", "1px solid #ccc");
    $(".li1").css("border-right", "1px solid #ccc");
    $(".li1").css("border-bottom", "1px solid #fff");
});
$(".li1").mouseout(function () {
    $(".Information1").mouseover(function () {
        $(".Information1").css("display", "block");
        $(".li1").css("background-color", "#fff");
        $(".li1").css("border-left", "1px solid #ccc");
        $(".li1").css("border-right", "1px solid #ccc");
        $(".li1").css("border-bottom", "1px solid #fff");
    });
    $(".Information1").mouseout(function () {
        $(".Information1").css("display", "none");
        $(".li1").css("background-color", "#e3e4e5");
        $(".li1").css("border-left", "0");
        $(".li1").css("border-right", "0");
        $(".li1").css("border-bottom", "0");
    });
    $(".Information1").css("display", "none");
    $(".li1").css("background-color", "#e3e4e5");
    $(".li1").css("border-left", "0");
    $(".li1").css("border-right", "0");
    $(".li1").css("border-bottom", "0");
});
/*导航栏的第一个下拉框结束*/

/*中间隐藏的类别栏：开始*/
$(".grid-col1>ul>li").each(function (index) {
    var m = index;
    $(this).mouseover(function () {
        $(this).css("background-color","#9c9698");
        $(".grid-col4").css("display","block");
    });
    $(this).mouseout(function () {
        var my = $(this);
        $(".grid-col4").mouseover(function () {
            $(".grid-col1>ul>li").each(function (index) {
                if(index == m){
                    my.css("background-color","#9c9698");
                }else{
                    $(this).css("background-color","#6e6568");
                }
            });
            $(".grid-col4").css("display","block");
        });
        $(".grid-col4").mouseout(function () {
            my.css("background-color","#6e6568");
            $(".grid-col4").css("display","none");
        });
        $(".grid-col4").css("display","none");
        $(this).css("background-color","#6e6568");
    });
});
/*中间隐藏的类别栏：结束*/

/*商品关键字由隐藏到显示：开始*/
var movex;
var movey; //用来接受鼠标位置的全局变量

$(".product1>ul>li>a").each(function (index) {
    var item = $(".product1>#item_Information");
    $(this).mouseover(function () {
        var information = $(this).find("h6").text();
        $(this).find("h6").mouseover(function () {
           $(this).css("color","red");
        });
        $(this).find("h6").mouseout(function () {
           $(this).css("color","#333");
        });
        item.css("display", "block");
        item.css("left", movex);
        item.css("top", movey);
        item.text(information);

    });
    $(this).mouseout(function () {
        item.css("display","none");
        item.text("");
    });
});
/*商品关键字由隐藏到显示：结束*/

/*商品1的列表栏的轮播：开始*/
$(function () {
   var left = $(".product1 .product1_left")[0];
   var right = $(".product1 .product1_right")[0];
   /*animate(left, "left", -1192);//-1192
   animate(right, "left", -4);//-4*/
   var left_current_x = -1192;
   var right_current_x = -4;
   animate(left, "left", left_current_x);
   animate(right, "left", right_current_x);
});
/*获得css样式的值*/
function getStyle(element, attr) {
    return window.getComputedStyle ? window.getComputedStyle(element, null)[attr]
        : element.currentStyle[attr];
}

function animate(element, attr, target) {  /*target是从开始到这个位置的移动*/
    clearInterval(element.timeId);
    element.timeId = setInterval(function () {
        var current = parseInt(getStyle(element, attr));
        var step = 2;
        step = target > current ? step : -step;

        if(!(movex>=0 && movex<=1188 && movey>=0 && movey<=260)){
            current +=step;
        }

        if(Math.abs(current - target) > Math.abs(step)) {
            element.style[attr] = current + "px";
        } else {
            if(target==-1192){
                target = -4;
                element.style[attr] = "1188px";
            }else{
               target = -1192;
               element.style[attr] = "0px";
            }
        }
    }, 20)
}
/*商品1的列表栏的轮播：结束*/