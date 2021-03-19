/* 7_7
 简单计算器
 */
#include<stdio.h>
int main()
{
	int iNum1,iNum2;
    char cOperator, choice = 'y';

	while(choice=='y'||choice=='Y')
	{
		printf("Input the expression:\n");
        scanf("%d%c%d",&iNum1,&cOperator,&iNum2);
	
	    switch(cOperator)
		{
			case'+':
				printf(" = %d\n",iNum1+iNum2);
				break;
			case'-':
				printf(" = %d\n",iNum1-iNum2);
				break;
			case'*':
				printf(" = %d\n",iNum1*iNum2);
				break;
			case'/':
				if(iNum2==0) //  if(abs(fNum)<1e-7) 
				{
					 printf("Error! Division by zero.\n");
				}
				else
				{
					printf(" = %d\n",iNum1/iNum2);
					//printf(" = %f\n",1.0*iNum1/iNum2);
				}
				 break;
			default:
				printf("Error operation!\n");
				break;
		}

		printf("Do you want to continue?(y/n)");
		scanf("\n%c",&choice);
		/*getchar();   去除回车*/
		/*choice = getchar();   接收‘y’*/
	}

   return 0;

}