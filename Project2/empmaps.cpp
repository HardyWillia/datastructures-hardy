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
#include <unordered_map>
#include <map>
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

    return lines;
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


// Function to build a map of Employee vector based on deptID
map<int,vector<Employee>> mapEmpDept(vector<Employee> & emp)
{
    map<int, vector<Employee>> deptID;

    for(int i = 0; i <= emp.size(); i++)
    {
        int dept_num = emp[i].id() / 100;
        deptID[dept_num].push_back(emp[i]);
    }

}

// Function to build of map of Employees vector based on salary range
map<int,vector<Employee>> mapSalRange(vector<Employee> & emp)
{
    map<int, vector<Employee>> salary;

    for(int i = 0; i <= emp.size(); i++)
    {
        int sal_range = (emp[i].sal() / 10000) * 10000;
        salary[sal_range].push_back(emp[i]);

    }
}

//Print salary ranges
//Determine the range with the most employees
void printSalRange(map<int, vector<Employee>> &salRange)
{
    int largestSize = 0;
    int largestGrouping = 0;

    for (auto i = salRange.begin(); i != salRange.end(); ++i)
    {
        int empCount = i->second.size();
        int groupCount = i->first;

        cout << "ORDERED Map Salary Range " << groupCount << " contains " << empCount << endl;
        
        // Check to see if we found a range with more employees
        if (empCount > largestSize)
        {
            largestGrouping = groupCount;
            largestSize = empCount;
        }
    }

    cout << "ORDERED Map Salary Range with most employees: " << largestGrouping << " containing " << largestSize << " employees" << endl;
}

//Functions below are the same as above, except, they have an unordered map

// Function to build an UNORDERED map of Employee vector based on deptID
unordered_map<int,vector<Employee>> umapEmpDept(vector<Employee> & emp)
{
    unordered_map<int, vector<Employee>> deptID;

    for(int i = 0; i <= emp.size(); i++)
    {
        int dept_num = emp[i].id() / 100;
        deptID[dept_num].push_back(emp[i]);
    }

}

// Function to build an UNORDERED map of Employees vector based on salary range
unordered_map<int,vector<Employee>> umapSalRange(vector<Employee> & emp)
{
    unordered_map<int, vector<Employee>> salary;

    for(int i = 0; i <= emp.size(); i++)
    {
        int sal_range = (emp[i].sal() / 10000) * 10000;
        salary[sal_range].push_back(emp[i]);

    }
}

//Print salary ranges
//Determine the range with the most employees
void uprintSalaryRange(unordered_map<int, vector<Employee>> &salRange)
{
    int largestSize = 0;
    int largestGrouping = 0;

    for (auto i = salRange.begin(); i != salRange.end(); ++i)
    {
        int empCount = i->second.size();
        int groupCount = i->first;

        cout << "UNORDERED Map Salary Range " << groupCount << " contains " << empCount << endl;
       
        // Check to see if we found a range with more employees
        if (empCount > largestSize)
        {
            largestGrouping = groupCount;
            largestSize = empCount;
        }
    }

    cout << "UNORDERED Map Salary Range with most employees: " << largestGrouping << " containing " << largestSize << " employees" << endl;
}