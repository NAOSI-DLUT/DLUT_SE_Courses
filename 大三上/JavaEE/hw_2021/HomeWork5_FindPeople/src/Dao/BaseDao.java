package Dao;

import entity.Man;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.util.ArrayList;
import java.util.List;

public class BaseDao {
    private static String tNamelogin = "Login";
    private static String tNameStu = "information";
    private Connection conn = null;
    PreparedStatement ps = null;
    ResultSet rs = null;

    private static int TOTAL_CHANCE = 3;

    /**
     * 获取数据库连接
     */
    public BaseDao() {
        conn = JdbcUtils.getConnection();
    }

    /**
     * 根据用户名来获取管理员密码
     * @param id
     * @return
     */
    public String getAdminPwd(String id) {
        String sql = "select password from " + tNamelogin + " where id = '" + id+"'";
        String pwd = "";
        try {
            ps = conn.prepareStatement(sql);
            rs = ps.executeQuery();
            while(rs.next()) {
                pwd = rs.getString(1);
            }
        } catch (Exception e) {
            e.printStackTrace();
        } finally {
            JdbcUtils.release(conn,ps,rs);
        }
        return pwd;
    }

    /**
     * 根据用户名来获得普通用户的密码
     * @param id
     * @return
     */
    public String getNormalPwd(String id){
        String sql = "select password from " + tNameStu + " where id = '" + id+"'";
        String pwd = "";
        try {
            ps = conn.prepareStatement(sql);
            rs = ps.executeQuery();
            while(rs.next()) {
                pwd = rs.getString(1);
            }
        } catch (Exception e) {
            e.printStackTrace();
        } finally {
            JdbcUtils.release(conn,ps,rs);
        }
        return pwd;
    }


    public List<Man> getVoteResult() {

        String sql = "select * from " + tNameStu;
        List<Man> result = new ArrayList<Man>();

        try {
            ps = conn.prepareStatement(sql);
            rs = ps.executeQuery();

            while(rs.next()) {
                Man tmp = new Man(rs.getString(1),rs.getString(2),rs.getString(3),rs.getString(4),rs.getString(5));
                result.add(tmp);
            }
        } catch(Exception e) {
            e.printStackTrace();
        }
        return result;
    }

    public List<Integer> getMaxPages(String query, int numPerPage) {

        int maxPages = 0;
        int maxRows = 0;
        List<Integer> ans = new ArrayList<Integer>();

        try {
            if(query == null || query == "")
                return null;

            String sql = "SELECT COUNT(*) total FROM " + tNameStu +
                    " WHERE id LIKE '%" + query + "%' OR name LIKE '%" + query +
                    "%' OR phone LIKE '%" + query + "%' OR qq LIKE '%" + query + "%' OR email LIKE '%" + query + "%' ";

            ps = conn.prepareStatement(sql);
            rs = ps.executeQuery();

            while(rs.next())
                maxRows = rs.getInt(1);

            System.out.println("maxRows = " + maxRows);

            maxPages = (int)Math.ceil((double)maxRows/numPerPage);

        } catch (Exception e) {
            e.printStackTrace();
        }

        ans.add(maxPages);
        ans.add(maxRows);
        return ans;
    }

    public List<Man> searchOf(String query, int currentPage, int numPerPage) {
        List<Man> manList = new ArrayList<>();
        String sql = "SELECT * FROM " + tNameStu + " WHERE id LIKE '%" + query + "%' OR name LIKE '%" + query +
                "%' OR phone LIKE '%" + query + "%' OR qq LIKE '%" + query + "%' OR email LIKE '%" + query + "%' " +
                "LIMIT ?,? ";

        try {
            ps = conn.prepareStatement(sql);
            ps.setInt(1, (currentPage - 1) * numPerPage);
            ps.setInt(2, numPerPage);

            ResultSet rs = ps.executeQuery();

            // 将指定页的内容放到manList中
            while(rs.next()) {
                String id = rs.getString(1);
                String name = rs.getString(2);
                String tel = rs.getString(3);
                String qq = rs.getString(4);
                String mail = rs.getString(5);

                Man man = new Man(id, name, tel, qq, mail);
                manList.add(man);
            }
        } catch (Exception e) {
            e.printStackTrace();
        }

        return manList;

    }

    public boolean add(Man man) {

        int result = 0;
        String sql="insert into " + tNameStu + " values(?,?,?,?,?,?)";

        try {
            ps=conn.prepareStatement(sql);
            ps.setString(1, man.getId());
            ps.setString(2, man.getName());
            ps.setString(3, man.getTel());
            ps.setString(4, man.getQq());
            ps.setString(5, man.getMail());
            ps.setString(6, man.getId());
            result = ps.executeUpdate();

        } catch (Exception e) {
            e.printStackTrace();
        }

        if(result != 0)
            return true;
        else
            return false;

    }

    public boolean delete(String id) {

        int result = 0;
        String sql="delete from " + tNameStu + " where id = ?";

        try {
            ps=conn.prepareStatement(sql);
            ps.setString(1, id);

            result = ps.executeUpdate();

        } catch (Exception e) {
            e.printStackTrace();
        }

        if(result != 0)
            return true;
        else
            return false;

    }

    public void release(){
        JdbcUtils.release(conn,ps,rs);
    }


}
