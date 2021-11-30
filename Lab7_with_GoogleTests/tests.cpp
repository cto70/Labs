//
// Created by yarov on 29.11.2021.
//
#include "gtest/gtest.h"
#include "StudentAfterSecondExaminationSeason.h"
#include "StudentAfterFirstExaminationSeason.h"
#include "Student.h"
#include <vector>
#include <set>

TEST(GenerateID, TestGenerateID) {
    vector<Student *> student(5000);
    std::set<long long> AllID;
    for (int i = 0; i < 5000; i++) {
        auto st = new Student(std::to_string(i), i, i);
        student[i] = st;
    }
    for (auto i: Student::GetAllStudents()) {
        AllID.insert(i->GetID());
    }
    for (int i = 0; i < 5000; i++) {
        delete student[i];
    }
    ASSERT_EQ(5000, AllID.size());
}

TEST(GenerateCreditCardNumber, TestGenerateCreditCardNumber) {
    vector<Student *> student(5000);
    std::set<long long> AllCreditCardNumber;
    for (int i = 0; i < 5000; i++) {
        auto st = new Student(std::to_string(i), i, i);
        student[i] = st;
    }
    for (auto i: Student::GetAllStudents()) {
        AllCreditCardNumber.insert(i->GetCreditCardNumber());
    }
    for (int i = 0; i < 5000; i++) {
        delete student[i];
    }
    ASSERT_EQ(5000, AllCreditCardNumber.size());
}

TEST(StudentAfterFirstExaminationSeason_AllMarksArithmethicMean, TestCounting1) {
    StudentAfterFirstExaminationSeason st("abc", 1, 1, {1, 2, 3, 4});
    ASSERT_EQ(2.5, st.AllMarksArithmeticMean());
}

TEST(StudentAfterFirstExaminationSeason_AllMarksArithmethicMean, TestCounting2) {
    StudentAfterFirstExaminationSeason st("abc", 1, 1, {3, 7, 9, 1});
    ASSERT_EQ(5, st.AllMarksArithmeticMean());
}

TEST(StudentAfterFirstExaminationSeason_AllMarksArithmethicMean, TestCounting3) {
    StudentAfterFirstExaminationSeason st("abc", 1, 1, {0, 1, 2, 5});
    ASSERT_EQ(2, st.AllMarksArithmeticMean());
}

TEST(StudentAfterSecondExaminationSeason_AllMarksArithmethicMean, TestCounting1) {
    StudentAfterSecondExaminationSeason st("abc", 1, 1, {1, 2, 3, 4}, {1, 2, 3, 4, 5});
    ASSERT_EQ(25 / 9.0, st.AllMarksArithmeticMean());
}

TEST(StudentAfterSecondExaminationSeason_AllMarksArithmethicMean, TestCounting2) {
    StudentAfterSecondExaminationSeason st("abc", 1, 1, {3, 7, 9, 1}, {6, 2, 5, 4, 1});
    ASSERT_EQ(38 / 9.0, st.AllMarksArithmeticMean());
}

TEST(StudentAfterSecondExaminationSeason_AllMarksArithmethicMean, TestCounting3) {
    StudentAfterSecondExaminationSeason st("abc", 1, 1, {1, 2, 3, 4}, {5, 6, 7, 8, 9});
    ASSERT_EQ(5, st.AllMarksArithmeticMean());
}

TEST(GetAllStudentsMarksArithmeticMeanAfterFirstExamenationSeason, TestCounting1) {
    StudentAfterFirstExaminationSeason st1("abc", 1, 1, {1, 2, 3, 5});
    StudentAfterFirstExaminationSeason st2("abc", 1, 1, {2, 2, 3, 4});
    StudentAfterFirstExaminationSeason st3("abc", 1, 1, {3, 2, 3, 4});
    ASSERT_EQ(17 / 6.0,
              StudentAfterFirstExaminationSeason::GetAllStudentsMarksArithmeticMeanAfterFirstExamenationSeason());
}

