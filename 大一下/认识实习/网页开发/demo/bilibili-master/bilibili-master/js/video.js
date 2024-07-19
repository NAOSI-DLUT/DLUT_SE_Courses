! function(window, document, $, undefined) {
	// 通过ID获取元素
	function getId(id) {
		return typeof id == 'string' ? document.getElementById(id) : id;
	}

	// 通过Class获取元素
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

	// 获取元素样式
	function getStyle(obj, attrname) {
		if (obj.currentStyle) {
			return obj.currentStyle[attrname];
		} else {
			return getComputedStyle(obj, false)[attrname];
		}
	}

	//删除节点
	function removeNode(node) {
		node.parentNode.removeChild(node);
	}

	// 获取当前元素的同胞元素
	function siblings(elm) {
		var a = [];
		var p = elm.parentNode.children;
		for (var i = 0, pl = p.length; i < pl; i++) {
			if (p[i] !== elm) {
				a.push(p[i]);
			}
		}
		return a;
	}



	var userID = 'tracyTeng',
		historySearch = getId('historySearch'),
		historyUl = historySearch.getElementsByTagName('ul')[0],
		inputWp = getId('inputWp'),

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
		login = getId('login'),

		authorIntro = getId('authorIntro'),
		txtIntro = getId('txtIntro'),
		txtBefore = txtIntro.innerHTML,
		txtAfter = txtBefore.slice(0, 33),
		onBtn = authorIntro.getElementsByTagName('a')[0],

		listUl = getId('listUl'),
		listLis = listUl.getElementsByTagName('li'),
		ulHeight = listUl.offsetHeight,
		liHeight = listLis[0].offsetHeight,
		cBtn = getId('c_btn'),

		shareBox = getId('shareBox'),
		shareLink = getId('shareLink'),
		maxH = parseInt(getStyle(shareLink, 'height')),
		h = 0,
		step = 30,
		timer,
		timer2,

		anotherBox = getId('anotherBox'),
		prevBtn = getByClass(anotherBox, 'prev')[0],
		nextBtn = getByClass(anotherBox, 'next')[0],
		anotherList = getId('anotherList'),
		aVideos = anotherList.getElementsByTagName('div'),
		len = aVideos.length,
		clkNum = 0,

		comEnter = getId('comEnter'),
		txtArea = getByClass(comEnter, 'com_area')[0],
		enterBtn = getByClass(comEnter, 'enter_btn')[0],

		comContent = getId('comContent'),
		userComments = getByClass(comContent, 'user_comment'),
		// userContxts = getByClass(comContent, 'user_contxt'),
		userTxts = getByClass(comContent, 'user_txt'),
		replyComs = getByClass(comContent, 'reply_com'),

		enterBtn = getId('enterBtn'),
		comArea = getId('comArea'),
		isExist = false,
		isCreate = false,
		isCreate2 = false,

		toTop = getId('toTop'),
		timer3,
		timer4;



	// 历史搜索框
	inputWp.onfocus = function() {
		historySearch.style.display = 'block';
	}

	inputWp.onblur = function() {
		historySearch.style.display = 'none';
	}

	var data = ['数据1', '数据2', '数据3']; //模拟数据

	for (var i = 0; i < data.length; i++) {
		historyUl.innerHTML += '<li><a href="###">' + data[i] + '</a></li>';
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


	//切换用户对话框拖拽&&居中
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


	//视频作者介绍的展开和收起
	txtIntro.innerHTML = txtAfter;
	onBtn.onclick = function() {
		if (this.innerHTML == '展开') {
			this.innerHTML = '收起';
			txtIntro.innerHTML = txtBefore;
		} else {
			this.innerHTML = '展开';
			txtIntro.innerHTML = txtAfter;
		}
	}

	if (txtIntro.innerHTML.length > 30) {
		onBtn.style.display = 'inline-block';
	}

	//多part
	if (listLis.length > 4) {
		listUl.style.height = liHeight + 'px';
		cBtn.style.display = 'block';
	}

	cBtn.onclick = function() {
		if (this.innerHTML == '展开') {
			this.innerHTML = '收起';
			listUl.style.height = ulHeight + 'px';
		} else {
			this.innerHTML = '展开';
			listUl.style.height = liHeight + 'px';
		}

	}

	//分享
	shareBox.onmouseenter = function() {
		timer2 = setTimeout(slideDown, 300);
	}

	function slideDown() {
		shareLink.style.display = 'block';
		shareLink.style.height = h + 'px';
		clearInterval(timer);
		timer = setInterval(function() {
			if (h < maxH) {
				h += step;
				shareLink.style.height = h + 'px';
			} else {
				clearInterval(timer);
			}
		}, 30)
	}

	shareBox.onmouseleave = function() {
		clearInterval(timer2);
		timer2 = setTimeout(slideUp, 300);
	}

	function slideUp() {
		shareBox.style.borderBottom = '1px solid #ccc';
		clearInterval(timer);
		timer = setInterval(function() {
			shareLink.style.height = h + 'px';
			if (h > 0) {
				h -= step;
			} else {
				clearInterval(timer);
				shareLink.style.display = 'none';
			}
		}, 30)
	}

	//视频切换
	// anotherBox prevBtn nextBtn
	anotherBox.onmouseover = function() {
		prevBtn.style.display = 'block';
		nextBtn.style.display = 'block';
	}

	anotherBox.onmouseout = function() {
		prevBtn.style.display = 'none';
		nextBtn.style.display = 'none';
	}

	function fadeOp() {
		for (var i = 0; i < aVideos.length; i++) {
			aVideos[i].className = 'avideo clearfix';
		}
		aVideos[clkNum].className += ' full_op';
	}

	nextBtn.onclick = function() {
		clkNum++;
		if (clkNum > len - 1) {
			clkNum = 0;
		}
		fadeOp();
	}

	prevBtn.onclick = function() {
		clkNum--;
		if (clkNum < 0) {
			clkNum = len - 1;
		}
		fadeOp();
	}

	//评论点赞回复--自己输入评论框和按钮
	txtArea.onmouseover = function() {
		this.className = 'com_area mover';
	}

	txtArea.onmouseout = function() {
		txtArea.className = 'com_area';
	}

	enterBtn.onmouseover = function() {
		this.className = 'enter_btn mover';
		txtArea.className = 'com_area mover';
	}

	enterBtn.onmouseout = function() {
		txtArea.className = 'com_area';
		enterBtn.className = 'enter_btn';
	}

	//评论点赞回复--点赞点反对，举报和黑名单显示隐藏
	function creatReInput() {
		var replyInput = document.createElement('div');
		replyInput.className = 'com_self clearfix reply_input';
		replyInput.innerHTML =
			'<div class="my_face"><img src="img/index/userimg.jpg"></div>' +
			'<div class="com_enter" id="comEnter">' +
			'<textarea class="com_area" id="replyArea" placeholder="请自觉遵守互联网相关的政策法规，严禁发布色情、暴力、反动的言论。"></textarea>' +
			'<button class="enter_btn" id="replyBtn">发表<br>评论</button>' +
			'</div>';
		return replyInput;
	}

	for (var i = 0; i < userTxts.length; i++) {
		userTxts[i].onclick = function(e) {
			var evt = e || window.event,
				target = evt.target || evt.srcElement;

			switch (target.className) {
				case 'like':
					var oldValue = parseInt(target.getAttribute('value')),
						newValue;
					target.className = 'like onlike';
					target.innerHTML = '(' + (oldValue + 1) + ')';
					newValue = oldValue + 1;
					target.setAttribute('value', newValue);
					evt.stopPropagation();
					evt.cancelBubble = true;
					break;

				case 'unlike':
					target.className = 'unlike light';
					evt.stopPropagation();
					evt.cancelBubble = true;
					break;

				case 'like onlike':
					var oldValue = parseInt(target.getAttribute('value')),
						newValue;
					target.className = 'like';
					target.innerHTML = '(' + (oldValue - 1) + ')';
					newValue = oldValue - 1;
					target.setAttribute('value', newValue);
					evt.stopPropagation();
					evt.cancelBubble = true;
					break;

				case 'unlike light':
					target.className = 'unlike';
					evt.stopPropagation();
					evt.cancelBubble = true;
					break;

				case 'reply main_reply':
					isCreate2 = true;
					if (this.parentNode.children[2]) {
						removeNode(this.parentNode.children[2]);
						return;
					} else {
						var sibs = siblings(this.parentNode.parentNode);
						for (var i = 0; i < sibs.length; i++) {
							if (sibs[i].children[1].children[2]) {
								removeNode(sibs[i].children[1].children[2]);
							}
						}
						this.parentNode.appendChild(creatReInput());
						var replyArea = getId('replyArea');

						replyArea.focus();

					}
					evt.stopPropagation();
					evt.cancelBubble = true;
					break;
			}

			if (isCreate2) {
				var replyBtn = getId('replyBtn');
				replyBtn.onmouseenter = function() {
					this.style.backgroundColor = '#00ADDA';
				}
				replyBtn.onmouseleave = function() {
					this.style.backgroundColor = '#00A1D6';
				}

				replyBtn.onclick = function(e) {
					var evt = e || window.event,
						target = evt.target || evt.srcElement;
					evt.stopPropagation();
					evt.cancelBubble = true;
					// console.log(this.parentNode.parentNode.parentNode.parentNode);这种也可以，获取到当前的userComment；
					var replyVal = replyArea.value,
						replyCom = siblings(this.parentNode.parentNode)[1];
					if (replyVal == '') {
						return;
					} else {
						var reLi = document.createElement('li');
						reLi.className = 'clearfix self';
						reLi.innerHTML =
							'<div class="reply_face"><a href="###"><img src="img/index/userimg.jpg"></a></div>' +
							'<div class="reply_con">' +
							'<p class="reply_txt">' +
							'<a href="###" class="userid">' + userID + '：' + '</a>' +
							replyVal +
							'</p>' +
							'<p class="operation">' +
							'<span class="replytime">' + filterTime(new Date()) + '</span>' +
							'<span><a href="###" class="like" value="0">(0)</a></span>' +
							'<span><a href="###" class="reply minor_reply">回复</a></span>' +
							'<span><a href="###" class="del" id="replyDelBtn">删除</a></span>' +
							'</p>' +
							'</div>'
							// var replyUl = target.children[1].children[1].children[0];这种也可以，获取到当前的ul；
						var replyUl = replyCom.children[0];
						replyUl.appendChild(reLi);
						replyArea.value = '';
					}
				}
			}
		}
	}

	/*	for (var i = 0; i < replyComs.length; i++) {
			var replyComLis = replyComs[i].getElementsByTagName('li');
			for (var i = 0; i < replyComLis.length; i++) {
				replyComLis[i].index = i;
				if (replyComLis[i].index > 2) {
					replyComLis[i].style.display = "none";
				}
			}
		}
	*/

	for (var i = 0; i < replyComs.length; i++) {
		var lis = replyComs[i].getElementsByTagName('li');
		if (lis.length > 3) {
			var spanBox = document.createElement('span');
			spanBox.className = 'check';
			spanBox.innerHTML = '还有' + (lis.length - 3) + '条回复，<a href="###" style="color: #0092C2;">点击查看更多</a>';
			replyComs[i].appendChild(spanBox);
			
			for (var i = 0; i < lis.length; i++) {
				lis[i].index = i;
				if (lis[i].index > 2) {
					lis[i].style.display = "none";
				}
			}
		}
	}


	for (var i = 0; i < replyComs.length; i++) {
		replyComs[i].index = i;
		replyComs[i].onmouseenter = function() {
			var replyComLis = this.getElementsByTagName('li');
			for (var i = 0; i < replyComLis.length; i++) {
				replyComLis[i].index = i;
				replyComLis[i].onmouseenter = function() {
					var rePort_s = getByClass(this, 'report')[0],
						backList_s = getByClass(this, 'backlist')[0];

					if (this.className == 'clearfix self') {
						var replyDel = getByClass(this, 'del')[0];
						replyDel.style.visibility = 'visible';
						return;
					}
					rePort_s.style.visibility = 'visible';
					backList_s.style.visibility = 'visible';
				}

				replyComLis[i].onmouseleave = function() {
					var rePort_s = getByClass(this, 'report')[0],
						backList_s = getByClass(this, 'backlist')[0];
					if (this.className == 'clearfix self') {
						var replyDel = getByClass(this, 'del')[0];
						replyDel.style.visibility = 'hidden';
						return;
					}
					rePort_s.style.visibility = 'hidden';
					backList_s.style.visibility = 'hidden';
				}

				replyComLis[i].onclick = function(e) {
					var evt = e || window.event,
						target = evt.target || evt.srcElement;

					switch (target.className) {
						case 'reply minor_reply':
							var userContxt = this.parentNode.parentNode.parentNode,
								replyArea;
							isCreate = true;
							if (userContxt.children[2]) {
								replyArea = getId('replyArea');
								replyArea.focus();
								var nameID = getByClass(this, 'userid')[0].innerHTML;
								replyArea.innerHTML = '回复 ' + '@' + nameID;
								return;
							} else {
								userContxt.appendChild(creatReInput());
								var sibs = siblings(userContxt.parentNode);
								for (var i = 0; i < sibs.length; i++) {
									if (sibs[i].children[1].children[2]) {
										removeNode(sibs[i].children[1].children[2]);
									}
								}
								replyArea = getId('replyArea');

								replyArea.focus();
								var nameID = getByClass(this, 'userid')[0].innerHTML;
								replyArea.innerHTML = '回复 ' + '@' + nameID;

							}
							break;

						case 'del':
							removeNode(this);
							break;

						case 'like':
							var oldValue = parseInt(target.getAttribute('value')),
								newValue;
							target.className = 'like onlike';
							target.innerHTML = '(' + (oldValue + 1) + ')';
							newValue = oldValue + 1;
							target.setAttribute('value', newValue);
							evt.stopPropagation();
							evt.cancelBubble = true;
							break;

						case 'unlike':
							target.className = 'unlike light';
							evt.stopPropagation();
							evt.cancelBubble = true;
							break;

						case 'like onlike':
							var oldValue = parseInt(target.getAttribute('value')),
								newValue;
							target.className = 'like';
							target.innerHTML = '(' + (oldValue - 1) + ')';
							newValue = oldValue - 1;
							target.setAttribute('value', newValue);
							evt.stopPropagation();
							evt.cancelBubble = true;
							break;

						case 'unlike light':
							target.className = 'unlike';
							evt.stopPropagation();
							evt.cancelBubble = true;
							break;

					}

					if (isCreate) {
						var replyBtn = getId('replyBtn');
						replyBtn.onmouseenter = function() {
							this.style.backgroundColor = '#00ADDA';
						}
						replyBtn.onmouseleave = function() {
							this.style.backgroundColor = '#00A1D6';
						}
						replyBtn.onclick = function() {
							var replyVal = replyArea.value;
							if (replyVal == '回复 ' + '@' + nameID || replyVal == '') {
								return;
							} else {
								var reLi = document.createElement('li'),
									replyCom = siblings(this.parentNode.parentNode)[1];
								reLi.className = 'clearfix self';
								reLi.innerHTML =
									'<div class="reply_face"><a href="###"><img src="img/index/userimg.jpg"></a></div>' +
									'<div class="reply_con">' +
									'<p class="reply_txt">' +
									'<a href="###" class="userid">' + userID + '：' + '</a>' +
									replyVal +
									'</p>' +
									'<p class="operation">' +
									'<span class="replytime">' + filterTime(new Date()) + '</span>' +
									'<span><a href="###" class="like" value="0">(0)</a></span>' +
									'<span><a href="###" class="reply minor_reply">回复</a></span>' +
									'<span><a href="###" class="del" id="replyDelBtn">删除</a></span>' +
									'</p>' +
									'</div>';

								var replyUl = replyCom.children[0];
								replyUl.appendChild(reLi);
								replyArea.value = '';
							}
						}
					}
				}
			}

		}
	}


	for (var i = 0; i < userComments.length; i++) {
		userComments[i].index = i;
		userComments[i].onmouseenter = function() {
			var rePort = getByClass(this.children[1], 'report')[0],
				backList = getByClass(this.children[1], 'backlist')[0];
			rePort.style.visibility = 'visible';
			backList.style.visibility = 'visible';
		}

		userComments[i].onmouseleave = function() {
			var rePort = getByClass(this.children[1], 'report')[0],
				backList = getByClass(this.children[1], 'backlist')[0];
			rePort.style.visibility = 'hidden';
			backList.style.visibility = 'hidden';
		}
	}


	//评论点赞回复--点击发表评论，评论显示到评论区；
	function filterTime(date) {
		var y = date.getFullYear(),
			m = date.getMonth() + 1,
			d = date.getDate(),
			h = date.getHours(),
			min = date.getMinutes();
		m = checkDate(m);
		d = checkDate(d);
		h = checkDate(h);
		min = checkDate(min);

		return y + '-' + m + '-' + d + ' ' + h + ':' + min;
	}

	function checkDate(val) {
		return val < 0 ? '0' + val : val;
	}

	enterBtn.onclick = function() {
		isExist = true;

		if (comArea.value.length == 0) {
			return;
		}

		var areaTxt = comArea.value,
			myComBox = document.createElement('div'),
			childs = comContent.children.length,
			floorNum;

		if (childs > 0) {
			floorNum = '#' + (childs + 1)
			comContent.insertBefore(myComBox, comContent.children[0]);
		} else {
			comContent.appendChild(myComBox);
		}

		myComBox.className = 'user_comment clearfix';
		myComBox.innerHTML =
			'<div class="user_face"><a href="###"><img src="img/index/userimg.jpg"></a></div>' +
			'<div class="user_contxt">' +
			'<div class="user_txt">' +
			'<h5 class="userid"><a href="###">' + userID + '</a></h5>' +
			'<p class="user_maincom">' + areaTxt + '</p>' +
			'<p class="operation">' +
			'<span class="floor">' + floorNum + '</span>' +
			'<span class="time">' + filterTime(new Date()) + '</span>' +
			'<span><a href="###" class="like" value="0">(0)</a></span>' +
			'<span><a href="###" class="unlike"></a></span>' +
			'<span><a href="###" class="del" id="delBtn">删除</a></span>' +
			'</p>' +
			'</div>' +
			'</div>'

		comArea.value = '';

		if (isExist) {
			var delBtn = getId('delBtn');
			myComBox.onmouseenter = function() {
				delBtn.style.visibility = 'visible';
			}
			myComBox.onmouseleave = function() {
				delBtn.style.visibility = 'hidden';
			}
			myComBox.onclick = function(e) {
				var evt = e || window.event,
					target = evt.target || evt.srcElement;

				switch (target.className) {
					case 'del':
						removeNode(myComBox);
						break;

					case 'like':
						var oldValue = parseInt(target.getAttribute('value')),
							newValue;
						target.className = 'like onlike';
						target.innerHTML = '(' + (oldValue + 1) + ')';
						newValue = oldValue + 1;
						target.setAttribute('value', newValue);
						break;

					case 'unlike':
						target.className = 'unlike light';
						break;

					case 'like onlike':
						target.className = 'like';
						var oldValue = parseInt(target.getAttribute('value')),
							newValue;
						target.className = 'like';
						target.innerHTML = '(' + (oldValue - 1) + ')';
						newValue = oldValue - 1;
						target.setAttribute('value', newValue);
						break;

					case 'unlike light':
						target.className = 'unlike';
						break;
				}
			}
		}

	}

	// 返回顶部
	window.onscroll = function() {
		var scrollT = document.documentElement.scrollTop || document.body.scrollTop,
			clientHeight = document.documentElement.clientHeight || document.body.clientHeight;

		if (scrollT > clientHeight) {
			fullOp(100);
		} else {
			fullOp(0);
		}

		function fullOp(end) {
			clearInterval(timer4);
			timer4 = setInterval(function() {
				var opacityVal = Math.round(parseFloat(getStyle(toTop, 'opacity')) * 100);
				step = (end - opacityVal) / 2;
				step = step > 0 ? Math.ceil(step) : Math.floor(step);

				if (opacityVal == end) {
					clearInterval(timer4);
				} else {
					toTop.style.opacity = (opacityVal + step) / 100;
					toTop.style.filter = 'alpha(opacity=' + (opacityVal + step) + ')';
				}
			}, 10)
		}
	}

	toTop.onclick = function() {
		backTop();
	}

	function backTop() {
		clearInterval(timer3);
		timer3 = setInterval(function() {
			var scrollT = document.documentElement.scrollTop || document.body.scrollTop;
			step = Math.floor(-scrollT / 5);

			if (scrollT == 0) {
				clearInterval(timer3);
			} else {
				document.documentElement.scrollTop = document.body.scrollTop = scrollT + step;
			}
		}, 30);
	}

}(window, document, jQuery)