/* 
    Willia Hardy
    wjh26@zips.uakron.edu
    2905326
    Project 2
*/

//include statements
#include "empmaps.h"
#include "Employee.h"
#include <vector>
#include <map>
#include <unordered_map>
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>


using std::vector;
using std::map;
using std::unordered_map;
using std::istringstream;
using std::cout;
using std::string;
using std::ifstream;
using std::cin;
using std::endl;


//Function to get the input files
vector<string> get_file(){

    ifstream recordFile;
    string filename;
    string line;
    vector<string> lines;

    //Prompt the user for a file that has the graph data
    cout << "Please enter the file name to process: ";
    cin >> filename;

    recordFile.open(filename.c_str());

    if(recordFile.fail()){
            cout << "There was an error opening the file, try again" << endl;
            cin >> filename;
            recordFile.open(filename.c_str());
    }

    while(getline(recordFile, line)){

        if(line.length() > 0){
            lines.push_back(line);
        }
    }

}

//Function to read the data from the file and build the Employee vector
vector<Employee> employees()
{
    vector<Employee> empvec;

    // get the data from the input file
    vector<string> records = get_file();

    // iterate through it to get what we want
    for(vector<string>::iterator it = records.begin(); it != records.end(); it++)
    {
        istringstream iss(*it);

        string id;
        iss >> id;

        string name;
        iss >> name;

        string salary;
        iss >> salary;

        Employee emp(stoi(id), name, stoi(salary));
        empvec.push_back(emp);
    }

    cout << "Number of employees: " << empvec.size() << "\n";

}

