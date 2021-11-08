<%@ page import="ssdut.work.pojo.*" %>
<%@ page import="java.util.List" %>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>

<html>
<head>
    <title>New</title>
    <%@include file="../common/head.jsp"%>
</head>
<body>
<%@include file="../common/login_status.jsp"%>
<div class="container text-center">
    <h2 style="margin-top: 35px;margin-bottom: 35px;">我的消息</h2>
</div>
<%--<c:forEach items="${applicationScope.login_users}" var="login_user">--%>
<%--    <p>${login_user.username}</p>--%>
<%--</c:forEach>--%>
<%
    User user = (User) session.getAttribute("user");
    List<String> msgList = (List) application.getAttribute(user.getUsername()+"_msg");
    request.setAttribute("msgList", msgList);
%>
<div class="container text-center">
    <c:if test="${empty requestScope.msgList}" >
        <p>暂无消息</p>
    </c:if>
    <table class="text-center table table-striped">
        <c:forEach items="${requestScope.msgList}" var="msg">
            <tr>
                <td><a href="${pageContext.request.contextPath}/msg?action=message&username=${sessionScope.user.username}&tar_username=${msg}">与${msg}的会话</a></td>
            </tr>
        </c:forEach>
    </table>
</div>

</body>
</html>
