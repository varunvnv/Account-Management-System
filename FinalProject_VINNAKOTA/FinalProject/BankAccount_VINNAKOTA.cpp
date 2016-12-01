//NAME: NAGA VENKATA VARUN VINNAKOTA
//RUID: 164009240
//TITLE:FINAL PROJECT - BankAccount_VINNAKOTA.cpp
//Date of submission: 12/13/2015

#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
#include"ACCOUNT_VINNAKOTA.h"
#include"BankAccount_VINNAKOTA.h"

using namespace std;

void BankAccount::set_cashbalance(double newbalance) //Define function set_cashbalance()
{
	CASH_BALANCE = newbalance; //Update the value of CASH_BALANCE
}


void BankAccount::get_balance() //Define function get_cashbalance()
{
	//Display Result
	cout << "\n\nYou have $" << get_cashbalance() << " in your bank account";
}
double BankAccount::deposit_money() //Define function deposit_money()
{
	double deposit;
	//Prompt user to enter the amount of Deposit
	cout << "\n\nEnter the amount you want to deposit: ";
	cin >> deposit; //Read input
	set_cashbalance(get_cashbalance() + deposit);
	//Display result
	cout << "\n\nYou deposited $" << deposit << " in your account";
	cout << "\nYour cash balance is: $" << get_cashbalance();
	//Save the action in Bank_transaction_history.txt file
	ofstream bankhistory("Bank_transaction_history.txt", ios::app);
	bankhistory << "Deposit" << setw(20)  << deposit << setw(20)<<get_cashbalance() << setw(20) << get_date() << setw(20) << get_time()<<endl;
	return deposit; //return the value of deposit to update balance of stockaccount
}
double BankAccount::withdraw_money() //Define function withdraw_money()
{
	double amount;
	//Prompt user to enter the amount of withdrawal
	cout << "\n\nEnter the amount you want to withdraw: ";
	cin >> amount; //Read input
	if (amount > get_cashbalance())
	{
		//Display error message if desired amount of withdrawal is more than the available balance
		cout << "\n\nERROR: The amount you want to withdraw is more than your available balance";
		return 0;
	}
	else
	{
		//Display result
		set_cashbalance(get_cashbalance() - amount);
		cout << "\n\nYour cash balance after withdrawing $" << amount << " is: $" << get_cashbalance();
		//Save the action in Bank_transaction_history.txt file
		ofstream bankhistory("Bank_transaction_history.txt", ios::app);
		bankhistory << "Withdrawal" << setw(20)<<amount << setw(20) <<get_cashbalance()<<setw(20)<< get_date() << setw(20) << get_time()<<endl;
		return amount; //return the value of deposit to update balance of stockaccount
	}
}
void BankAccount::printout_history()  //Define function printout_history()
{
	string event,amount,balance,date,time;
	//Display results
	cout << "\nEVENT" << setw(20) << "AMOUNT" << setw(12) << "BALANCE" << setw(9) << "DATE" << setw(20) << "TIME" << endl;
	ifstream file("Bank_transaction_history.txt", ios::in); //Open file Bank_transaction_history.txt
	if (!file)
	{
		cout << "\n-----" << setw(20) << "------" << setw(12) << "-------" << setw(9) << "----" << setw(20) << "----";

	}
	else {
		while (true)
		{
			//Display the contents of file
			file >> event >> amount >> balance >> date >> time;
			if (file.eof())
				break;
			cout << event << setw(12) << amount << setw(15) << balance << setw(15) << date << setw(15) << time << endl;
		}
	}
}
void BankAccount::save_bank_info() //Define function save_bank_info()
{
	//Open file BankAccount_Info.txt to save the action
	ofstream bankinfo("BankAccount_Info.txt", ios::app);
	bankinfo <<"\n"<< get_cashbalance();
}
