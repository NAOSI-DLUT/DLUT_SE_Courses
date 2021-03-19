
7
#include <stdio.h>
char* lianjie(char*p1,char*p2)
{
	int i, j;
	for (i = 0; *(p1 + i) != '\0'; i ++)
		p1[i] = p1[i];
	for (j = 0; *(p2 + j) != '\0'; i ++, j ++)
		p1[i] = p2[j];
	p1[i] = '\0';
	return p1;
}
int main ()
{
	char a [20] = "xu shi ";
	char b [10] = "chang";
	lianjie(a,b);
	printf("%s",a);
	return 0;
}
