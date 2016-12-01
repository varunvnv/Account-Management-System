//NAME: NAGA VENKATA VARUN VINNAKOTA
//RUID: 164009240
//TITLE:FINAL PROJECT - Node_VINNAKOTA.h
//Date of submission: 12/13/2015

#ifndef NODE_H
#define NODE_H
#include<iostream>
#include<string>

using namespace std;
//Define class Node
class Node {
	//declare friend member
	friend class DoublyLinkedList;
	//declare public data members
public:
	Node(string & symbol, int num)
		:stocksymbol(symbol), numofshares(num)
	{
		this->forward = NULL;
		this->backward = NULL;
	}

private:
	int numofshares;
	string stocksymbol;

	Node *forward;
	Node *backward;
};

#endif