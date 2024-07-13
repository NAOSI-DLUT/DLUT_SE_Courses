/**
 * Created by win on 2017/2/3.
 */
window.addEventListener("DOMContentLoaded",function(){
    //TODO:广告图轮播
    var oBox=document.querySelector(".index_flow_banner");
    var oDiv=document.querySelector(".flow_ban_img");
    var oImg=oBox.querySelectorAll("a");
    var bannerTxt=document.querySelector(".index_banner>p a");
    var oLi=oBox.querySelectorAll("li");

    var step=28;
    var eleN=0;
    var sum=0;
    var num=0;
    var imgIndex=0;
    var dotIndex=0;
    var boo=true;
    oDiv.timer="";
    oBox.timer="";
    var xA= 0,
        xB= 0;
var bTA=["魔兽电影版:史上最丑精灵","西部世界:机器人教你做人","超验骇客:将意识上传","Fate :冷饭大餐来袭","银河系漫游指南:银河旅游","奇异博士:侦探转职法师","fate:麻婆神父专场","黑镜子:迷失在科技中"];
    bannerTxt.innerHTML=bTA[0];

    function noColor(){//清除所有li的class名
        for (var i=0;i<oLi.length;i++){
            if(oLi[i].className=="on")oLi[i].className="";
        }
    }
    function move(width,st){
        num=Math.abs(width/st);
        oDiv.timer=setInterval(function(){
            if(sum>=num){
                clearInterval(oDiv.timer);
                sum=0;
                eleN=0;
                boo=true;
                return false;
            }
            oDiv.style.marginLeft=oDiv.offsetLeft+st+"px";
            sum++;
        },5);
    }
    function autoPlay(){
        oBox.timer=setInterval(function(){
            rightFY();
        },4000);
    }
    autoPlay();
    //鼠标悬停时停止滚动
    oBox.onmousemove=function(){
        clearInterval(oBox.timer);
    };
    oBox.onmouseout=function(){
        autoPlay();
    };

    oBox.addEventListener("touchstart",function(e){
        xA= e.touches[0].clientX;
        clearInterval(oBox.timer);
    },false);
    oBox.addEventListener("touchmove",function(e){
        xB= e.touches[0].clientX;
    },false);
    oBox.addEventListener("touchend",function() {
        ch=0;
        if(xA-xB>100&&xB!=0){
            rightFY();
        }else if(xA-xB<-100&&xB!=0){
            leftFY();
        }
        xB=0;
    },false);
        function rightFY(){//右滑动翻页
        if(boo){
            boo=false;
            if(imgIndex>=oImg.length-1){
                oDiv.style.marginLeft="0px";
                imgIndex=0;
                bannerTxt.innerHTML=bTA[0];
            }
            move(616,-step);
            console.log(imgIndex);
            bannerTxt.innerHTML=bTA[imgIndex+1];
            if(imgIndex==oImg.length-2){
                bannerTxt.innerHTML=bTA[0];
            }
            imgIndex++;
            noColor();
            if(dotIndex>=oLi.length-1)dotIndex=-1;
            oLi[dotIndex+1].className="on";
            dotIndex++;
        }
    }
        function leftFY(){//左滑动翻页
        if(boo){
            boo=false;
            if(imgIndex<=0){
                oDiv.style.marginLeft="-4928px";
                imgIndex=oImg.length-1;
        }
            move(616,step);
            bannerTxt.innerHTML=bTA[imgIndex-1];
            imgIndex--;
            noColor();
            if(dotIndex<=0){
                dotIndex=oLi.length;
            }
            oLi[dotIndex-1].className="on";
            dotIndex--;
        }
    }
    for (var j=0;j<oLi.length;j++){
        oLi[j].index=j;
        oLi[j].onclick=function(){
            change(this.index);
        }
    }
    function change(n){
        if(boo){
            boo=false;
            noColor();
            oLi[n].className="on";
            if(n>dotIndex){
                var width=616*Math.abs(n-dotIndex);
                move(width,-step);
            }else {
                var width=616*Math.abs(n-dotIndex);
                move(width,step);
            }
            imgIndex=dotIndex=n;
            bannerTxt.innerHTML=bTA[imgIndex];

        }
    }
},false);///*结束*/
