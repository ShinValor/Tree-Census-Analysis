/*******************************************************************************
  Title          : avl.cpp
  Author         : Ho Ming Poon
  Created on     : March 09, 2018
  Description    : Implementation of AVL_Tree class
  Purpose        : 

  Usage          : 
  Build with     : 
  Modifications  : 

*******************************************************************************/

#include "avl.h"

AVL_Tree::AVL_Tree()
{
	root = NULL;
	size = 0;
}

AVL_Tree::AVL_Tree(const AVL_Tree & tree)
{
	root = copyNodes(tree.get_root());
}

Node* AVL_Tree::copyNodes(Node* toCopy) const
{

	if (toCopy == NULL)
	{
		return NULL;
	}
	Node*copyNode = new Node;
	copyNode->key = toCopy->key;
	copyNode->height = toCopy->height;
	copyNode->left = copyNodes(toCopy->left);
	copyNode->right = copyNodes(toCopy->right);
	return copyNode;
}

Node* AVL_Tree::get_root() const
{
	return root;
}

AVL_Tree::~AVL_Tree()
{
	clear();
	size = 0;
}

const Tree & AVL_Tree::find(const Tree & x) const
{
	Node* temp = root;
	while (x != temp->key)
	{
		if (x < temp->key)
		{
			temp = temp->left;
		}
		else
		{
			temp = temp->right;
		}
	}
	return temp->key;
}

const Tree & AVL_Tree::findMin() const
{	
	Node* temp = root;
	while(temp->left != NULL)
	{
		temp = temp->left;
	}
	return temp->key;
}

const Tree & AVL_Tree::findMin(Node* root) const
{
	while (root->left != NULL)
	{
		root = root->left;
	}
	return root->key;
}

const Tree & AVL_Tree::findMax() const
{
	Node* temp = root;
	while(temp->right != NULL)
	{
		temp = temp->right;
	}
	return temp->key;
}

list<Tree> AVL_Tree::findallmatches(const Tree & x) const
{
	list<Tree> myList;
	findAll(root,x,myList);
	return myList;

}

void AVL_Tree::findAll(Node* root, const Tree & x, list<Tree>& myList) const
{
	if (root == NULL)
	{
		return;
	}
	else if (islessname(root->key,x))
	{
		findAll(root->left,x,myList);
	}
	else if (isgreatername(root->key,x))
	{
		findAll(root->right,x,myList);
	}
	else
	{
		if (samename(root->key,x))
		{
			myList.push_back(root->key);
			findAll(root->left,x,myList);
			findAll(root->right,x,myList);
		}
	}

}

void AVL_Tree::print(ostream & out) const
{
	inorder(out,root);
}

void AVL_Tree::inorder(ostream & out, Node* root) const
{
	if (root == NULL)
	{
		return;
	}
	inorder(out,root->left);
	out << (root->key).common_name() << ", " << (root->key).id() <<endl;
	inorder(out,root->right);
}

list<string> AVL_Tree::get_matching_species(const string & species_name) const
{
	list<string> myList;
	findSpecies(root,species_name,myList);
	return myList;
}

void AVL_Tree::findSpecies(Node* root, const string & species_name, list<string>& myList) const
{
	if (root == NULL)
	{
		return;
	}
	else if (species_name < (root->key).common_name())
	{
		findSpecies(root->left,species_name,myList);
	}
	else if (species_name > (root->key).common_name())
	{
		findSpecies(root->right,species_name,myList);
	}
	else
	{
		if ((root->key).common_name() == species_name)
		{
			if (std::find(myList.begin(), myList.end(), species_name) != myList.end())
			{	
				myList.push_back((root->key).common_name());
				findSpecies(root->left,species_name,myList);
				findSpecies(root->right,species_name,myList);
			}
		}	
	}
}

list<string> AVL_Tree::get_all_in_zipcode(int zipcode) const
{
	list<string> myList;
	findZip(root,zipcode,myList);
	return myList;
}

void AVL_Tree::findZip(Node* root, int zipcode, list<string>& myList) const
{
	if (root == NULL)
	{
		return;
	}
	else
	{
		findZip(root->left,zipcode,myList);
		if ((root->key).zip() == zipcode)
		{
			if (std::find(myList.begin(), myList.end(),(root->key).common_name()) != myList.end())
			{
				myList.push_back((root->key).common_name()); 
			}
		}
		findZip(root->right,zipcode,myList);
	}
}

list<string> AVL_Tree::get_all_near(double latitude, double longitude, double distance) const
{
	list<string> myList;
	list_near(latitude,longitude,distance,root,myList);
	return myList;
}

