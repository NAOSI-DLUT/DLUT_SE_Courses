#include<stdio.h>
int isPerfectnum(n)
{
	int i,temp,sum=0;
	for(i=1;i<n;i++)
	{
		temp=n%i;
		if(temp==0)
			sum=sum+i;
	
	}
	if(sum==n)
		printf("%4d",n);
	return 0;


}
int main()
{
	int n;
	for(n=1;n<=1000;n++)
		isPerfectnum(n);
	return 0;


}