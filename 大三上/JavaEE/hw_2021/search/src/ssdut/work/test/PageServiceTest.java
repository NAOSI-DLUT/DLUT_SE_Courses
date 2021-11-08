package ssdut.work.test;

import org.junit.Test;
import ssdut.work.pojo.Page;
import ssdut.work.pojo.Student;
import ssdut.work.pojo.Teacher;
import ssdut.work.service.PageService;
import ssdut.work.service.impl.PageServiceImpl;

import static org.junit.Assert.*;

public class PageServiceTest {

    @Test
    public void page() {
        Student student = new Student();
        Teacher teacher = new Teacher();
        PageService pageService = new PageServiceImpl();
        Page page = pageService.page(student,teacher,3,10);
        System.out.println(page.getTeachers().size() + " " + page.getStudents().size());
    }
}