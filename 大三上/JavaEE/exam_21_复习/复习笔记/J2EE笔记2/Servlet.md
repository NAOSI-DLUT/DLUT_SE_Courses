# Servlet

公共接口Servlet

定义所有servlet必须实现的方法。

servlet是在Web服务器中运行的小型Java程序。servlet接收和响应来自Web客户端的请求，通常是通过超文本传输协议HTTP。

为了实现这个接口，您可以编写一个通用的servlet来扩展javax.servlet.GenericServlet或扩展的HTTP servletjavax.servlet.http.HttpServlet。

这个接口定义了初始化servlet、服务请求和从服务器删除servlet的方法。这些方法称为生命周期方法，按以下顺序调用：

构建servlet，然后用init方法初始化。

处理从客户端到服务方法的任何调用。

servlet停止服务，然后使用destroy方法销毁，然后进行垃圾收集并最终完成。

除了生命周期方法之外，这个接口还提供了getServletConfig方法（servlet可以使用它来获取任何启动信息）和getServletInfo方法，它允许servlet返回有关自身的基本信息，如作者、版本和版权

* 已知实现类

  [FacesServlet](https://javaee.github.io/javaee-spec/javadocs/javax/faces/webapp/FacesServlet.html), [GenericServlet](https://javaee.github.io/javaee-spec/javadocs/javax/servlet/GenericServlet.html), [HttpServlet](https://javaee.github.io/javaee-spec/javadocs/javax/servlet/http/HttpServlet.html)

## init

``` java
void init(ServletConfig config)
   throws ServletException
```

由servlet容器调用，以向servlet指示servlet正在被置于服务中。

在实例化servlet之后，servlet容器只调用init方法一次。在servlet可以接收任何请求之前，init方法必须成功完成。

抛出异常服务

服务器未在时间段内定义返回

parameters：

config—一个ServletConfig对象，包含servlet的配置和初始化参数

throws：

ServletException—如果发生了干扰servlet正常操作的异常



## getServletConfig

```java
ServletConfig getServletConfig()
```

返回一个ServletConfig对象，该对象包含此servlet的初始化和启动参数。返回的ServletConfig对象是传递给init方法的对象。

这个接口的实现负责存储ServletConfig对象，以便这个方法可以返回它。实现此接口的GenericServlet类已经完成了此操作。

**Returns:**

the `ServletConfig` object that initializes this servlet



## service

```java
void service(ServletRequest req,ServletResponse res)
      throws ServletException,
             IOException
```

由servlet容器调用以允许servlet响应请求。

只有在servlet的init（）方法成功完成后才会调用此方法。

servlet通常在多线程servlet容器中运行，这些容器可以同时处理多个请求。开发人员必须知道同步访问任何共享资源，如文件、网络连接以及servlet的类和实例变量。

参数：

req-包含客户端请求的ServletRequest对象

res-包含servlet响应的ServletResponse对象

投掷：

ServletException—如果发生干扰servlet正常操作的异常

IOException-如果发生输入或输出异常

## getServletInfo

``` java
String getServletInfo()
```

Returns information about the servlet, such as author, version, and copyright.

The string that this method returns should be plain text and not markup of any kind (such as HTML, XML, etc.).



## destory

``` java
void destory
```

Called by the servlet container to indicate to a servlet that the servlet is being taken out of service. This method is only called once all threads within the servlet's `service` method have exited or after a timeout period has passed. After the servlet container calls this method, it will not call the `service` method again on this servlet.s



