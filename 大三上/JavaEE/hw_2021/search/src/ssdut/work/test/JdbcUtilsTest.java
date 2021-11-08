package ssdut.work.test;


import org.junit.Test;
import ssdut.work.utils.JdbcUtils;

import java.sql.Connection;

public class JdbcUtilsTest {

    @Test
    public void testJdbcUtils(){
        Connection conn = JdbcUtils.getConnection();
        System.out.println(conn);
        JdbcUtils.close(conn);
    }
}

