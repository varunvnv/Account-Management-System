//NAME: NAGA VENKATA VARUN VINNAKOTA
//RUID: 164009240
//TITLE:FINAL PROJECT - ACCOUNT_VINNAKOTA.h
//Date of submission: 12/13/2015


//Define abstract base class ACCOUNT
#ifndef ACCOUNT_H
#define ACCOUNT_H
#include<iostream>
#include<fstream>
#include<ctime>
#include<time.h>
#include<string>

using namespace std;

class ACCOUNT
{
	//Declare protected class members
protected:
	double CASH_BALANCE;
//Declare public class members
public:
	
	 //Declare variable CASH_BALANCE of type double

	ACCOUNT() //Define Constructor of class ACCOUNT
	{
		//Open the file BankAccount_Info.txt in input mode
		ifstream account("BankAccount_Info.txt", ios::in); 
		//Define constructor if no such file is present
		if (!account)
		{
			CASH_BALANCE = 10000; //Set CASH_BALANCE=10000
		}
		else //Proceed if file is present
		{
			string date, time; //Declare variables of type string
			double balance,portfoliovalue; //Declare variables of type double
			while (true) //While condition to read data from file
			{
				account >> balance >> portfoliovalue >> date >> time; //Read values from file
				CASH_BALANCE = balance; //Initialize CASH_BALANCE value
				if (account.eof()) //Break if end of file is reached
					break;
			}
		}
	}
    
	//Declare a pure virtual function to make an abstract class
	virtual void set_cashbalance(double) = 0; 

	 double get_cashbalance() //Define function get_cashblance()
	 {
		 return CASH_BALANCE; //Return the value of CASH_BALANCE
	 }
	
	 string get_time() //Define function get_time()
	{
		time_t seconds;
		seconds = time(NULL);
		tm * timeinfo;
		timeinfo = localtime(&seconds);
		string hour = to_string(timeinfo->tm_hour);
		string minute = to_string(timeinfo->tm_min);
		string second = to_string(timeinfo->tm_sec);
		string time = hour + ":" + minute + ":" + second;
		return time; //Return time of type string
	}
	string get_date() //Define function get_date()
	{
		time_t seconds;
		seconds = time(NULL);
		tm * timeinfo;
		timeinfo = localtime(&seconds);
		string month = to_string(timeinfo->tm_mon + 1);
		string day = to_string(timeinfo->tm_mday);
		string year = to_string(timeinfo->tm_year + 1900);
		string date = month + "/" + day + "/" + year;
		return date; //Return date of type string
	}
};

#endif