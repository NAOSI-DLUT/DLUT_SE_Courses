#include <stdio.h>
int main()
{
	float fHemline,fHigh,fArea;  /*底，高，面积*/	 
    printf("请输底和高：\n");		/*提示输入*/
	scanf("%f%f",&fHemline,&fHigh) ;
	fArea=fHemline*fHigh/2; 
	printf("面积为：%f\n",fArea); 
	return 0;
}