/*8_3
 分别用穷举法和迭代发求两个整数的最大公约数。
输 入两个正整数m和n，编程求它们的最大公约数。*/
#include <stdio.h>
int main()
{ 
   int m , n , i, min;
   int a , b , r ;
   printf("input two integers :" );	
   scanf( "%d%d", &m, &n);
  
  /*穷举法-最大公约数*/
	min =(m<n)?m:n;

   for( i = min; i>1 ; i-- )
	   if( m%i==0 && n%i==0 ) break;
   printf( "Greatest common divisor is %d \n", i) ;
	
 
   /*辗转相除法*/
   r = a % b ;	/*余数*/
   
  while ( r != 0 )
  {	
     a = b ;			
     b = r ; 
	 r = a % b ;	
  }
  printf( "Greatest common divisor is %d \n", i) ;

   return 0;
}