package ssdut.work.web;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.util.List;

public class MsgServlet extends BaseServlet {

    protected void message(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        String username = req.getParameter("username");
        String tarUsername = req.getParameter("tar_username");
        //给另一个用户发消息
        List<String> msgList = (List) getServletContext().getAttribute(tarUsername+"_msg");
        if(!msgList.contains(username)){
            msgList.add(username);
        }
        //转到聊天室
        req.setAttribute("name", username);
        req.getRequestDispatcher("/pages/client/message.jsp").forward(req,resp);
    }
}
