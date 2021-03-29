#include<stdio.h>
#define N 8
int main()
{
    int  a[N]={3,2,-6,4,7,-3,5,-2},i,j;
    int sum;/*当前位置的和*/  
    int max;/*目前为止最大的子数组和*/  
    int left,right;/*子数组的位置*/  
    int t1;/*子数组的临时左位置*/  
    /*初始化*/  
    sum=max=a[0];  
    left=right=t1=0;  
    for(i=1;i<N;i++)
	{  
        sum+=a[i];            
        if(sum<0)
		{  
             sum=0;/*如果和为负了，就应该重新计算*/  
             t1=i+1;/*t1也从下一个位置开始*/  
             continue;  
        }  
        if(sum>max)
		{/*如果当前和比原先的最大值还大*/  
           max=sum;/*最大值等于当前值  */
           left=t1;/*左右区间也要调成相应的*/  
           right=i;  
        }  
    }  
    for(i=left;i<=right;i++)  
       printf("%d ",a[i]);  
    return 0;
}
 