<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<%
    String basePath = request.getScheme()
            + "://"
            + request.getServerName()
            + ":"
            + request.getServerPort()
            + request.getContextPath()
            + "/";
%>

<!--写base标签，永远固定相对路径跳转的结果-->
<meta charset="UTF-8">
<base href="<%=basePath%>">
<link rel="stylesheet" href="static/css/style.css">
<!-- <link rel="stylesheet" href="static/css/bootstrap.min.css"> -->
<script src="static/javascript/jquery-3.2.1.min.js"></script>
<script src="static/javascript/bootstrap.bundle.min.js"></script>
<script src="static/javascript/bootstrap.min.js"></script>
