! function(window, document, $, undefined) {

	// 通过ID获取元素
	function getById(id) {
		return typeof id == 'string' ? document.getElementById(id) : id;
	}

	// 通过Class获取元素
	function getByClass(obj, cls) {
		var result = [],
			els = obj.getElementsByTagName('*');
		for (var i = 0; i < els.length; i++) {
			if (els[i].className == cls || els[i].className.indexOf(' ' + cls) >= 0 || els[i].className.indexOf(' ' + cls + ' ') >= 0 || els[i].className.indexOf(cls + ' ') >= 0) {
				result.push(els[i])
			}
		}
		return result;
	}

	// 获取样式
	function getStyle(obj, attr) {
		if (obj.currentStyle) {
			return obj.currentStyle[attr];
		} else {
			return getComputedStyle(obj, false)[attr];
		}
	}

	//删除节点
	function removeNode(node) {
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

	// 点击按钮prevbtn，nextbtn图片滑动；

	var listCon = getById('listCon'),
		preBtn = getById('preBtn'),
		nextBtn = getById('nextBtn'),
		timer,
		timer2,
		isSlide = false;

	nextBtn.onclick = function() {
		if (!isSlide) {
			slider_lf(-1093);
		}
	}

	preBtn.onclick = function() {
		if (!isSlide) {
			slider_rt(-1093);
		}

	}


	function slider_lf(end) {
		var leftval = parseInt(getStyle(listCon, 'left'));
		if (leftval == -2186) {
			return;
		} else {
			if (end == leftval) {
				end = -2186;
			}
			clearInterval(timer);
			timer = setInterval(function() {
				var leftval = parseInt(getStyle(listCon, 'left')),
					step = (end - leftval) / 10;
				step = step > 0 ? Math.ceil(step) : Math.floor(step);
				if (leftval == end) {
					clearInterval(timer);
					isSlide = false;
				} else {
					listCon.style.left = leftval + step + 'px';
					isSlide = true;
				}
			}, 30)
		}
	}


	function slider_rt(end) {
		var leftval = parseInt(getStyle(listCon, 'left'));
		if (leftval == 0) {
			return;
		} else {
			if (end == leftval) {
				end = 0;
			}
			clearInterval(timer2);
			timer2 = setInterval(function() {
				var leftval = parseInt(getStyle(listCon, 'left')),
					step = (end - leftval) / 10;
				step = step > 0 ? Math.ceil(step) : Math.floor(step);
				if (leftval == end) {
					clearInterval(timer2);
					isSlide = false;
				} else {
					listCon.style.left = leftval + step + 'px';
					isSlide = true;
				}
			}, 30)
		}
	}

	// 瀑布流布局flow
	var dataBox = {
		'data': [{
			'src': '0.jpg'
		}, {
			'src': '1.jpg'
		}, {
			'src': '2.jpg'
		}, {
			'src': '3.jpg'
		}, {
			'src': '4.jpg'
		}, {
			'src': '5.jpg'
		}]
	};

	var init = function() {
		waterfall('flow_wp', 'box');
		window.onscroll = loadimg;
	};

	function loadimg() {
		var flow_wp = getById('flow_wp');

		if (check()) {
			for (var i = 0; i < dataBox.data.length; i++) {
				var box_wp = document.createElement('div');
				box_wp.className = 'box';
				var pic_wp = document.createElement('div');
				pic_wp.className = 'pic';
				var imp_wp = document.createElement('img');
				imp_wp.src = 'img/paint-friend/' + dataBox.data[i].src;

				flow_wp.appendChild(box_wp);
				box_wp.appendChild(pic_wp);
				pic_wp.appendChild(imp_wp);
			}
			waterfall('flow_wp', 'box');
		}

	}

	function check() {
		var flowWp = getById('flow_wp'),
			ele_cls = getByClass(flowWp, 'box'),
			lastBoxIndex = ele_cls.length - 1,
			lastBox = ele_cls[lastBoxIndex],
			scrollT = document.documentElement.scrollTop || document.body.scrollTop,
			clientH = document.documentElement.clientHeight || document.body.clientHeight,
			lsBoxOffsetT = lastBox.offsetTop,
			lsBoxHalfH = parseInt(lastBox.offsetHeight / 2);

		return scrollT + clientH > lsBoxOffsetT + lsBoxHalfH ? true : false;
	}


	function waterfall(mainId, boxcls) {
		var flowWp = getById(mainId),
			ele_cls = getByClass(flowWp, boxcls),
			clientW = window.screen.availWidth, //用屏幕可用大小window.screen.availWidth代替浏览器可视区域大小document.documentElement.clientWidth，就不会出现如果浏览器从小切换大时列数变化的问题；
			boxOffsetWidth = ele_cls[0].offsetWidth,
			cols = parseInt(clientW / boxOffsetWidth);

		flowWp.style.cssText += ' ; width:' + cols * boxOffsetWidth + 'px; margin: 0 auto;'; //'+=':cssText默认会将原样式去掉换成设置的样式，所以需要+=在原样式后面添加设置的样式，这样才不会将原来样式给去掉了；';'：加;是为了兼容IE，在IE中会将前面原样式的分号去掉，所以要加上;来兼容IE; 还有一点，cssText属性的属性值是字符串，记得加上引号；

		var hArr = [];
		for (var i = 0; i < ele_cls.length; i++) {
			if (i < cols) {
				hArr.push(ele_cls[i].offsetHeight);
			} else {
				var minHeight = Math.min.apply(Math, hArr); //求一个数组里的最大或最小值，可以用Math.max/min.apply(null/Math, 数组名); null或者Math都可以；
				// var minHIndex = getIndex(hArr, minHeight); 这句是写了一个getIndex方法来求最小高度的索引；用下面那句也可以，更为方便；
				var minHIndex = hArr.indexOf(minHeight);
				ele_cls[i].style.position = 'absolute';
				ele_cls[i].style.top = minHeight + 'px';
				// ele_cls[i].style.left = minHIndex*boxOffsetWidth + 'px'; 或者用下面那句也可以！
				ele_cls[i].style.left = ele_cls[minHIndex].offsetLeft + 'px';
				hArr[minHIndex] += ele_cls[i].offsetHeight;
			}
		}

		// function getIndex(arr, minHeight) {
		// 	for (var i in arr) {
		// 		if (arr[i] == minHeight) {
		// 			return i;
		// 		}
		// 	}
		// }
	}

	init();

}(window, document, jQuery)