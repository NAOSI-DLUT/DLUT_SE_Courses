/*6_7
 输入三角形的三边长，计算其中最大角的三角函数
 */
#include<stdio.h>
#include<math.h>
int main()
{     
	  
	 float fa, fb,fc,fSin, fCos, fMax;
	 printf( "输入三条边\n") ;     
     scanf("%f%f%f",&fa,&fb ,&fc );
	 fMax = (fa>fb)?fa:fb;
	 fMax = (fMax>fc)?fMax:fc;
	 if(fMax>=fa+fb+fc-fMax)
	 {
		 printf("Error\n");
		 return 1;
	 }
     fCos = (fa*fa + fb*fb +fc*fc - 2*fMax*fMax)*fMax/(2*fa*fb*fc);
	 printf("cos=:%.2f\n",fCos );
     printf("sin=:%.2f\n",sqrt(1- fCos* fCos));
	return 0;
}

