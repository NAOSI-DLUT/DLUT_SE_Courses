! function(window, document, $, undefined) {
	// 通过ID获取元素
	function getById(id) {
		return typeof id == 'string' ? document.getElementById(id) : id;
	}

	// 通过Class获取元素
	function getByClass(obj, cls){
		var result = [],
			els = obj.getElementsByTagName('*');
		for (var i = 0; i < els.length; i++) {
			if (els[i].className == cls || els[i].className.indexOf(' '+cls)>=0 ||els[i].className.indexOf(' '+cls+' ')>=0 ||els[i].className.indexOf(cls+ ' ')>=0) {
				result.push(els[i])
			}
		}
		return result;
	}

	// 获取样式
	function getStyle(obj, attr) {
		if (obj.currentStyle) {
			return obj.currentStyle[attr];
		}else{
			return getComputedStyle(obj,false)[attr];
		}
	}

	//删除节点
	function removeNode(node){
		return node.parentNode.removeChild(node);
	}

	// 获取当前元素的同胞元素
	function getSiblings(node) {
		var sibs = [],
			childs = node.parentNode.children;
		for (var i = 0; i < childs.length; i++) {
			if (childs[i] !== node) {
				sibs.push(childs[i]);
			}
		}
		return sibs;
	}

	// 图片点击预览

	var smallView = getById('smallView'),
		small_Lis = smallView.getElementsByTagName('li'),
		bigView = getById('bigView'),
		big_Items = bigView.getElementsByTagName('div'),
		floatBox = getById('floatBox'),
		productPreview = getById('productPreview');

	for (var i = 0; i < small_Lis.length; i++) {
		small_Lis[i].index = i;
		small_Lis[i].onclick = function() {
			for (var i = 0; i < big_Items.length; i++) {
				big_Items[i].style.display = 'none';
			}
			big_Items[this.index].style.display = 'block';
			for (var i = 0; i < small_Lis.length; i++) {
				small_Lis[i].className = 'sm'+(i+1);
			}
			this.className += ' on'; 
		}
	}

	// 浮块显示
	bigView.onmouseover = function() {
		floatBox.style.display = 'block';
	}
	bigView.onmouseout = function() {
		floatBox.style.display = 'none';
	}
	// 浮块随鼠标移动
	bigView.onmousemove = function(e) {
		var evt = e || window.event,
			left_val = evt.clientX-productPreview.offsetLeft-(floatBox.offsetWidth)/2, //兼容性写法;
			top_val = evt.clientY-productPreview.offsetTop-(floatBox.offsetHeight)/2; //兼容性写法;
		left_val = Math.min(bigView.offsetWidth-floatBox.offsetWidth, Math.max(0, left_val));
		top_val = Math.min(bigView.offsetHeight-floatBox.offsetHeight, Math.max(0, top_val));

		floatBox.style.left = left_val + 'px';
		floatBox.style.top = top_val + 'px';
	}


	// 颜色按钮点击
	var priceCon = getById('priceCon'),
		colorLink = getByClass(priceCon, 'color_link')[0],
		txtInput = getByClass(priceCon, 'txt_input')[0],
		inputVal = txtInput.value,
		add = getByClass(priceCon, 'add')[0],
		reduce = getByClass(priceCon, 'reduce')[0],
		lastNum = parseInt(getByClass(priceCon, 'lastnum')[0].innerHTML);

	colorLink.onclick = function() {
		if (this.className == 'color_link ck') {
			this.className = 'color_link';
		}else{
			this.className = 'color_link ck';
		}
	}

	add.onclick = function() {
		inputVal = txtInput.value;
		if (inputVal >= lastNum) {
			return;
		}
		inputVal++;
		txtInput.value = inputVal;
		if (inputVal > 1) {
			reduce.disabled = '';
		}else{
			reduce.disabled = true;
		}
	}

	reduce.onclick = function() {
		inputVal = txtInput.value;
		inputVal--;
		if (inputVal <= 1) {
			inputVal = 1;
			reduce.disabled = true;
		}
		txtInput.value = inputVal;
	}

	txtInput.onkeyup = function() {
		var val = parseInt(txtInput.value);
		if (isNaN(val) || val < 1) {
			val = 1;
		}

		if (val > lastNum) {
			val = lastNum;
		}

		this.value = val;

		if (val <= 1) {
			reduce.disabled = true;
		}else{
			reduce.disabled = '';
		}

	}

	// 返回顶部
	var toTop = getById('toTop'),
		timer,
		timer2,
		timer3;
	
	window.onscroll = function() {
		var scrollT = document.documentElement.scrollTop || document.body.scrollTop,
			winHeight = document.documentElement.clientHeight || document.body.clientHeight;

		if (scrollT > winHeight) {
			fill(100);
			move(160);
		}else{
			fill(0);
			move(-50)
		}

		function fill(end) {
			clearInterval(timer2);
			timer2 = setInterval(function(){
				var op_val = Math.round(parseFloat(getStyle(toTop, 'opacity'))*100),
					step = (end - op_val)/10;
				step = step > 0 ? Math.ceil(step) : Math.floor(step);

				if (op_val == end) {
					clearInterval(timer2);
				}else{
					toTop.style.opacity = (op_val + step)/100;
					toTop.style.filter = 'alpha(opacity=' + op_val + step + ')';
				}
			}, 20)
		}

		function move(end){
			clearInterval(timer3);
			timer3 = setInterval(function(){
				var bottomVal = parseInt(getStyle(toTop, 'bottom')),
					step = (end - bottomVal)/10;
				step = step > 0 ? Math.ceil(step) : Math.floor(step);

				if (bottomVal == end) {
					clearInterval(timer3);
				}else{
					toTop.style.bottom = bottomVal + step + 'px';
				}
			},30)
		}
	}


	toTop.onclick = function() {
		backTop();
	}

	function backTop() {
		clearInterval(timer);
		timer = setInterval(function(){
			var scrollT = document.documentElement.scrollTop || document.body.scrollTop,
			step = Math.floor(-scrollT/5);
			if (scrollT == 0) {
				clearInterval(timer);
			}else{
				document.documentElement.scrollTop = document.body.scrollTop = scrollT + step;
			}
		}, 30)	
	}

	// 顶部导航定位变化
	var topNav = getById('topNav');
		
	window.onscroll = function() {
		var scrollT = document.documentElement.scrollTop || document.body.scrollTop;
		if (scrollT > 700) {
			topNav.style.position = 'fixed';
			topNav.style.top = 0;
			topNav.style.opacity = 0.8;
		}else{
			topNav.style.position = 'static';
		}
	}
}(window, document, jQuery)