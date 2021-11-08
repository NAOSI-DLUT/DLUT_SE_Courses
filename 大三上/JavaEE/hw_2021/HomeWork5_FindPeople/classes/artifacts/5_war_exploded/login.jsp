<%--
  Created by IntelliJ IDEA.
  User: 26960
  Date: 2020/10/18
  Time: 9:57
  To change this template use File | Settings | File Templates.
--%>
<%@ page language="java" contentType="text/html; charset=UTF-8"
         pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>

</head>
<body>
<a href="index.jsp">首页</a>
<form action="LoginServlet" method="post">
    <p>
        <input type="text" style="width:500px; height:40px;" name="account" placeholder="请输入帐号"/>
        <input type="password" style="width:500px; height:40px;" name="password" placeholder="请输入密码"/>
        <input type="submit" name="role" value="normal" style="background:blue;width:100px; height:45px;"/>
        <input type="submit" name="role" value="admin" style="background:blue;width:100px; height:45px;">
    </p>
</form>
</body>
</html>
