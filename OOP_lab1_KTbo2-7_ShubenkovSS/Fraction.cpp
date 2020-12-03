#include "Fraction.h"

void Fraction::AddFraction(const Fraction& fr)
{
	if (!fr._numerator) return;
	_numerator = _numerator * fr._denominator + _denominator * fr._numerator;
	_denominator = _denominator * fr._denominator;
	ReductionFraction();
}

void Fraction::MultiplyFraction(const Fraction& fr)
{
	if (!fr._numerator)
	{
		_numerator = 0;
		_denominator = 1;
		return;
	}
	_numerator = _numerator * fr._numerator;
	_denominator = _denominator * fr._denominator;
	ReductionFraction();
}
void Fraction::SubtractFraction(Fraction fr)
{
	fr._numerator *= -1;
	AddFraction(fr);
}

void Fraction::DivisionFraction(Fraction fr)
{
	if (!fr._numerator)
	{
		throw std::exception("Division by zero");
	}
	std::swap(fr._numerator, fr._denominator);
	MultiplyFraction(fr);
}

void Fraction::ReductionFraction()
{
	if (_numerator == 0)
	{
		_denominator = 1;
		return;
	}
	//находим общий делитель
	int a = _numerator;
	int b = _denominator;
	while (b) {
		a %= b;
		std::swap(a, b);
	}
	a = abs(a);
	_numerator /= a;
	_denominator /= a;
}

Fraction Fraction::operator+ (const Fraction& fr)
{
	Fraction res = *this;
	res.AddFraction(fr);
	return res;
}

Fraction Fraction::operator* (const Fraction& fr)
{
	Fraction res = *this;
	res.MultiplyFraction(fr);
	return res;
}

Fraction Fraction::operator- (const Fraction& fr)
{
	Fraction res = *this;
	res.SubtractFraction(fr);
	return res;
}

Fraction Fraction::operator/ (const Fraction& fr)
{
	Fraction res = *this;
	res.DivisionFraction(fr);
	return res;
}

bool Fraction::operator> (const Fraction& fr)
{
	if (_numerator * fr._denominator > _denominator * fr._numerator)
		return true;
	return false;
}

bool Fraction::operator<= (const Fraction& fr)
{
	return !(*this > fr);
}

bool Fraction::operator< (const Fraction& fr)
{
	if (_numerator * fr._denominator < _denominator * fr._numerator)	
		return true;
	return false;
}

bool Fraction::operator>= (const Fraction& fr)
{
	return !(*this < fr);
}

bool Fraction::operator== (const Fraction& fr)
{
	if (_numerator * fr._denominator == _denominator * fr._numerator)
		return true;
	return false;
}

bool Fraction::operator!= (const Fraction& fr)
{
	return !(*this == fr);
}

void Fraction::CorrectedMinuses()
{
	if (_denominator < 0)
	{
		_numerator = -_numerator;
		_denominator = -_denominator;
	}
}
