//
// Created by yarov on 22.11.2021.
//
#include "Student.h"

vector<Student *> Student::AllStudents = vector<Student *>();

long long Student::GenerateID() const {
    long long n = rand() % 9000 + 1000;
    while (FindID(n)) {
        n = rand() % 9000 + 1000;
    }
    return n;
}

Student *Student::FindStudent(long long id_) {
    for (auto i: Student::AllStudents) {
        if (i->GetID() == id_) {
            return i;
        }
    }
    return nullptr;
}

bool Student::FindID(long long id_) const {
    for (auto student_: (Student::AllStudents)) {
        if ((*student_).GetID() == id_) {
            return true;
        }
    }
    return false;
}

bool Student::FindCreditCardNumber(long long credit_card_number_) const {
    for (auto student_: (Student::AllStudents)) {
        if ((*student_).GetCreditCardNumber() == credit_card_number_) {
            return true;
        }
    }
    return false;
}

long long Student::GenerateCreditCardNumber() const {
    long long n = rand() % 9000 + 1000;
    while (FindCreditCardNumber(n)) {
        n = rand() % 9000 + 1000;
    }
    return n;
}

Student::Student() {
}

void Student::CreateNewStudent(Student *student_) {
    Student::AllStudents.push_back(student_);
}

Student::Student(string name_, int course_, int group_) {
    name = name_;
    course = course_;
    group = group_;
    long long id_ = GenerateID();
    long long credit_card_number_ = GenerateCreditCardNumber();
    id = id_;
    credit_card_number = credit_card_number_;
    CreateNewStudent(this);
}

Student::Student(const Student &student_) {
    name = student_.GetName();
    course = student_.GetCourse();
    group = student_.GetGroup();
    id = GenerateID();
    credit_card_number = GenerateCreditCardNumber();
    CreateNewStudent(this);
}

int Student::GetCourse() const {
    return course;
}

string Student::GetName() const {
    return name;
}

int Student::GetGroup() const {
    return group;
}

long long Student::GetID() const {
    return id;
}

long long Student::GetCreditCardNumber() const {
    return credit_card_number;
}

long long Student::NumberOfStudents() {
    return Student::AllStudents.size();
}

void Student::SetName(string name_) {
    name = name_;
    Student::FindStudent(id)->name = name_;
}

void Student::SetCourse(int course_) {
    course = course_;
    Student::FindStudent(id)->course = course_;
}

void Student::SetGroup(int group_) {
    group = group_;
    Student::FindStudent(id)->group = group_;
}

vector<Student *> Student::GetAllStudents() {
    return AllStudents;
}

string Student::to_string() const {
    string s = "";
    s += "Name: ";
    s += name;
    s += '\n';
    s += "ID: " + std::to_string(id) + "\n";
    s += "Credit Card Number: " + std::to_string(credit_card_number) + "\n";
    s += "Course: " + std::to_string(course) + "\n";
    s += "Group " + std::to_string(group) + "\n";
    return s;
}

void Student::remove(long long id_) {
    for (int i = 0; i < AllStudents.size(); i++) {
        if (AllStudents[i]->GetID() == id_) {
            AllStudents.erase(AllStudents.begin() + i);
            break;
        }
    }
}

Student::~Student() {
    Student::remove(id);
}