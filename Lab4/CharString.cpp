//
// Created by yarov on 10.10.2021.
//
#include "CharString.h"
char* find_end( char* str)
{
    int i = 0;
    while( *( str + i ) != '\0' )
    {
        i++;
    }
    return (str + i);
}
void copy( char* ptr, const char* string)
{
    for( int i = 0; i >= 0; i++ )
    {
        *( ptr + i ) = *( string + i );
        if( *(string + i ) == '\0')
        {
            break;
        }
    }
}
void copy( char* ptr, const char* string, int n)
{
    for( int i = 0; i < n; i++ )
    {
        *( ptr + i ) = *( string + i );
    }
}
char* _strcat( char* strDestination, const char* strSource )
{
    char* end = find_end( strDestination );
    copy( end, strSource );
    return strDestination;
}
char* find( char* str, char* start_index )
{
    char* index = start_index;
    while( *index  != '\0' && *index != ' ' )
    {
        index++;
    }
    return index;
}
int CountDifferentSymbols( char* start, const char* end )
{
    int* data = new int[ 256 ];
    for( int i = 0; i < 256; i++ )
    {
        data[ i ] = 0;
    }
    int n = 0;
    for( char* i = start; i <= end; i++ )
    {
        if( data[ *i ] == 0 )
        {
            n++;
        }
        data[ *i ]++;
    }
    delete[] data;
    return n;
}
char* MinDifferentSymbols( char* str )
{
    int min_number = 301;
    char* min_start;
    char* min_end;
    char* start = str;
    char* end;
    int n;
    while( true )
    {
        end = find( str, start );
        n = CountDifferentSymbols( start, end - 1);
        if( n < min_number )
        {
            min_number = n;
            min_start = start;
            min_end = end - 1;
        }
        if( *end == '\0' )
        {
            break;
        }
        end++;
        start = end;
    }
    char* result = new char[ min_end - min_start + 2];
    copy( result, min_start, min_end - min_start + 1);
    result[ min_end - min_start + 1 ] = '\0';
    return result;
}