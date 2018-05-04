# Overview

This project is a extension of TreeCensus1. In TreeCensus1, I wrote a program that read the NYC open data set the 2015 Street Tree Census conducted by volunteers and staff organized by the NYC Department of Parks & Recreation as well as partner organizations. The data includes information about more than 680,000 trees on the streets of New York City. In this project, I will again read the data from that data set, but this time I will do some processing with the data. I will write a program that will allow a user to summarize certain aspects of the data, such as how many trees of a given species are growing, borough by borough, or which trees are within a given distance of a given GPS location. The user will be able to specify a fragment of a species common name, such as "oak" and the program will display the frequency of occurrence of all types of oak trees throughout the city, such
as pin oaks, sawtooth oaks, scarlet oaks, and white oaks.

<b> Main Implementation: </b>
- I overloaded the main function for user to input arguments and the program will check if the agruments are valid.
- I create ifstream to open Tree census dataset and Commandline file.
- Based on the different commands, the program will output different tree data.
- Using while loop until the Commandline eof.

<b> AVL_Tree Implementation: </b>
- The AVL_Tree takes in tree object and store it in order.
- It balances itself in every insertion or deletion using tree rotations.
- The AVL_Tree class also has functions that output tree info that TreeCollection can call.

<b> TreeCollection Implementation: </b>
- The TreeCollection is the heart of the program. It combines every classes into one. It encapsulate AVL_Tree, Boroughname and TreeSpecies.
- The main function calls TreeCollection functions which calls the AVL_Tree functions or Tree_Species depending on the commands.

<b> Tree Implementation: </b>
- The Tree class takes in string input by the Tree Census data and parse it. It takes the necessary data and put it into private variables.
- The Tree class has accessor functions to output the private variables and comparator functions to compare different Tree objects.

<b> Processing </b>
- Given the command lines, I have to output the data within the TreeCollection class. 
- Some of the difficulties involved searching through the AVL_Tree and TreeSpecies to collect/count the data required.
- To process the commands, I have to create functions to specifically process different type of command.