#include "stack.h"
#include "LinkNode.h"

template<class T>
class LinkStack:public Stack<T>
{
	private:
		LinkNode <T> *top;           		//指向栈顶的指针
		int size;                     		//存放元素的个数

	public:
		LinkStack(int s)             		//构造函数
		{
			top = NULL;
			size = 0;
		}
		~LinkStack()               		//析构函数
		{
			Clear();
		}
		void Clear()                		//清空栈内容
		{
			while(top != NULL)
			{
				LinkNode <T> *tmp = top;
				top = top->link;
				delete tmp;
			}
			size = 0;
		}
		bool Push(const T item)     		//入栈操作的链式实现
		{
			LinkNode <T> *tmp = new LinkNode<T>(item, top);
			top = tmp;
			size++;
			return true;
		}
		bool Pop(T & item)           		//出栈操作的链式实现
		{
			LinkNode<T> *tmp;
			if(size == 0)
			{
				cout << "栈为空，不能执行出栈操作" << endl;
				return false;
			}
			item = top->data;
			tmp = top->link;
			delete top;
			top = tmp;
			size--;
			return true;
		}
		bool Top(T & item)            //读取栈顶元素，但不删除
		{
			if(size == 0)
			{
				cout << "栈为空，不能读取栈顶元素" << endl;
				return false;
			}
			item = top->data;
			return true;
		}
};