#include<stdio.h>
int isPerfectnum(int x){
	int i=1,sum=0;
	for(i=1;i<x;i++){
		if(x%i==0)
			sum+=i;
	}
	if(sum==x)
		return 1;
	else
		return 0;
}
int main(){
	int i=1;
	for(i=1;i<=1000;i++){
		if(isPerfectnum(i)){
			printf("%d\t", i);
		}
	}
	return 0;
}
