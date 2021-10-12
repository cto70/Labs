#include <iostream>
#include "CharString.h"
#include <map>
#include <vector>

int main() {
char* x = new char[ 2 ];
while( true )
{
    std :: cout << "If you want to test _strcat enter 1 and enter two strings\n";
    std :: cout << "If you want to find word with minimun different symbols enter 2 and enter one string\n";
   std :: cout << "If you want to finish enter 0\n";
   gets( x );
   std :: cin.clear( );
    if( x[0] == '0' )
    {
        break;
    }
    if( x[ 0 ] == '1' )
    {
        char* str1 = new char[ 602 ];
        char* str2 = new char[ 301 ];
        gets( str1 );
        std :: cin.clear();
        gets( str2 );
        printf( _strcat( str1, str2 ) );
        std :: cout << std :: endl;
        delete[] str1;
        delete[] str2;
    }
    else if( x[ 0 ] == '2' )
    {
        char* str1 = new char[ 301 ];
        gets( str1 );
        std :: cin.clear();
        printf( MinDifferentSymbols( str1 ) );
        std :: cout << std :: endl;
        delete[] str1;
    }
}
}
