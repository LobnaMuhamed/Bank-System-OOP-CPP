#pragma once
#include <iostream>
#include "Global.h"
#include "clsDate.h"

using namespace std;

class clsScreen
{
protected:
	static void _DrawScreenHeader(string Title, string SubTitle = "")
	{
		cout << "\t\t\t\t\t______________________________________";
		cout << "\n\n\t\t\t\t\t   " << Title;
		if (SubTitle != "")
			cout << "\n\t\t\t\t\t   " << SubTitle;
		cout << "\n\t\t\t\t\t______________________________________\n\n";
		if (CurrentUser.UserName != "")
			cout << "\t\t\t\t\tUser: " << CurrentUser.UserName;
		cout << "\n\t\t\t\t\tDate: " << clsDate::DateToString(clsDate()) << "\n\n";
	}

	static bool CheckAccessRights(clsUser::enPermissions Permission)
	{
		if (!CurrentUser.CheckAccessPermission(Permission))
		{
			_DrawScreenHeader("Access Denied! Contact your Admin.");
			return false;
		}
		else
			return true;
	}
};

