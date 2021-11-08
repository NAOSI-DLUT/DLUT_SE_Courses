package ssdut.work.dao.impl;

import ssdut.work.dao.StudentDao;
import ssdut.work.pojo.Student;

import java.util.List;

public class StudentDaoImpl extends BaseDao implements StudentDao {
    @Override
    public int addStudent(Student student) {
        String sql = "insert into student(id,name,phonenumber,qqnumber,mail ) values(?,?,?,?,? )";
        return update(sql, student.getId(), student.getName(),
                student.getPhoneNumber(), student.getQqNumber(), student.getMail());
    }

    @Override
    public int deleteStudent(Student student) {
        String sql = "delete from student where id = ?";
        return update(sql, student.getId());
    }

    @Override
    public int updateStudent(Student student) {
        String sql = "update student set name=?, phonenumber=?, qqnumber=?, mail=? where id = ?";
        return update(sql,  student.getName(), student.getPhoneNumber(),
                student.getQqNumber(),student.getMail(), student.getId());
    }

    @Override
    public List<Student> queryStudent(Student student) {
        String sql = "select * from student where 1=1";
        sql = createSqlString(student, sql);
        return  queryForList(Student.class, sql);
    }

    @Override
    public String createSqlString(Student student, String sql) {

        if (student.getId()!=null&&!student.getId().isEmpty()){
            sql = sql + " and id like '%" + student.getId() + "%' ";
        }
        if (student.getName()!=null&&!student.getName().isEmpty()){
            sql = sql + " and name like '%" + student.getName() + "%' ";
        }
        if (student.getPhoneNumber()!=null&&!student.getPhoneNumber().isEmpty()){
            sql = sql + " and phonenumber like '%" + student.getPhoneNumber() + "%' ";
        }
        if (student.getQqNumber()!=null&&!student.getQqNumber().isEmpty()){
            sql = sql + " and qqnumber like '%" + student.getQqNumber() + "%' ";
        }
        if (student.getMail()!=null&&!student.getMail().isEmpty()){
            sql = sql + " and mail like '%" + student.getMail() + "%' ";
        }
        return sql;
    }

    @Override
    public Integer queryCount(Student student) {
        String sql = "select count(*) from student where 1=1 ";
        sql = createSqlString(student, sql);
        Number count = (Number) queryForSingleValue(sql);
        return count.intValue();
    }

    @Override
    public List<Student> queryStudentLimited(Student student, int begin, int pageSize) {
        String sql = "select * from student where 1=1";
        sql = createSqlString(student, sql);
        sql = sql + " limit " + begin + " , " + pageSize;
        return queryForList(Student.class, sql);
    }
}
