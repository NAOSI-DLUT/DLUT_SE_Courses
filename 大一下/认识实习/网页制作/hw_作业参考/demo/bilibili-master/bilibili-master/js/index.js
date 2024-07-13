! function(window, document, $, undefined) {

	function getId(id) {
		return typeof id == 'string' ? document.getElementById(id) : id;
	}


	function getByClass(obj, cls) {
		var reArr = [],
			els = obj.getElementsByTagName('*');

		for (var i = 0, len = els.length; i < len; i++) {
			if (els[i].className === cls || els[i].className.indexOf(cls + ' ') >= 0 || els[i].className.indexOf(' ' + cls + ' ') >= 0 || els[i].className.indexOf(' ' + cls) >= 0) {
				reArr.push(els[i]);
			}
		}

		return reArr;
	}

	function getStyle(obj, attrname) {
		if (obj.currentStyle) {
			return obj.currentStyle[attrname];
		} else {
			return getComputedStyle(obj, false)[attrname];
		}
	}



	var rContainer = getId('rContainer'),
		imgBox = getId('imgBox'),
		imgs = imgBox.getElementsByTagName('img'),
		btnBox = getId('btnBox'),
		btnLis = btnBox.getElementsByTagName('li'),
		prevWp = getId('prev_btn'),
		nextWp = getId('next_btn'),
		rTxt = getId('rTxt'),
		rSpan = rTxt.getElementsByTagName('span'),
		index = 0,
		timer1,
		animated = false,

		now = 0,
		sItems = getId('sItems'),
		sUl = sItems.getElementsByTagName('ul'),
		prevBtn = getId('prevBtn'),
		nextBtn = getId('nextBtn'),

		historySearch = getId('historySearch'),
		historyUl = historySearch.getElementsByTagName('ul')[0],
		inputWp = getId('inputWp'),

		proItems = getId('proItems'),
		proDts = proItems.getElementsByTagName('dt'),

		rankTitle = getId('rankTitle'),
		rankLis = rankTitle.getElementsByTagName('li'),
		rankItems = getId('rankItems'),
		index2 = 0,

		recomTop = getId('recomTop'),
		recomBtn = getId('recomBtn'),
		recomLis = recomBtn.getElementsByTagName('li'),
		imgBox2 = getId('imgBox2'),
		recom_Mask = getId('recom_Mask'),
		recom_as = recom_Mask.getElementsByTagName('a'),
		timer2,
		index3 = 0,

		cartoonTab = getId('cartoonTab'),
		cartoonLis = cartoonTab.getElementsByTagName('li'),
		cartoonCon = getId('cartoonCon'),
		cartoonConUls = cartoonCon.getElementsByTagName('ul'),
		index4 = 0,

		carankTab = getId('carankTab'),
		caranktabLis = carankTab.getElementsByTagName('li'),
		ctrankCon = getId('ctrankCon'),
		ctrankUls = ctrankCon.getElementsByTagName('ul'),
		rankTime = getId('rankTime'),
		rankTimeOl = rankTime.getElementsByTagName('ol')[0],
		fLi = rankTimeOl.children[0],
		sLi = rankTimeOl.children[1],
		rankTimeLis = rankTime.getElementsByTagName('li'),
		index5 = 0,

		funTab = getId('funTab'),
		funtabLis = funTab.getElementsByTagName('li'),
		funCon = getId('funCon'),
		funConUls = funCon.getElementsByTagName('ul'),
		index6 = 0,

		fr_RightCon = getId('fr_RightCon'),
		frconSpan = fr_RightCon.getElementsByTagName('span')[0],
		fr_rightconUl = fr_RightCon.getElementsByTagName('ul')[0],
		fr_rightconLis = fr_rightconUl.getElementsByTagName('li'),

		sidemenuBar = getId('sidemenuBar'),
		topArrow = getId('topArrow'),
		barList = getId('barList'),
		barListas = barList.getElementsByTagName('a'),
		timer3 = null,

		dialog = getId('dialog'),
		dialog_bar = getId('dialog_bar'),
		distX = 0,
		distY = 0,
		switchUser = getId('switchUser'),
		switchMask = getId('switchMask'),

		textInput = getId('textInput'),
		pswdInput = getId('pswdInput'),
		userCheck = getId('userCheck'),
		pswdCheck = getId('pswdCheck'),
		login = getId('login');

	// 主导航左轮播
	imgBox.style.width = imgs.length * 440 + 'px';

	for (var i = 0; i < btnLis.length; i++) {
		btnLis[i].index = i;
		btnLis[i].onclick = function() {
			if (this.className == 'on') {
				return;
			}

			if (!animated) {
				var step = -440 * (this.index - index);
				index = this.index;
				action(step);
				active();
			}
		}
	}

	function active() {
		for (var i = 0; i < btnLis.length; i++) {
			if (btnLis[i].className == 'on') {
				btnLis[i].className = '';
				break;
			}
		}
		btnLis[index].className = 'on';
	}


	function action(step) {
		animated = true; //true表示图片正在切换的这个过程中，若再点击箭头按钮和小圆点按钮时不会产生切换，不会发生任何作用！即图片还在滚动的情况下，点击的话就不做任何处理
		var newLeft = parseInt(imgBox.style.left) + step;
		var alltime = 200; //位移总时间
		var interval = 20; //每次位移的间隔时间
		var speed = step / (alltime / interval); //每次位移量

		function go() {
			if (speed < 0 && parseInt(imgBox.style.left) > newLeft || speed > 0 && parseInt(imgBox.style.left) < newLeft) {
				imgBox.style.left = parseInt(imgBox.style.left) + speed + 'px';
				setTimeout(go, interval);
			} else {
				animated = false; //达到目标值（newLeft）了。只有当animated等于false时，点击下一次才会起作用；
				imgBox.style.left = newLeft + 'px';
				if (newLeft > -440) {
					imgBox.style.left = -2200 + 'px';
				}

				if (newLeft < -2200) {
					imgBox.style.left = -440 + 'px';
				}
			}
		}
		go();

	}

	prevWp.onclick = function() {
		if (!animated) {
			if (index == 0) {
				index = btnLis.length - 1;
			} else {
				index--;
			}
			active();
			action(440);
			showtxt();
		}
	}

	nextWp.onclick = function() {
		if (!animated) {
			if (index == btnLis.length - 1) {
				index = 0;
			} else {
				index++;
			}
			active();
			action(-440);
			showtxt();
		}

	}

	timer1 = setInterval(nextWp.onclick, 2000);

	rContainer.onmouseover = function() {
		clearInterval(timer1);
	}

	rContainer.onmouseout = function() {
		timer1 = setInterval(nextWp.onclick, 2000);
	}

	function showtxt() {
		for (var i = 0; i < rSpan.length; i++) {
			rSpan[i].className = '';
		}
		rSpan[index].className = 'show';
	}



	// 主导航右轮播
	prevBtn.onclick = function() {
		now--;
		if (now < 0) {
			now = 2;
		}
		changeTxt();
		visiUl();
	}


	nextBtn.onclick = function() {
		now++;
		if (now > sUl.length - 1) {
			now = 0;
		}
		changeTxt();
		visiUl();
	}

	function visiUl() {
		for (var i = 0; i < sUl.length; i++) {
			sUl[i].className = 'clearfix';
		}
		sUl[now].className = 'visible clearfix';
	}

	function changeTxt() {
		if (now == 1) {
			nextBtn.innerHTML = '昨<br>日';
			prevBtn.innerHTML = '三<br>日';
		} else if (now == 2) {
			nextBtn.innerHTML = '三<br>日';
			prevBtn.innerHTML = '一<br>周';
		} else {
			nextBtn.innerHTML = '一<br>周';
			prevBtn.innerHTML = '昨<br>日';
		}
	}


	// 历史搜索框

	inputWp.onfocus = function() {
		historySearch.style.display = 'block';
	}

	inputWp.onblur = function() {
		historySearch.style.display = 'none';
	}

	var data = ['女流66', '陈一发儿', '大司马']; //模拟数据

	for (var i = 0; i < data.length; i++) {
		historyUl.innerHTML += '<li><a href="###">' + data[i] + '</a></li>';
	}


	// 推广块鼠标hover弹幕滑出

	for (var i = 0; i < proDts.length; i++) {

		proDts[i].onmouseover = function() {

			var proDivs = this.getElementsByTagName('div');
			for (var i = 0; i < proDivs.length; i++) {
				var lw = -(proDivs[i].offsetWidth + 180) + 'px';
				proDivs[i].style.transform = 'translateX(' + 　lw + ')'
			}
		}

		proDts[i].onmouseout = function() {

			var proDivs = this.getElementsByTagName('div');
			for (var i = 0; i < proDivs.length; i++) {
				proDivs[i].style.transform = 'translateX(0)'
			}
		}
	}


	// 直播排行标题块点击切换
	for (var i = 0; i < rankLis.length; i++) {
		rankLis[i].index = i;
		rankLis[i].onclick = function() {
			for (var i = 0; i < rankLis.length; i++) {
				rankLis[i].className = '';
			}
			rankLis[this.index].className = 'clk';

			var toleft = -260 * (this.index - index2);
			rankItems.style.left = toleft + 'px';
		}
	}


	// 正在直播-为你推荐块鼠标hover小按钮
	for (var i = 0; i < recomLis.length; i++) {
		recomLis[i].index = i;
		recomLis[i].onmouseover = function() {

			if (this.className == 'mhover') {
				return;
			}
			// if (index3 >= recomLis.length - 1) {
			// 	index3 = 0;
			// }   

			var step = -260 * (this.index);
			imgBox2.style.left = step + 'px';
			index3 = this.index;

			recomlisOn();
			recomasOn();

		}
	}

	function recomasOn() {
		for (var i = 0; i < recom_as.length; i++) {
			recom_as[i].style.display = 'none';
		}
		recom_as[index3].style.display = 'inline-block';
	}

	function recomlisOn() {
		for (var i = 0; i < recomLis.length; i++) {
			recomLis[i].className = '';
		}
		recomLis[index3].className = 'mhover';
	}

	function autoPlay2() {
		timer2 = setInterval(function() {
			index3++;
			if (index3 > recomLis.length - 1) {
				index3 = 0;
			}
			recomlisOn();
			recomasOn();
			// recomLis[this].onmouseover();
			imgBox2.style.left = -260 * index3 + 'px';

		}, 1000);
	}
	autoPlay2();

	recomTop.onmouseover = function() {
		clearInterval(timer2);
	}

	recomTop.onmouseout = function() {
		autoPlay2();
	}


	// 动画左边tab切换
	for (var i = 0; i < cartoonLis.length; i++) {
		cartoonLis[i].index = i;
		cartoonLis[i].onclick = function() {
			if (this.className == 'clk') {
				return;
			}

			for (var i = 0; i < cartoonLis.length; i++) {
				cartoonLis[i].className = '';
			}
			this.className = 'clk';
			index4 = this.index;

			for (var i = 0; i < cartoonConUls.length; i++) {
				cartoonConUls[i].className = '';
			}
			cartoonConUls[index4].className = 'visible';
		}
	}


	// 动画右边tab切换
	for (var i = 0; i < caranktabLis.length; i++) {
		caranktabLis[i].index = i;
		caranktabLis[i].onmouseover = function() {
			for (var i = 0; i < caranktabLis.length; i++) {
				caranktabLis[i].className = '';
			}
			this.className = 'mhover';
			index5 = this.index;

			for (var i = 0; i < ctrankUls.length; i++) {
				ctrankUls[i].className = '';
			}
			ctrankUls[index5].className = 'active';
		}
	}

	// 三日&&一周小tab切换
	for (var i = 0; i < rankTimeLis.length; i++) {
		rankTimeLis[i].onclick = function() {
			if (this.innerHTML == '一周') {
				fLi.innerHTML = '一周';
				sLi.innerHTML = '三日';
			} else if (this.innerHTML == '三日') {
				fLi.innerHTML = '三日';
				sLi.innerHTML = '一周';
			}

			rankTime.style.height = '25px';
			rankTime.style.lineHeight = '25px';
		}
	}

	rankTime.onmouseover = function() {
		this.style.height = '50px';
		this.style.lineHeight = '50px';
	}

	rankTime.onmouseout = function() {
		this.style.height = '25px';
		this.style.lineHeight = '25px';
	}

	// 番剧周一至周五tab切换
	for (var i = 0; i < funtabLis.length; i++) {
		funtabLis[i].index = i;
		funtabLis[i].onclick = function() {
			for (var i = 0; i < funtabLis.length; i++) {
				funtabLis[i].className = '';
			}
			this.className = 'clk';
			index6 = this.index;

			for (var i = 0; i < funConUls.length; i++) {
				funConUls[i].style.display = 'none';
			}
			funConUls[index6].style.display = 'block';
		}
	}

	// 番剧排行三日&&一周tab切换
	fr_RightCon.onmouseover = function() {
		fr_rightconUl.style.display = 'block';
		fr_rightconUl.style.boxShadow = '0 2px 4px rgba(0,0,0,0.16)';
		this.onclick = function() {
			if (fr_rightconUl.style.display == 'block') {
				fr_rightconUl.style.display = 'none';
			}
		}
	}

	fr_RightCon.onmouseout = function() {
		fr_rightconUl.style.display = 'none';
	}

	for (var i = 0; i < fr_rightconLis.length; i++) {
		fr_rightconLis[i].onclick = function() {
			for (var i = 0; i < fr_rightconLis.length; i++) {
				fr_rightconLis[i].className = '';
			}
			this.className = 'hide';

			fr_rightconUl.style.display = 'none';
			frconSpan.innerHTML = this.innerHTML;
		}
	}

	// 侧边导航条滚动
	function hasClass(obj, cls) {
		return obj.className.match(new RegExp("(\\s|^)" + cls + "(\\s|$)"));
	}

	function removeClass(obj, cls) {
		if (hasClass(obj, cls)) {
			var reg = new RegExp("(\\s|^)" + cls + "(\\s|$)");
			obj.className = obj.className.replace(reg, '');
		}
	}

	function addClass(obj, cls) {
		if (!hasClass(obj, cls)) {
			obj.className += ' ' + cls;
		}
	}

	window.onscroll = function() {
		var scrollTopVal = document.documentElement.scrollTop || document.body.scrollTop,
			mainCon = getId('mainCon'),
			items = getByClass(mainCon, 'conbox'),
			len = items.length,
			link_len = barListas.length,
			currentId = '';

		for (var i = 0; i < len; i++) {
			var offsetTop = items[i].offsetTop;
			if (scrollTopVal > offsetTop - 300) {
				currentId = items[i].id;
			} else {
				break;
			}
		}

		if (currentId) {
			for (var j = 0; j < link_len; j++) {
				var hrefId = barListas[j].getAttribute("href");
				if (hrefId != ('#' + currentId)) {
					removeClass(barListas[j], 'on');
				} else {
					addClass(barListas[j], 'on');
				}
			}
		}


		if (scrollTopVal >= 500) {
			sidemenuBar.style.top = 180 + 'px';
		} else {
			sidemenuBar.style.top = 510 + 'px';
		}
	}

	for (var i = 0; i < barListas.length; i++) {
		barListas[i].onclick = function() {
			for (var i = 0; i < barListas.length; i++) {
				barListas[i].className = '';
			}
			this.className = 'on';
		}
	}

	topArrow.onclick = function() {
		runner();
	}

	function runner() {
		clearInterval(timer3);
		timer3 = setInterval(function() {
			var scrollT = document.documentElement.scrollTop || document.body.scrollTop,
				step = Math.floor(-scrollT / 5);

			if (scrollT == 0) {
				clearInterval(timer3);
			} else {
				document.documentElement.scrollTop = document.body.scrollTop = scrollT + step;
				// console.log(scrollT + step);
			}
		}, 30)

	}

	//点击弹出遮罩层和登录对话框
	switchUser.onclick = function() {
		dialog.style.display = 'block';
		switchMask.style.display = 'block';
		autoCenter(dialog);
	}

	switchMask.onclick = function() {
		dialog.style.display = 'none';
		switchMask.style.display = 'none';
	}


	//切换用户对话框以及遮罩层
	function autoCenter(obj) {
		var winWidth = document.documentElement.clientWidth || document.body.clientWidth,
			winHeight = document.documentElement.clientHeight || document.body.clientHeight,
			objWidth = obj.offsetWidth,
			objHeight = obj.offsetHeight;

		obj.style.left = (winWidth - objWidth) / 2 + 'px';
		obj.style.top = (winHeight - objHeight) / 2 + 'px';
	}

	autoCenter(dialog);

	window.onresize = function() {
		autoCenter(dialog);
	}

	dialog_bar.onmousedown = function(e) {
		var evt = e || window.event;
		distX = evt.clientX - dialog.offsetLeft; //获取边界到鼠标的距离  
		distY = evt.clientY - dialog.offsetTop;

		document.onmousemove = function(e) {
			var evt = e || window.event,
				winWidth = document.documentElement.clientWidth || document.body.clientWidth,
				winHeight = document.documentElement.clientHeight || document.body.clientHeight,
				x = evt.clientX - distX,
				y = evt.clientY - distY;

			document.onselectstart = function() {
				return false;
			}


			x = Math.min(winWidth - dialog.offsetWidth, Math.max(0, x));
			y = Math.min(winHeight - dialog.offsetHeight, Math.max(0, y));

			dialog.style.left = x + 'px';
			dialog.style.top = y + 'px';
		}

		document.onmouseup = function() {
			document.onmousemove = null;
			document.onmouseup = null;
		}
	}

	//登录对话框表单验证

	textInput.onfocus = function() {
		userCheck.style.display = 'none';
	}

	pswdInput.onfocus = function() {
		pswdCheck.style.display = 'none';
	}

	textInput.onblur = function() {
		var txt = this.value;
		if (txt == '') {
			userCheck.style.display = 'block';
			userCheck.innerHTML = '您的用户名不能为空!';
			return;
		}
	}

	pswdInput.onblur = function() {
		var txt = this.value;
		if (txt == '') {
			pswdCheck.style.display = 'block';
			pswdCheck.innerHTML = '您的密码不能为空!';
			return;
		}
	}

	login.onclick = function() {
		textInput.onblur();
		pswdInput.onblur();
	}


}(window, document, jQuery)