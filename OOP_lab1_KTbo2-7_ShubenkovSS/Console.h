#pragma once
#include <iostream>
#include "Fraction.h"
using namespace std;

class Console
{
public:
	void Run(); //запуск консоли

	~Console()
	{
		delete[] _results;
	}

private:
	Fraction* _results = nullptr; //массив дробей
	int _numberFr = 0; //размер массива
	int _numberFrNow = 0; //количество запис. в мас. дробей
	int _menuItemNumber = -1; //номер пункта меню
	Fraction _first; //первая дробь
	Fraction _second; //вторая дробь
	void SetNumFr(); //установка размера массива
	void Menu(); //вывод главного меню
	void PrintFr(const Fraction& fr); //вывод дроби
	void ChangeFr(Fraction& fr); //изменение дроби
	void Input(int& Int); //ввод
	void SaveFr(const Fraction& fr); //сохранение дроби
	bool PrintArrayFr(); //вывод массива дробей
	void Actions(); //меню действий с дробями
	void MenuActions(); //вывод меню
	void LocationSaveFr(const Fraction& fr); //выбор места сох. др.
	void ComparisonFr(); //сравнение дробей
	Fraction& SelectFrArray(); //выбор дроби из массива
};