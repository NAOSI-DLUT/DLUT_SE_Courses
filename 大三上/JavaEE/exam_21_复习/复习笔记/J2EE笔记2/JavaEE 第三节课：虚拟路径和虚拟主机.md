# **JavaEE 第三节课：虚拟路径和虚拟主机**

## 1. 虚拟路径配置方法

### 1）第一种

即将web项目配置到webapps以外的目录

在D:\apache-tomcat-9.0.37-windows-x64\apache-tomcat-9.0.37\conf\server.xml文件中，找到

```xml
<Host name="localhost"  appBase="webapps"
            unpackWARs="true" autoDeploy="true">

        <!-- SingleSignOn valve, share authentication between web applications
             Documentation at: /docs/config/valve.html -->
        <!--
        <Valve className="org.apache.catalina.authenticator.SingleSignOn" />
        -->

        <!-- Access log processes all example.
             Documentation at: /docs/config/valve.html
             Note: The pattern used is equivalent to using pattern="common" -->
        <Valve className="org.apache.catalina.valves.AccessLogValve" directory="logs"
               prefix="localhost_access_log" suffix=".txt"
               pattern="%h %l %u %t &quot;%r&quot; %s %b" />

      </Host>
```

其中，appBase代表着项目所配置到的默认目录

配置虚拟路径需要在<Host></Host>中加入：

```xml
<Context docBase="" path=""/>
```

其中docBase中的路径为项目实际所在的路径，path为之前项目所位于webapps内的路径（可以为相对路径也可以为绝对路径），结果是，访问path内的路径相当于访问docBase内的路径。所以可以将项目配置到docBase中去了。



缺点：配置完了tomcat需要重启

### 2) 第二种

在目录D:\apache-tomcat-9.0.37-windows-x64\apache-tomcat-9.0.37\conf\Catalina\localhost

中新建一个与项目名相同的xml文件：项目名.xml

在xml文件中写入：

```xml
<Context docBase="" path=""/>
```

## 

## 2. 虚拟主机

将主机名称改成自己想要的域名如：www.jd.com

在本地域名解析器中修改，域名与 ip地址之间的映射

如：通过www.test.com 访问本机

在D:\apache-tomcat-9.0.37-windows-x64\apache-tomcat-9.0.37\conf\server.xml文件中

找到

```xml
<Engine name="Catalina" defaultHost="localhost">
```

把默认主机defaultHost改为“www.test.com”

再加入(例子)：

```xml
<Host appBase="D:\study\JspProject" name="www.test.com">
    <Context docBase="D:\study\JspProject" path="/">
</Host>
```

最后在本机的host文件

C:\Windows\System32\drivers\etc\host

中加入映射

127.0.0.1 www.test.com







