
8
#include <stdio.h>
int jishu(char*p)
{
	int i;
	for(i = 0; *(p + i) != '\0';i ++);
	return i;
}
int main ()
{
	char a[20] = "xu shi chang";
    printf("%d",jishu(a));
	return 0;
}
