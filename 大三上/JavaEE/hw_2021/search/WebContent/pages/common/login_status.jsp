<%@ page contentType="text/html;charset=UTF-8" language="java" %>

<%
    String uri = request.getRequestURI();
    if(request.getQueryString()!=null){
        uri += "?" + request.getQueryString();
    }
    request.setAttribute("last_uri",uri);
%>

<div class="row" style="margin-top: 15px;margin-bottom: 15px;">
    <div class="col-sm-2 text-center">
        <a href="pages/client/search.jsp">首页</a>
    </div>
    <div class="col-sm-7"></div>
    <div class="text-center col-sm-3">
        <c:if test="${sessionScope.user == null}">
            <a href="pages/manager/login.jsp?uri=${requestScope.last_uri}">登录</a>&nbsp;&nbsp;
            <a href="pages/client/search.jsp">注册</a>
        </c:if>
        <c:if test="${sessionScope.user != null}">
            <div class="row">
                <span>欢迎${ sessionScope.user.username }！</span>&nbsp;&nbsp;
                <a href="pages/client/userInfo.jsp">用户中心</a>&nbsp;&nbsp;&nbsp;&nbsp;
                <a href="pages/client/new.jsp">我的消息</a>&nbsp;&nbsp;&nbsp;&nbsp;
                <a href="${pageContext.request.contextPath}/login?action=logout&username=${sessionScope.user.username}">注销</a>
            </div>
        </c:if>
    </div>
</div>

