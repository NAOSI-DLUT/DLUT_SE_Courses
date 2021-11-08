# JavaEE 第一节课：Servlet组件

## 1.容器的概念

容器主要包括 Collection 和 Map 两种，Collection 存储着对象的集合，而 Map 存储着键值对（两个对象）的映射表。

### 1）Collection

#### a.Set

* TreeSet：基于红黑树实现，支持有序性操作，例如根据一个范围查找元素的操作。但是查找效率不如 HashSet，HashSet 查找的时间复杂度为 O(1)，TreeSet 则为 O(logN)。

* HashSet：基于哈希表实现，支持快速查找，但不支持有序性操作。并且失去了元素的插入顺序信息，也就是说使用 Iterator 遍历 HashSet 得到的结果是不确定的。

* LinkedHashSet：具有 HashSet 的查找效率，且内部使用双向链表维护元素的插入顺序。

  有序性操作：插入时自动排序

#### b.List

* ArrayList：基于动态数组实现，支持随机访问。

* Vector：和 ArrayList 类似，但它是线程安全的。

* LinkedList：基于双向链表实现，只能顺序访问，但是可以快速地在链表中间插入和删除元素。不仅如此，LinkedList 还可以用作栈、队列和双向队列。

  **线程安全：多个线程访问同一变量或对象时，都能保证结果的正确性就是线程安全。**

#### c.Queue

* LinkedList：可以用它来实现双向队列。
* PriorityQueue：基于堆结构实现，可以用它来实现优先队列。

### 2）Map

* TreeMap：基于红黑树实现
* HashMap：基于哈希表实现
* HashTable：和 HashMap 类似，但它是线程安全的，这意味着同一时刻多个线程可以同时写入 HashTable 并且不会导致数据不一致。它是遗留类，不应该去使用它。现在可以使用 ConcurrentHashMap 来支持线程安全，并且 ConcurrentHashMap 的效率会更高，因为 ConcurrentHashMap 引入了分段锁。

## 2.容器中的设计模式

### 1）迭代器模式

Collection 继承了 Iterable 接口，其中的 iterator() 方法能够产生一个 Iterator 对象，通过这个对象就可以迭代遍历 Collection 中的元素。

```java
List<String> list = new ArrayList<>();
list.add("a");
list.add("b");
for (String item : list) {
    System.out.println(item);
}
```

### 2）适配器模式

```  java
java.util.Arrays#asList() 可以把数组类型转化为List类型
```

应该注意的是 asList() 的参数为泛型的变长参数，**不能使用基本类型数组**作为参数，只能使用相应的包装类型数组。

```java
Integer[] arr = {1, 2, 3};
List list = Arrays.asList(arr);
```

也可以使用以下方式调用 asList()：

```java
List list = Arrays.asList(1, 2, 3);
```

## 2.容器中的组件

容器理解为java中的一个应用，启动之后加载并运行容器中的组件。容器管理组件，管理组件的**生命周期**。容器创建组件对象，并向组件提供配置信息。之后组件运行在服务器进程，并为客户端提供服务。由于是客户端与服务器端之间的交互，所以客户端想要访问组件需要通过应用协议。协议可以是自定义协议也可以是标准互联网访问协议（HTTP）等。

组件运行过程中需要访问容器，其中的关系为：

**容器执行组件的函数，组件访问容器，容器会传给组件一个配置对象：ServletConfig**

其中有一个函数为getServletContext，可以获得代表整个应用的ServletConfig对象，这个对象提供Web应用全局服务。 

组件的声明通过一个部署描述符文件（web.xml）来完成组件的声明和组件的访问的URL地址。





 