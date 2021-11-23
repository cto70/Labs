//
// Created by yarov on 22.11.2021.
//
#pragma once

#include "Student.h"

class StudentAfterFirstExaminationSeason : public Student {
protected:
    const int number_of_marks_after_first_examination_season = 4;
    vector<int> first_examination_season_marks = {0, 0, 0, 0};
    static vector<StudentAfterFirstExaminationSeason *> AllStudentsAfterFirstExaminationSeason;
protected:
    StudentAfterFirstExaminationSeason();

public:
    StudentAfterFirstExaminationSeason(string name_, int course_, int group_,
                                       const initializer_list<int> &first_examination_season_marks_);

    StudentAfterFirstExaminationSeason(const StudentAfterFirstExaminationSeason &student_);

protected:
    void CreateNewStudentAfterFirstExaminationSeason(StudentAfterFirstExaminationSeason *student_);

    StudentAfterFirstExaminationSeason *FindStudent(long long id_);

public:
    vector<int> GetFirstExaminationSeasonMarks() const;

public:
    virtual double AllMarksArithmeticMean() const;

    static double GetAllStudentsMarksArithmeticMeanAfterFirstExamenationSeason();

    static double GetGroupMarksArithmeticMeanAfterFirstExamenationSeason(int group);

    static long long NumberOfAllStudentsAfterFirstExaminationSeason();

public:
    virtual void SetName(string name_);

    virtual void SetCourse(int course_);

    virtual void SetGroup(int group_);

    virtual void SetFirstExaminationSeasonMarks(vector<int> marks_);

public:
    static vector<StudentAfterFirstExaminationSeason *> GetAllStudentAfterFirstExaminationSeason();

public:
    virtual string to_string() const;

    friend std::ostream &operator<<(std::ostream &os, const StudentAfterFirstExaminationSeason &st) {
        os << st.to_string();
        return os;
    }
};