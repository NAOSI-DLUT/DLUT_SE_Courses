package ssdut.work.dao.impl;

import ssdut.work.dao.UserDao;
import ssdut.work.pojo.User;

import java.util.List;

public class UserDaoImpl extends BaseDao implements UserDao {

    @Override
    public User queryAdminByUsernameAndPassword(String username, String password) {
        String sql = "select * from user where username = ? and password = ?";
        return queryForOne(User.class, sql, username, password);
    }

    @Override
    public int updateIconPath(String username, String path) {
        String sql = "update user set path = ? where username = ?";
        return update(sql, path, username);
    }

    @Override
    public List<User> queryAllUser() {
        String sql = "select * from user";
        return queryForList(User.class, sql);
    }
}
