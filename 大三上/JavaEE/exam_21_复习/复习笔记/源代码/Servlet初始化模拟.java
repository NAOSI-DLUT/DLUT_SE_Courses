package test;

interface ServletConfig {
    public String getInitParameter(String name);
}
abstract class GenericServlet implements ServletConfig {

    private transient ServletConfig config;

    public void init(ServletConfig config) {
        this.config = config;
        init();
    }
    public void init() {
        
    }
    public String getInitParameter(String name) {
        return "name value";
    }
}
abstract class HttpServlet extends GenericServlet {

    public void doGet() {
    }
    public void doPost() {
    }
}

public class MyServlet extends HttpServlet {
    /*public void init(ServletConfig config){
    super.init(config);
    System.out.println("Main::init(ServletConfig config)");
    }*/

    public void init() {
        System.out.println("MyServlet::init()");
    }

    public static void main(String[] args) {
        ServletConfig config = null;
        MyServlet servlet = new MyServlet();
        servlet.init(config);
    }
}
