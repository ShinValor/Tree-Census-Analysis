Main Implementation
- I overloaded main function for user to input arguments and check them.
- Then I create ifstream to open the files, the tree census data and command line file.
- Based on the different commands, I output the tree info and data.
- Using while loop, I do this until eof.

AVL_Tree implementation
- The AVL_Tree takes in tree object and store it in order.
- It balance itself everytime insertion or deletion if it is unbalanced by doing rotations.
- The AVL_Tree class also has functions that output tree info that TreeCollection can call.

TreeCollection Implementation
- The TreeCollection is the heart of the program. It combines everyclass into one. It encapsulate AVL_Tree, Boroughname and TreeSpecies.
- The main function calls TreeCollection functions which calls the AVL_Tree functions or Tree_Species depending on the commands.

Tree Implementation
- The Tree class takes in string input by the Tree Census data and parse it. It takes the necessary data and put it into private variables.
- It has accessor functions to output the private variables and comparator functions to compare different Tree objects.

Processing
- Given the command lines, I have to output back the data within the TreeCollection class. 
- Some of the difficulties involved searching through the AVL_Tree and TreeSpecies to collect/count the data required.
- To process the commands, I have to create functions to specifically process each command line.