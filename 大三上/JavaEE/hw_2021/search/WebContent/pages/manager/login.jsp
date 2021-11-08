<%@ page contentType="text/html;charset=UTF-8" %>
<html>
<head>
    <title>Login</title>
    <%@include file="../common/head.jsp"%>
</head>
<body>
<div class="col-sm-2 text-center" style="margin-top: 20px;">
    <a href="pages/client/search.jsp">首页</a>
</div>
<div class="container text-center" style="margin-top: 35px;margin-bottom: 35px;">
    <h2>欢迎登录</h2>
    <hr/>
</div>
<div class="msg_cont">
    <div class="text-center" style="margin-top: 50px;margin-bottom: 30px;">
        ${ empty requestScope.msg ? "请输入用户名和密码":requestScope.msg }
    </div>
</div>
<div class="container" align="center">
    <form action="${pageContext.request.contextPath}/login" method="post">
        <input type="hidden" name="action" value="login" />
        <input type="hidden" name="uri" value="${param.uri}">
        <input type="hidden" name="pageNo" value="${param.pageNo}">
        <input type="hidden" name="pageSize" value="${param.pageSize}">
        <label>用户名称：</label>
        <input type="text" placeholder="请输入用户名"
               autocomplete="off" tabindex="1" name="username"
               value="${requestScope.username}" />
        <br />
        <br />
        <label>用户密码：</label>
        <input type="password" placeholder="请输入密码"
               autocomplete="off" tabindex="1" name="password" />
        <br />
        <br />
        <input type="submit" value="登录" id="sub_btn" />
    </form>
</div>
</body>
</html>
