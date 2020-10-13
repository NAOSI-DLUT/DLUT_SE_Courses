#include<stdio.h>
int main(){
	int a, b, c;
	printf("Input the first number:\n");
	scanf("%d", &a);
	printf("Input the second number:\n");
	scanf("%d", &b);
	printf("Input the third number:\n");
	scanf("%d", &c);
	int sum = a+b+c;
	int product = a*b*c;
	float average = (a+b+c)/3.0;
	printf("sum: %d\n", sum);
	printf("product: %d\n", product);
	printf("average: %.2f\n", average);
	return 0;
} 
