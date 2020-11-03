#include <stdio.h>

int main()
{
    double e =1;
    int i=0;
    int j=0;
    int n=1;
    for(i =1;i<20;i++){
        for(j=1;j<=i;j++){
            n = n*j;
        }
        e = e+(double)1/n;
        n=1;
    }
    printf("e=%.10f",e);
    return 0;
}
