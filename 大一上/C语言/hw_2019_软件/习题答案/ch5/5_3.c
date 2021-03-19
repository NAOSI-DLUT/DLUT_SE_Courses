/*5.3
编写程序实现华氏温度和摄氏温度的转换。输入一个华氏温度F，要求输出摄氏温度C。
输出结果要有文字说明，取小数点后4位数字。转换公式为：c=5×（F-32）/9 
*/
#include<stdio.h>
 
int main()
{
	float dCentigrade,dFahrenheit;/*摄氏温度，华氏温度*/	
 
	printf("请输入华氏温度F：");
	scanf("%f",&dFahrenheit);
	
	dCentigrade = 5*(dFahrenheit-32)/9;

	printf("摄氏温度为%.4f\n",dCentigrade);
 

}