TEST(GetAllStudentsMarksArithmeticMeanAfterFirstExamenationSeason, TestCounting2) {
    StudentAfterFirstExaminationSeason st1("abc", 1, 1, {1, 2, 3, 4});
    StudentAfterFirstExaminationSeason st2("abc", 1, 1, {2, 2, 3, 4});
    StudentAfterFirstExaminationSeason st3("abc", 1, 1, {3, 2, 3, 4});
    StudentAfterFirstExaminationSeason st4("abc", 1, 1, {4, 2, 3, 4});
    StudentAfterFirstExaminationSeason st5("abc", 1, 1, {5, 2, 3, 4});
    ASSERT_EQ(3, StudentAfterFirstExaminationSeason::GetAllStudentsMarksArithmeticMeanAfterFirstExamenationSeason());
}

TEST(GetAllStudentsMarksArithmeticMeanAfterFirstExamenationSeason, TestCounting3) {
    StudentAfterFirstExaminationSeason st1("abc", 2, 5, {1, 2, 3, 5});
    StudentAfterFirstExaminationSeason st2("abc", 1, 5, {2, 2, 3, 4});
    StudentAfterFirstExaminationSeason st3("abc", 2, 4, {3, 2, 3, 4});
    StudentAfterFirstExaminationSeason st4("abc", 1, 5, {1, 2, 3, 5});
    StudentAfterFirstExaminationSeason st5("abc", 2, 5, {2, 2, 3, 4});
    StudentAfterFirstExaminationSeason st6("abc", 1, 7, {1, 2, 3, 5});
    StudentAfterFirstExaminationSeason st7("abc", 2, 2, {2, 2, 3, 4});
    ASSERT_EQ(StudentAfterFirstExaminationSeason::GetGroupMarksArithmeticMeanAfterFirstExamenationSeason(5),
              44.0 / 4 / 4);
}

TEST(GetAllStudentsMarksArithmeticMeanAfterFirstExamenationSeason, TestIfNoStudent) {
    ASSERT_EQ(-1,
              StudentAfterFirstExaminationSeason::GetAllStudentsMarksArithmeticMeanAfterFirstExamenationSeason());
}

TEST(GetAllStudentsMarksArithmeticMeanAfterSecondExamenationSeason, TestCounting1) {
    StudentAfterSecondExaminationSeason st1("abc", 1, 1, {1, 2, 3, 5}, {7, 2, 3, 1, 6});
    StudentAfterSecondExaminationSeason st2("abc", 1, 1, {2, 2, 3, 4}, {1, 7, 3, 4, 7});
    StudentAfterSecondExaminationSeason st3("abc", 1, 1, {3, 2, 3, 4}, {1, 9, 2, 1, 0});
    ASSERT_EQ(88 / 9.0 / 3,
              StudentAfterSecondExaminationSeason::GetAllStudentsMarksArithmeticMeanAfterSecondExamenationSeason());
}

TEST(GetAllStudentsMarksArithmeticMeanAfterSecondExamenationSeason, TestCounting2) {
    StudentAfterSecondExaminationSeason st1("abc", 1, 1, {1, 2, 3, 4}, {2, 5, 3, 5, 3});
    StudentAfterSecondExaminationSeason st2("abc", 1, 1, {2, 2, 3, 4}, {2, 8, 5, 3, 1});
    StudentAfterSecondExaminationSeason st3("abc", 1, 1, {3, 2, 3, 4}, {1, 7, 4, 2, 7});
    StudentAfterSecondExaminationSeason st4("abc", 1, 1, {4, 2, 3, 4}, {1, 9, 3, 6, 2});
    StudentAfterSecondExaminationSeason st5("abc", 1, 1, {5, 2, 3, 4}, {1, 9, 5, 3, 5});
    ASSERT_EQ(162 / 9.0 / 5,
              StudentAfterSecondExaminationSeason::GetAllStudentsMarksArithmeticMeanAfterSecondExamenationSeason());
}

