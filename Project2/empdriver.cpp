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



int main(){

    // Define clock variable which will be used for timing
        clock_t start, stop;
    
    vector<Employee> emps = employees();
    cout << "Number of employees: " << emps.size() << endl;


    //Clock ticks for Ordered Map
    start = clock();
    map<int,vector<Employee> > omapDept = mapEmpDept(emps);
    stop = clock();
    cout << "Clock ticks for mapEmpDept: " << double(stop - start) << "\n";
    cout << "Number of departments in Ordered Map: " << omapDept.size() << endl;

    start = clock();
    map<int, vector<Employee> > omapSal = mapSalRange(emps);
    stop = clock();
    cout << "Clock ticks for mapSalRange: " << double(stop - start) << "\n";
    cout << "Number of salary ranges in Ordered Map: " << omapSal.size() << endl;


    printSalRange(omapSal);

    cout << endl;


    //Clock ticks for Unordered maps
    start = clock();
    unordered_map<int,vector<Employee> > umapDept = umapEmpDept(emps);
    stop = clock();
    cout << "Clock ticks for umapEmpDept: " << double(stop - start) << "\n";
    cout << "Number of departments in Unrdered Map: " << umapDept.size() << endl;


    start = clock();
    unordered_map<int, vector<Employee> > umapSal = umapSalRange(emps);
    stop = clock();
    cout << "Clock ticks for umapSalRange: " << double(stop - start) << "\n";
    cout << "Number of salary ranges in Unrdered Map: " << umapSal.size() << endl;


    uprintSalRange(umapSal);
    cout << endl;
    
    
    
    
    
    
    return 0;
}