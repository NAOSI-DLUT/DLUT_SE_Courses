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

	printf("请输入第字符串:\n");
	gets(str);

	printf("复制后的字符串为：\n%s",strcpy(str_copy,str));
	return 0;
}
