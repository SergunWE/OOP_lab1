#include "Console.h"

void Console::Run()
{
	SetNumFr();
	while (_menuItemNumber)
	{
		Menu();
		Input(_menuItemNumber);
		switch (_menuItemNumber)
		{
		case 1:
			ChangeFr(_first);
			break;
		case 2:
			ChangeFr(_second);
			break;
		case 3:
			Actions();
			break;
		case 4:
			SaveFr(_first);
			break;
		case 5:
			SaveFr(_second);
			break;
		case 6:
			(void)PrintArrayFr();
			break;
		case 7:
			SetNumFr();
			break;
		case 0:
			break;
		default:
			system("cls");
			cout << "Incorrect menu item number. Try again\n\n";
		}
	}
}

void Console::SetNumFr()
{
	delete[] _results;
	_numberFr = 0;
	system("cls");
	cout << "Enter the array's size to save fractions\n> ";
	while (_numberFr == 0)
	{
		Input(_numberFr);
		if (_numberFr != 0)
		{
			try
			{
				_results = new Fraction[_numberFr];
				_numberFrNow = 0;
				system("cls");
				cout << "An array of size " << _numberFr << " is created\n\n";
			}
			catch (bad_array_new_length)
			{
				if (_numberFr < 0)
				{
					cout << "Error. Enter a number greater than 0\n >";
				}
				else
				{
					cout << "Error. Array size is too big. Please enter a smaller size\n >";
				}
				_numberFr = 0;
			}
		}
		else
		{
			cout << "Enter a size greater than 0\n >";
		}
	}
}

inline void Console::Menu()
{
	cout << "1. Enter the first fraction\t= ";
	PrintFr(_first);
	cout << "\n2. Enter the second fraction\t= ";
	PrintFr(_second);
	cout << "\n3. Actions with a fraction\n";
	cout << "4. Save the first fraction\n";
	cout << "5. Save the second fraction\n";
	cout << "6. View saved fractions\n";
	cout << "7. Re-create an array of fractions\n";
	cout << "0. Complete the program\n> ";
}

void Console::PrintFr(const Fraction& fr)
{
	cout << fr.GetNumerator() << '/' << fr.GetDenumerator();
}

void Console::ChangeFr(Fraction& fr)
{
	int num = 0, den = 1;
	system("cls");
	
	_menuItemNumber = -1;
	while (_menuItemNumber != 1 && _menuItemNumber != 2)
	{
		cout << "1. Select a fraction from the array\n";
		cout << "2. Create a new fraction\n> ";
		Input(_menuItemNumber);
		switch (_menuItemNumber)
		{
		case 1:
			if (PrintArrayFr())
			{
				fr = SelectFrArray();
				system("cls");
			}
			break;
		case 2:
			cout << "Enter numerator\n> ";
			Input(num);
			cout << "Enter denumerator\n> ";
			Input(den);
			system("cls");
			try
			{
				fr.SetFraction(num, den);
				fr.ReductionFraction();
				system("cls");
			}
			catch (exception er)
			{
				cout << "Error. " << er.what() << ". Try again\n\n";
				_menuItemNumber = 0;
			}
			break;
		default:
			system("cls");
			cout << "Incorrect menu item number. Try again\n\n";
			break;
		}

	}
}

