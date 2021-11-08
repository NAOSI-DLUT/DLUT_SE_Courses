<%--
  Created by IntelliJ IDEA.
  User: 26960
  Date: 2020/10/21
  Time: 10:21
  To change this template use File | Settings | File Templates.
--%>
<%@ page language="java" contentType="text/html; charset=UTF-8"
         pageEncoding="UTF-8"%>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core"%>

<c:choose>
    <c:when test="${role=='normal'}">
        <head>
            <style>
                body{text-align: center;}
                #div1{width:802px;height: 500px;border:1px solid red;margin: auto}
                #cs{width:650px;height: 350px;border:1px solid red;float: left;}
                #cs2{width: 148px;height: 350px;border: 1px solid red;float: left;}
                p{text-align: left}
                #ss{    height: 109px;
                    width: 796px;}
                #cs,#cs2{OVERFLOW: auto;}
                #btnSend{float: right;width: 100px;height: 30px;}
            </style>
        </head>

        <body>
        <h2>聊天室</h2>
        <input type="button" id="btnConnection" value="打开连接" />
        <input type="button" id="btnClose" value="关闭连接" />
        <div id="div1">
            <div id="cs" ></div>
            <div id="cs2"></div>
            <textarea id="ss"></textarea>
            <br/> <input type="button" id="btnSend" value="发送" />
        </div>
        <script src="js/jQuery.js" type="text/javascript" charset="utf-8"></script>
        <script type="text/javascript">
            let socket;
            if(typeof(WebSocket) == "undefined") {
                console.log("您的浏览器不支持WebSocket");
            }
            $("#btnSend").attr("disabled","disabled");//禁用
            $("#btnClose").attr("disabled","disabled");//禁用
            let name;
            $("#btnConnection").click(function() {
                name= ${NorAcc};
                if(name!=null){
                    $("#btnConnection").attr("disabled","disabled");//禁用
                    //实例化WebSocket对象，指定要连接的服务器地址与端口
                    socket = new WebSocket("ws://172.19.54.138:8088/find/ws/"+name);
                    //打开事件
                    socket.onopen = function() {
                        $("#btnSend").removeAttr("disabled");//启用
                        $("#btnClose").removeAttr("disabled");//启用
                        $("#cs2").append($("<p/>").html(name+"：连接成功"));
                        $("#cs2").append($("<p/>").html(${ol[0]}+"：连接成功"));
                    };
                    //获得消息事件
                    socket.onmessage = function(msg) {
                        $("#cs").append($("<p/>").html(msg.data));
                    };
                    //关闭事件
                    socket.onclose = function() {
                        $("#btnSend").attr("disabled","disabled");//禁用
                        $("#btnConnection").removeAttr("disabled");//启用
                        $("#btnClose").attr("disabled","disabled");//禁用
                        $("#cs2").append($("<p/>").html(name+"：已关闭"));
                    };
                    //发生了错误事件
                    socket.onerror = function() {
                        $("#cs2").append($("<p/>").html("已关闭发生了错误"));

                    }
                }
            });
            //发送消息
            $("#btnSend").click(function() {
                socket.send(document.getElementById("ss").value);
                $("#ss").val("");
            });
            //关闭
            $("#btnClose").click(function() {
                socket.close();
            });
        </script>
        </body>
    </c:when>
</c:choose>