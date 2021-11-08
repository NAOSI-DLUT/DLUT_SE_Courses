package ssdut.work.service;

import ssdut.work.pojo.Student;

import java.util.List;

public interface StudentService {

    public void addStudent(Student student);

    public void deleteStudent(Student student);

    public void updateStudent(Student student);

    public List<Student> queryStudent(Student student);

}
