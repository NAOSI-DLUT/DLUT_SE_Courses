package ssdut.work.service;

import ssdut.work.pojo.User;

import java.util.List;

public interface UserService {

    /**
     * 登录
     * @param user
     * @return null说明登录失败
     */
    public User login(User user);

    public void updatePath(String username, String path);

    public List<User> queryAllUser();
}
