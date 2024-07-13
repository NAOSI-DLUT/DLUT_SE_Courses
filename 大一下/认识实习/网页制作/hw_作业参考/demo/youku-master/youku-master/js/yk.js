const titles = document.querySelectorAll('.titles a');//标题集合
const imgs = document.querySelectorAll('.imgs a');//图片集合
let curIndex = 0 , timer = null;//当前banner下标，定时器

//移除active格式
function removeActive(){
    titles.forEach(item=>{
        item.classList.remove('active');
    })
    imgs.forEach(item=>{
        item.classList.remove('active');
    })
}

//切换banner
function changeBanner(index){
    removeActive();
    titles[index].classList.add('active');
    imgs[index].classList.add('active');
}

// 自动播放banner
function autoBanner(){
    timer = setInterval(function(){
        curIndex++;
        if(curIndex>titles.length - 1){
            curIndex=0;
        }
        changeBanner(curIndex);
    },3000)
}

//遍历绑定鼠标绑定事件
titles.forEach((item,index)=>{
    // 鼠标移入事件
    item.addEventListener('mouseenter',function(){
        curIndex = index;
        changeBanner(index);
        clearInterval(timer);
    });
    // 鼠标移出事件
    item.addEventListener('mouseleave',function(){
        autoBanner();
    })
})
//初始化自动播放banner
autoBanner();