void Console::Input(int& Int)
{
	cin >> Int;
	if (cin.fail())
	{
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
}

void Console::SaveFr(const Fraction& fr)
{
	system("cls");
	if (_numberFrNow == _numberFr)
	{
		_results[_numberFr - 1] = fr;
		cout << "Attention. The array is full. The answer will overwrite the last answer. Re-create the array\n\n";
		return;
	}
	_results[_numberFrNow] = fr;
	_numberFrNow++;
}

bool Console::PrintArrayFr()
{
	system("cls");
	if (_numberFrNow == 0)
	{
		cout << "The array is empty\n\n";
		return false;
	}
	for (int i = 0; i < _numberFrNow; i++)
	{
		cout << i + 1 << ") ";
		PrintFr(_results[i]);
		cout << '\n';
	}
	cout << '\n';
	return true;
}

inline void Console::Actions()
{
	system("cls");
	_menuItemNumber = 0;
	Fraction res;
	while (!_menuItemNumber)
	{
		MenuActions();
		Input(_menuItemNumber);
		switch (_menuItemNumber)
		{
		case 1:
			res = _first + _second;
			break;
		case 2:
			res = _first - _second;
			break;
		case 3:
			res = _first * _second;
			break;
		case 4:
			try
			{
				res = _first / _second;
			}
			catch (exception er)
			{
				system("cls");
				cout << "Error. " << er.what() << ".\n\n";
				_menuItemNumber = 5;
			}
			break;
		case 5:
			ComparisonFr();
			break;
		default:
			system("cls");
			cout << "Incorrect menu item number. Try again\n\n";
			_menuItemNumber = 0;
			break;
		}
	}
	if (_menuItemNumber < 5)
	{
		LocationSaveFr(res);
		system("cls");
	}
}

inline void Console::MenuActions()
{
	cout << "1. Add fractions\n";
	cout << "2. Subtract fractions\n";
	cout << "3. Multiply fractions\n";
	cout << "4. Divide fractions\n";
	cout << "5. Compare fractions\n> ";
}

void Console::LocationSaveFr(const Fraction& fr)
{
	_menuItemNumber = 0;
	cout << "\nResult = ";
	PrintFr(fr);
	cout << "\n\n1. Save the result in the first fraction\n";
	cout << "2. Save the result to an array\n> ";
	while (_menuItemNumber != 1 && _menuItemNumber != 2)
	{
		Input(_menuItemNumber);
		switch (_menuItemNumber)
		{
		case 1:
			_first = fr;
			break;
		case 2:
			SaveFr(fr);
			break;
		default:
			cout << "Incorrect menu item number. Try again\n> ";
			break;
		}
	}
}

inline void Console::ComparisonFr()
{
	bool comparison = true;
	system("cls");
	_menuItemNumber = 0;
	cout << "1. Compare the first fraction with the second\n";
	cout << "2. Compare the first fraction with element from array of fractions\n";
	cout << "3. Compare the second fraction with element from array of fractions\n> ";
	Fraction fr1, fr2;
	while (_menuItemNumber < 1 || _menuItemNumber > 3)
	{
		Input(_menuItemNumber);
		switch (_menuItemNumber)
		{
		case 1:
			fr1 = _first;
			fr2 = _second;
			break;
		case 2:
			if (PrintArrayFr())
			{
				fr1 = _first;
				fr2 = SelectFrArray();
			}
			else
			{
				comparison = false;
			}
			break;
		case 3:
			if (PrintArrayFr())
			{
				fr1 = _second;
				fr2 = SelectFrArray();
			}
			else
			{
				comparison = false;
			}
			break;
		default:
			cout << "Incorrect number. Try again\n> ";
			break;
		}
	}
	
	if (comparison)
	{
		cout << '\n';
		PrintFr(fr1);
		if (fr1 == fr2)
		{
			cout << " = ";
		}
		else
			if (fr1 > fr2) cout << " > ";
			else cout << " < ";
		PrintFr(fr2);
		cout << "\n\n5. Exit to the main menu\n";
		cout << "0. Exit to the actions menu\n> ";
		_menuItemNumber = -1;
		while (_menuItemNumber != 5 && _menuItemNumber != 0)
		{
			Input(_menuItemNumber);
			switch (_menuItemNumber)
			{
			case 5:
			case 0:
				system("cls");
				break;
			default:
				cout << "Incorrect menu item number. Try again\n> ";
				break;
			}
		}
	}
	else
	{
		_menuItemNumber = 5;
	}
}

Fraction& Console::SelectFrArray()
{
	int number = 0;
	cout << "Select a fraction\n> ";
	while (!number)
	{
		Input(number);
		if (number < 0 && number > _numberFrNow)
		{
			number = 0;
			cout << "Incorrect number. Try again\n> ";
		}
	}
	return _results[number - 1];
}