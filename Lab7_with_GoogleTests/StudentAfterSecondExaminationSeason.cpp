//
// Created by yarov on 23.11.2021.
//
#include "StudentAfterSecondExaminationSeason.h"

vector<StudentAfterSecondExaminationSeason *>
        StudentAfterSecondExaminationSeason::AllStudentAfterSecondExaminationSeason = vector<StudentAfterSecondExaminationSeason *>();

StudentAfterSecondExaminationSeason::StudentAfterSecondExaminationSeason() {
}

void StudentAfterSecondExaminationSeason::CreateNewStudentAfterSecondExaminationSeason(
        StudentAfterSecondExaminationSeason *student_) {
    AllStudentAfterSecondExaminationSeason.push_back(student_);
}

StudentAfterSecondExaminationSeason *StudentAfterSecondExaminationSeason::FindStudent(long long id_) {
    for (auto i: StudentAfterSecondExaminationSeason::AllStudentAfterSecondExaminationSeason) {
        if (i->GetID() == id_) {
            return i;
        }
    }
    return nullptr;
}

StudentAfterSecondExaminationSeason::StudentAfterSecondExaminationSeason::StudentAfterSecondExaminationSeason(
        string name_, int course_, int group_,
        const initializer_list<int> &first_examination_season_marks_,
        const initializer_list<int> &second_examination_season_marks_) {
    name = name_;
    course = course_;
    group = group_;
    id = GenerateID();
    credit_card_number = GenerateCreditCardNumber();
    int j = 0;
    for (auto mark: first_examination_season_marks_) {
        first_examination_season_marks.at(j) = mark;
        j++;
    }
    j = 0;
    for (auto mark: second_examination_season_marks_) {
        second_examination_season_marks.at(j) = mark;
        j++;
    }
    CreateNewStudent(this);
    CreateNewStudentAfterFirstExaminationSeason(this);
    CreateNewStudentAfterSecondExaminationSeason(this);
}

vector<int> StudentAfterSecondExaminationSeason::GetSecondExaminationSeasonMarks() const {
    return second_examination_season_marks;
}

StudentAfterSecondExaminationSeason::StudentAfterSecondExaminationSeason(
        const StudentAfterSecondExaminationSeason &student_) {
    name = student_.GetName();
    course = student_.GetCourse();
    group = student_.GetGroup();
    id = GenerateID();
    credit_card_number = GenerateCreditCardNumber();
    first_examination_season_marks = student_.GetFirstExaminationSeasonMarks();
    second_examination_season_marks = student_.GetSecondExaminationSeasonMarks();
    CreateNewStudent(this);
    CreateNewStudentAfterFirstExaminationSeason(this);
    CreateNewStudentAfterSecondExaminationSeason(this);
}

double StudentAfterSecondExaminationSeason::AllMarksArithmeticMean() {
    double result = 0;
    for (auto i: first_examination_season_marks) {
        result += i;
    }
    for (auto i: second_examination_season_marks) {
        result += i;
    }
    return result /= number_of_marks_after_second_examination_season;
}

void StudentAfterSecondExaminationSeason::SetName(string name_) {
    StudentAfterFirstExaminationSeason::SetName(name_);
    FindStudent(id)->name = name_;
}

void StudentAfterSecondExaminationSeason::SetCourse(int course_) {
    StudentAfterFirstExaminationSeason::SetCourse(course_);
    FindStudent(id)->course = course_;
}

void StudentAfterSecondExaminationSeason::SetGroup(int group_) {
    StudentAfterFirstExaminationSeason::SetGroup(group_);
    FindStudent(id)->group = group_;
}

void StudentAfterSecondExaminationSeason::SetFirstExaminationSeasonMarks(vector<int> marks_) {
    StudentAfterFirstExaminationSeason::SetFirstExaminationSeasonMarks(marks_);
    FindStudent(id)->first_examination_season_marks = marks_;
}

void StudentAfterSecondExaminationSeason::SetSecondExaminationSeasonMarks(vector<int> marks_) {
    second_examination_season_marks = marks_;
    FindStudent(id)->second_examination_season_marks = marks_;
}

long long StudentAfterSecondExaminationSeason::NumberOfStudentsAfterSecondExaminationSeason() {
    return StudentAfterSecondExaminationSeason::AllStudentAfterSecondExaminationSeason.size();
}

vector<StudentAfterSecondExaminationSeason *>
StudentAfterSecondExaminationSeason::GetAllStudentAfterSecondExaminationSeason() {
    return AllStudentAfterSecondExaminationSeason;
}

double StudentAfterSecondExaminationSeason::GetAllStudentsMarksArithmeticMeanAfterSecondExamenationSeason() {
    double sum = 0;
    for (auto i: StudentAfterSecondExaminationSeason::AllStudentAfterSecondExaminationSeason) {
        sum += i->AllMarksArithmeticMean();
    }
    if (StudentAfterSecondExaminationSeason::NumberOfStudentsAfterSecondExaminationSeason() != 0) {
        return sum / StudentAfterSecondExaminationSeason::NumberOfStudentsAfterSecondExaminationSeason();
    } else return -1;
}

double StudentAfterSecondExaminationSeason::GetGroupMarksArithmeticMeanAfterSecondExamenationSeason(int group_) {
    double sum = 0;
    int n = 0;
    for (auto i: StudentAfterSecondExaminationSeason::AllStudentAfterSecondExaminationSeason) {
        if (i->GetGroup() == group_) {
            sum += i->AllMarksArithmeticMean();
            n++;
        }
    }
    if (n != 0) {
        return sum / n;
    } else {
        return -1;
    }
}

string StudentAfterSecondExaminationSeason::to_string() const {
    string s = "";
    s += "Name: ";
    s += name;
    s += '\n';
    s += "ID: " + std::to_string(id) + "\n";
    s += "Credit Card Number: " + std::to_string(credit_card_number) + "\n";
    s += "Course: " + std::to_string(course) + "\n";
    s += "Group " + std::to_string(group) + "\n";
    s += "Marks for first examination season: ";
    for (auto i: first_examination_season_marks) {
        s += std::to_string(i) + " ";
    }
    s += '\n';
    s += "Marks for second examination season: ";
    for (auto i: second_examination_season_marks) {
        s += std::to_string(i) + " ";
    }
    s += '\n';
    return s;
}

void StudentAfterSecondExaminationSeason::remove(long long id_) {
    for (int i = 0; i < AllStudentAfterSecondExaminationSeason.size(); i++) {
        if (AllStudentAfterSecondExaminationSeason[i]->GetID() == id_) {
            AllStudentAfterSecondExaminationSeason.erase(AllStudentAfterSecondExaminationSeason.begin() + i);
            break;
        }
    }
}

StudentAfterSecondExaminationSeason::~StudentAfterSecondExaminationSeason() {
    Student::remove(id);
    StudentAfterFirstExaminationSeason::remove(id);
    StudentAfterSecondExaminationSeason::remove(id);
}

