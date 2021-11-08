# JavaEE 第二节课：JSP基础

## 1. CS 模式：

服务器到客户端模式，每个客户端都需要在本地下载一个应用，这样服务器端更新后客户端也需要更新

## 2. BS 模式：

browser -> server即浏览器到服务器端模式， 客户端浏览器直接从服务器端请求对象，所以服务器端更新后，客户端不用更新，但是速度较慢。

## 3. Tomcat 解压后目录

### 目录

* bin：可执行文件

* 有start.bat 以及 shutdown.bat

* conf:配置文件（server.xml）

* lib:tomcat依赖的jar文件 
  * 在tomcat目录中的lib中配置jar文件，是全局配置，即所有的项目都会有该jar文件

* log：日志文件（记录出错等信息）
* temp:临时文件
* webapps：可执行项目（我们开发的项目都放在里面）
* work：存放由jsp翻译成的java，以及编辑成的class文件（jsp->java->class）

### 访问tomcat：

http://localhost:8080/ ,8080为tomcat的端口号

## 4. webapps中项目构建

* 需要root文件夹中的web-inf文件

  web-inf文件中需要有：

  * 需要创建classes文件夹保存class文件

  * 需要lib文件夹保存jar文件



建立index.jsp文件

```html
<html>
	<head>
		<titel>
			hello world
		</titel>
	</head>
	<body>
		hello jsp
		<%
				out.print("hello world");
		%>
	</body>
	
</html>
```

其中<%%>内嵌的是java代码，即jsp就是将java代码嵌入html文件中

