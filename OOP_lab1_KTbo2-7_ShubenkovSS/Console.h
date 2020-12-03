#pragma once
#include <iostream>
#include "Fraction.h"
using namespace std;

class Console
{
public:
	void Run(); //������ �������

	~Console()
	{
		delete[] _results;
	}

private:
	Fraction* _results = nullptr; //������ ������
	int _numberFr = 0; //������ �������
	int _numberFrNow = 0; //���������� �����. � ���. ������
	int _menuItemNumber = -1; //����� ������ ����
	Fraction _first; //������ �����
	Fraction _second; //������ �����
	void SetNumFr(); //��������� ������� �������
	void Menu(); //����� �������� ����
	void PrintFr(const Fraction& fr); //����� �����
	void ChangeFr(Fraction& fr); //��������� �����
	void Input(int& Int); //����
	void SaveFr(const Fraction& fr); //���������� �����
	bool PrintArrayFr(); //����� ������� ������
	void Actions(); //���� �������� � �������
	void MenuActions(); //����� ����
	void LocationSaveFr(const Fraction& fr); //����� ����� ���. ��.
	void ComparisonFr(); //��������� ������
	Fraction& SelectFrArray(); //����� ����� �� �������
};