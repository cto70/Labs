//
// Created by yarov on 21.12.2021.
//
#include "Type.h"

string const Type::AllBinOperations = "+-*/^";
string const Type::AllStaples = "(){}[]";
string const Type::AllOpenStaples = "({[";
string const Type::AllCloseStaples = ")}]";
string const Type::AllNumbers = "0123456789.,";
string const Type::AllUnOperations = "+-";
string const Type::AllDots = ".,";

bool Type::IsBinOperation(const string &s_) {
    return (AllBinOperations.find(s_) != -1);
}

bool Type::IsStaple(const string &s_) {
    return (AllStaples.find(s_) != -1);
}

bool Type::IsOpenStaple(const string &s_) {
    return (AllOpenStaples.find(s_) != -1);
}

bool Type::IsOneTypeOfStaples(const string &staple1, const string &staple2) {
    return (AllOpenStaples.find(staple1) == AllCloseStaples.find(staple2));
}

bool Type::IsNumber(const string &s_) {
    for (int i = 0; i < s_.size(); i++) {
        if (AllNumbers.find(s_[i]) == -1) {
            return false;
        }
    }
    return true;
}

bool Type::CompareOperations(const string &operation1, const string &operation2) {
    return (AllBinOperations.find(operation1) <= AllBinOperations.find(operation2));
}

bool Type::IsUnOperation(const string &s_) {
    return (AllUnOperations.find(s_) != -1);
}

bool Type::IsOneType(const string &string1, const string &string2) {
    if (IsNumber(string1) && IsNumber(string2)) {
        return true;
    }
    if (IsStaple(string1) && IsStaple(string2)) {
        return true;
    }
    if (IsBinOperation(string1) && IsBinOperation(string2)) {
        return true;
    }
    return false;
}

bool Type::IsDot(const string &s_) {
    return (AllDots.find(s_) != -1);
}

double Type::StringToDouble(const string &s_) {
    if (Type::IsDot(string(1, s_[0])) || Type::IsDot(string(1, s_[s_.size() - 1]))) {
        throw std::invalid_argument("Something wrong with syntax");
    }
    if (s_[0] == '-') {
        return -(StringToDouble(s_.substr(1, s_.size())));
    }
    int number_of_dots = 0;
    double result = 0;
    int dot_position = -1;
    for (int i = 0; i < s_.size(); i++) {
        if (Type::IsDot(string(1, s_[i]))) {
            dot_position = i;
            number_of_dots++;
            if (number_of_dots > 1) {
                throw std::invalid_argument("Something wrong with syntax");
            }
            continue;
        }
        result *= 10;
        result += (s_[i] - '0');
    }
    if (dot_position != -1) {
        result /= pow(10, s_.size() - dot_position - 1);
    }
    return result;
}