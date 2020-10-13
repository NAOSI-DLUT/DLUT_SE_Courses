/*
question1:

design a recursive function to satisfy following requirement:

input: an integer
output: a binary number
*/


#include<stdio.h>

void integer_to_binary(int number){
	if (number > 0){
		integer_to_binary(number / 2);
	}
	if(number>0)
		printf("%d", number % 2);
}

int main(){
	int integer;
	printf("please input an integer number :");
	scanf("%d", &integer);
	printf("transforming integer number into binary number ......\n");
	printf("integer number:%d\n", integer);
	printf("binary number:");
	integer_to_binary(integer);
	printf("\n");
	return 0;
}
