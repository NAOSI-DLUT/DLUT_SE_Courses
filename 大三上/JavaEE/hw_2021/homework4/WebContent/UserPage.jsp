<%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c" %>  
<%@ page language="java" pageEncoding="utf-8"%>
<!DOCTYPE html>
<html>

<head>
<title>User Page</title>
</head>

<body>

<%= request.getSession().getAttribute("id") %>

<br/>

<a href = "LogIn.jsp">重新登录</a>

<br/>

<form action="SearchServlet" method="get">
		
	输入查询内容吧：<br/>
	<table>
		<tr>
			<td>&nbsp;&nbsp; 查询内容</td>
			<td>&nbsp;<input type="text" name="query"/></td>
		</tr>
		<tr>
			<td>&nbsp;&nbsp; 每页显示条数</td>
			<td>&nbsp;<input type="text" name="numPerPage"/></td>
		</tr>
	</table>
	
	<input type="submit" name="action" value="searchAdmin">
</form>

<br/>

<a href = "UploadImg.jsp">上传照片</a>

<br/>

<a href = "IfHaveImgServlet">查看照片</a>

<br/>

<a href = "DeleteImgServlet">删除照片</a>


<br/>

<a href = "ChangePwd.jsp">修改密码</a>

</body>
</html>