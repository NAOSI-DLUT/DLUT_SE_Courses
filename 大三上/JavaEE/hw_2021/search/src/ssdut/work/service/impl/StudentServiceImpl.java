package ssdut.work.service.impl;

import ssdut.work.dao.StudentDao;
import ssdut.work.dao.impl.StudentDaoImpl;
import ssdut.work.pojo.Student;
import ssdut.work.service.StudentService;

import java.util.List;

public class StudentServiceImpl implements StudentService {

    private final StudentDao studentDao = new StudentDaoImpl();

    @Override
    public void addStudent(Student student) {
        studentDao.addStudent(student);
    }

    @Override
    public void deleteStudent(Student student) {
        studentDao.deleteStudent(student);
    }

    @Override
    public void updateStudent(Student student) {
        studentDao.updateStudent(student);
    }

    @Override
    public List<Student> queryStudent(Student student) {
        return studentDao.queryStudent(student);
    }
}
