/*
Title: tree.cpp
Author: Ho Ming Poon
Created on: February 20th, 2018
Description: Parse the inputted string to get the data and do int/string conversion to 
			 paste on to output file.
*/

#include "tree.h"

Tree::Tree(const string& treedata)
{
	string temp = "";
	int count = 0;
	bool flip = false; // For data with ""
	for (unsigned int i = 0; i < treedata.length(); i++) // Parsing the string
	{
		if (treedata[i] == ',' && flip == false)
		{
			switch (count) // Switch case to input the data
			{
				case 9:
					spc_common = temp;
					break;
				case 0: 
					istringstream(temp) >> tree_id;
					break;
				case 3: 
					istringstream(temp) >> tree_dbh;
					break;
				case 6:
					status = temp;
					break;
				case 7:
					health = temp;
					break;
				case 24:
					address = temp;
					break;
				case 29: 
					boroname = temp;
					break;
				case 25: 
					istringstream(temp) >> zipcode;
					break;
				case 37: 
					istringstream(temp) >> latitude;
					break;
				case 38:
					istringstream(temp) >> longitude;
					break;
				default:
					break;
			}
			temp = "";
			count++;
		}
		else if (treedata[i] == '\"')
		{
			if (flip == false)
			{
				flip = true;
				temp += treedata[i];
			}
			else
			{
				flip =  false;
				temp += treedata[i];
			}
		}
		else
		{
			temp += treedata[i];
		}
	}
}

Tree::~Tree()
{
}

ostream& operator<<(ostream & os, const Tree & t) // Output operator 
{
	os << t.spc_common << ","<< t.tree_id << "," << t.tree_dbh << "," << t.status << "," << t.health << "," << t.address << "," << t.boroname << "," << t.zipcode << "," << setprecision(10) << t.latitude << "," << setprecision(10) << t.longitude;
	return os;
}

string Tree::write() // Write function using int/double/string conversion function
{	
	string display = spc_common + "\t" + IntToStr(tree_id) + "\t" + IntToStr(tree_dbh) + "\t" + status + "\t" + health + "\t" + address + "\t" + boroname + "\t" + IntToStr(zipcode) + "\t" + DecToStr(latitude) + "\t" + DecToStr(longitude);
	return display;	
}

string Tree::IntToStr(const int & tmp) // Integer to string Conversion 
{
    ostringstream out;
    out << tmp;
    return out.str();
}

string Tree::DecToStr(const double & tmp) // Double to String conversion
{
    ostringstream out;
    out << setprecision(10) << tmp;
    return out.str();
}
