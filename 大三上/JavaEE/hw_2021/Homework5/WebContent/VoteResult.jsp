<%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c" %>  
<%@ page pageEncoding="utf-8"%>
<%@ page import="Vote.VoteObject" %>
<!DOCTYPE html>
<html>
<head>
	<title>Vote Result Tomcat2</title>
	<!--  <meta http-equiv="refresh" content="10; GetResultServlet"></head>-->
<body> 

<c:set var="userid" value="${requestScope.userid }"/>

<% System.out.println("in VoteResult.jsp"); %>

<c:set var="currentResult" value="${requestScope.voteResult }"/>

<a href = "LogIn.jsp">返回重新登录</a>

<br />
<br />

<a href = "GetVoteServlet?userid=${userid }">继续投票</a>

<br />
<br />
  
<table>
	
	<c:forEach items="${currentResult }" var="item">
	
		<tr>
			<td>${item.getName() }</td>
			<td>${item.getNum() } 票</td>
		</tr>
		
	</c:forEach>
	

</table>

<br />
<br />
<a href = "GetResultServlet?userid=${userid }">刷新投票结果</a>

<%
	String userid = (String)request.getAttribute("userid");
	System.out.println("userid = " + userid);
	String content= 5 +";URL=GetResultServlet?userid=" + userid;
	response.setHeader("REFRESH",content);
%>

<!--  
<script type="text/javascript">
	setInterval(window.location.href = "GetResultServlet?userid=${userid}", 10000);
</script>
-->

</body>

</html>