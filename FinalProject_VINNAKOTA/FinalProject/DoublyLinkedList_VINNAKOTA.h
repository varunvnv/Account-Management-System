//NAME: NAGA VENKATA VARUN VINNAKOTA
//RUID: 164009240
//TITLE:FINAL PROJECT - DoublyLinkedList_VINNAKOTA.h
//Date of submission: 12/13/2015

#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H
#include"Node_VINNAKOTA.h"
#include<string>
#include<time.h>
#include<ctime>

using namespace std;
//Define class DoublyLinkedList
class DoublyLinkedList
{
	//declare private data members
private:
	Node *firstptr;
	Node *lastptr;
	//declare public data members
public:
	DoublyLinkedList();
	void insert(Node *);
	void remove(Node*);
	void sortlist();
	int size;
	int get_numofshares(string);
	void print(double);
	double pricepershare(string);
	void save();
	void initialize();
	void saveportfolio(double);
	string get_time()
	{
		time_t seconds;
		seconds = time(NULL);
		tm * timeinfo;
		timeinfo = localtime(&seconds);
		string hour = to_string(timeinfo->tm_hour);
		string minute = to_string(timeinfo->tm_min);
		string second = to_string(timeinfo->tm_sec);
		string time = hour + ":" + minute + ":" + second;
		return time;
	}
	string get_date()
	{
		time_t seconds;
		seconds = time(NULL);
		tm * timeinfo;
		timeinfo = localtime(&seconds);
		string month = to_string(timeinfo->tm_mon + 1);
		string day = to_string(timeinfo->tm_mday);
		string year = to_string(timeinfo->tm_year + 1900);
		string date = month + "/" + day + "/" + year;
		return date;
	}
};

#endif