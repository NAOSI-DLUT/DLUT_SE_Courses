package ssdut.work.web;

import org.apache.commons.fileupload.FileItem;
import org.apache.commons.fileupload.FileItemFactory;
import org.apache.commons.fileupload.disk.DiskFileItemFactory;
import org.apache.commons.fileupload.servlet.ServletFileUpload;
import ssdut.work.dao.UserDao;
import ssdut.work.dao.impl.UserDaoImpl;
import ssdut.work.pojo.User;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.File;
import java.io.IOException;
import java.util.List;

public class UserServlet extends BaseServlet{

    private final UserDao userDao = new UserDaoImpl();

    protected void update(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        if (ServletFileUpload.isMultipartContent(req)){
            FileItemFactory fileItemFactory = new DiskFileItemFactory();

            ServletFileUpload servletFileUpload = new ServletFileUpload(fileItemFactory);
            try {
                List<FileItem> list = servletFileUpload.parseRequest(req);
                for(FileItem fileItem : list){
                    if(!fileItem.isFormField())  {
                        // 上传的文件
                        String path = req.getParameter("username") + fileItem.getName();
                        fileItem.write(new File(User.getAbsolutePath() + path));
                        userDao.updateIconPath(req.getParameter("username"), path);
                    }
                }
            }catch (Exception e){
                e.printStackTrace();
            }finally {
                User user = (User) req.getSession().getAttribute("user");
                user = userDao.queryAdminByUsernameAndPassword(user.getUsername(),user.getPassword());
                req.getSession().setAttribute("user", user);
                resp.sendRedirect(req.getContextPath()+"/pages/client/userInfo.jsp");
            }
        }

    }

}
