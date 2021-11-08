package service;

import java.io.*;
import java.util.*;

import entity.Man;
import jxl.*;
import jxl.Workbook;  
import jxl.read.biff.BiffException;  


public class ReadFile {
	private static int LIST_SIZE = 8;

	private Workbook wb;
	private FIFOCache<String, Man> cache = null;;
	private ArrayList<Man> manList = null;

	/**
	 * 读取文件，并且生成缓存
	 * @param filename
	 * @param ccache
	 */
	public ReadFile(String filename, FIFOCache<String, Man> ccache) {
		
		cache = ccache;
		manList = new ArrayList<Man>();
		
		try {
			wb = Workbook.getWorkbook(new File(filename));
		} catch (FileNotFoundException e) {
			e.printStackTrace(); 
		} catch (BiffException e) {
			e.printStackTrace(); 
		} catch (IOException e) {
			e.printStackTrace();  
		}
		
	}

	/**
	 * 判断数据是否已经存在在缓存之中 --xy
	 * @param query
	 * @return
	 */
	private boolean isInCache(String query) {
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

	/**
	 * 判断Man对象是否已经存在于列表之中 --xy
	 * @param id
	 * @return
	 */
	private boolean isInManList(String id) {
		Iterator<Man> it = manList.iterator();
		
		while(it.hasNext()) {
			Man man = it.next();
			if(man.isEquals(id) == true)
				return true;
		}
		return false;
	}

	/**
	 * 判断是否Man列表达到最大值，但是本程序中已经不再调用 --xy
	 * @return
	 */
	private boolean isManListFull() {
		if(manList.size() == LIST_SIZE || manList.size() > LIST_SIZE)
			return true;
		return false;
	}
	
	public ArrayList<Man> search(String query) {		
		

		isInCache(query);
		

		int sheet_size = wb.getNumberOfSheets(); 
		int i = 0, j = 0;

		System.out.println("index_sheet:"+sheet_size);
		for (int index=0; index<sheet_size; index++) {
            Sheet sheet = wb.getSheet(index);

            for (i = 0; i < sheet.getRows(); i++) {
            	for (j = 0; j < sheet.getColumns(); j++) {
            		//推测可能是因为j不应该从0开始，可以尝试更改 --xy --10.17
					//更改失败，j需要从0开始判断 --xy --10.18
            		String cellinfo = sheet.getCell(j, i).getContents();
            		
            		if(cellinfo.contains(query)) {
            			String id = sheet.getCell(0, i).getContents();
            			System.out.println("Contents:"+id);
            			if(isInManList(id) == true)
            				continue;
            			Man manTemp = new Man(id, sheet.getCell(1, i).getContents(), 
            					sheet.getCell(2, i).getContents(), sheet.getCell(3, i).getContents(), 
            					sheet.getCell(4, i).getContents());
            			//不要判断是否列表满，直接全部读取到Man组中，最后由jsp判断显示多少 --xy
//            			if(this.isManListFull() == true)
//            				continue;
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
