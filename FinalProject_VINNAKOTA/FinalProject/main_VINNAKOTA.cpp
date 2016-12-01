//NAME: NAGA VENKATA VARUN VINNAKOTA
//RUID: 164009240
//TITLE:FINAL PROJECT - main_VINNAKOTA.cpp
//Date of submission: 12/13/2015

#include<iostream>
#include<fstream>
#include"ACCOUNT_VINNAKOTA.h"
#include"BankAccount_VINNAKOTA.h"
#include"StockAccount_VINNAKOTA.h"

using namespace std;

//start of main
int main()
{
	double ch, ch1, ch2, value; //Declare variables of type double
	int choice, st_choice, bk_choice; //Declare variables of type int
	BankAccount bankaccount; //Declare object bankaccount of class BankAccount 
	StockAccount stockaccount; //Declare object stockaccount of class StockAccount

restart: //Label to redsiplay menu
	//Display Menu
	cout << "\n\nWelcome to the Account Management System"; 
	cout << "\nPlease select an account to access:";
	cout << "\n1. Stock Portfolio Account\n2. Bank Account\n3. Exit\n Option:";
	cin >> ch; //Read input from user
	
    //Check if the user entered an invalid input
	if (ch < 1 || ch>3 || ch != (int)ch)
	{
		//Display error message on entering invalid input
		cout << "\n\nInvalid Input. Please select a valid option"; 
		goto restart;
	} //Proceed if entered valid input
	else
	{
		choice = (int)ch; 
		switch (choice) //Switch choice
		{
		case 1: //Define case 1
		{
		redisplay1: //Label to redisplay menu of Stock Portfolio Account
			//Display Menu of Stock Account
			cout << "\n\nStock Portfolio Account";
			cout << "\nPlease select an option:";
			cout << "\n1. Display the price for a stocksymbol";
			cout << "\n2. Display the current portfolio";
			cout << "\n3. Buy shares\n4. Sell shares\n5. View a graph for the portfolio value";
			cout << "\n6. View transaction history\n7. Sort the stock list\n8. Return to previous menu\nOption:";
			cin >> ch1; //Read input

			//Check if the user entered an invalid input
			if (ch1 < 1 || ch1>8 || ch1 != (int)ch1)
			{
				//Display an error message on entering invalid input
				cout << "\n\nInvalid Input. Please select a valid option";
			}
			else { //Proced if entered valid input
				st_choice = (int)ch1; 

				switch (st_choice) //Switch input
				{
				case 1: //Define case 1 of Stock Portfolio Account
				{
					stockaccount.price_of_stock(); //Call price_of_stock() function of class StockAccount
					goto redisplay1;
					break;
				}
				case 2: //Define case 2 of Stock Portfolio Account
				{
					stockaccount.current_portfolio(); //Call current_portfolio() function of class StockAccount
					goto redisplay1;
					break;
				}
				case 3: //Define case 3 of Stock Portfolio Account
				{
					//Call Buy_shares() function of class StockAccount
					value = stockaccount.Buy_shares(); 
					//Update the balance of BankAccount
					bankaccount.set_cashbalance(bankaccount.get_cashbalance() - value);
					goto redisplay1;
					break;
				}
				case 4: //Define case 4 of Stock Portfolio Account
				{
					//Call Sell_shares() function of class StockAccount
					value = stockaccount.Sell_shares(); 
					//Update the balance of BankAccount
					bankaccount.set_cashbalance(bankaccount.get_cashbalance() + value);
					goto redisplay1;
					break;
				}
				case 5: //Define case 5 of Stock Portfolio Account
				{
					stockaccount.view_a_graph(); //Call view_a_graph() function of class StockAccount
					goto redisplay1;
					break;
				}
				case 6: //Define case 6 of Stock Portfolio Account
				{
					//Call view_transaction_history() function of class StockAccount
					stockaccount.view_transaction_history(); 
					goto redisplay1;
					break;
				}
				case 7: //Define case 7 of Stock Portfolio Account
				{
					stockaccount.sort_stock_list(); //Call sort_stock_list() function of class StockAccount
					goto redisplay1;
					break;
				}
				case 8: //Define case 8 of Stock Portfolio Account
				{
					goto start1;
					break;
				}
			start1: goto restart;
				}
			}
			break;
		}
		case 2:
		{
		redisplay2: //Label to redisplay menu of Bank Account
			//Display Menu of Bank Account
			cout << "\n\nBank Account\nPlease select an option:";
			cout << "\n1. View account balance\n2. Deposit Money\n3. Withdraw money\n4. Print out history";
			cout << "\n5. Return to previous menu\nOption:";
			cin >> ch2; //Read input
			
			//Check if the user entered an invalid input
			if (ch2 < 1 || ch2>5 || ch2 != (int)ch2)
			{
				//Display error message if an invalid input is entered
				cout << "\n\nInvalid Input. Please select a valid option";
			}
			else //Proceed if valid input is entered
			{
				bk_choice = (int)ch2;

				switch (bk_choice) //Switch choice
				{
				case 1: //Define case 1 of Bank Account
				{
					bankaccount.get_balance(); //Call get_balance() function of class BankAccount
					goto redisplay2;
					break;
				}
				case 2: //Define case 2 of Bank Account
				{
					//Call deposit_money() function of class BankAccount
					value = bankaccount.deposit_money();
					//Update balance of StockAccount
					stockaccount.set_cashbalance(stockaccount.get_cashbalance() + value);
					goto redisplay2;
					break;
				}
				case 3: //Define case 3 of Bank Account
				{
					//Call withdraw_money() function of class BankAccount
					value = bankaccount.withdraw_money();
					//Update balance of StockAccount
					stockaccount.set_cashbalance(stockaccount.get_cashbalance() - value);
					goto redisplay2;
					break;
				}
				case 4: //Define case 4 of Bank Account
				{
					//Call printout_history() function of class BankAccount
					bankaccount.printout_history();
					goto redisplay2;
					break;
				}
			case 5: //Define case 5 of Bank Account
				{
					goto start2;
					break;
				}
				}
			start2:goto restart;
			}
			break;
		}
		case 3: //Define case 3
		{
			//Call functions to save information for future correspondence
			bankaccount.save_bank_info();
			stockaccount.save_stock_info();
			stockaccount.save_totalportfoliovalue();
			goto end;
			break;
		}
		}
	}
end:
	return 0; //Indicates succesful termination of program
} //End of main