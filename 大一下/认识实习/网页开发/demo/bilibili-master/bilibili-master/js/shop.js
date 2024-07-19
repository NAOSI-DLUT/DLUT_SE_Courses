! function(window, document, $, undefined) {
	function getById(id) {
		return typeof id == 'string' ? document.getElementById(id) : id;
	}

	function getStyle(obj, attr) {
		if (obj.currentStyle) {
			return obj.currentStyle[attr];
		} else {
			return getComputedStyle(obj, false)[attr];
		}
	}

	var bannerBox = getById('bannerBox'),
		bannerUl = bannerBox.getElementsByTagName('ul')[0],
		ban_ul_lis = bannerUl.getElementsByTagName('li'),
		bannerOl = bannerBox.getElementsByTagName('ol')[0],
		ban_ol_lis = bannerOl.getElementsByTagName('li'),
		now = 0,
		timer,
		timer2,

		toTop = getById('toTop'),
		timer3;


	//banner轮播
	function active() {
		for (var i = 0; i < ban_ol_lis.length; i++) {
			ban_ol_lis[i].className = '';
		}
		ban_ol_lis[now].className = 'active';
	}

	function action(finish) {
		clearInterval(timer);
		timer = setInterval(function() {
			var leftVal = parseInt(getStyle(bannerUl, 'left'));
			var step = (finish - leftVal) / 6;
			step = step > 0 ? Math.ceil(step) : Math.floor(step);
			if (leftVal == finish) {
				clearInterval(timer);
			} else {
				bannerUl.style.left = leftVal + step + 'px';
			}
		}, 20)
	}

	function autoRun() {
		now++;
		if (now > ban_ol_lis.length - 1) {
			now = 0;
		}
		var winWidth = document.documentElement.clientWidth || document.body.clientWidth,
			finish = -winWidth * (now);
		active();
		action(finish);
	}

	timer2 = setInterval(autoRun, 3000);

	bannerBox.onmouseover = function() {
		clearInterval(timer2);
	}
	bannerBox.onmouseout = function() {
		timer2 = setInterval(autoRun, 3000);
	}

	for (var i = 0; i < ban_ol_lis.length; i++) {
		ban_ol_lis[i].index = i;
		ban_ol_lis[i].onclick = function() {
			if (this.className == 'active') {
				return;
			}
			var winWidth = document.documentElement.clientWidth || document.body.clientWidth,
				finish = -winWidth * (this.index);
			now = this.index;
			active();
			action(finish);
		}
	}

	//返回顶部

	toTop.onclick = function() {
		scrollTop();
	}

	function scrollTop() {
		clearInterval(timer3);
		timer3 = setInterval(function() {
			var scrollT = document.documentElement.scrollTop || document.body.scrollTop,
				step = Math.floor(-scrollT / 8);

			if (scrollT == 0) {
				clearInterval(timer3);
			}else{
				document.documentElement.scrollTop = document.body.scrollTop = scrollT + step;
				// console.log(scrollT + step);
			}
		}, 30)
	}

}(window, document, jQuery)