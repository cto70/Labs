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

    void CreateNewStudentAfterFirstExaminationSeason(StudentAfterFirstExaminationSeason *student_);

    StudentAfterFirstExaminationSeason *FindStudent(long long id_);

public:
    StudentAfterFirstExaminationSeason(int course_, int group_,
                                       const initializer_list<int> &first_examination_season_marks_);

    vector<int> GetFirstExaminationSeasonMarks() const;

    StudentAfterFirstExaminationSeason(const StudentAfterFirstExaminationSeason &student_);

    virtual double AllMarksArithmeticMean() const;

    static long long NumberOfAllStudentsAfterFirstExaminationSeason();

    virtual void SetCourse(int course_);

    virtual void SetGroup(int group_);

    virtual void SetFirstExaminationSeasonMarks(vector<int> marks_);

    static vector<StudentAfterFirstExaminationSeason *> GetAllStudentAfterFirstExaminationSeason();
    static double GetAllStudentsMarksArithmeticMeanAfterFirstExamenationSeason();
    static double GetGroupMarksArithmeticMeanAfterFirstExamenationSeason(int group);
};