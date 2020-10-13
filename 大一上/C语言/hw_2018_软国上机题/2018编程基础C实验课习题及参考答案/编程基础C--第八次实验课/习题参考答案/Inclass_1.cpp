#include<stdio.h>

float add(float (*p)[3], int n)
{
	
	float sum=0;
	int i;
	for(i=0;i<3;i++)
	{
		sum+=p[n][i];		
	}
	return sum;
}
int main()
{
	float score[][3]={{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},};
	int i,j;
	float b=80;
	for(i=0;i<10;i++)
	{
		for(j=0;j<3;j++)
		{
			score[i][j]=b;
			b=b+0.5;
			printf("%.1f ",score[i][j]);
		}
		printf("\n");
	}
	for(i=0;i<10;i++)
	{
		printf("第%d个学生的总成绩是%.1f:\n",i+1,add(score,i));
	}
	return 0;
}
