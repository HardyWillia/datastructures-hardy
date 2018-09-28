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



    //Function to display the list
    void displayList(vector <list<int> > adjList){

        cout << "The adjacency list for your graph: " << endl;
        
        for(vector<list<int> >::iterator node = adjList.begin(); node != adjList.end(); node++){
            int itList = node - adjList.begin();
            cout << "List " << itList << ": ";

            for(auto currentLine = node->begin(); currentLine != node->end(); currentLine++ ){
                cout << *currentLine << ' ' << endl;
            }

            cout << '\n';
        }
    }


 	//Function to find the number that is greater than in a list
     list<int>::iterator find_gt(list<int>::iterator start, list<int>::iterator stop, int x){

         for(list<int>::iterator temp = start; temp != stop; temp++){
             if(*temp > x)
                return temp;
         }

            return stop;

	}

	//Assumes lists are sorted in ascending order and elements are unique
     bool connComponent (const list<int> &conn1, const list<int> &conn2){



	}

	//Merges two lists together as long as they have at least one common element
    bool merge2(list<int> & cp1, list<int> & cp2){


	}


//Run the program
int main(){

    //vector of integer lists called adjList for adjacency list
    vector <list<int> > adjList;
    string line;

    //Prompt the user for a file that has the graph data
    ifstream graphFile;
    string filename;

    cout << "Please enter the graph file name to process: ";
    cin >> filename;

    string filepath = "/home/hardyl/datastructures-hardy/Project1/" + filename;

    graphFile.open(filepath.c_str());

    //Check to make sure the file can open
    if(graphFile.is_open()){
	while(getline(graphFile, line)){
		cout << line << "\n";
	}

	graphFile.close();
	}
	else cout << "Unable to open the file" << endl;

	return 0;

}
    


