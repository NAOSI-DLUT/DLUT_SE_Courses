//修改后的代码																									

/*【例2.12】栈的类定义。

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

【例2.13】栈的顺序实现。

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
			if(top == maxSize - 1)	//栈已满       //修改//
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

		bool Pop(T & item)     		//出栈操作
		{
			if(top == -1)      		//栈为空
			{
				cout << "栈为空，不能进行删除操作" << endl;     //修改//
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

/*
【例2.14】改进的进栈操作。

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

【例2.15】栈的链式实现。

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

【例2.16】阶乘函数。

long factorial(long n)
{
	if(n <= 0)
		return 1;
	return n * factorial(n-1);
}


【例2.17】阶乘函数主程序。

#include<iostream>
using namespace std;
int main()
{
	cout << factorial(4) << endl;
	return 0;
}


【例2.18】队列的抽象数据类型定义。

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


【例2.19】队列的顺序实现。

template<class T>
class ArrayQueue:public Queue<T>
{
	private:
		int maxSize;        			//存放队列数组的大小
		int front;           			//表示队头所在位置的下标
		int rear;              		//表示队尾所在位置的下标
		int *queue;                  	//存放类型为T的队列元素的数组

	public:
		ArrayQueue(int size)    		//创建队列的实例
		{
			maxSize = size + 1;    	//多出一个空间，区分队列空与满
			queue = new T[maxSize];
			front = rear = 0;
		}

		~ArrayQueue()               	//析构函数
		{
			delete [] queue;
		}

		void Clear()              	//清空队列
		{
			front = rear;
		}

		bool EnQueue(const T item)	//item入队，插入队尾
		{
			if((rear + 1) % maxSize == front)
			{
				cout << "队列已满，溢出" << endl;
				return false;
			}
			queue[rear] = item;
			rear = (rear + 1) % maxSize;
			return true;
		}

		bool DeQueue(T & item)  	//返回队头元素，并删除该元素
		{
			if(front == rear)
			{
				cout << "队列为空" << endl;
				return false;
			}
			item = queue[front];
			front = (front + 1) % maxSize;
			return true;
		}

		bool GetFront(T & item)  	//返回队头元素，但不删除
		{
			if(front == rear)
			{
				cout << "队列为空" << endl;
				return false;
			}
			item = queue[item];
			return true;
		}
};

【例2.20】队列的链式实现。

template<class T>
class LinkQueue:public Queue<T>
{
private:
	int size;              		//队列中当前元素的个数
	LinkNode<T> * front;       	//表示队列的头指针
	LinkNode<T> * rear;         	//表示队列的尾指针

public:
	LinkQueue(int size)        	//构造函数，创建队列的实例
	{
		size = 0;
		front = rear = NULL;
	}

	~LinkQueue()               	//析构函数
	{
		Clear();
	}

	void Clear()             		//清空队列
	{
		while(front != NULL)
		{
			rear = front;
			front = front->link;
			delete rear;
		}
		rear = NULL;
		size = 0;
	}

	bool EnQueue(const T item)	//item入队，插入队尾
	{
		if(rear == NULL)
		{
			front = rear = new LinkNode<T>(item, NULL);
		}
		else
		{
			rear->link = new LinkNode<T>(item, NULL);       //修改//
			rear = rear->link;                              //修改//
		}
		size++;
		return true;
	}

	bool DeQueue(T & item) 		//读取队头元素并删除
	{
		LinkNode<T> * temp;
		if(size == 0)
		{
			cout << "队列为空" << endl;
			return false;
		}
		&item = front->data;
		temp = front;
		front = front->link;
		delete temp;
		if(front == NULL)
		{
			rear = NULL;
		}
		size--;
		return true;
	}

	bool GetFront(T & item) 		//返回队头元素，但不删除
	{
		if(size == 0)
		{
			cout << "队列为空" << endl;
			return false;
		}
		item = front->data;
		return true;
	}
};

*/
