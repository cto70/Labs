#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main()
{
    string s;
    const int MAX_VALUE = 15;
    double degree_of_accuracy; // степень точности(количество знаков после запятой)
    double pow_of_function_e;  // степень в которую надо возвести число е
    double power; // эталонное значение
    int length_of_integer_part; // длина челой части эталона(нужна для определения максимального значения degree_of_accuracy
while(true)
{
cout << "Enter the power of function e from -9 to 30\n";
cin >> pow_of_function_e;
if( ( pow_of_function_e < -9 ) || ( pow_of_function_e > 30 ) )
{
    cout << "Invalid value\n";
    continue;
}
power = pow(M_E, pow_of_function_e);
if( pow_of_function_e < 1 )
{
    length_of_integer_part = 1;
}
else length_of_integer_part = floor( log10( power ) ) + 1;
while(true)
{
    cout << "\nEnter the accuracy of the number from " << 0 << " to " << MAX_VALUE - length_of_integer_part << endl;
    cin >> degree_of_accuracy;
    int min_size = 0;
    int max_size = MAX_VALUE - length_of_integer_part;
    if ( degree_of_accuracy == floor(degree_of_accuracy) && degree_of_accuracy >= min_size && degree_of_accuracy <= max_size )
    {
        break;
    }
    cout << "Invalid value";
}
double summand = 1;
double result = 1;
int i = 1;
while( floor( pow(10, degree_of_accuracy) * result) != floor( pow( 10, degree_of_accuracy) * power))
{
    summand /= i;
    summand *= pow_of_function_e;
    result += summand;
    i++;
     if ( summand == 0) break;
}
result = floor( pow(10, degree_of_accuracy) * result ) / pow(10, degree_of_accuracy);
cout << setprecision(length_of_integer_part + degree_of_accuracy) << result;
cout << endl;
cout << "\nIf you want to finish write stop, otherwise enter any other string\n";
cin >> s;
if(s == "stop" )
{
    break;
}
else
{
    cout << "\n\n";
}
}
}
