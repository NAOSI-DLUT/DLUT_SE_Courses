#include<stdio.h>
void prime(int n)
{
	int i,item;
	for(i=2;i<n;i++)
	{
		item=n%i;
		if(item==0)
			break;
	}
	if(i==n)
		printf("%4d",n);
	 


}
int main()
{
	int n;
	for(n=1;n<=200;n++)
		prime(n);
    return 0;


}