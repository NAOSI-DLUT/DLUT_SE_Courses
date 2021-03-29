#include<stdio.h>
int leap(int year)
{
  if(year%400==0 || year%4==0 && year%100!=0)
	  return 1;
  else 
	  return 0;
}

int main()
{
	int d[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
	int year,month,day,i,sum=0;
	scanf("%d%d%d",&year,&month,&day);
	for(i=1;i<month;i++)
       sum=sum+ d[i];
	sum=sum+day+(month>2?leap(year):0);
	printf("%d",sum);
	return 0;
}