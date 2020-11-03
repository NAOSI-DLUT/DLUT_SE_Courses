#include<stdio.h>
int main(){
	float f,c;
	printf("Input the Fahrenheit temperaturs:\n");
	scanf("%f", &f);
	c=5*(f-32)/9;
	printf("The Celsius temperature is: %.4f\n", c);
	return 0;
}
