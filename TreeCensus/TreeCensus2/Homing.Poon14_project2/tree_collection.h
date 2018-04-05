/*******************************************************************************
  Title          : tree_collection.h
  Author         : Ho Ming Poon
  Created on     : March 09, 2018
  Description    : The header file for the TreeCollection class
  Purpose        : Group AVL_Tree, TreeSpecies, and borough into one class to process command line.

  Usage          : Create a TreeCollection object and use mutator functions to insert/remove and print tree object data.
  Modifications  : Added functions for insertion/deletion to AVL_Tree, print tree object data, and command lines processing.

*******************************************************************************/

#ifndef Tree_Collection_H
#define Tree_Collection_H

#include <iostream>
#include <list>
#include <iomanip>
#include "avl.h"
#include "tree_species.h"

using namespace std;

class TreeCollection
{

public:

	/** TreeCollection()
    *	A default constructor for the class that creates an empty TreeCollection. 
    */
	TreeCollection();


	/** A destructor for the class. 
    */
	~TreeCollection();



	/***********************Mutators***********************/

	/** void insert_to_Avl(const Tree & tree)
	*	Insert tree object into AVL_Tree.
	*	@param tree is the tree object to be inserted.
	*/
	void insert_to_Avl(const Tree & tree);


	/** void insert_to_species(const Tree & tree)
	*	Insert Tree object's spc_common to species container.
	*	@param tree is the tree object's spc_common to be inserted.
	*/
	void insert_to_species(const Tree & tree);


	/** void insert_to_boro(const Tree & tree)
	*	Insert Tree object's borough into container.
	*	@param tree is the tree object's borough to be inserted.
	*/
	void insert_to_boro(const Tree & tree);



	/***********************Accessors***********************/

	/** int total_tree_count() const
	*	return the total number of tree object in AVL_Tree.
	*/
	int total_tree_count() const;


	/** int count_of_tree_species(const string & species_name) const
	*	return the number of Tree objects in the collection whose spc_common species name matches the
	*	species_name specified by the param.
	*	@param species_name
	**/
	int count_of_tree_species(const string & species_name) const;


	/** int count_of_trees_in_boro(const string & boro_name) const
	*	return the number of Tree object in the collection that are located in the borough specified by the param.
	*	@param boro_name
	*/
	int count_of_trees_in_boro(const string & boro_name) const;


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


	/**	list<string> get_all_near(double latitude, double longitude, double distance) const
	*	return a list containing a list of all of the actual tree species that are located within distance
	*	kilometers from the GPS position.
	*	@param latitude, longitude, distance
	*/	
	list<string> get_all_near(double latitude, double longitude, double distance) const;



	/***********************Command_Output***********************/

	/** void print_tree_info() const
	*	lists certain information about the trees whose common name matches tree_name.
	*	@param tree_name
	*/
	void print_tree_info(const string & tree_name) const;


	/** void print_listall_names() const
	*	list all trees common names found in the TreeCollection.
	*/
	void print_listall_names() const;


	/** void print_list_near() const
	*	lists the common names of all trees within dist kilometers of the given point (latitude,longitude).
	*	@param latitude, longitude, distance
	*/
	void print_list_near(const double & latitude, const double & longitude, const double & distance) const;


	/** void print_listall_inzip() const
	*	lists the common names of all trees found in the given zipcode
	*	@param zipcode
	*/
	void print_listall_inzip(const int & zipcode) const;



	/***********************Printing***********************/

	/** void printAVL() const
	*	print Inorder Traversal in AVL_Tree
	*/
	void printAVL() const;

private:

	struct BoroughNames
	{
		int brooklyn;
		int manhattan;
		int queens;
		int bronx;
		int statenisland;
	};

	AVL_Tree collection;
	TreeSpecies species;
	BoroughNames boro;

};

#endif