# Overview
In 2016, New York City made public the results of TreesCount, the 2015 Street Tree Census, conducted by volunteers and staff organized by the NYC Department of Parks & Recreation as well as partner organizations. The data includes information about more than 680,000 trees on the streets of New York City. This is a large dataset, with over 683,000 lines of text totaling more than 193 MB of data. Although it will fit into computer's memory, it will make many computers behave sluggishly, depending on what you do with the data. The project objective is to process the datasets in a piecewise way rather than by reading the entire data set into a single contiguous data structure such as a vector or an array.


<b> Main Implementation: </b>
- Overload the main function for users to input arguments. The program will check if the agruments are valid.
- Create ifstream to open Tree census dataset and Commandline file.
- Based on different commands, the program will output different tree data.


<b> Tree Implementation: </b>
- The Tree class takes in data from the Tree Census dataset and analyze it.
- The Tree class has functions to output the tree information and overloaded compare functions to compare different Tree objects.


<b> PseudoServer Implementation: </b>
- Implement a queue linked list to enqueue and dequeue efficiently
- Input part of the dataset into the queue so the program can analyze the dataset in a piecewise way.


<b> Processing: </b>
- Given the command lines, the program outputs the tree data embeded in AVL_Tree object.
- To process the commands, I created functions to process different type of commands.