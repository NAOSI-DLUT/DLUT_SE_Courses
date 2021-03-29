#include<stdio.h>
int main()
{
	int number;
	void smart(int n);
	printf("input a number\n");
	scanf("%d",&number);
	smart (number);
	return 0;
}
void smart(int n)
{
    if(n == 1 || n == 0)
		printf("%d",n);
	else
	{
		smart(n / 2);
		printf("%d",n%2);
	}
}