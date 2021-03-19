/*6_8
 编写程序预测断电后冰箱的温度。
 程序提示用户输入时间，它以整数小时和分钟表示，
 需要将其转换为浮点型的小时数。输出此时的温度值（小数点后2位有效数字）。
 */
#include<stdio.h>

int main()
{     
	 int iHour, iMinute, iSecond ;
	 double dTime,dTempreature;
	 printf( "断电时间（时,分,秒\n") ;     
     scanf("%d,%d,%d",&iHour,&iMinute ,&iSecond );
	 dTime =  iHour+iMinute/60.0 + iSecond/3600.0;

	 dTempreature = 4*dTime*dTime/(dTime+2)-20;
	 if( dTempreature>30)  /*假设室温为30度*/
		dTempreature=30;
	 printf("冰箱温度为:%.2f\n",dTempreature);

	return 0;
}

