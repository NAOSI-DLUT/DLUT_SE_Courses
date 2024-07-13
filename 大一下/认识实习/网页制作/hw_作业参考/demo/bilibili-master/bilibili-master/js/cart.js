! function(window, document, $, undefined) {
	function getById(id) {
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



	var cartTable = getById('cartTable'),
		trs = cartTable.children[1].rows, //rows是表格特有的属性，表示所有的行；
		selectedTotal = getById('selected_total'),
		priceTotal = getById('price_total'),
		checkBoxes = getByClass(document, 'check'),
		selectAll = getByClass(document, 'select_all')[0],
		selectOne = getByClass(document, 'select_one'),
		delete_all = getByClass(document, 'delete_all')[0],
		toTop = getById('toTop'),

		timer;

	//合计
	function getTotal() {
		var seleted = 0,
			price = 0;

		for (var i = 0, len = trs.length; i < len; i++) {
			if (trs[i].getElementsByTagName('input')[0].checked) {
				trs[i].className = 'on';
				seleted += parseInt(trs[i].getElementsByTagName('input')[1].value);
				price += parseFloat(trs[i].cells[4].getElementsByTagName('span')[0].innerHTML); //cells是表格特有的属性，表示所有的单元格；
			} else {
				trs[i].className = '';
			}
		}

		selectedTotal.innerHTML = seleted + '件'
		priceTotal.innerHTML = '￥' + price.toFixed(2);
	}

	//小计
	function getSubTotal(tr) {
		var tds = tr.cells, //cells是表格特有的属性，表示所有的单元格；
			price = parseFloat(tds[2].getElementsByTagName('span')[0].innerHTML),
			count = parseInt(tr.getElementsByTagName('input')[1].value),
			SubTotal = parseFloat(price * count),
			td4 = tds[4].getElementsByTagName('span')[0];


		td4.innerHTML = SubTotal.toFixed(2);
		console.log(td4);
	}

	for (var i = 0, len = checkBoxes.length; i < len; i++) {
		checkBoxes[i].onclick = function() {
			if (this.className == 'select_all check') {
				for (var j = 0, len = checkBoxes.length; j < len; j++) {
					checkBoxes[j].checked = this.checked;
				}
			}

			if (this.checked == false) {
				selectAll.checked = false;
			}

			if (this.className === 'select_one check') {
				var count = 0;
				for (var i = 0, len = selectOne.length; i < len; i++) {
					if (selectOne[i].checked) {
						count++;
					}

					if (count == selectOne.length) {
						selectAll.checked = true;
					}
				}
			}

			getTotal();
		}
	}


	for (var i = 0, len = trs.length; i < len; i++) {
		trs[i].onclick = function(e) {
			var evt = e || window.event,
				target = evt.target || evt.srcElement,
				cls = target.className,
				input = this.getElementsByTagName('input')[1],
				input0 = this.getElementsByTagName('input')[0],
				val = parseInt(input.value),
				reduce = this.getElementsByTagName('i')[0];

			switch (cls) {
				case 'add':
					input.value = val + 1;
					reduce.innerHTML = '-';
					getSubTotal(this);
					break;

				case 'reduce':
					if (val > 1) {
						input.value = val - 1;
					}
					if (input.value <= 1) {
						reduce.innerHTML = '';
					}
					getSubTotal(this);
					break;

				case 'delete':
					if (input0.checked) {
						var conf = confirm('确定删除吗？');
						if (conf) {
							this.parentNode.removeChild(this);
						}
						if (trs.length == 0) {
							selectAll.checked = false;
						}

						break;
					}

				default:
					break;
			}
			getTotal();
		}

		trs[i].getElementsByTagName('input')[1].onkeyup = function() {
			var val = parseInt(this.value),
				tr = this.parentNode.parentNode.parentNode,
				reduce = tr.getElementsByTagName('i')[0];

			if (isNaN(val) || val < 1) {
				val = 1;
			}

			this.value = val;

			if (val <= 1) {
				reduce.innerHTML = '';
			} else {
				reduce.innerHTML = '-';
			}

			getSubTotal(tr);
			getTotal();
		}
	}


	delete_all.onclick = function() {
		if (selectedTotal.innerHTML != '0件') {
			var conf = confirm('确定删除吗？');
			if (conf) {
				for (var i = 0; i < trs.length; i++) {
					var input = trs[i].getElementsByTagName('input')[0];
					if (input.checked) {
						trs[i].parentNode.removeChild(trs[i]);
						i--;
					}
				}
				selectAll.checked = false;
			}
		}

		getTotal();
	}

	selectAll.checked = true; //页面初始化的时候默认是全部选中的；
	selectAll.onclick();

	//返回顶部
	toTop.onclick = function() {
		backTop();
	}

	function backTop() {
		clearInterval(timer);
		timer = setInterval(function() {
			var scrollT = document.documentElement.scrollTop || document.body.scrollTop,
				step = Math.floor(-scrollT / 8);

			if (scrollT == 0) {
				clearInterval(timer);
			} else {
				document.documentElement.scrollTop = document.body.scrollTop = scrollT + step;
			}
		}, 30);
	}
}(window, document, jQuery)