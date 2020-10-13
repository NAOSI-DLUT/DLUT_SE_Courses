#include <stdio.h>
#include <string.h>

const int MAXLEN = 100;
const int MAXSIZE = 10;
int strcmp(char *m1, char *m2)
{
	char *p1;
	char *p2;
	char a;
	char b;
	p1 = m1;
	p2 = m2;
	while(*p1 && *p2)
	{
		a = *p1;
		b = *p2;
		if(a>='A' && a<='Z')
			a = a + 'a' - 'A';
		if(b>='A' && b<='Z')
			b = b + 'a' - 'A';
		if(a>b)
			return 1;
		if(a<b)
			return -1;
		p1++;
		p2++;
	}
	if(*p1==*p2)
		return 0;
	else
	{
		if(*p1)
			return 1;
		if(*p2)
			return -1;
	}

}
void sort(char s[][MAXLEN],int n) {//ÅÅÐò
    int i,j;
    char *p;
    for(i = 0; i < n - 1; ++i) {
        for(j = i + 1; j < n; ++j) {
            if(strcmp(s[i],s[j]) > 0){
            	strcpy(p,s[i]);
            	strcpy(s[i],s[j]);
            	strcpy(s[j],p);
			}
        }
    }
}

void show(char s[][MAXLEN],int n) {
    int i;
    for(i = 0; i < n; ++i)
        printf("%s",s[i]);
    puts(" ");
}

int main(void) {
    char s[MAXSIZE][MAXLEN];
    int i;
    for(i = 0; i < MAXSIZE; ++i) {
        printf("string(%02d/%d):",i + 1,MAXSIZE);
        fgets(s[i],MAXLEN,stdin);
    }
    printf("ÅÅÐòÇ°:\n");
    show(s,MAXSIZE);
    sort(s,MAXSIZE);
    printf("ÅÅÐòºó:\n");
    show(s,MAXSIZE);
    return 0;
}
