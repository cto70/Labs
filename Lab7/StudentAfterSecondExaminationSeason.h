//
// Created by yarov on 23.11.2021.
//
#pragma once

#include "StudentAfterFirstExaminationSeason.h"

class StudentAfterSecondExaminationSeason : public StudentAfterFirstExaminationSeason {
protected:
    const int number_of_marks_after_second_examination_season = 9;
    vector<int> second_examination_season_marks = {0, 0, 0, 0, 0};
    static vector<StudentAfterSecondExaminationSeason *> AllStudentAfterSecondExaminationSeason;
protected:
    StudentAfterSecondExaminationSeason();

    void CreateNewStudentAfterSecondExaminationSeason(StudentAfterSecondExaminationSeason *student_);

    virtual StudentAfterSecondExaminationSeason *FindStudent(long long id_);

public:
    StudentAfterSecondExaminationSeason(int course_, int group_,
                                        const initializer_list<int> &first_examination_season_marks_,
                                        const initializer_list<int> &second_examination_season_marks_);

    vector<int> GetSecondExaminationSeasonMarks() const;

    StudentAfterSecondExaminationSeason(const StudentAfterSecondExaminationSeason &student_);

    virtual double AllMarksArithmeticMean();

    virtual void SetCourse(int course_);

    virtual void SetGroup(int group_);

    virtual void SetFirstExaminationSeasonMarks(vector<int> marks_);

    void SetSecondExaminationSeasonMarks(vector<int> marks_);

    static long long NumberOfStudentsAfterSecondExaminationSeason();
    static vector<StudentAfterSecondExaminationSeason*> GetAllStudentAfterSecondExaminationSeason();
    static double GetAllStudentsMarksArithmeticMeanAfterSecondExamenationSeason();
    static double GetGroupMarksArithmeticMeanAfterSecondExamenationSeason(int group);
};