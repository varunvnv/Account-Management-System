//NAME: NAGA VENKATA VARUN VINNAKOTA
//RUID: 164009240
//TITLE:FINAL PROJECT - BankAccount_VINNAKOTA.h
//Date of submission: 12/13/2015

#include"ACCOUNT_VINNAKOTA.h"
#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

//Define class BankAccount which is derived class of base class ACCOUNT
class BankAccount :public ACCOUNT 
{
public:
	//declare public data members
	void get_balance();
	double deposit_money();
	double withdraw_money();
	void printout_history();
	void save_bank_info();
	void set_cashbalance(double);
};

#endif