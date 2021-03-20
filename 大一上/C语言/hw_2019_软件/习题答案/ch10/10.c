#include<stdio.h>
int f(int n)
{
	int p;
	if(n>0)
		p=n*f(n-1);
	else
		p=1;
	return p;


}
int main()
{
	int m,n,p,q,r;
	float t;
	scanf("%d,%d",&n,&m);
	p=f(m);
	q=f(n);
	r=f(n-m);
	t=(float)q/(p*r);
	printf("%f",t);


}