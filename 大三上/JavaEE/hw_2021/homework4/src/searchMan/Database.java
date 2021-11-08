package searchMan;

import java.sql.*;
import java.util.*;
import java.io.*;

public class Database {
	
	private static String tableName = "homework4";
	private int maxPages = 0;
	private int maxRows = 0;
	private List<Man> manList;
	private Connection conn = null;
	PreparedStatement ps = null;
	ResultSet rs = null;
	
	public Database() {
		
		conn = JdbcUtils.getConnection();
		manList = new ArrayList<Man>();
	}
	
	public boolean deleteFile(String id) {
		
		String sql = "update " + tableName + " set image = NULL where id = ?";
		
		int num = 0;
		try {
			ps = conn.prepareStatement(sql);
			ps.setString(1, id);
			
			num = ps.executeUpdate();
		} catch (Exception e) {
			e.printStackTrace();
		}
		
		if(num > 0)
			return true;
		else
			return false;
	}
	
	public boolean upLoadFile(String id, String path) throws Exception {
		
		String sql = "update " + tableName + " set image = ? where id = ?";
		
		ps = conn.prepareStatement(sql);
		ps.setString(1, path);
		ps.setString(2, id);
		
		int num = ps.executeUpdate();
		
		if(num > 0)
			return true;
		else
			return false;
	}
	
	public String getPath(String id) {
		
		System.out.println(id);
		String sql = "select image from " + tableName + " where id = " + id;
		
		String path = null;
		try {
			ps = conn.prepareStatement(sql);
			rs = ps.executeQuery();
			
			while(rs.next())
				path = rs.getString(1);
			
		} catch (Exception e) {
			e.printStackTrace();
		}
		
		
		return path;
	}
	
	public String getPwd(String id) {
		
		String sql = "select password from " + tableName + " where id = " + id;
		String pwd = "";
		
		try {
			ps = conn.prepareStatement(sql);
			
			rs = ps.executeQuery();
			
			while(rs.next()) {
				pwd = rs.getString(1);
			}
				
		} catch (Exception e) {
			e.printStackTrace();
		}
		
		return pwd;
	}
	
	public boolean changePwd(String id, String newpwd) {
		
		String sql = "update " + tableName + " set password = " + newpwd + " where id = " + id;
		
		try {
			ps = conn.prepareStatement(sql);
			int rows = ps.executeUpdate();
			if(rows > 0)
				return true;
			return false;
		} catch (Exception e) {
			e.printStackTrace();
		}
		return false;
	}
	
	public List<Integer> getMaxPages(String query, int numPerPage) {
		
		List<Integer> ans = new ArrayList<Integer>();
		
		try {
			if(query == null || query == "")
				return null;
			
			String sql = "SELECT COUNT(*) total FROM " + tableName + 
					" WHERE id LIKE '%" + query + "%' OR name LIKE '%" + query + 
					"%' OR tel LIKE '%" + query + "%' OR qq LIKE '%" + query + "%' OR mail LIKE '%" + query + "%' ";
			
			ps = conn.prepareStatement(sql);
			rs = ps.executeQuery();
			
			while(rs.next())
				maxRows = rs.getInt(1);
			
			System.out.println("maxRows = " + maxRows);
	
			maxPages = (int)Math.ceil((double)maxRows/numPerPage);
			
			//rs.close();
			
		} catch (Exception e) {
			e.printStackTrace();
		}

		ans.add(maxPages);
		ans.add(maxRows);
		return ans;
	}
	
	
	public List<Man> searchOf(String query, int currentPage, int numPerPage) {
		
		String sql = "SELECT * FROM " + tableName + " WHERE id LIKE '%" + query + "%' OR name LIKE '%" + query + 
				"%' OR tel LIKE '%" + query + "%' OR qq LIKE '%" + query + "%' OR mail LIKE '%" + query + "%' " + 
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
			
			//rs.close();
			
		} catch (Exception e) {
			e.printStackTrace();
		}
		
		return manList;
		
	} 
	
	public boolean add(Man man) {
		
		int result = 0;
		String sql="insert into " + tableName + " (id,name,tel,qq,mail) values(?,?,?,?,?)";
		
		System.out.println("id:" + man.getID() + " name:" + man.getName() + " tel:" + man.getTel() + " qq:" + man.getQq() + " mail:" + man.getMail());
		
		try {	
			ps=conn.prepareStatement(sql);
			ps.setString(1, man.getID());
			ps.setString(2, man.getName());
			ps.setString(3, man.getTel());
			ps.setString(4, man.getQq());
			ps.setString(5, man.getMail());
			
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
		String sql="delete from " + tableName + " where id = ?";
		
		try {
			ps=conn.prepareStatement(sql);
			ps.setString(1, id);
			//sql = sql.replace("'","");
			
			result = ps.executeUpdate();
			
		} catch (Exception e) {
			e.printStackTrace();
		}
		
		if(result != 0) 
			return true;
		else
			return false;
		
	}
	
	public void release () {
		System.out.println("Database release. Bye~");
		System.out.println("----------------");
		JdbcUtils.release(conn, ps, rs);
	}

}
