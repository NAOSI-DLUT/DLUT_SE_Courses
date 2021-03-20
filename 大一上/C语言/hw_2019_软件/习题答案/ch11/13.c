
12
#include <stdio.h>
#include <string.h>
int main()
{
	
	char b[80][20];
	char a[80];
	char tem[20];
	char c[3] = " ";
	char*p, *p1;
	int i = 0;
	int i1, i2, flag;
	p1 = a;
	p = p1;
	gets(a);
	while(1)
	{
		p = strstr(p1,c);
		if (p != NULL )
		{
			*p = '\0';
			strcpy(b[i],p1);
			p = p + 1;
			while (1)
			{
				if(*p != ' ')
				break;
				p ++;
			}
			p1 = p;
		}
		else 
		{
			strcpy(b[i],p1);
			break;
		}
		i ++;
	}
	for(i1 = 0; i1 < i; i1 ++)
	{
		flag = i1;
		for(i2 = i1+1; i2 < i+1; i2 ++)
		{
			if(strlen(b[flag]) > strlen(b[i2]))
				flag = i2;
		}	
		if(flag != i1)
		{
			strcpy(tem,b[flag]);
			strcpy(b[flag],b[i1]);
			strcpy(b[i1],tem);
		}
	}
	for(i1 = 0; i1 <= i; i1 ++) 
		printf("%s\n",b[i1]);
	return 0;
	
}
