<%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c" %>  
<%@ page language="java" pageEncoding="utf-8"%>
<!DOCTYPE html>
<html>
<head>
<title>VotePage Tomcat2</title>
</head>
<body>

<c:set var="currentVoteInfo" value="${requestScope.voteInfo}"/>
<c:set var="userid" value="${requestScope.userid }"/>


<a href = "GetResultServlet?userid=${userid }">直接查看结果${userid }</a>

<form action="VoteServlet" method="get">
	<input type="hidden" name="userid" value=${userid }>
	<c:forEach items="${currentVoteInfo}" var="name">
		<input type='radio' name="choose" value="${name}"/>${name}
	</c:forEach>

	<input type="submit" value="choose" />
</form>

</body>
</html>