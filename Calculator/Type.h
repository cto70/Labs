//
// Created by yarov on 21.12.2021.
//

#ifndef GOOGLE_TESTS_TYPE_H
#define GOOGLE_TESTS_TYPE_H

#include <iostream>
#include <string>
#include <vector>
#include <exception>
#include <cmath>

using namespace std;

class Type {
private:
    static const string AllBinOperations;
    static const string AllStaples;
    static const string AllOpenStaples;
    static const string AllCloseStaples;
    static const string AllNumbers;
    static const string AllUnOperations;
    static const string AllDots;
public:
    static bool IsBinOperation(const string &s_);

    static bool IsStaple(const string &s_);

    static bool IsOpenStaple(const string &s_);

    static bool IsOneTypeOfStaples(const string &staple1, const string &staple2);

    static bool IsNumber(const string &s_);

    static bool CompareOperations(const string &operation1, const string &operation2);

    static bool IsUnOperation(const string &s_);

    static bool IsOneType(const string &string1, const string &string2);

    static bool IsDot(const string &s_);

    static double StringToDouble(const string &s_);
};

#endif //GOOGLE_TESTS_TYPE_H
