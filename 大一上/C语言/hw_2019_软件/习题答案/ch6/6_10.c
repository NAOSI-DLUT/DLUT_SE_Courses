#include<stdio.h>

int main()
{     
	 float total,pay,unit,bonus;/*总收入、基本工资、提成、奖金*/
	 int number;  /*台数*/
	 printf("输入基本工资：");
	 scanf("%f",&pay);
	 printf("\n输入销售台数：");
	 scanf("%d",&number);
     total=pay+1000*number+(10800*number>100000?10800*number*0.02:0);
     printf("\n工资总额为：%f",total);
	 return 0;
}