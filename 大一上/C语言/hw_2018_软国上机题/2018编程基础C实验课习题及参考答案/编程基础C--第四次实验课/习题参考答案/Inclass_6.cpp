#include <stdio.h>
#include <math.h>
int main()
{
    double e1 =0,e2 = 1;
    double e1_tmp=0, e2_tmp=0;
    int n=0;
    do{
        e1_tmp=e1;
        n++;
        e1 = e1+pow(-1, n-1)/(2*n-1);
    }while(fabs(e1_tmp-e1)>pow(10, -6));
    
    n=0;
    do{
        e2_tmp=e2;
        n++;
        e2 = e2*(2*n*2*n)/((2*n-1)*(2*n+1));
    }while (fabs(e2_tmp-e2)>pow(10, -6)) ;
    
    printf("e=%.7f\ne=%.7f\n",e1*4,e2*2);
    return 0;
}