TEST(GetAllStudentsMarksArithmeticMeanAfterSecondExamenationSeason, TestCounting3) {
    StudentAfterSecondExaminationSeason st1("abc", 2, 5, {1, 2, 3, 5}, {3, 7, 1, 5, 2});
    StudentAfterSecondExaminationSeason st2("abc", 1, 5, {2, 2, 3, 4}, {9, 1, 6, 2, 3});
    StudentAfterSecondExaminationSeason st3("abc", 2, 4, {3, 2, 3, 4}, {7, 1, 2, 0, 5});
    StudentAfterSecondExaminationSeason st4("abc", 1, 5, {1, 2, 3, 5}, {1, 6, 2, 5, 4});
    StudentAfterSecondExaminationSeason st5("abc", 2, 5, {2, 2, 3, 4}, {7, 1, 0, 2, 3});
    StudentAfterSecondExaminationSeason st6("abc", 1, 7, {1, 2, 3, 5}, {7, 1, 4, 3, 2});
    StudentAfterSecondExaminationSeason st7("abc", 2, 2, {2, 2, 3, 4}, {9, 1, 2, 1, 6});
    ASSERT_EQ(199.0 / 9 / 7,
              StudentAfterSecondExaminationSeason::GetAllStudentsMarksArithmeticMeanAfterSecondExamenationSeason());
}


TEST(GetAllStudentsMarksArithmeticMeanAfterSecondExamenationSeason, TestIfNoStudent) {
    ASSERT_EQ(-1,
              StudentAfterSecondExaminationSeason::GetAllStudentsMarksArithmeticMeanAfterSecondExamenationSeason());
}

TEST(GetGroupMarksArithmeticMeanAfterFirstExamenationSeason, TestCounting1) {
    StudentAfterFirstExaminationSeason st1("abc", 2, 2, {1, 2, 3, 5});
    StudentAfterFirstExaminationSeason st2("abc", 1, 1, {2, 2, 3, 4});
    StudentAfterFirstExaminationSeason st3("abc", 2, 2, {3, 2, 3, 4});
    StudentAfterFirstExaminationSeason st4("abc", 1, 1, {1, 2, 3, 5});
    StudentAfterFirstExaminationSeason st5("abc", 2, 2, {2, 2, 3, 4});
    ASSERT_EQ(StudentAfterFirstExaminationSeason::GetGroupMarksArithmeticMeanAfterFirstExamenationSeason(2),
              34.0 / 4 / 3);
}

TEST(GetGroupMarksArithmeticMeanAfterFirstExamenationSeason, TestCounting2) {
    StudentAfterFirstExaminationSeason st1("abc", 2, 5, {1, 2, 3, 5});
    StudentAfterFirstExaminationSeason st2("abc", 1, 5, {2, 2, 3, 4});
    StudentAfterFirstExaminationSeason st3("abc", 2, 4, {3, 2, 3, 4});
    StudentAfterFirstExaminationSeason st4("abc", 1, 5, {1, 2, 3, 5});
    StudentAfterFirstExaminationSeason st5("abc", 2, 5, {2, 2, 3, 4});
    StudentAfterFirstExaminationSeason st6("abc", 1, 7, {1, 2, 3, 5});
    StudentAfterFirstExaminationSeason st7("abc", 2, 2, {2, 2, 3, 4});
    ASSERT_EQ(StudentAfterFirstExaminationSeason::GetGroupMarksArithmeticMeanAfterFirstExamenationSeason(5),
              44.0 / 4 / 4);
}

TEST(GetGroupMarksArithmeticMeanAfterFirstExamenationSeason, TestIfNoGroup) {
    StudentAfterFirstExaminationSeason st1("abc", 1, 2, {1, 2, 3, 5});
    StudentAfterFirstExaminationSeason st2("abc", 4, 1, {2, 2, 3, 4});
    StudentAfterFirstExaminationSeason st3("abc", 2, 2, {3, 2, 3, 4});
    StudentAfterFirstExaminationSeason st4("abc", 4, 1, {1, 2, 3, 5});
    StudentAfterFirstExaminationSeason st5("abc", 1, 2, {2, 2, 3, 4});
    ASSERT_EQ(StudentAfterFirstExaminationSeason::GetGroupMarksArithmeticMeanAfterFirstExamenationSeason(7),
              -1);
}

