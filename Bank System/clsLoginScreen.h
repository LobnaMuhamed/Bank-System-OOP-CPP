#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include <iomanip>
#include "clsMainScreen.h"
#include "Global.h"


class clsLoginScreen : protected clsScreen
{
	static bool _Login()
	{
		bool LoginFailed = false;
		short Trails = 3;
		string Username, Password;
		do {
			if (LoginFailed)
			{
				cout << "\nInvalid Username/Password!\n";
				cout << "You have " << --Trails << " Trails to login.";
			}
			if (Trails == 0)
			{
				cout << "\n\nYou are Locked after 3 failed trials.";
				return false;
			}
			cout << "\nEnter Username? ";
			cin >> Username;

			cout << "Enter Passwrod? ";
			cin >> Password;

			CurrentUser = clsUser::Find(Username, Password);
			LoginFailed = CurrentUser.IsEmpty();

		} while (LoginFailed);

		CurrentUser.RegisterLogin();
		clsMainScreen::ShowMainMenu();
		return true;

	}

public:
	static bool ShowLoginScreen()
	{
		system("cls");
		_DrawScreenHeader("\t  Login Screen");
		return(_Login());
	}
};

