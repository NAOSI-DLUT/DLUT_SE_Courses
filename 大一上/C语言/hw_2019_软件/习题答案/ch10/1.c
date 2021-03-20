#include<stdio.h>
int square(int x)
{
	
	int num;
	num=x*x;
	return num;
    
}
int main()
{
	int i;
	for(i=1;i<=10;i++)
		printf("%8d",square(i));

return 0;

}

