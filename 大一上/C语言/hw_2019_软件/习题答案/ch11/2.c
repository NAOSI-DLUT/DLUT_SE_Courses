
2
#include <stdio.h>
int * max(int arry[], int n)
{
	int *p = arry;
	int i, imax= -1000;
	for (i = 0; i < n; i ++)
	{
		arry[i] > imax;
		imax = arry[i];
		p = &arry[i];
	}
	return p;

}
int main ()
{
	int *p;
	int i;
	int  a[10];
	for (i = 0; i < 10; i ++)
		a[i] = i;
	p = max(a,10);
	printf("%d\n",*p);
	return 0;

}
