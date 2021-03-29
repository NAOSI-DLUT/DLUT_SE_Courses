/*编写程序实现百分制和等级制的成绩转换。*/

#include<stdio.h>   
 
int main()
{
     
	/*根据考试成绩的等级打印出百分制分数段*/
	char grade;
	printf("Input grade (a,b,c,d):");
	scanf("%c",&grade);
	switch(grade)
	{
		case 'a':
			printf("85～100\n");break;
		case 'b':
			printf("70～84\n");break;
		case 'c':
			printf("60～69\n");break;
		case 'D':
			printf("<60\n");break;
		default:
			printf("error\n");break;
	}
 
	if(grade== 'a')
		printf("85～100\n");
	else if(grade=='b') 
		printf("70～84\n");  
	else if (grade=='c')
		printf("60～69\n");  
	else if ( grade =='d')
		printf("<60\n");    
	else
		printf("error\n");   
 
	
 
	return 0;
}