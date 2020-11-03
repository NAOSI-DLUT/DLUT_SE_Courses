#include<stdio.h>
#include<math.h>
float distance(float x1, float y1, float x2, float y2){
	return sqrt(pow((x1-x2),2) + pow((y1-y2),2));
}
int main(){
	float x1,x2,y1,y2;
	printf("Input x1,x2,y1,y2:\n");
	scanf("%f%f%f%f",&x1,&x2,&y1,&y2);
	printf("distance:%f", distance(x1,y1,x2,y2));
	return 0;
}
