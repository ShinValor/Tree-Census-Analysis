/*
Title: tree.h
Author: Ho Ming Poon
Created on: February 20th, 2018
Description: Header file for Tree, Private variable are information we need to input
			 so that we can paste to output file.
*/

#ifndef TREE
#define TREE

#include <iostream>
#include <sstream>
#include <iomanip>
using namespace std;

class Tree
{
	public:
		// Constructor
		Tree(const string & treedata); // Takes a string from a csv file.

		// Destructor
		~Tree();

		friend ostream& operator<<(ostream& os, const Tree& t);
		string write();

		// Conversion
		string IntToStr(const int & tmp); // Convert Integer to String
		string DecToStr(const double & tmp); // Convert Decimal to String

	private:
		string spc_common; // Name of the tree
		int tree_id; // Tree id (Non-negative)
 		int tree_dbh; // Tree diameter (Non-negative)
		string status; // Alive, Dead, Stump
		string health; // Good, Fair, Poor
		string address; // Nearest estimated address to tree
		string boroname; // Manhattan, Bronx, Brooklyn, Queen, Staten Island
		int zipcode; // a positive five digit integer (0 to 99999)
		double latitude; // GPS latitude of tree point, in decimal degrees
		double longitude; // GPS longitude of the tree point, in decimal degrees
};

#endif
