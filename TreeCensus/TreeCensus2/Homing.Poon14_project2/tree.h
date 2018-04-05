/*******************************************************************************
  Title          : tree.h
  Author         : Ho Ming Poon
  Created on     : March 09, 2018
  Description    : The header file for the Tree class
  Purpose        : Store input file data

  Usage          : Input a string into a Tree object so that it can parse the string and store data
  Modifications  : Added few more comparator friend functions and conversion from int/double to string.

*******************************************************************************/

#ifndef TREE
#define TREE

#include <iostream>
#include <sstream>
#include <iomanip>
#include <algorithm>

using namespace std;

class Tree
{
	public:
		/** Tree()
		*  A default constructor for the class that creates an empty Tree. 
		*/
		Tree() {};


		/** Tree(const string & treedata)
		*	A overloaded constructor for the class that takes a string and parse for data (Taking substrings).
		*	@param treedata is the string to be input and parse.
		*/
		Tree(const string & treedata);


		/** Tree(int id, int diam, string tree_status, string tree_health, string spc, int zip, string addr, string boro, double tree_latitude, double tree_longitude)
		*	A overloaded constructor for the class that takes multiple arguments and assign these arguments to data placeholders.
		*	@param id, diam, tree_status, tree_health, spc, zip, addr, boro, tree_latitude, tree_longitude are the datas to be input.
		*/
		Tree(int id, int diam, string tree_status, string tree_health, string spc, int zip, string addr, string boro, double tree_latitude, double tree_longitude);


		/** A destructor for the class. 
		*/
		~Tree();

		/***********************Friend Functions***********************/

		/** friend bool operator==(const Tree & t1, const Tree & t2)
		*	Tree t1 is not equal to Tree t2 if their spc_common and tree_id are not identical.
		*	@Param t1 and t2 are the tree to be compared.
		*/
		friend bool operator==(const Tree & t1, const Tree & t2);


		/** friend bool operator!=(const Tree & t1, const Tree & t2)
		*	Tree t1 is not equal to Tree t2 if their spc_common and tree_id are not identical.
		*	@Param t1 and t2 are the tree to be compared.
		*/
		friend bool operator!=(const Tree & t1, const Tree & t2);


		/** friend bool operator<(const Tree & t1, const Tree & t2)
		*	Tree t1 is less than Tree t2 if t1's spc_common is less than t2's (alphabetically) or if 
		*	t1's spc_common is same as t2's but t1's tree_id is less than t2's.
		*	@Param t1 and t2 are the tree to be compared.
		*/
		friend bool operator<(const Tree & t1, const Tree & t2);


		/** friend bool operator>(const Tree & t1, const Tree & t2)
		*	Tree t1 is greater than Tree t2 if t1's spc_common is greater than t2's (alphabetically) or if 
		*	t1's spc_common is same as t2's but t1's tree_id is greater than t2's.
		*	@Param t1 and t2 are the tree to be compared.
		*/
		friend bool operator>(const Tree & t1, const Tree & t2);


		/** friend ostream& operator<<(ostream & os, const Tree & t)
		*	Prints the Tree's data on the given ostream.
		*	@Param ostream& os is the output stream to be modified.
		*/
		friend ostream& operator<<(ostream & os, const Tree & t);


		/** friend bool samename(const Tree & t1, const Tree & t2)
		*	Tree t1 is samename as Tree t2 if their spc_common is the same.
		*	@Param t1 and t2 are the tree to be compared.
		*/
		friend bool samename(const Tree & t1, const Tree & t2);


		/** friend bool islessname(const Tree & t1, const Tree & t2)
		*	Tree t1 is islessname than Tree t2 if t1's spc_common is less than (alphabetically) t2's.
		*	@Param t1 and t2 are the tree to be compared.
		*/
		friend bool islessname(const Tree & t1, const Tree & t2);


		/** friend bool isgreatername(const Tree & t1, const Tree & t2)
		*	Tree t1 is isgreatername than Tree t2 if t1's spc_common is greater than (alphabetically) t2's.
		*	@Param t1 and t2 are the tree to be compared.
		*/
		friend bool isgreatername(const Tree & t1, const Tree & t2);


		/***********************Accessors***********************/

		/** string common_name() const
		*	return spc_common of the Tree object.
		*/
		string common_name() const;


		/** int id() const
		*	return tree_id of the Tree object.
		*/
		int id() const;


		/** string borough_name() const
		*	return boroname of the Tree object. 
		*/
		string borough_name() const;


		/** string nearest_address() const
		*	return the address of the Tree object.
		*/
		string nearest_address() const;


		/** int diameter() const
		*	return tree_dbh of the Tree object.
		*/
		int diameter() const;


		/** int zip() const
		*	return zipcode of the Tree object.
		*/
		int zip() const;


		/** void get_position(double & latitude, double & longitude) const
		*	stores into its two parameter the latitude and logitude of the Tree.
		*/
		void get_position(double & latitude, double & longitude) const;

	private:
		string spc_common;	// Name of the tree
		int tree_id; 		// Tree id (Non-negative)
		int tree_dbh; 		// Tree diameter (Non-negative)
		string status; 		// Alive, Dead, Stump
		string health; 		// Good, Fair, Poor
		string address; 	// Nearest estimated address to tree
		string boroname; 	// Manhattan, Bronx, Brooklyn, Queen, Staten Island
		int zipcode; 		// a positive five digit integer (0 to 99999)
		double latitude; 	// GPS latitude of tree point, in decimal degrees
		double longitude; 	// GPS longitude of the tree point, in decimal degrees


		/***********************Conversions***********************/

		/** IntToStr(const int & tmp) 
		*	Function takes in an integer and convert it into string
		*	@param tmp is the integer to be coverted.
		*/
		string IntToStr(const int & tmp);

		/** DouToStr(const double & tmp)
		*	Function takes in a double and convert it to string
		*	@param tmp is the double to be coverted.
		*/
		string DouToStr(const double & tmp);
};

#endif