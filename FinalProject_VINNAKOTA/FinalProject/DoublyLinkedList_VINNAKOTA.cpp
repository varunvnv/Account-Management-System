//NAME: NAGA VENKATA VARUN VINNAKOTA
//RUID: 164009240
//TITLE:FINAL PROJECT - DoublyLinkedList_VINNAKOTA.cpp
//Date of submission: 12/13/2015

#include<iostream>
#include"DoublyLinkedList_VINNAKOTA.h"
#include"Node_VINNAKOTA.h"
#include"ACCOUNT_VINNAKOTA.h"
#include<string>
#include<iomanip>
#include<fstream>

using namespace std;

DoublyLinkedList::DoublyLinkedList() //Define Constructor
{
	//Initialize private data members
	firstptr = NULL;
	lastptr = NULL;
	size = 0;
}
void DoublyLinkedList::insert(Node *newptr) //Define function insert()
{
	Node *tempptr1 = NULL;
	int found = 0;
	tempptr1 = firstptr;
	if (firstptr != NULL)
	{
		//If the symbol bought is already in the list add the number of shares
		if (firstptr->stocksymbol == newptr->stocksymbol)
		{
			firstptr->numofshares += newptr->numofshares;
			found = 1;
		}
		else if (lastptr->stocksymbol == newptr->stocksymbol)
		{
			lastptr->numofshares += newptr->numofshares;
			found = 1;
		}
		else {
			while (tempptr1->backward != NULL)
			{
				if (tempptr1->stocksymbol == newptr->stocksymbol)
				{
					tempptr1->numofshares += newptr->numofshares;
					found = 1;
					break;
				}
				else
				{
					tempptr1 = tempptr1->backward;
				}
			}
		}
	}
	//If the symbol bought is not present in the list add it to the DoublyLinkedList 
	if (size == 0)
	{
		//Insert if list is empty
		firstptr = lastptr = newptr;
		size++;
	}
	else if (size == 1 && found == 0)
	{
		//Insert if only one element is present
		firstptr = newptr;
		lastptr->forward = firstptr;
		firstptr->backward = lastptr;
		size++;
	}
	else  if (size > 1 && found == 0)
	{
		//Insert if more than one elemnt is present
		Node *tempptr = NULL;
		tempptr = firstptr;
		firstptr = newptr;
		tempptr->forward = firstptr;
		firstptr->backward = tempptr;
		size++;
	}
}

void DoublyLinkedList::sortlist() //Define function sortlist()
{
	if (size == 0)
	{
		//Display result for an empty list
		cout << "\nYou do not have any shares bought to sort";
	}
	else {
		//Display if the list is not empty
		string name, date;
		double price, big;

		//open the file randomly
		ifstream file;
		srand(time(0));
		int number = rand();
		int no = number % 2;
		Node *currentptr = firstptr;
		for (int i = 0;i < size;i++)
		{
			if (no == 1)
			{
				file.open("Results_1.txt");
			}
			else
			{
				file.open("Results_2.txt");
			}

			//Search for the symbol
			for (int k = 0;k < 49;k++)
			{
				file >> name >> price >> date;
				if (name == currentptr->stocksymbol)
				{
					big = (currentptr->numofshares)*price; //assign first element as big
				}
			}
			file.close(); //close file
			Node *tempptr = currentptr->backward;
			for (int j = i + 1;j < size;j++)
			{
				srand(time(0));
				int num = rand()%2;
				if (num == 1)
				{
					file.open("Results_1.txt");
				}
				else
				{
					file.open("Results_2.txt");
				}
				for (int l = 0;l < 49;l++)
				{
					file >> name >> price >> date;
					if (name == tempptr->stocksymbol)
					{
						if ((tempptr->numofshares)*price > big) //check if the element is greater than big
						{
							//Swap the values if greater than big
							string temp1;
							int temp2;
							temp1 = currentptr->stocksymbol;
							temp2 = currentptr->numofshares;
							currentptr->stocksymbol = tempptr->stocksymbol;
							currentptr->numofshares = tempptr->numofshares;
							tempptr->stocksymbol = temp1;
							tempptr->numofshares = temp2;
							big = (currentptr->numofshares)*price;
						}
					}
				}
				file.close(); //close file
				if (i == 0)
				{
					firstptr = currentptr;
				}
				if (i == size - 1)
				{
					lastptr = tempptr;
				}
				tempptr = tempptr->backward;
			}
			currentptr = currentptr->backward;
		}
	}
	//method-2 
	/*Node *a = firstptr;

	for (int i = 0; i < size; i++)
	{
	cout << "\ni=" << i;
	Node *currentptr = a;

	for (int j = 0; j < size - i - 1;j++)
	{
	cout << "\nj=" << j;
	Node *tempptr = currentptr->backward;
	if (tempptr->numofshares*pricepershare(tempptr->stocksymbol)>currentptr->numofshares*pricepershare(currentptr->stocksymbol))
	{
	cout << "\nfound";
	if (currentptr == firstptr)
	{
	cout << "\nfirst";
	tempptr->backward->forward = currentptr;
	tempptr->forward = NULL;
	currentptr->backward = tempptr->backward;
	tempptr->backward = currentptr;
	currentptr->forward = tempptr;
	firstptr = tempptr;
	}
	else if (tempptr == lastptr)
	{
	cout << "\nlast";
	currentptr->forward->backward = tempptr;
	tempptr->forward = currentptr->forward;
	currentptr->backward = NULL;
	tempptr->backward = currentptr;
	currentptr->forward = tempptr;
	lastptr = currentptr;
	}
	else {
	cout << "\nadjacent";
	currentptr->forward->backward = tempptr;
	currentptr->forward = tempptr;
	currentptr->backward = tempptr->backward;
	tempptr->backward->forward = currentptr;
	tempptr->backward = currentptr;
	}

	tempptr = tempptr->backward;
	}
	currentptr = tempptr;
	}
	if (a->backward == lastptr)
	break;
	else a = a->backward;
	}*/
}
void DoublyLinkedList::remove(Node *newptr) //Define function remove()
{
	Node *currentptr;
	Node *tempptr;
	currentptr = firstptr;
	for (int i = 0;i < size;i++)
	{
		//Subtract the number of shares if the stock is in the list
		if (currentptr->stocksymbol == newptr->stocksymbol)
		{
			currentptr->numofshares -= newptr->numofshares;
            if (currentptr->numofshares == 0)
			{
				//Delete the node if the number of stocks are zero
				if (size == 1)
				{
					//Delete for size=1
					tempptr = firstptr;
					firstptr = lastptr = NULL;
					delete tempptr;
					size--;
				}
				else {
					//Delete for size greater than 1
					if (currentptr == firstptr)
					{
						//Delete if the element is first node
						tempptr = firstptr;
						firstptr = firstptr->backward;
						firstptr->forward = NULL;
						delete tempptr;
						currentptr = firstptr;
						size--;
					}
					else if (currentptr == lastptr)
					{
						//Delete if the element is last node
						tempptr = lastptr;
						lastptr = lastptr->forward;
						lastptr->backward = NULL;
						delete tempptr;
						size--;
					}
					else
					{
						//Delete if the element is in middle of the list
						tempptr = currentptr;
						currentptr->backward->forward = currentptr->forward;
						currentptr->forward->backward = currentptr->backward;
						currentptr = currentptr->backward;
						delete tempptr;
						size--;
					}
				}
			}
		}
		currentptr = currentptr->backward;
	}
}

