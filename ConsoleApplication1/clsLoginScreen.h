#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include <iomanip>
#include "clsMainScreen.h"
#include "Global.h"



class clsLoginScreen :protected clsScreen
{
	static bool _Login()
	{

		bool LoginFaild = false;
		string UserName, Password;
		short FaildLoginCount = 0;

		do
		{
			
			if (LoginFaild)
			{
				
				FaildLoginCount++;
				cout << "\nInvlaid Username/Password!";
				cout << "\nYou have " << (3 - FaildLoginCount) << " Trials(s) to login\n\n";

			}

			if (FaildLoginCount == 3)
			{
				cout << "\nYour are Locked after 3 faild trails \n\n";
				return false;
			}


			cout << "Enter Username? ";
			cin >> UserName;

			cout << "Enter Password? ";
			cin >> Password;

			CurrentUser = clsUser::Find(UserName, Password);

			LoginFaild = CurrentUser.IsEmpty();

			

		} while (LoginFaild);

		
		CurrentUser.RegisterLogIn();
		clsMainScreen::ShowMainMenue();

		return true;
	}


public:
	static bool ShowLoginScreen()
	{
		system("cls");
		_DrawScreenHeader("\t    Login Screen");
		return _Login();

	}

};


