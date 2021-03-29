#include<stdio.h>
#define N 12
int main()
{
    int  a[N]={1,1,2,7,3,2,3,4,5,8,7,4},i,j;
	for(i=0;i<N-1;i++)
	  if(a[i]!=-1)/*约定数据中不存在-1*/
         for(j=i+1;j<N;j++)
			 if(a[j]==a[i])
				 a[j]=-1;
	for(i=0;i<N;i++)
	  if(a[i]!=-1)
		printf("%d ",a[i]);
    return 0;
}
 