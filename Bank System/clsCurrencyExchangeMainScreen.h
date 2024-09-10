#pragma once

#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsCurrenciesListScreen.h";
#include "clsFindCurrencyScreen.h"
#include "clsUpdateCurrencyRateScreen.h"
#include "clsCurrencyCalculatorScreen.h"
#include <iomanip>

class clsCurrencyExchangeMainScreen : protected clsScreen
{
	enum enCurrencMainMenueOptions {
		eListCurrencies = 1,
		eFindCurrency = 2,
		eUpdateCuurrencyRate = 3,
		eCurrencyCalculator = 4,
		eMainMenue = 5
	};
	static short _ReadCurrenciesMainMenuOptions()
	{
		cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 5]? ";
		short Choice = clsInputValidate<short>::ReadNumberBetween(1, 5, "Enter Number Between 1 to 5? ");
		return Choice;
	}
	static void _GoBackToCurrenciesMenue()
	{
		cout << "\n\nPress any key to go back to Currency Menue...";
		system("pause>0");
		ShowCurrenciesMenue();
	}
	static void _ShowListCurrenciesScreen()
	{
		clsCurrenciesListScreen::ShowCurrenciesListScreen();
	}
	static void _ShowFindCurrencyScreen()
	{
		clsFindCurrencyScreen::ShowFindCurrencyScreen();
	}
	static void _ShowUpdateRateScreen()
	{
		clsUpdateCurrencyRateScreen::ShowUpdateCurrencyRateScreen();
	}
	static void _ShowCurrencyCalculatorScreen()
	{
		clsCurrencyCalculatorScreen::ShowCurrencyCalculatorScreen();
	}

	static void _PerformCurrenciesMainMenueOptions(enCurrencMainMenueOptions CurrencMainMenueOption)
	{
		switch (CurrencMainMenueOption)
		{
		case enCurrencMainMenueOptions::eListCurrencies:
			system("cls");
			_ShowListCurrenciesScreen();
			_GoBackToCurrenciesMenue();
			break;
		case enCurrencMainMenueOptions::eFindCurrency:
			system("cls");
			_ShowFindCurrencyScreen();
			_GoBackToCurrenciesMenue();
			break;
		case enCurrencMainMenueOptions::eUpdateCuurrencyRate:
			system("cls");
			_ShowUpdateRateScreen();
			_GoBackToCurrenciesMenue();
			break;
		case enCurrencMainMenueOptions::eCurrencyCalculator:
			system("cls");
			_ShowCurrencyCalculatorScreen();
			_GoBackToCurrenciesMenue();
			break;
		case enCurrencMainMenueOptions::eMainMenue:
		{
		}
		}
	}
public:


	static void ShowCurrenciesMenue()
	{
		system("cls");
		_DrawScreenHeader("\t\tCurrency Exchange Main Screen");

		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\tCurrency Exchange Menue\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] List Currencies.\n";
		cout << setw(37) << left << "" << "\t[2] Find Currency.\n";
		cout << setw(37) << left << "" << "\t[3] Update Rate.\n";
		cout << setw(37) << left << "" << "\t[4] Currency Calculator.\n";
		cout << setw(37) << left << "" << "\t[5] Main Menu.\n";
		cout << setw(37) << left << "" << "===========================================\n";
		_PerformCurrenciesMainMenueOptions((enCurrencMainMenueOptions)_ReadCurrenciesMainMenuOptions());
	}
};