void AVL_Tree::list_near(const double & latitude, const double & longitude, const double & distance, Node* root, list<string> & myList) const
{
	if (root == NULL)
	{
		return;
	}
	else
	{
		list_near(latitude,longitude,distance,root->left,myList);
		double lat; double lon; 
		(root->key).get_position(lat,lon);
		if (haversine(latitude,longitude,lat,lon) <= distance) 
		{
			myList.push_back((root->key).common_name());
		}
		list_near(latitude,longitude,distance,root->left,myList);
	}
}


int AVL_Tree::height(Node* n)
{
	if (n == NULL)
	{
		return -1;
	}
	return n->height;
}

int AVL_Tree::getSize() const
{
	return size;
}

int AVL_Tree::count_of_tree_species(const string & species_name) const
{
	int count = 0;

	string species = species_name;
	transform(species.begin(), species.end(), species.begin(), ::tolower);

	tree_species_counter(species,root,count);
	return count;
}

void AVL_Tree::tree_species_counter(const string & species_name, Node* root, int & count) const
{
	if (root == NULL)
	{
		return;
	}
	else
	{
		string common = (root->key).common_name();
		transform(common.begin(), common.end(), common.begin(), ::tolower);

		if (species_name < common)
		{
			tree_species_counter(species_name,root->left,count);
		}
		else if (species_name > common)
		{
			tree_species_counter(species_name,root->right,count);
		}
		else if (species_name == common)
		{
			count++;
			tree_species_counter(species_name,root->left,count);
			tree_species_counter(species_name,root->right,count);	
		}
	}
}

void AVL_Tree::print_tree_info(const string & tree_name) const
{
	vector<string> myVector;

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

	cout << "Command: tree_info " << word <<endl;
	tree_info(word,root,myVector);
	cout << "All matching species:" <<endl;
	for (unsigned int i = 0; i < myVector.size(); i++)
	{
		cout << "	" << myVector[i] <<endl;
	}

	cout <<endl;	
}

void AVL_Tree::tree_info(const string & tree_name, Node* root, vector<string>& myVector) const
{
	if (root == NULL)
	{
		return;
	}
	else
	{
		tree_info(tree_name,root->left,myVector);
		if (tree_name == (root->key).common_name()) // the enitre word matches
		{
			if(std::find(myVector.begin(), myVector.end(), (root->key).common_name()) != myVector.end()) 
			{
				/* v contains x */
			} 						
			else 
			{
				/* v does not contain x */
				myVector.push_back((root->key).common_name());
			}
		}
		else
		{
			string temp = "";
			string word = (root->key).common_name();
			word = word + " ";
			for (unsigned int i = 0; i < word.length(); i++)
			{

				if (word[i] == ' ' || word[i] == '-')
				{
					string compare1 = tree_name;
					string compare2 = temp;
					transform(compare1.begin(), compare1.end(), compare1.begin(), ::tolower);
					transform(compare2.begin(), compare2.end(), compare2.begin(), ::tolower);
					if (compare1 == compare2)	// If one of the two words matches
					{
						if(std::find(myVector.begin(), myVector.end(), (root->key).common_name()) != myVector.end()) 
						{
							/* v contains x */
						} 						
						else 
						{
							/* v does not contain x */
							myVector.push_back((root->key).common_name());
						}
					}
					temp = "";
				}
				else
				{
					temp = temp + (root->key).common_name()[i];
				}
			}
		}
		tree_info(tree_name,root->right,myVector);
	}
}

int AVL_Tree::boroughCount(const string & species, const string & borough) const
{
	int count = 0;
	string species_name = species;
	transform(species_name.begin(), species_name.end(), species_name.begin(), ::tolower);
	whichBorough(species_name,borough,root,count);
	return count;
}

void AVL_Tree::whichBorough(const string & species, const string & borough, Node* root, int & count) const
{
	if (root == NULL)
	{
		return;
	}
	else
	{
		string common = (root->key).common_name();
		transform(common.begin(), common.end(), common.begin(), ::tolower);

		string boro = (root->key).borough_name();
		transform(boro.begin(), boro.end(), boro.begin(), ::tolower);

		if (species < common)
		{
			whichBorough(species,borough,root->left,count);
		}
		else if (species > common)
		{
			whichBorough(species,borough,root->right,count);
		}
		else
		{
			if (borough == boro)
			{
				whichBorough(species,borough,root->left,count);
				count = count + 1;
				whichBorough(species,borough,root->right,count);

			}
			else
			{
				whichBorough(species,borough,root->left,count);
				whichBorough(species,borough,root->right,count);
			}
		}
	}
}

