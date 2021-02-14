#include "Queue.h"
#include "LinkNode.h"

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
			rear->link = new LinkNode<T>(item, NULL);
			rear = rear->link;
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
		item = front->data;
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
