//
// Created by yarov on 21.12.2021.
//
#include "PolishNotation.h"

void PolishNotation::DoIfIsNumber(const string &s, vector<string> &PolishEquation, Stack<string> &operations) {
    PolishEquation.push_back(s);
}

void PolishNotation::DoIfIsStaple(const string &s, vector<string> &PolishEquation, Stack<string> &operations) {
    if (Type::IsOpenStaple(s)) {
        operations.push(s);
    } else {
        while (!Type::IsOpenStaple(operations.top_element())) {
            PolishEquation.push_back(operations.pop());
        }
        if (!Type::IsOneTypeOfStaples(operations.pop(), s)) {
            throw std::invalid_argument("Something wrong with brackets");
        }
    }
}

void PolishNotation::DoIfIsOperation(const string &s, vector<string> &PolishEquation, Stack<string> &operations) {

    if (!operations.IsEmpty() && Type::IsBinOperation(operations.top_element())) {
        if (Type::CompareOperations(s, operations.top_element())) {
            PolishEquation.push_back(operations.pop());
        }
    }
    operations.push(s);
}

vector<string> PolishNotation::TransformToPolishNotation(const vector<string> &equation) {
    vector<string> PolishEquation;
    Stack<string> operations;
    try {
        for (const auto &i: equation) {
            if (Type::IsNumber(i)) {
                DoIfIsNumber(i, PolishEquation, operations);
            } else if (Type::IsStaple(i)) {
                DoIfIsStaple(i, PolishEquation, operations);
            } else if (Type::IsBinOperation(i)) {
                DoIfIsOperation(i, PolishEquation, operations);
            } else {
                throw std::invalid_argument("Unknown symbol " + i);
            }
        }
        while (!operations.IsEmpty()) {
            if (Type::IsOpenStaple(operations.top_element())) {
                throw std::invalid_argument("Something wrong with brackets");
            }
            PolishEquation.push_back(operations.pop());
        }
    } catch (std::out_of_range) {
        cout << "Something wrong with brackets";
        throw std::invalid_argument("Something wrong with brackets");
    }
    return PolishEquation;
}
