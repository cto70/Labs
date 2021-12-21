//
// Created by yarov on 21.12.2021.
//
#include "StringTokenizer.h"

vector<string> StringTokenizer::Tokenize(const string &s) {
    vector<string> result;
    if (Type::IsUnOperation(string(1, s[0]))) {
        result.push_back("0");
    }
    result.push_back(string(1, s[0]));
    for (int i = 1; i < s.size(); i++) {
        if (Type::IsUnOperation(string(1, s[i - 1])) && Type::IsUnOperation(string(1, s[i])) &&
            result[result.size() - 1] != string(1, s[i])) {
            result.pop_back();
            result.push_back("-");
        } else if (Type::IsOpenStaple(string(1, s[i - 1])) && Type::IsUnOperation(string(1, s[i]))) {
            result.push_back("0");
            result.push_back(string(1, s[i]));
        } else if (s[i] == ' ') {
            continue;
        } else {
            if (Type::IsNumber(string(1, s[i - 1])) && Type::IsNumber(string(1, s[i]))) {
                result.at(result.size() - 1) += s[i];
            } else {
                result.push_back(string(1, s[i]));
            }
        }
    }
    return result;
}