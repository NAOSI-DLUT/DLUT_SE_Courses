package SearchMan;

import java.util.LinkedHashMap;
import java.util.*;

public class FIFOCache<K,V>{
	
	private static int MAX_CACHE_SIZE = 0;
	private final float LOAD_FACTORY = 0.75f;
	
	Map<K,V> map;
	
	public FIFOCache(int cacheSize) {
		MAX_CACHE_SIZE = cacheSize;
		//int capacity = (int)Math.ceil(MAX_CACHE_SIZE / LOAD_FACTORY) + 1;
		
		map = new LinkedHashMap<K,V>(MAX_CACHE_SIZE, LOAD_FACTORY, false) {
			@Override
			protected boolean removeEldestEntry(Map.Entry<K, V> eldest) {
				return size() >  MAX_CACHE_SIZE;
			}
		};
	}
	
	public synchronized void put(K key, V value) {
		map.put(key, value);
	}
	
	public synchronized V get(K key) {
		return map.get(key);
	}
	
	public synchronized void remove(K key) {
		map.remove(key);
	}
	
	public synchronized Iterator<Map.Entry<K, V>> getIterator() {
		return map.entrySet().iterator();
	}
	
	public int getNum() {
		return map.size();
	}

}
