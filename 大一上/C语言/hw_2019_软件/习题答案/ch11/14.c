#include <stdio.h>
#include <string.h>
void main()
{
  void sub1(char str[]);
  char string[80];
  gets(string);
  sub1(string);
  puts(string);
}

void sub1(char str[])
{
  char str2[80],str3[20];
  int len=strlen(str),i,k3=0,k2=0,m;
  for(i=len-1;i>=0;i--)
  {
    if(str[i]!=' ')
       str3[k3++]=str[i];
	else
	{
	   if(k3!=0)
	   {
		  for(m=k3-1;m>=0;m--)
			  str2[k2++]=str3[m];
		  k3=0;
       }
	   str2[k2++]=' ';
	} 
  }
  //处理第一个单词
  if(k3!=0)
	for(m=k3-1;m>=0;m--)
	  str2[k2++]=str3[m];
  str2[k2]='\0';
  strcpy(str,str2);
}
