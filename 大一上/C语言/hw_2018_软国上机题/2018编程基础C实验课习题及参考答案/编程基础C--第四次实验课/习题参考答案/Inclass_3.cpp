#include<stdio.h> 
int main(){
	int a=0, b=1, i=0, sum=0;
	int num = 0;
	for(i=1;i<=20;i++){
		if(num==0)
			printf("%d\t", a);
		else if(num==1)
			printf("%d\t", b);
		else if(num<20){
			sum=a+b;
			a=b;
			b=sum;
			printf("%d\t",b);
		}
		if(i%8==0)
			printf("\n");
		num++;
	}
	return 0;
}
