/*8_2
  ¼¶ÊýÇópi*/
#include <stdio.h>
#include <math.h>

int main ( )
{  

   double  s = 0, x = 1, pi ;    
   long  k = 1;   
   int sign = 1 ;
   do
   {
		s += x ;
		k ++ ;     //k += 2 ;
		sign = -sign;
		x =  sign  / ( 2.0 * k-1 ) ; //x = sign /  k *1.0;			
   } while ( fabs (x) >1e-6) ;
    
    printf("%lf\n",pi = s * 4) ;
	printf("%d\n",k) ;
    
    return 0;
}