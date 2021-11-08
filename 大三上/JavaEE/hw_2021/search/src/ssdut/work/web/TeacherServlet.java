package ssdut.work.web;

import ssdut.work.pojo.Teacher;
import ssdut.work.service.TeacherService;
import ssdut.work.service.impl.TeacherServiceImpl;
import ssdut.work.utils.WebUtils;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;

public class TeacherServlet extends BaseServlet{

    private final TeacherService teacherService = new TeacherServiceImpl();

    protected void add(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        Teacher teacher = WebUtils.copyParamToBean(req.getParameterMap(), new Teacher());
        teacherService.addTeacher(teacher);
        resp.sendRedirect(req.getContextPath()+ "/search?action=page&pageNo="+req.getParameter("pageNo")+"&pageSize="+req.getParameter("pageSize"));
    }


    protected void delete(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        Teacher teacher = WebUtils.copyParamToBean(req.getParameterMap(), new Teacher() );
        teacherService.deleteTeacher(teacher);
        resp.sendRedirect(req.getContextPath()+ "/search?action=page&pageNo="+req.getParameter("pageNo")+"&pageSize="+req.getParameter("pageSize"));
    }


    protected void update(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        Teacher teacher = WebUtils.copyParamToBean(req.getParameterMap(), new Teacher() );
        teacherService.updateTeacher(teacher);
        resp.sendRedirect(req.getContextPath()+ "/search?action=page&pageNo="+req.getParameter("pageNo")+"&pageSize="+req.getParameter("pageSize"));
    }

    protected void getTeacher(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        String  id = (req.getParameter("id")!=null)?req.getParameter("id"):"0";
        Teacher teacher = new Teacher();
        teacher.setId(id);
        teacher = teacherService.queryTeacher(teacher).get(0);

        req.setAttribute("teacher", teacher);

        req.getRequestDispatcher("/pages/manager/info_edit.jsp").forward(req, resp);

    }

}
