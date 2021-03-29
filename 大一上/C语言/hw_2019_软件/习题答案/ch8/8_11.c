//打印三角形图案

#include<stdio.h>
int main()
{
	int i, j;
    for( i = 1; i <= 8; i ++)
    {
        for( j = 1; j < 2 * i; j ++)
            printf( "*" );
        printf( "\n" );
        if ( i == 2 )
            printf( "*" );
        else if( i == 3 )
            printf( "*" );
    }
    printf( "\n\n" );
    for( i = 8;i > 0; i--)
    {
        for( j = 1; j < 2 * i; j ++)
            printf( "*" );
            if (i == 3)
            printf( "*" );
        printf( "\n" );
    }

	return 0;
}
