# Overview
This project is a extension of TreeCensus1. In TreeCensus1, I wrote a program that read the NYC open data set the 2015 Street Tree Census conducted by volunteers and staff organized by the NYC Department of Parks & Recreation as well as partner organizations. The data includes information about more than 680,000 trees on the streets of New York City. In this project, I will again read the data from that data set, but this time I will do some processing with the data. I will write a program that will allow a user to summarize certain aspects of the data, such as how many trees of a given species are growing, borough by borough, or which trees are within a given distance of a given GPS location. The user will be able to specify a fragment of a species common name, such as "oak" and the program will display the frequency of occurrence of all types of oak trees throughout the city, such as pin oaks, sawtooth oaks, scarlet oaks, and white oaks.


<b> Main Implementation: </b>
- Overload the main function for users to input arguments. The program will check if the agruments are valid.
- Create ifstream to open Tree census dataset and Commandline file.
- Based on different commands, the program will output different tree data.


<b> AVL_Tree Implementation: </b>
- The AVL_Tree object takes in tree object and store it in order.
- To keep it in order, it balances itself in every insertions or deletions using tree rotations.
- The AVL_Tree class has functions that output tree info.


<b> TreeCollection Implementation: </b>
- The TreeCollection is the heart of the program; it combines every classes into one. It encapsulates AVL_Tree, Boroughname and TreeSpecies.
- The main function calls TreeCollection functions which, then, call the AVL_Tree functions or Tree_Species depending on the commands.


<b> Tree Implementation: </b>
- The Tree class takes in data from the Tree Census dataset and analyze it.
- The Tree class has functions to output the tree information and overloaded compare functions to compare different Tree objects.


<b> Processing: </b>
- Given the command lines, the program outputs the tree data embeded in AVL_Tree object.
- To process the commands, I created functions to process different type of commands.
