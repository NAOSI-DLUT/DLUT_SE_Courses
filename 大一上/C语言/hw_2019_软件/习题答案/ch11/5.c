
5
#include <stdio.h>
float sum (float(*p)[3])
{
	float fsum = 0 ;
	int i;
	for (i = 0; i < 3; i ++)
		fsum += *(*p+i);
	return fsum;
}
int  main ()
{
	float a[10][3] = {0};
	int i;
	float (*p)[3];
	float b[10];
	p = a;
	for (i = 0; i < 10; i ++,p++)
	{
		b[i] = sum(p);
	}
	for (i = 0; i <10; i ++)
		printf("第%d行总成绩   %.2f\n",i,b[i]);
	return 0;
}
