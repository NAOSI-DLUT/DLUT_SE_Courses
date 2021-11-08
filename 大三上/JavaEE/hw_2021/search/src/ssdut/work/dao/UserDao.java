package ssdut.work.dao;

import ssdut.work.pojo.User;

import java.util.List;

public interface UserDao {

    /**
     * 根据用户名和密码返回Admin
     * @param username
     * @param password
     * @return
     */
    public User queryAdminByUsernameAndPassword(String username, String password );

    public int updateIconPath(String username, String path);

    public List<User> queryAllUser();

}
