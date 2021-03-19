15
#include <stdio.h>
#include <string.h>
int main ()
{
	int sum[200] = {0};
	char a[200];
	int b,c,i;
	scanf("%d",&b);b
	while (b--)
	{
		scanf("%s",a);
		c = strlen(a);
		for(i = 0; i < c; i ++)
		{
			sum[i] += (a[c-i-1]-48);		
			sum[i+1] += sum[i]/10;
			sum[i] = sum[i]%10;
		}
	}
	for(i = 199; sum[i] == 0; i --);
	for(i = i;i >=0; i --)
		printf("%d",sum[i]);
	return 0;
}

