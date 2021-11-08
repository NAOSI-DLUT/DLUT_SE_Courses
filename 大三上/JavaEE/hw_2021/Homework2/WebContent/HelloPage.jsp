<%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c" %>  
<%@ page language="java" pageEncoding="utf-8"%>
<%@ page import="java.util.*"%>
<%@ page import="SearchMan.Man" %>
<!DOCTYPE html>
<html>

<head>
<title>软院找人</title>
</head>

<body>

<div class="container">

	<form action="SearchServlet" method="get">
		输入查询内容吧</br>
		<input type="text" name="query"/>
		每页显示 <input type="text" name="numPerPage"/> 条（默认5条）
		<input type="submit" value="Search">
		</br>
	</form>
	
</div>

</body>

</html>