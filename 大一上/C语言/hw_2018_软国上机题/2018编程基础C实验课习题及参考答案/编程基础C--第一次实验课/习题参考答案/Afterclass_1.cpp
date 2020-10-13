#include <stdio.h>
#include<stdlib.h>
#include <math.h>

int convertOct2Dec(int octNum);
int convertHex2Dec(char hex[3]);
/*
int main(){
	int targetNum = 152;
	char *hexNum = "6A";
	double result1 = convertOct2Dec(targetNum);
	double result2 = convertHex2Dec(hexNum);

	printf("Oct to Dec : %f\n", result1);
	printf("Hex to Dec : %f\n", result2);

	system("pause");
}
*/

int convertOct2Dec(int octNum){
	double pos_1 = octNum % 10;
	double pos_2 = (octNum / 10) % 10;
	double pos_3 = octNum / 100;

	double result = pos_3 * pow(8.0, 2) + pos_2 * pow(8.0, 1) + pos_1 * pow(8.0, 0);

	return result;
}

int convertHex2Dec(char *hex){
	int i;
	double result = 0.0;
	double temp;
	for (i = 0; i < 2; i++){
		if (hex[i] >= 'A' && hex[i] <= 'F'){
			temp = int(hex[i] - 'A' + 10);
		}
		else{
			temp = int(hex[i]-'0');
		}
		result += (temp * pow(16.0, 1-i));
	}

	return result;
}

