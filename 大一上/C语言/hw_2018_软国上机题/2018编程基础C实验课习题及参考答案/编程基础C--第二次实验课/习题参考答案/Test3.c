#include<stdio.h>
#include<stdlib.h>

int main(){
	int length, width, height;
	int perimeter, surface, volume;
	printf("Please input the length, width, height of a cuboid in the format of l,w,h :");
	scanf("%d,%d,%d", &length, &width, &height);

	perimeter = (length + width + height) * 4;
	surface = (length * width + width * height + length * height) * 2;
	volume = length * width * height;

	printf("The perimeter of the cuboid is %d\n", perimeter);
	printf("The surface of the cuboid is %d\n", surface);
	printf("The volume of the cuboid is %d\n", volume);

	system("pause");
	return 0;

}