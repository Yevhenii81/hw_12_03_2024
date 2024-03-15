#pragma once
#include "Student.h"
#include <set>

class Group
{
private:
    unsigned short countStudent = 0;
    unsigned short numberOfCoure;
    set<Student> classmates;
    string groupName;
    string specialization;
public:
    Group();

    void PrintGroup();

    void AddStudent(const Student& newStudent);

    void WeanStudent(const Student& deleteStudent);

    void Expel();

    void SetCountOfStudent(int countStudent);
    void SetGroupName(string groupName);
    void SetSpecialization(string specialization);
    void SetNumberOfCourse(int numberOfCoure);

    int GetCountOfStudent() const;
    string GetGroupName() const;
    string GetSpecialization() const;
    int GetNumberOfCourse() const;

    Group& operator += (const Student& s)
    {
        AddStudent(s);
        return *this;
    }

    operator string ()
    {
        return groupName + "\n" + specialization + "\n" + to_string(numberOfCoure) + "\n" + to_string(countStudent);
    }
};