<%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c" %>  
<%@ page language="java" pageEncoding="utf-8"%>
<!DOCTYPE html>
<html>
<head>
<title>Admin Page Tomcat2</title>
</head>
<body>

	<a href = "LogIn.jsp">重新登录</a>
	
	<br />
	<br />
	
	<form action="AdminServlet" method="get">
		<input type="submit" name="action" value="resetAllChances"> 重置全部用户投票次数
	</form>
	
	<br />
	<br />
	
	<form action="AdminServlet" method="get">
		<table>
			<tr>
				<td><input type="submit" name="action" value="setInactive"> 禁言该用户</td>
				<td><input type="text" name="id"></td>
			</tr>
		</table>
	</form>

</body>
</html>