TEST(GetGroupMarksArithmeticMeanAfterFirstExamenationSeason, TestIfNoStudent) {
    ASSERT_EQ(StudentAfterFirstExaminationSeason::GetGroupMarksArithmeticMeanAfterFirstExamenationSeason(7),
              -1);
}

TEST(GetGroupMarksArithmeticMeanAfterSecondExamenationSeason, TestCounting1) {
    StudentAfterSecondExaminationSeason st1("abc", 4, 2, {1, 2, 3, 5}, {3, 7, 1, 3, 7});
    StudentAfterSecondExaminationSeason st2("abc", 3, 11, {2, 2, 3, 4}, {6, 1, 3, 9, 5});
    StudentAfterSecondExaminationSeason st3("abc", 1, 2, {3, 2, 3, 4}, {1, 8, 2, 6, 1});
    StudentAfterSecondExaminationSeason st4("abc", 3, 9, {1, 2, 3, 5}, {1, 9, 3, 5, 1});
    StudentAfterSecondExaminationSeason st5("abc", 2, 2, {2, 2, 3, 4}, {7, 1, 3, 2, 8});
    ASSERT_EQ(StudentAfterSecondExaminationSeason::GetGroupMarksArithmeticMeanAfterSecondExamenationSeason(2),
              94.0 / 9 / 3);
}

TEST(GetGroupMarksArithmeticMeanAfterSecondExamenationSeason, TestCounting2) {
    StudentAfterSecondExaminationSeason st1("abc", 2, 5, {1, 2, 3, 5}, {3, 7, 1, 5, 2});
    StudentAfterSecondExaminationSeason st2("abc", 1, 5, {2, 2, 3, 4}, {9, 1, 6, 2, 3});
    StudentAfterSecondExaminationSeason st3("abc", 4, 11, {3, 2, 3, 4}, {7, 1, 2, 0, 5});
    StudentAfterSecondExaminationSeason st4("abc", 2, 5, {1, 2, 3, 5}, {1, 6, 2, 5, 4});
    StudentAfterSecondExaminationSeason st5("abc", 1, 5, {2, 2, 3, 4}, {7, 1, 0, 2, 3});
    StudentAfterSecondExaminationSeason st6("abc", 4, 7, {1, 2, 3, 5}, {7, 1, 4, 3, 2});
    StudentAfterSecondExaminationSeason st7("abc", 3, 2, {2, 2, 3, 4}, {9, 1, 2, 1, 6});
    ASSERT_EQ(StudentAfterSecondExaminationSeason::GetGroupMarksArithmeticMeanAfterSecondExamenationSeason(5),
              114.0 / 4 / 9);
}

TEST(GetGroupMarksArithmeticMeanAfterSecondExamenationSeason, TestIfNoGroup) {
    StudentAfterSecondExaminationSeason st1("abc", 2, 2, {1, 2, 3, 5}, {3, 5, 2, 1, 6});
    StudentAfterSecondExaminationSeason st2("abc", 3, 1, {2, 2, 3, 4}, {8, 1, 2, 6, 43});
    StudentAfterSecondExaminationSeason st3("abc", 1, 2, {3, 2, 3, 4}, {8, 1, 2, 6, 4});
    StudentAfterSecondExaminationSeason st4("abc", 4, 1, {1, 2, 3, 5}, {9, 1, 2, 1, 2});
    StudentAfterSecondExaminationSeason st5("abc", 2, 2, {2, 2, 3, 4}, {8, 4, 1, 1, 0});
    ASSERT_EQ(StudentAfterSecondExaminationSeason::GetGroupMarksArithmeticMeanAfterSecondExamenationSeason(7),
              -1);
}

TEST(GetGroupMarksArithmeticMeanAfterSecondExamenationSeason, TestIfNoStudent) {
    ASSERT_EQ(StudentAfterSecondExaminationSeason::GetGroupMarksArithmeticMeanAfterSecondExamenationSeason(7),
              -1);
}
