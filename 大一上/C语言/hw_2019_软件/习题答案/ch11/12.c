#include <stdio.h>
#include <string.h>
int main ()
{
	char a[80];
	char b[80];
	char a1[80];
	char *p1;
	int c, i, j;
	unsigned int max = 0;
	gets(a);
	gets(b);
	c = strlen(b);
	for(i = c; i > 0; i --)
	{
		b[i] = '\0';
		for(j = 0; j < i; j ++)
		{
			p1 = b + j;
			 if(strstr(a,p1) != NULL)
			 {
				 if(strlen(p1) > max)
				 {
					 strcpy(a1,p1);
					max = strlen(a1);
				 }
			 }
		}
		
	}
	printf("%s\n",a1);
	return 0;
}

