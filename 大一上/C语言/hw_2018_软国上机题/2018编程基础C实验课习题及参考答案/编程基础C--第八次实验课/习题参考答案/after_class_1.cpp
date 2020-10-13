#include <stdio.h>
#include <string.h>

void substr(char *s1, char *s2, int len)
{
    int i, j, m = 0;
    int p, q;
    int length = strlen(s2);
    char a[100] = {0};
    char b[100] = {0};
    for(i = 0; i < len; i++)
    {
        for(j = 0; j < length; j++)
        {
            strcpy(a, "0");
            p = i;
            q = j;

            while(s1[p] == s2[q] && s1[p] != 0)
            {
                a[m] = s2[q];
                p++;
                q++;
                m++;
            }

            if(strlen(a) > strlen(b))
            {
                strcpy(b, a);
            }
            m = 0;
        }
    }
    printf("最大公子串：%s\n", b);
}

int main()
{
    char str1[100] = {0};
    char str2[100] = {0};
    int len;

    printf("请输入字符串1：");
    scanf("%s", str1);
    printf("请输入字符串2：");
    scanf("%s", str2);

    len = strlen(str1) <= strlen(str2) ? strlen(str1) : strlen(str2);
    if(len == strlen(str1))
    {
        substr(str1, str2, len);    
    }
    else if(len == strlen(str2))
    {
        substr(str2, str1, len);
    }

    return 0;
}

