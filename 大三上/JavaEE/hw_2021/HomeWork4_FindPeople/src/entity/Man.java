package entity;

public class Man {
	
	private String id = null;
	private String name = null;
	private String tel = null;
	private String qq = null;
	private String mail = null;

	public Man() {}

	public Man(String id, String name, String tel, String qq, String mail) {
		this.id = id;
		this.name = name;
		this.tel = tel;
		this.qq = qq;
		this.mail = mail;
	}

	public String getId() {
		return id;
	}

	public void setId(String id) {
		this.id = id;
	}

	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}

	public String getTel() {
		return tel;
	}

	public void setTel(String tel) {
		this.tel = tel;
	}

	public String getQq() {
		return qq;
	}

	public void setQq(String qq) {
		this.qq = qq;
	}

	public String getMail() {
		return mail;
	}

	public void setMail(String mail) {
		this.mail = mail;
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
	
	public boolean isEquals(String iid) {
		if(iid.equals(id))
			return true;
		return false;
	}

}
