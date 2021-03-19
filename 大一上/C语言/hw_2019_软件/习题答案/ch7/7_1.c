 /* 7_1
   从键盘输入三个整数，按从小到大的顺序输出*/
#include<stdio.h>
void main()
{
     int a,b,c,t ;
     scanf("%d,%d,%d",&a,&b,&c);
	 
	 if(a>b)
	{   /* 实现a和b的互换 */
		t=a;
		a=b;
		b=t;
	}  
    
	if(a>c)
    {  /* 实现a和c的互换 */
		t=a;
		a=c;
		c=t;
	}      
   
    if(b>c)
   {   /* 实现b和c的互换 */
		t=b;
		b=c;
		c=t;
    }     
   printf("%d,%d,%d\n", a, b,c);

   /*方案2*/
	if( a < b )
	{    
		if  ( b < c )
			printf("%d,%d,%d\n", a, b,c);
    else  if  ( a< c )  
			printf("%d,%d,%d\n", a, c,b);
    else 
			printf("%d,%d,%d\n", c, a,b);
	}
	// a>=b
   else if  ( a < c )  
        printf("%d,%d,%d\n",  b,a,c); 
   else  if  ( b < c )  
		printf("%d,%d,%d\n",  b,c,a);
   else  
	    printf("%d,%d,%d\n", c,b,a );
     
}