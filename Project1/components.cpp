/*  
    Willia Hardy
    wjh26@zips.uakron.edu
    2905326
    Project 1

*/

/*This file:
    - Declares an adjacency list
    - Prompts the user for input file to graph data
    - Returns an iterator
    - Builds the adjacency list
    - Displays the list
    - Compares vector components
    - Merges lists together if they have at least one element in common
    - Removes the empty list after it has been merged
    */

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include <vector>
#include <list>
#include <string>

using std::list;
using std::vector;
using std::cout;
using std::cin;
using std::string;
using std::endl;
using std::cerr;
using std::ifstream;


int main(){

    //vector of integer lists called adjList for adjacency list
    vector <list<int> > adjList;

    //Prompt the user for a file that has the graph data
    ifstream graphFile;
    string filename;
    

    cout << "Enter a file name: ";
    cin >> filename;

    graphFile.open(filename.c_str());

    //Check to make sure the file can open
    if(!graphFile){
        cerr << "File cannot be opened." << endl;
        exit(1);
    }

    graphFile.close();

}
