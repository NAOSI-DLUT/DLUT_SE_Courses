#include <iostream>

using namespace std;

template <class T>
//顺序查找过程，Array[]为待查找的数据记录集合，n为集合的记录个数，key为要查找的数据记录
int Search(T Array[], T key,int n)
{
	for (int index = 0; index < n; index ++)
	{//从数组起始位置遍历数组，n表示数组长度
		if( Array[index] == key)//如果数组元素等于待查找关键字
		{
			return index;      	//查找成功，返回该数组元素所在的位置
		}
	}
	return -1;                   	//查找不成功，返回-1
}


int main()
{
    int A[]={1,2,3,45,6,7};
    int m=Search(A,8,6);

    cout << "查找的数字在"<<m<<"处"<< endl;
    return 0;
}
