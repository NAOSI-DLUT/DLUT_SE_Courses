package ssdut.work.web;

import org.apache.commons.fileupload.FileItem;
import org.apache.commons.fileupload.FileItemFactory;
import org.apache.commons.fileupload.disk.DiskFileItemFactory;
import org.apache.commons.fileupload.servlet.ServletFileUpload;
import ssdut.work.pojo.Page;
import ssdut.work.pojo.Student;
import ssdut.work.pojo.Teacher;
import ssdut.work.pojo.User;
import ssdut.work.service.*;
import ssdut.work.service.impl.*;
import ssdut.work.utils.WebUtils;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
import java.io.File;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

public class SearchServlet extends BaseServlet{

    private final StudentService studentService = new StudentServiceImpl();
    private final TeacherService teacherService = new TeacherServiceImpl();
    private final PageService pageService = new PageServiceImpl();
    private final UserService userService = new UserServiceImpl();
    private final FaceMatchService faceMatchService = new FaceMatchServiceImpl();

    protected void search(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        String[] type = req.getParameterValues("type");
        if (type==null||type.length==2){
            Student student = WebUtils.copyParamToBean(req.getParameterMap(), new Student());
            Teacher teacher = WebUtils.copyParamToBean(req.getParameterMap(), new Teacher());
            List<Student> studentList = studentService.queryStudent(student);
            List<Teacher> teacherList = teacherService.queryTeacher(teacher);

            req.setAttribute("students",studentList);
            req.setAttribute("teachers",teacherList);
        } else if(type[0].equals("teacher")){
            Teacher teacher = WebUtils.copyParamToBean(req.getParameterMap(), new Teacher());
            List<Teacher> teacherList = teacherService.queryTeacher(teacher);

            req.setAttribute("teachers",teacherList);
        }else {
            Student student = WebUtils.copyParamToBean(req.getParameterMap(), new Student());
            List<Student> studentList = studentService.queryStudent(student);

            req.setAttribute("students",studentList);
        }
        req.getRequestDispatcher("/pages/client/show.jsp").forward(req,resp);
    }

    protected void page(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        //1 获取请求的参数 pageNo 和 pageSize
        int pageNo = WebUtils.parseInt(req.getParameter("pageNo"), 1);
        int pageSize = WebUtils.parseInt(req.getParameter("pageSize"), Page.PAGE_SIZE);
        HttpSession session = req.getSession();

        String[] type = req.getParameterValues("type");
        String update = req.getParameter("update");

        Teacher teacher = null;
        Student student = null;

        if(update!=null){
            // 请求来自搜索页
            if ((type==null||type.length==2)){
                student = WebUtils.copyParamToBean(req.getParameterMap(), new Student());
                teacher = WebUtils.copyParamToBean(req.getParameterMap(), new Teacher());
                session.setAttribute("student_format", student);
                session.setAttribute("teacher_format", teacher);
            } else if(type[0].equals("teacher")){
                session.removeAttribute("student_format");
                teacher = WebUtils.copyParamToBean(req.getParameterMap(), new Teacher());
                session.setAttribute("teacher_format", teacher);
            }else if(type[0].equals("student")){
                session.removeAttribute("teacher_format");
                student = WebUtils.copyParamToBean(req.getParameterMap(), new Student());
                session.setAttribute("student_format", student);
            }
        } else {
            student = (Student) session.getAttribute("student_format");
            teacher = (Teacher) session.getAttribute("teacher_format");
        }


        Page page = pageService.page(student, teacher, pageNo, pageSize);

        page.setUrl("search?action=page");

        //3 保存Page对象到Request域中
        req.setAttribute("page",page);
        //4 请求转发到pages/manager/book_manager.jsp页面
        req.getRequestDispatcher("/pages/client/show.jsp").forward(req,resp);
    }

    protected void imgSearch(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        if (ServletFileUpload.isMultipartContent(req)){
            FileItemFactory fileItemFactory = new DiskFileItemFactory();
            String path = User.getAbsolutePath() + "temp/temp.jpg" ;

            ServletFileUpload servletFileUpload = new ServletFileUpload(fileItemFactory);
            try {
                List<FileItem> list = servletFileUpload.parseRequest(req);
                for(FileItem fileItem : list){
                    if(!fileItem.isFormField())  {
                        // 保存上传的图片
                        fileItem.write(new File(path));
                    }
                }
            }catch (Exception e){
                e.printStackTrace();
            }

            // 图片比较的工作
            List<User> userList = userService.queryAllUser();
            List<User> resList = new ArrayList<>();

            for(User user : userList){
                if(user.getPath()==null){
                    continue;
                }
                if(faceMatchService.matchResult(path, User.getAbsolutePath()+user.getPath())){
                    resList.add(user);
                }
            }

            for(User user : resList){
                if(user.isIsTeacher()){
                    Teacher teacher = new Teacher();
                    teacher.setId(user.getId());
                    user.setPerson(teacherService.queryTeacher(teacher).get(0));
                }else {
                    Student student = new Student();
                    student.setId(user.getId());
                    user.setPerson(studentService.queryStudent(student).get(0));
                }
            }

            req.setAttribute("users", resList);
            req.getRequestDispatcher("/pages/client/facematch_show.jsp").forward(req, resp);
        }
    }
}
