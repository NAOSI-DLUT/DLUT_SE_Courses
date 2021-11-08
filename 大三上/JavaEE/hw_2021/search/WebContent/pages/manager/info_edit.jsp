<%@ page contentType="text/html;charset=UTF-8"%>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<html>
<head>
    <title>Info Edit</title>
    <%@include file="../common/head.jsp"%>
</head>
<body>

<%@include file="../common/login_status.jsp"%>

<div class="container text-center">
    <h2 style="margin-top: 20px;margin-bottom: 35px;">修改信息</h2>
    <hr/>
</div>
<div class="container text-center" style="margin-top: 100px;">
<c:if test="${not empty requestScope.teacher}">
    <form class="form-inline" action="${pageContext.request.contextPath}/teacherServlet">
    </c:if>
<c:if test="${not empty requestScope.student}">
    <form class="form-inline" action="${pageContext.request.contextPath}/studentServlet">
</c:if>
<c:if test="${param.type==1}">
<%--老师--%>
    <form class="form-inline" action="${pageContext.request.contextPath}/teacherServlet">
</c:if>
<c:if test="${param.type==0}">
    <form class="form-inline" action="${pageContext.request.contextPath}/studentServlet">
</c:if>
    <input type="hidden" name="action" value="${empty param.id ? "add" : "update"}">
    <input type="hidden" name="pageNo" value="${param.pageNo}">
    <input type="hidden" name="pageSize" value="${param.pageSize}">
    <table>
            <thead>
            <tr>
                <th>ID</th>
                <th>姓名</th>
                <th>手机号</th>
                <th>QQ号</th>
                <th>邮箱</th>
            </tr>
            </thead>
            <tbody>
            <c:if test="${(not empty requestScope.teacher)&&(empty requestScope.student)}">
                <tr>
                    <td><input name="id" type="text" value="${requestScope.teacher.id}"/></td>
                    <td><input name="name" type="text" value="${requestScope.teacher.name}"/></td>
                    <td><input name="phoneNumber" type="text" value="${requestScope.teacher.phoneNumber}"/></td>
                    <td><input name="qqNumber" type="text" value="${requestScope.teacher.qqNumber}"/></td>
                    <td><input name="mail" type="text" value="${requestScope.teacher.mail}"/></td>
                    <td><input type="submit" value="提交"/></td>
                </tr>
            </c:if>
            <c:if test="${(not empty requestScope.student )&& (empty requestScope.teacher)}">

                <input type="hidden" name="action" value="update">
                <tr>
                    <td><input name="id" type="text" value="${requestScope.student.id}"/></td>
                    <td><input name="name" type="text" value="${requestScope.student.name}"/></td>
                    <td><input name="phoneNumber" type="text" value="${requestScope.student.phoneNumber}"/></td>
                    <td><input name="qqNumber" type="text" value="${requestScope.student.qqNumber}"/></td>
                    <td><input name="mail" type="text" value="${requestScope.student.mail}"/></td>
                    <td><input type="submit" value="提交"/></td>
                </tr>
            </c:if>
            <c:if test="${(empty requestScope.student )&& (empty requestScope.teacher)}">
                <input type="hidden" name="action" value="add">
                <tr>
                    <td><input name="id" type="text" value=""/></td>
                    <td><input name="name" type="text" value=""/></td>
                    <td><input name="phoneNumber" type="text" value=""/></td>
                    <td><input name="qqNumber" type="text" value=""/></td>
                    <td><input name="mail" type="text" value=""/></td>
                    <td><input type="submit" value="提交"/></td>
                </tr>
            </c:if>
            </tbody>
        </table>
    </form>
</div>

</body>
</html>
