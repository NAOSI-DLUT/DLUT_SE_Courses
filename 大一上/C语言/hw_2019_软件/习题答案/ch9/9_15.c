#include <stdio.h>
int main()
{
	int a[2][3]={{1,2,3},{4,5,6}};
	int b[3][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12}};
	int c[2][4];
	int i,j,k;
	for(i=0;i<2;i++)
		for(j=0;j<4;j++)
		{
	    	c[i][j]=0;
            for(k=0;k<3;k++)
				c[i][j]=c[i][j]+a[i][k]*b[k][j];
		}
     for(i=0;i<2;i++)
	 {
		for(j=0;j<4;j++)
		   	printf("%d  ",c[i][j]);
		printf("\n");
	 }
      return 0;
}