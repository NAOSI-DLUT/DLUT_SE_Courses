#include<stdio.h>
int a[4][5];
int put(int b[],int n)
{
	int i,p=0;
	for(i=0;i<n;i++)
		if(b[i]<60)
			p=p+1;
		return p;


}
float f(int i,int j)
{
	int p;
	float q;
	for(i=0;i<4;i++)
		for(j=0;j<5;j++)
		{
		if(a[i][j]>60)
			p=p+1;
		q=(float)p/4;
		}
		return q;




}




int main()
{
	int i,j,p,b[5][4];
	float n;
	for(i=0;i<4;i++)
		for(j=0;j<5;j++)
			scanf("%d",&a[i][j]);
	for(j=0;j<4;j++)
		for(i=0;i<5;i++)
			b[j][i]=a[i][j];
	for(j=0;j<5;j++)
	{
		p=put(b,5);
		printf("不及格课程数：%4d\n",p);
	}
	for(i=0;i<4;i++)
	{
		n=f(i,j);
     	printf("课程及格率：%4f\n",n);
	}
	
	for(i=0;i<4;i++)
	{
		printf("\n");
		
	
	

		for(j=0;j<5;j++)
			printf("%4d",a[i][j]);
	}
	
	return 0;


}