//
// Created by yarov on 02.11.2021.
//
#ifndef LAB6_CORRECTFRACTION_H
#define LAB6_CORRECTFRACTION_H
#include <iostream>
#include <exception>
#include <cmath>
#include <string>
#include <vector>
using std :: string;
using std :: vector;
class CorrectFraction
{
private:
    long long numerator;
    long long denominator;
private:
    CorrectFraction();
private:
    long long GCD( const long long numerator, const long long denominator );
    string IntToString( long long a );
    void StandartView();
    void assign( long long  numerator, long long denominator );
public:
    CorrectFraction( const long long numerator, const long long denominator );
    CorrectFraction( const CorrectFraction& CorrectFraction );
public:
    static CorrectFraction SUM( CorrectFraction a, CorrectFraction b );
    static CorrectFraction MULTIPLY( CorrectFraction a, CorrectFraction b );
    static CorrectFraction DIVIDE( CorrectFraction a, CorrectFraction b );
public:
    void SUM( CorrectFraction a );
    void MULTIPLY( CorrectFraction a );
    void DIVIDE( CorrectFraction a );
public:
    long long getNumerator();
    long long getDenominator();
    string to_string();
};
#endif //LAB6_CORRECTFRACTION_H
