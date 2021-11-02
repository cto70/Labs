#include "CorrectFraction.h"
CorrectFraction :: CorrectFraction()
{
}
long long CorrectFraction :: GCD( const long long numerator, const long long denominator )
{
    long long numerator_ = abs( numerator );
    long long denominator_ = abs( denominator );
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
void CorrectFraction :: assign( long long  numerator, long long denominator )
{
    this -> numerator = numerator;
    this -> denominator = denominator;
}
CorrectFraction :: CorrectFraction( const long long numerator, const long long denominator )
{
    if( denominator == 0 )
    {
        throw "Exception";
    }
    assign( numerator, denominator );
    long long reminder = GCD( this -> numerator, this -> denominator );
    this -> numerator /= reminder;
    this -> denominator /= reminder;
    StandartView();
}
CorrectFraction :: CorrectFraction( const CorrectFraction& CorrectFraction )
{
    assign( CorrectFraction.numerator, CorrectFraction.denominator );
}
CorrectFraction CorrectFraction :: SUM( CorrectFraction a, CorrectFraction b )
{
    long long numerator = a.numerator * b.denominator + b.numerator * a.denominator;
    long long denominator = a.denominator * b.denominator;
    CorrectFraction c( numerator, denominator );
    return c;
}
CorrectFraction CorrectFraction :: MULTIPLY( CorrectFraction a, CorrectFraction b )
{
    long long numerator = a.numerator * b.numerator;
    long long denominator = a.denominator * b.denominator;
    CorrectFraction c( numerator, denominator );
    return c;
}
CorrectFraction CorrectFraction :: DIVIDE( CorrectFraction a, CorrectFraction b )
{
    if( b.numerator == 0 )
    {
        throw "Exception";
    }
    long long numerator = a.numerator * b.denominator;
    long long denominator = b.numerator * a.denominator;
    CorrectFraction c( numerator, denominator );
    return c;
}
void CorrectFraction :: SUM( CorrectFraction a )
{
    long long numerator = this -> numerator * a.denominator + a.numerator * this -> denominator;
    long long denominator = this -> denominator * a.denominator;
    this -> numerator = numerator;
    this -> denominator = denominator;
}
void CorrectFraction :: MULTIPLY( CorrectFraction a )
{
    long long numerator = this -> numerator * a.numerator;
    long long  denominator = this -> denominator * a.denominator;
    this -> numerator = numerator;
    this -> denominator = denominator;
}
void CorrectFraction :: DIVIDE( CorrectFraction a )
{
    if( a.numerator == 0 )
    {
        throw "Exception";
    }
    long long numerator = this -> numerator * a.denominator;
    long long denominator = a.numerator * this -> denominator;
    assign( numerator, denominator );
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
