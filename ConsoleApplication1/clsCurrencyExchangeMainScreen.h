#pragma once
#include<iostream>
#include<iomanip>
#include"clsInputValidate.h"

#include"clsScreen.h"
#include"clsCurrenciesListScreen.h"
#include"clsFindCurrencyScreen.h"
#include"clsUpdateRateCurrencyScreen.h"
#include"clsCurrencyCalculatorScreen.h"

class clsCurrencyExchangeMainScreen:protected clsScreen
{

	enum enCurrencyExchangeMenueOptions 
	{
		eListCurrencies = 1, eFindCurrency = 2,
		eUpdateRate = 3, eCurrencyCalculator = 4, eMainMenue=5
	};

	static short _ReadTransactionMenueOption()
	{
		cout << setw(37) << left << "" << "Choose what do you want to do ?[ 1 to 5]? ";
		short Choice = clsInputValidate::ReadIntNumberBetween(1, 5, "Enter Number between 1 to 5?");

		return Choice;
	}

	static void _GoBackToCurrencyExchangeMenue()
	{
		cout << setw(37) << left << "" << "\n\tPress any key to go back to Currencies Menue...\n";

		system("pause>0");

		ShowCurrencyExchangeMenue();
	}

	static void _ShowCurrenciesList()
	{
		clsCurrenciesListScreen::ShowCurrenciesListScreen();
	}

	static void _ShowFindCurrency()
	{
		clsFindCurrencyScreen::ShowFindCurrencyScreen();
	}

	static void _ShowUpdateRate()
	{
		clsUpdateRateCurrencyScreen::ShowUpdateCurrencyRateScreen();

	}

	static void _ShowCurrencyCalculator()
	{
		clsCurrencyCalculatorScreen::ShowCurrecncyCalculatorScreen();

	}


	static void _PerformCurrencyExchangeOption(enCurrencyExchangeMenueOptions MainCurrencyExchangeOption)
	{
		switch (MainCurrencyExchangeOption)
		{
		case enCurrencyExchangeMenueOptions::eListCurrencies:
		{
			system("cls");
			_ShowCurrenciesList();
			_GoBackToCurrencyExchangeMenue();
			break;
		}

		case enCurrencyExchangeMenueOptions::eFindCurrency:
		{
			system("cls");
			_ShowFindCurrency();
			_GoBackToCurrencyExchangeMenue();
			break;
		}

		case enCurrencyExchangeMenueOptions::eUpdateRate:
		{
			system("cls");
			_ShowUpdateRate();
			_GoBackToCurrencyExchangeMenue();
			break;
		}

		case enCurrencyExchangeMenueOptions::eCurrencyCalculator:
		{
			system("cls");
			_ShowCurrencyCalculator();
			_GoBackToCurrencyExchangeMenue();
			break;
		}

		
		case enCurrencyExchangeMenueOptions::eMainMenue:
		{
			// nothing do with this case just will go back to transactions screen
		}


		}
	}


public:

	static void ShowCurrencyExchangeMenue()
	{

		
		system("cls");
		_DrawScreenHeader("\tCurrency Exchange Main Menue");
		cout << setw(37) << left << "" << "============================================";
		cout << setw(37) << left << "" << "\t\t\t\t\t\t 	       Currency Exchange Menue\n";
		cout << setw(37) << left << "" << "============================================";
		cout << setw(37) << left << "" << "\t\t\t\t\t\t\t[1] List Currencies.\n";
		cout << setw(37) << left << "" << "\t[2] Find Currency.\n";
		cout << setw(37) << left << "" << "\t[3] Update Rate.\n";
		cout << setw(37) << left << "" << "\t[4] Currency Calculator.\n";
		cout << setw(37) << left << "" << "\t[5] MainMenue.\n";
		cout << setw(37) << left << "" << "============================================\n";

		_PerformCurrencyExchangeOption((enCurrencyExchangeMenueOptions)_ReadTransactionMenueOption());
	}

};

