/*
Question2:

Compute combinatorial number C(n, m)
You are required to input n and m (n>m) and output combinatorial number
*/

#include<stdio.h>

int factorial(int num){
	int i,result=1;
	for (i = num; i >= 1; i--){
		result = result * i;
	}
	return result;
}

double combinatorial_number(int n, int m){
	return factorial(n) / (factorial(m)*factorial(n - m));
}

int main(){
	int n, m;
	printf("Please input n and m :");
	scanf("%d%d", &n, &m);
	printf("The combinatorial number of n and m is : %lf\n", combinatorial_number(n, m));
	return 0;
}
