/*******************************************************************************
  Title          : tree_collection.cpp
  Author         : Ho Ming Poon
  Created on     : March 09, 2018
  Description    : Implementation of TreeCollection class
  Purpose        : 

  Usage          : 
  Build with     : 
  Modifications  : 

*******************************************************************************/

#include "tree_collection.h"

TreeCollection::TreeCollection()
{
	boro.manhattan = 0;
	boro.bronx = 0;
	boro.queens = 0;
	boro.brooklyn = 0;
	boro.statenisland = 0;
}

TreeCollection::~TreeCollection()
{
	collection.~AVL_Tree();
	boro.manhattan = 0;
	boro.bronx = 0;
	boro.queens = 0;
	boro.brooklyn = 0;
	boro.statenisland = 0;
}

void TreeCollection::insert_to_Avl(const Tree & tree)
{
	collection.insert(tree);
}

void TreeCollection::insert_to_species(const Tree& tree)
{
	species.add_species(tree.common_name());
}

void TreeCollection::insert_to_boro(const Tree & tree)
{
	string name = tree.borough_name();
	transform(name.begin(), name.end(), name.begin(), ::tolower);

	if (name == "manhattan")
	{
		boro.manhattan++;
	}
	else if (name == "bronx")
	{
		boro.bronx++;
	}
	else if (name == "queens")
	{
		boro.queens++;
	}
	else if (name == "brooklyn")
	{
		boro.brooklyn++;
	}
	else if (name == "staten island")
	{
		boro.statenisland++;
	}
	else
	{
		return;
	}
}

int TreeCollection::total_tree_count() const
{
	return collection.getSize();
}

int TreeCollection::count_of_tree_species(const string & species_name) const
{
	return collection.count_of_tree_species(species_name);
}

int TreeCollection::count_of_trees_in_boro(const string & boro_name) const
{
	string name = boro_name;
	transform(name.begin(), name.end(), name.begin(), ::tolower);

	if (name == "manhattan")
	{
		return boro.manhattan;
	}
	else if (name == "bronx")
	{
		return boro.bronx;
	}
	else if (name == "queens")
	{
		return boro.queens;
	}
	else if (name == "brooklyn")
	{
		return boro.brooklyn;
	}
	else if (name == "staten island")
	{
		return boro.statenisland;
	}
	else
	{
		return 0;
	}
}

list<string> TreeCollection::get_matching_species(const string & species_name) const
{
	return collection.get_matching_species(species_name);
}

list<string> TreeCollection::get_all_in_zipcode(int zipcode) const
{
	return collection.get_all_in_zipcode(zipcode);
}

list<string> TreeCollection::get_all_near(double latitude, double longitude, double distance) const
{
	return collection.get_all_near(latitude,longitude,distance);
}

void TreeCollection::print_tree_info(const string & tree_name) const
{
	collection.print_tree_info(tree_name);

	string word;
	for (unsigned int i = 0; i < tree_name.length(); i++) // removing spaces in front of tree_name
	{
		if (tree_name[i] == ' ' && word.length() == 0)
		{

		}
		else
		{
			word = word + tree_name[i];
		}
	}
	
	int num_of_tree = 0;
	int manhattan_tree = 0;
	int bronx_tree = 0;
	int brooklyn_tree = 0;
	int queens_tree = 0;
	int staten_island_tree = 0;

	list<string> myList = species.get_matching_species(word);

	for (list<string>::const_iterator iterator = myList.begin(), end = myList.end(); iterator != end; ++iterator) 
	{
		manhattan_tree = manhattan_tree + collection.boroughCount(*iterator,"manhattan");
		bronx_tree = bronx_tree + collection.boroughCount(*iterator,"bronx");
		brooklyn_tree = brooklyn_tree + collection.boroughCount(*iterator,"brooklyn");
		queens_tree = queens_tree + collection.boroughCount(*iterator,"queens");
		staten_island_tree = staten_island_tree + collection.boroughCount(*iterator,"staten island");
    	num_of_tree = num_of_tree + count_of_tree_species(*iterator);
	}

	cout<< setprecision(2) << fixed;

	cout << "Frequency by borough:" <<endl;
	cout << "	Total in NYC:  " << num_of_tree << "      (" << total_tree_count() << ") " << ((double) num_of_tree/total_tree_count())*100 << "%" <<endl;
	cout << "	Manhattan:     " << manhattan_tree <<  "       (" << count_of_trees_in_boro("manhattan") <<  ") " << ((double) manhattan_tree/count_of_trees_in_boro("manhattan"))*100  << "%" <<endl;
	cout << "	Bronx:         " << bronx_tree <<      "       (" << count_of_trees_in_boro("bronx") <<     ") "  << ((double) bronx_tree/count_of_trees_in_boro("bronx"))*100          << "%" <<endl;
	cout << "	Brooklyn:      " << brooklyn_tree <<   "       (" << count_of_trees_in_boro("brooklyn") <<   ") " << ((double) brooklyn_tree/count_of_trees_in_boro("brooklyn"))*100    << "%" <<endl;
	cout << "	Queens:        " << queens_tree <<     "       (" << count_of_trees_in_boro("queens") <<     ") " << ((double) queens_tree/count_of_trees_in_boro("queens"))*100        << "%" <<endl;
	cout << "	Staten Island: " << staten_island_tree << "       (" << count_of_trees_in_boro("staten island") << ") " << ((double) staten_island_tree/count_of_trees_in_boro("staten island"))*100 << "%" <<endl;

	cout <<endl;
}

void TreeCollection::print_listall_names() const
{
	species.print_all_species(std::cout);
}

void TreeCollection::print_list_near(const double & latitude, const double & longitude, const double & distance) const
{
	cout << "Command: list_near " << latitude << " " << longitude << " " << distance <<endl;
	list<string> myList = get_all_near(latitude,longitude,distance);
	for(list<string>::iterator i = myList.begin(); i != myList.end(); ++i)
	{
		cout << *i <<endl;
	}
	cout <<endl;
}

void TreeCollection::print_listall_inzip(const int & zipcode) const
{
	collection.print_listall_inzip(zipcode);
}

void TreeCollection::printAVL() const
{
	collection.print(std::cout);
}