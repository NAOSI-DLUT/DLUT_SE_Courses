/*编写程序实现百分制和等级制的成绩转换。*/

#include<stdio.h>   
 
int main()
{
     /*根据分数打印学生成绩等级*/
	int grade=67;
	
	if ( grade>90)   printf("A \n");
	if ( grade<90&&grade>80)  printf ("B \n");
	if ( grade<80&&grade>70)  printf  ("C \n");
	if (grade<70&&grade>60)   printf ("D \n");
	if (grade<60)			 printf ("F \n");
  
    
	/*根据分数打印学生成绩等级*/	  

	if ( grade>=90 )
		printf("A \n");
	else if( grade>=80) 
		printf("B \n");
	else if( grade>=70 )
		printf("C \n");
	else if( grade>=60)
		printf("D \n");
	else
		printf("F \n");
    

	/*根据分数打印学生成绩等级*/
  
	switch(grade/10)
	{
		case 10:
		case 9 :
			printf("A \n");	
			break;
		case 8:
			printf("B \n");
			break;
		case 7:
			printf("C \n");
			break;
		case 6:
			printf("D \n");	
			break;
		default:
			printf("F \n");
			break;
	}
	return 0;
}