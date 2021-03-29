#include <stdio.h>
int main() 
{
	char c;
	scanf("%c",&c);
	if(c>=48 && c<=57) 
		printf("Êý×Ö×Ö·û");
	else if(c>=65 && c<=90) 
		printf("´óÐ´×ÖÄ¸×Ö·û");
	else if(c>=97 && c<=122) 
		printf("Ð¡Ð´×ÖÄ¸×Ö·û");
	else
		printf("ÆäËû×Ö·û");
    return 0;
}