//
// Created by yarov on 10.10.2021.
//

#ifndef LAB4_CHARSTRING_H
#define LAB4_CHARSTRING_H
void copy( char* ptr, const char* string);
char* _strcat( char* strDestination, const char* strSource );
char* find_end( char* str);
void copy( char* ptr, const char* string, int n);
int CountDifferentSymbols( char* start, const char* end );
char* MinDifferentSymbols( char* str );
char* find( char* str, char* start_index );
#endif //LAB4_CHARSTRING_H
