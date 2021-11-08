<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
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
<h1>软院   <img src="image/dagong.jpg" width="128" height="128">  找人</h1>
<form action="TestServlet" method="post">
<p>	    <input type="text" style="width:500px; height:40px;" name="information" placeholder="可输入电话号码/学号/教工号/QQ/姓名/邮箱查询"/>
		<input type="submit" value="搜索" style="background:blue;width:100px; height:45px;"/></p>
</form>
<a href="login.jsp"> 登录 </a>
</body>
</html>