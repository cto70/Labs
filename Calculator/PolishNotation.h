//
// Created by yarov on 21.12.2021.
//

#ifndef GOOGLE_TESTS_POLISHNOTATION_H
#define GOOGLE_TESTS_POLISHNOTATION_H

#include "Type.h"
#include "Stack.h"

class PolishNotation {
private:
    static void DoIfIsNumber(const string &s, vector<string> &PolishEquation, Stack<string> &operations);

    static void DoIfIsStaple(const string &s, vector<string> &PolishEquation, Stack<string> &operations);

    static void DoIfIsOperation(const string &s, vector<string> &PolishEquation, Stack<string> &operations);

public:
    static vector<string> TransformToPolishNotation(const vector<string> &equation);
};

#endif //GOOGLE_TESTS_POLISHNOTATION_H
