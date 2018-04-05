/*
Title: pseudoServer.h
Author: Ho Ming Poon
Created on: February 20th, 2018
Description: Made queue using link-list implementation and use that to implement pseudoServer
			 pseudoServer has read, extract, and queuesize to read input file and extract data from queue. 
*/

#ifndef QUEUE
#define QUEUE

#include <iostream>
using namespace std;

// Link-list imeplementation

struct Node
{
	string data;
	Node* next;
};

class Queue
{
	public:
		// Constructor
		Queue();

		// Destructor
		~Queue();

		// Accessor
		bool getEmpty();
		int getSize();
		void display();

		// Mutator
		void push_back(const string& sent);
		string pop_front();

	private:
		Node* head;
		Node* tail;
		int size;
};

class pseudoServer
{
	public:
		// Constructor
		pseudoServer();

		// Destructor
		~pseudoServer();
		
		// Mutator
		bool read(istream& is); 
		bool extract(string& s);
		
		// Accessor
		int queuesize();

	private:
		Queue database;
};

#endif
