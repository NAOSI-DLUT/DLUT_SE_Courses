package SearchMan;

public class Man {
	
	private String id = null;
	private String name = null;
	private String tel = null;
	private String qq = null;
	private String mail = null;
	
	public Man() {}
	
	public Man(String iid, String nname, String ttel, String qqq, String mmail) {
		id = iid;
		name = nname;
		tel = ttel;
		qq = qqq;
		mail = mmail;
	}
	
	public void setId(String iid) {
		id = iid;
	}
	
	public void setName(String nname) {
		name = nname;
	}
	
	public void setTel(String ttel) {
		tel = ttel;
	}
	
	public void setQq(String qqq) {
		qq = qqq;
	}
	
	public void setMail(String mmail) {
		mail = mmail;
	}
	
	public String printMan() {
		
		String man = "id: " + id + "  name: " + name + "  tel: " + tel + "  qq: " + qq + "  mail: " + mail;
		return man;
	}
	
	public boolean isMatch(String query) {	//�ж�������Ϣ�ǲ�������ˣ���ģ����ѯ
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
	
	public boolean isEquals(String iid) {	//ͨ���ж�id�Ƿ���ͬ�����ж��Ƿ���������ͬ��
		if(iid.equals(id))
			return true;
		return false;
	}

}
