/***
 * @param id
 * @return document.getElementById(id)
 */
function my$(id) {
    return document.getElementById(id);
};
/*文本兼容性问题*/

/*设置任意标签中间的任意文本内容*/
function setInnerText(element, text) {
    if (typeof element.textContent == "undefined") {
        element.innertext = text;
    } else {
        element.textContent = text;
    }
};

/*获取任意文本之间的内容*/
function getInnerText(element) {
    if (typeof element.textContent == "undefined") {
        return element.innerText;
    } else {
        return element.textContent;
    }
};

/*获取任意一个父级元素的第一个子级元素*/
function getFirstElementChild(element) {
    if (element.firstElementChild) {
        return element.firstElementChild;
    } else {
        var node = element.firstChild;
        while (node && node.nodeType != 1) {
            node = node.nextSibling;
        }
        return node;
    }
};

/*获取任意一个父级元素的最后子级元素*/
function getLastElementChild(element) {
    if (element.lastElementChild) {
        return element.lastElementChild;
    } else {
        var node = element.lastChild;
        while (node && node.nodeType != 1) {
            node = node.previousSibling;
        }
        return node;
    }
};

/*为元素绑定事件的兼容性代码*/
function addEventListener(element, type, fn) {
    if(element.addEventListener){
        return element.addEventListener(type, fn,false);
    }else if(element.attachEvent){
        return element.attachEvent("on" + type, fn);
    }else{
        return element["on" + type] = fn;
    }
};

/*为元素解除绑定事件的兼容性代码*/
function removeEventListener(element, type, fnName) {
    if(element.removeEventListener){
        return element.removeEventListener(type,fnName,false);
    }else if(element.detachEvent){
        return element.detachEvent("on" + type, fnName);
    }else{
        return element["on" + type] = null;
    }
};