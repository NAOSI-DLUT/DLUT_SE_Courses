/*7-6．
   设计一个程序，推断三角形的类别和面积。
*/
#include <stdio.h>
#include <math.h>
int main() 
{
     float fa, fb,fc,fArea,fs,ft;
	printf( "输入三条边\n") ;     
     scanf("%f%f%f",&fa,&fb ,&fc );
	 if(fa<fb)
	{   ft=fa;	fa=fb;	fb=ft;	}  
    
	if(fa<fc)
    {  	ft=fa;	fa=fc;	fc=ft;	}      
   
    if(fb<fc)
   {   	ft=fb;	fb=fc;	fc=ft;    }  
	
	printf("%f,%f,%f\n", fa, fb,fc);

	if(fa==fb && fb==fc)
	{
		printf("等边三角形");
		fArea = sqrt(3)*fa*fa/2;
	}
	else if( fa*fa==fb*fb+fc*fc)
	{
		printf("直角三角形");
		fArea = fb*fc/2;
	}
	else
	{
		printf("其他字符三角形");
		fs = (fa+fb+fc)/2;
	   fArea = sqrt((fs)*(fs-fa)*(fs-fb)*(fs-fc));
	}
	printf("\n面积为%f\n",fArea);
	return 0;
}