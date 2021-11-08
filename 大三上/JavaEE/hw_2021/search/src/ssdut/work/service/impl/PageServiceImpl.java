package ssdut.work.service.impl;


import ssdut.work.dao.StudentDao;
import ssdut.work.dao.TeacherDao;
import ssdut.work.dao.impl.StudentDaoImpl;
import ssdut.work.dao.impl.TeacherDaoImpl;
import ssdut.work.pojo.Page;
import ssdut.work.pojo.Student;
import ssdut.work.pojo.Teacher;
import ssdut.work.service.PageService;

import java.util.List;

public class PageServiceImpl implements PageService {

    StudentDao studentDao = new StudentDaoImpl();
    TeacherDao teacherDao = new TeacherDaoImpl();

    @Override
    public Page page(Student student, Teacher teacher, int pageNo, int pageSize) {
        Page page = new Page();

        page.setPageSize(pageSize);
        // 总记录数
        int studentCount = 0;
        int teacherCount = 0;
        if (teacher != null){
            teacherCount = teacherDao.queryCount(teacher);
        }
        if (student != null){
            studentCount = studentDao.queryCount(student);
        }
        int pageTotalCount =  + studentCount + teacherCount;
        page.setPageTotalCount(pageTotalCount);
        // 总页码
        int pageTotal = pageTotalCount / pageSize;
        if(pageTotalCount % pageSize > 0){
            pageTotal += 1;
        }
        page.setPageTotal(pageTotal);
        // 当前页码
        page.setPageNo(pageNo);
        // 求当前页数据的开始索引
        int begin = (page.getPageNo() - 1) * pageSize;
        // todo: 设置对象
        List<Teacher> teachers = null;
        List<Student> students = null;
        int teacherSize = 0;
        if (teacher!=null){
            teachers = teacherDao.queryTeacherLimited(teacher, begin, pageSize);
            teacherSize = teachers.size();
        }
        begin = begin - teacherCount;
        if(begin+pageSize>0 && student!=null){
            begin = Math.max(begin, 0);
            students = studentDao.queryStudentLimited(student, begin, pageSize-teacherSize);
        }
        page.setTeachers(teachers);
        page.setStudents(students);

        return page;
    }
}
