#include <iostream>

using namespace std;

template <class T>
int BiSearch(T Array[], T key, int n)
{ //折半查找过程，Array[0,…,n-1]为待查找的有序数据记录，key为查找的记录
	int left = 0;          	//定义查找范围的左端
	int right = n-1;       	//定义查找范围的右端，n表示数组的长度
	int mid;                	//定义查找范围的中间点
	while (left <= right)
	{//如果查找范围有效，则进行查找，否则结束查找
		mid = (left + right)/2;
		if (key < Array[mid])
		{ //将查找范围缩小到中间元素的左边
			right = mid - 1;
		}
		else if (key > Array[mid])
		{//将查找范围缩小到中间元素的右边
			left = mid + 1;
		}
		else
			return mid;    		//查找成功，返回该元素所在位置
	}
	return -1;            		//查找不成功，返回-1
}



int main()
{
    int A[]={1,2,3,6,7,45};
    int m=BiSearch(A,2,6);

    cout << "查找的数字在"<<m<<"处"<< endl;
    return 0;
}
