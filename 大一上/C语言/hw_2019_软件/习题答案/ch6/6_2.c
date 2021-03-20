/*6_2
输入一个3位整数，将每位的数据进行分离，要求逆序输出对应的数，
即分别按照字符型输出个位、十位、百位上的整数。
*/
#include <stdio.h>

int main()
{
	int iNum;  /*3位数据*/	 
    char c3, c2, c1;

	printf("请输入一个3位数：\n");		/*提示输入*/
	scanf("%d",&iNum) ;

	/*分离数据*/
    c3 = iNum/100+48;	/*百位*/ 
	c2 = iNum%100/10+48;		/*十位*/ 
	c1 = iNum%10+48;			/*个位*/ 
	printf("分离之后为%c%c%c\n",c1, c2, c3); 
	return 0;
}