
9
#include <stdio.h>
#include <string.h>
int main ()
{ 
	char a[20] = "abdabdabvd";
	char a1[20] ="";
	char b[3] = "ab";
	char *p1=a, *p2=a;
	while (1)
	{
		p1 = strstr(p1,b);
		if(p1 != NULL)
		{
			*p1  = '\0';
			strcat(a1,p2);
			p1 = p1 + 2;
			p2 = p1;
		}
		else 
		{
			strcat(a1,p2);
			break;
		}

	}
	printf("%s",a1);
	return 0;

}
