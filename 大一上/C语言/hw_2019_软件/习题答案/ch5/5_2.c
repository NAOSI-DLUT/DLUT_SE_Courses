/*5.2
编写程序求圆柱体底面周长、圆柱体的表面积和体积。
要求输入圆柱的底面直径和高，输出计算结果，取小数点后2位数字。
*/
#include<stdio.h>
#define PI 3.1415926
int main()
{
	double dDiameter,dHeight;			/*直径，高*/
	double dCircleGirth ,dCircleArea ;	/*圆周长，面积*/
    double fColumnArea = 0;			    /*圆柱表面积*/
	
	/*输入数据*/
	printf("请输入圆柱体底面半径和高：");
	scanf("%lf %lf",&dDiameter,&dHeight);
	
	/*计算各量*/
	dCircleGirth = 2 * PI * (dDiameter/2);			
	dCircleArea = PI * (dDiameter/2) * (dDiameter/2);
	fColumnArea = 2 * dCircleArea + dCircleGirth * dHeight;
	
	/*输出结果*/
	printf("圆柱体表底面周长为%.2f\n",dCircleGirth);
	printf("圆柱体表面积为%.2f\n",fColumnArea);
	printf("圆柱体体积为%.2f\n",dCircleArea * dHeight);

}
