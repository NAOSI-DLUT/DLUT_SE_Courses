package ssdut.work.dao.impl;

import ssdut.work.dao.TeacherDao;
import ssdut.work.pojo.Teacher;

import java.util.List;

public class TeacherDaoImpl extends BaseDao implements TeacherDao {
    @Override
    public int addTeacher(Teacher teacher) {
        String sql = "insert into teacher(id,name,phonenumber,qqnumber,mail ) values(?,?,?,?,? )";
        return update(sql, teacher.getId(), teacher.getName(),
                teacher.getPhoneNumber(), teacher.getQqNumber(), teacher.getMail());
    }

    @Override
    public int deleteTeacher(Teacher teacher) {
        String sql = "delete from teacher where id = ?";
        return update(sql, teacher.getId());
    }

    @Override
    public int updateTeacher(Teacher teacher) {
        String sql = "update teacher set name=?, phonenumber=?, qqnumber=?, mail=? where id = ?";
        return update(sql,  teacher.getName(), teacher.getPhoneNumber(),
                teacher.getQqNumber(),teacher.getMail(), teacher.getId());
    }

    @Override
    public List<Teacher> queryTeacher(Teacher teacher) {
        String sql = "select * from teacher where 1=1";
        sql = createSqlString(teacher, sql);
        return  queryForList(Teacher.class, sql);
    }

    @Override
    public String createSqlString(Teacher teacher, String sql) {
        if (teacher.getId()!=null&&!teacher.getId().isEmpty()){
            sql = sql + " and id like '%" + teacher.getId() + "%' ";
        }
        if (teacher.getName()!=null&&!teacher.getName().isEmpty()){
            sql = sql + " and name like '%" + teacher.getName() + "%' ";
        }
        if (teacher.getPhoneNumber()!=null&&!teacher.getPhoneNumber().isEmpty()){
            sql = sql + " and phonenumber like '%" + teacher.getPhoneNumber() + "%' ";
        }
        if (teacher.getQqNumber()!=null&&!teacher.getQqNumber().isEmpty()){
            sql = sql + " and qqnumber like '%" + teacher.getQqNumber() + "%' ";
        }
        if (teacher.getMail()!=null&&!teacher.getMail().isEmpty()){
            sql = sql + " and mail like '%" + teacher.getMail() + "%' ";
        }
        return sql;
    }

    @Override
    public Integer queryCount(Teacher teacher) {
        String  sql = "select count(*) from teacher where 1=1 ";
        sql = createSqlString(teacher, sql);
        Number count = (Number) queryForSingleValue(sql);
        return count.intValue();
    }

    @Override
    public List<Teacher> queryTeacherLimited(Teacher teacher, int begin, int pageSize) {
        String sql = "select * from teacher where 1=1 ";
        sql = createSqlString(teacher, sql);
        sql = sql + " limit " + begin + " , " + pageSize;
        return queryForList(Teacher.class, sql);
    }
}
