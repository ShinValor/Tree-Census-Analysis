/*******************************************************************************
  Title          : avl.h
  Author         : Ho Ming Poon
  Created on     : March 09, 2018
  Description    : The header file for AVL_Tree class
  Purpose        : Store Tree objects

  Usage          : Input Tree objects to AVL Tree
  Modifications  : Added some functions to output tree object data to supplement TreeCollection

*******************************************************************************/

#ifndef AVL_H
#define AVL_H
#define R 6372.8
#define TO_RAD (3.1415926536 / 180)

#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <math.h>
#include "tree.h"

using namespace std;


struct Node
{
	Tree key;
	Node* left;
	Node* right;
	int height;
};


class AVL_Tree
{
public:

	/** AVL_Tree()
    *  A default constructor for the class that creates an empty AVL_Tree. . 
    */
	AVL_Tree();


	/** A copy constructor. 
    */
	AVL_Tree(const AVL_Tree & tree);


	/** A destructor for the class. 
    */
	~AVL_Tree();



	/***********************Search Methods***********************/

	/** const Tree & find(const Tree & x) const
	*	return Tree object by searching the AVL_Tree given the param.
	*	@param x
	*/
	const Tree & find(const Tree & x) const;


	/** const Tree & findMin() const
	*	return the smallest Tree object (alphabetically) in the AVL_Tree.
	*/
	const Tree & findMin() const;


	/** const Tree & findMin(Node* root) const.
	*	return the smallest Tree object (alphabetically) in the AVL_Tree given the param.
	*	@param root
	*/
	const Tree & findMin(Node* root) const;


	/** const Tree & findMax() const
	*	return the largest Tree object (alphabetically) in the AVL_Tree.
	*/
	const Tree & findMax() const;


	/** list<Tree> findallmatches(const Tree & x) const
	*	return a list of Tree objects in the collection whose spc_common species name matches the given param
	*	@param x
	*/
	list<Tree> findallmatches(const Tree & x) const;



	/***********************Print***********************/

	/** print() 
    * Prints the Tree objects onto the ostream using inorder traversal.
    * Each of the members of the Tree object is printed, in the exact
    * same order, with tree spc_common name first, then the tree_id.
    * Fields will be separated by commas in the output stream.
    */
	void print(ostream & out) const;



	/** Methods to consider adding- getting all trees in a zipcode, or near given point **/

	/** list<string> get_matching_species(const string & species_name) const
	*	return a list of all of the actual species that match the given param string species_name.
	*	@param species_name
	*/
	list<string> get_matching_species(const string & species_name) const;


	/** list<string> get_all_in_zipcode(int zipcode) const
	*	return a list containing a list of all of the actual tree species that are located in the given zipcode.
	*	@param zipcode
	*/
	list<string> get_all_in_zipcode(int zipcode) const;


	/** list<string> get_all_near(double latitude, double longitude, double distance) const
	*	return a list containing a list of all of the actual tree species that are located within distance
	*	kilometers from the GPS position.
	*	@param latitude, longitude, distance
	*/
	list<string> get_all_near(double latitude, double longitude, double distance) const;



	/***********************Mutators***********************/

	/** void clear()
	*	delete the entire AVL_Tree
	*/
	void clear();

	/** void insert(const Tree & x)
	*	Insert the Tree object to the AVL_Tree.
	*	@param x is the Tree object to be inserted.
	*/
	void insert(const Tree & x);

	/** void remove(const Tree & x)
	*	Remove a Tree object in the AVL_Tree.
	*	@param x is the Tree object to be removed.
	*/
	void remove(const Tree & x);



	/***********************Accessors***********************/

	/** int height(Node* n)
	*	return height of the Node
	*	@param n
	*/
	int height(Node* n);


	/** int getSize() const
	*	return number of element in AVL_Tree
	*/
	int getSize() const;


	/** int count_of_tree_species(const string & species_name) const
	*	return the number of Tree objects in the collection whose spc_common species name matches given param.
	*	@param species_name
	*/
	int count_of_tree_species(const string & species_name) const;



	/***********************Command_Output***********************/

	/** void print_tree_info(const string & tree_name) const
	*	lists certain information about the trees whose common name matches tree_name.
	*/
	void print_tree_info(const string & tree_name) const;


	/**	int boroughCount(const string & species, const string & borough) const
	*	lists the common names of all trees whose common name matches species and boroname matches borough.
	*/
	int boroughCount(const string & species, const string & borough) const;

	/** void print_list_near(const double & latitude, const double & longitude, const int & distance) const
	*	lists the common names of all trees within dist kilometers of the given point (latitude,longitude).
	*/
	void print_list_near(const double & latitude, const double & longitude, const double & distance) const;

	/** void print_listall_inzip(const int & zipcode) const
	*	lists the common names of all trees found in the given zipcode.
	*/
	void print_listall_inzip(const int & zipcode) const;

private:

	Node* root;
	int size;



	/***********************Helper Functions***********************/
	/**
		Below are helper functions for functions defined above.
		The functionality of these function is the same as the one defined above.
		Which helper functions are helping are indictated below.
	**/

	// AVL_Tree(const AVL_Tree & tree);
	Node* copyNodes(Node* toCopy) const;


	// AVL_Tree(const AVL_Tree & tree);
	Node* get_root() const;


	// list<Tree> findallmatches(const Tree & x) const;
	void findAll(Node* root, const Tree & x, list<Tree>& myList) const;


	// void print(ostream & out) const;
	void inorder(ostream & out, Node* root) const;


	// list<string> get_matching_species(const string & species_name) const;
	void findSpecies(Node* root, const string & species_name, list<string>& myList) const;


	// list<string> get_all_in_zipcode(int zipcode) const;
	void findZip(Node* root, int zipcode, list<string>& myList) const;


	// int count_of_tree_species(const string & species_name) const;
	void tree_species_counter(const string & species_name, Node* root, int & count) const; 


	// void print_tree_info(const string & tree_name) const;
	void tree_info(const string & tree_name, Node* root, vector<string>& myVector) const;

	// int boroughCount(const string & species, const string & borough) const;
	void whichBorough(const string & species, const string & borough, Node* root, int & count) const;


	// list<string> get_all_near(double latitude, double longitude, double distance) const
	void list_near(const double & latitude, const double & longitude, const double & distance, Node* root, list<string> & myList) const;


	// void print_listall_inzip(const int & zipcode) const;
	void listall_inzip(const int & zipcode, Node* root, vector<string>& myVector) const;


	// void clear();
	void clean(Node*& root);


	// void insert(const Tree & x);
	void insertion(const Tree & x, Node* & root);


	// void remove(const Tree & x);
	void deletion(const Tree& x, Node* & root);


	// Rotation for Avl insertion/remove to balance the AVL_Tree
	void LL_rotation(Node* & root);
	void LR_rotation(Node* & root);
	void RR_rotation(Node* & root);
	void RL_rotation(Node* & root); 


	/***********************Haversine***********************/
	
	double haversine(double lat1, double lon1, double lat2, double lon2) const
	{
    	lat1        = TO_RAD * lat1;
    	lat2        = TO_RAD * lat2;
    	lon1        = TO_RAD * lon1;
    	lon2        = TO_RAD * lon2;
    	double dLat = (lat2 - lat1)/2;
    	double dLon = (lon2 - lon1)/2;
    	double a    = sin(dLat);
    	double b    = sin(dLon);
    	return 2*R * asin(sqrt(a*a + cos(lat1) * cos(lat2) * b*b));
	}

};

#endif