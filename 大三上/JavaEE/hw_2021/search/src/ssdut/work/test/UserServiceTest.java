package ssdut.work.test;

import org.junit.Test;
import ssdut.work.pojo.User;
import ssdut.work.service.UserService;
import ssdut.work.service.impl.UserServiceImpl;

public class UserServiceTest {

    @Test
    public void login() {
        User user = new User();
        user.setUsername("admin");
        user.setPassword("admin");

        UserService userService = new UserServiceImpl();
        user = userService.login(user);
        if (user != null) {
            System.out.println("login success");
            if(user.isIsAdmin()){
                System.out.println("admin!");
            }
        }else {
            System.out.println("login failed");
        }


    }
}