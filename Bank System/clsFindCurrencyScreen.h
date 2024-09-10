#pragma once

#include "clsScreen.h"
#include "clsCurrency.h"
#include "clsInputValidate.h"

class clsFindCurrencyScreen : protected clsScreen
{

	static void _PrintCurrency(clsCurrency Currency)
	{
		cout << "\nCurrency Card:\n";
		cout << "_____________________________\n";
		cout << "\nCountry    : " << Currency.Country();
		cout << "\nCode       : " << Currency.CurrencyCode();
		cout << "\nName       : " << Currency.CurrencyName();
		cout << "\nRate(1$) = : " << Currency.Rate();

		cout << "\n_____________________________\n";
	}

	static void _ShowResults(clsCurrency Currency)
	{
		if (!Currency.IsEmpty())
		{
			cout << "\nCurrency Found :-)\n";
			_PrintCurrency(Currency);
		}
		else
		{
			cout << "\nCurrency Not Found :-(\n";
		}
	}

public:
	static void ShowFindCurrencyScreen()
	{
		_DrawScreenHeader("\t  Find Currency Screen");
		short Answer = 1;
		cin >> Answer;
		if (Answer == 1)
		{
			cout << "Please Enter Currency Code: ";
			string CurrencyCode = clsInputValidate<string>::ReadString();
			_ShowResults(clsCurrency::FindByCode(CurrencyCode));

		}
		else
		{
			cout << "Please Enter Country Name: ";
			string Country = clsInputValidate<string>::ReadString();
			_ShowResults(clsCurrency::FindByCountry(Country));
		}
	}

};

