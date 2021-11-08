package servlet;

import Dao.BaseDao;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
import java.io.IOException;
import java.io.PrintWriter;

@WebServlet("/LoginServlet")
public class LoginServlet extends HttpServlet {
    public LoginServlet() {
        super();
    }

    @Override
    public void init() throws ServletException {
        super.init();
    }

    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        doPost(req, resp);
    }

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        request.setCharacterEncoding("utf-8");
        response.setContentType("text/html;charset=utf-8");
        String account = request.getParameter("account");
        String pwd = request.getParameter("password");
        System.out.println("用户输入account:"+account + "---password:"+pwd);
        PrintWriter out=response.getWriter();

        if(account == null || pwd == null || account == "" || pwd == "") {
            out.print("<script charset=UTF-8>alert('请输入帐号或者密码！！！');window.location.href='login.jsp'</script>");
            return;
        }

        BaseDao bd =  new BaseDao();
        String role = request.getParameter("role");
        System.out.println(role);
        HttpSession hs=request.getSession();
        if (role.equals("admin")){
            hs.setAttribute("role","admin");
            String realPwd = bd.getAdminPwd(account);
            hs.setAttribute("AdminAcc",account);
            if (realPwd.equals(pwd)){
                System.out.println("密码正确");
                request.getRequestDispatcher("/account.jsp").include(request, response);
            }else {
                out.print("<script charset=UTF-8>alert('帐号或者密码错误！！！');window.location.href='login.jsp'</script>");
                return;
            }
            System.out.println("真正的:"+realPwd);
        }else {
            hs.setAttribute("role","normal");
            String realPwd = bd.getNormalPwd(account);
            hs.setAttribute("NorAcc",account);
            if (realPwd.equals(pwd)){
                System.out.println("密码正确");
                request.getRequestDispatcher("/normal.jsp").include(request, response);
                request.getRequestDispatcher("/Index1.jsp").include(request, response);
            }else {
                out.print("<script charset=UTF-8>alert('帐号或者密码错误！！！');window.location.href='login.jsp'</script>");
                return;
            }
        }

    }
}
