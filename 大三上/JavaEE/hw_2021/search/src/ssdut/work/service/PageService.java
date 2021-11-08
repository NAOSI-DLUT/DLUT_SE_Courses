package ssdut.work.service;

import ssdut.work.pojo.Page;
import ssdut.work.pojo.Student;
import ssdut.work.pojo.Teacher;

public interface PageService {
    public Page page(Student student, Teacher teacher, int pageNo, int pageSize);
}
