//
// Created by yarov on 22.11.2021.
//
#pragma once

#include <iostream>
#include <vector>
#include <set>
#include <ctime>
#include <vector>
#include <string>

using std::vector;
using std::string;
using std::initializer_list;

class Student {
protected:
    static vector<Student *> AllStudents;
    long long id;
    int course;
    int group;
    long long credit_card_number;

    virtual double AllMarksArithmeticMean() {
        return 0;
    }

protected:
    long long GenerateID() const;

    virtual Student *FindStudent(long long id_);

    bool FindID(long long id_) const;

    bool FindCreditCardNumber(long long credit_card_number_) const;

    long long GenerateCreditCardNumber() const;

protected:
    static void CreateNewStudent(Student *student_);

    Student();

public:
    Student(int course_, int group_, long long id_, long long credit_card_number_) {
        course = course_;
        group = group_;
        id = id_;
        credit_card_number = credit_card_number_;
    }

public:
    Student(int course_, int group_);

    Student(const Student &student_);

    int GetCourse() const;

    int GetGroup() const;

    long long GetID() const;

    static vector<Student *> GetAllStudents();

    long long GetCreditCardNumber() const;

    static long long NumberOfStudents();

    virtual void SetCourse(int course_);

    virtual void SetGroup(int group_);

    virtual string to_string() const;
};
std :: ostream& operator<<(std :: ostream& os, const Student& st) {
    os << st.to_string();
    return os;
}