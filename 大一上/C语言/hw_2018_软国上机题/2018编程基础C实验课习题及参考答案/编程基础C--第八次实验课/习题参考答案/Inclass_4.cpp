#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char inStr[80+1];
char outStrs[40+1][80+1];
int main()
{   
	printf("������һ���ַ���\n");
	gets(inStr);
    int len = strlen(inStr);
    int wordNum = 0;
    int i, j = 0;
    for (i = 0; i < len; i++)
    {
        if (inStr[i] == ' ')//���ո񻮷ֵ��� 
        {
            j = 0;
            wordNum++;
            continue;
        }
        outStrs[wordNum][j] = inStr[i];
        j++; 
    }
	printf("ת�ú���ַ�Ϊ��\n");
    for (i = wordNum; i > 0 ; i--)
    {
        printf("%s ", outStrs[i]);
    }
    printf("%s\n", outStrs[0]);
    return 0;
}
