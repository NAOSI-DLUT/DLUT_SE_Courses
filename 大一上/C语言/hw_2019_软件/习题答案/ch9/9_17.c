#include <stdio.h>
int main()
{
	int a[9][9];
	int i,j,k;
	for(i=0;i<9;i++)
		for(j=0;j<9;j++)
	    	a[i][j]=(i+1)*(j+1);
	printf("      ");
	for(i=1;i<=9;i++)
         printf("%4d  ",i);
	printf("\n");
    for(i=0;i<9;i++)
	 {
	    printf("%4d  ",i+1);
		for(j=0;j<=i;j++)
		   	printf("%4d  ",a[i][j]);
		printf("\n");
	 }
      return 0;
}