int DoublyLinkedList::get_numofshares(string symbol) //Define function get_numofshares()
{
	Node *tempptr = firstptr;
	for (int i = 0;i < size;i++)
	{
		//Search for the symbol in the list
		if (tempptr->stocksymbol == symbol)
		{
			return tempptr->numofshares; //Return the value of number of shares
		}
		tempptr = tempptr->backward;
	}
	return -1; //Return -1 if symbol is not present in the list
}

void DoublyLinkedList::print(double balance) //Define function print()
{
	Node *newptr;
	newptr = firstptr;
	double sum = 0;
	//Display results
	cout << "\nCompany Symbol" << setw(15) << "Number" << setw(23) << "Price per share" << setw(19) << "Total value" << endl;
	if (size == 0)
	{
		cout << "---" << setw(22) << "--" << setw(18) << "--" << setw(25) << "--" << endl;
	}
	else {
		for (int i = 0;i < size;i++)
		{
			double price = pricepershare(newptr->stocksymbol);
			cout << newptr->stocksymbol << setw(22) << newptr->numofshares << setw(22) << price << setw(23) << price*(newptr->numofshares) << endl;
			sum += price*(newptr->numofshares);
			newptr = newptr->backward;
		}
	}
	cout << "\nTotal portfolio value is: $" << sum + balance; //Display total portfolio value
}

double DoublyLinkedList::pricepershare(string symbol) //Define function pricepershare()
{
	string name, date;
	double price;

	//open random file
	ifstream file;
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
	for (int i = 0;i < 49;i++)
	{
		//search for symbol
		file >> name >> price >> date;
		if (name == symbol)
		{
			return price; //return price of symbol
		}
	}
}

void DoublyLinkedList::save() //Define function save()
{
	//open file StockAccount_Info.txt for output
	ofstream stockfile("StockAccount_Info.txt", ios::out);
	Node *tempptr = firstptr;
	stockfile << "Name" << setw(20) << "Number" << endl;
	//save the information in StockAccount_Info.txt for future use
	for (int i = 0;i < size;i++)
	{
		stockfile << tempptr->stocksymbol << setw(20) << tempptr->numofshares << endl;
		tempptr = tempptr->backward;
	}
}

void DoublyLinkedList::initialize() //Define function initialize()
{
	//open file StockAccount_Info.txt for input
	ifstream file("StockAccount_Info.txt", ios::in);
	string symbol, title1, title2;
	int num;
	file >> title1 >> title2;
	//Read data from file
	while (true)
	{
		file >> symbol >> num;
		if (file.eof())
			break;
		Node *newptr = new Node(symbol, num);
		insert(newptr);
	}
}

void DoublyLinkedList::saveportfolio(double balance) //Define function saveportfolio()
{
	Node *newptr;
	newptr = firstptr;
	double sum = 0;
	//save data to BankAccount_Info.txt for future use
	if (size == 0)
	{
		//save when size is zero
		ofstream bankinfo("BankAccount_Info.txt", ios::app);
		bankinfo << setw(20) << balance << setw(20) << get_date() << setw(20) << get_time();
	}
	else {
		//save when size is greater than zero
		for (int i = 0;i < size;i++)
		{
			double price = pricepershare(newptr->stocksymbol);
			sum += price*(newptr->numofshares);
			newptr = newptr->backward;
		}
		//open file BankAccount_Info.txt for input
		ofstream bankinfo("BankAccount_Info.txt", ios::app);
		bankinfo << setw(20) << sum + balance << setw(20) << get_date() << setw(20) << get_time();
	}
}

