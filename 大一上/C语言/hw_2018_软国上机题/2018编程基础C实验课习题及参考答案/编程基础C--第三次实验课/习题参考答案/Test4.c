#include<stdio.h>

int Test2(){
	int type;
	while (1){
		char input;
		printf("please input a charactor:\n");
		input = getchar();
		getchar();

		if (48 <= input && input <= 57){
			type = 0;
		}
		else if (90 >= input && input >= 65){
			type = 1;
		}
		else if (122 >= input && input >= 97){
			type = 2;
		}
		else{
			type = 3;
		}

		if (type == 0){
			printf("The charactor you input is a Number charactor\n");
		}
		if (type == 1){
			printf("The charactor you input is a Capital charactor\n");
		}
		if (type == 2){
			printf("The charactor you input is a Lowercase charactor\n");
		}
		if (type == 3){
			printf("The charactor you input is an Extra charactor\n");
		}
	}

	system("pause");
	return 0;
}

int main(){
	Test2();
}