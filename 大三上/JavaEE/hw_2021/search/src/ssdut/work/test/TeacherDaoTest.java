package ssdut.work.test;

import org.junit.Test;
import ssdut.work.dao.TeacherDao;
import ssdut.work.dao.impl.TeacherDaoImpl;
import ssdut.work.pojo.Teacher;

import java.util.List;

import static org.junit.Assert.*;

public class TeacherDaoTest {

    @Test
    public void addTeacher() {
        Teacher teacher = new Teacher();
        teacher.setId("50001");
        teacher.setName("test");
        teacher.setPhoneNumber("111111111");
        TeacherDao teacherDao = new TeacherDaoImpl();
        teacherDao.addTeacher(teacher);
    }

    @Test
    public void deleteTeacher() {
        Teacher teacher = new Teacher();
        teacher.setId("50001");
        teacher.setName("test");
        teacher.setPhoneNumber("111111111");
        TeacherDao teacherDao = new TeacherDaoImpl();
        teacherDao.deleteTeacher(teacher);
    }

    @Test
    public void updateTeacher() {
        Teacher teacher = new Teacher();
        teacher.setId("50001");
        teacher.setName("test2");
        teacher.setPhoneNumber("1111111112");
        TeacherDao teacherDao = new TeacherDaoImpl();
        teacherDao.updateTeacher(teacher);
    }

    @Test
    public void queryTeacher() {
        Teacher teacher = new Teacher();
//        teacher.setId("50001");
//        teacher.setName("test2");
//        teacher.setPhoneNumber("1111111112");
        TeacherDao teacherDao = new TeacherDaoImpl();
        List<Teacher> teachers = teacherDao.queryTeacher(teacher);
        System.out.println(teachers.size());
    }

    @Test
    public void queryCount() {
        Teacher teacher = new Teacher() ;
        TeacherDao teacherDao = new TeacherDaoImpl();
        int count = teacherDao.queryCount(teacher);
        System.out.println(count);
    }
}