<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<html>
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width" />
    <title>聊天室</title>
    <%@include file="../common/head.jsp"%>
</head>
<!-- <style>
    body{text-align: center;}
    #div1{width:802px;height: 500px;border:1px solid red;margin: auto}
    #cs{width:650px;height: 350px;border:1px solid red;float: left;}
    #cs2{width: 148px;height: 350px;border: 1px solid red;float: left;}
    p{text-align: left}
    #ss{    height: 109px;
        width: 796px;}
    #cs,#cs2{OVERFLOW: auto;}
    #btnSend{float: right;width: 100px;height: 30px;}
</style> -->
<body>

<%@include file="../common/login_status.jsp"%>
<h2>与${param.tar_username}的聊天室</h2>
<div id="div1">
    <div id="cs" ></div>
    <div id="cs2"></div>
    <textarea id="ss"></textarea>
    <br/> <input type="button" id="btnSend" value="发送" />
</div>
<script src="static/javascript/jquery-3.2.1.min.js" type="text/javascript" charset="utf-8"></script>
<script type="text/javascript">
    var socket;
    if(typeof(WebSocket) == "undefined") {
        console.log("您的浏览器不支持WebSocket");
    }
    var name;
    name = "${requestScope.get("name")}";
    if(name!=null){
        //实现化WebSocket对象，指定要连接的服务器地址与端口
        // socket = new WebSocket("ws://:80/ws/"+name);
        //本机
        socket = new WebSocket("ws://localhost:8081${pageContext.servletContext.contextPath}/ws/"+name);
        //打开事件
        socket.onopen = function() {
            // $("#btnSend").attr("disabled","");//禁用
            // $("#btnClose").attr("disabled","");//禁用
            $("#btnSend").removeAttr("disabled");//禁用
            $("#cs2").append($("<p/>").html(name+"：连接成功"));
        };
        //获得消息事件
        socket.onmessage = function(msg) {
            $("#cs").append($("<p/>").html(msg.data));
        };
        //关闭事件
        socket.onclose = function() {
            $("#btnSend").attr("disabled","disabled");//禁用
            $("#cs2").append($("<p/>").html(name+"：已关闭"));
        };
        //发生了错误事件
        socket.onerror = function() {
            $("#cs2").append($("<p/>").html("已关闭发生了错误"));

        }
    }

    //发送消息
    $("#btnSend").click(function() {
        // socket.send(document.getElementById("ss").value);
        socket.send(JSON.stringify({message:document.getElementById("ss").value,msgTo:"${param.tar_username}"}));
        $("#ss").val("");
    });

</script>
</body>



</html>
