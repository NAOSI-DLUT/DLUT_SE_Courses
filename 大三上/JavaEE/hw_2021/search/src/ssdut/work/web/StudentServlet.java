package ssdut.work.web;

import ssdut.work.pojo.Student;
import ssdut.work.service.StudentService;
import ssdut.work.service.impl.StudentServiceImpl;
import ssdut.work.utils.WebUtils;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;

public class StudentServlet extends BaseServlet{

    private final StudentService studentService = new StudentServiceImpl();

    protected void add(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        Student student = WebUtils.copyParamToBean(req.getParameterMap(), new Student());
        studentService.addStudent(student);
        resp.sendRedirect(req.getContextPath()+ "/search?action=page&pageNo="+req.getParameter("pageNo")+"&pageSize="+req.getParameter("pageSize"));
    }


    protected void delete(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        Student student = WebUtils.copyParamToBean(req.getParameterMap(), new Student() );
        studentService.deleteStudent(student);
        resp.sendRedirect(req.getContextPath()+ "/search?action=page&pageNo="+req.getParameter("pageNo")+"&pageSize="+req.getParameter("pageSize"));
    }


    protected void update(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        Student student = WebUtils.copyParamToBean(req.getParameterMap(), new Student() );
        studentService.updateStudent(student);
        resp.sendRedirect(req.getContextPath()+ "/search?action=page&pageNo="+req.getParameter("pageNo")+"&pageSize="+req.getParameter("pageSize"));
    }

    protected void getStudent(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        String  id = (req.getParameter("id")!=null)?req.getParameter("id"):"0";
        Student student = new Student();
        student.setId(id);
        student = studentService.queryStudent(student).get(0);

        req.setAttribute("student", student);

        req.getRequestDispatcher("/pages/manager/info_edit.jsp").forward(req, resp);
    }
}
