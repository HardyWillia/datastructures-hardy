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
using std::ifstream;
using std::istringstream;




    //Function to display the list every time it is merged
    void displayList(vector<list<int> > adjList){

        int itList = 0;
        vector<list<int> >::iterator node;
        list<int>::iterator currentLine;

        cout << "The adjacency list for your graph: " << endl;
        
        for(node = adjList.begin(); node != adjList.end(); ++node){
            
            cout << "List " << itList << ": ";

            for(currentLine = node->begin(); currentLine != node->end(); ++currentLine ){
                cout << *currentLine << ' ';
            }

            cout << '\n';
            itList++;
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

    //Function to load the file and save it in the list
    vector<list<int> > get_file(){

        ifstream graphFile;
        string filename;
        string line;
        vector <list<int> > adjList;
        list<int> emptyList;
        list<int>::iterator greater = emptyList.begin();


        //Prompt the user for a file that has the graph data
        cout << "Please enter the graph file name to process: ";
        cin >> filename;

        /*The two lines below had to be used on my computer because the file couldn't be found using cmake
            - The file path was manipulated to make sure the compiler found graph.dat
            - Will not be needed if running in Codeblocks or using g++
            - Use this way and change the file path if the file cannot be found
        */
        //string filepath = "/home/hardyl/datastructures-hardy/Project1/" + filename;
        //graphFile.open(filepath.c_str());

        graphFile.open(filename.c_str());

        //Check to make sure the file can open
            while(getline(graphFile, line)){
            
            //Check to make sure the file is actually printing
                cout << line << "\n";

            //Prints the ordered list as it is ordered
                istringstream iss(line);
                for(string s; iss >> s;){

                    int i = std::atoi(s.c_str());
                    if(emptyList.size() == 0){
                        emptyList.insert(greater, i);
                    }
                    else{
                        greater = find_gt(emptyList.begin(), emptyList.end(), i);
                        emptyList.insert(greater, i);
                    }
                }
            adjList.push_back(emptyList);
            emptyList.clear();
            greater = emptyList.begin();
            
            }
            return adjList;
    }




	//Assumes lists are sorted in ascending order and elements are unique
     bool connComponent (const list<int> &connComp1, const list<int> &connComp2){

        list<int>::const_iterator conn1;
        list<int>::const_iterator conn2;
  
        for(conn1 = connComp1.begin(); conn1 != connComp2.end(); ++conn1){
            for(conn2 = connComp1.begin(); conn2 != connComp2.end(); ++conn2){
                    if(*conn1 == *conn2){
                        return true;
                    }
            }
        }

            return false;

	}

	//Merges two lists together as long as they have at least one common element
    bool merge2(list<int> & cp1, list<int> & cp2){

            const int cp1Size = cp1.size();
            const int cp2Size = cp2.size();

            list<int>::iterator greater;
            list<int>::iterator from;

        // Determine which list we will merge into
            list<int> &listMergingTo = cp1Size < cp2Size ? cp2 : cp1;
            list<int> &listMergingFrom = cp1Size < cp2Size ? cp1 : cp2;


        for (from = listMergingFrom.begin(); from != listMergingFrom.end(); ++from)
        {
            int initial = *from;
            greater = find_gt(listMergingTo.begin(), listMergingTo.end(), initial);
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

    //Create the list from the file
    adjList = get_file();

    //Display the list
    displayList(adjList);

    while(true){

        int listID1;
        int listID2;

        cout << "Enter the two list IDs to potentially merge together (or -1 to quit): " << endl;
        cout << "First list to merge: ";
        cin >> listID1;
        cout << "\n";

        if(listID1 == -1){
            break;
        }

        cout << "Second list to merge: ";
        cin >> listID2;
        cout << "\n";

        if(listID2 == -1){
            break;
        } else {

            list<int> &list1 = adjList.at(listID1);
            list<int> &list2 = adjList.at(listID2);
            const bool merged = merge2(list1,list2);

            cout << "The lists you chose are " << (merged ? "" : "not ") << "merged." << endl;

            if(merged){

                //Loop over each element to delete the lists that are empty
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
}



    


