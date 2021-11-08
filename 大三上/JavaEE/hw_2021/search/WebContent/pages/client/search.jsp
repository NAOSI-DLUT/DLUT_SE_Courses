<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
<title>Search</title>
    <%@ include file="../common/head.jsp"%>

    <script>
        function loadFile(file){
            $("#filePos").html(file.name);
        }

        function submitForm1(){
            document.getElementById("form1").submit();
        }
        function submitForm2(){
            document.getElementById("form2").submit();
        }
    </script>

</head>

<body>

<%@include file="../common/login_status.jsp"%>

    <div class="container text-center" >
        <h2 style="margin-top: 20px;margin-bottom: 35px;">软院找人</h2>
        <hr/>
    </div>

    <div class="container text-center" style="margin-top: 50px;">
    <form action="${pageContext.request.contextPath}/search" method="post" id="form1">
        <input type="hidden" name="action" value="page">
        <input type="hidden" name="update" value="update">
        <div class="form-group form-inline ">
            <div class="col-sm-6 text-right">学号/教工号:</div>
            <div class="col-sm-6 text-left">
                <input type="text" autocomplete="off" name="id" size="16"/>
            </div>
        </div>
        <div class="form-group form-inline ">
            <div class="col-sm-6 text-right">查找范围:</div>
            <div class="col-sm-6 text-left">
                <input type="checkbox" name="type" value="teacher"/> 老师
                <input type="checkbox" name="type" value="student"/> 学生
            </div>
        </div>
        <div class="form-group form-inline">
            <div class="col-sm-6 text-right ">姓名：</div>
            <div class="col-sm-6 text-left">
                <input type="text" autocomplete="off" name="name" size="16"/>
            </div>
        </div>
        <div class="form-group form-inline">
            <div class="col-sm-6 text-right">手机号：</div>
            <div class="col-sm-6 text-left">
                <input type="text" autocomplete="off" name="phoneNumber" size="16"/>
            </div>
        </div>
        <div class="form-group form-inline">
            <div class="col-sm-6 text-right">qq号：</div>
            <div class="col-sm-6 text-left">
                <input type="text" autocomplete="off" name="qqNumber"   size="16"/>
            </div>
        </div>
        <div class="form-group form-inline">
            <div class="col-sm-6 text-right">电子邮箱：</div>
            <div class="col-sm-6 text-left">
                <input type="text" autocomplete="off" name="mail" size="16"/>
            </div>
        </div>

        <div class="row">
            <div class="col-sm-6">
            </div>
            <div class="col-sm-6 text-left">
                <input type="submit" class="btn btn-light" value="搜索" onclick="submitForm1()"/>
            </div>
        </div>
    </form>
   
    </div>

</body>
</html>