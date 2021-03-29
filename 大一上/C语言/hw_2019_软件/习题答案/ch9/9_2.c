#include<stdio.h>
int main()
{
   int a[5]={1,3,5,8,10},b[5]={2,4,6,7,9},i,j,k,c[10];
   k=0;
   for(i=0,j=0;i<5&&j<5;)
	   if(a[i]<=b[j])
		   c[k++]=a[i++];
	   else
	       c[k++]=b[j++];
   if(i==5)/*a中元素空了*/
	   for(;j<5;)
		   c[k++]=b[j++];
   else   /*b中元素空了*/
	   for(;i<5;)
		   c[k++]=a[i++];
   for(i=0;i<10;i++)
     printf("%d  ", c[i]);
   return 0;
}