template<class T>
class Stack
{
	public:
		void Clear();              	//清空栈
		bool Push(const T item);	//栈的压入操作
		bool Pop(T & item);        	//读取栈顶元素的值并删除
		bool Top(T & item);        	//读取栈顶元素的值但不删除
		bool IsEmpty();            	//判断栈是否为空
		bool IsFull();              	//判断栈是否已满
}; 

