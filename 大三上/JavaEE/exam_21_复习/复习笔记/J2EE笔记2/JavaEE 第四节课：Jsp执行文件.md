# JavaEE 第四节课：Jsp执行流程

jsp -> java(servlet文件) -> class

文件存储在下列目录：

D:\apache-tomcat-9.0.37-windows-x64\apache-tomcat-9.0.37\work\Catalina\localhost\JSPprojects\org\apache\jsp



第一次请求服务端 会有翻译和编译的过程，所以比较慢，后续访问可以直接访问class，所以速度较快。到那时如果服务器端修改了代码，所以再次访问时会重新翻译和编译