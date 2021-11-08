package ssdut.work.service;

import ssdut.work.pojo.Teacher;

import java.util.List;

public interface TeacherService {

    public void addTeacher(Teacher teacher);

    public void deleteTeacher(Teacher teacher);

    public void updateTeacher(Teacher teacher);

    public List<Teacher> queryTeacher(Teacher teacher);

}
