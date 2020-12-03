#pragma once
#include <algorithm>

class Fraction {
public:
	int GetNumerator() const { return _numerator; } //получение числителя
	int GetDenumerator() const { return _denominator; } //получение знаменателя
	void SetFraction(const int& num, const int& den = 1) //изменение дроби
	{
		if (den == 0)
		{
			throw std::exception("The denominator is zero");
		}
		_numerator = num;
		_denominator = den;
		CorrectedMinuses();
	}

	void AddFraction(const Fraction& fr); //прибавление дроби
	void MultiplyFraction(const Fraction& fr); //умножение дроби
	void SubtractFraction(Fraction fr); //вычитание дроби
	void DivisionFraction(Fraction fr); //деление дробей
	void ReductionFraction(); //сокращение дроби

	Fraction operator+ (const Fraction& fr);
	Fraction operator* (const Fraction& fr);
	Fraction operator- (const Fraction& fr);
	Fraction operator/ (const Fraction& fr);

	bool operator> (const Fraction& fr);
	bool operator<= (const Fraction& fr);
	bool operator< (const Fraction& fr);
	bool operator>= (const Fraction& fr);
	bool operator== (const Fraction& fr);
	bool operator!= (const Fraction& fr);

	Fraction() = default;
	Fraction(const int& num, const int& den = 1)
	{
		if (den == 0)
		{
			throw std::exception("The denominator is zero");
		}
		_numerator = num;
		_denominator = den;
		CorrectedMinuses();
	}

private:
	int _numerator = 0;
	int _denominator = 1;
	//функция приведения отрицальных дробей к "стандартному" виду
	//(минус всегда только в числителе)
	void CorrectedMinuses();
};