//NAME: NAGA VENKATA VARUN VINNAKOTA
//RUID: 164009240
//TITLE:FINAL PROJECT - StockAccount_VINNAKOTA.h
//Date of submission: 12/13/2015

#include"ACCOUNT_VINNAKOTA.h"
#include"BankAccount_VINNAKOTA.h"

#ifndef STOCKACCOUNT_H
#define STOCKACCOUNT_H

//Define class StockAccount which is derived class of base class ACCOUNT
class StockAccount : public ACCOUNT
{
public:
	//declare public data members
	StockAccount();
	void price_of_stock();
	void current_portfolio();
	double Buy_shares();
	double Sell_shares();
	void view_a_graph();
	void view_transaction_history();
	void sort_stock_list();
	void save_stock_info();
	void set_cashbalance(double);
	void save_totalportfoliovalue();
};

#endif