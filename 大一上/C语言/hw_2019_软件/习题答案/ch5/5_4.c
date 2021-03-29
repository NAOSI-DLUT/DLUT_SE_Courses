/*5.4
  输入一个小写字母，输出对应的大写字母。
*/
#include<stdio.h>
 
int main()
{
	char c;
 
	printf("请输入输入一个小写字母：");
	scanf("%c",&c);
    if(c>='a' &&c<='z')
	   printf("对应的大写字母为%c\n",c-32); 

}