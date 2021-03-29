#include<stdio.h>
void printnChar(int n,char t)
{
	for(int i=1;i<=n;i++)
		printf("%c",t);
}
int main()
{
	int n;
	char t;
	printf("打印出n个连续字符t：");
	scanf("%d,%c",&n,&t);
	printnChar(n,t);
	return 0;
}