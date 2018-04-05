/*******************************************************************************
  Title          : main.cpp
  Author         : Ho Ming Poon
  Created on     : March 09, 2018
  Description    : 
  Purpose        : 

  Usage          : 
  Build with     : 
  Modifications  : 

*******************************************************************************/

#include <iostream>
#include <fstream>
#include <stdlib.h>

#include "tree.h"
#include "tree_collection.h"
#include "avl.h"
#include "command.h"

using namespace std;


int main(int argc, char const *argv[])
{
	ifstream inFile; 
	ifstream inFile2;

	if(argc == 3)
	{
    	inFile.open(argv[1]);
    	if (!inFile) 
    	{
        	cerr << "Could not open data " << argv[1] << " for reading.\n";
        	exit(1);
    	}  

    	inFile2.open(argv[2]);
    	if (!inFile2) 
    	{
        	cerr << "Could not open commands " << argv[2] << " for reading.\n";
        	exit(1);
    	}		
	}
	else if(argc > 3) 
	{
		cout << "Invalid argument passed." <<endl;
		exit(1);
	}
	else
	{
		cout << "Invalid argument passed." <<endl;
		exit(1);
	}

	TreeCollection database;
	Command   command;
	string    treename;
	int       zipcode;
	double    latitude, longitude, distance;
	bool      result;	

	string temp;
	while (!inFile.eof())
	{
		getline(inFile,temp);
		Tree t(temp);

		// Add to TreeCollection
		database.insert_to_Avl(t);
		database.insert_to_species(t);
		database.insert_to_boro(t);
	}

	while (!inFile2.eof()) 
	{
		if (!command.get_next(inFile2))
		{
			if (!inFile2.eof())
			{
				cerr << "Could not get next command.\n";
				return 1;
			}
		}
		command.get_args(treename, zipcode, latitude, longitude, distance, result);
		
		switch (command.type_of())
		{
			case tree_info_cmmd:
				// Function for tree_info
				database.print_tree_info(treename);
				break;
			case listall_names_cmmd:
				// Function for listall_names
				database.print_listall_names();
				break;
			case list_near_cmmd:
				// Function for list_near
				database.print_list_near(latitude,longitude,distance);
				break;
			case listall_inzip_cmmd:
				// Function for listall_inzip
				database.print_listall_inzip(zipcode);        
				break;
			case bad_cmmd:
				break;
			default:
				break;
		}
	}


	inFile.close();
	inFile2.close();

	return 0;
}