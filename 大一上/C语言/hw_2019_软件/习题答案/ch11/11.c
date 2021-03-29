
11
#include <stdio.h>
#include <string.h>
int main ()
{
	char a[10][20];
	char b[20];
	int i, j;
	int tem;
	for (i = 0; i < 10; i ++)
	{
		 scanf("%s",a[i]);
	}
	for (i = 0; i < 9; i ++)
	{
		tem = i;
		for(j = i+1; j < 10; j++ )
		{
			if(strcmp(a[i],a[j]) > 0)
				tem = j;
		}
		if(tem != i)
			{
				strcpy(b,a[tem]);
				strcpy(a[tem],a[i]);
				strcpy(a[i],b);
			}
	}
	for(i = 0; i < 10; i ++)
		printf("%s\n",a[i]);
	return 0;
}
