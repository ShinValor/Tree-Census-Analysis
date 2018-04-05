/*
Title: pseudoServer.cpp
Author: Ho Ming Poon
Created on: February 20th, 2018
Description: Implementation of pseudoServer.cpp. Queue has add, delete and getempty function. pseudoServer can read
			 from input file and place in queue. Extract can get data from queue and output on output file.
*/

#include "pseudoserver.h"

Queue::Queue()
{
	head = NULL; // Set to null
	tail = NULL;
	size = 0;
}

Queue::~Queue()
{
	Node* temp;
	while (head != NULL) // Delete every element dellocate
	{
		temp = head;
		head = head->next;
		delete temp;
	}
	head = NULL;
	tail = NULL;
}

bool Queue::getEmpty() 
{
	if (size == 0) // If empty return true
	{
		return true;
	}
}

int Queue::getSize()
{
	return size;
}

void Queue::push_back(const string& sent)
{
	Node *temp = new Node; // Allocate element and push back the element in the correct insertion position
	temp->data = sent;
	temp->next = NULL;
	size++;
	if (head == NULL)
	{
		head = temp;
		tail = temp;
		temp = NULL;
	}
	else
	{	
		tail->next = temp;
		tail = temp;
	}
}

string Queue::pop_front()
{
	string sentence; // Dellocate specific element form link-list and return the delete element
	Node* temp = head;
	sentence = temp->data;
	head = head->next;
	delete temp;
	temp = NULL;
	size--;
	return sentence;
}

// ______________________________________

pseudoServer::pseudoServer()
{
}

pseudoServer::~pseudoServer()
{
	database.~Queue(); // dellocate everything
}

bool pseudoServer::read(istream& is)
{
	string sent;
	if (getline(is,sent)) // Read next line and put in Sent
	{
		database.push_back(sent); // Add to queue
		return true;
	}
	else
	{
		return false;
	}
}

bool pseudoServer::extract(string& s)
{
	if (queuesize() != 0)
	{
		s = database.pop_front(); // Delete element from queue
		return true;
	}
	else
	{
		return false;
	}
}

int pseudoServer::queuesize()
{
	return database.getSize();	
}
