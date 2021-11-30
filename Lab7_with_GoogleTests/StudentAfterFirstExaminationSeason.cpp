//
// Created by yarov on 22.11.2021.
//
#include "StudentAfterFirstExaminationSeason.h"

vector<StudentAfterFirstExaminationSeason *>
        StudentAfterFirstExaminationSeason::AllStudentsAfterFirstExaminationSeason = vector<StudentAfterFirstExaminationSeason *>();

StudentAfterFirstExaminationSeason::StudentAfterFirstExaminationSeason() {
}

void StudentAfterFirstExaminationSeason::CreateNewStudentAfterFirstExaminationSeason(
        StudentAfterFirstExaminationSeason *student_) {
    AllStudentsAfterFirstExaminationSeason.push_back(student_);
}

StudentAfterFirstExaminationSeason::StudentAfterFirstExaminationSeason(string name_, int course_, int group_,
                                                                       const initializer_list<int> &first_examination_season_marks_) {
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
    CreateNewStudent(this);
    CreateNewStudentAfterFirstExaminationSeason(this);
}

vector<int> StudentAfterFirstExaminationSeason::GetFirstExaminationSeasonMarks() const {
    return first_examination_season_marks;
}

StudentAfterFirstExaminationSeason::StudentAfterFirstExaminationSeason(
        const StudentAfterFirstExaminationSeason &student_) {
    name = student_.GetName();
    course = student_.GetCourse();
    group = student_.GetGroup();
    id = GenerateID();
    first_examination_season_marks = student_.GetFirstExaminationSeasonMarks();
    credit_card_number = GenerateCreditCardNumber();
    CreateNewStudent(this);
    CreateNewStudentAfterFirstExaminationSeason(this);
}

StudentAfterFirstExaminationSeason *StudentAfterFirstExaminationSeason::FindStudent(long long id_) {
    for (auto i: StudentAfterFirstExaminationSeason::AllStudentsAfterFirstExaminationSeason) {
        if (i->id == id_) {
            return i;
        }
    }
    return nullptr;
}

double StudentAfterFirstExaminationSeason::AllMarksArithmeticMean() const {
    double result = 0;
    for (auto i: first_examination_season_marks) {
        result += i;
    }
    return result / number_of_marks_after_first_examination_season;
}

long long StudentAfterFirstExaminationSeason::NumberOfAllStudentsAfterFirstExaminationSeason() {
    return AllStudentsAfterFirstExaminationSeason.size();
}

void StudentAfterFirstExaminationSeason::SetName(string name_) {
    Student::SetName(name_);
    StudentAfterFirstExaminationSeason::FindStudent(id)->name = name_;
}

void StudentAfterFirstExaminationSeason::SetCourse(int course_) {
    Student::SetCourse(course_);
    StudentAfterFirstExaminationSeason::FindStudent(id)->course = course_;
}

void StudentAfterFirstExaminationSeason::SetGroup(int group_) {
    Student::SetGroup(group_);
    StudentAfterFirstExaminationSeason::FindStudent(id)->group = group_;
}

void StudentAfterFirstExaminationSeason::SetFirstExaminationSeasonMarks(vector<int> marks_) {
    first_examination_season_marks = marks_;
    StudentAfterFirstExaminationSeason::FindStudent(id)->first_examination_season_marks = marks_;
}

vector<StudentAfterFirstExaminationSeason *>
StudentAfterFirstExaminationSeason::GetAllStudentAfterFirstExaminationSeason() {
    return AllStudentsAfterFirstExaminationSeason;
}

double StudentAfterFirstExaminationSeason::GetAllStudentsMarksArithmeticMeanAfterFirstExamenationSeason() {
    double sum = 0;
    for (auto i: StudentAfterFirstExaminationSeason::AllStudentsAfterFirstExaminationSeason) {
        sum += i->AllMarksArithmeticMean();
    }
    if (StudentAfterFirstExaminationSeason::NumberOfAllStudentsAfterFirstExaminationSeason() != 0) {
        return sum / StudentAfterFirstExaminationSeason::NumberOfAllStudentsAfterFirstExaminationSeason();
    } else return -1;
}

double StudentAfterFirstExaminationSeason::GetGroupMarksArithmeticMeanAfterFirstExamenationSeason(int group_) {
    double sum = 0;
    int n = 0;
    for (auto i: StudentAfterFirstExaminationSeason::AllStudentsAfterFirstExaminationSeason) {
        if (i->GetGroup() == group_) {
            sum += i->AllMarksArithmeticMean();
            n++;
        }
    }
    if (n != 0) {
        return sum / n;
    } else return -1;
}

string StudentAfterFirstExaminationSeason::to_string() const {
    string s = "";
    s += "Name: ";
    s += name;
    s += '\n';
    s += "ID: " + std::to_string(id) + "\n";
    s += "Credit Card Number: " + std::to_string(credit_card_number) + "\n";
    s += "Course: " + std::to_string(course) + "\n";
    s += "Group " + std::to_string(group) + "\n";
    s += "Marks for first session: ";
    for (auto i: first_examination_season_marks) {
        s += std::to_string(i) + " ";
    }
    s += '\n';
    return s;
}

void StudentAfterFirstExaminationSeason::remove(long long id_) {
    for (int i = 0; i < AllStudentsAfterFirstExaminationSeason.size(); i++) {
        if (AllStudentsAfterFirstExaminationSeason[i]->GetID() == id_) {
            AllStudentsAfterFirstExaminationSeason.erase(AllStudentsAfterFirstExaminationSeason.begin() + i);
            break;
        }
    }
}

StudentAfterFirstExaminationSeason::~StudentAfterFirstExaminationSeason() {
    Student::remove(id);
    StudentAfterFirstExaminationSeason::remove(id);
}