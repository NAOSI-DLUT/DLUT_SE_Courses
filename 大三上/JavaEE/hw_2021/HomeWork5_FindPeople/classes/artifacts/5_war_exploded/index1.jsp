<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core"%>
<!DOCTYPE html>
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" /> 
<title>Insert title here</title>
<style> 
      body{text-align:top} 
    </style> 
</head>
<body>
<a href="index.jsp">首页</a>
<c:choose>
    <c:when test="${role=='admin'}">
        管理员${AdminAcc}你好！
        <a href="account.jsp">返回管理员界面</a>
    </c:when>
    <c:when test="${role=='normal'}">
        用户${NorAcc}你好！
        <img style="width:80px; height:110px;" src="<%=request.getContextPath()%>/ShowImgServlet?photo=${NorAcc}">
        <form action="UploadServlet?id=${NorAcc}" method="post" enctype="multipart/form-data">
            <input type="file" name="uploadfile">
            <input id="button" type="submit" value="上传图片">
        </form>
    </c:when>
</c:choose>
<form action="TestServlet" method="post">
<p>	    <input type="text" style="width:500px; height:50px;" name="information" placeholder="可输入电话号码/学号/教工号/QQ/姓名/邮箱查询"/>
		<input type="submit" value="软院一下" style="background:blue;width:100px; height:50px;"/></p>
</form>
</body>
</html>