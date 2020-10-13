#include<stdio.h>
int main(){
	int i = 0;
    int ret = 1;
    int sum = 0;
    int m;
    printf("Input m:\n");
    scanf("%d", &m);
    for (i = 1; i <= m; i++)
    {
        ret *= i;//ret=ret*i
        sum += ret;//sum=sum+ret
    }
    printf("sum = %d\n", sum);
    return 0;
}

