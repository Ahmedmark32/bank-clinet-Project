#pragma once
#include<iostream>
#include<iomanip>
#include"clsInputValidate.h"

#include"clsScreen.h"
#include"clsDepositScreen.h"
#include"clsWithdrawScreen.h"
#include"clsTotalBalancesScreen.h"
#include"clsTransferScreen.h"
#include "clsTransferLogclsTransferLogScreen .h"

using namespace std;

class clsTransactionsScreen : protected clsScreen
{
private:

	enum enTransactionsMenueOptions{
		eDeposit=1, eWithdraw=2, 
	     eShowTotalBalance=3, eTransfer=4, eTransferLog = 5, eShowMainMenue=6};


	static short _ReadTransactionMenueOption()
	{
		cout << setw(37) << left << "" << "Choose what do you want to do ?[ 1 to 6]? ";
		short Choice = clsInputValidate::ReadIntNumberBetween(1, 6, "Enter Number between 1 to 6?");

		return Choice;
	}

	static void _GoBackToTransactionMenue()
	{
		cout << setw(37) << left << "" << "\n\tPress any key to go back to Transactions Menue...\n";

		system("pause>0");

		ShowTransactionsMenue();
	}

	static void _ShowDepositScreen()
	{
		clsDepositScreen::ShowDepositScreen();
	}

	static void _ShowWithdrawScreen()
	{
		clsWithdraw::ShowWithdrawScreen();
	}

	static void _ShowTotalBalanceScreen()
	{
		clsTotalBalancesScreen::ShowTotalBalances();

	}

	static void _ShowTransfer()
	{
		clsTransferScreen::ShowTansferScreen();

	}

	static void _ShowTransferLogScreen()
	{
		
		clsTransferLogScreen::ShowTransferLogScreen();

	}


	
	static void _PerformMainMenueOption(enTransactionsMenueOptions MainTransactionOption)
	{
		switch (MainTransactionOption)
		{
		case enTransactionsMenueOptions::eDeposit:
		{
			system("cls");
			_ShowDepositScreen();
			_GoBackToTransactionMenue();
			break;
		}

		case enTransactionsMenueOptions::eWithdraw:
		{
			system("cls");
			_ShowWithdrawScreen();
			_GoBackToTransactionMenue();
			break;
		}

		case enTransactionsMenueOptions::eShowTotalBalance:
		{
			system("cls");
			_ShowTotalBalanceScreen();
			_GoBackToTransactionMenue();
			break;
		}

		case enTransactionsMenueOptions::eTransfer:
		{
			system("cls");
			_ShowTransfer();
			_GoBackToTransactionMenue();
			break;
		}

		case enTransactionsMenueOptions::eTransferLog:
		{
			system("cls");
			_ShowTransferLogScreen();
			_GoBackToTransactionMenue();
			break;
		}
			
		case enTransactionsMenueOptions::eShowMainMenue:
		{
			// nothing do with this case just will go back to transactions screen
		}


		}
	}


public:

	 static void ShowTransactionsMenue()
	{

		 if (!CheckAccessRights(clsUser::enPermissions::pTransactions))
		 {
			 return;

		 }

		system("cls");
		_DrawScreenHeader("\t   Transactions Screen");
		cout << setw(37) << left << "" << "============================================";
		cout << setw(37) << left << "" << "\t\t\t\t\t\t 	       	   Transaction Menue\n";
		cout << setw(37) << left << "" << "============================================";
		cout << setw(37) << left << "" << "\t\t\t\t\t\t\t[1] Deposite.\n";
		cout << setw(37) << left << "" << "\t[2] Withdraw.\n";
		cout << setw(37) << left << "" << "\t[3] Total Balance.\n";
		cout << setw(37) << left << "" << "\t[4] Transfer.\n";
		cout << setw(37) << left << "" << "\t[5] Transfer Log.\n";
		cout << setw(37) << left << "" << "\t[6] Main Menue.\n";
		cout << setw(37) << left << "" << "============================================\n";

		_PerformMainMenueOption((enTransactionsMenueOptions)_ReadTransactionMenueOption());
	}

};

