#include<stdio.h>
int prim(int m){
	if(m<2)
		return 0;
	int i=2;
	for(i=2;i<m;i++){
		if(m%i==0)
			return 0;
	}
	return 1;
}
int main(){
	int m,n,count=0,i,result;
	printf("Input m and n:\n");
	scanf("%d %d", &m, &n);
	for(i=m;i<=n;i++){
		result=prim(i);
		if(result==1){
			count++;
			printf("%4d", i);
			if(count%10==0)
				printf("\n");
		}
	}
	printf("\nNumber of prime numbers: %d", count);
	return 0;
}
