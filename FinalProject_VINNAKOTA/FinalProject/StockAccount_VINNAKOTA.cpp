//NAME: NAGA VENKATA VARUN VINNAKOTA
//RUID: 164009240
//TITLE:FINAL PROJECT - StockAccount_VINNAKOTA.cpp
//Date of submission: 12/13/2015

#pragma comment( lib, "libmx.lib" )
#pragma comment( lib, "libmex.lib" )   
#pragma comment( lib, "libeng.lib" )

#include <yvals.h>
#if (_MSC_VER >= 1600)
#define __STDC_UTF_16__
#endif
#include "mex.h"
// end

#include<engine.h>
#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
#include"ACCOUNT_VINNAKOTA.h"
#include"StockAccount_VINNAKOTA.h"
#include"Node_VINNAKOTA.h"
#include"DoublyLinkedList_VINNAKOTA.h"
#include"BankAccount_VINNAKOTA.h"

using namespace std;

DoublyLinkedList doublylinkedlist; //Declare object doublylinkedlist of class DoublyLinkedList

void StockAccount::set_cashbalance(double newbalance) //Define function save_bank_info()
{
	CASH_BALANCE = newbalance; //Update variable CASH_BALANCE
}

StockAccount::StockAccount() //Define Constructor
{
	//Open file StockAccount_Info.txt
	ifstream file("StockAccount_Info.txt", ios::in);
	if (!file)
	{
		//If no file is present take no action
	}
	else
	{
		doublylinkedlist.initialize(); //Call initialize() function of DoublyLinkedList
	}
}

void StockAccount::price_of_stock() //Define price_of_stock()
{
	int found = 0;
	string name, date, symbol;
	double price;
	//Prompt for input
	cout << "\n\nPlease enter the stock symbol: ";
	cin >> symbol;
	ifstream file;
	
	//Randomly select a file
	srand(time(0));
	int number = rand();
	int num = number % 2;
	if (num == 1)
	{
		file.open("Results_1.txt");
	}
	else
	{
		file.open("Results_2.txt");
	}
	
	//Display Result
	for (int i = 0;i < 49;i++)
	{
		file >> name >> price >> date;
		if (name == symbol) //Search for input in files
		{
			cout << "\nCompany Symbol" << setw(20) << "Price per share" << endl;
			cout << symbol << setw(25) <<"$"<< price;
			found = 1;
		}
	}
	if (found == 0) //Display error message if entered symbol is not present
	{
		cout << "\nStock symbol is not present in the list";
	}
}
void StockAccount::current_portfolio() //Define function current_portfolio()
{
	//Display Result
	cout << "\nYour cash balance is: $" << get_cashbalance();
	doublylinkedlist.print(get_cashbalance()); //Call print() function of DoublyLinkedList
}
double StockAccount::Buy_shares() //Define function Buy_shares()
{
	string symbol;
	string name, date;
	double price, maxamount;
	int num, found = 0;
	//Prompt for input
	cout << "\nEnter the symbol of the stock you want to buy: ";
	cin >> symbol;
	cout << "\nEnter the number of shares you want to buy: ";
	cin >> num;
	cout << "\nEnter the maximum amount you are willing to pay per share: ";
	cin >> maxamount;
	ifstream file;
	//Randomly select a file
	srand(time(0));
	int number = rand();
	int no = number % 2;
	if (no == 1)
	{
		file.open("Results_1.txt");
	}
	else
	{
		file.open("Results_2.txt");
	}

	//Search for the symbol entered
	for (int i = 0;i < 49;i++)
	{
		file >> name >> price >> date;
		if (name == symbol)
		{
			if (price > maxamount)
			{
				//Display Error message if price value is more than the amount willing to spend
				cout << "\nTransaction Failed: The maximum amount you are willing to pay is less than the current share value";
				found = 1;
				return 0;
			}
			else if (num*price > get_cashbalance())
			{
				////Display Error message if no sufficient balance is present
				cout << "\nTransaction Failed: You do not have enough balance in your account";
				found = 1;
				return 0;
			}
			else
			{
				//Proceed if no errors
				Node *newptr = new Node(symbol, num);
				doublylinkedlist.insert(newptr); //Call insert() function of DoublyLinkedList
				found = 1;
				set_cashbalance(get_cashbalance() - num*price); //Update CASH_BALANCE
				cout << "\nYou bought " << num << " shares and your balance is: $" << get_cashbalance();
				
				//open file stock_transaction_history.txt
				ofstream stockhistory("stock_transaction_history.txt", ios::app);
				//Save action for future reference
				stockhistory << "BUY" << setw(10) << symbol << setw(10) << num << setw(10) << price << setw(10) << num*price << setw(10) << get_time()<<endl;
				ofstream bankhistory("Bank_transaction_history.txt", ios::app);
				bankhistory << "Withdrawal" << setw(20) << num*price << setw(20) << get_cashbalance() << setw(20) << get_date() << setw(20) << get_time() << endl;
				return num*price; //Return value to update balance of BankAccount
			}
		}
	}
	if (found == 0)
	{
		//Display Error message if symbol is not found
		cout << "\nThe symbol you entered is not found";
		return 0;
	}
}
double StockAccount::Sell_shares() //Define function Sell_shares()
{
	int found = 0;
	string symbol;
	string name, date;
	double price, minamount;
	int num;
	//Prompt for input
	cout << "\nEnter the symbol of the stock you want to sell: ";
	cin >> symbol;
	cout << "\nEnter the number of shares you want to sell: ";
	cin >> num;
	cout << "\nEnter the minimum amount you are willing to pay per share: ";
	cin >> minamount;
	//Randomly select a file
	ifstream file;
	srand(time(0));
	int number = rand();
	int no = number % 2;
	if (no == 1)
	{
		file.open("Results_1.txt");
	}
	else
	{
		file.open("Results_2.txt");
	}
	
	//Search for the symbol entered
	for (int i = 0;i < 49;i++)
	{
		file >> name >> price >> date;
		if (name == symbol)
		{
			found = 1;
			int value = doublylinkedlist.get_numofshares(symbol);
			
			 if (value == -1)
			{
				//Display Error message if shares of that symbol are not bought
				cout << "\nTransaction Failed: You have no shares of this symbol";
				return 0;
			}
			if (num>value)
			{
				//Display Error message if number of shares are greater than the number entered
				cout << "\nTransaction Failed: You do not have enough number of shares";
				return 0;
			}
			if (price < minamount)
			{
				//Display Error message if amount the user is willing to sell is more than the price
				cout << "\nTransaction Failed: The minimum amount you are willing to sell is greater than the current share value";
				return 0;
			}
			else
			{
				//Proceed if no errors
				Node *newptr = new Node(symbol, num);
				doublylinkedlist.remove(newptr); //Call remove() function of DoublyLinkedList
				set_cashbalance(get_cashbalance() + num*price); //Update CASH_BALANCE
				cout << "\nYou sold " << num << " shares and your balance is: " << get_cashbalance();

				//open file stock_transaction_history.txt
				ofstream stockhistory("stock_transaction_history.txt", ios::app);
				//Save action for future reference
				stockhistory << "SELL" << setw(10) << symbol << setw(10) << num << setw(10) << price << setw(10) << num*price << setw(10) << get_time()<<endl;
				ofstream bankhistory("Bank_transaction_history.txt", ios::app);
				bankhistory << "Deposit" << setw(20) << num*price << setw(20) << get_cashbalance() << setw(20) << get_date() << setw(20) << get_time() << endl;
				return num*price; //Return value to update balance of BankAccount
			}
		}
	}
	file.close();
	if (found == 0)
	{
		//Display Error message if symbol is not found
		cout << "\nTransaction Failed: The symbol you entered is not present in your stocks";
	}
}

