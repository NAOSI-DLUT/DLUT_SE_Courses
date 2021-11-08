package SearchMan;

import java.sql.*;
import java.util.*;

public class DataBase {
	
	private static String userName = "root";
	private static String userPw = "123456";
	private static String driverName = "com.mysql.cj.jdbc.Driver";
	private static String dbName = "JavaEEDB";
	private static String tableName = "homework2";
	
	private static String url = 
			"jdbc:mysql://localhost/" + dbName + "?user=" + userName + "&password=" + userPw + "&serverTimezone=GMT";
	
	private static Connection conn = null;
	private int maxRows = 0;
	private int maxPages = 0;
	private List<Man> manList;
	//private int numPerPage = 5;
	
	/*
	 * 构造函数
	 */
	public DataBase() {
		try {
			manList = new ArrayList<Man>();
			Class.forName(driverName);
			conn = DriverManager.getConnection(url, userName, userPw);
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
	
	/*
	 * 获取Connection连接对象
	 */
	public Connection getConn() {
		return conn;
	}
	
	/*
	 * 获取当前查询的总页数
	 */
	public int getMaxPages(String query, int numPerPage) {
		
		try {
			if(query == null || query == "")
				return 0;
			
			String sql = "SELECT COUNT(*) total FROM " + tableName + 
					" WHERE id LIKE '%" + query + "%' OR name LIKE '%" + query + 
					"%' OR tel LIKE '%" + query + "%' OR qq LIKE '%" + query + "%' OR mail LIKE '%" + query + "%' ";
			Statement stmt = conn.createStatement();
			ResultSet rs = stmt.executeQuery(sql);
			
			while(rs.next())
				maxRows = rs.getInt(1);
			
			System.out.println("maxRows = " + maxRows);
	
			maxPages = (int)Math.ceil((double)maxRows/numPerPage);
			
			rs.close();
			
		} catch (Exception e) {
			e.printStackTrace();
		}

		return maxPages;
	}
	
	public int getMaxRows() {
		return maxRows;
	}


	public List<Man> searchOf(String query, int currentPage, int numPerPage) {
		
		String sql = "SELECT * FROM " + tableName + " WHERE id LIKE '%" + query + "%' OR name LIKE '%" + query + 
				"%' OR tel LIKE '%" + query + "%' OR qq LIKE '%" + query + "%' OR mail LIKE '%" + query + "%' " + 
				"LIMIT ?,? ";
		
		try {
			PreparedStatement pstmt = conn.prepareStatement(sql);
			pstmt.setInt(1, (currentPage - 1) * numPerPage);
			pstmt.setInt(2, numPerPage);
			
			ResultSet rs = pstmt.executeQuery();
			
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
			
			rs.close();
			
		} catch (Exception e) {
			e.printStackTrace();
		}
		
		return manList;
		
	}
	
	
	/*
	 * 关闭Connection
	 */
	public void close() {
		
		try {
			if(conn != null) {
				conn.close();
				conn = null;
			}
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
	
	
	

	
}
