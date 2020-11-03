#include<stdio.h>
int main(){
	char lower, upper;
	printf("Input lowercase:\n");
	scanf("%c", &lower);
	upper=lower-32;
	printf("The corresponding uppercase letter is: %c", upper); 
	return 0;
}
