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
#include <map>

using std::list;
using std::vector;
using std::cout;
using std::cin;
using std::string;
using std::endl;
using std::cerr;
using std::ifstream;
using std::istringstream;
using std::map;



    //Function to display the list
    void displayList(vector <list<int> > adjList){

        cout << "The adjacency list for your graph: " << endl;
        
        for(vector<list<int> >::iterator node = adjList.begin(); node != adjList.end(); node++){
            int itList = node - adjList.begin();
            cout << "List " << itList << ": ";

            for(list<int>::iterator currentLine = node->begin(); currentLine != node->end(); currentLine++ ){
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

         const int conn1Size = conn1.size();
         const int conn2Size = conn2.size();
         map<int, bool> m;
        
        const int upperBound = (conn1Size < conn2Size ? conn2Size : conn1Size);

        list<int>::const_iterator conn1Iterator = conn1.begin();
        list<int>::const_iterator conn2Iterator = conn2.begin();

        for (int i = 0; i < upperBound; i++)
        {   
            // Make sure we do not try to access element beyond bounds of A
            if (i < conn1Size)
            {
                const int currentConn1Value = *conn1Iterator;
                // Test if value is already in map, if yes return true
            if (m[currentConn1Value])
            {
                return true;
            }
            // Add new value to map
            m[currentConn1Value] = true;
            ++conn1Iterator;
        }
        // Make sure we do not try to access element beyond bounds of B
        if (i < conn2Size)
        {
            const int currentConn2Value = *conn2Iterator;
            // Test if value is already in map, if yes return true
            if (m[currentConn2Value])
            {
                return true;
            }
            // Add new value to map
            m[currentConn2Value] = true;
            ++conn2Iterator;
        }
    }
    return false;

	}

	//Merges two lists together as long as they have at least one common element
    bool merge2(list<int> & cp1, list<int> & cp2){

            const int cp1Size = cp1.size();
            const int cp2Size = cp2.size();

        // Determine which list we will merge into
            list<int> &listMergingTo = cp1Size < cp2Size ? cp2 : cp1;
            list<int> &listMergingFrom = cp1Size < cp2Size ? cp1 : cp2;

        for (list<int>::iterator from = listMergingFrom.begin(); from != listMergingFrom.end(); ++from)
        {
            const int initial = *from;
            list<int>::iterator greater = find_gt(listMergingTo.begin(), listMergingTo.end(), initial);
            listMergingTo.insert(greater, initial);
        }
        // Make the merged list unique
        listMergingTo.unique();
        // Clear out old list
        listMergingFrom.clear();
        return true;
	}


//Run the program
int main(){

    //vector of integer lists called adjList for adjacency list
    vector <list<int> > adjList;
    list<int> emptyList;
    string line;
    string readline;

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

    //Find_gt method, sorting the list as it is populated

    istringstream iss(line);
    for(string s; iss >> s;){

        int i = std::stoi(s);
        if(emptyList.size() == 0)
        emptyList.push_back(i);
        else{
            list<int>::iterator greater = find_gt(emptyList.begin(), emptyList.end(), i);
            emptyList.insert(greater, i);
        }
    }

    adjList.push_back(emptyList);

    displayList(adjList);

    while(true){

        int listID1;
        int listID2;

        cout << "Enter the two list IDs to potentially merge together (or -1 to quit: ";
        cin >> listID1;

        cin >> listID2;

        if(listID1 == -1 || listID2 == -1){
            break;
        } else {

            std::list<int> list1;
            std::list<int> list2;
            const bool merged = merge2(list1,list2);

            cout << "The lists are " << (merged ? "" : "not ") << "merged." << endl;

            if(merged){

                for(vector<list<int> >::iterator node = adjList.begin(); node != adjList.end(); node++){
                    if(node->size() == 0){
                        //Remove from list
                        adjList.erase(node);
                        break;
                    }
                }
            }

            displayList(adjList);
        }
    }

	return 0;

}
    


