/*初学者做题模板*/
/*筛法素数*/
#include<stdio.h>
int main()
{
    /*准备数据空间*/
    int i,j,number=0,a[101];
    /*获取数据*/
    for(i=1;i<=100;i++)
		a[i]=i;
	/*筛法计算*/
    for(i=2;i<=50;i++)
		if(a[i]!=0)
			for(j=2;i*j<=100;j++)
			    a[i*j]=0;
    /*输出数据*/
    printf("输出素数：\n");
    for(i=2;i<=100;i++)
	{
	    if(a[i]!=0)
		{
			printf("%4d",a[i]);
            number++;
		    if(number%5==0)
			    printf("\n");
		}
	}
    return 0;
}