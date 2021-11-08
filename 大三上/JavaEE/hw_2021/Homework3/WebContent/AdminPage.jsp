<%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c" %>  
<%@ page language="java" pageEncoding="utf-8"%>
<%@ page import="java.util.*"%>
<%@ page import="SearchMan.Man" %>
<!DOCTYPE html>
<html>
<head>

<title>管理员页面</title>

</head>
<body>

	<form action="AdminServlet" method="get">
		增加一条信息：<br/>
		<table>
			<tr>
				<td>&nbsp;&nbsp; 用户id</td>
				<td>&nbsp;<input type="text" name="id"></td>
			</tr>
			<tr>
				<td>&nbsp;&nbsp; 用户姓名</td>
				<td>&nbsp;<input type="text" name="name"></td>
			</tr>
			<tr>
				<td>&nbsp;&nbsp; 电话号码</td>
				<td>&nbsp;<input type="text" name="tel"></td>
			</tr>
			<tr>
				<td>&nbsp;&nbsp; QQ号码</td>
				<td>&nbsp;<input type="text" name="qq"></td>
			</tr>
			<tr>
				<td>&nbsp;&nbsp; 用户邮箱</td>
				<td>&nbsp;<input type="text" name="mail"></td>
			</tr>
		</table>
		
		<input type="submit" name="action" value="add">
	</form>
	
	<br/>
	<form action="AdminServlet" method="get">
		删除一条信息：<br/>
		<table>
			<tr>
				<td>&nbsp;&nbsp; 用户id</td>
				<td>&nbsp;<input type="text" name="id"></td>
			</tr>
		</table>
		
		<input type="submit" name="action" value="delete">
	</form>
	
	<br/>
	<form action="AdminServlet" method="get">
		修改一条信息：<br/>
		<table>
			<tr>
				<td>&nbsp;&nbsp; 用户id</td>
				<td>&nbsp;<input type="text" name="id"></td>
			</tr>
			<tr>
				<td>&nbsp;&nbsp; 用户姓名</td>
				<td>&nbsp;<input type="text" name="name"></td>
			</tr>
			<tr>
				<td>&nbsp;&nbsp; 电话号码</td>
				<td>&nbsp;<input type="text" name="tel"></td>
			</tr>
			<tr>
				<td>&nbsp;&nbsp; QQ号码</td>
				<td>&nbsp;<input type="text" name="qq"></td>
			</tr>
			<tr>
				<td>&nbsp;&nbsp; 用户邮箱</td>
				<td>&nbsp;<input type="text" name="mail"></td>
			</tr>
		</table>
		
		<input type="submit" name="action" value="change">
	</form>
	
	<br/>
	<form action="SearchServlet" method="get">
		
		输入查询内容吧：<br/>
		<table>
			<tr>
				<td>&nbsp;&nbsp; 查询内容</td>
				<td>&nbsp;<input type="text" name="query"/></td>
			</tr>
			<tr>
				<td>&nbsp;&nbsp; 每页显示条数</td>
				<td>&nbsp;<input type="text" name="numPerPage"/></td>
			</tr>
		</table>
		
		<input type="submit" name="action" value="searchAdmin">
	</form>

</body>
</html>