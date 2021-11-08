package Vote;

import java.sql.*;
import java.util.*;

import java.io.*;

public class Database {
	
	private static String tableNameLogin = "homework5Login";
	private static String tableNameVote = "VoteInfo";
	private Connection conn = null;
	PreparedStatement ps = null;
	ResultSet rs = null;
	
	private static int TOTAL_CHANCE = 3;	// 默认初始也为3
	
	public Database() {
		conn = JdbcUtils.getConnection();
	}
	
	public void release () {
		System.out.println("Database release. Bye~");
		System.out.println("----------------");
		JdbcUtils.release(conn, ps, rs);
	}

	public String getPwd(String id) {
		
		String sql = "select password from " + tableNameLogin + " where id = " + id;
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
	
	public List<String> getVoteInfo() {
		
		String sql = "select name from " + tableNameVote;
		List<String> result = new ArrayList<String>();
		
		try {
			ps = conn.prepareStatement(sql);
			rs = ps.executeQuery();
			
			while(rs.next()) {
				result.add(rs.getString(1));
			}
		} catch(Exception e) {
			e.printStackTrace();
		}
		
		return result;
	}

	public boolean addVoteNum(String name) {
		
		String sql = "select num from " + tableNameVote + " where name = ?";
		int num = 0;
		
		try {
			ps = conn.prepareStatement(sql);
			ps.setString(1, name);
			
			rs = ps.executeQuery();
			
			while(rs.next()) {
				num = rs.getInt(1);
			}
		} catch(Exception e) {
			e.printStackTrace();
		}
		
		String sql2 = "update " + tableNameVote + " set num = ? where name = ?";
		int row = 0;
		try {
			ps = conn.prepareStatement(sql2);
			ps.setInt(1, num+1);
			ps.setString(2, name);
			
			row = ps.executeUpdate();
			
		} catch (Exception e) {
			e.printStackTrace();
		}
		
		if(row > 0)
			return true;
		else
			return false;
	}

	public List<VoteObject> getVoteResult() {
		
		String sql = "select * from " + tableNameVote;
		List<VoteObject> result = new ArrayList<VoteObject>();
		
		try {
			ps = conn.prepareStatement(sql);
			rs = ps.executeQuery();
			
			while(rs.next()) {
				VoteObject tmp = new VoteObject(rs.getString(1), rs.getInt(2));
				result.add(tmp);
			}
		} catch(Exception e) {
			e.printStackTrace();
		}
		
		return result;
	}
	
	public int getUserChances(String id) {
		
		String sql = "select chances from " + tableNameLogin + " where id=?";
		int result = 0;
		
		try {
			ps = conn.prepareStatement(sql);
			ps.setString(1, id);
			rs = ps.executeQuery();
			
			while(rs.next()) {
				result = rs.getInt(1);
			}
		} catch (Exception e) {
			e.printStackTrace();
		}
		return result;
	}

	public boolean delUserChances(String id) {
		
		String sql = "select chances from " + tableNameLogin + " where id=?";
		int currentChance = 0;
		
		try {
			ps = conn.prepareStatement(sql);
			ps.setString(1, id);
			
			rs = ps.executeQuery();
			while(rs.next()) {
				currentChance = rs.getInt(1);
			}
		} catch (Exception e) {
			e.printStackTrace();
		}
		
		String sql2 = "update " + tableNameLogin + " set chances = ? where id = ?";
		int row = 0;
		
		try {
			ps = conn.prepareStatement(sql2);
			ps.setInt(1, currentChance-1);
			ps.setString(2, id);
			
			row = ps.executeUpdate();
		} catch (Exception e) {
			e.printStackTrace();
		}
		
		if(row > 0)
			return true;
		else 
			return false;
	}

	public boolean getStatus(String id) {
		
		String sql = "select status from " + tableNameLogin + " where id=?";
		String status = "";
		
		try {
			ps = conn.prepareStatement(sql);
			ps.setString(1, id);
			
			rs = ps.executeQuery();
			while(rs.next()) {
				status = rs.getString(1);
			}
		} catch(Exception e) {
			e.printStackTrace();
		}
		
		if(status.equals("active"))
			return true;
		else
			return false;
		
	}

	public boolean resetAllChances() {
		
		String sql = "update " + tableNameLogin + " set chances = ?";
		int row = 0;
		
		try {
			ps = conn.prepareStatement(sql);
			ps.setInt(1, TOTAL_CHANCE);
			
			row = ps.executeUpdate();
		} catch(Exception e) {
			e.printStackTrace();
		}
		
		if(row > 0)
			return true;
		else
			return false;
	}

	public boolean ifHasUser(String id) {
		
		String sql = "select * from " + tableNameLogin + " where id = ?";
		String foundId = null;
		
		try {
			ps = conn.prepareStatement(sql);
			ps.setString(1, id);
			
			rs = ps.executeQuery();
			while(rs.next()) {
				foundId = rs.getString(1);
			}
		} catch(Exception e) {
			e.printStackTrace();
		}
		
		if(foundId == null || foundId.equals(""))
			return false;
		else
			return true;
	}
	
	public boolean setInactive(String id) {
		
		String sql = "update " + tableNameLogin + " set status = 'inactive' where id = ?";
		int row = 0;
		
		try {
			ps = conn.prepareStatement(sql);
			ps.setString(1, id);
			
			row = ps.executeUpdate();
		} catch(Exception e) {
			e.printStackTrace();
		}
		
		if(row > 0)
			return true;
		else
			return false;
	}
	
}
