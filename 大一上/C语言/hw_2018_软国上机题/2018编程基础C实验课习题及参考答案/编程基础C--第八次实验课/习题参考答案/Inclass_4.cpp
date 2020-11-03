#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char inStr[80+1];
char outStrs[40+1][80+1];
int main()
{   
	printf("请输入一行字符：\n");
	gets(inStr);
    int len = strlen(inStr);
    int wordNum = 0;
    int i, j = 0;
    for (i = 0; i < len; i++)
    {
        if (inStr[i] == ' ')//按空格划分单词 
        {
            j = 0;
            wordNum++;
            continue;
        }
        outStrs[wordNum][j] = inStr[i];
        j++; 
    }
	printf("转置后的字符为：\n");
    for (i = wordNum; i > 0 ; i--)
    {
        printf("%s ", outStrs[i]);
    }
    printf("%s\n", outStrs[0]);
    return 0;
}
