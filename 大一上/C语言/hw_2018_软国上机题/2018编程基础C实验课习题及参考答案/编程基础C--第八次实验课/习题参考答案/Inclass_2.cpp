#include<stdio.h>
char *strcpy(char *dest, const char *src)
{
	char *dstr=dest;	
	while(*src!='\0')
	{
		*dest++=*src++;
	}
	return dstr;
}
int main()
{
	char str[100],str_copy[100];

	printf("��������ַ���:\n");
	gets(str);

	printf("���ƺ���ַ���Ϊ��\n%s",strcpy(str_copy,str));
	return 0;
}
