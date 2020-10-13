#include <stdio.h>
#include <math.h>

int main()
{
    int i, j;
    
    for ( i = 0 ; i < 10 ; i++ )
    {
        for ( j = 0 ; j < (i+1) ; j++ )
            printf("* ");
        printf("\n");
    }
    printf("\n");
    
    for ( i = 10 ; i > 0 ; i-- )
    {
        for ( j = 0 ; j < i ; j++ )
            printf("* ");
        printf("\n");
    }
    printf("\n");
    
    for ( i = 0 ; i < 10 ; i++ )
    {
        for ( j = 0 ; j < i ; j++ )
            printf("  ");
        
        for ( j = i ; j < 10 ; j++ )
            printf("* ");
        printf("\n");
    }
    printf("\n");
    
    for ( i = 0 ; i < 10 ; i++ )
    {
        for ( j = 0 ; j < (9-i) ; j++ )
            printf("  ");
        
        for ( j = (9-i) ; j < 10 ; j++ )
            printf("* ");
        printf("\n");
    }
    printf("\n");
    
    return 0;
}
