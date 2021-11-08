package ssdut.work.web;

import ssdut.work.pojo.User;
import ssdut.work.service.UserService;
import ssdut.work.service.impl.UserServiceImpl;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

public class LoginServlet extends BaseServlet{

    UserService userService = new UserServiceImpl();

    @Override
    public void init() throws ServletException {
        List<User> loginUsernames = new ArrayList<>();
        getServletContext().setAttribute("login_users", loginUsernames);
    }

    protected void login(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        String username = req.getParameter("username");
        String password = req.getParameter("password");
        User loginUser = userService.login(new User(username, password));
        String uri = req.getParameter("uri");

        if (loginUser == null) {
            // 把错误信息，和回显的表单项信息，保存到Request域中
            req.setAttribute("msg", "用户或密码错误！");
            req.setAttribute("username", username);
            //   跳回登录页面
            req.getRequestDispatcher("/pages/manager/login.jsp" + "?uri=" + uri).forward(req, resp);
        } else {
            // 登录 成功
            // 保存用户登录的信息到Session域中
            req.getSession().setAttribute("user", loginUser);

            // 已经登录信息保存到context中
            List<User> loginUsernames = (List) getServletContext().getAttribute("login_users");
            if(!loginUsernames.contains(loginUser)){
                loginUsernames.add(loginUser);
            }
            getServletContext().setAttribute("login_users", loginUsernames);

            // 消息队列
            List<String> msgList = new ArrayList<>();
            getServletContext().setAttribute(loginUser.getUsername()+"_msg",msgList);

            uri = uri.substring(6);
            if(uri.contains("/pages/client/show.jsp")){
                String pageNo = (req.getParameter("pageNo")!=null)?req.getParameter("pageNo"):"";
                String pageSize = (req.getParameter("pageSize")!=null)?req.getParameter("pageSize"):"";
                String dispatcher = "/search?action=page&pageNo=" + pageNo + "&pageSize=" + pageSize;
                req.getRequestDispatcher(dispatcher).forward(req,resp);
            }else{
                resp.sendRedirect("/search/pages/client/search.jsp");
            }
        }
    }

    protected void logout(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        String username = req.getParameter("username");
        req.getSession().invalidate();
        List<User> loginUsers = (List) getServletContext().getAttribute("login_users");
        loginUsers.removeIf(user -> user.getUsername().equals(username));
        resp.sendRedirect(req.getContextPath() + "/pages/client/search.jsp");
    }


}
