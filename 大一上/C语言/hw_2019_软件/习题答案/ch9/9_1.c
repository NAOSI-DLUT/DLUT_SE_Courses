#include<stdio.h>
int main()
{
   int a[10],i,sum=0;
   float aver;
   /*输入元素*/
   for(i=0;i<10;i++)
	   scanf("%d",&a[i]);
   /*计算平均值*/
   for(i=0;i<10;i++)
	   sum=sum+a[i];
   aver=sum/10.0;
   /*计算个数*/
   sum=0;
   for(i=0;i<10;i++)
	   if(a[i]>=aver)
		   sum++;
   printf("sum = %d", sum);
   return 0;
}