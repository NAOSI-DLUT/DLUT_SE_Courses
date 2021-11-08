<%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c" %>  
<%@ page language="java" pageEncoding="utf-8"%>
<%@ page import="java.util.*"%>
<%@ page import="SearchMan.Man" %>
<!DOCTYPE html>
<html>
<head>

<title>身份选择</title>
</head>
<body>

<div class="container">

	<form action="CheckServlet" method="get">
	
		
		<input type="radio"  name="role" value="normal" checked="checked" > 普通用户 <br>
		<input type="radio"  name="role"  value="admin" > 管理员 <br>


		<td>请输入用户名：<input type="text" name="username" size="20">
		</td>
		
		<td>请输入密码：&nbsp;&nbsp;<input type="password" name="userpwd" size="20">
			</td>
		
		<td><input type="submit" value="login" /> <input type="reset" /></td>
		
	</form>
		
	
	

</div>

</body>
</html>