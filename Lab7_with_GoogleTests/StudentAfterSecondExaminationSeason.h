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

protected:

    void CreateNewStudentAfterSecondExaminationSeason(StudentAfterSecondExaminationSeason *student_);

    virtual StudentAfterSecondExaminationSeason *FindStudent(long long id_);

    virtual void remove(long long id_);

public:
    StudentAfterSecondExaminationSeason(string name_, int course_, int group_,
                                        const initializer_list<int> &first_examination_season_marks_,
                                        const initializer_list<int> &second_examination_season_marks_);

    StudentAfterSecondExaminationSeason(const StudentAfterSecondExaminationSeason &student_);

    ~StudentAfterSecondExaminationSeason();


public:
    virtual void SetCourse(int course_);

    virtual void SetGroup(int group_);

    virtual void SetName(string name_);

    virtual void SetFirstExaminationSeasonMarks(vector<int> marks_);

    void SetSecondExaminationSeasonMarks(vector<int> marks_);

    static vector<StudentAfterSecondExaminationSeason *> GetAllStudentAfterSecondExaminationSeason();

    vector<int> GetSecondExaminationSeasonMarks() const;

public:
    virtual double AllMarksArithmeticMean();

    static double GetAllStudentsMarksArithmeticMeanAfterSecondExamenationSeason();

    static double GetGroupMarksArithmeticMeanAfterSecondExamenationSeason(int group);

public:
    static long long NumberOfStudentsAfterSecondExaminationSeason();

public:
    virtual string to_string() const;

    friend std::ostream &operator<<(std::ostream &os, const StudentAfterSecondExaminationSeason &st) {
        os << st.to_string();
        return os;
    }
};