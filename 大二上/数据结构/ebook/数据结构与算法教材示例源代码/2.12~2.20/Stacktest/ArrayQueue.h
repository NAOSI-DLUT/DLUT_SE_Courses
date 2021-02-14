#include "Queue.h"

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