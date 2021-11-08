package ssdut.work.dao;

import ssdut.work.pojo.Student;

import java.util.List;

public interface StudentDao {

    public int addStudent(Student student);

    /**
     * 注意：该方法是通过id删除
     * @param student
     * @return
     */
    public int deleteStudent(Student student);

    public int updateStudent(Student student);

    /**
     * 注意：该方法是通过传进来的student对象的所有非null值进行模糊搜索
     * @param student
     * @return
     */
    public List<Student> queryStudent(Student student);

    public String createSqlString(Student student, String sql);

    public Integer queryCount(Student student);

    public List<Student> queryStudentLimited(Student student, int begin, int pageSize);
}