void AVL_Tree::print_listall_inzip(const int & zipcode) const
{
	vector<string> myVector;
	listall_inzip(zipcode,root,myVector);
	cout << "Command: listall_inzip: " << zipcode <<endl;
	for (unsigned int i = 0; i < myVector.size(); i++)
	{
		cout << myVector[i] <<endl;
	}
	cout <<endl;
}

void AVL_Tree::listall_inzip(const int & zipcode, Node* root, vector<string>& myVector) const
{
	if (root == NULL)
	{
		return;
	}
	else
	{
		listall_inzip(zipcode,root->left,myVector);
		if ((root->key).zip() == zipcode)
		{
			if(std::find(myVector.begin(), myVector.end(), (root->key).common_name()) != myVector.end()) 
			{
				/* myVector contains species name */
			} 						
			else 
			{
				/* myVector does not contain species name */
				if (((root->key).common_name()).length() != 0)
				{
					myVector.push_back((root->key).common_name());
				}
			}
		}
		listall_inzip(zipcode,root->right,myVector);
	}	
}

void AVL_Tree::clear()
{
	clean(root);
}

void AVL_Tree::clean(Node*& root)
{
	if (root == NULL)
	{
		return;
	}
	clean(root->left);
	clean(root->right);
	delete root;
	root = NULL;
}

void AVL_Tree::insert(const Tree & x)
{
	size++;
	insertion(x,root);
}

void AVL_Tree::insertion(const Tree & x, Node* & root)
{
	if (root == NULL) // Add node
	{
		root = new Node;
		root->key = x;
		root->left = NULL;
		root->right = NULL;
		root->height = 1;
	}
	else if (x < root->key)
	{
		insertion(x,root->left);
		if (height(root->left) - height(root->right) == 2)
		{
			if (x < root->left->key)
			{
				LL_rotation(root);
			}
			else
			{
				LR_rotation(root); 
			}
		}
	}
	else if (x > root->key)
	{
		insertion(x,root->right);
		if (height(root->right) - height(root->left) == 2)
		{
			if (root->right->key < x)
			{
				RR_rotation(root);
			}
			else
			{
				RL_rotation(root);
			}
		}
	}
	else
	{
		// Duplicate, do nothing
	}
	root->height = max(height(root->left), height(root->right)) + 1;
}

void AVL_Tree::remove(const Tree & x)
{
	size--;
	deletion(x,root);
}

void AVL_Tree::deletion(const Tree& x, Node* & root)
{
	if (root == NULL)
	{
		return;
	}
	if (x < root->key)
	{
		deletion(x,root->left);
		if (height(root->right) - height(root->left) == 2) // Unbalanced
		{
			if (height((root->right)->right) >= height((root->right)->left))
			{
				RR_rotation(root);
			}
			else
			{
				RL_rotation(root);
			}
		}
	}
	else if (root->key < x)
	{
		deletion(x,root->right);
		if (height(root->left) - height(root->right) == 2) // Unbalanced
		{
			if (height((root->left)->left) >= height((root->left)->right))
			{
				LL_rotation(root);
			}
			else
			{
				LR_rotation(root);
			}
		}
	}
	else // Delete node
	{ 
		if (root->left != NULL && (root->right != NULL)) // Two non-empty
		{
			root->key = findMin(root->right);
			deletion(root->key,root->right);
			if (height(root->left) - height(root->right) == 2) // Unbalanced
			{
				if (height((root->left)->left) >= height((root->left)->right))
				{
					LL_rotation(root);
				}
				else
				{
					LR_rotation(root);
				}
			}
		}
		else // one or both empty
		{
			Node* oldNode = root;
			root = (root->left != NULL) ? root->left : root->right;
			delete oldNode;
		}
	}

}

void AVL_Tree::RR_rotation(Node* & root)
{
	Node *temp = root->right;
	root->right = temp->left;
	temp->left = root;
	root->height = max(height(root->right), height(root->left)) + 1;
	temp->height = max(height(temp->right), root->height) + 1;
	root = temp;
}

void AVL_Tree::LR_rotation(Node* & root)
{
	RR_rotation(root->left);
	LL_rotation(root);
}

void AVL_Tree::LL_rotation(Node* & root)
{
	Node *temp = root->left;
	root->left = temp->right;
	temp->right = root;
	root->height = max(height(root->left), height(root->right)) + 1;
	temp->height = max(height(temp->left), root->height) + 1;
	root = temp;
}

void AVL_Tree::RL_rotation(Node* & root)
{
	LL_rotation(root->right);
	RR_rotation(root);
}