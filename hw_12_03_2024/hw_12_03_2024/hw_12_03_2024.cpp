using namespace std;
#include "Student.h"
#include "Date.h"
#include "Group.h"
#include "Fraction.h"

class Aspirant : public Student
{
private:
    string dissertationTopic;
public:
    Aspirant(string surname, string name, string patronymic, string adress, string phoneNumber, string dissertationTopic) : Student(surname, name, patronymic, adress, phoneNumber)
    {
        SetDissertationTopic(dissertationTopic);
    }

    void SetDissertationTopic(string dissertationTopic)
    {
        this->dissertationTopic = dissertationTopic;
    }

    string GetDissertationTopic()
    {
        return dissertationTopic;
    }

    void PrintStudent()
    {
        Student::PrintStudent();
        cout << "\nDissertation topic: " << GetDissertationTopic() << "\n";
    }
};

int operator - (const Date& dateNow, const Date& otherDate)
{
    int thisDays = dateNow.GetDay() + 31 * (dateNow.GetMonth() - 1);
    int otherDays = otherDate.GetDay() + 31 * (otherDate.GetMonth() - 1);

    thisDays += (dateNow.GetYear() % 4 == 0 && dateNow.GetMonth() > 2);
    otherDays += (otherDate.GetYear() % 4 == 0 && otherDate.GetMonth() > 2);

    thisDays += (dateNow.GetMonth() > 1);
    otherDays += (otherDate.GetMonth() > 1);

    thisDays += dateNow.GetMonth() / 2 + ((dateNow.GetMonth() % 2 == 0 && dateNow.GetMonth() > 7));
    otherDays += otherDate.GetMonth() / 2 + ((otherDate.GetMonth() % 2 == 0 && otherDate.GetMonth() > 7));

    thisDays += 365 * (dateNow.GetYear() - 1);
    otherDays += 365 * (otherDate.GetYear() - 1);

    return thisDays - otherDays;
}

//Student
bool operator > (const Student& a, const Student& b)
{
    return a.GetAverageGrade() > b.GetAverageGrade();
}

bool operator<(const Student& left, const Student& right)
{
    return left.GetAverageGrade() < right.GetAverageGrade();
}

bool operator >= (const Student& a, const Student& b)
{
    return a.GetAverageGrade() > b.GetAverageGrade();
}

bool operator <= (const Student& a, const Student& b)
{
    return a.GetAverageGrade() <= b.GetAverageGrade();
}

bool operator == (const Student& a, const Student& b)
{
    return a.GetAverageGrade() == b.GetAverageGrade();
}

bool operator != (const Student& a, const Student& b)
{
    return a.GetAverageGrade() != b.GetAverageGrade();
}

//Group
bool operator > (const Group& a, const  Group& b)
{
    return a.GetCountOfStudent() > b.GetCountOfStudent();
}

bool operator < (const Group& left, const Group& right)
{
    return left.GetCountOfStudent() < right.GetCountOfStudent();
}

bool operator >= (const Group& a, const  Group& b)
{
    return a.GetCountOfStudent() >= b.GetCountOfStudent();
}

bool operator <= (const Group& a, const  Group& b)
{
    return a.GetCountOfStudent() <= b.GetCountOfStudent();
}

bool operator == (const Group& a, const Group& b)
{
    return a.GetCountOfStudent() == b.GetCountOfStudent();
}

bool operator != (const Group& a, const Group& b)
{
    return a.GetCountOfStudent() != b.GetCountOfStudent();
}

//Student
istream& operator >> (const istream& i, Student& d)
{
    cout << "surname: ";
    string answear;
    cin >> answear;
    d.SetSurname(answear);

    cout << "name: ";
    cin >> answear;
    d.SetName(answear);

    cout << "middle name: ";
    cin >> answear;
    d.SetPatronymic(answear);

    cout << "adress: ";
    cin >> answear;
    d.SetAdress(answear);

    cout << "phonnumber: ";
    cin >> answear;
    d.SetPhoneNumber(answear);

    cout << "adress: ";
    cin >> answear;
    d.SetAdress(answear);

    return cin;
}

ostream& operator << (const ostream& i, Student& d)
{
    d.PrintStudent();
    d.PrintExam();
    d.PrintPractic();
    d.PrintHW();
    return cout;
}

istream& operator >> (const istream& i, Group& g)
{
    cout << "Group Name: ";
    string answear;
    cin >> answear;
    g.SetGroupName(answear);

    cout << "Group Specification: ";
    cin >> answear;
    g.SetSpecialization(answear);

    cout << "Course: ";
    unsigned short amswear2;
    cin >> amswear2;
    g.SetNumberOfCourse(amswear2);

    return cin;
}

ostream& operator << (const ostream& i, Group& d)
{
    d.PrintGroup();
    return cout;
}

istream& operator >> (const istream& i, Fraction& f)
{
    cout << "numerator: ";
    int answear;
    cin >> answear;
    f.SetNumerator(answear);

    cout << "denominator: ";
    cin >> answear;
    f.SetDenominator(answear);

    return cin;
}

ostream& operator << (const ostream& i, Fraction& f)
{
    //f.Print();
    return cout;
}

int main()
{
    Aspirant first("Shostak", "Yevhenii", "Stanislavovich", "111", "1111111111", "OOP");
    first.AddExam(12);
    first.AddPractic(12);
    first.AddHW(12);
    first.PrintStudent();
}