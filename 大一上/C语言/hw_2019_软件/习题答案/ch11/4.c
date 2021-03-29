
4
#include <stdio.h>
#include <stdlib.h>
int main ()
{
	unsigned int a, i;
	int a1, a2, a3;
	float ave;
	float *p;
	printf("输入人数\n");
	scanf("%d",&a);
	p = (float*)malloc(a*sizeof(float));
	for (i = 0, ave = 0; i < a; i ++)
	{
		printf("输入第%d个人的成绩\n",i);
		scanf("%d%d%d",&a1,&a2,&a3);
		ave = (float)((a1 + a2 + a3)/3.0);
		p[i] = ave;
	}
	for (i = 0; i < a; i ++)
		printf("第%d个人的成绩%f",p[i]);
	return 0;
}
