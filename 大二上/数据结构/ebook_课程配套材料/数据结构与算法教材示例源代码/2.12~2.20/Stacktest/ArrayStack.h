#include "stack.h"

template<class T>
class ArrayStack:public Stack<T>
{
	private:
		int maxSize;          		//栈的最大值
		int top;              		//栈顶位置
		T *st;               			//存放栈元素的数组

	public:
		ArrayStack(int size)		//创建一个给定长度的顺序栈实例
		{
			maxSize = size;
			top = -1;
			st = new T[maxSize];
		}

		ArrayStack()          		//创建一个顺序栈实例
		{
			top = -1;
		}

		~ArrayStack()         		//析构函数
		{
			delete [] st;
		}

		void Clear()          		//清空栈的内容
		{
			top = -1;
		}

		bool Push(const T item)		//入栈操作
		{
			if(top == maxSize - 1)	//栈已满
			{
				cout << "栈满溢出" << endl;
				return false;
			}
			else                		//入栈，并修改栈顶指针
			{
				st[++top] = item;
				return true;
			}      
		}

		
/* 改进的进栈操作
template<class T>             
bool ArrayStack<T>::push(const T item)
{
	if(top == maxSize - 1)
	{
		T * newSt = new T [maxSize * 2];
		for(int i = 0; i <= top; i++)
		{
			newSt[i] = st[i];
		}
		delete [] st;     //释放原栈
		st = newSt;
		maxSize *= 2;
	}
	st[++top] = item;
	return true;
}
*/

		bool Pop(T & item)     		//出栈操作
		{
			if(top == -1)      		//栈为空
			{
				cout << "栈为空，不能进行删除操作" << endl;
				return false;
			}
			else
			{
				item = st[top--];	//读取栈顶元素并修改栈顶指针
				return true;
			}
		}

		bool Top(T & item)      		//读取栈顶元素，但不删除
		{
			if(top == -1)        	//栈为空
			{
				cout << "栈为空，不能读取栈顶元素" << endl;
				return false;
			}
			else
			{
				item = st[top];
				return true;
			}
		}
};