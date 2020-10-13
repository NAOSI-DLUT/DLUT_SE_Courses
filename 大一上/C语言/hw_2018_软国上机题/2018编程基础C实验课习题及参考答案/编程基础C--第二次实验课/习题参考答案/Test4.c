#include<stdio.h>
#include<stdlib.h>

int main(){
	int in_distance, out_distance;
	int in_h, in_m, in_s, out_h, out_m, out_s;

	double converted_time_in, converted_time_out;
	
	int relative_distance;
	double relative_time;

	printf("Please input the distance of in and out in the format of in,out : ");
	scanf("%d,%d", &in_distance, &out_distance);

	printf("Please input the time of in in the format of hour:minute:second : ");
	scanf("%d:%d:%d", &in_h, &in_m, &in_s);

	printf("Please input the time of out in the format of hour:minute:second : ");
	scanf("%d:%d:%d", &out_h, &out_m, &out_s);

	converted_time_in = (in_h * 3600 + in_m * 60 + in_s) / 3600.0;
	converted_time_out = (out_h * 3600 + out_m * 60 + out_s) / 3600.0;

	relative_distance = out_distance - in_distance;
	relative_time = converted_time_out - converted_time_in;

	printf("The average speed of the car is : %.2lf", relative_distance / relative_time);

	system("pause");

	return 0;
}