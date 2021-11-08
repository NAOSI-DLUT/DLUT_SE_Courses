package Dao;

import org.apache.commons.dbcp2.BasicDataSourceFactory;

import javax.sql.DataSource;
import java.io.InputStream;
import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.Statement;
import java.util.Properties;

public class JdbcUtils {

    private static DataSource ds = null;

    /**
     * 静态代码段，实现数据库基础加载
     */
    static {
        InputStream in = JdbcUtils.class.getClassLoader().getResourceAsStream("dbcpconfig.properties");
        if(in == null)
            System.out.println("in is null");
        else
            System.out.println("in is not null");

        Properties prop = new Properties();
        try {
            prop.load(in);
            ds = BasicDataSourceFactory.createDataSource(prop);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    /**
     * 数据库连接
     * @return
     */
    public static Connection getConnection() {
        Connection conn = null;
        try {
            conn = ds.getConnection();
        } catch (Exception e) {
            e.printStackTrace();
        }
        return conn;
    }

    /**
     * 释放数据库连接资源
     * @param conn
     * @param stmt
     * @param rs
     */
    public static void release (Connection conn, Statement stmt, ResultSet rs) {

        if(rs != null) {
            try {
                rs.close();
            } catch (Exception e) {
                e.printStackTrace();
            }
            rs  = null;
        }

        if(stmt != null) {
            try {
                stmt.close();
            } catch (Exception e) {
                e.printStackTrace();
            }
            stmt = null;
        }

        if(conn != null) {
            try {
                //关闭数据库连接
                conn.close();
            } catch (Exception e) {
                e.printStackTrace();
            }
            conn = null;
        }
    }
}
