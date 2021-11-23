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
    string name;
    long long id;
    int course;
    int group;
    long long credit_card_number;
public:
    virtual double AllMarksArithmeticMean() {
        return 0;
    }

protected:
    long long GenerateID() const;

    long long GenerateCreditCardNumber() const;

    virtual Student *FindStudent(long long id_);

    bool FindID(long long id_) const;

    bool FindCreditCardNumber(long long credit_card_number_) const;

    static void CreateNewStudent(Student *student_);

protected:
    Student();

public:
    Student(string name_, int course_, int group_);

    Student(const Student &student_);

public:
    string GetName() const;

    int GetCourse() const;

    int GetGroup() const;

    long long GetID() const;

    long long GetCreditCardNumber() const;

    static vector<Student *> GetAllStudents();

public:
    static long long NumberOfStudents();

public:
    virtual void SetName(string name_);

    virtual void SetCourse(int course_);

    virtual void SetGroup(int group_);

public:

    virtual string to_string() const;

    friend std::ostream &operator<<(std::ostream &os, const Student &st) {
        os << st.to_string();
        return os;
    }

public:
    static char *Copy(const char *a);
};