<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>Show</title>
    <%@include file="../common/head.jsp"%>
    <style>
        td {
            width: 200px;
        }
    </style>
</head>
<body>
<%@include file="../common/login_status.jsp"%>
<div class="container text-center">
    <h2 style="margin-top: 35px;margin-bottom: 35px;">查询结果</h2>
</div>
<div class="table">
    <table align="center" style="text-align: center; width: 70%" class="table table-striped table-bordered table-hover">
        <thead>
        <tr>
            <th>类别</th>
            <th>ID</th>
            <th>姓名</th>
            <th>手机号</th>
            <th>QQ号</th>
            <th>邮箱</th>
            <c:if test="${not empty sessionScope.user}">
                <th>在线状态</th>
            </c:if>
            <c:if test="${sessionScope.user.isAdmin}">
                <th colspan="2">操作</th>
            </c:if>
        </tr>
        </thead>
        <tbody>
        <c:forEach items="${requestScope.page.teachers}" var="teacher">
            <tr>
                <td>老师</td>
                <td>${teacher.id}</td>
                <td>${teacher.name}</td>
                <td>${teacher.phoneNumber}</td>
                <td>${teacher.qqNumber}</td>
                <td>${teacher.mail}</td>
                <c:if test="${sessionScope.user.isAdmin}">
                    <td><a href="${pageContext.request.contextPath}/teacherServlet?action=getTeacher&id=${teacher.id}&pageNo=${requestScope.page.pageNo}&pageSize=${requestScope.page.pageSize}">修改</a></td>
                    <td><a href="${pageContext.request.contextPath}/teacherServlet?action=delete&id=${teacher.id}&pageNo=${requestScope.page.pageNo}&pageSize=${requestScope.page.pageSize}">删除</a></td>
                </c:if>
                <c:if test="${not empty sessionScope.user}">
                <c:set var="flag" value="0"/>
                <c:forEach items="${applicationScope.login_users}" var="user">
                    <c:if test="${user.isTeacher && user.id==teacher.id}">
                <%--                        --%>
                <%--                        --%>
<%--                        <td>在线</td>--%>
                        <td><a href="${pageContext.request.contextPath}/msg?action=message&username=${sessionScope.user.username}&tar_username=${user.username}">在线</a></td>
                        <c:set var="flag" value="1"/>
                    </c:if>
                </c:forEach>
                <c:if test="${flag==0}">
                    <td>离线</td>
                </c:if>
                </c:if>
            </tr>
        </c:forEach>
        <c:forEach items="${requestScope.page.students}" var="student">
            <tr>
                <td>学生</td>
                <td>${student.id}</td>
                <td>${student.name}</td>
                <td>${student.phoneNumber}</td>
                <td>${student.qqNumber}</td>
                <td>${student.mail}</td>
                <c:if test="${sessionScope.user.isAdmin}">
                    <td><a href="${pageContext.request.contextPath}/studentServlet?action=getStudent&id=${student.id}&pageNo=${requestScope.page.pageNo}&pageSize=${requestScope.page.pageSize}">修改</a></td>
                    <td><a href="${pageContext.request.contextPath}/studentServlet?action=delete&id=${student.id}&pageNo=${requestScope.page.pageNo}&pageSize=${requestScope.page.pageSize}">删除</a></td>
                </c:if>
                <c:if test="${not empty sessionScope.user}">
                <c:set var="flag" value="0"/>
                <c:forEach items="${applicationScope.login_users}" var="user">
                    <c:if test="${!user.isTeacher && user.id==student.id}">
                        <%--                        --%>
                        <%--                        --%>
<%--                        <td>在线</td>--%>
                        <td><a href="${pageContext.request.contextPath}/msg?action=message&username=${sessionScope.user.username}&tar_username=${user.username}">在线</a></td>
                        <c:set var="flag" value="1"/>
                    </c:if>
                </c:forEach>
                <c:if test="${flag==0}">
                    <td>离线</td>
                </c:if>
                </c:if>
            </tr>
        </c:forEach>
        <c:if test="${sessionScope.user.isAdmin}">
        <tr>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>
            <td></td>

            <td><a href="pages/manager/info_edit.jsp?type=1&pageNo=${requestScope.page.pageNo}&pageSize=${requestScope.page.pageSize}">添加老师</a></td>
            <td><a href="pages/manager/info_edit.jsp?type=0&pageNo=${requestScope.page.pageNo}&pageSize=${requestScope.page.pageSize}">添加学生</a></td>
        </tr>
        </c:if>
        </tbody>
    </table>

</div>

<%--分页条的开始--%>

<%--分页条的结束--%>
</body>
</html>
