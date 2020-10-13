#include<stdio.h>
char *str(char *p1, char *p2)
{
	char *p=p1;
	while(*p1++);

	p1--;
	while(*p1++=*p2++);
	return p;
}
int main()
{
	char c,str1[100],str2[100];
	int i;

	printf("请输入第一个字符串:\n");
	gets(str1);
	printf("请输入第二个字符串:\n");
	gets(str2);
	printf("连接后的字符串为：\n%s",str(str1,str2));
	return 0;
}
