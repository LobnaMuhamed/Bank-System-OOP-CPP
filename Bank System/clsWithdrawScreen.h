#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"


class clsWithdrawScreen : protected clsScreen
{
	static void _PrintClient(clsBankClient Client)
	{
		cout << "\nClient Card:";
		cout << "\n___________________";
		cout << "\nFirstName   : " << Client.FirstName;
		cout << "\nLastName    : " << Client.LastName;
		cout << "\nFull Name   : " << Client.FullName();
		cout << "\nEmail       : " << Client.Email;
		cout << "\nPhone       : " << Client.Phone;
		cout << "\nAcc. Number : " << Client.AccountNumber();
		cout << "\nPassword    : " << Client.PinCode;
		cout << "\nBalance     : " << Client.AccountBalance;
		cout << "\n___________________\n";
	}
	static string _ReadAccountNumber()
	{
		string AccountNumber = "";
		cout << "\nPlease Enter AccountNumber? ";
		cin >> AccountNumber;
		return AccountNumber;
	}

public:
	static void ShowWithdrawScreen()
	{
		_DrawScreenHeader("\t   Withdraw Screen");
		string AccountNumber = _ReadAccountNumber();

		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nClient With [" << AccountNumber << "] doesn't exist.\n";
			AccountNumber = _ReadAccountNumber();
		}
		clsBankClient Client1 = clsBankClient::Find(AccountNumber);
		_PrintClient(Client1);

		double Amount = 0;
		cout << "\nPlease Enter Withdraw Amount? ";
		Amount = clsInputValidate<double>::ReadNumber();

		cout << "\nAre you sure you want to perform this transaction? ";
		char Answer = 'n';
		cin >> Answer;

		if (Answer == 'Y' || Answer == 'y')
		{
			if (Client1.Withdraw(Amount))
			{
				cout << "\nAmount Withdraw Successfully.\n";
				cout << "\nNew Balance Is: " << Client1.AccountBalance;
			}
			else
			{
				cout << "\nCan't Withdraw, Insuffecient Balance!\n";
				cout << "\nAmount to Withdraw is: " << Amount;
				cout << "\nYour Balance is: " << Client1.AccountBalance;
			}
		}
		else
			cout << "\nOperation was cancelled.\n";
	}

};
