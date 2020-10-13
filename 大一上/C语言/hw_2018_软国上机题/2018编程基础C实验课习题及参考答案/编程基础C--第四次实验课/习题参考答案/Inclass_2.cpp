#include <stdio.h>
#include <math.h>
//课本第10题
int main()
{
    int n, res;
    
    printf("Input a positive number less than (100000) : ");
    scanf("%d", &n);
    
    if ( n <= 0 || n > 100000 )
    {
        printf("Input a positive number less than (100000)\n");
        return 1;
    }
    
    res = 0;
    do
    {
        res += n % 10;
        n = n / 10;
        
    }while(n);
    
    printf("res = %d\n", res);
    
    return 0;
}
