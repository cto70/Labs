#include <iostream>
#include <vector>
#include <cmath>
#include <string>
using std :: cout;
using std :: cin;
using std :: vector;
using std :: endl;
using std :: string;
void swap( int& a, int& b)
{
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
}
int get( int i, int j, const vector< vector< int > >& data)
{
    if ( j > i )
    {
        swap( i, j);
    }
    return data[ i ][ j ];
}
void enter_data( vector< vector < int >>& data, const int& length )
{
    for( int i = 0; i < length; i++ )
    {
        int x;
        data.push_back( {} );
        for( int j = 0; j < length; j++)
        {
            cin >> x;
            if( j <= i)
            {
                data[i].push_back( x );
            }
        }
    }
}
int max_negative_in_column_i( const vector< vector< int > >& data, const int& i, const int& length )
// вычисляет максимальное значение в столбце i где все элементы отрицательные
{
    int max = get( 0, i, data);
    for( int j = 0; j < length; j++)
    {
        if( get(j, i, data) > 0 )
        {
            return 0;
        }
        if( get( j, i, data) > max )
        {
            max = get( j, i, data );
        }
    }
    return max;
}
int max_negative( const vector< vector< int >>& data, int length)
// вычисляет максимальное значение в отрицательных столбцах во всей таблице
{
    int x = 0;
    int max = INT_MIN;
    for( int i = 0; i < length; i++ )
    {
        int y = max_negative_in_column_i(data, i, length);
        if( y == 0 )
        {
            x++;
            continue;
        }
        if( y > max )
        {
            max = y;
        }
    }
    if( x == length )
    {
        return 0;
    }
    else
    {
        return max;
    }
}
double cross_up_to_down( const int& i, const int& j, const vector< vector< int >>& data, const int& length)
/* выводит среднее геометричиское элементов
диагонали которая начинается в точке i, j и паралельна главной диагонали (0,0) - ( length - 1, length - 1) */
{
    int i_ = i;
    int j_ = j;
    int n = 0;
    double sum = 0;
    while( i_ < length && j_ < length)
    {
        sum+= get( i_, j_, data );
        n++;
        i_++;
        j_++;
    }
    sum /= n;
    return sum;
}
double cross_down_to_up( const int& i, const int& j, const vector< vector< int >>& data, const int& length)
/* выводит среднее геометричиское элементов
диагонали которая начинается в точке i, j и паралельна главной диагонали (0, length - 1) - ( length - 1, 0) */
{
    int i_ = i;
    int j_ = j;
    int n = 0;
    double sum = 0;
    while( i_ < length && j_ < length && i_ >= 0 && j_ >= 0)
    {
        sum+= get( i_, j_, data );
        n++;
        i_--;
        j_++;
    }
    sum /= n;
    return sum;
}
double min_cross( const vector< vector< int > >& data, const int& length)
// вычисляет диагональ с минимальным средним арифметическим( кроме двух основных )
{
    double min = INT_MAX;
    for( int i = 1; i < length; i++)
    {
        if( cross_up_to_down( 0, i, data, length) < min)
        {
            min = cross_up_to_down(0, i, data, length);
        }
    }
    for( int i = 1; i < length; i++)
    {
        if( cross_up_to_down( i, 0, data, length) < min)
        {
            min = cross_up_to_down( i, 0, data, length );
        }
    }
    for( int i = 0; i < length - 1; i++)
    {
        if( cross_down_to_up( 0, i, data, length) < min)
        {
            min = cross_down_to_up( 0, i, data, length);
        }
    }
    for( int i = 1; i < length; i++)
    {
        if( cross_down_to_up(i, length - 1, data, length) < min)
        {
            min = cross_down_to_up(i, length - 1, data, length);
        }
    }
    return min;
}
void write_data( const vector< vector< int >>& data, const int& length)
{
    for (int i = 0; i < length; i++)
    {
        for( int j = 0; j < length; j++)
        {
            cout << get( i, j, data) << " ";
        }
        cout << endl;
    }
}
int main() {
    while( true )
    {
        vector< vector< int > > data;
        double length;
        while(true) {
            cout << "Enter the array length:" << endl;
            cin >> length;
            if( floor( length ) == length && length >= 1)
            {
                break;
            }
            else
            {
                cout << "Invalid value" << endl;
            }
        }
        cout << "Enter the array:" << endl;
        enter_data( data, (int) length);
        cout << "The array is:" << endl;
        write_data( data, (int)length );
        double min = min_cross( data, (int) length );
        int max = max_negative( data, (int) length );
        if( max == 0 )
        {
           cout <<  "The column with all negative doesn't exist" << endl;
        }
        else
        {
            cout << "The max element from all columns with only negative elements is: " << max << endl;
        }
        if( length == 1 )
        {
            cout << "The program can't count because all diagonals are main" << endl;
        }
        else
        {
            cout << "The min value of arithmetic mean of all diagonals without main diagonals is: " << min << endl;
        }
        string s;
        cout << "If you want to finish enter 0, else enter any other string" << endl;
        cin >> s;
        if( s == "0")
        {
            break;
        }
    }
}
