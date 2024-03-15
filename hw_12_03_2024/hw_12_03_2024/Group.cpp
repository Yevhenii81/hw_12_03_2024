#include "Group.h"
#include <set>
#include <algorithm>

Group::Group()
{
    SetGroupName("P26");
    SetNumberOfCourse(2);
    SetSpecialization("Software Delelopmer");
}

void Group::PrintGroup()
{
    cout << groupName << "\n";
    for (auto current : classmates)
    {
        current.PrintStudent();
        cout << "\naver grade: ";
        current.AverageGrade();
        cout << "\n";
    }
}

void Group::AddStudent(const Student& newStudent)
{
    countStudent++;
    classmates.insert(newStudent);
}

void Group::WeanStudent(const Student& deleteStudent)
{
    classmates.erase(deleteStudent);
    countStudent--;
}

void Group::Expel()
{
    if (countStudent == 0)
    {
        cout << "Group is empty\n\n";
        return;
    }
    auto minGradeStudent = classmates.begin();

    for (const auto& current : classmates)
    {
        if (current.GetAverageGrade() < minGradeStudent->GetAverageGrade())
        {
            minGradeStudent = classmates.find(current);
        }
    }

    WeanStudent(*minGradeStudent);
    cout << "The student with the lowest grade point average is dropped from the group\n\n";
}

void Group::SetCountOfStudent(int countStudent)
{
    this->countStudent = countStudent;
}

void Group::SetGroupName(string groupName)
{
    this->groupName = groupName;
}

void Group::SetSpecialization(string specialization)
{
    this->specialization = specialization;
}

void Group::SetNumberOfCourse(int numberOfCoure)
{
    this->numberOfCoure = numberOfCoure;
}

int Group::GetCountOfStudent() const
{
    return countStudent;
}

string Group::GetGroupName() const
{
    return groupName;
}

string Group::GetSpecialization() const
{
    return specialization;
}

int Group::GetNumberOfCourse() const
{
    return numberOfCoure;
}