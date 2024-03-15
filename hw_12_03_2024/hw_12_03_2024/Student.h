#pragma once
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Student {
    string surname;
    string name;
    string patronymic;
    string adress;
    string phoneNumber;
    int averGradeExam = 0;
    /*unsigned int countPractic = 0;
    unsigned int countHW = 0;
    unsigned int countExam = 0;*/
    vector<int> gradeOfPractic;
    vector<int> gradeOfHW;
    vector<int> gradeOfExam;

public:
    //Student(const Student& original);
    /// <summary>
    ///  Конструктор по умолчанию. Инициализирует объект Student без параметров
    /// </summary>
    Student();

    /// <summary>
    /// Конструктор с параметрами. Инициализирует объект Student с заданными значениями полей
    /// </summary>
    /// <param name="surname">Фамилия студента</param>
    /// <param name="name">Имя студента</param>
    /// <param name="patronymic">Отчество студента</param>
    /// <param name="adress">Адрес студента</param>
    /// <param name="phoneNumber">Номер телефона студента</param>
    Student(string surname, string name, string patronymic, string adress, string phoneNumber);

    /// <summary>
    /// Конструктор с параметрами. Инициализирует объект Student с заданными значениями полей,
    /// предоставляя значения по умолчанию для номера телефона
    /// </summary>
    /// <param name="surname">Фамилия студента</param>
    /// <param name="name">Имя студента</param>
    /// <param name="patronymic">Отчество студента</param>
    /// <param name="adress">Адрес студента</param>
    Student(string surname, string name, string patronymic, string adress);

    /// <summary>
   /// Деструктор. Освобождает выделенную динамическую память
   /// </summary>
    ~Student();

    /// <summary>
    /// Выводит информацию о студенте
    /// </summary>
    void PrintStudent() const;

    /// <summary>
    /// Устанавливает фамилию студента
    /// </summary>
    /// <param name="surname">Фамилия студента</param>
    void SetSurname(string surname);

    /// <summary>
    /// Устанавливает имя студента
    /// </summary>
    /// <param name="name">Имя студента</param>
    void SetName(string name);

    /// <summary>
    /// Устанавливает отчество студента
    /// </summary>
    /// <param name="patronymic">Отчество студента</param>
    void SetPatronymic(string patronymic);

    /// <summary>
    /// Устанавливает адрес студента
    /// </summary>
    /// <param name="adress">Адрес студента</param>
    void SetAdress(string adress);

    /// <summary>
   /// Устанавливает номер телефона студента
   /// </summary>
   /// <param name="phoneNumber">Номер телефона студента</param>
    void SetPhoneNumber(string phoneNumber);

    /// <summary>
    /// Получает фамилию студента
    /// </summary>
    /// <returns>Фамилия студента</returns>
    string GetSurname() const;

    /// <summary>
    /// Получает имя студента
    /// </summary>
    /// <returns>Имя студента</returns>
    string GetName() const;

    /// <summary>
    /// Получает отчество студента
    /// </summary>
    /// <returns>Отчество студента</returns>
    string GetPatronymic() const;

    /// <summary>
    /// Получает адрес студента
    /// </summary>
    /// <returns>Адрес студента</returns>
    string GetAdress() const;

    /// <summary>
    /// Получает номер телефона студента
    /// </summary>
    /// <returns>Номер телефона студента</returns>
    string GetPhoneNumber() const;

    /// <summary>
    /// Добавляет оценку за практику
    /// </summary>
    /// <param name="grade">Оценка за практику</param>
    void AddPractic(int grade);

    /// <summary>
    /// Выводит оценки за практику
    /// </summary>
    void PrintPractic() const;

    /// <summary>
    /// Получает оценку за практику по указанному индексу
    /// </summary>
    /// <param name="index">Индекс оценки за практику</param>
    /// <returns>Оценка за практику</returns>
    int GetPracticRates(unsigned int index) const;

    /// <summary>
    /// Добавляет оценку за домашние задания
    /// </summary>
    /// <param name="grade">Оценка за домашние задания</param>
    void AddHW(int grade);

    /// <summary>
    /// Выводит оценки за домашние задания
    /// </summary>
    void PrintHW() const;

    /// <summary>
    /// Получает оценку за домашние задания по указанному индексу
    /// </summary>
    /// <param name="index">Индекс оценки за домашние задания</param>
    /// <returns>Оценка за домашние задания</returns>
    int GetHWRates(unsigned int index) const;

    /// <summary>
    /// Добавляет оценку за экзамен
    /// </summary>
    /// <param name="grade">Оценка за экзамен</param>
    void AddExam(int grade);

    /// <summary>
    /// Выводит оценки за экзамены
    /// </summary>
    void PrintExam() const;

    /// <summary>
    /// Получает оценку за экзамен по указанному индексу
    /// </summary>
    /// <param name="index">Индекс оценки за экзамен</param>
    /// <returns>Оценка за экзамен</returns>
    int GetExamRates(unsigned int index) const;

    void AverageGrade();

    void SetAverageGrade(int averGradeExam);
    int GetAverageGrade() const;

    bool operator < (const Student& other) const
    {
        return this->GetSurname() < other.GetSurname();
    }

    operator string()
    {
        return surname + "\n" + name + "\n" + patronymic + "\n" + to_string(averGradeExam) + "\n" + phoneNumber;
    }
};