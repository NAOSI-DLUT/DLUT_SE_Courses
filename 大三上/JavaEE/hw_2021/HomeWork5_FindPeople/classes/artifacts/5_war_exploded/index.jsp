<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>PeopleQuery in academy of software</title>
 	<style> 
      body{text-align:center} 
    </style> 
</head>
<body>
<h1>软院   <img src="image/dagong.jpg" width="128" height="128">  寻他</h1>
<form action="TestServlet" method="post">
<p>	    <input type="text" style="width:500px; height:40px;" name="information" placeholder="可输入电话号码/学号/教工号/QQ/姓名/邮箱查询"/>
		<input type="submit" value="寻他千百度" style="background:blue;width:100px; height:45px;"/></p>
</form>
<c:choose>
	<c:when test="${role=='admin'}">
		管理员${AdminAcc}你好！
	</c:when>
	<c:when test="${role=='normal'}">
		用户${NorAcc}你好！
	</c:when>
</c:choose>
<a href="login.jsp"> 登录 </a>
</body>
</html>