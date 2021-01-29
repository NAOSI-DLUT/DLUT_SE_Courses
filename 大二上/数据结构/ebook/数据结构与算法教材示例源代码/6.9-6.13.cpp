#include <iostream>
using namespace std;
//6.9
template<class T>
void SelectionSort(T Data[], int n)
{
	for (int i = 1; i < n; i++)      	//共进行n-1趟选择
	{//第i趟时的待排序列为Data[i-1],…,Data[n-1]
		int k = i - 1;             		//记录当前待排序列的第一个元素
		for (int j = i; j < n; j++)	//找到待排序列中最小元素的下标
		{
			if (Data[j] < Data[k])
				k = j;
		}
		if (k != i - 1)		//交换最小元素到当前待排序列的第一个位置
		{
			T t = Data[k];
			Data[k] = Data[i - 1];
			Data[i - 1] = t;
		}
	}
}
//6.10
template<class T>
void SiftDown(T Data[], int i, int n)
{//用来保持以结点i为根的最大堆的性质，n是所有元素的个数
	int l = 2 * i + 1, r = 2 * i + 2, min = i;//找到i结点的两个孩子的下标
	if (l < n && Data[min] < Data[l])	   //和左子结点进行比较
		min = l;
	if (r < n && Data[min] < Data[r])	   //和右子结点进行比较
		min = r;
	if (min != i)						   //判断是否需要进行调整
	{
		T t = Data[min];
		Data[min] = Data[i];
		Data[i] = t;
		SiftDown(Data, min, n);			   //递归对子结点进行调整
	}
}
template<class T>
void BuildHeap(T Data[], int n)
{
	int p = n / 2 - 1;				//求出非叶子结点的最大下标
	for (int i = p; i >= 0; i--)
	{
		SiftDown(Data, i, n);		//调用SiftDown函数，保持最大堆的性质
	}
}
template<class T>
void MaxHeap(T Data[], int m, int n) 
{//调整取出最大元素后的堆
	for (int i = n / 2 - 1; i >= m; i--)
		SiftDown(Data, i, n);
}
template<class T>
void HeapSort(T Data[], int n)
{
	BuildHeap(Data, n);				//首先建立一个最大堆
	for (int i = n - 1; i > 0; i--)	//进行循环
	{
		T t = Data[0];				//每次取出最大元素后不断调整最大堆
		Data[0] = Data[i];
		Data[i] = t;
		MaxHeap(Data, 0, i);
	}
}
//6.11
template<class T>
void Merge(T Data[], int start, int mid, int end)
{
	int len1 = mid - start + 1, len2 = end - mid;//分别表示两个归并区间的长度
	int i, j, k;
	T *left = new int[len1];   //临时数组用来存放Data[start,mid]数据
	T *right = new int[len2];   //临时数组用来存放Data[mid+1,end]
	for (i = 0; i < len1; i++)   //执行数据复制操作
	{
		left[i] = Data[i + start];
	}
	for (i = 0; i < len2; i++)    //执行数据复制操作
	{
		right[i] = Data[i + mid + 1];
	}
	i = 0, j = 0;
	for (k = start; k<end; k++)   //执行归并
	{
		if (i == len1 || j == len2)
		{
			break;
		}
		if (left[i] <= right[j])
		{
			Data[k] = left[i++];
		}
		else
		{
			Data[k] = right[j++];
		}
	}
	while (i < len1)     //若Data[start,mid]还有待归并数据，则放到Data后面
	{
		Data[k++] = left[i++];
	}
	while (j < len2)      //对Data[mid+1,end]间的数据执行同样的操作
	{
		Data[k++] = right[j++];
	}
	delete[] left;    //释放内存
	delete[] right;
}
//6.12
template<class T>
void MergeSort(T Data[], int start, int end)
{//对Data[start]-Data[end]之间的序列进行归并排序
	if (start < end)
	{
		T mid = (start + end) / 2;   	//计算中间位置
		MergeSort(Data, start, mid);    	//对左边子序列归并排序
		MergeSort(Data, mid + 1, end);    	//对右边子序列归并排序
		Merge(Data, start, mid, end);  	//归并左、右两边的有序序列
	}
}
//6.13
const int RADIX = 10;					//定义基数，用于区分不同进制
template<class T>
struct LinkNode {						//定义链式结构的结点
	T data;
	LinkNode* next;
};
template<class T>
struct TubNode {							//定义队列数组结点
	LinkNode<T>*rear;
	LinkNode<T>*front;
};
/*
分配操作
输入：Data[]数据数组，n 元素个数, ith第i次分配操作
输出：执行分配操作之后的一个队列数组。
*/
template<class T>
TubNode<T>* Distribute(T Data[], int n, int ith)
{
	//申请内存
	TubNode<T>* tube = new TubNode<T>[RADIX];
	//执行初始化
	memset(tube, 0, sizeof(TubNode<T>)*RADIX);
	LinkNode<T>* t;
	for (int i = 0; i<n; i++)
	{
		T v = Data[i];
		int j = ith - 1;
		while (j--)					//求第i个位上的数字
			v = v / RADIX;
		v = v % RADIX;
		t = new LinkNode<T>;		//申请新的链表结点
		t->data = Data[i];
		t->next = NULL;
		if (tube[v].front)			//如果对应的队列不为空，则放到末尾
		{
			tube[v].rear->next = t;
			tube[v].rear = t;
		}
		else						//否则，初始化队列头和尾
		{
			tube[v].front = tube[v].rear = t;
		}

	}
	return tube;
}
/*
收集操作，将tube中数据收集到Data数组中
输入：Data数据数组，tube执行完分配操作之后的队列数组
输出：无
*/
template<class T>
void Collect(T Data[], TubNode<T>* tube)
{
	LinkNode<T>*t, *p;				//临时变量
	int index = 0;					//数据下标
	for (int i = 0; i<RADIX; i++)
	{
		p = t = tube[i].front;
		while (t)
		{
			Data[index++] = t->data;//复制对应数据
			t = t->next;
			delete p;				//释放内存
			p = t;
		}
	}
	delete[] tube;					//释放内存
}

/*
基数排序，堆Data[]中数据进行排序，并将结果放入到Data[]中
输入：Data[]数据，n元素个数，keys关键字个数
输出：无
*/
template<class T>
void RadixSort(T Data[], int n, int keys)//基数排序
{
	TubNode<T>* tube;
	for (int i = 0; i<keys; i++)			//循环执行keys次分配和收集操作
	{
		tube = Distribute<T>(Data, n, i + 1);
		Collect<T>(Data, tube);
	}
}
int main()
{
	int a[10] = { 0,2,3,5,6,7,1,9,8,4 };

	SelectionSort(a, 10);
	HeapSort(a, 10);
	MergeSort(a, 0, 9);
	RadixSort(a, 10, 1);
	for (int i = 0; i < 10;i++)
		cout << a[i];

	system("pause");
	return 0;
}