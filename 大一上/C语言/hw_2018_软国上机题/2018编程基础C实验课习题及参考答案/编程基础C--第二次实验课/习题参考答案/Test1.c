#include<stdio.h>

int Test1(){
	double a, b, c;
	double max, min;
	printf("Please input three numbers:\n");
	scanf("%lf%lf%lf", &a, &b, &c);

	max = a;
	min = a;

	if (b > max){
		max = b;
	}
	if (c > max){
		max = c;
	}
	if (b < min){
		min = b;
	}
	if (c < min){
		min = c;
	}

	printf("Max numbur : %lf, Min mumber : %lf\n", max, min);
	return 0;
}

main(){
	Test1();
}