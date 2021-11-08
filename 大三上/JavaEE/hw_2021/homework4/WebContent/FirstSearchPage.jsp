<%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c" %>  
<%@ page language="java" pageEncoding="utf-8"%>
<%@ page import="java.util.*"%>
<%@ page import="searchMan.Man" %>
<!DOCTYPE html>
<html>

<head>
<title>软院找人</title>
</head>

<body>

<div class="container">

	<% System.out.println("in FirstSearch jsp"); %>

	<c:set var="from" value="${sessionScope.from }"/>
	<c:set var="admin" value="admin"/>

	<form action="SearchServlet" method="get">
		输入查询内容吧
		<input type="text" name="query"/>
		每页显示 <input type="text" name="numPerPage"/> 条（默认5条）
		<input type="submit" value="Search">
	</form>
	
	<a href = "LogIn.jsp">重新登录</a>
	
	<c:choose>
		<c:when test="${from eq admin}">
			<a href = "AdminPage.jsp">返回管理员页</a>
		</c:when>
		<c:otherwise>
			<a href = "UserPage.jsp">返回用户页</a>
		</c:otherwise>
	</c:choose>
	
</div>

</body>

</html>