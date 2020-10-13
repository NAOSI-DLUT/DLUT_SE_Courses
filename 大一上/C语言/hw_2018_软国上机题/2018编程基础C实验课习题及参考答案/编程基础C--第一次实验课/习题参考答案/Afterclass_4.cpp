#include <stdio.h>
#include <stdlib.h>

int main(){
	short num1 = -32768;
	short num2 = num1 - 2;
	printf("Directly output s - 2 : %d\n", num1 - 2);
	printf("Output s = s - 2 : %d\n", num2);
	system("pause");
	return 0;
}