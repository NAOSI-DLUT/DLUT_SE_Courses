package ssdut.work.dao;

import ssdut.work.pojo.Teacher;

import java.util.List;

public interface TeacherDao {
    public int addTeacher(Teacher teacher);

    /**
     * 注意：该方法是通过id删除
     * @param teacher
     * @return int
     */
    public int deleteTeacher(Teacher teacher);

    public int updateTeacher(Teacher teacher);

    /**
     * 注意：该方法是通过传进来的teacher对象的所有非null值进行模糊搜索
     * @param teacher
     * @return int
     */
    public List<Teacher> queryTeacher(Teacher teacher);

    public String createSqlString(Teacher teacher, String sql);

    public Integer queryCount(Teacher teacher);

    public List<Teacher> queryTeacherLimited(Teacher teacher, int begin, int pageSize);

}
