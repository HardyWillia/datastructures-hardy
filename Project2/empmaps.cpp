/*
    Willia Hardy
    wjh26@zips.uakron.edu
    2905326
    Project 2
*/

//include statements
#include "empmaps.h"

#include "Employee.h"
#include <fstream>
#include <unordered_map>
#include <ctime>
#include <map>
#include <vector>
#include <iostream>
#include <vector>
#include <list>
#include <iterator>
#include <fstream>
#include <functional>
#include <string>
#include <sstream>

using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::ifstream;
using std::istringstream;
using std::map;
using std::string;
using std::unordered_map;
using std::vector;


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
            cout << "There was an error opening the file, try again: ";
            cin >> filename;
            recordFile.open(filename.c_str());
    }

    while(getline(recordFile, line)){

        if(line.length() > 0){
            lines.push_back(line);
        }
    }

    return lines;
}

/*
    Read data file and build a vector of Employees
*/
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

        if (id.length() > 0 && name.length() > 0 && salary.length() > 0)
        {
            Employee emp(stoi(id), name, stoi(salary));
            empvec.push_back(emp);
        }
    }


    return empvec;

}

/*
    Build a map of Employees from the vector of employees
    based on the department id
*/
map<int, vector<Employee>> mapEmpDept(vector<Employee> &emp)
{

    map<int, vector<Employee>> empMap;
    for (int i = 0; i < emp.size(); ++i)
    {
        // Extract out the department id and insert
        empMap[emp[i].id() / 100].push_back(emp[i]);
    }
    return empMap;
}

/*
    Build a map of Employees from the vector of employees
    based on salary range
*/
map<int, vector<Employee>> mapSalRange(vector<Employee> &emp)
{
    map<int, vector<Employee>> empMap;
    for (int i = 0; i < emp.size(); ++i)
    {
        // Extract the salary range and insert
        int trueRange = (emp[i].sal() / 10000) * 10000;
        empMap[trueRange].push_back(emp[i]);
    }
    return empMap;
}

/*
    Print the map of salary ranges
    Determine which range has the most employees
*/
void printSalRange(map<int, vector<Employee>> &salRange)
{
    int largestSize = 0;
    int largestGrouping = 0;

    for (auto i = salRange.begin(); i != salRange.end(); ++i)
    {
        int emps = i->second.size();
        int groups = i->first;
        cout << "ORDERED Map Salary Range " << groups << " contains " << emps << endl;
        // Check to see if we found a range with more employees
        if (emps > largestSize)
        {
            largestGrouping = groups;
            largestSize = emps;
        }
    }

    cout << "ORDERED Map Salary Range with most employees: " << largestGrouping << " containing " << largestSize << " employees" << endl;
}

/*
    Build a unordered map of Employees from the vector of employees
    based on the department id
*/
unordered_map<int, vector<Employee>> umapEmpDept(vector<Employee> &emp)
{
    unordered_map<int, vector<Employee>> empMap;
    for (int i = 0; i < emp.size(); ++i)
    {
        empMap[emp[i].id() / 100].push_back(emp[i]);
    }
    return empMap;
}

/*
    Build a unordered map of Employees from the vector of employees
    based on salary range
*/
unordered_map<int, vector<Employee>> umapSalRange(vector<Employee> &emp)
{
    unordered_map<int, vector<Employee>> empMap;
    for (int i = 0; i < emp.size(); ++i)
    {
        int lowRange = (emp[i].sal() / 10000) * 10000;
        empMap[lowRange].push_back(emp[i]);
    }
    return empMap;
}

/*
    Print the unordered map of salary ranges
    Determine which range has the most employees
*/
void uprintSalRange(unordered_map<int, vector<Employee>> &salRange)
{
    int largestSize = 0;
    int largestGrouping = 0;

    for (auto i = salRange.begin(); i != salRange.end(); ++i)
    {
        int emps = i->second.size();
        int groups = i->first;
        cout << "UNORDERED Map Salary Range " << groups << " contains " << emps << endl;
        // Check to see if we found a range with more employees
        if (emps > largestSize)
        {
            largestGrouping = groups;
            largestSize = emps;
        }
    }

    cout << "UNORDERED Map Salary Range with most employees: " << largestGrouping << " containing " << largestSize << " employees" << endl;
}
