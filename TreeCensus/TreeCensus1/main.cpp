/*
Title: main.cpp
Author: Ho Ming Poon
Created on: February 20th, 2018
Description: Parsing the input file and outputting informations that are needed.   
*/
#include <iostream>
#include <fstream>
#include <stdlib.h>

#include "pseudoserver.h"
#include "tree.h"
#include "bitcoin.h"
using namespace std;

int main(int argc, char const *argv[])
{
	if( argc == 4 ) // Argument checks 
	{
	
	}
	else if( argc > 4 ) 
	{
		cout << "Too many arguments supplied." <<endl;
		exit(1);
	}
	else
	{
		cout << "Invalid argument passed." <<endl;
		exit(1);
	}

	const char* ifile = argv[1]; // Input File
	const char* ofile = argv[2]; // Output File
	int seed; // Seed
	istringstream (argv[3]) >> seed;

	Bitcoin mycoin(seed); // Bitcoin initialization
	pseudoServer container; // Create pseudoServer for inputting element in queue

	ifstream inFile; // Opening input file and output file
	ofstream outFile;
	inFile.open(ifile);
	outFile.open(ofile);

	double n = 0.0; // Average
	int iteration = 0;
	int e = 0; // eof queue size
	int m = 0; // Max queue size
	int c = 0; // Empty counts	

	string temp;
	while (!inFile.eof())
	{
		if (mycoin())
		{
			container.read(inFile); // Read from file 
			n += container.queuesize(); // For average 
			iteration++;
			if (container.queuesize() > m) // For max size
			{
				m = container.queuesize();
			}
		}
		else
		{
			if (container.extract(temp)) // Extract from queue if possible
			{
				Tree t(temp); // Create a tree
				outFile << t <<endl; // outputting on the output file
				n += container.queuesize(); // For average
				iteration++;
			}
			else
			{
				c++; // Empty count
			}
		}
	}
	e = container.queuesize(); // eof queue size
	while (container.queuesize() > 0) // Extracting remaining element in queue after eof
	{
		container.extract(temp);
		Tree t(temp);
		outFile << t <<endl;
	}		
	n = n/iteration;

	inFile.close(); // Close file
	outFile.close();
	cout << "average queue size: " << n <<endl;
	cout << "maximum queue size: " << m <<endl;
	cout << "empty queue count: "  << c <<endl;
	cout << "queue size on eof: "  << e <<endl;
}