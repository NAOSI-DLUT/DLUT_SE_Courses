#include<cstdio>
#include<iostream>
int main()
{
	int a[10][10];
	int i,j;
	for(i=0;i<10;i++)
	{
		for(j=0;j<10;j++)
		{
			a[i][j]=-1;
		}
	}
	for(i=1;i<10;i++)
		a[i][0]=i;	
	for(j=1;j<10;j++)
		a[0][j]=j;
	for(i=1;i<10;i++)
	{
		for(j=1;j<=i;j++)
			a[i][j]=i*j;
	}
	for(i=0;i<10;i++)
	{
		for(j=0;j<10;j++)
		{
			if(a[i][j]!=-1)
				printf("%3d",a[i][j]);
			else
				printf("%3c",' ');
		}
		printf("\n");
	}

	system("pause");
	return 0;
}
