# JavaEE 第五节课：Eclipse快速开发JSP

## 1. 使用Eclipse开发web项目（jsp）

在eclipse中创建的Web项目：

浏览器可以直接访问WebContent中的文件，例如http://localhost:7080/MyJspProject/index2.jsp

其中的index2.jsp就在WebContent目录中

但是保存在WebContent中的WEB-INF中的文件index1.jsp，就无法通过客户端直接访问。

## 2. 配置tomcat运行时环境

使得jsp与Servlet之间可以相互转换

jsp <-> Servlet

方法：将tomcat/lib中的servlet-api.jar加入项目的构建路径中。

（将jar包放入java Resources中，然后右键build path）

## 3.统一字符集编码

### 1）编码分类

* 设置jsp文件的编码（jsp文件中的pageEncoding属性）：jsp->java

* 设置浏览器读取jsp文件的编码（jsp文件中的content属性）：

  一般将上述设置成一致的编码，推荐使用UTF-8

* 文本编码：

  * 整个Eclipse中的文件统一设置
  * 设置某一个项目
  * 设置单独文件（对文件属性右键找properties->other）