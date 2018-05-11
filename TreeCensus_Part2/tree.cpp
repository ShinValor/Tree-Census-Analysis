/*******************************************************************************
  Title          : tree.cpp
  Author         : Ho Ming Poon
  Created on     : March 09, 2018
  Description    : Implementation of Tree class
  Purpose        : 

  Usage          : 
  Build with     : 
  Modifications  : 

*******************************************************************************/

#include "tree.h"

Tree::Tree(const string& treedata)
{
	string temp = "";
	int count = 0;
	bool flip = false;
	for (unsigned int i = 0; i < treedata.length(); i++)
	{
		if (treedata[i] == ',' && flip == false)
		{
			switch (count)
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


Tree::Tree(int id, int diam, string tree_status, string tree_health, string spc, int zip, string addr, string boro, double tree_latitude, double tree_longitude)
{
	tree_id = id; tree_dbh = diam; status = tree_status; health = tree_health; spc_common = spc; 
	zipcode = zip; address = addr; boroname = boro; latitude = tree_latitude; longitude = tree_longitude;
}

Tree::~Tree()
{

}


bool operator==(const Tree & t1, const Tree & t2)
{
	string compare1 = t1.spc_common;
	string compare2 = t2.spc_common;
	transform(compare1.begin(), compare1.end(), compare1.begin(), ::tolower);
	transform(compare2.begin(), compare2.end(), compare2.begin(), ::tolower);

	if (compare1 == compare2 && t1.tree_id == t2.tree_id)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool operator!=(const Tree & t1, const Tree & t2)
{
	string compare1 = t1.spc_common;
	string compare2 = t2.spc_common;
	transform(compare1.begin(), compare1.end(), compare1.begin(), ::tolower);
	transform(compare2.begin(), compare2.end(), compare2.begin(), ::tolower);

	if (compare1 != compare2 && t1.tree_id != t2.tree_id)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool operator<(const Tree & t1, const Tree & t2)
{
	string compare1 = t1.spc_common;
	string compare2 = t2.spc_common;
	transform(compare1.begin(), compare1.end(), compare1.begin(), ::tolower);
	transform(compare2.begin(), compare2.end(), compare2.begin(), ::tolower);

	if (compare1 < compare2)
	{
		return true;
	}
	else if (compare1 == compare2)
	{
		if (t1.tree_id < t2.tree_id)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}

bool operator>(const Tree & t1, const Tree & t2)
{
	string compare1 = t1.spc_common;
	string compare2 = t2.spc_common;
	transform(compare1.begin(), compare1.end(), compare1.begin(), ::tolower);
	transform(compare2.begin(), compare2.end(), compare2.begin(), ::tolower);

	if (compare1 > compare2)
	{
		return true;
	}
	else if (compare1 == compare2)
	{
		if (t1.tree_id > t2.tree_id)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}

ostream& operator<<(ostream & os, const Tree & t)
{
	os << t.spc_common << ","<< t.tree_id << "," << t.tree_dbh << "," << t.status << "," << t.health << "," << t.address << "," << t.boroname << "," << t.zipcode << "," << setprecision(10) << t.latitude << "," << setprecision(10) << t.longitude;
	return os;
}

bool samename(const Tree & t1, const Tree & t2)
{
	string compare1 = t1.spc_common;
	string compare2 = t2.spc_common;
	transform(compare1.begin(), compare1.end(), compare1.begin(), ::tolower);
	transform(compare2.begin(), compare2.end(), compare2.begin(), ::tolower);

	if (compare1 == compare2)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool islessname(const Tree & t1, const Tree & t2)
{
	string compare1 = t1.spc_common;
	string compare2 = t2.spc_common;
	transform(compare1.begin(), compare1.end(), compare1.begin(), ::tolower);
	transform(compare2.begin(), compare2.end(), compare2.begin(), ::tolower);

	if (compare1 < compare2)
	{
		return true;
	}	
	else
	{
		return false;
	}
}

bool isgreatername(const Tree & t1, const Tree & t2)
{
	string compare1 = t1.spc_common;
	string compare2 = t2.spc_common;
	transform(compare1.begin(), compare1.end(), compare1.begin(), ::tolower);
	transform(compare2.begin(), compare2.end(), compare2.begin(), ::tolower);

	if (compare1 > compare2)
	{
		return true;
	}	
	else
	{
		return false;
	}
}

string Tree::common_name() const
{
	return spc_common;
}

int Tree::id() const
{
	return tree_id;
}

string Tree::borough_name() const
{
	return boroname;
}

string Tree::nearest_address() const
{
	return address;
}

int Tree::diameter() const
{
	return tree_dbh;
}

int Tree::zip() const
{	
	return zipcode;
}

void Tree::get_position(double & latitude, double & longitude) const
{
	latitude = latitude;
	longitude = longitude;
}

string Tree::IntToStr(const int & tmp) // Integer to string Conversion 
{
    ostringstream out;
    out << tmp;
    return out.str();
}

string Tree::DouToStr(const double & tmp) // Double to String conversion
{
    ostringstream out;
    out << setprecision(10) << tmp;
    return out.str();
}