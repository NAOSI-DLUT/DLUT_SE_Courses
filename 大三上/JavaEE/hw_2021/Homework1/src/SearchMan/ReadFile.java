package SearchMan;

import java.io.*;
import java.util.*;

import jxl.*;
import jxl.Workbook;  
import jxl.read.biff.BiffException;  


public class ReadFile {
	
	private static int CACHE_SIZE = 3;
	private static int LIST_SIZE = 8;
	
	private Workbook wb;
	private FIFOCache<String, Man> cache = null;;
	private ArrayList<Man> manList = null;
	
	public ReadFile(String filename, FIFOCache<String, Man> ccache) {
		
		cache = ccache;
		manList = new ArrayList<Man>();
		
		try {
			// 读文件的预处理
			wb = Workbook.getWorkbook(new File(filename));
		} catch (FileNotFoundException e) {
			e.printStackTrace(); 
		} catch (BiffException e) {
			e.printStackTrace(); 
		} catch (IOException e) {
			e.printStackTrace();  
		}
		
	}
	
	private boolean isInCache(String query) {	// 判断是否在cache中，如果在，都添加到返回给主类的manList中
		Iterator<Map.Entry<String, Man>> it = cache.getIterator();
		boolean flag = false;
		
		while(it.hasNext()) {
			Map.Entry<String, Man> now = it.next();
			Man value = now.getValue();
			if(value.isMatch(query) == true) {
				if(this.isManListFull() == true)
					continue;
				manList.add(value);
				System.out.println("got one in cache!");
				System.out.println("cacah now has " + cache.getNum() + " elements!");
				flag = true;
			}
		}
		
		return flag;
	}
	
	private boolean isInManList(String id) {	// 判断是否在manList中，避免重复
		Iterator<Man> it = manList.iterator();
		
		while(it.hasNext()) {
			Man man = it.next();
			if(man.isEquals(id) == true)
				return true;
		}
		return false;
	}
	
	private boolean isManListFull() {
		if(manList.size() == LIST_SIZE || manList.size() > LIST_SIZE)
			return true;
		return false;
	}
	
	public ArrayList<Man> search(String query) {		
		
		//先在cache中查
		isInCache(query);
		
		//再从表中直接查
		int sheet_size = wb.getNumberOfSheets(); 
		int i = 0, j = 0;
		
		for (int index=0; index<sheet_size; index++) {
			
            Sheet sheet = wb.getSheet(index); 		//每个页签创建一个Sheet对象  
            
            for (i = 0; i < sheet.getRows(); i++) {	//循环一行
            	
            	for (j = 0; j < sheet.getColumns(); j++) {	//循环一列
            		String cellinfo = sheet.getCell(j, i).getContents();
            		
            		if(cellinfo.contains(query)) {	//查到了是这个人
            			String id = sheet.getCell(0, i).getContents();
            			//如果已经在manList里了
            			if(isInManList(id) == true)
            				continue;
            			Man manTemp = new Man(id, sheet.getCell(1, i).getContents(), 
            					sheet.getCell(2, i).getContents(), sheet.getCell(3, i).getContents(), 
            					sheet.getCell(4, i).getContents());
            			if(this.isManListFull() == true)
            				continue;
            			manList.add(manTemp);
            			cache.put(id, manTemp);
            			System.out.println("after add one to cache, cache now has " + cache.getNum() + " elements");
            		}
            	}
            }
		}
		return manList;
	}
	
	public int getCacheNum() {
		return cache.getNum();
	}

}
