#include<stdio.h>
int main()
{
    int  a[3][3]={3,2,6,4,7,3,5,2,8},b[3],i,j;
    for(i=0;i<3;i++)
	{  
        b[i]=0;            
        for(j=0;j<3;j++)
		  if(a[i][j]%2==0)
			  b[i]++;  
    }  
    for(i=0;i<3;i++)  
       printf("%d ",b[i]);  
    return 0;
}
 