package ssdut.work.service.impl;

import ssdut.work.dao.TeacherDao;
import ssdut.work.dao.impl.TeacherDaoImpl;
import ssdut.work.pojo.Teacher;
import ssdut.work.service.TeacherService;

import java.util.List;

public class TeacherServiceImpl implements TeacherService {

    private final TeacherDao teacherDao = new TeacherDaoImpl();

    @Override
    public void addTeacher(Teacher teacher) {
        teacherDao.addTeacher(teacher);
    }

    @Override
    public void deleteTeacher(Teacher teacher) {
        teacherDao.deleteTeacher(teacher);
    }

    @Override
    public void updateTeacher(Teacher teacher) {
        teacherDao.updateTeacher(teacher);
    }

    @Override
    public List<Teacher> queryTeacher(Teacher teacher) {
        return teacherDao.queryTeacher(teacher);
    }
}
