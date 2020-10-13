#include<cstdio>
#include<iostream>
#define M 12

int main()
{
	int a[M];
	int i,j,k,length;
	printf("ÇëÊäÈëÊı×éa[%d]\n",M);
	for(i=0;i<M;i++)
	{
		scanf("%d",&a[i]);
	}
	length=M;
	for(i=0;i<length-1;i++)
	{
		for(j=i+1;j<length;)
		{
			if(a[j]==a[i])
			{
				for(;j<length-1;j++)
				{
					a[j]=a[j+1];
				}
				length--;
				j=i+1;
			}
			else
				j++;
		}
	}
	for(k=0;k<length;k++)
	{
		printf("%3d",a[k]);
	}

	return 0;
}
