#pragma once

template <class T>
class clsInputValidate
{

public:
	static bool IsNumberBetween(T Number, T From, T To)
	{
		return (Number >= From && Number <= To);
	};

	static bool IsDateBetween(clsDate Date, clsDate From, clsDate To)
	{
		// Date >= From && Date <= To
		if ((clsDate::IsDate1AfterDate2(Date, From) || clsDate::IsDate1EqualToDate2(Date, From))
			&& (clsDate::IsDate1BeforeDate2(Date, To) || clsDate::IsDate1EqualToDate2(Date, To)))
			return true;
		// Date >= To && Date <= From
		if ((clsDate::IsDate1AfterDate2(Date, To) || clsDate::IsDate1EqualToDate2(Date, To))
			&& (clsDate::IsDate1BeforeDate2(Date, From) || clsDate::IsDate1EqualToDate2(Date, From))
			)
			return true;
		return false;
	}

	static T ReadNumber(string ErrorMessage = "Invalid Number, Enter again\n")
	{
		T Number = 0;
		while (!(cin >> Number))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << ErrorMessage;
		}
		return Number;
	}

	static T ReadNumberBetween(T From, T To, string ErrorMessage = "Number is not within range, Enter again:")
	{
		T Number = ReadNumber();

		while (!IsNumberBetween(Number, From, To))
		{
			cout << ErrorMessage;
			Number = ReadNumber();
		}
		return Number;
	}


	static bool IsValidateDate(clsDate Date)
	{
		return clsDate::IsValidDate(Date);
	};

	static string ReadString()
	{
		string S1 = "";
		getline(cin >> ws, S1);
		return S1;
	}
};