void StockAccount::view_a_graph() //Define function view_a_graph()
{
	int n = 0;
	double balance, portfoliovalue;
	string date, time;
	double val[100] = { 0 };
	cout << "\nGraph of Total Portfolio values plotting in MATLAB...";
	//open file BankAccount_Info.txt
	ifstream file("BankAccount_Info.txt", ios::in);
	if (!file)
	{
		//If no file is present assign the current cashbalance
		val[0] = get_cashbalance();
		n = 1;
	}
	else { //Proceed if file is found
		while (true)
		{
			//Read data from file
			file >> balance >> portfoliovalue >> date >> time;
			val[n] = portfoliovalue;
			n++;
			if (file.eof())
				break;
		}
	}
	double *a = new double[n]; //Declare a new matrix of to hold values of c++ data
	for (int i = 0;i < n;i++)
	{
		a[i] = val[i]; //Assign values to matrix a
	}

	// creating a pointer to the engine
	Engine *ep;
	ep = engOpen(NULL);
	if (ep == NULL)
	{
		cout << "Error: Not Found." << endl;
		exit(1);
	}
	

	mxArray *A; //Create a pointer to array of matrix for MATLAB
    A = mxCreateDoubleMatrix(1, n, mxREAL); //Assign size to matrix of MATLAB
	memcpy((void *)mxGetPr(A), (void *)a, n*sizeof(double)); //copy the values of c++ matrix to MATLAB matrix
	engPutVariable(ep, "y", A);
	engEvalString(ep, "Y=y;");
	engEvalString(ep, "plot(Y);");	//call plot function
	engEvalString(ep, "xlabel('Time');"); //label x-axis
	engEvalString(ep, "ylabel('Portfolio Value');"); //label y-axis
	engEvalString(ep, "title('TOTAL PORTFOLIO VALUES');"); //Display title

	mxDestroyArray(A); //Destroy MATLAB matrix to free memory
}

void StockAccount::view_transaction_history() //Define function view_transaction_history()
{
	cout << "\nTransaction History:";
	string symbol, action, num, price, value, time;
	cout << "\nEVENT" << setw(20) << "CompSym" << setw(20) << "Number" << setw(20) << "PricePerSh" << setw(20) << "Totalvalue" << setw(14) << "Time"<<endl;
	//open file stock_transaction_history.txt
	ifstream file("stock_transaction_history.txt", ios::in);
	if (!file) 
	{
		//Display if no file is found
		cout << "\n-----" << setw(20) << "-------" << setw(20) << "------" << setw(20) << "----------" << setw(20) << "----------" << setw(20) << "----";
		
	}
	else { //Display results if file is found
		while (true)
		{
			//Read data from file
			file >> action >> symbol >> num >> price >> value >> time;
			if (file.eof())
				break;
			cout << action << setw(20) << symbol << setw(20) << num << setw(20) << price << setw(20) << value << setw(20) << time << endl;
		}
	}
}
void StockAccount::sort_stock_list() //Define function sort_stock_list()
{
	doublylinkedlist.sortlist(); //call function sortlist of class DoublyLinkedList
	doublylinkedlist.print(get_cashbalance()); //call function print() of class DoublyLinkedList
}
void StockAccount::save_stock_info() //Define function save_stock_info()
{
	if (doublylinkedlist.size != 0) //save information if any records are present
	{
		doublylinkedlist.save(); //call function save() of class DoublyLinkedList
	}
	else remove("StockAccount_Info.txt"); //If the list is empty delete the file
}

void StockAccount::save_totalportfoliovalue() //Define function save_totalportfoliovalue()
{
	doublylinkedlist.saveportfolio(get_cashbalance()); //call function saveportfolio() of class DoublyLinkedList
}
