//输出N ~ M之间的所有素数
# include < stdio.h >
# include< math.h >

void  main ()
{  
	int  N=10, M  =20, m, k = 0 ,i=0;
    double  sqrtm; 
    for ( m = N;  m <= M ;   m++ )
    {  
	 sqrtm = sqrt ( m ) ;
        for (   i = 2 ;   i <= sqrtm ;   i ++  )
        {
			if  ( m % i  == 0 )  
				break  ;
		}/* end of for2*/
         
		if  ( i > sqrtm )
        {  
			 printf("%d\t",m);
              k ++ ;
               if  (  k % 10 == 0 )  
				   printf("\n");/* 每行输出10个数据*/
		} // end of if
    } /* end of for1*/
   printf("\n%d primes in total\n",k);
} /* end of main*/
