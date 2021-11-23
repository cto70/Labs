#include <iostream>

#include "Student.h"
#include "StudentAfterFirstExaminationSeason.h"
#include "StudentAfterSecondExaminationSeason.h"

int main() {
    StudentAfterSecondExaminationSeason st1(1, 2, {1, 1,1,1}, {1,1,1,1,1});
    StudentAfterFirstExaminationSeason st2(1, 3, {2, 2, 2, 2});
    StudentAfterFirstExaminationSeason st3(1, 3, {3, 3, 3, 3});
    Student st(1,2);
    std :: cout << st;
}

