/*6_3
 输入三个小数，判断并输出其中的最大值和最小值。
 */
#include<stdio.h>
 
int main()
{     
	  
	 float fa, fb,fc,fMin, fMax;
	 printf(" 输入三个小数\n") ;     
     scanf("%f%f%f",&fa,&fb ,&fc );
	 fMax = (fa>fb)?fa:fb;
	 fMax = (fMax>fc)?fMax:fc;
	 fMin = (fa<fb)?fa:fb;
	 fMin = (fMin<fc)?fMin:fc;
     
	 printf("min=:%.2f\n",fMin  );
     printf("max=:%.2f\n",fMax );
	return 0;
}

