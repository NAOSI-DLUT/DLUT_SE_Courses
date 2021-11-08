# JavaEE Response响应和Request请求

Web服务器接收到客户端的http请求，会针对每一次请求，分别创建一个用于代表请求的request对象、和代表响应的response对象。

request和response对象既然代表请求和响应，那么我们要获取客户机提交过来的数据，只需要找request对象，就行了。要向客户机输出数据，只需要找response对象就行了。

HttpServletRequest封装客户端相关信息，服务器Servlet程序可以通过request对象操作客户端信息
HttpServletResponse封装服务器向客户端发送响应数据信息，Servlet程序通过response对象向客户端发送响应

## Response

* response常用API
  setStatus：设置响应行当中的状态码
  setHeader：设置响应头信息
  getOutputStream：获得字节流 --- 输出响应体内容
  getWriter：获得字符流 --- 输出响应体内容
* HttpServletResponse继承ServletResponse接口，ServletResponse并没有提供与HTTP协议相关API，HttpServletResponse添加了与协议相关API
  JavaEE API 中并没有提供HttpServletResponse实现类---实现类由tomcat服务器提供的
* 常用状态码：200 302 304 404 500
  200 请求处理成功
  302 客户端重定向
  304 客户端访问资源没有被修改，客户端访问本地缓存
  404 访问资源不存在
  500 服务器内部出错

## Request

HttpServletRequest相比ServletRequest添加与协议相关的API
HttpServletRequest对象代表客户端的请求，当客户端通过HTTP协议访问服务器时，HTTP请求中的所有信息都封装在这个对象中，可通过这个对象的方法，获取客户这些信息。
HttpServletRequest分为四个部分



* 获取客户机信息
  几个方法：
  getRequestURL方法返回客户端发出请求完整URL
  getRequestURI方法返回请求行中的资源名部分
  getQueryString方法返回请求行中的参数部分
  getRemoteAddr方法返回发出请求的客户机的IP地址
  getMethod得到客户机请求方式
  getContextPath获得工程虚拟目录名称

  ​	URI和URL区别
  url:http://localhost:8080/Request/request1 （完整）
  uri:/Request/request1 （部分）

* 获取请求头信息
  getHeader获得头信息的值，转换一个字符串
  getHeaders获得头信息值，返回Enumeration
  getHeaderNames获得所有头信息名称，返回Enumeration//枚举类型

​	

*  获取请求参数
  什么是请求参数？
  用户用过请求提交服务器一些数据

  四个常用API
  getParameter
  getParameterValues
  getParameterNames
  getParameterMap



eg.

```html
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html>
  <head>
    <title>request.html</title>
  </head>
  
  <body>
    <h1>分别以get和post方式提交数据</h1>
    <h1>第一种 通过超链接提交数据 以？方式</h1>
    <a href="/Request/request4?name=zhangsan&&city=beijing"">超链接提交数据</a>
    <h1>第二种 通过form的post方式提交数据</h1>
    <form action="/Request/request4" method="post">
        请输入姓名<input type="text" name="name" /><br/>
        请输入城市<input type="text" name="city" /><br/>
        <input type="submit" value="提交" />
    </form>
  </body>
</html>
```

```java
package cn.lsl.request;
import java.io.IOException;
import java.io.PrintWriter;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

public class RequestServlet4 extends HttpServlet {

    public void doGet(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        //通过getParameter获得请求数据
        String name = request.getParameter("name");
        System.out.println(name);
        String city = request.getParameter("city");
        System.out.println(city);
    }


    public void doPost(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        doGet(request,response);
    }

}
```

