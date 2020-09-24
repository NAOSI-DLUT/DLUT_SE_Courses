#include <iostream>
#include<stdlib.h>
using namespace std;

template <class T>
class MinHeap
{
private:
	T* heapArray;               		//存放堆数据的数组
	int CurrentSize;             		//当前堆中元素数目
	int MaxSize;                		//堆所能容纳的最大元素数目
public:
	MinHeap(T* array, int num, int max) {
		this->heapArray = new T[num];
		for (int i = 0; i<num; i++) {
			this->heapArray[i] = array[i];
		}

		this->CurrentSize = num;
		this->MaxSize = max;
	}
	virtual ~MinHeap() {};    		//析构函数
	void BuildHeap();
	bool isLeaf(int pos) const;		//如果是叶结点，返回TRUE
	int leftchild(int pos) const;	//返回左孩子位置
	int rightchild(int pos) const;	//返回右孩子位置
	bool Remove(int pos, T& node);	//删除给定下标的元素
	void SiftDown(int left);//筛选法函数，参数left表示开始处理的数组下标
	void SiftUp(int position);	//从position向上开始调整，使序列成为堆
	bool Insert(const T& newNode);	//向堆中插入新元素newNode
	void MoveMin();                  	//从堆顶移动最小值到尾部
	T& RemoveMin();                  	//从堆顶删除最小值
	T* getMinHeap();
	int getCurrSize();
};

template<class T>
void MinHeap<T>::BuildHeap()
{
	for (int i = CurrentSize / 2 - 1; i >= 0; i--)
		SiftDown(i);
}

template<class T>
T* MinHeap<T>::getMinHeap()
{
	return heapArray;
}

template<class T>
int MinHeap<T>::getCurrSize()
{
	return CurrentSize;
}

template<class T>
T& MinHeap<T>::RemoveMin()
{                                     		//删除堆顶元素
	if (CurrentSize == 0)
	{
		//空堆情况
		cout << "Can't Delete";
		exit(1);
	}
	else
	{
		T temp = heapArray[0];       		//取堆顶元素
		heapArray[0] = heapArray[CurrentSize - 1];//将堆尾元素上升至堆顶
		CurrentSize--;	              	//堆中元素数量减1
		if (CurrentSize > 1)    			//堆中元素个数大于1时才需要调整
											//从堆顶开始筛选
			SiftDown(0);
		cout << temp << ' ';
		return temp;
	}
}

template<class T>
void MinHeap<T>::SiftDown(int left)
{
	//准备
	int i = left;            			//标识父结点
	int j = 2 * i + 1;           		//标识左子结点
	T temp = heapArray[i];     		//保存父结点的关键码
									//过筛
	while (j < CurrentSize)
	{
		if ((j < CurrentSize - 1) && (heapArray[j] > heapArray[j + 1]))
			j++;
		//该结点有右孩子且右孩子的关键码小于左孩子的关键码时，j指向右子结点
		if (temp>heapArray[j])
		{                       //该结点的关键码大于左右孩子中比较小的那个时
			heapArray[i] = heapArray[j];	//交换对应值
			i = j;
			j = 2 * j + 1;                 //向下继续判断是否满足最大堆的性质
		}
		else break;
	}
	heapArray[i] = temp;
}

int main()
{

	int a[10] = { 15,2,7,17,5,30,13,12,9,18 };

	MinHeap<int> mh1(a, 10, 20);

	mh1.BuildHeap();
	int *b = mh1.getMinHeap();
	cout << "最小堆的构建结果：";
	for (int i = 0; i<10; i++) {
		cout << b[i] << ' ';
	}
	cout << endl;
	cout << "优先队列的出队结果：";
	while (mh1.getCurrSize()>0)
	{
		mh1.RemoveMin();
	}

	return 0;
}
