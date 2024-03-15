#pragma once
#include "Date.h"
#include "Group.h"
#include <iostream>
using namespace std;

class Fraction
{
	int numerator;
	int denominator;

public:
	friend Fraction operator + (const Fraction& left, const double right);
	friend Fraction operator + (const Fraction& left, const int right);
	friend Fraction operator + (const double left, const Fraction& right);
	friend Fraction operator + (const int left, const Fraction& right);

	Fraction();
	Fraction(int numerator, int denominator);
	Fraction(int value);

	double GetDecimal() const;

	void Print() const;
	void PrintDecimal() const;

	void SetNumerator(int numerator) {
		this->numerator = numerator;
	}
	void SetDenominator(int denominator) {
		if (denominator == 0) denominator = 1;
		this->denominator = denominator;
	}

	int GetNumerator() const
	{
		return numerator;
	}
	int GetDenominator() const
	{
		return denominator;
	}

	bool GreaterThan(const Fraction& another) const;
	bool LessThan(const Fraction& another) const;
	bool IsEquals(const Fraction& another) const;
};
