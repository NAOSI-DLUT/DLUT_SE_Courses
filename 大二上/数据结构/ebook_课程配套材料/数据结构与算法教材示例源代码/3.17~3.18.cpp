#include<iostream>
using namespace std;

template <class T>
class MaxHeap
{
private:
	T* heapArray;               		//存放堆数据的数组
	int CurrentSize;             		//当前堆中元素数目
	int MaxSize;                		//堆所能容纳的最大元素数目
public:
	MaxHeap(T* array, int num, int max) {
		this->heapArray = new T[num];
		for (int i = 0; i < num; i++) {
			this->heapArray[i] = array[i];
		}
		this->CurrentSize = num;
		this->MaxSize = max;
	}
	virtual ~MaxHeap() {};    		//析构函数
	void BuildHeap();
	bool isLeaf(int pos) const;		//如果是叶结点，返回TRUE
	int leftchild(int pos) const;	//返回左孩子位置
	int rightchild(int pos) const;	//返回右孩子位置
	int parent(int pos) const;   	//返回父结点位置
	bool Remove(int pos, T& node);	//删除给定下标的元素
	void SiftDown(int left);    //筛选法函数，参数left表示开始处理的数组下标
	void SiftUp(int position);	//从position向上开始调整，使序列成为堆
	bool Insert(const T& newNode);	//向堆中插入新元素newNode
	void MoveMax();                  	//从堆顶移动最大值到尾部
	T& RemoveMax();                  	//从堆顶删除最大值
	T* getMaxHeap();
	int getCurrSize();
};

template<class T>
int MaxHeap<T>::getCurrSize()
{
	return CurrentSize;
}

template<class T>
bool MaxHeap<T>::isLeaf(int pos) const
{
	if (2 * pos + 1 > CurrentSize - 1)
		return true;
	else
		return false;
}

template<class T>
int MaxHeap<T>::leftchild(int pos) const
{
	int leftchild;
	if (!isLeaf(pos))
	{
		leftchild = 2 * pos + 1;
		cout << pos << "号结点的左孩子为" << leftchild << "号" << endl;
	}
	else
		cout << pos << "号结点是叶子结点，没有左孩子" << endl;
	return leftchild;
}

template<class T>
int MaxHeap<T>::rightchild(int pos) const
{
	int rightchild = 2 * pos + 2;
	if (rightchild < CurrentSize)
		cout << pos << "号结点的右孩子为" << rightchild << "号" << endl;
	else
		cout << pos << "号结点没有右孩子" << endl;

	return rightchild;
}

template<class T>
int MaxHeap<T>::parent(int pos) const
{
	int parent = 0;
	if (pos > 0)
	{
		parent = (pos - 1) / 2;
		cout << pos << "号结点的父结点为" << parent << "号" << endl;
	}
	else
		cout << pos << "号位置无父结点" << endl;
	return parent;
}

template<class T>
bool MaxHeap<T>::Remove(int pos, T& node)
{
	int i = pos;
	int j = CurrentSize - 1;
	T temp = node;
	heapArray[i] = heapArray[j];
	heapArray[j] = temp;
	CurrentSize--;
	BuildHeap();
	return true;
}

template<class T>
void MaxHeap<T>::SiftUp(int position)
{
	//准备
	int i = position;           //标识插入的新结点
	int j = parent(position);   //标识父结点
	T temp = heapArray[i];     	//保存新结点的关键码
								//过筛
	while (j >= 0)
	{
		if (temp > heapArray[j])
		{                             //该结点的关键码大于父结点的值时
			heapArray[i] = heapArray[j];	//交换对应值
			i = j;
			j = parent(i);              //向上继续判断是否满足最大堆的性质
		}
		else break;
	}
	heapArray[i] = temp;
}

template<class T>
bool MaxHeap<T>::Insert(const T& newNode)
{
	heapArray[CurrentSize] = newNode;
	SiftUp(CurrentSize);
	CurrentSize++;
	return true;
}

template<class T>
T* MaxHeap<T>::getMaxHeap()
{
	return heapArray;
}

template<class T>
void MaxHeap<T>::BuildHeap()
{
	for (int i = CurrentSize / 2 - 1; i >= 0; i--)
		SiftDown(i);
}

template<class T>
void MaxHeap<T>::SiftDown(int left)
{
	//准备
	int i = left;            			//标识父结点
	int j = 2 * i + 1;           		//标识左子结点
	T temp = heapArray[i];     		//保存父结点的关键码
									//过筛
	while (j < CurrentSize)
	{
		if ((j < CurrentSize - 1) && (heapArray[j] < heapArray[j + 1]))
			j++;
		//该结点有右孩子且右孩子的关键码大于左孩子的关键码时，j指向右子结点
		if (temp < heapArray[j])
		{                           //该结点的关键码小于左右孩子中比较大的那个时
			heapArray[i] = heapArray[j];	//交换对应值
			i = j;
			j = 2 * j + 1;                //向下继续判断是否满足最大堆的性质
		}
		else break;
	}
	heapArray[i] = temp;
}

int main()
{
	int a[10] = { 20,12,35,15,10,80,30,17,2,1 };
	MaxHeap<int> mh1(a, 10, 20);
	mh1.BuildHeap();
	int *b = mh1.getMaxHeap();
	for (int i = 0; i < mh1.getCurrSize(); i++) {
		cout << b[i] << ' ';
	}
	if (mh1.isLeaf(3))
		cout << "true" << endl;
	else
		cout << "false" << endl;
	mh1.leftchild(3);
	mh1.rightchild(3);
	mh1.parent(3);
	mh1.Insert(25);
	int *c = mh1.getMaxHeap();
	for (int i = 0; i < mh1.getCurrSize(); i++) {
		cout << c[i] << ' ';
	}
	cout << endl;
	mh1.Remove(1, c[1]);
	int *d = mh1.getMaxHeap();
	for (int i = 0; i < mh1.getCurrSize(); i++) {
		cout << d[i] << ' ';
	}
	return 0;
}