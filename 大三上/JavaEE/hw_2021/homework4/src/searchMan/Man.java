package searchMan;

public class Man {
	
	private String id = null;
	private String name = null;
	private String tel = null;
	private String qq = null;
	private String mail = null;
	
	/*
	 * 构造函数，两个
	 */
	public Man() {}
	
	public Man(String iid, String nname, String ttel, String qqq, String mmail) {
		id = iid;
		name = nname;
		tel = ttel;
		qq = qqq;
		mail = mmail;
	}
	
	public String getID() { return id;}
	public String getName() { return name; }
	public String getTel() { return tel; }
	public String getQq() { return qq; }
	public String getMail() { return mail; }
	
	/*
	 * 判断输入的信息当前人是否拥有，模糊查询
	 */
	public boolean isMatch(String query) {	
		if(id.equals(query))
			return true;
		else if(name.contains(query))
			return true;
		else if(tel.contains(query))
			return true;
		else if(qq.contains(query))
			return true;
		else if(mail.contains(query))
			return true;
		else
			return false;
	}
	
	/*
	 * 判断id是否相同
	 */
	public boolean isEquals(String iid) {	
		if(iid.equals(id))
			return true;
		return false;
	}

}

