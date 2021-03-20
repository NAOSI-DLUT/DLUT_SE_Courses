/*8_5
有一分数序列：2/1，3/2，5/3，8/5，13/8，21/13
求出这个数列的前20项之和。*/
#include <stdio.h>
int main()
{
	float f1=1,f2=2,s1=2,s2=3,i=1,s=0;
	while(i<=10)
		{
			s=s+s1/f1+s2/f2;
			f1=f1+f2;
			f2=f2+f1;
			s1=s1+s2;
			s2=s1+s2;
			i++;
		}
	printf("%f",s);
	return(0);
}