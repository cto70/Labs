#include <iostream>
#include <ctime>
#include <vector>
#include <string>
using std :: cout;
using std :: cin;
void swap(int* a, int* b)
{
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}
void sort_array( int* start, int length) {
    int i = -1;
    int j = -1;
    while( true )
    {
        while( i < length )
        {
            i++;
            if( *( start + i ) < 0)
            {
                break;
            }
        }
        if( i == length )
        {
            break;
        }
        j++;
        int x = *(start + i);
        for(int k = i; k >= j + 1; k--)
        {
            *(start + k) = *(start + (k - 1));
        }
        *(start + j) = x;
    }
}
long long composition(int* start, int length)
{
    long long composition = 1;
    for(int i = 0; i < length; i += 2)
    {
        composition *= *( start + i );
    }
    return composition;
}
long long sum(int* start, int length)
{
    int i = -1;
    int j = length;
    while( i < length )
    {
        i++;
        if( *(start + i) == 0)
        {
            break;
        }
    }
    while( j >= 0)
    {
        j--;
        if( *(start + j) == 0)
        {
            break;
        }
    }
    if( i == j)
    {
        return -2;
    }
    if( i == length)
    {
        return -1;
    }
    long long sum = 0;
    for(int k = i + 1; k <= j - 1; k++ )
    {
        sum += *(start + k);
    }
    return sum;
}
int main() {
srand(time(0) );
while(true)
{
    int n;
    cout << "Enter the array length\n";
    cin >> n;
    int* data = new int[n];
    while(true) {
        cout << "If you want to enter the array from the console write 0\n";
        cout << "If you want to fill the array with random numbers write 1\n";
        int x;
        cin >> x;
        if (x == 0) {
            for (int i = 0; i < n; i++) {
                cin >> *(data + i);
            }
            break;
        } else if (x == 1) {
            cout << "Enter min value and max value of array element\n";
            int min;
            int max;
            cin >> min >> max;
            for(int i = 0; i < n; i++)
            {
                *(data + i) = rand() % (max - min + 1) + min;
            }
            cout << "The array is:\n";
            for(int i = 0; i < n; i++ )
            {
                cout << *( data + i ) << " ";
            }
            cout << std :: endl;
            break;
        } else {
            cout << "Invalid value\n";
        }
    }
    cout << "The product of even array elements is: ";
    cout << composition(data, n) << std :: endl;
    cout << "The sum of the array elements located between the first and last zero elements is: ";
    if( sum( data, n) == -2) cout << "The program can't count because there is only 1 zero\n";
    else if ( sum( data, n ) == -1 ) cout << "The program can't count because there is no zero\n";
    else cout << sum(data, n) << std :: endl;
    cout << "The transformed array so that first there are negative numbers, and then positive ones with an unchanged order:\n";
    sort_array( data, n);
    for(int i = 0; i < n; i++)
    {
        cout << *( data + i ) << " ";
    }
    cout << std :: endl;
    cout << "If you want to finish enter 0 otherwise enter any other string\n";
    std :: string s;
    cin >> s;
    if( s == "0" )
    {
        break;
    }
    cout << std :: endl;
    delete[] data;
}
}
