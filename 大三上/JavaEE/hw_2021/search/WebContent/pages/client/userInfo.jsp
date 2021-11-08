<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%@ page contentType="text/html;charset=UTF-8"%>
<%@page import="ssdut.work.pojo.User" %>
<%request.setAttribute("defaultPath", User.getDefaultPath());%>
<html>
<head>
    <title>User Info</title>
    <%@include file="../common/head.jsp"%>

    <script type="text/javascript">
        $(document).ready(function(e) {
            $("#file").change(function(e) {
                // alert("change事件触发");
                if(!this.file){
                    // alert("change事件触发");
                    $("#submit_").removeAttr("disabled");
                }
            });
        });
    </script>
</head>
<body>
<%@include file="../common/login_status.jsp"%>
<div class="container text-center" >
    <h2 style="margin-top: 30px;margin-bottom: 30px;">用户中心</h2>
    <hr>
</div>
<div class="container align-content-center" style="width: 60%;margin-top: 35px;">
    <div class="row justify-content-center" style="height: 300px;">
        <div class="col-sm-6 align-self-center text-center" style="height: 200px;">
            <img src="${pageContext.request.contextPath}/image/${not empty sessionScope.user.path ? sessionScope.user.path : defaultPath}" alt="icon" height="200px" width="150px">
        </div>
        <div class="col-sm-6" style="margin-top: 50px;margin-bottom: 50px;">
            <div class="row">
                <div class="col-sm-6">用户名：</div>
                <div class="col-sm-6">${sessionScope.user.username}</div>
            </div>
            <div class="row">
                <div class="col-sm-6">${(sessionScope.user.isTeacher)?"教师":"学生"}ID：</div>
                <div class="col-sm-6">${sessionScope.user.id}</div>
            </div>
            <div class="row">
                <div class="col-sm-6">上传/修改头像</div>
                <div class="col-sm-6">
                    <form action="${pageContext.request.contextPath}/userServlet?action=update&username=${sessionScope.user.username}" method="post" enctype="multipart/form-data">
                        <input type="file" name="icon" id="file">
                        <input type="submit" value="上传" id="submit_" disabled>
                    </form>
                </div>
            </div>
        </div>
    </div>
</div>
</body>
</html>
