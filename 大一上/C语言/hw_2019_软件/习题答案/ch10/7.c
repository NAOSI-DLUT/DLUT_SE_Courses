#include<stdio.h>
int fact(int array[],int n)
{
	int m;
	if(n>1)
	{
		m=array[n]+fact(array,n-1);
		return m;
	}
	else
	return array[n];

 
}
int main()
{
	int array[11],m,i;
	for(i=1;i<11;i++)
		scanf("%d",&array[i]);
	m=fact(array,10);
	printf("%d\n",m);
	return 0;
}