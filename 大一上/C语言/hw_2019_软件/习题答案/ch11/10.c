#include<stdio.h>
#include<string.h>
int main()
{
   char str1[80]="ssabbcabcd",str2[10]="ab",
	   str3[10]="xyabz",str4[80];
   int  str2Length,str3Length;
   char *p,*q,*r;
   str2Length=strlen(str2);
   str3Length=strlen(str3);
   p=str1;
   while(p!=0)
   {
     q=strstr(p,str2);
	 if(q==0)
		 break;
     r=q+str2Length;
	 *q='\0';
     strcpy(str4,str3);
     strcat(str4,r);
	 strcat(str1,str4);
	 p=q+str3Length;
   }
   puts(str1);
}