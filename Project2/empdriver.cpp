/*
    Willia Hardy
    wjh26@zips.uakron.edu
    2905326
    Project2
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
#include <ctime>
#include <list>
#include <iterator>


using std::vector;
using std::map;
using std::unordered_map;
using std::istringstream;
using std::cout;
using std::string;
using std::ifstream;
using std::cin;
using std::endl;
using std::list;

void uprintSalRange(unordered_map<int,vector<Employee>> & salRange);


int main(){

    // Define clock variable which will be used for timing
        clock_t start, stop;

    vector<Employee> emps = employees();
    cout << "Number of employees: " << emps.size() << endl;


    //Clock ticks for Ordered Map
    start = clock();
    map<int,vector<Employee> > omapDept = mapEmpDept(emps);
    stop = clock();
    cout << "ORDERED Map creation with department as key clock ticks: " << double(stop - start) << "\n";
    cout << "ORDERED Map number of departments: " << omapDept.size() << endl;

    start = clock();
    map<int, vector<Employee> > omapSal = mapSalRange(emps);
    stop = clock();
    cout << "ORDERED Map creation with salary as key clock ticks: " << double(stop - start) << "\n";
    cout << "ORDERED Map number of salary ranges: " << omapSal.size() << endl;


    printSalRange(omapSal);

    cout << endl;


    //Clock ticks for Unordered maps
    start = clock();
    unordered_map<int,vector<Employee> > umapDept = umapEmpDept(emps);
    stop = clock();
    cout << "UNORDERED Map creation with department as key clock ticks: " << double(stop - start) << "\n";
    cout << "UNORDERED Map number of departments: " << umapDept.size() << endl;


    start = clock();
    unordered_map<int, vector<Employee> > umapSal = umapSalRange(emps);
    stop = clock();
    cout << "UNORDERED Map creation with salary as key clock ticks: " << double(stop - start) << "\n";
    cout << "UNORDERED Map number of salary ranges: " << umapSal.size() << endl;


    uprintSalRange(umapSal);
    cout << endl;






    return 0;
}
