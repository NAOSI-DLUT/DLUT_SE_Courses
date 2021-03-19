#include<stdio.h>
#define N 100
int main()
{
    char  s[80]="as23r98dn2	EKJFWfffkl  ;,dsags934jf";
	int i,digital=0,uLetter=0,lLetter=0,other=0;
	for(i=0;s[i];i++)
	{
		if(s[i]>=48 && s[i]<=57) 
			digital++;
		else if(s[i]>=65 && s[i]<=90) 
			uLetter++;
		else if(s[i]>=97 && s[i]<=122) 
			lLetter++;
		else
			other++;
	}
    printf("数字＝%d 大写字母＝%d 小写字母＝%d 其他＝%d ",digital,uLetter,lLetter,other);
    return 0;
}
 