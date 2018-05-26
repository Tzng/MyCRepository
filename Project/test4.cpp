#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;

class Change
{
public:
    void Menu();


    void Operate( char op );


    void Two();


    void Ten();


private:
    char op;
};
int main( void )
{
    char    op;
    Change  Num;
    /* 选择要进行的操作 */
    Num.Operate( op );

    system( "PAUSE" );
    return(0);
}


void Change::Menu()
{
    cout << "        Menu        \n";
    cout << "1:Binary to decimal.\n";
    cout << "2:Decimal to binary.\n";
    cout << "3:Exit.\n";
    cout << "Please enter the function to perform:\n";
}


void Change::Operate( char op )
{
    while ( op != '3')
    {
        /* 展示功能菜单 */
        Menu();

        /* 进行操作 */
        cin >> op;
        cin.get();
        cout << "\n";
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
                cout << "Exit the success!\n";
                system( "PAUSE" );
                exit(0);

            default:
                cout << "\nUnknown operation!\n";
                cout << "Please enter again!\n\n";
        }
    }
}


void Change::Two()
{
    int i;
    int j   = 0;
    int a   = 0;
    char    n[32]   = { '0' };
    
    /* 输入二进制数 */
    cout << "Please enter binary number:\n";
    cin >> n;

    /* 转换成十进制 */
    cout << "The converted decimal is:\n";

    /* 判断是否为负数 */
    if( n[0] == '1' )
    {
        cout <<"-";
    }
    for( i = strlen( n ) - 1; i > 0; i--, j++ )
    {
        a += ( n[i] - '0' ) << j;
    }
    cout << a << endl;   
}


void Change::Ten()
{
    int a;
    int i   = 32;

    /* 输入十进制数 */
    cout << "Please enter a decimal integer:\n";
    cin >> a;
    cin.get();

    /* 转换成二进制数 */
    cout << "The converted binary is:\n";

    /* 判断正负 */
    if ( a >= 0)
    {
        cout << ( ( a >> i - 1 ) & 1 );
    }
    else
    {
        cout << ( ( ~ ( abs( a ) >> i - 1 ) ) & 1 );
    }
    for( i = 31; i > 0; i-- )
    {
        cout << ( ( ( abs( a ) >> i - 1 ) & 1 ) );
    }
    cout << "\n" <<endl;
}