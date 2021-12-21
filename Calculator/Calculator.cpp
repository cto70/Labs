//
// Created by yarov on 21.12.2021.
//
#include "Calculator.h"

double Calculator::Calculate(const string &s_) {
    vector<string> PolishEquation = PolishNotation::TransformToPolishNotation(StringTokenizer::Tokenize(s_));
    Stack<string> equation;
    try {
        for (int i = 0; i < PolishEquation.size(); i++) {
            if (Type::IsBinOperation(PolishEquation[i])) {
                string s2 = equation.pop();
                string s1 = equation.pop();
                if (Type::IsBinOperation(s2)) {
                    equation.push(s1);
                    equation.push(s2);
                    equation.push(PolishEquation[i]);
                } else {
                    equation.push(to_string(DoOperation(s1, s2, PolishEquation[i])));
                }
            } else {
                equation.push(PolishEquation[i]);
            }
        }
        if (equation.number_of_elements() != 1) {
            throw std::invalid_argument("Something wrong with syntax");
        }
    } catch (out_of_range) {
        throw std::invalid_argument("Something wrong with syntax");
    }
    return Type::StringToDouble(equation.pop());
}

double Calculator::DoOperation(const string &s1, const string &s2, const string &operation) {
    if (operation == "+") {
        return Type::StringToDouble(s1) + Type::StringToDouble(s2);
    } else if (operation == "-") {
        return Type::StringToDouble(s1) - Type::StringToDouble(s2);
    } else if (operation == "*") {
        return Type::StringToDouble(s1) * Type::StringToDouble(s2);
    } else if (operation == "^") {
        double a = Type::StringToDouble(s1);
        double b = Type::StringToDouble(s2);
        if (a == 0 && b <= 0) {
            throw std::invalid_argument("Can't raise zero to a negative degree or zero");
        }
        if (a < 0 && floor(b) != b) {
            throw std::invalid_argument("Can't raise negative number to double degree");
        }
        return pow(a, b);
    } else if (operation == "/") {
        if (Type::StringToDouble(s2) == 0) {
            throw std::invalid_argument("Can't divide by zero");
        }
        return Type::StringToDouble(s1) / Type::StringToDouble(s2);
    }
    return 0;
}
