<%@ page import="ssdut.work.pojo.User" %>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%request.setAttribute("defaultPath", User.getDefaultPath());%>
<html>
<head>
    <title>Face Match Result</title>
    <%@include file="../common/head.jsp"%>
</head>
<body>
<%@include file="../common/login_status.jsp"%>

<div class="container text-center">
    <h2 style="margin-top: 35px;margin-bottom: 35px;">查询结果</h2>
</div>

<div class="table">
    <table align="center" style="text-align: center; width: 50%" class="table table-striped table-bordered table-hover">
        <thead>
        <tr>
            <th>头像</th>
            <th>类别</th>
            <th>ID</th>
            <th>姓名</th>
            <th>用户名</th>
            <th>手机号</th>
            <th>QQ号</th>
            <th>邮箱</th>
        </tr>
        </thead>
        <tbody>
        <c:forEach items="${requestScope.users}" var="user">
            <tr>
                <td><img src="${pageContext.request.contextPath}/image/${not empty user.path ? user.path : defaultPath}" alt="icon" height="90px" width="60px"></td>
                <td>${user.isTeacher ? "老师" : "学生"}</td>
                <td>${user.id}</td>
                <td>${user.person.name}</td>
                <td>${user.username}</td>
                <td>${user.person.phoneNumber}</td>
                <td>${user.person.qqNumber}</td>
                <td>${user.person.mail}</td>
            </tr>
        </c:forEach>
        </tbody>
    </table>
</div>
</body>
</html>
