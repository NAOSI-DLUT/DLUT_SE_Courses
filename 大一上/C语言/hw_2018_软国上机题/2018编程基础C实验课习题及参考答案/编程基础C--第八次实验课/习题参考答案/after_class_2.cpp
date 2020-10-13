#include<stdio.h>
#include <stdlib.h>
#include <string.h>
char inStr[80+1];
char outStrs[20+1][80+1];
int main()
{
	printf("请输入一段不超过80字符，20单词的文章：\n");
	gets(inStr);
    int len = strlen(inStr);
    int wordNum = 0;
	int temp=0;
	int wordlength[20]={100};
	int sid[21]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};//记录单词的序号
    int i, j =0;
    for (i = 0;i < len; i++)
    {
        if (inStr[i] == ' ')//按空格划分单词 
        {            
			wordlength[wordNum]=j;//记录每个单词长度
			j=0;
            wordNum++;
            continue;
        }
        outStrs[wordNum][j] = inStr[i];
        j++; 
    }
	wordlength[wordNum]=j;
	/*for(i=0;i<=wordNum;i++)
	{
		printf("%d",wordlength[i]);
	}*/
	printf("单词的个数为：%d\n",wordNum+1);
	printf("单词按长度由小到大排列结果：\n");
	for(i=0;i<wordNum;i++)
	{
		for(j=0;j<wordNum-i;j++)
		{
			if(wordlength[j]>wordlength[j+1])
			{
				temp=wordlength[j];
				wordlength[j]=wordlength[j+1];
				wordlength[j+1]=temp;
				temp=sid[j];
				sid[j]=sid[j+1];
				sid[j+1]=temp;
			}						
		}		
	}
	for (i = 0; i <= wordNum ; i++)
    {		
		printf("%s ", outStrs[(sid[i])]);
	}
    return 0;
}
