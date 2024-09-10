#pragma once
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "Global.h"

class clsTransferScreen : protected clsScreen
{
	static void _PrintClient(clsBankClient Client)
	{
		cout << "\nClient Card:";
		cout << "\n___________________\n";
		cout << "\nFull Name   : " << Client.FullName();
		cout << "\nAcc. Number : " << Client.AccountNumber();
		cout << "\nBalance     : " << Client.AccountBalance;
		cout << "\n___________________\n";
	}

	static string _ReadAccountNumber(string Message)
	{
		string AccountNumber = "";
		cout << Message;
		AccountNumber = clsInputValidate<string>::ReadString();
		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nClient With [" << AccountNumber << "] doesn't exist, Enter Another Account Number? \n";
			AccountNumber = clsInputValidate<string>::ReadString();
		}
		return AccountNumber;
	}
	static float _ReadAmount(clsBankClient SourceClient)
	{
		float Amount = 0;
		cout << "\nEnter Transfer Amount? ";

		Amount = clsInputValidate<float>::ReadNumber();
		while (Amount > SourceClient.AccountBalance)
		{
			cout << "Amount Exceeds the available Balance, Enter Another Amount? ";
			Amount = clsInputValidate<float>::ReadNumber();
		}
		return Amount;
	}
public:
	static void ShowTransferScreen()
	{
		_DrawScreenHeader("\t Transfer Screen");

		clsBankClient SourceClient = clsBankClient::Find(_ReadAccountNumber("Please Enter Account Number To Transfer From: "));
		_PrintClient(SourceClient);

		clsBankClient DestinationClient = clsBankClient::Find(_ReadAccountNumber("Please Enter Account Number To Transfer To: "));
		_PrintClient(DestinationClient);

		float Amount = _ReadAmount(SourceClient);

		cout << "Are you sure you want to perform this operation? y/n? ";
		char Answer = 'n';
		cin >> Answer;
		if (tolower(Answer) == 'y')
		{
			if (SourceClient.Transfer(Amount, DestinationClient, CurrentUser.UserName))
				cout << "\nTransfer done successfully\n";
			else
				cout << "\nTransfer Failed\n";

		}
		_PrintClient(SourceClient);
		_PrintClient(DestinationClient);
	}
};

