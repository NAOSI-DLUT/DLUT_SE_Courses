<%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c" %>  
<%@ page language="java" pageEncoding="utf-8"%>
<!DOCTYPE html>
<html>

<head>
<title>Change Password</title>
</head>

<body>

<form action="ChangePwdServlet" method="get">

	修改密码： <br/>
	
	<table>
		<tr>
			<td>&nbsp;&nbsp; 旧密码</td>
			<td><input type="password" name="oldpwd"/> </td>
		</tr>
		
		<tr>
			<td>&nbsp;&nbsp; 新密码</td>
			<td><input type="password" name="newpwd"/></td>
		</tr>
		
		<tr>
			<td>&nbsp;&nbsp; 确认新密码</td>
			<td><input type="password" name="confirmpwd"/></td>
		</tr>
		
		<tr>
			<td><input type="submit" value="修改密码" /> <input type="reset" /></td>
		</tr>
	
	</table>

</form>

<a href = "UserPage.jsp">返回用户页面</a>

</body>
</html>