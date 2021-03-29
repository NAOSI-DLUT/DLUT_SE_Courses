#include<stdio.h>
#define N 100
int main()
{
    int  a[10]={1,2,3,4,5,6,7,8,9,10};
	int i,temp;
	for(i=0;i<10/2;i++)
	{
		temp=a[i];
		a[i]=a[9-i];
		a[9-i]=temp;
	}
    for(i=0;i<10;i++)
		printf("%d ",a[i]);
    return 0;
}
 