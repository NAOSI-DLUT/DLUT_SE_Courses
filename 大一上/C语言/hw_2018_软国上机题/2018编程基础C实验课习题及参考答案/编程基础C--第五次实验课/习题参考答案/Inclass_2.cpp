#include<cstdio>
#include<iostream>
int main()
{
	int a[20]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,21};
	int b[20][2];
	int i,j,k;
	for(j=0;j<20;j++)
	{
		for(k=0;k<2;k++)
			b[j][k]=-1;	
	}
	j=0;k=0;
	for(i=0;i<20;i++)
	{
		if(a[i]%2==0)
			b[j++][0]=a[i];
		else
			b[k++][1]=a[i];
	}	
	for(i=0;i<20;i++)
	{
		for(j=0;j<2;j++)
		{
			if(b[i][j]!=-1)
				printf("%3d",b[i][j]);
			else
				printf("%3c",' ');
		}
		printf("\n");
	}
	system("pause");
	return 0;
}
