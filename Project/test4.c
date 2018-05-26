#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


void Menu();


void Operate( char op );


void Two();


void Ten();


int main( void )
{
    char op;

    /* 选择要进行的操作 */
    Operate( op );

    system( "PAUSE" );
    return(0);
}


void Menu()
{
    printf( "        Menu        \n");
    printf( "1:Binary to decimal.\n");
    printf( "2:Decimal to binary.\n");
    printf( "3:Exit.\n");
    printf( "Please enter the function to perform:\n");
}


void Operate( char op )
{
    while ( op != '3')
    {
        /* 展示功能菜单 */
        Menu();

        /* 进行操作 */
        scanf( "%c", &op);
        getchar();
        printf( "\n" );
        switch ( op )
        {
            /* 进行二进制转为十进制 */
            case '1':
                Two();
                break;

            /* 进行十进制转为二进制 */
            case '2':
                Ten();
                break;
            
            /* 退出 */
            case '3':
                printf( "Exit the success!\n" );
                system( "PAUSE" );
                exit(0);

            default:
                printf( "\nUnknown operation!\n" );
                printf( "Please enter again!\n\n");
        }
    }
}


void Two()
{
    int i;
    int j   = 0;
    int a   = 0;
    char    n[32]   = { '0' };
    
    /* 输入二进制数 */
    printf( "Please enter binary number:\n" );
    gets( n );

    /* 转换成十进制 */
    printf( "The converted decimal is:\n" );

    /* 判断是否为负数 */
    if( n[0] == '1' )
    {
        printf("-");
    }
    for( i = strlen( n ) - 1; i > 0; i--, j++ )
    {
        a += ( n[i] - '0' ) << j;
    }
    printf( "%d\n\n",a );    
}


void Ten()
{
    int a;
    int i   = 32;

    /* 输入十进制数 */
    printf( "Please enter a decimal integer:\n" );
    scanf( "%d", &a);
    getchar();

    /* 转换成二进制数 */
    printf( "The converted binary is:\n" );

    /* 判断正负 */
    if ( a >= 0)
    {
        printf( "%d", ( a >> i - 1 ) & 1 );
    }
    else
    {
        printf( "%d", ( ~ ( abs( a ) >> i - 1 ) ) & 1 );
    }
    for( i = 31; i > 0; i-- )
    {
        printf( "%d", ( abs( a ) >> i - 1 ) & 1 );
    }
    printf( "\n\n");
}