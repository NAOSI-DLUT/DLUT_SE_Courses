#include<stdio.h>
int square(int x){
	return x*x;
}
int main(){
	int i=1;
	for(i=1;i<=10;i++){
		printf("%d\t", square(i));
	}
	return 0;
} 
