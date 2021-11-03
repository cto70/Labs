#include "CorrectFraction.h"
CorrectFraction :: CorrectFraction()
{
}
long long CorrectFraction :: GCD( const long long num, const long long den )
{
    long long numerator_ = abs( num );
    long long denominator_ = abs( den );
    if( numerator_ == 0 )
    {
        return denominator_;
    }
    long long reminder_ = numerator_ % denominator_;
    while( reminder_ != 0 )
    {
        numerator_ = denominator_;
        denominator_ = reminder_;
        reminder_ = numerator_ % denominator_;
    }
    return denominator_;
}
string CorrectFraction :: IntToString( long long a )
{
    string s;
    if( a >= 0)
    {
        s = "";
    }
    else
    {
        s = "-";
    }
    long long a_ = abs( a );
    vector< int > data;
    while( a_ != 0 )
    {
        data.push_back( a_ % 10);
        a_ /= 10;
    }
    for( long long i = data.size() - 1; i >= 0; i-- )
    {
        s += ( data[ i ] + '0' );
    }
    if( s == "")
    {
        s = "0";
    }
    return s;
}
void CorrectFraction :: StandartView()
{
    long long reminder = GCD( this -> numerator, this -> denominator );
    this -> numerator /= reminder;
    this -> denominator /= reminder;
    if( this -> numerator == 0 )
    {
        this -> denominator = 1;
    }
    if( this -> denominator < 0 )
    {
        this -> numerator *= -1;
        this -> denominator *= -1;
    }
}
void CorrectFraction :: assign( long long  numerator_, long long denominator_ )
{
    this -> numerator = numerator_;
    this -> denominator = denominator_;
}
CorrectFraction :: CorrectFraction( const long long numerator_, const long long denominator_ )
{
    if( denominator_ == 0 )
    {
        throw "Exception";
    }
    assign( numerator_, denominator_ );
    StandartView();
}
CorrectFraction :: CorrectFraction( const CorrectFraction& CorrectFraction )
{
    assign( CorrectFraction.numerator, CorrectFraction.denominator );
}
CorrectFraction CorrectFraction :: SUM( CorrectFraction a, CorrectFraction b )
{
    long long numerator_ = a.numerator * b.denominator + b.numerator * a.denominator;
    long long denominator_ = a.denominator * b.denominator;
    CorrectFraction c( numerator_, denominator_ );
    return c;
}
CorrectFraction CorrectFraction :: MULTIPLY( CorrectFraction a, CorrectFraction b )
{
    long long numerator_ = a.numerator * b.numerator;
    long long denominator_ = a.denominator * b.denominator;
    CorrectFraction c( numerator_, denominator_ );
    return c;
}
CorrectFraction CorrectFraction :: DIVIDE( CorrectFraction a, CorrectFraction b )
{
    if( b.numerator == 0 )
    {
        throw "Exception";
    }
    long long numerator_ = a.numerator * b.denominator;
    long long denominator_ = b.numerator * a.denominator;
    CorrectFraction c( numerator_, denominator_ );
    return c;
}
void CorrectFraction :: SUM( CorrectFraction a )
{
    long long numerator_ = this -> numerator * a.denominator + a.numerator * this -> denominator;
    long long denominator_ = this -> denominator * a.denominator;
    assign( numerator_, denominator_);
    StandartView();
}
void CorrectFraction :: MULTIPLY( CorrectFraction a )
{
    long long numerator_ = this -> numerator * a.numerator;
    long long  denominator_ = this -> denominator * a.denominator;
    assign( numerator_, denominator_);
    StandartView();
}
void CorrectFraction :: DIVIDE( CorrectFraction a )
{
    if( a.numerator == 0 )
    {
        throw "Exception";
    }
    long long numerator_ = this -> numerator * a.denominator;
    long long denominator_ = a.numerator * this -> denominator;
    assign( numerator_, denominator_ );
    StandartView();
}
long long CorrectFraction :: getNumerator()
{
    return this -> numerator;
}
long long CorrectFraction :: getDenominator()
{
    return this -> denominator;
}
string CorrectFraction :: to_string()
{
    string s = "";
    if( this -> denominator == 1 )
    {
        s = IntToString( this -> numerator );
    }
    else
    {
        s = IntToString( this -> numerator ) + " / " + IntToString( this -> denominator );
    }
    return s;
}
