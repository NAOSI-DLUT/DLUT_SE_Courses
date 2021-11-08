package ssdut.work.test;

import org.junit.Test;
import ssdut.work.dao.UserDao;
import ssdut.work.dao.impl.UserDaoImpl;
import ssdut.work.pojo.User;

import java.util.List;

public class UserDaoTest {

    UserDao userDao = new UserDaoImpl();

    @Test
    public void queryAdminByUsernameAndPassword() {
        User user = userDao.queryAdminByUsernameAndPassword("user1","user1");
        System.out.println(user);
    }

    @Test
    public void updateIconPath(){
        userDao.updateIconPath("user3", "test");
    }

    @Test
    public void queryAllUser(){
        List<User> userList = userDao.queryAllUser();
        for(User user : userList){
            System.out.println(user.getPath());
        }
    }
}