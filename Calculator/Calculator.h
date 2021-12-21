//
// Created by yarov on 20.12.2021.
//

#ifndef CALCULATOR_CALCULATOR_H
#define CALCULATOR_CALCULATOR_H

#include <iostream>
#include <string>
#include <vector>
#include <exception>
#include <cmath>
#include "Type.h"
#include "PolishNotation.h"
#include "StringTokenizer.h"


class Calculator {
public:
    static double Calculate(const string &s_);

private:
    static double DoOperation(const string &s1, const string &s2, const string &operation);
};

#endif //CALCULATOR_CALCULATOR_H
