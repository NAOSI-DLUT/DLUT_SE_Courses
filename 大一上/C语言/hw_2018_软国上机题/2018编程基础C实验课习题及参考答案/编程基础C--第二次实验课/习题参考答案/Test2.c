#include<stdio.h>
#include<stdlib.h>

int Test3(){
	int hour, minute;
	float time, temperature;

	//注意输入的格式！！
	printf("Please input the time(hour:minute):\n");
	scanf("%d:%d", &hour, &minute);

	time = hour + minute / 60.0;

	temperature = (4 * time * time) / (time + 2) - 20;

	printf("Temperature:%.2f\n", temperature);
	system("pause");
}

int main(){
	Test3();
}