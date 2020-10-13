#include<cstdio>
#include<iostream>
#define M 5
#define N 5
int main()
{
	int a[M],b[N],c[M+N];
	int i,j,k;
	printf("请输入数组a[%d]\n",M);
	for(i=0;i<M;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("请输入数组b[%d]\n",N);
	for(j=0;j<N;j++)
	{
		scanf("%d",&b[j]);
	}
	i=0,j=0,k=0;
	while(i<M&&j<N)
	{
		if(a[i]<b[j])
		{
			c[k]=a[i];
			i++;
		}
		else
		{
			c[k]=b[j];
			j++;
		}

		k++;
	}
	while(i<M)
	{
		c[k]=a[i];
		i++;
		k++;
	}
	while(j<N)
	{
		c[k]=b[j];
		j++;
		k++;
	}
	for(k=0;k<M+N;k++)
	{
		printf("%3d",c[k]);
	}
	system("pause");
	return 0;
}
