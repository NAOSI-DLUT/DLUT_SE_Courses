package Vote;

public class VoteObject {
	
	private String name;
	private int num;
	
	public VoteObject() {
		name = "";
		num = 0;
	}
	
	public VoteObject(String nname, int nnum) {
		name = nname;
		num = nnum;
	}
	
	public String getName() {
		return name;
	}
	
	public int getNum() {
		return num;
	}
	
	public void set(String nname, int nnum) {
		name = nname;
		num = nnum;
	}

}
