#include<stdio.h>
#include<math.h>
double f(double a,double b,double c,double d,double x)
{
	double n;
	n=x*a*x*x+b*x*x+c*x+d;
	return n;
		


}
double f1(double a,double b,double c,double d,double x)
{
	double m;

    m=3*a*x*x+2*b*x+c;
	return m;



}
int main()
{
	double a,b,c,d,x,x1=1;
	printf("ÊäÈëa,b,c,d:");
	scanf("%lf,%lf,%lf,%lf",&a,&b,&c,&d);
	while(fabs(x1-x)>=1e-6)
	{
		x=x1;
		x1=x-f(a,b,c,d,x)/f1(a,b,c,d,x);
	}
	printf("%lf\n",x1);
	return 0;


}