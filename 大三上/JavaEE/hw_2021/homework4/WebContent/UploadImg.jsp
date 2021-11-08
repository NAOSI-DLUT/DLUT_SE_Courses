<%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c" %>  
<%@ page language="java" pageEncoding="utf-8"%>
<%@ page import="java.util.*"%>

<%
	String path = request.getContextPath();
	String id = (String)request.getAttribute("id");
	String basePath = request.getScheme() + "://"
			+ request.getServerName() + ":" + request.getServerPort()
			+ path + "/";
%>

<!DOCTYPE html>
<html>

<head>
<base href="<%=basePath%>">
<title>上传图片</title>
</head>

<body>

<form action="UploadServlet" method="post" enctype="multipart/form-data">

	<table>
		<tr>
			<td>选择上传的图片 </td>
			<td><input type="file" name="uploadFile">
		</tr>
		<tr>
		</tr>
		<tr>
		<td align="center" colspan="2"><input id="button" type="submit" value="上传图片">
		</tr>
	</table>

</form>

<a href = "UserPage.jsp">返回用户页面</a>



</body>
</html>