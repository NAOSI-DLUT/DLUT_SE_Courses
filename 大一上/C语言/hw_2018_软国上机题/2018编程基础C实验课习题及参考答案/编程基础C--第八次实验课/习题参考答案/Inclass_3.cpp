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

	printf("�������һ���ַ���:\n");
	gets(str1);
	printf("������ڶ����ַ���:\n");
	gets(str2);
	printf("���Ӻ���ַ���Ϊ��\n%s",str(str1,str2));
	return 0;
}
