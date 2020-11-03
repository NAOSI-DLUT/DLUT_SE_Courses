#include<stdio.h>
int main(){
	int d, h;
	float pi=3.1415;
	printf("Input the diameter:\n");
	scanf("%d", &d);
	printf("Input the height:\n");
	scanf("%d", &h);
	float r=d/2.0;
	float circumference=pi*d;
	float surface_area=pi*d*h;
	float volume=pi*r*r*h;
	printf("circumference: %.2f:\n", circumference);
	printf("surface area: %.2f:\n", surface_area);
	printf("volume: %.2f:\n", volume);
	
	
	return 0;
}
