/*8_9
有1、2、3、4个数字，能组成多少个互不相同且无重复数字的三位数？都是多少？
*/
#include<stdio.h>
int main()
{
	int i,j,k,n;
	n=0;
	for(i=1;i<=4;i++)
	{
		for(j=1;j<=4;j++)
		{
			for(k=1;k<=4;k++)
			{
				if(k!=i&&k!=j&&j!=i)         //判断数据是否重复
				{
					printf("%d%d%d\n",i,j,k);
					n=n+1;					//计数器
				}
			}
		}
	}
	printf("sum=%d\n",n);
}
