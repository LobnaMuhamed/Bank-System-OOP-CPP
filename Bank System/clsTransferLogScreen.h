#pragma once
#include "clsScreen.h"
#include "clsBankClient.h"

class clsTransferLogScreen : protected clsScreen
{
	static void _PrintTransferLogRecordLine(clsBankClient::stTransferLog TransferLogRecord)
	{
		cout << setw(8) << left << "" << "| " << setw(23) << left << TransferLogRecord.DateTime;
		cout << "| " << setw(8) << left << TransferLogRecord.SourceAccountNumber;
		cout << "| " << setw(8) << left << TransferLogRecord.DestinationAccountNumber;
		cout << "| " << setw(8) << left << TransferLogRecord.Amount;
		cout << "| " << setw(10) << left << TransferLogRecord.srcBalanceAfter;
		cout << "| " << setw(10) << left << TransferLogRecord.desBalanceAfter;
		cout << "| " << setw(8) << left << TransferLogRecord.UserName;
	}

public:
	static void ShowTransferLogScreen()
	{
		vector <clsBankClient::stTransferLog> vTransferLogRecord;
		vTransferLogRecord = clsBankClient::GetTransferLogList();
		string Title = "\tTransfer Log List Screen";
		string SubTitle = "(" + to_string(vTransferLogRecord.size()) + ") Record(s).";
		_DrawScreenHeader(Title, SubTitle);

		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		cout << setw(8) << left << "" << "| " << left << setw(23) << "Date/Time";
		cout << "| " << left << setw(8) << "s.Acct";
		cout << "| " << left << setw(8) << "d.Acct";
		cout << "| " << left << setw(8) << "Amount";
		cout << "| " << left << setw(10) << "s.Balance";
		cout << "| " << left << setw(10) << "d.Balance";
		cout << "| " << left << setw(8) << "User";
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		if (vTransferLogRecord.size() == 0)
			cout << "\nNo Transfer Log Available In The System!";
		else
		{
			for (clsBankClient::stTransferLog& T : vTransferLogRecord)
			{
				_PrintTransferLogRecordLine(T);
				cout << endl;
			}
		}
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;

	}
};

