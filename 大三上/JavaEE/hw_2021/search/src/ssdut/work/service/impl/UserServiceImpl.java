package ssdut.work.service.impl;

import ssdut.work.dao.UserDao;
import ssdut.work.dao.impl.UserDaoImpl;
import ssdut.work.pojo.User;
import ssdut.work.service.UserService;

import java.util.List;

public class UserServiceImpl implements UserService {

    UserDao userDao = new UserDaoImpl();

    @Override
    public User login(User user) {
        return userDao.queryAdminByUsernameAndPassword(user.getUsername(), user.getPassword());
    }

    @Override
    public void updatePath(String username, String path) {
        userDao.updateIconPath(username, path);
    }

    @Override
    public List<User> queryAllUser() {
        return userDao.queryAllUser();
    }
}
