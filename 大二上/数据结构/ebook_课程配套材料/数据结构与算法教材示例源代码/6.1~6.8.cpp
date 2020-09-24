#include <iostream>

using namespace std;


template<class T>
void PrintArray(T Data[],int n){
    for(int i=0;i!=n;i++){
        cout<<Data[i]<<",";
    }
    cout<<'\b'<<endl;
}

template<class T>
void InsertionSort(T Data[],int n)
{//利用直接插入排序对于n个数据元素进行不减序排序
	int p,i;
	for( p = 1; p < n; p++)	//循环，p表示插入趟数，共进行n-1趟插入
	{
		T temp = Data[p];	//把待插入元素赋给temp
		i = p - 1;
		while( i>= 0 && Data[i] > temp)	//把比temp大的元素都向后移动
		{
			Data[i+1] = Data[i];
			i--;
		}
		Data[i+1] = temp;	//i+1为temp的位置，将temp插入到这个位置
		PrintArray(Data,n);
	}
}

template<class T>
void BinaryInsertionSort(T Data[],int n)	//参数：待排序数据和待排序元													//素个数
{
	int left,mid,right,p;				//声明一些变量
	for( p = 1; p < n; p++)				//共进行n-1次插入
	{
		T temp = Data[p];				//保存待插入数据
		left = 0,right = p-1;			  //初始化left和right的值
		while(left <= right)			  //执行折半查找
			{
			mid = (left + right) / 2;	  //求出中心点
			if( Data[mid] > temp ) 		  //中心点元素值比待插入数据大
				right = mid -1;			  //更新右区间值
			else
				left = mid + 1;			  //更新左区间值
		}
		for( int i = p-1; i >= left; i--)//执行移动操作
			Data[i+1] = Data[i];
		Data[left] = temp;				 //将待插入元素插入到有序表中
	}
}


template<class T>
void ShellSort(T Data[],int n)
{
	int d = n/2;						//增量初始化为数组大小的一半
	while(d>=1)							//循环遍历增量的所有可能
	{
		for(int k = 0; k<d; k++)		//遍历所有的子序列
		{
			for( int i = k+d; i < n; i+=d)	//对每一个子序列执行直接插													//入排序
			{
				T temp = Data[i];
				int j = i - d;
				while( j>= k && Data[j] > temp)
				{
					Data[j+d] = Data[j];
					j -= d;
				}
				Data[j+d] = temp;
			}
		}
		d = d/2;						//增量变为上次的一半
	}
}

template<typename T>
void BubbleSort(T Data[],int n)
{
	for(int i = 0; i < n; i++)			//外层循环控制排序的每一趟
	{
		for(int j = 1; j < n-i; j++)	//内层循环控制本趟中的冒泡操作
		{
			if(Data[j] < Data[j-1])		//如果是逆序的，则交换这两个元素
			{
				T t = Data[j];
				Data[j] = Data[j-1];
				Data[j-1] = t;
			}
		}
	}
}

template<class T>
void BubbleSort1(T Data[],int n)
{
	int  flag = 0;               //标记每一趟的冒泡排序过程中是否发生了交换
	for(int i = 0; i < n; i++)			//外层循环控制排序的每一趟
	{   flag = 0;
		for(int j = 1; j < n-i; j++)	//内层循环控制本趟中的冒泡操作
		{
			if(Data[j] < Data[j-1])		//如果是逆序的，则交换这两个元素
			{   flag = 1;
				T t = Data[j];
				Data[j] = Data[j-1];
				Data[j-1] = t;
			}
		}
		if (flag == 0)   //如果某一趟的冒泡过程中没有发生交换则结束排序
			return;
	}
}


以下两个函数中有几处是中文符号导致的错误，没进行标注
template <class T>
int Partition2(T Data[],int start, int fin)
{//实现对data[start]到data[fin]的分割操作，并返回划分后轴元素对应的位置
	T pivot = Data[start];
	int left =start, right = fin; 		//初始化left,right
    while(left<=right)					//外层循环控制遍历数组
	{
		while(left<= right && Data[left] <= pivot)//控制left指针的移动
			left++;
		while(left<=right && Data[right] >pivot)	//控制right指针移动
			right--;
		if(left<right)
        {
            swap(Data[right],Data[left]);//交换Data[right]和Data[left]
            left ++; right--;
        }
	}
    swap(Data[start] ,Data[right]);	//交换Data[right]和轴元素Data[start]
    cout<<"Part2"<<endl;
	return right;				//返回轴元素的新位置，实现分治
}

template <class T>
int Partition1(T Data[],int left, int right)
{//实现对data[left]到data[right]的分割操作，并返回划分后轴元素对应的位置
	T pivot = Data[left];			//选择最左边的为轴元素
	while(left < right)				//外层循环控制遍历数组
	{
		while(left< right && Data[right] > pivot)//控制right指针的移动
			right--;
		Data[left] = Data[right];	//将right指向的数据移动到left位置
		while(left < right && Data[left] <= pivot)//控制left指针移动
			left++;
		Data[right] = Data[left];	//将left指向的数据移动到right位置
	}
	Data[left] = pivot;				//将轴元素放到left位置
	cout<<"Part1"<<endl;
	return left;					//返回轴元素的新位置，实现分治
}

template <class T>
void QuickSort(T Data[],int left,int right)
{//用分治法实现快速排序算法
	if(left < right)						//控制分治的结束条件
	{
		int p = Partition1(Data,left,right);	//实现分割并找到分离的位置
		QuickSort(Data,left,p-1);		//对左边的子序列进行快速排序
		QuickSort(Data,p+1,right);		//对右边的子序列进行快速排序
	}
	cout<<"Quick"<<endl;
}

int main()
{
    int Data[]={32,18,65,48,27,9};
    int Data1[]={65,34,25,87,12,38,56,46,14,77,92,23};
    QuickSort<int>(Data1,0,11);
    PrintArray<int>(Data1,12);
    return 0;
}
