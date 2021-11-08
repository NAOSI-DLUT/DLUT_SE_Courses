# JavaEE Session

 在做网站开发的时候，我们经常会用到session对象，下面我来谈谈对session的理解；

 Java Servlet API引入session 机制来跟踪客户的状态，session指的是在一段时间内，单个客户和web

服务器之间一连串的交互过程，在一个session中，一个客户可能会多次请求同一个网页，也可能请求多个不同服务器资源，例如：在一个邮件系统应用中，从一个客户登录到邮件系统，到写信，收信和发信等，到最后退出邮件系统，整个过程为一个session；再例如：大家在网上购物的时候，从购物到最后的付款，整个过程也是一个session 。



session对像是jsp中的内置对象，可以直接使用；在Servlet中使用session时，必须先创建出该对象，Servlet中创建session的方法：

```java
HttpSession session=request.getSession();   
HttpSession session=request.getSession(boolean value);
```

在服务器上，通过session ID来区分每一个请求服务器的用户，用户只要一连接到服务器，服务器就会为之分配一个唯一的不会重复的session ID，session ID由服务器统一管理，人为不能控制.



## session中的主要方法：

```java


session.getId();//获取session ID，长度为32位
session.isNew();//判断是否是新建立的session 

 

session.getCreationTime();//获取session创建的时间   

session.getLastAccessedTime();//获取用户最后操作时间
sesson.setAttribute(String key,Object value);//将对象存到session中    

 

session.getAttribute(String key);//获取session中存的Object对象   

session.removeAttribute(String key);//将键值为key的对象从session中删除
```

## 补充：session与cookie的区别

1. session将信息保存在服务器上，cookie保存在客户端上
2. session比cookie更安全，session比cookie更占资源
3. session使用cookie的机制，如果cookie被禁用，那么session也无法使用，因为session ID是以cookie的形式保存在客户端的内存当中

