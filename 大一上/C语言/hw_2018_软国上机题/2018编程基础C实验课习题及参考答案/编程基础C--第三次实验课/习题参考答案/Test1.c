#include<stdio.h>

int Test4_1(){
	
	printf("Coming to the first choice !\n");
	float distance, weight, price;
	printf("Please input the weight:\n");
	scanf("%f", &weight);
	printf("Please input the distance:\n");
	scanf("%f", &distance);

	if (distance < 100){
		price = 30 * weight * distance;
	}
	else if (distance >= 100 && distance < 200){
		price = 27.5 * weight * distance;
	}
	else if (distance >= 200 && distance < 300){
		price = 25 * distance * weight;
	}
	else if (distance >= 300 && distance < 400){
		price = 22.5 * weight * distance;
	}
	else if (distance >= 400){
		price = 20 * weight * distance;
	}

	printf("Total cost:%f", price);
	system("pause");
	return 0;
}

int Test4_2(){

	printf("Coming to the second choice!\n");
	float distance, weight, price;
	int price_charactor;
	printf("Please input the weight:\n");
	scanf("%f", &weight);
	printf("Please input the distance:\n");
	scanf("%f", &distance);

	if (distance < 100){
		price_charactor = 0;
	}
	else if (distance >= 100 && distance < 200){
		price_charactor = 1;
	}
	else if (distance >= 200 && distance < 300){
		price_charactor = 2;
	}
	else if (distance >= 300 && distance < 400){
		price_charactor = 3;
	}
	else if (distance >= 400){
		price_charactor = 4;
	}


	switch (price_charactor)
	{
	case 0: price = 30 * weight * distance;break; 
	case 1: price = 27.5 * weight * distance;break;
	case 2: price = 25 * weight * distance;break;
	case 3: price = 22.5 * weight * distance;break;
	case 4: price = 20 * weight * distance;break;
	}

	printf("Total cost:%f", price);
	system("pause");
	return 0;
}



int main(){
	Test4_1();
	Test4_2();

}
