
6
#include <stdio.h>
char* fuzhi(char *p1,char *p2 )
{
	int i;
	for(i = 0; *(p2 + i) != '\0';i ++)
		*(p1 + i) = *(p2 + i) ;
	*(p1 + i) = '\0';
	return p1;
}
int main ()
{ 
	char a[20] = "xu ";
	char b[20] = " shi chang";
	fuzhi(a,b);
	printf("%s",a);
	return 0;
}
