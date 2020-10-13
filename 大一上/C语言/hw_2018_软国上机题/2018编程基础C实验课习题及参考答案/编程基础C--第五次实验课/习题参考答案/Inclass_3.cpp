#include<cstdio>
#include<iostream>
int main()
{
	double a[5][3];
	int i,j;
	double avgst[5],avgsu[3];
	double sum=0,temp=0;
	for(i=0;i<5;i++)
		for(j=0;j<3;j++)
			scanf("%lf",&a[i][j]);
	for(i=0;i<5;i++)
	{
		for(j=0;j<3;j++)
		{
			sum=sum+a[i][j];
		}
		avgst[i]=sum/3;
		sum=0;
	}
	for(i=0;i<5;i++)
	{
		for(j=0;i+j<4;j++)
		{
			if(avgst[j]<avgst[j+1])
			{
				temp=avgst[j];
				avgst[j]=avgst[j+1];
				avgst[j+1]=temp;
			}
		}
	}

	for(j=0;j<3;j++)
	{
		for(i=0;i<5;i++)
		{
			sum=sum+a[i][j];
		}
		avgsu[j]=sum/5;
		sum=0;
	}
	for(i=0;i<3;i++)
	{
		for(j=0;i+j<2;j++)
		{
			if(avgsu[j]>avgsu[j+1])
			{
				temp=avgsu[j];
				avgsu[j]=avgsu[j+1];
				avgsu[j+1]=temp;
			}
		}
	}
	printf("每个人平均成绩的降序输出为：");
	for(i=0;i<5;i++)
	{
		printf("%.1lf ",avgst[i]);
	}
	printf("\n");
	printf("每门课平均成绩的升序输出为：");
	for(i=0;i<3;i++)
	{
		printf("%.1lf ",avgsu[i]);
	}
	system("pause");
	return 0;
}
