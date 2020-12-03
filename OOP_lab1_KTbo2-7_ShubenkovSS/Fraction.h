#pragma once
#include <algorithm>

class Fraction {
public:
	int GetNumerator() const { return _numerator; } //��������� ���������
	int GetDenumerator() const { return _denominator; } //��������� �����������
	void SetFraction(const int& num, const int& den = 1) //��������� �����
	{
		if (den == 0)
		{
			throw std::exception("The denominator is zero");
		}
		_numerator = num;
		_denominator = den;
		CorrectedMinuses();
	}

	void AddFraction(const Fraction& fr); //����������� �����
	void MultiplyFraction(const Fraction& fr); //��������� �����
	void SubtractFraction(Fraction fr); //��������� �����
	void DivisionFraction(Fraction fr); //������� ������
	void ReductionFraction(); //���������� �����

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
	//������� ���������� ����������� ������ � "������������" ����
	//(����� ������ ������ � ���������)
	void CorrectedMinuses();
};