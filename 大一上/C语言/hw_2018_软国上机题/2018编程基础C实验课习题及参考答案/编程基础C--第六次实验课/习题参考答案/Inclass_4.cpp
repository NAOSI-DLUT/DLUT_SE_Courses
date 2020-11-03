#include<stdio.h>
int isPrime(int x){
	int i=2;
	if(x==1)
		return 0;
	for(i=2;i<x;i++){
		if(x%i==0)
			return 0;
	}
	return 1;
} 
int main(){
	int i=1;
	for(i=1;i<=200;i++){
		if(isPrime(i)){
			printf("%d\t", i);
		}
	}
	return 0;
}
