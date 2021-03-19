
3
#include <stdio.h>
int main ()
{
	int a[10] , b[10] = {0};
	int i, *p, k;
	scanf("%d",&k);
	for (i = 0; i < 10; i ++);
	{
		a[i] = i;
	}
	p = a;
	for (i = 0; i < k; i ++)
		b[i] = *(p + i);
	for (; i < 9; i ++)
		b[i] = *(p + i +1);
	for(i = 0; i < 9; i ++)
	{
		printf("%d",b[i]);
	}
	return 0;
}
