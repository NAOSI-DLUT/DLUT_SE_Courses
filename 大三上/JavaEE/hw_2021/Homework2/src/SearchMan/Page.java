package SearchMan;

import java.util.*;

public class Page {
	
	public int currentPage;
	public int maxPages;
	public int maxRows;
	public int numPerPage;
	
	public List<Man> data;
	
	public void countMaxPage() {
		
		maxPages = (int)Math.ceil((double)maxRows/numPerPage);
	}

}


