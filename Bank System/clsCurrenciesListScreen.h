#pragma once

#include "clsScreen.h"
#include "clsCurrency.h"
#include <iomanip>

class clsCurrenciesListScreen : protected clsScreen
{
	static void _PrintCurrencyRecordLine(clsCurrency Currency)
	{
		cout << setw(8) << left << "" << "| " << setw(30) << left << Currency.Country();
		cout << "| " << setw(8) << left << Currency.CurrencyCode();
		cout << "| " << setw(45) << left << Currency.CurrencyName();
		cout << "| " << setw(10) << left << Currency.Rate();
	}

public:
	static void ShowCurrenciesListScreen()
	{
		vector <clsCurrency> vCurrenies = clsCurrency::GetCurrenciesList();
		string Title = "\t  Currencies List Screen";
		string SubTitle = "\t    (" + to_string(vCurrenies.size()) + ") Currency.";

		_DrawScreenHeader(Title, SubTitle);
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_______________________________________________________\n" << endl;
		cout << setw(8) << left << "" << "| " << left << setw(20) << "Country";
		cout << "| " << left << setw(8) << "Code";
		cout << "| " << left << setw(45) << "Name";
		cout << "| " << left << setw(10) << "Rate";
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_______________________________________________________\n" << endl;

		if (vCurrenies.size() == 0)
			cout << "\t\t\t\tNo Currencies Available In The System!";
		else
			for (clsCurrency& C : vCurrenies)
			{
				_PrintCurrencyRecordLine(C);
				cout << endl;
			}
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_______________________________________________________\n" << endl;
	}
};

