<%--
  Created by IntelliJ IDEA.
  User: 26960
  Date: 2020/10/18
  Time: 10:42
  To change this template use File | Settings | File Templates.
--%>
<%@ page language="java" contentType="text/html; charset=UTF-8"
         pageEncoding="UTF-8"%>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core"%>
<!DOCTYPE html>
<html>
<head>
    <meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
    <title>Account manager</title>
</head>
<body>
<c:choose>
    <c:when test="${role=='admin'}">
        管理员${AdminAcc}你好！
    </c:when>
</c:choose>
<a href="index.jsp">首页</a>
<p style="height: 50px; font-size: 40px; background-color: pink">删除学生功能</p>
<form action="AdminServlet" method="post">
    <p>	<input type="text" style="width:500px; height:50px;" name="id" placeholder="输入要删除的学号"/>
        <input type="submit" name="action" value="delete" style="background:blue;width:100px; height:50px;"/></p>
</form>
<p style="height: 50px; font-size: 40px; background-color: pink">添加学生功能</p>
<form action="AdminServlet" method="post">
    <p>	<input type="text" style="width:500px; height:50px;" name="id" placeholder="输入要添加的学号"/>
        <input type="text" style="width:500px; height:50px;" name="name" placeholder="输入要添加的姓名"/>
        <input type="text" style="width:500px; height:50px;" name="tel" placeholder="输入要添加的电话号"/>
        <input type="text" style="width:500px; height:50px;" name="qq" placeholder="输入要添加的QQ"/>
        <input type="text" style="width:500px; height:50px;" name="mail" placeholder="输入要添加的邮箱"/>
        <input type="submit" name="action" value="add" style="background:blue;width:100px; height:50px;"/></p>
</form>
<p style="height: 50px; font-size: 40px; background-color: pink">修改学生信息</p>
<form action="AdminServlet" method="get">
    <p><input type="text" style="width:500px; height:50px;" name="id">
        <input style="width:500px; height:50px;" type="text" name="name">
        <input style="width:500px; height:50px;" type="text" name="tel">
        <input style="width:500px; height:50px;" type="text" name="qq">
        <input style="width:500px; height:50px;" type="text" name="mail">
    <input type="submit" name="action" value="change" style="background:blue;width:100px; height:50px;"></p>
</form>
<p style="height: 50px; font-size: 40px; background-color: pink">查询学生信息</p>
<form action="SearchServlet" method="post">
    <p>
    <input type="text" style="width:500px; height:50px;" name="query" />
    <input type="submit" name="action" value="searchAdmin" style="background:blue;width:100px; height:50px;">
    </p>
</form>

<br/>
</body>
</html>
