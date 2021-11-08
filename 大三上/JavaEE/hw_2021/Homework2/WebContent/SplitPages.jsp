<%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c" %>  
<%@ page language="java" pageEncoding="utf-8"%>
<%@ page import="java.util.*"%>
<%@ page import="SearchMan.Man" %>
<!DOCTYPE html>

<html>

<head>
	<title>软院找人</title>
</head>

<body>


<div class="container">

	<c:set var="currentPageMan" value="${requestScope.manList}"/>
	<c:set var="totalPageCount" value="${requestScope.totalPageCount }"/>
	<c:set var="currentPage" value="${requestScope.currentPage }" />
	<c:set var="totalRows" value="${requestScope.maxRows }" />
	<c:set var="numPerPage" value="${requestScope.numPerPage }"/>

	<form action="SearchServlet" method="get">
		输入查询内容吧
		<input type="text" name="query"/>
		<input type="submit" value="Search">
	</form>
	<br>
	当前共查询到${totalRows }条信息，每页显示${numPerPage }条信息<p>
	
	<form action="SearchServlet" method="get">
		更新每页显示数量为 
		<input type="text" name="updatePerPage" />
		<input type="submit" value="Update" />
	</form>
	<br>

	<table class="table table-hover table-responsive table-striped table-bordered">
	
		<thread>
		<tr>
			<td>ID</td>
			<td>姓名</td>
			<td>电话号码</td>
			<td>QQ</td>
			<td>邮箱</td>
		</tr>
		</thread>
	
		<tbody>
		<c:forEach items="${currentPageMan}" var="man">  
			<tr>
                <td>${man.getID()}</td>
                <td>${man.getName()}</td>
                <td>${man.getTel()}</td>
                <td>${man.getQq()}</td>
                <td>${man.getMail()}</td>
            </tr>
		</c:forEach>
		</tbody>
	</table>
	
	<hr>
	
	<c:if test="${currentPage == 1}">
		<a>首页</a>
		<a>上一页</a>
	</c:if>
	
	<c:if test="${currentPage > 1}">
		<a href="SearchServlet?currentPage=1">首页</a>
		<a href="SearchServlet?currentPage=${currentPage-1 }">上一页</a>
	</c:if>
	
	<c:forEach begin="1" end="${totalPageCount}" varStatus="loop">
        <c:set var="active" value="${loop.index==currentPage?'active':''}"/>
        <class="${active}">
        	<a href="SearchServlet?currentPage=${loop.index}">${loop.index}</a>
        </class>
    </c:forEach>
             
    <c:if test="${currentPage == totalPageCount}">
		<a>下一页</a>
		<a>尾页</a>
	</c:if>
	
	<c:if test="${currentPage < totalPageCount}">
		<a href="SearchServlet?currentPage=${currentPage+1}">下一页</a>
		<a href="SearchServlet?currentPage=${totalPageCount}">尾页</a>
	</c:if>
	
</div>

</body>

</html>