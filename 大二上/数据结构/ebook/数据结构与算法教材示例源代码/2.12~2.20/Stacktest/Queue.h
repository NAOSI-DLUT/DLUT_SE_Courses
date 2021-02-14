template<class T>
class Queue
{
public:
	void Clear();                		//清空队列
	bool EnQueue(const T item); 	//队列的尾部加入元素item
	bool DeQueue(T & item);     		//取出队列的第一个元素，并删除
	bool IsEmpty();             		//判断队列是否为空
	bool IsFull();              		//判断队列是否已满
	bool GetFront(T & item);     	//读取队头元素，但不删除
};
