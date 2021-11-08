package ssdut.work.test;

import org.junit.Test;
import ssdut.work.dao.StudentDao;
import ssdut.work.dao.impl.StudentDaoImpl;
import ssdut.work.pojo.Student;

import java.util.List;

import static org.junit.Assert.*;

public class StudentDaoTest {

    @Test
    public void addStudent() {
        Student student = new Student();
        student.setId("50001");
        student.setName("test");
        student.setPhoneNumber("00000000000");
        StudentDao studentDao = new StudentDaoImpl();
        studentDao.addStudent(student);
    }

    @Test
    public void deleteStudent() {
        Student student = new Student();
        student.setId("50001");
        StudentDao studentDao = new StudentDaoImpl();
        studentDao.deleteStudent(student);
    }

    @Test
    public void updateStudent() {
        Student student = new Student();
        student.setId("50001");
        student.setName("test2");
        student.setPhoneNumber("10000000000");
        StudentDao studentDao = new StudentDaoImpl();
        studentDao.updateStudent(student);
    }
    @Test
    public void queryStudent() {
        Student student = new Student();
//        student.setId("000");
//        student.setName("张伟");
//        student.setPhoneNumber("03");
        StudentDao studentDao = new StudentDaoImpl();
        List<Student> students = studentDao.queryStudent(student);
        System.out.println(students.size());
    }

    @Test
    public void queryCount() {
        Student student = new Student();
        StudentDao studentDao = new StudentDaoImpl();
        int count = studentDao.queryCount(student);
        System.out.println(count);
    }
}