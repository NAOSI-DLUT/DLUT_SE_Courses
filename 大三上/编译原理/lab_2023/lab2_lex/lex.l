%{
    #include<stdio.h>
    #include<stdlib.h>
    #define NUM 5
    #define LETTER 1
    #define STU_NUM 2
    #define NEWLINE 3
    int cnt_letter=0;
    int cnt_num=0;
    //int cnt_len=11;
%}

num [0-9]
letter [a-z|A-Z]
stu_num 999999
%%

{letter} {cnt_letter++;return LETTER;}
{num} {cnt_num++;return NUM;}
{stu_num} {return STU_NUM;}

%%

int yywrap(){
    return 1;
}

void writeout(int c)
{
    switch (c)
    {
    case NUM: fprintf(yyout, "%s", yytext);break;
    case LETTER: fprintf(yyout, "%s", yytext);break;
    case STU_NUM: cnt_num+=strlen(yytext);fprintf(yyout,"NAME");break;
    case NEWLINE: fprintf(yyout, "\n");break;
    default:break;
    }
    return;
}


int main(int argc, char* argv[])
{
    int c, j = 0;
    if (argc >= 2)
    {
        if ((yyin = fopen(argv[1], "r")) == NULL)
        {
            printf("Can't open file %s\n", argv[1]);
            return 1;
        }
        if (argc >= 3)
        {
            yyout = fopen(argv[2], "w");
        }
    }
    while (c = yylex())
    {
        writeout(c);
        j++;
      //  if (j % 20 == 0) writeout(NEWLINE);
    }

    if (argc >= 2)
    {
        fclose(yyin);
        fprintf(yyout, "\nletter: %d\n",cnt_letter);
        fprintf(yyout, "num: %d\n",cnt_num);      
        if (argc >= 3) fclose(yyout);
    }
    return 0;
}
